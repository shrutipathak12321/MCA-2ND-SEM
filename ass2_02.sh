IFS=:
for dir in $PATH
do
  if [ -d $dir ]
     then
       echo "$dir"
       echo "permision : $(ls -ld $dir | awk '{print $1}')"
    echo "modification time : $(date -r $dir)"
  else
       echo "$dir does not exit"
          fi
done
