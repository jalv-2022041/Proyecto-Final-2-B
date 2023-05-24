#include <Adafruit_NeoPixel.h>// Incluye la librería para controlar los LEDs NeoPixel
#define numerodeleds 7// Número de LEDs en el neopixel
#define pinled 2// Pin al que está conectada el neopixel
int LDR=0;//Pin analógico para la fotoresistencia 1
int valorLDR=0;//Almacena el valor leído de la fotoresistencia 1
int LDR2=1;//Pin analógico para la fotoresistencia 2
int valorLDR2=0;//Almacena el valor leído de la fotoresistencia 2
int LDR3=2;//Pin analógico para la fotoresistencia 3
int valorLDR3=0;//Almacena el valor leído de la fotoresistencia 3
int LDR4=3;//Pin analógico para la fotoresistencia 4
int valorLDR4 = 0;//Almacena el valor leído de la fotoresistencia 4
int Luz=900; //Umbral de luz para la fotoresistencia 1
int Luz2=900;//Umbral de luz para la fotoresistencia 2
int Luz3=900;//Umbral de luz para la fotoresistencia 3
int Luz4=900;//Umbral de luz para la fotoresistencia 4


Adafruit_NeoPixel neopix(numerodeleds,pinled,NEO_GRB + NEO_KHZ800);// Crear una instancia de la clase Adafruit_NeoPixel

void setup(){
  Serial.begin(9600);
  neopix.begin();//Inicializa la matriz de neopixel
  neopix.show();//Muestra los cambios en la matriz neopixel
}
void loop(){
  parqueo1();//Función de control para el parqueo 1
  parqueo2();//Función de control para el parqueo 2
  parqueo3();//Función de control para el parqueo 3
  parqueo4();//Función de control para el parqueo 4
}

void parqueo1(){
   valorLDR=analogRead(LDR);//Lee el valor de la fotoresistencia 1
   if (valorLDR <= Luz){//Compara el valor leído con el umbral de luz
    neopix.setPixelColor(0,neopix.Color(0,255,0));//Establece el color del LED en verde
    neopix.show();//Muestra los cambios en el neopixel
  }
  else{
    neopix.setPixelColor(0,neopix.Color(255,0,0));//Establece el color del LED en rojo
    neopix.show();//Muestra los cambios en el neopixel
  }
}
void parqueo2(){
  valorLDR2=analogRead(LDR2);//Lee el valor de la fotoresistencia 2
  if (valorLDR2 <= Luz2){//Compara el valor leído con el umbral de luz
    neopix.setPixelColor(1,neopix.Color(0,255,0));//Establece el color del LED en verde
    neopix.show();//Muestra los cambios en el neopixel
  }
  else{
    neopix.setPixelColor(1,neopix.Color(255,0,0));//Establece el color del LED en rojo
    neopix.show();//Muestra los cambios en el neopixel
  }
}
void parqueo3(){
  valorLDR3=analogRead(LDR3);//Lee el valor de la fotoresistencia 3
  if (valorLDR3 <= Luz3){//Compara el valor leído con el umbral de luz
    neopix.setPixelColor(2,neopix.Color(0,255,0));//Establece el color del LED en verde
    neopix.show();//Muestra los cambios en el neopixel
  }
  else{
    neopix.setPixelColor(2,neopix.Color(255,0,0));//Establece el color del LED en rojo
    neopix.show();//Muestra los cambios en el neopixel
  }
}
void parqueo4(){
  valorLDR4=analogRead(LDR4);//Lee el valor de la fotoresistencia 4
  if (valorLDR4 <= Luz4){//Compara el valor leído con el umbral de luz
    neopix.setPixelColor(5,neopix.Color(0,255,0));//Establece el color del LED en verde
    neopix.show();//Muestra los cambios en el neopixel
  }
  else{
    neopix.setPixelColor(5,neopix.Color(255,0,0));//Establece el color del LED en rojo
    neopix.show();//Muestra los cambios en el neopixel
  }
}
