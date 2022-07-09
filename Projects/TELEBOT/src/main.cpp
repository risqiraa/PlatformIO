#include <Arduino.h> // library arduino
#include <CTBot.h> // library telegram bot

CTBot myBot;

String ssid  = "HARIINNN"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "00000000"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

uint8_t led1 = D1;           
uint8_t led2 = D2;           
uint8_t led3 = D3;           
uint8_t led4 = D5;           
uint8_t led5 = D6;           
uint8_t led6 = D7;           


//*START VOID SETUP
void setup() {
	// initialize the Serial
	Serial.begin(115200);

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);
	
	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");
		
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(led5, OUTPUT);
	pinMode(led6, OUTPUT);

	digitalWrite(led1, LOW); 
	digitalWrite(led2, LOW); 
	digitalWrite(led3, LOW); 
	digitalWrite(led4, LOW); 
	digitalWrite(led5, LOW); 
	digitalWrite(led6, LOW); 
	
}
//*END VOID SETUP


//*START VOID LOOP
void loop() {
  	TBMessage msg;

	// if there is an incoming message...
	if (CTBotMessageText == myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("L1 ON")) {              
			digitalWrite(led1, HIGH);                              
			myBot.sendMessage(msg.sender.id, "L1 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L1 OFF")) {      
			digitalWrite(led1, LOW);                              
			myBot.sendMessage(msg.sender.id, "L1 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("L2 ON")) {             
			digitalWrite(led2, HIGH);                              
			myBot.sendMessage(msg.sender.id, "L2 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L2 OFF")) {       
			digitalWrite(led2, LOW);                             
			myBot.sendMessage(msg.sender.id, "L2 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("L3 ON")) {           
			digitalWrite(led3, HIGH);                             
			myBot.sendMessage(msg.sender.id, "L3 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L3 OFF")) {        
			digitalWrite(led3, LOW);                             
			myBot.sendMessage(msg.sender.id, "L3 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("L4 ON")) {          
			digitalWrite(led4, HIGH);                              
			myBot.sendMessage(msg.sender.id, "L4 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L4 OFF")) {       
			digitalWrite(led4, LOW);                            
			myBot.sendMessage(msg.sender.id, "L4 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("L5 ON")) {              
			digitalWrite(led5, HIGH);                              
			myBot.sendMessage(msg.sender.id, "L5 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L5 OFF")) {        
			digitalWrite(led5, LOW);                              
			myBot.sendMessage(msg.sender.id, "L5 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("L6 ON")) {             
			digitalWrite(led6, HIGH);                               
			myBot.sendMessage(msg.sender.id, "L6 is now ON ");  
		}
		else if (msg.text.equalsIgnoreCase("L6 OFF")) {        
			digitalWrite(led6, LOW);                              
			myBot.sendMessage(msg.sender.id, "L6 is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("ALL ON")) {        
			digitalWrite(led1, HIGH);                              
			digitalWrite(led2, HIGH);                              
			digitalWrite(led3, HIGH);                              
			digitalWrite(led4, HIGH);                              
			digitalWrite(led5, HIGH);                              
			digitalWrite(led6, HIGH);                              
			myBot.sendMessage(msg.sender.id, "ALL Lamp is now OFF"); 
		}
		else if (msg.text.equalsIgnoreCase("ALL OFF")) {        
			digitalWrite(led1, LOW);                              
			digitalWrite(led2, LOW);                              
			digitalWrite(led3, LOW);                              
			digitalWrite(led4, LOW);                              
			digitalWrite(led5, LOW);                              
			digitalWrite(led6, LOW);                              
			myBot.sendMessage(msg.sender.id, "ALL Lamp is now OFF"); 
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



