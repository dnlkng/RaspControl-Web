

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

int main(int argc, char* argv[]) {
    
  Cgicc formData;
  /*
  output rcDataPin is hardcoded for testing purposes
  see https://projects.drogon.net/raspberry-pi/wiringpi/rcDataPins/
  for rcDataPin maprcDataPing of the raspberry pi GPIO connector
  */
  int rcDataPin = 0;
  int ledPin = 1;
    
    

   

   // form_iterator fi = formData.getElement("device");  
   string foo = formData("cmd");
   // if( !fi->isEmpty() && fi != (*formData).end()) {  
      // cout << "selected device: " << fi->getValue() << endl;  
   // }else{
   //    cout << "No text entered for first name" << endl;  
   // }



  int mode = atoi(formData("cmd").c_str());
  int groupId = atoi(formData("group").c_str());
  int DeviceId  = atoi(formData("device").c_str());

   // int mode = 1;
   // int groupId = 1;
   // int DeviceId = 1;

    
  if (wiringPiSetup() == -1) return -1;
    
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(rcDataPin);

  pinMode(ledPin, OUTPUT);
    
  switch(mode) {
    case 1:
      digitalWrite(ledPin, HIGH);
      mySwitch.switchOn('a',groupId, DeviceId);
      break;
    case 0:
      digitalWrite(ledPin, LOW);
      mySwitch.switchOff('a',groupId, DeviceId);
      break;
    default:
      cout << "unsuported mode[" << mode << "]" << endl;
      return -1;
    }

  cout << "Location:http://raspberrypi.local/\n\n";

	return 0;
}