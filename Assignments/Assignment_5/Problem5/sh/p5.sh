 ## Tucker Emmett, Problem 5 for HW5
## bash shell script program to organize files in a zipped tar file. 
## 1. Unzip the file
## 2. Create subfolders for each file extension associated with extracted files
## 3. Place files in subfolders associated with their extension
## 4. If file does not have extension, don't put it in a folder
## 5. Zip the resulting folder structure and name it...
## 6. Data_clean.tar.gz if the original name was Data.tar.gz


#! /bin/bash
 tar -xzvf $1 



for file in *.*[!.]
do
ext=${file##*.}
mkdir -p -- "$ext" && mv -- "$file" "$ext"/
done

tar -czvf MIDG_clean.tar.gz ~/Documents/tuck/Assignments/Assignment_5/Problem5/


