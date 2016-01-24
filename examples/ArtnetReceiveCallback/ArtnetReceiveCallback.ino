/*
This is similar to ArtnetReceive but uses a callback to read the data.
This example may be copied under the terms of the MIT license, see the LICENSE file for details
*/

#include <ESP8266WiFi.h>
#include <Artnet.h>
#include <SPI.h>

Artnet artnet;

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
  // print out our data
  Serial.print("universe number = ");
  Serial.print(universe);
  Serial.print("\tdata length = ");
  Serial.print(length);
  Serial.print("\tsequence n0. = ");
  Serial.println(sequence);
  Serial.print("DMX data: ");
  for (int i = 0 ; i < length ; i++)
  {
    Serial.print(data[i]);
    Serial.print("  ");
  }
  Serial.println();
  Serial.println();

}

void setup()
{
  Serial.begin(115200);
  WiFi.begin("ssid", "password");
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  artnet.begin();
  
  // this will be called for each packet received
  artnet.setArtDmxCallback(onDmxFrame);
}

void loop()
{
  // we call the read function inside the loop
  artnet.read();
}
