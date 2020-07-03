echo "#ifndef __EVENT_DATAS_HEADER__" > $2
echo "#define __EVENT_DATAS_HEADER__" >> $2

for file in $1/*.h
do
	DATA="$(basename -s .h $file)Data"
	VAR_NAME=$(basename -s Event $DATA | sed 's/.*/\l&/')
	echo "struct $DATA $VAR_NAME;">> $2
done
echo "#endif" >> $2
