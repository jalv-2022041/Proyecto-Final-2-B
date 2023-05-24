//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//librerias
#include <Servo.h>
//directivas
#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 7
#define servo_salida 6
#define servo_entrada 5
//display
#define A 8
#define B 9
#define C 10
#define D 11
#define E 12
#define F 13
#define G 14
//variables
int carros = 0;
bool estado_s;
bool estado_e;
//Funciones
bool sensor_entrada();
bool sensor_salida();
void talanquera_entrada();
void talanquera_salida();
void conteo();
//constructores
Servo entrada;
Servo salida;
void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(echo2, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  salida.attach(servo_salida);
  entrada.attach(servo_entrada);
  }
void loop() {
 estado_e = sensor_entrada();
 talanquera_salida();
 estado_s = sensor_salida();
 talanquera_salida();
 conteo();
}
bool sensor_salida(){
  bool estado;
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  int t = pulseIn(echo1, HIGH);
  int d = t/59;
  if ( d < 10){
    estado = 1;
    }
    else{
      estado = 0;
    }
  return estado;
  }
bool sensor_entrada(){
  bool estado;
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  int t = pulseIn(echo2, HIGH);
  int d = t/59;
  if ( d < 10){
    estado = 1;
    }
    else{
      estado = 0;
    }
  return estado;
  }
void talanquera_salida(){
  if(estado_s == 1){
    if(carros > 0){ // No abre si no hay autos registrados
    salida.write(80);
    carros--;
    delay(1000);
    salida.write(0);    
    }
    }
  }
  void talanquera_entrada(){
  if(estado_e == 1){
    if(carros < 4){ // Si hay cupo
    entrada.write(80);
    carros++;
    delay(500);
    entrada.write(0);
    }
    if(carros = 4){ //parqueo lleno
    entrada.write(0);
    }
    }
  }
  void conteo(){
    switch(carros){
     case 0:
     digitalWrite(A, HIGH);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, HIGH);
     digitalWrite(E, HIGH);
     digitalWrite(F, HIGH);
     digitalWrite(G, LOW );
     break;

     case 1:
     digitalWrite(A, LOW);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW );
     break;
     
     case 2:
     digitalWrite(A, HIGH);
     digitalWrite(B, HIGH);
     digitalWrite(C, LOW);
     digitalWrite(D, HIGH);
     digitalWrite(E, HIGH);
     digitalWrite(F, LOW);
     digitalWrite(G, HIGH);
     break;
     
     case 3:
     digitalWrite(A, HIGH);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, HIGH);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, HIGH );
     break;
     
     case 4:
     digitalWrite(A, LOW);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, HIGH);
     digitalWrite(G, HIGH );
     break;
    }
    }
