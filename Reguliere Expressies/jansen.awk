BEGIN {FS=";"}
/Jansen/i {print "Voornaam = ", $1}
