echo -ne "unique words in welcome.txt : "
tr ' ' '\n' < welcome.txt | sort | uniq -c | wc -l #firstly replaced ' ' to '\n' and then  sorted and found unique words using unique -c and then counted using wc

