# Instructies

Om deze variant werkend te krijgen moet je aangeven waar je Shared Object (.so) file te vinden is. 
Dit is o.a. beschreven op deze [website](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html). 

Het komt er op neer dat je óf je .so-file steeds kopieert naar een speciale locatie. Praktischer is om aan te geven dat je .so-file in een ándere plek staat, namelijk de
locatie van waaruit je nu werkt. Bijvoorbeeld: jouw code staat om `/home/martin/ops/helloWorld/C/V3`. Dan kun je met het volgende commando aangeven bij Linux dat dit een plek 
is waar .so-bestanden gevonden kunnen worden:

```bash
LD_LIBRARY_PATH=/home/martin/ops/helloWorld/C/V3:$LD_LIBRARY_PATH
```
En dat zou het moeten werken. 

*Let op: * deze instelling gaat verloren als je de terminal sluit. Bij een volgende keer moet je dat commando dus weer opnieuw geven. Mooie gelegenheid om daar een alias van 
te maken! [bash aliases](https://linuxize.com/post/how-to-create-bash-aliases/)

