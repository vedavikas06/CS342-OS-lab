echo "Enter the value of n"
  read n
  declare -a fib=(0 1) #declared an array
  for ((i=2;i<$n;i++));
    do
      {
       fib[i]=$((fib[i-1]+fib[i-2])) #formed fibonnacci series
      }
   done
  echo "fibonnacci series"
  echo "${fib[@]}" #showing full series

   z=$((n/3)) #3 segments
   for((i=0;i<$z;i++)); do
   {
     fib[i]=$((fib[i]+fib[n-1-i])) #elementwise sum
   }
  done

  echo first segment
  for((i=0;i<$((z));i++)); do
   {
    echo -ne "${fib[i]} " #printed 1st segment
   }
  done	
  
  echo ""
  echo second segment
  for((i=z;i<$((2*z));i++)); do
   {
    echo -ne "${fib[i]} " #printed 2nd segment
   }
  done	
  
  echo ""
  echo concatenated segment
  for((i=0;i<$((2*z));i++)); do
   {
    echo -ne "${fib[i]} " #printed concatenated segment
   }
  done			
  
  echo ""
