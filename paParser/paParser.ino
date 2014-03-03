/**
Created by: Romarie E. Yuag
BS Computer Engineering
MSU-Iligan Institute of Technology
*/
#include<SoftwareSerial.h>
#define DATABUFFERSIZE 53
char dataBuffer[DATABUFFERSIZE + 1];
char startChar='I';
char endChar= '\r';
const int rx=10;
const int tx=255;

SoftwareSerial paSerial(rx,tx);

char *range;
char *watts;
char *va;
char *var;
char *pf;
char *volts;
char *amps;
	

void setup(){
Serial.begin(9600);
paSerial.begin(9600);
}

void loop(){
	if(getSerialString){	
	
	range = strtok(dataBuffer, ",");
	watts = strtok(NULL, ",");
	va = strtok(NULL, ",");
	var = strtok(NULL, ",");
	pf = strtok(NULL, ",");
	volts = strtok(NULL, ",");
	amps = strtok(NULL, ",");
	
	Serial.print("WATTS:"); Serial.println(watts);
	Serial.print("VA:"); Serial.println(va);
	Serial.print("VAR:"); Serial.println(var);
	Serial.print("Power Factor:"); Serial.println(pf);
	Serial.print("VOLTS:"); Serial.println(volts);
	Serial.print("CURRENT:"); Serial.println(amps);
	memset(dataBuffer, NULL, 53);
	
	}

}

//this is a function!

boolean getSerialString(){

boolean startCharReceived = false;
static byte dataBufferIndex=0;	
		while(paSerial.available()>0){
			
			char incomingByte = paSerial.read();
			if(incomingByte==startChar){
				dataBufferIndex=0;
				startCharReceived=true;
							
			}
			if(startCharReceived){
				
				if(dataBufferIndex==DATABUFFERSIZE){
					dataBufferIndex=0;
					break;
				}
				if(incomingByte==endChar){
					dataBuffer[dataBufferIndex]=0;
					return true;
				}
				else{
					dataBuffer[dataBufferIndex++]= incomingByte;
					dataBuffer[dataBufferIndex]=0;
				}
				
			}
			else {
			}
		}			
	}
