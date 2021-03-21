# Three phase power supply control using SSR relays and relay cooling
# Upravljanje trofaznim napajanjem mreže, hlađenje releja 

ESP32, BLYNK, ARDUINO OTA, SSR RELAYS, RELAY COOLING, CONTROLLING THREEPHASE POWER GRID, SENSOR DS1820

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(5).jpeg)

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(4).jpeg)

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(1).jpeg)


With the help of an arduino microcontroller and an SSR relay, control of the mains power supply up to 50A was made. Since the relays are heating, it is necessary to perform cooling of the relays, or automation that will turn on the fan in the relay housing if the temperature exceeds a certain value. The user in this case had two options of power supply, via the mains or via the generator. The problem is that every time he should physically turn on and off the fuses or switches when turning on or off the unit that is far from the distribution cabinet. The user is enabled to turn the power supply on or off remotely via the application interface. The user can also control the cooling of the relay and set the temperature value to which the automatic switches off the relays so that ignition does not occur in the event of overheating. It also has a current and historical display of the temperature movement in the relay housing as well as the performance of the relay cooling.


Pomoću arduino mikrokontrolera i SSR releja napravljeno je upravljanje napajanjem mreže do 50A. Pošto se releji griju
potrebno je izvesti i hlađenje releja odnosno automatiku koja će paliti ventilator u kućištu releja ako temperatura
prijeđe određenu vrijednost. 
Korisnik u ovom slučaju je imao dvije mogućnosti napona napajanja, preko električne mreže ili preko agregata.
Problem je u tome što bi svaki put trebao fizički paliti i gasiti osigurače ili sklopke pri paljenu ili gašenju agregata koji je
udaljen od razvodnog ormara.
Korisniku je omogućeno putem sučelja aplikacije daljinsko uključenje ili isključenje napajanje mreže. Također korisnik
može upravljati hlađenjem releja te postaviti na koju vrijednost temperature automatika gasi releje da u slučaju
pregrijavanja ne dođe do zapaljenja. Također ima trenutni i povijesni prikaz kretanja temperature u kućištu releja kao i
odrađivanja hlađenja releja.

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.44.08.jpeg)![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.44.09%20(1))
![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.44.09.jpeg)
