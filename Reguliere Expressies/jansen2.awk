BEGIN {FS=";"}
/Jansen/ {print "Voornaam = " $1}
!/Jansen/ {print "Achternaam = " $2 " " $3}
