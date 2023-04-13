
R4="S: RAPOSE"
R5="S: RAPOSE B"
R6="T: KERBS"
R7="G: 3"
R8="B: 51"
R9="G: 3 L"
R9_2="G: 3 H"

R10="A: 3"
R11="I :"


echo "Test for R4 - S: RAPOSE ">test.txt
echo "$R4" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R5 - S: RAPOSE B ">>test.txt
echo "$R5" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R6 - T: KERBS ">>test.txt
echo "$R6" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R7 - G : 3 ">>test.txt
echo "$R7" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R8 - B: 51 ">>test.txt
echo "$R8" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R9 - G: 3 L ">>test.txt
echo "$R9" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R9_2 - G : 3 H ">>test.txt
echo "$R9_2" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R10 - A: 3 ">>test.txt
echo "$R10" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt

echo "Test for R11 - I:  ">>test.txt
echo "$R11" | ./lab1 | sed '1,13d' | tail -r | sed '1,13d' | tail -r >> test.txt



