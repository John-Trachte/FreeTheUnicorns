.PHONY: clean one two three four five six seven eight nine ten eleven twelve thirteen

default:
	g++ -o out FreeTheUnicorns.cpp
	./out

clean:
	rm -rvf out

one:
	g++ -o out FreeTheUnicorns.cpp 
	./out ../TestInputs/1.csv 2

two:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/2.csv 4

three:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/3.csv 4

four:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/4.csv 4
	
five:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/5.csv 4
	
six:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/6.csv 9
	
seven: 
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/7.csv 9
	
eight:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/8.csv 9
	
nine: 
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/9.csv 9
	
ten: 
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/10.csv 16
	
eleven:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/11.csv 16
	
twelve: 
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/12.csv 16

thirteen:
	g++ -o out FreeTheUnicorns.cpp 
	./out /TestInputs/13.csv 16