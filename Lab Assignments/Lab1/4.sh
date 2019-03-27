clear

cd OS #directory OS

filename=($(ls -rSA)) #sort files by size 

for(( i =1 ; i<=4; i++))
do
{
  cat ${filename[i]} | head -n1 -q >>${filename[0]} #append the first line of this non-empty file to predefined empty-file
}
done

