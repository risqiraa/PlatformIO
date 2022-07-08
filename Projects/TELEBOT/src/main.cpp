#include <Arduino.h> // library arduino
#include <CTBot.h> // library telegram bot

CTBot myBot;

String ssid  = "HARIINNN"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "00000000"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

uint8_t led = 2;            // the onboard ESP8266 LED.    
                            // If you have a NodeMCU you can use the BUILTIN_LED pin
                            // (replace 2 with BUILTIN_LED)	


//*START VOID SETUP
void setup() {
	// initialize the Serial
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);
	
	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");
		
	pinMode(led, OUTPUT);
	digitalWrite(led, HIGH); // turn off the led (inverted logic!)
}
//*END VOID SETUP


//*START VOID LOOP
void loop() {
  	TBMessage msg;

	// if there is an incoming message...
	if (CTBotMessageText == myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("LIGHT ON")) {              // if the received message is "LIGHT ON"...
			digitalWrite(led, LOW);                               // turn on the LED (inverted logic!)
			myBot.sendMessage(msg.sender.id, "Light is now ON YEY");  // notify the sender
		}
		else if (msg.text.equalsIgnoreCase("LIGHT OFF")) {        // if the received message is "LIGHT OFF"...
			digitalWrite(led, HIGH);                              // turn off the led (inverted logic!)
			myBot.sendMessage(msg.sender.id, "Light is now OFF"); // notify the sender
		}
		else {                                                    // otherwise...
			// generate the message for the sender
			String reply;
			reply = (String)"Welcome " + msg.sender.username + (String)". Try LIGHT ON or LIGHT OFF.";
			myBot.sendMessage(msg.sender.id, reply);             // and send it
		}
	}
	// wait 500 milliseconds
	delay(500);
}
//*END VOID LOOP


//*START VOID CEK KONEKSI
void cekkoneksi() {
	
}
//*END VOID CEK KONEKSI


//*START VOID GREETING
void greeting(){ 
  TBMessage msg;
  myBot.sendMessage(msg.sender.id, "HAI ADMINISTRATOR");
}
//*END VOID GREETING