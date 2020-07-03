echo "#ifndef __EVENT_INCLUDES_HEADER__" > $2
echo "#define __EVENT_INCLUDES_HEADER__" >> $2

for file in $1/*.h
do
	echo "#include \"""$file""\"" >> $2
done
echo "#endif" >> $2
