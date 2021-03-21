# Three phase power supply control using SSR relays and relay cooling
# Upravljanje trofaznim napajanjem mreže, hlađenje releja 

ESP32, BLYNK, ARDUINO OTA, SSR RELAYS, RELAY COOLING, CONTROLLING THREEPHASE POWER GRID, SENSOR DS1820

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(5).jpeg)

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(4).jpeg)

![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.42.11%20(1).jpeg)



With the help of arduino microcontroller esp32, SSR relays, temperature sensor ds1820 and electromechanical relay, control of mains power supply up to 50A was made.
Computer power supply was used to power the microcontroller and components. The computer power supply has all the necessary voltage levels (3.3,5,12 V) to supply the microcontroller as well as the fan used for cooling relays (12V).
The housing of the old faulty power supply of the computer, inside which the temperature sensor is placed, was used as the housing of the SSR relays. The fan of the old housing for cooling the SSR relay was also used. The electromechanical relay is separated from the SSR relay housing itself and is used to control the relay cooling fan.
Since the relays are heating, it is necessary to perform cooling of the relay, ie automation that will turn on the fan in the relay housing if the temperature exceeds a certain value.
In order to prevent possible damage in the event of a failure of the relay that starts the fan or the cooling fan itself, the temperature value is set at which the SSR relays will automatically turn off and prevent possible damage.
The user in this case had two options of supply voltage, via the mains or via the generator. The problem is that every time you should physically turn on and off the fuses or switches when turning on or off the unit that is far from the distribution cabinet. The power supply of the network is enabled on or off via the application interface.
The user can control the cooling of the relay via the application interface and set the temperature value to which the automatic switches off the relays so that ignition does not occur in the event of overheating. It also has a current and historical display of the temperature movement in the relay housing as well as the performance of the relay cooling.


Pomoću arduino mikrokontrolera esp32, SSR releja, senzora temperature ds1820 i elektromehaničkog releja napravljeno je upravljanje napajanjem mreže do 50A. 
Za napajanje mikrokontrolera i komponenti iskorišteno je napajanje računala. Napajanje računala ima sve potrebne naponske nivoe(3.3,5,12 V) za opskrbiti mikrokontroler kao i ventilator koji se koristi zahlađenje releja(12V). 
Kao kućište SSR releja iskorišteno je kućište starog neispravnog napajanja računala unutar kojeg je postavljen senzor temperature. Iskorišten je i ventilator starog kućišta za hlađenje SSR releja. Elektromehanički relej odvojen je od samog kućišta SSR releja te se koristi za upravljanje ventilatorom za hlađenje releja.
Pošto se releji griju potrebno je izvesti i hlađenje releja odnosno automatiku koja će paliti ventilator u kućištu releja ako temperatura prijeđe određenu vrijednost. 
Da ne bi došlo do eventualnog zapaljenja prilikom kvara releja koji pokreće ventilator ili samog ventilatora koji hladi postavlja se i vrijednost temperature pri kojoj će se automatski ugasiti SSR releji i spriječiti eventualnu štetu.
Korisnik u ovom slučaju je imao dvije mogućnosti napona napajanja, preko električne mreže ili preko agregata. Problem je u tome što bi svaki put trebao fizički paliti i gasiti osigurače ili sklopke pri paljenu ili gašenju agregata koji je udaljen od razvodnog ormara. Omogućeno je putem sučelja aplikacije daljinsko uključenje ili isključenje napajanje mreže. 
![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.44.08.jpeg)
Korisnik ima trenutni i povijesni prikaz kretanja temperature u kućištu releja kao i odrađivanja hlađenja releja.
Korisnik može putem sučelja aplikacije upravljati hlađenjem releja te postaviti na koju vrijednost temperature automatika gasi releje da u slučaju pregrijavanja ne dođe do zapaljenja. Tromost služi za postavljanje razlike temperature na koju će se ventilator gasiti jer bi se u protivnom svaku par sekunda palio i gasio te bi elektromehanički relej koji upravlja ventilatorom brzo zakazao.
![](Project%20images/WhatsApp%20Image%202021-03-21%20at%2014.44.09%20(1))

