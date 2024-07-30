byte led = 12;

// BSL measurement
unsigned long measure_aoc();

unsigned int int_time = 5000;
unsigned long aoc = 0;



//##############################################

void setup() {
  pinMode(led, OUTPUT);
  
  Serial.begin(112500);
}

//##############################################

void loop() {

  aoc = measure_aoc();
  Serial.println(aoc);

  delay(20000);
}
//##############################################
unsigned long measure_aoc(){
  unsigned long blank = 0;
  unsigned long aoc_time = 0;
  aoc_time = millis();
  
  while(millis() < aoc_time+int_time){
    int input = analogRead(A0);
    blank += 1023 - input;
  }
  
  digitalWrite(led, HIGH);
  aoc = 0;
  
  aoc_time = millis();

  while(millis() < aoc_time+int_time){
    int input = analogRead(A0);
    aoc += 1023 - input;
  }

  aoc = aoc - blank;
  
  digitalWrite(led, LOW);
    
  return(aoc);
}
 

//##############################################
