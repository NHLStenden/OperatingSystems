BEGIN {FS=";"}
$3 ~/Jansen/ {print "Voornaam = " $1}
$3 !~/Jansen/ {print "Achternaam = " $2 " " $3}
