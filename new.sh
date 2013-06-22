#!/bin/bash
dir=uva$1
mkdir $dir
./open.py $1
./download.py $1

cp template/main.cpp $dir/$dir.cpp
echo "paste input.txt, then press Enter, ^D"
cat > $dir/input.txt
echo "paste output.txt, then press Enter, ^D"
cat > $dir/output.txt
subl $dir/$dir.cpp
