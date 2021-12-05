#define sen1 A0
#define sen2 A1
int led1=3,led2=4,led3=5, pump_rly=3;
void setup()
{
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pump_rly,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(pump_rly,LOW);
  Serial.begin(9600);
  Serial.println("automatic irrigation system using arduino");
}

void loop()
{
  // put your main code here, to run repeatedly:
  int sen1_value, sen2_value,soil_moisture_level_1,soil_moisture_level_2;
  sen1_value = analogRead(sen1);
  sen2_value = analogRead(sen2); 
  soil_moisture_level_1 = map(sen1_value,200,1020,100,1);
  soil_moisture_level_2 = map(sen2_value,200,1020,100,1);
  Serial.print("Soil Moisture level in POT 1: ");
  Serial.print(soil_moisture_level_1);
  Serial.println("%");
  Serial.print("Soil Moisture level in POT 2: ");
  Serial.print(soil_moisture_level_2);
  Serial.println("%");

 

  

  if((soil_moisture_level_1<10) || (soil_moisture_level_2<10))
    {
      Serial.println("PUMP ON");
      digitalWrite(pump_rly,HIGH);
      
    }

  if((soil_moisture_level_1>94) && (soil_moisture_level_2>94))
  {
    Serial.println("PUMP OFF");
    digitalWrite(pump_rly,LOW);
  }
  delay(3000);
}
