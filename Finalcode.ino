// constants won't change. They're used here to set pin numbers:
const int buttonPin0 = 2; // the number of the pushbutton pin
const int buttonPin1 = 3;
const int buttonPin2 = 4;
const int buttonPin3 = 5;
 

const int O0 =  10; // the number of the LED pin
const int O1 =  11;
const int O2 =  12;
const int O3 =  13;

// variables will change:
int I0 = 0;  // variable for reading the pushbutton status
int I1 = 0;
int I2 = 0;
int I3 = 0;

void setup() {
  // initialize the LED pin as an output:
 // Serial.begin(9600);
  pinMode(O0, OUTPUT);
  pinMode(O1, OUTPUT);
  pinMode(O2, OUTPUT);
  pinMode(O3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(I0, INPUT);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(I3, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  I0 = digitalRead(buttonPin0);
  I1 = digitalRead(buttonPin1);
  I2 = digitalRead(buttonPin2);
  I3 = digitalRead(buttonPin3);

  // check the input for output
  int x =(not I0 && not I2);
  int y =(I0 && not I2);
  int z =(I0 && not I1);
  int  output0 =((not I1 && not I2)||(x && not I3) || (y && I3) || ( z && not I3));
  digitalWrite(O0,output0);

  int output1 =((not I0 && not I1 && I3) || (I1 && not I2 && not I3) || (I0 && not I2 && I3) || (I0 && I1) || (I2 && not I3));
  digitalWrite(O1,output1);

  int output2 =((I2 && I3) || (I1 && I3) || (not I0 && I1 && I2) || (not I0 && not I1 && not I2 && not I3));
  digitalWrite(O2,output2);

  int output3 =((I1 && not I2 && not I3) || (not I0 && I1 && I3) || (I0 && I2 && I3) || (not I1 && I2 && not I3));
  digitalWrite(O3,output3);

  
 /* Serial.println(I0);
  Serial.println(I1);
  Serial.println(I2);
  Serial.println(I3);
  
 
  
  delay(1000);*/
}
