#include <Servo.h>

int servoPin = 8;
int servoPos = 0;
Servo miServo;

int estado = 0;
int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int boton1 = 1;
int boton2 = 2;
int boton3 = 3;
int boton4 = 4;
int trig = 9;
int  eco= 10;
int duracion;
int distancia;


void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(trig, OUTPUT);
 pinMode(eco, INPUT);
}

void loop() {
 
  estado3= digitalRead(boton4);
  estado2= digitalRead(boton3);
  estado1 = digitalRead(boton2);
  estado = digitalRead(boton1);

  if(estado2 == HIGH){
     
       int valorRecibido;
       valorRecibido = multiplicar(5,6);
       if(valorRecibido ==30){
      digitalWrite(11, HIGH);
      delay(2000);
      digitalWrite(11, LOW);
  }
    }
    if(estado1 == HIGH){
       servoM();
    }
    if(estado ==HIGH){
      secuencia();
    }
    if(estado ==HIGH){
      ultrasonico();
    }
   }
   int multiplicar ( int x, int y){
  int resultado;
  resultado = x*y;
  return resultado;
}

void servoM(){
   miServo.attach(servoPin);
  miServo.write(servoPos);
  delay(1000);
  miServo.write(90);
}
void secuencia(){
  for(int i = 5; i<8;i++){
    digitalWrite(i,1);
    delay(1000);
        digitalWrite(i,0);
    
  }
}
void ultrasonico(){
  Serial.begin(9600);
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
    distancia = duracion / 58.2;
  Serial.println(distancia);
  delay(200);
}
