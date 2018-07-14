//www.elegoo.com
//2016.12.08
//#include <stdio.h>
#include <string.h>
#include "IRremote.h"
#include <Servo.h>

//for the hand
int motorPin1 = 3; //red
int motorPin2 = 2; //black
bool closed = true; //the hand has to start closed

//for the LED
int RED = 7;
int GREEN = 6;
int BLUE = 5;

//for the remote
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

//for the servo motor
Servo myservo;
int servoPos = 1;

//for the neural net

#define PASTLOOKING 10

void Close() {
  closed = true;
  Serial.println("calling Close()");
  digitalWrite(motorPin1, HIGH); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(2500); //waits
  digitalWrite(motorPin2, HIGH);    // set the Pin motorPin1 LOW
}

void Open() {
  closed = false;
  Serial.println("calling Open()");
  digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(2700); //waits
  digitalWrite(motorPin1, HIGH);    // set the Pin motorPin2 LOW
}

void color(int r, int g, int b) {
  digitalWrite(RED, r);
  digitalWrite(GREEN, g);
  digitalWrite(BLUE, b);
}

void Rock() {
  color(255, 0, 0);
  myservo.write(45);
  if (!closed) {
    Close();
  }
  delay(500);
  color(0, 0, 0);
}

void Scissors() {
  color(0, 0, 255);
  myservo.write(45);
  if (closed) {
    Open();
  }
  delay(500);
  color(0, 0, 0);
}

int translateIR() // takes action based on IR code received
// describing Remote IR codes
{

  switch (results.value)

  {
    case 0xFF30CF: return 1;    break; //1
    case 0xFF18E7: return 2;    break; //2
    case 0xFF7A85: return 3;    break; //3
    case 0xFF02FD: return 4;    break; //pause


    default:
      return 0;

  }

  delay(500); // Do not get immediate repeat


} //END translateIR


void Paper() {
  color(255, 0, 255);
  myservo.write(135);
  if (!closed) {
    Close();
  }
  delay(500);
  color(0, 0, 0);
}


void outputMove(int userMove) {
  if (userMove == 0) {
    Rock();
  } else if (userMove == 1) {
    Paper();
  } else {
    Scissors();
  }
}

void rpsBuildup() //does the "Rock Paper Scissors" people do to set the temp for making their moves
{
  color(0,0,0);
  delay(100);
  for(int i = 0; i < 3; i++){
    color(0,255,0);
    delay(400);
    color(0,0,0);
    delay(200);
  }
}

void setup()
{
  //for the hand
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  Open();

  //for the LED
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //general
  Serial.begin(9600);

  //for the IR reciever
  irrecv.enableIRIn(); // Start the receiver
  myservo.attach(9);

}

//now for the neural net functions

int compare1dArrays(int arrayA[], int arrayB[], int length){
  for (int i = 0; i < length; i++){
    if (arrayA[i] != arrayB[i]){ return 0; }
  }
  return 1;
}

void copyChangeCode(int newArray[9], int oldArray[9]){
  for (int i = 0; i < 9; i++){
    newArray[i] = oldArray[i];
  }
}

void printValues(int values[3][3][3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        printf("%d\n", values[i][j][k]);
      }
      printf(">\n");
    }
    printf(">>\n");
  }
}

void copyValues(int newArray[3][3][3], int oldArray[3][3][3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        newArray[i][j][k] = oldArray[i][j][k];
      }
    }
  }
}

void applyChange(int values[3][3][3], int changeCode[9]){

  for (int a = 0; a < 9; a++){
    changeCode[a] --;
  }

  for (int i = 0; i < 3; i++){
    for (int k = 0; k < 3; k++){
      values[i][k][ (0+k) % 3 ] += changeCode[ (3*i) + 0];
      values[i][k][ (1+k) % 3 ] += changeCode[ (3*i) + 1];
      values[i][k][ (2+k) % 3 ] += changeCode[ (3*i) + 2];
    }
  }

  for (int a = 0; a < 9; a++){//we need this so that we don't mess up changeCode in the upper stack frame
    changeCode[a] ++;
  }

}

void outputMove(int index){
  const char *moves[] = {"rock","paper","scissors"};
  printf("%s\n", moves[index]);

}

int maxIndex(int array[],int length){
  int best[2] = {0,array[0]};
  for (int i = 1; i < length; i++){
    if (array[i] > best[1]) {
      best[0] = i;
      best[1] = array[i];
    }
  }
  //printf("the top value was %d\n", best[1]);
  return best[0];
}

