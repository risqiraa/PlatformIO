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

String led1status = "OFF";
String led2status = "OFF";
String led3status = "OFF";
String led4status = "OFF";
String led5status = "OFF";
String led6status = "OFF";

int jumlhonled1 = 0;
int jumlhonled2 = 0;
int jumlhonled3 = 0;
int jumlhonled4 = 0;
int jumlhonled5 = 0;
int jumlhonled6 = 0;

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
	led1status = "ON";
	myBot.sendMessage(msg.sender.id, "L1 is now ON ");
}
void L1OFF()
{
	digitalWrite(led1, LOW);
	led1status = "OFF";
	myBot.sendMessage(msg.sender.id, "L1 is now OFF");
}
//*VOID L1 END

//*VOID L2 START
void L2ON()
{
	digitalWrite(led2, HIGH);
	led2status = "ON";
	myBot.sendMessage(msg.sender.id, "L2 is now ON ");
}
void L2OFF()
{
	digitalWrite(led2, LOW);
	led2status = "OFF";
	myBot.sendMessage(msg.sender.id, "L2 is now OFF");
}
//*VOID L2 END

//*VOID L3 START
void L3ON()
{
	digitalWrite(led3, HIGH);
	led3status = "ON";
	myBot.sendMessage(msg.sender.id, "L3 is now ON ");
}

void L3OFF()
{
	digitalWrite(led3, LOW);
	led3status = "OFF";
	myBot.sendMessage(msg.sender.id, "L3 is now OFF");
}
//*VOID L3 END

//*VOID L4 START
void L4ON()
{
	digitalWrite(led4, HIGH);
	led4status = "ON";
	myBot.sendMessage(msg.sender.id, "L4 is now ON ");
}

void L4OFF()
{
	digitalWrite(led4, LOW);
	led4status = "OFF";
	myBot.sendMessage(msg.sender.id, "L4 is now OFF");
}
//*VOID L4 END

//*VOID L5 START
void L5ON()
{
	digitalWrite(led5, HIGH);
	led5status = "ON";
	myBot.sendMessage(msg.sender.id, "L5 is now ON ");
}

void L5OFF()
{
	digitalWrite(led5, LOW);
	led5status = "OFF";
	myBot.sendMessage(msg.sender.id, "L5 is now OFF");
}
//*VOID L5 END

//*VOID L6 START
void L6ON()
{
	digitalWrite(led6, HIGH);
	led6status = "ON";
	myBot.sendMessage(msg.sender.id, "L6 is now ON ");
}

void L6OFF()
{
	digitalWrite(led6, LOW);
	led6status = "OFF";
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

	led1status = "ON";
	led2status = "ON";
	led3status = "ON";
	led4status = "ON";
	led5status = "ON";
	led6status = "ON";
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

	led1status = "OFF";
	led2status = "OFF";
	led3status = "OFF";
	led4status = "OFF";
	led5status = "OFF";
	led6status = "OFF";
	myBot.sendMessage(msg.sender.id, "ALL Lamp is now OFF");
}
//*VOID ALL END

//*VOID STATUS LAMPU START
void statusmenu()
{
	myBot.sendMessage(msg.sender.id, "<========>"
									 "\nL1 : " +
										 led1status + "\nL2 : " + led2status + "\nL3 : " + led3status + "\nL4 : " + led4status + "\nL5 : " + led5status + "\nL6 : " + led6status + "\n<========>");
}
//*VOID STATUS LAMPU END

//*VOID TUTORIAL START
void menu()
{
	myBot.sendMessage(msg.sender.id, "FITUR\n========================\nL1 ON/OFF : Lampu lantai 1\nL2 ON/OFF : Lampu lantai 2\nL3 ON/OFF : Lampu lantai 3\nL4 ON/OFF : Lampu lantai 4\nL5 ON/OFF : Lampu lantai 5\nL6 ON/OFF : Lampu lantai 6\nALL ON/OFF : Lampu semua lantai\n========================\n*note : hanya gunakan salah satu perintah ON atau OFF");
}
//*VOID TUTORIAL END

//*VOID GREETING START
void greeting()
{
	myBot.sendMessage(msg.sender.id, "USER ID : " + msg.sender.username + "\n========================\n/status : untuk melihat status semua lampu");
} //*VOID GREETING END

//*VOID ERROR MESSAGE START
void errormessage()
{
	myBot.sendMessage(msg.sender.id, "error : menu yang anda pilih tidak ada\n========================\nSilahkan ketik /menu untuk melihat informasi fitur yang tersedia");
}
//*VOID ERROR MESSAGE END

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
		else if (msg.text.equalsIgnoreCase("/status"))
		{
			statusmenu();
		}
		else if (msg.text.equalsIgnoreCase("/menu"))
		{
			menu();
		}
		else if (msg.text.equalsIgnoreCase("/start"))
		{
			greeting();
		}
		else
		{ // otherwise...
			errormessage();
		}
	}
	// wait 500 milliseconds
	delay(500);
}
//*END VOID LOOP

//-------------------------------------------------------------------------------->
