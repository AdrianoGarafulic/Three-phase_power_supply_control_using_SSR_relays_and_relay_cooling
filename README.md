# _relayThree-phase_power_supply_control_using_SSR_relays__cooling
ESP32, BLYNK, ARDUINO OTA, SSR RELAYS, RELAY COOLING,CONTROLLING POWER GRID
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