int makeMove(int values[3][3][3], int pastMoves[3]){
  int decidingValues[3] = {0,0,0};
  for (int i = 0; i < 3; i++){
    int pieceMoved = pastMoves[i];
    for (int j = 0; j < 3; j++){
      decidingValues[j] += values[i][pieceMoved][j];
    }
  }
  return maxIndex(decidingValues,3);
}

void updateArray(int array[], int newElement, int length) {
  for (int i = 0; i < length - 1; i ++) {
    array[i] = array[i+1];
  }
  array[length-1] = newElement;
}

void print(int array[], int length){
  for (int i = 0; i < length; i ++) {
    printf("%d\n", array[i]);
  }
  printf("\n");
}

int evaluateValues(int values[3][3][3], int data[PASTLOOKING]){

  int score = 0;
  int wouldBeMove;
  for (int i = 0; i < (PASTLOOKING-3); i++){
    int tempMoves[3] = {data[i], data[i+1], data[i+2]};
    wouldBeMove = makeMove(values, tempMoves);
    if ( wouldBeMove == (data[i+3] + 1) % 3 ){//if the computer move would have beaten the user move
      score++;
    } else {//this method does not like ties. Maybe not the best. TODO test having ties be worth nothing
      score --;
    }
  }
  return score;

}

int incrementBaseThree(int number[], int length){//the return value is 1 if successfull, and 0 if not. this happens when you try and increment an all two's array

  //NOTE: number[0] is the least significant digit
  int i = 0;
  int carry = 1;
  while (carry) {
    number[i]++;
    if (number[i]==3){
      number[i] = 0;
    } else {
      carry = 0;
    }
    i++;
    if (i == length) {
      if (carry) return 0;
    }
  }
  return 1;
}

void hillClimb(int values[3][3][3],int pastData[PASTLOOKING]){
  int bestVal = evaluateValues(values,pastData);
  int bestCode[9] = {0,0,0,0,0,0,0,0,0};

  int valueChangeCode[9] = {0,0,0,0,0,0,0,0,0};
  int valuesCopy[3][3][3];
  //copyValues(valuesCopy,values);
  int i = 0;
  while (incrementBaseThree(valueChangeCode,9)){
    copyValues(valuesCopy,values);
    applyChange(valuesCopy,valueChangeCode);
    int evaluation = evaluateValues(valuesCopy,pastData);
    if (evaluation > bestVal) {
      bestVal = evaluation;
      copyChangeCode(bestCode,valueChangeCode);
    }
    i++;
  }
  applyChange(values,bestCode);
  //printf("the best values I found had a score of: %d\n", bestVal);
}

int choseMove(int evaluateRecentMoves[3][3][3],int pastMoves[3], int extendedPastMoves[PASTLOOKING], int userMoveInt){

  color(255,255,0);//sets the color to yellow while it is calculating

  int goForAnother = 1;

  /*  evaluateRecentMoves is:
   *  [move][pieceMoved][valueForPiece]
   */

  int move = makeMove(evaluateRecentMoves,pastMoves);

  /*
  printf("what was your move? (r/p/s)\n");
  scanf("%s",userMove);
  printf("\n");
  */

  updateArray(pastMoves,userMoveInt,3);
  updateArray(extendedPastMoves,userMoveInt,PASTLOOKING);
  hillClimb(evaluateRecentMoves,extendedPastMoves);

  rpsBuildup();

  return move;
}

void loop(){

  int evaluateRecentMoves[3][3][3] = {
    {
      {0,0,0},
      {0,0,0},
      {0,0,0}
    },
    {
      {0,0,0},
      {0,0,0},
      {0,0,0}
    },
    {
      {0,0,0},
      {0,0,0},
      {0,0,0}
    }
  };
  int pastMoves[3] = {0,1,2};
  int extendedPastMoves[PASTLOOKING];
  char userMove[1];
  int userMoveInt;

  goBack:
  while (! irrecv.decode(&results) ) // have we received an IR signal?
  {
    Serial.println("here");
    delay(100);
  }
  int move = translateIR() - 1;
  if (move == -1) {
    color(255, 255, 0);
    Serial.println("error in IR");
    delay(500);
    color(0, 0, 0);
    irrecv.resume();
    goto goBack;
  }
  if (move == 4) outputMove(rand()%3);//4 means random
  else outputMove(choseMove(evaluateRecentMoves, pastMoves, extendedPastMoves, move));
  irrecv.resume();//resumes the IR sensor
  delay(500);//waits a bit, just to ease out kinks
}
