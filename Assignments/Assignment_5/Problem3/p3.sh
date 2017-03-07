### File is supposed to rename all the files with a particular file extension in a directory. We'll see how this goes...


#! /bin/bash
tar -xzvf ~/Documents/Shared/Assignments/Assignment_5/Materials/Pictures.tar.gz;


name=$1;
ext=$2;

shopt -s globstar
files=(~/Documents/tuck/Assignments/Assignment_5/Problem3/)
for ((i=0;i<(find $( pwd ) -mindepth 1 -type f -name "*.$ext" -exec printf x \; | wc -c ) in $( pwd ); i++));
do
mv "$file" "{$name%.$ext}$i.$ext"
done

ls

