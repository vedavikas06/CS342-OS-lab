awk '{for(i = 1; i <= NF; i++) {a[$i]++}} END {for(k in a) if(a[k] > max){
max = a[k]
word = k
} print "maximum occured word in welcome.txt : "word}' welcome.txt #counted the frequency of words and then printed the one having maximum frequency

