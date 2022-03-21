#define PAD1 2 //Buttons pins
#define PAD2 3
#define PAD3 4
#define PAD4 5

//Arduino pins to which RGB LED connected
#define RED_LED 9  
#define GREEN_LED 10
#define BLUE_LED 11

// Variables to store PWM duty cycle for each LED

int Red=0, Blue=0, Green=0; //Color values to be affected to the RGB

//Boolean variable to store pad state

bool PAD1_State, PAD2_State, PAD3_State, PAD4_State; 


void setup() {
  
  Serial.begin(9600);        //Set Serial communication
  
  pinMode(PAD1,INPUT);    //Set pin modes
  pinMode(PAD2,INPUT);
  pinMode(PAD3,INPUT);
  pinMode(PAD4,INPUT);

  pinMode(RED_LED,OUTPUT);     
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  
}

void loop() {

  Serial.print(Red);     //Display the colors values on the serial monitor
  Serial.print("\t");
  Serial.print(Green);
  Serial.print("\t");
  Serial.println(Blue);
  
  
  PAD1_State = digitalRead(PAD1); //Read the buttons states
  PAD2_State = digitalRead(PAD2);
  PAD3_State = digitalRead(PAD3);
  PAD4_State = digitalRead(PAD4);

  analogWrite(RED_LED,Red);       //Write the values on the RGB
  analogWrite(GREEN_LED,Green);
  analogWrite(BLUE_LED,Blue);

  if(PAD1_State == HIGH)   //Button 1 controls the RED, 2 Green and 3 Blue
     Red+= 20;                //Everytime you press the value gets incremented by 20 you can change as you want
  if(Red >= 255)              //If it exceeds the limit it will be brought back to 0
     Red=0;

   if(PAD2_State == HIGH)
   Green+= 20;
  if(Green >= 255)
   Green=0;

   if(PAD3_State == HIGH)
   Blue+= 20;
   if(Blue >= 255)
   Blue=0;

   if(PAD4_State == HIGH){ //Button 4 resets the value to 0
    
    Red=0;
    Green=0;
    Blue=0;
    
   }
  delay(100); //To avoid that one touch gets counted as 10 or more, although 100 is pretty big you can reduce it and test
}
