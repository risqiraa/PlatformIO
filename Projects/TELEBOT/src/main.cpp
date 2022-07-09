#include <Arduino.h> // library arduino
#include <CTBot.h>	 // library telegram bot

CTBot myBot;
TBMessage msg;

String ssid = "HARIINNN";										 // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "00000000";										 // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5424171815:AAGYT8if_KMlM0KrPWr1yDG64oL227IT6D0"; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

uint8_t led1 = D1;
uint8_t led2 = D2;
uint8_t led3 = D3;
uint8_t led4 = D5;
uint8_t led5 = D6;
uint8_t led6 = D7;

//!----------------------------------------------------------->
//*START VOID SETUP
void setup()
{

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

//!------------------------------------------------------>
//*VOID L1 START
void L1ON()
{
	digitalWrite(led1, HIGH);
	myBot.sendMessage(msg.sender.id, "L1 is now ON ");
}
void L1OFF()
{
	digitalWrite(led1, LOW);
	myBot.sendMessage(msg.sender.id, "L1 is now OFF");
}
//*VOID L1 END

//*VOID L2 START
void L2ON()
{
	digitalWrite(led2, HIGH);
	myBot.sendMessage(msg.sender.id, "L2 is now ON ");
}
void L2OFF()
{
	digitalWrite(led2, LOW);
	myBot.sendMessage(msg.sender.id, "L2 is now OFF");
}
//*VOID L2 END

//*VOID L3 START
void L3ON()
{
	digitalWrite(led3, HIGH);
	myBot.sendMessage(msg.sender.id, "L3 is now ON ");
}

void L3OFF()
{
	digitalWrite(led3, LOW);
	myBot.sendMessage(msg.sender.id, "L3 is now OFF");
}
//*VOID L3 END

//*VOID L4 START
void L4ON()
{
	digitalWrite(led4, HIGH);
	myBot.sendMessage(msg.sender.id, "L4 is now ON ");
}

void L4OFF()
{
	digitalWrite(led4, LOW);
	myBot.sendMessage(msg.sender.id, "L4 is now OFF");
}
//*VOID L4 END

//*VOID L5 START
void L5ON()
{
	digitalWrite(led5, HIGH);
	myBot.sendMessage(msg.sender.id, "L5 is now ON ");
	digitalWrite(led5, LOW);
	myBot.sendMessage(msg.sender.id, "L5 is now OFF");
}

void L5OFF()
{
}
//*VOID L5 END

//*VOID L6 START
void L6ON()
{
	digitalWrite(led6, HIGH);
	myBot.sendMessage(msg.sender.id, "L6 is now ON ");
}

void L6OFF()
{
	digitalWrite(led6, LOW);
	myBot.sendMessage(msg.sender.id, "L6 is now OFF");
}
//*VOID L6 END

//*VOID ALL START
void ALLLAMPON()
{
	digitalWrite(led1, HIGH);
	digitalWrite(led2, HIGH);
	digitalWrite(led3, HIGH);
	digitalWrite(led4, HIGH);
	digitalWrite(led5, HIGH);
	digitalWrite(led6, HIGH);
	myBot.sendMessage(msg.sender.id, "ALL Lamp is now ON");
}

void ALLLAMPOFF()
{
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);
	digitalWrite(led5, LOW);
	digitalWrite(led6, LOW);
	myBot.sendMessage(msg.sender.id, "ALL Lamp is now OFF");
}
//*VOID ALL END

//!-------------------------------------------------------------------------------->
//*START VOID LOOP
void loop()
{
	// if there is an incoming message...
	if (CTBotMessageText == myBot.getNewMessage(msg))
	{

		if (msg.text.equalsIgnoreCase("L1 ON"))
		{
			L1ON();
		}
		else if (msg.text.equalsIgnoreCase("L1 OFF"))
		{
			L1OFF();
		}

		else if (msg.text.equalsIgnoreCase("L2 ON"))
		{
			L2ON();
		}

		else if (msg.text.equalsIgnoreCase("L2 OFF"))
		{
			L2OFF();
		}
		else if (msg.text.equalsIgnoreCase("L3 ON"))
		{
			L3ON();
		}
		else if (msg.text.equalsIgnoreCase("L3 OFF"))
		{
			L3OFF();
		}
		else if (msg.text.equalsIgnoreCase("L4 ON"))
		{

			L4ON();
		}
		else if (msg.text.equalsIgnoreCase("L4 OFF"))
		{
			L4OFF();
		}
		else if (msg.text.equalsIgnoreCase("L5 ON"))
		{

			L5ON();
		}
		else if (msg.text.equalsIgnoreCase("L5 OFF"))
		{
			L5OFF();
		}
		else if (msg.text.equalsIgnoreCase("L6 ON"))
		{

			L6ON();
		}
		else if (msg.text.equalsIgnoreCase("L6 OFF"))
		{
			L6OFF();
		}
		else if (msg.text.equalsIgnoreCase("ALL ON"))
		{

			ALLLAMPON();
		}
		else if (msg.text.equalsIgnoreCase("ALL OFF"))
		{
			ALLLAMPOFF();
		}
		else if (msg.text.equalsIgnoreCase("/start"))
		{
			myBot.sendMessage(msg.sender.id, "Selamat datang administrator " + msg.sender.username);
		}
		else
		{ // otherwise...
			// generate the message for the sender
			String reply;
			reply = (String) "Welcome " + msg.sender.username + (String) ". Try L1 ON or L1 OFF.";
			myBot.sendMessage(msg.sender.id, reply); // and send it
		}
	}
	// wait 500 milliseconds
	delay(500);
}
//*END VOID LOOP

//-------------------------------------------------------------------------------->
