# Artnet

An Art-Net library for ESP8266 with support for listening for polling + responding to polling

## Installation

You can download the [master](https://github.com/jakobbraun/Artnet/archive/master.zip) and place the folder in your `~/Documents/Arduino/libraries` folder.

## Examples

Different examples are provided, here is a summary of what each example does.

### ArtnetReceive

This is a basic example that will print out the header and the content of an ArtDmx packet.  This example uses the read() function and the different getter functions to read the data.

### ArtnetReceiveCallback

This is similar to ArtnetReceive but uses a callback to read the data.

## Acknowledgements

This is a merge of github.com/stremlau/Artnet and github.com/nickysemenza/Artnet
