echo "#ifndef __EVENT_TYPES_HEADER__" > $2
echo "#define __EVENT_TYPES_HEADER__" >> $2

for file in $1/*.h
do
	TYPE=$(basename -s Event.h $file | sed 's/.*/\U&/g')
	echo $TYPE"_EVENT,">> $2
done
echo "#endif" >> $2
