//Vixen_arduino_uno_controll_16chv4.ino
#define HIGH 1
#define LOW  0

int A = 2;
int B = 3;
int C = 4;
int D = 7;
int E = 8;
int F = 9;
int G = 10;
int H = 11;
int I = 12;
int J = 13;
int K = A0;
int L = A1;
int M = A2;
int N = A3;
int O = A4;
int P = A5;


int triggerStart = 0;

#define RELAYCOUNT 16

int i = 0;
//Declare an array of integer
int incomingByte[16];

void setup()
{

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(I, OUTPUT);
  pinMode(J, OUTPUT);
  pinMode(K, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(N, OUTPUT);
  pinMode(O, OUTPUT);
  pinMode(P, OUTPUT);

  RelayActivation(~(1));

  Serial.begin(57600);
 

}

void loop()
{


  //There is available data on the serial port 
  //Check if the lenght is what we are expecting
  if (Serial.available() >= 18)
  {
   //Check if it is the header character
   if (Serial.read() == '~')
    {
		if (Serial.read() == '!')
		{
			// Turn off the Relay first on the first Sequence
			if (triggerStart == 0)
			{
				triggerStart = 1;
				RelayActivation(~(1));
			}
	
			// Loop thru the incoming data
			for (int i=0; i<RELAYCOUNT;i++)
			{
				incomingByte[i] = ~(Serial.read());
			}  
	
	
			digitalWrite(A, incomingByte[0]);  // Pin 2
			digitalWrite(B, incomingByte[1]);  // Pin 3
			digitalWrite(C, incomingByte[2]);  // Pin 4
			digitalWrite(D, incomingByte[3]);  // Pin 5
			digitalWrite(E, incomingByte[4]);  // Pin 6
			digitalWrite(F, incomingByte[5]);  // Pin 7
			digitalWrite(G, incomingByte[6]);  // Pin 8
			digitalWrite(H, incomingByte[7]);  // Pin 9
			digitalWrite(I, incomingByte[8]);  // Pin 10
			digitalWrite(J, incomingByte[9]);  // Pin 11
			digitalWrite(K, incomingByte[10]); // Pin 12
			digitalWrite(L, incomingByte[11]); // Pin 13
			digitalWrite(M, incomingByte[12]); // Pin A0
			digitalWrite(N, incomingByte[13]); // Pin A1
			digitalWrite(O, incomingByte[14]); // Pin A2
			digitalWrite(P, incomingByte[15]); // Pin A3
    
		} 

		else 
		{ // NO command turn of the LED

          RelayActivation(~(1));

        }
    }
     
  }
}

void RelayActivation(int RelayActivation)
{
          digitalWrite(A, RelayActivation);
          digitalWrite(B, RelayActivation);
          digitalWrite(C, RelayActivation);
          digitalWrite(D, RelayActivation);
          digitalWrite(E, RelayActivation);
          digitalWrite(F, RelayActivation);
          digitalWrite(G, RelayActivation);
          digitalWrite(H, RelayActivation);
          digitalWrite(I, RelayActivation);
          digitalWrite(J, RelayActivation);
          digitalWrite(K, RelayActivation);
          digitalWrite(L, RelayActivation);
          digitalWrite(M, RelayActivation);
          digitalWrite(N, RelayActivation);
          digitalWrite(O, RelayActivation);
          digitalWrite(P, RelayActivation);
}
