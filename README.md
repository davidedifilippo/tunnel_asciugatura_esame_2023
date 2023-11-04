## Tunnel_asciugatura_esame_2023

Simulazione tunnel asciugatura 2023

![scheda di simulazione del tunnel di asciugatura](http://mdp.tylingsoft.com/icon.png)

Bisogna fissare i piedini di controllo del LEDche simula la lampada ad infrarossi:

        const int pinSensorePresenzaPezzo = 2;  //pin collegamento del sensore presenza
        const int IR_Lamp_Pin = 12;  

Dichiaro le variabili necessarie:

        bool presenzaPezzo = false; //stato del sensore di presenza pezzo
        int HR_Numerico = 0;
        float HR = 100; 


## Fase di Setup:
  
      Serial.begin(9600);
      pinMode(IR_Lamp_Pin, OUTPUT);
      pinMode(pinSensorePresenzaPezzo, INPUT);

  

## Fase di loop:

Stampo il messaggio di attesa pezzo:
  
      Serial.println("Attesa pezzo...");
  
      while(!presenzaPezzo)
      presenzaPezzo = digitalRead(pinSensorePresenzaPezzo);

  Dato che il pezzo è presente accendo la lampada infrarossi:

      digitalWrite(IR_Lamp_Pin, HIGH); 

  Lascio asciugare fino ada arrivare ad umidità relativa sotto il 10%:
  
      while(HR>=10)
      {
        HR_Numerico = analogRead(0);
        HR = (HR_Numerico / 1023.0)*100;
        //controllo 
        Serial.print("HR= ");
        Serial.println(HR);
        delay(500);
    
      }

  Esco dal ciclo se HR è minore del 10%:
  
      Serial.println("pezzo asciutto...");
      digitalWrite(IR_Lamp_Pin, LOW); //lampada infrarossi OFF

 Tolgo il pezzo:
 
      presenzaPezzo = false;
  
  


