
/*
	Define pin numbers
    Variable to store off/on state
    Array to store activation LED state pattern
    variable for flash frequency
    variable to store led pattern/combination
    variable to store last time the button has changed
    variable to store the timer
*/

//Pin numbers
const int Button1_Pin = 2;
const int Button2_Pin = 3;

const int LED1_Pin = 8;
const int LED2_Pin = 9;
const int LED3_Pin = 10;

bool On_Off_State = HIGH;
bool LED_Activation_States[3] = {true, false, false};

int flash_frequency = 1500;
int Selected_Pattern = 1;

unsigned long Last_Time_Button1_Pressed = 0;
unsigned long Last_Time_Button2_Pressed = 0;
unsigned long flash_timer = 0;
int Debounce_Delay = 50;


void setup()
{
  pinMode(LED1_Pin, OUTPUT);
  pinMode(LED2_Pin, OUTPUT);
  pinMode(LED3_Pin, OUTPUT);
  pinMode(Button1_Pin, INPUT);
  pinMode(Button2_Pin, INPUT);
  Serial.begin(9600);
}

void Flash_LEDs(){
  
  if ( millis() > (flash_timer + flash_frequency)){
    On_Off_State = !On_Off_State;
    flash_timer = millis();
    
  }
  
  Serial.println(flash_timer);
  
  if (LED_Activation_States[0] == true){
    digitalWrite(LED1_Pin, On_Off_State);
  }
  else {
    digitalWrite(LED1_Pin, LOW);
  }

  if (LED_Activation_States[1] == true){
    digitalWrite(LED2_Pin, On_Off_State);
  }
  else {
    digitalWrite(LED2_Pin, LOW);
  }
  
  if (LED_Activation_States[2] == true){
    digitalWrite(LED3_Pin, On_Off_State);
  }
  else {
    digitalWrite(LED3_Pin, LOW);
  }
  
}


void loop()
{
  bool Button1_Read = digitalRead(Button1_Pin);
  bool Button2_Read = digitalRead(Button2_Pin);
  
  // check if button1 has been pressed
  if (Button1_Read == HIGH){
    if ( (millis() - Last_Time_Button1_Pressed) > Debounce_Delay){
 		flash_frequency = flash_frequency / 2;
    }
    
    if (flash_frequency < 40){
      flash_frequency = 1500;
    }
    Last_Time_Button1_Pressed = millis();
  }
    
  // check if button2 has been pressed
  if (Button2_Read == HIGH){
    if ( (millis() - Last_Time_Button2_Pressed) > Debounce_Delay){
 		Selected_Pattern++; 
    }
    
    if (Selected_Pattern > 7){
      Selected_Pattern = 0;
    }
    
    switch (Selected_Pattern){
      case 0:
      	LED_Activation_States[0] = false;
      	LED_Activation_States[1] = false;
      	LED_Activation_States[2] = false;
    	break;  
      case 1:
      	LED_Activation_States[0] = true;
      	LED_Activation_States[1] = false;
      	LED_Activation_States[2] = false;
    	break;
      case 2:
      	LED_Activation_States[0] = false;
      	LED_Activation_States[1] = true;
      	LED_Activation_States[2] = false;
    	break;
      case 3:
      	LED_Activation_States[0] = false;
      	LED_Activation_States[1] = false;
      	LED_Activation_States[2] = true;
    	break;
      case 4:
      	LED_Activation_States[0] = true;
      	LED_Activation_States[1] = true;
      	LED_Activation_States[2] = false;
    	break;
      case 5:
      	LED_Activation_States[0] = false;
      	LED_Activation_States[1] = true;
      	LED_Activation_States[2] = true;
    	break;
      case 6:
      	LED_Activation_States[0] = true;
      	LED_Activation_States[1] = false;
      	LED_Activation_States[2] = true;
    	break;
      case 7:
      	LED_Activation_States[0] = true;
      	LED_Activation_States[1] = true;
      	LED_Activation_States[2] = true;
    	break;
    }
    
    Last_Time_Button2_Pressed = millis();
  }
  
  Flash_LEDs();
}
