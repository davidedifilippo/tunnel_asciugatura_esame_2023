const int pinSensorePresenzaPezzo = 2;  // pin collegamento del sensore presenza
const int ledPin = 12;   

bool presenzaPezzo = false; //stato del sensore di presenza pezzo
int HR_Numerico = 0;
float HR = 100; 


void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pinSensorePresenzaPezzo, INPUT);
}

void loop() {
  
  Serial.println("Attesa pezzo...");
  
  while(!presenzaPezzo)
  presenzaPezzo = digitalRead(pinSensorePresenzaPezzo);

  digitalWrite(ledPin, HIGH);  //lampada infrarossi ON
  
  while(HR>=10)
  {
    HR_Numerico = analogRead(0);
    HR = (HR_Numerico / 1023.0)*100;
    //controllo 
    Serial.print("HR= ");
    Serial.println(HR);
    delay(500);
    
  }
   
  Serial.println("pezzo asciutto...");
  digitalWrite(ledPin, LOW); //lampada infrarossi OFF
  presenzaPezzo = false;
  
  
}
