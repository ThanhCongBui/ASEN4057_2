#! /bin/bash

## Tucker Emmet for Aerospace Software, HW5. Trying to take a file/directory
## name in and then output whether the file is a directory, regular file, or 
## other and report if the user has r/w/x permissions

input=$1;


if [ -d $input ]

	then echo "$input is a directory";

elif [ -f $input ]

	then echo "$input is a file";

else

	echo "$input doesn't seem to be working";

fi


if [ -r $input ]

	then echo "... and $input is readable by the user";
fi

if [ -w $input ]

	then echo "... and $input is writable by the user";
fi

if [ -x $input ]

	then echo "... and $input is executable by the user";
fi


