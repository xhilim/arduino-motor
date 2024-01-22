unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;
unsigned long roznicaCzasu = 0;
#define IN1 8 // GPIO 8
#define IN2 9 // GPIO 9
#define IN3 10 // GPIO 10
#define IN4 11 // GPIO 11
const int lengthSeq = 8;
int Step = 0;
int pin = 0;
int counter;
int stepsMatrix[lengthSeq][4] =
{
  {0, 0, 0, 1},  // 1
  {0, 0, 1, 1},  // 2
  {0, 0, 1, 0},  // 4
  {0, 1, 1, 0},  // 8
  {0, 1, 0, 0},  // 1
  {1, 1, 0, 0},  // 2
  {1, 0, 0, 0},  // 4
  {1, 0, 0, 1},  // 8
};
 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 
digitalWrite(IN1, 0);
digitalWrite(IN2, 0);
digitalWrite(IN3, 0);
digitalWrite(IN4,0);
pin = 0;
}
 
void fun(int  Mode, int speed, int Side,int StepCounter,int Spins)
{
  if(Mode == 1 && Step == 0)
  {
    Step = 1;  
  } 
StepCounter = StepCounter + (2048 * Spins);
  aktualnyCzas = millis();
  roznicaCzasu = aktualnyCzas - zapamietanyCzas;
        if (roznicaCzasu >= speed) 
    {
          zapamietanyCzas = aktualnyCzas;
  digitalWrite(IN1, stepsMatrix[Step][pin]);
    pin = Change(pin,Side,StepCounter,Mode);
    digitalWrite(IN2, stepsMatrix[Step][pin]);
    pin = Change(pin,Side,StepCounter,Mode);
    digitalWrite(IN3, stepsMatrix[Step][pin]);
    pin = Change(pin,Side,StepCounter,Mode);
    digitalWrite(IN4, stepsMatrix[Step][pin]);
    pin = Change(pin,Side,StepCounter,Mode);
    switch(Mode)
    {
      case 0:
         Step += 2;
          if(Step > 7)
      {
          Step = 0;
      }
       break;
      case 1:
       Step += 2;
          if(Step > 7)
      {
          Step = 1;
      }
      break;
      default:
             Step += 1;
          if(Step > 7)
      {
          Step = 0;
      }
    }
    }
}
 
 
int Change(int value, int Side,int Steps,int Mode)
{
  if( value == 0&& Side == 1)
  {
      value = 3;
  }
  else if(Side == 1)
  {
    value--;  
  }
 
  if(value == 3 && Side == 0)
  {
    value = 0;  
  }
  else if(Side ==0)
  {
    value ++;
 
  }
  counter = count(Steps,Mode);
  return value;
}
 
int count(int x,int Mode)
{
int   y = counter;
if(Mode == 2)
{
  x = x*2;  
}
  if(y == x*4)
  {
    delay(10000);
  y = 0;
  }
  else
  {
    y = counter +1;
  }
  return y;
}
 
void loop() {
  fun(2,2,0,0,1);
 
 
}
