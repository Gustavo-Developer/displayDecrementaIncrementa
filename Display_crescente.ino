#include <EEPROM.h>

/* Display crescente e decrescente de 7 segmentos. */

int contador; 
int segA=1;
int segB=2;
int segC=3;
int segD=4;
int segE=5;
int segF=6;
int segG=7;
int segPD=0;
int bt=A0;
int bt2=A3;
int Delay=250;

void setup() {                
  
 pinMode (segA,OUTPUT);
 pinMode (segB,OUTPUT);
 pinMode (segC,OUTPUT);
 pinMode (segD,OUTPUT);
 pinMode (segE,OUTPUT);
 pinMode (segF,OUTPUT);
 pinMode (segG,OUTPUT);
 pinMode (segPD,OUTPUT);
 pinMode (bt,INPUT_PULLUP);
 pinMode (bt2,INPUT_PULLUP);
 contador=EEPROM.read (0);
 if (contador==0xFF) contador=0;
 atualiza();
}


void loop() {

 //incrementa bt1
  if (digitalRead(bt)==0 && contador<9){
 contador++;
                                                                      //Salvar na EEPROM  EEPROM.write (end.,valor);
 EEPROM.write(0,contador);
 atualiza();
  }
  
  //decrementa bt2
 if (digitalRead(bt2)==0 && contador>0){
   contador--;
   EEPROM.write(0,contador);
 atualiza();
 }


}

    void atualiza(){
         if (contador==0) zero();
         if (contador==1) one();
         if (contador==2) two();
         if (contador==3) three();
         if (contador==4) four();
         if (contador==5) five();
         if (contador==6) six();
         if (contador==7) seven();
         if (contador==8) eight();
         if (contador==9) nine();
    }

    
 //Number 0
    void zero(){
  digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,1); 
 digitalWrite (segF,1); 
 digitalWrite (segG,0); 
 digitalWrite (segPD,0);
   delay (Delay);
    }
    
   //Number 1
   void one(){ 
 digitalWrite (segA,0);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,0); 
 digitalWrite (segE,0); 
 digitalWrite (segF,0); 
 digitalWrite (segG,0); 
 digitalWrite (segPD,0);
   delay (Delay);
   }

 //Number 2
   void two(){
 digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,0); 
 digitalWrite (segD,1); 
 digitalWrite (segE,1); 
 digitalWrite (segF,0); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
   delay (Delay);
   }

  //Number 3
   void three(){
 digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,0); 
 digitalWrite (segF,0); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
   delay (Delay);
   }

 //Number 4
   void four(){
 digitalWrite (segA,0);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,0); 
 digitalWrite (segE,0); 
 digitalWrite (segF,1); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
   delay (Delay);
   }

   //Number 5
   void five(){
 digitalWrite (segA,1);
 digitalWrite (segB,0);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,0); 
 digitalWrite (segF,1); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
   delay (Delay);
   }

   //Number 6
  void six(){
 digitalWrite (segA,1);
 digitalWrite (segB,0);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,1); 
 digitalWrite (segF,1); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
   delay (Delay);
  }

   //Number 7
  void seven(){
 digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,0); 
 digitalWrite (segE,0); 
 digitalWrite (segF,0); 
 digitalWrite (segG,0); 
 digitalWrite (segPD,0);
   delay (Delay);
  } 

   //Number 8
  void eight(){
 digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,1); 
 digitalWrite (segF,1); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
  delay (Delay);
  }

   //Number 9
  void nine(){
 digitalWrite (segA,1);
 digitalWrite (segB,1);
 digitalWrite (segC,1); 
 digitalWrite (segD,1); 
 digitalWrite (segE,0); 
 digitalWrite (segF,1); 
 digitalWrite (segG,1); 
 digitalWrite (segPD,0);
  delay (Delay);
  }

    //Number NULL
  void nulo(){
 digitalWrite (segA,0);
 digitalWrite (segB,0);
 digitalWrite (segC,0); 
 digitalWrite (segD,0); 
 digitalWrite (segE,0); 
 digitalWrite (segF,0); 
 digitalWrite (segG,0); 
 digitalWrite (segPD,0);
   delay (Delay);
  }
       


