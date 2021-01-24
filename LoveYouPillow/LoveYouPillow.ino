/*
  EchoBot

  This example shows how to program a Telegram Bot
  that echoes your messages.

  For a step-by-step tutorial visit:
  https://create.arduino.cc/projecthub/Arduino_Genuino/telegram-bot-library-ced4d4

  In oreder to make the bot more reliable in the long run we suggest using a watchdog
  The Adafruit_SleepyDog is a handy library that will reset the board if something goes wrong

  Updated 29 May 2016
  by Tommaso Laterza
  Updated 13 February 2018
  by Tommaso Laterza

  This example code is in the public domain.

*/
// ArduinoJSON - Version 5.13.5
//#include <ArduinoJson.h>
//#include <ArduinoJson.hpp>

#include "arduino_secrets.h"
#include <WiFi101.h>
#include <SPI.h>
#include <WiFiSSLClient.h>
#include <TelegramBot.h> 

// Initialize Wifi connection to the router
char ssid[] = SECRET_SSID;  // your network SSID (name)
char pass[] = SECRET_PASS;  // your network key

// Initialize Telegram BOT
const char BotToken[] = SECRET_BOT_TOKEN;

WiFiSSLClient client;
TelegramBot bot (BotToken, client);


void setup() {

  Serial.begin(115200);
  while (!Serial) {} // Wait for the Serial monitor to be opened
  delay(3000);

  // attempt to connect to Wifi network:
  Serial.println("Hello Calum");
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");

  bot.begin();
  Serial.println("Let's Start!");
}

void loop() {

    Serial.println("About to check for updates");
    message m = bot.getUpdates(); // Read new messages
    Serial.println("Executed 'bot.getUpdates'");
//    Serial.println("message " + m);
//    Serial.println("message text " + m.text);
//    Serial.println("message sender " + m.sender);
//    Serial.println("message date " + m.date);
    if ( m.chat_id != 0 ){ // Checks if there are some updates
      Serial.println(m.text);
      bot.sendMessage(m.chat_id, m.text);  // Reply to the same chat with the same text
    } else {
      Serial.println("no new message");
    }
    Serial.println("End of loop, back around we go...");

}
