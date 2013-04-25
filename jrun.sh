#!/bin/bash
dir=uva$1
cd $dir
javac Main.java || exit 1 
java Main < input.txt > test_output.txt
cat test_output.txt
echo "------DIFF-WITH-TEST-DATA------"
diff output.txt test_output.txt
#cleanup
rm Main.class
rm test_output.txt
cd -
