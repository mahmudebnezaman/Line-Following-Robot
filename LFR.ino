int In1 =7;///motor 1
int In2 =8;

int In3 =9; //motor2
int In4 =10;

int En1=6; //Enable pin 1
int En2=5;   //Enable pin 2

int S1=A4;//left
int S2=A3;
int S3=A2;
int S4=A1;
int S5=A0;    // Sensor pin

int s1,s2,s3,s4,s5; //Sensor Data

void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(En1, OUTPUT);
  pinMode(En2, OUTPUT);
  
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
  
  Serial.begin(9600);
  
  analogWrite(En1,255);
  analogWrite(En2,255);
}

void loop()
{
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  
  
  Serial.print(s1);
  Serial.print(s2);
  Serial.print(s3);
  Serial.print(s4);
  Serial.println(s5);
  
  
  if (s1==1 && s2==1 && s3==0 && s4==1 && s5==1){
  forward();
  }else if (s1==1 && s2==1 && s3==1 && s4==0 && s5==1){
  right();
  }else if (s1==1 && s2==1 && s3==1 && s4==1 && s5==0){
  right();
  }else if (s1==1 && s2==1 && s3==1 && s4==0 && s5==0){
  right();
  }else if (s1==1 && s2==1 && s3==0 && s4==0 && s5==0){
  right();
  }else if (s1==1 && s2==0 && s3==0 && s4==0 && s5==0){
  right();
  }else if (s1==1 && s2==0 && s3==1 && s4==1 && s5==1){
  left();
  } else if (s1==0 && s2==0 && s3==0 && s4==1 && s5==1){
  left();
  } else if (s1==0 && s2==1 && s3==1 && s4==1 && s5==1){
  left();
  }else if (s1==0 && s2==0 && s3==1 && s4==1 && s5==1){
  left();
  }else if (s1==0 && s2==0 && s3==0 && s4==0 && s5==1){
  left();
  }else if (s1==0 && s2==0 && s3==0 && s4==0 && s5==0){
  stop();
  }
}


int forward(){
  analogWrite(En1,220);
  analogWrite(En2,220);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);

}

int left(){
  analogWrite(En1,100);
  analogWrite(En2,100);
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, HIGH);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);

}

int right(){
  analogWrite(En1,100);
  analogWrite(En2,100);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

int stop(){
  analogWrite(En1,0);
  analogWrite(En2,0);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
