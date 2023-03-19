FOLDERNAME=~/Afbeeldingen/Achtergronden/Slideshow
CONFIG_FILE=slideshow.xml
DURATION=30
TRANSITION_TIME=2

cat << PREAMBLE > $CONFIG_FILE
<background>
  <starttime>
    <year>2000</year>
    <month>01</month>
    <day>01</day>
    <hour>00</hour>
    <minute>00</minute>
    <second>00</second>
  </starttime>
PREAMBLE
  
previousfile=""

for filename in $FOLDERNAME/*.{jpg,png,jpeg} ; do
  fullpath=$filename
  
  if [ -f "$fullpath" ] ; then
	  chmod a-w "$fullpath"
	  
	  if [ "$previousfile" != "" ]; then 
		  echo "<transition>" >> $CONFIG_FILE
		  echo "  <duration>$TRANSITION_TIME.00</duration>" >> $CONFIG_FILE
		  echo "  <from>$previousfile</from>" >> $CONFIG_FILE
		  echo "  <to>$fullpath</to>" >> $CONFIG_FILE
		  echo "</transition>" >> $CONFIG_FILE
	  fi 

	  echo "<static>" >> $CONFIG_FILE
	  echo "  <duration>$DURATION.00</duration>" >> $CONFIG_FILE
	  echo "  <file>$fullpath</file>" >> $CONFIG_FILE
	  echo "</static>" >> $CONFIG_FILE
	  

	  previousfile=$fullpath
  fi
done
echo "</background>" >> $CONFIG_FILE

