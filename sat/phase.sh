# !/bin/bash

rm -rf phase.txt
rm -rf final1.txt
rm -rf final2.txt
g++ generator.c -o gene
g++ stat.c -o st
g++ pro.c -o pro
mkdir test
./gene
cat phase.txt
for ((i=1; i<=10000; i++))
do
	minisat test/${i}.cnf test/${i}.log
	if [ $? -eq 10 ]; then
		echo -e "1 \c" >> phase.txt
	else
		echo -e "0 \c" >> phase.txt
	fi
	./st test/${i}.cnf
done
./pro
python phase1.py
python phase2.py

rm -rf test
rm -rf gene
rm -rf st
rm -rf pro


