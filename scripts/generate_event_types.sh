echo "#ifndef __EVENT_TYPES_HEADER__" > $2
echo "#define __EVENT_TYPES_HEADER__" >> $2

for file in $1/*.h
do
	CATEGORY=$(basename -s .h $file)
	VAR_NAME=$(basename -s Event $CATEGORY | sed 's/.*/\l&/')
	echo "enum $CATEGORY ${VAR_NAME};">> $2
done
echo "#endif" >> $2
