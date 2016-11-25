
int led1 = D7;
int led2 = D3;

int reading = 0;
double volts = 0.0;
int analogPin = A0;

boolean HCPblink = false;

void setup()
{
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   Particle.function("HCPSwitchLed",HCPledToggle);
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   
    Spark.variable("analog", &reading, INT);
    Spark.variable("volts", &volts, DOUBLE);

}


void loop()
{
    
   if (HCPblink) {
        digitalWrite(led1, HIGH);
        delay(200);
        digitalWrite(led1, LOW);
        delay(400);
        digitalWrite(led2, HIGH);
        delay(200);
        digitalWrite(led2, LOW);
        delay(400);
        
        reading = analogRead(analogPin);
        volts = reading * 3.3 / 4096.0;
    }
}


int HCPledToggle(String command) {

    if (command=="on") {
       HCPblink = true;
        return 1;
    }
    else if (command=="off") {
       HCPblink = false;
        return 0;
    }
    else {
        return -1;
    }
}
