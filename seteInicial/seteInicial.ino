/*Para el relay primera pata positivo segunda va al arduino y tercera al negativo, la referencia es (- + s)*/
void setup() {
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite (0, LOW);/*NADA*/
  digitalWrite (13, LOW);/*NADA*/
  digitalWrite (1, HIGH);/*luz AMARILLA*/
  digitalWrite (6, HIGH);/*Ventilador led AMARILLA*/
  digitalWrite (2, HIGH);/*luz VIOLETA*/
  digitalWrite (8, HIGH);/*Ventilador led VIOLETA*/
  digitalWrite (7, HIGH);/*luz BLANCA*/
  digitalWrite (4, HIGH);/*Ventilador led BLANCA*/
  
  
  digitalWrite (5, LOW);/*vALVULA INTERIOR*/

  
  digitalWrite (3, HIGH);/*Extractor*/

  
  digitalWrite (9,  LOW);/*vALVULA A*/
  digitalWrite (10, LOW);/*vALVULA B*/
  digitalWrite (11, LOW);/*vALVULA C*/
  digitalWrite (12, LOW);/*vALVULA D*/

  int lecturaA0 = analogRead(A0);/* MEDIDOR MEDIO*/
  int lecturaPorcentajeA0 = map(lecturaA0,1023,0,0,100);

  int lecturaA2 = analogRead(A2);/* MEDIDOR ALTO*/
  int lecturaPorcentajeA2 = map(lecturaA2,1023,0,0,100);

  int lecturaA1 = analogRead(A1);/* MEDIDOR BAJO*/
  int lecturaPorcentajeA1 = map(lecturaA1,1023,0,0,100);
}
  
