int pin = A2; //Initialize an integer variable 'pin' and then assign the value A2 to it 
//This sets the analog input pin to read the temperature sensor's data
void setup() { //setup() function which only once when device is powered on or rest 
  pinMode(pin, INPUT);//sets the pin variable as an input which use to read data from the temperature sensor
}

void loop() {//loop function which runs repeatedly after setup function finished execution
  String temp = String (analogRead(pin));//reads the voltage on the analog input pin and converts it into a digital value
                                        //This value represents the temperature reading from the sensor
                                        //The temperature value is then converted to a string
  Particle.publish("temp", temp, PRIVATE);//publishes the temperature data to the Particle cloud with an event name of "temp"
                                            //and the temperature data as its data payload
                                            //This data can be viewed in the Particle console 
  delay(30000);             // adds a 30-second delay before the code is executed again
                            //to prevent the device from overwhelming the cloud with data 
} 