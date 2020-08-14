void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);

}
void moverobot(String motion){
  if(motion == "forward"){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  if(motion == "stop"){
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(13,LOW);
  }
  if(motion == "right"){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  if(motion == "left"){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
   if(motion == "back"){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  
}
void turnleft(){
  Serial.println("turnleft");

  int M_temp = 1;

  while(M_temp != 0){
    moverobot("left");
    delay(100);
    moverobot("stop");
    delay(100);

    M_temp = digitalRead(3);
    
  }
}

void turnright(){
  Serial.println("turnright");

  int L_temp = 1;

  while(L_temp != 0){
    moverobot("right");
    delay(100);
    moverobot("stop");
    delay(100);

    L_temp = digitalRead(2);
    
  }
}


void loop() {
  // put your main code here, to run repeatedly:
int l = digitalRead(2);
int m = digitalRead(3);
int r = digitalRead(4);
if(l==0 && m==1 && r==1){
  turnleft();
}
if(l==0 && m==0 && r==0){
  turnleft();
}
if(l==0 && m==0 && r==1){
  turnleft();
}
if(l==1 && m==1&& r==0){
  moverobot("forward");
  delay(100);
  moverobot("stop");
  delay(100);
}
if(l==1 && m==1 && r==1){
  moverobot("forward");
  delay(100);
  moverobot("stop");
  delay(100);
}
if(l==1 && m==0 && r==0){
  moverobot("forward");
  delay(100);
  moverobot("stop");
  delay(100);
  turnright();
}
if(l==1 && m==0 && r==1){
  moverobot("forward");
  delay(100);
  moverobot("stop");
  delay(100);
  int l_temp = digitalRead(2);
  int m_temp = digitalRead(3);
  int r_temp = digitalRead(4);
  if(l_temp==1 && m_temp==0 && r_temp==1){
    turnleft();
    
  }
}
if(l==0 && m==1 && r==0){
  moverobot("forward");
  delay(100);
  moverobot("stop");
  delay(100);
  int l_temp = digitalRead(2);
  int m_temp = digitalRead(3);
  int r_temp = digitalRead(4);
  if(l_temp==0 && m_temp==1 && r_temp==0){
    moverobot("stop");
    exit(0);
    
  }
  else{
    turnleft();
  }
}
 }
 
