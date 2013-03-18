#!/bin/bash
dir=uva$1
cd $dir
g++ -lm -O2 -pipe main.cpp -o main || exit 1 
./main < input.txt > test_output.txt
cat test_output.txt
echo "------DIFF-WITH-TEST-DATA------"
diff output.txt test_output.txt
#cleanup
rm main
rm test_output.txt
cd -
