// variable declartion for 
// the Arduino Pins that Relay is connected
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;
int IN7 = 7;
int IN8 = 8;
int IN9 = 9;
int IN10 = 10;
int IN11 = 11;
int IN12 = 12;
int IN13 = 13;
int INA0 = A0;
int INA1 = A1;
int INA2 = A2;
int INA3 = A3;
int INA4 = A4;
int INA5 = A5;

#define ON   0
#define OFF  1

void setup() 
{
  //Initialization
  relay_init();
}

void loop() {
  relay_SetStatus(ON, ON);//turn on RELAY Module 1 and 2
  delay(500);//delay half second
  relay_SetStatus(OFF, OFF);//turn on RELAY Module 1 and 2
  delay(500);//delay half second
}

//initialize Arduino PINS being used
//by Relay to OUTPUT MODE
void relay_init(void)
{  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);
  pinMode(IN13, OUTPUT);
  pinMode(INA0, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INA3, OUTPUT);
  pinMode(INA4, OUTPUT);
  pinMode(INA5, OUTPUT);
  
  relay_SetStatus(OFF,OFF);//turn off all the relay  
}

//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2)
{
  digitalWrite(IN2, status_1);
  digitalWrite(IN3, status_2);
  digitalWrite(IN4, status_1);
  digitalWrite(IN7, status_2);
  digitalWrite(IN8, status_1);
  digitalWrite(IN9, status_2);
  digitalWrite(IN10, status_1);
  digitalWrite(IN11, status_2);
  digitalWrite(IN12, status_1);
  digitalWrite(IN13, status_2);
  digitalWrite(INA0, status_1);
  digitalWrite(INA1, status_2);
  digitalWrite(INA2, status_1);
  digitalWrite(INA3, status_2);
  digitalWrite(INA4, status_1);
  digitalWrite(INA5, status_2);
}
