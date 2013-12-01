#!/bin/bash
dir=uva$1
cd $dir
g++ -lm -O2 -pipe -DONLINE_JUDGE $dir.cpp -o $dir || exit 1 
./$dir < input.txt > test_output.txt
cat test_output.txt
echo "------DIFF-WITH-TEST-DATA------"
diff output.txt test_output.txt
#cleanup
rm $dir
rm test_output.txt
cd -
