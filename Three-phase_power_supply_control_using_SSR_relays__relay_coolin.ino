#define BLYNK_PRINT Serial
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#define oneWireBus 13
#define L1 4
#define L2 14
#define L3 17
#define vent 12

float temp;
bool a=HIGH,a_vent=HIGH, notifikacije=HIGH, n1=0,n2=0,faza1,faza2,faza3,vent_manual;
bool faza1_graf,faza2_graf,faza3_graf,vent_graf;
int temp_poli_vent=20, temp_gosi_struju=45,temp_visoka=30,temp_previsoka=43,temp_offset=6;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
const char* ssid     = "";
const char* password = "";

char auth[] = "" ;
BlynkTimer  timer;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

BLYNK_CONNECTED() 
{
  // Request the latest state from the server
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
  Blynk.syncVirtual(V9);
  Blynk.syncVirtual(V10);
  Blynk.syncVirtual(V11);
  Blynk.syncVirtual(V12);
  Blynk.syncVirtual(V17);
  Blynk.syncVirtual(V18);
  
}
BLYNK_WRITE(V1) 
{//reset botun
 if((param.asInt()==1))
  {
  ESP.restart();
  }
}
BLYNK_WRITE(V3) 
{//botun auto/manual
  a=param.asInt();
}
BLYNK_WRITE(V18) 
{//botun auto/manual za ventilaciju
  a_vent=param.asInt();
}
  BLYNK_WRITE(V4)
{
  temp_offset=param.asFloat();
}
BLYNK_WRITE(V5)
{
  temp_poli_vent=param.asInt();
}
BLYNK_WRITE(V6)
{
  temp_gosi_struju=param.asInt();
}
BLYNK_WRITE(V7)
{
  temp_visoka=param.asInt();
}
BLYNK_WRITE(V8)
{
  temp_previsoka=param.asInt();
}
 BLYNK_WRITE(V9)
{
 notifikacije=param.asInt();
}
BLYNK_WRITE(V10)
{
 if((param.asInt()==1)&&(a==LOW))
  {
     digitalWrite(L1, HIGH);
     faza1=HIGH;
  }
  if ((param.asInt()==0)&&(a==LOW))
  {
     digitalWrite(L1, LOW);
     faza1=LOW;
  }
}
BLYNK_WRITE(V11)
{
 if((param.asInt()==1)&&(a==LOW))
  {
     digitalWrite(L2, HIGH);
     faza2=HIGH;
  }
  if ((param.asInt()==0)&&(a==LOW))
  {
     digitalWrite(L2, LOW);
     faza2=LOW;
  }
}
BLYNK_WRITE(V12)
{
 if((param.asInt()==1)&&(a==LOW))
  {
     digitalWrite(L3, HIGH);
     faza3=HIGH;
  }
  if ((param.asInt()==0)&&(a==LOW))
  {
     digitalWrite(L3, LOW);
     faza3=LOW;
  }
}
BLYNK_WRITE(V17)
{
 if((param.asInt()==1)&&(a_vent==LOW))
  {
     digitalWrite(vent, HIGH);
     vent_manual=HIGH;
  }
  if ((param.asInt()==0)&&(a_vent==LOW))
  {
     digitalWrite(vent, LOW);
     vent_manual=LOW;
  }
}



void sendSensor()
{
   
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, temp);  //V5 is for Humidity
  Blynk.virtualWrite(V10, faza1);
  Blynk.virtualWrite(V11, faza2);
  Blynk.virtualWrite(V12, faza3);
  Blynk.virtualWrite(V13, WiFi.RSSI()); 
  Blynk.virtualWrite(V14, faza1_graf);
  Blynk.virtualWrite(V15, faza2_graf);
  Blynk.virtualWrite(V16, faza3_graf);
  Blynk.virtualWrite(V19, vent_graf);
  Blynk.virtualWrite(V17, vent_manual);

}

void setup() 
{
  Serial.begin(115200);       
 
  sensors.begin();
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(vent, OUTPUT);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(vent, HIGH);
  
  WiFi.mode(WIFI_STA);//ZA OTA 
  
  // only for debug
 //WiFi.config(ip, gateway, subnet);       // forces to use the fix IP ne rodi blynk
  WiFi.begin(ssid, password);    
  // put your setup code here, to run once:
  
  ArduinoOTA//OTA  OD VODE
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.setHostname("struja");
  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());//OTA DO VODE

  Blynk.config(auth);
  Blynk.connect();
  timer.setInterval(1000L, sendSensor);
}

void loop() 
{
  
  ArduinoOTA.handle();
  
  sensors.requestTemperatures(); 
  temp= sensors.getTempCByIndex(0);
  if ((temp_poli_vent>0)&&(temp_poli_vent<100)&&(temp>0 )&&(temp<100))
       {
        if(a_vent==HIGH)  
           {
            if ((temp_poli_vent-temp_offset)>(temp))//GOS ventilator
               digitalWrite(vent, LOW);
            if ((temp_poli_vent)<(temp))// POL ventilaciju
                 digitalWrite(vent, HIGH);
           }

        
        if(a==HIGH)
          {
             
             if ((temp_gosi_struju-temp_offset)>(temp) )//pol struju
                { 
                 digitalWrite(L1, HIGH);
                 digitalWrite(L2, HIGH);
                 digitalWrite(L3, HIGH);
                }
          
             
            
             if (temp_gosi_struju<temp )//gos struju
                { 
                 digitalWrite(L1, LOW);
                 digitalWrite(L2, LOW);
                 digitalWrite(L3, LOW);
                } 
          }
        }
        if(a==LOW)
        {    
          digitalWrite(L1,faza1);
          digitalWrite(L2,faza2);
          digitalWrite(L3,faza3);   
        }      
         if(a_vent==LOW)
         digitalWrite(vent, vent_manual);
         
        if(notifikacije==HIGH)
        {
          if ((temp<temp_visoka))
             n1=0;
          if ((temp<temp_previsoka))
             n2=0;
             
          if ((temp>temp_visoka)&&(n1==0))
             {
              n1=1;
              Blynk.notify("Struja temperija visoka");
             } 
          
          if ((temp>temp_previsoka)&&(n2==0))
             {
              n2=1;
              Blynk.notify("Struja temperija privisoka !!!");
             }
        }  
  if(digitalRead(L1)==HIGH)
  faza1_graf=HIGH;
  else
  faza1_graf=LOW;
  
  if(digitalRead(L2)==HIGH)
  faza2_graf=HIGH;
  else
  faza2_graf=LOW;
  
  if(digitalRead(L3)==HIGH)
  faza3_graf=HIGH;
  else
  faza3_graf=LOW;

  if(digitalRead(vent)==HIGH)
  vent_graf=HIGH;
  else
  vent_graf=LOW;
  
  if(!Blynk.connected())
  {
    WiFi.begin(ssid, password);
    Serial.println("Not connected to Blynk server"); 
    Blynk.connect(3333);  // timeout set to 10 seconds and then continue without Blynk  
  }
  else 
  Blynk.run();
  
  timer.run();
  // put your main code here, to run repeatedly:

}
