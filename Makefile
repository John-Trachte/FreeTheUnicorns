FOLDERPATH = TestInputs

.PHONY: clean one two three four five six seven eight nine ten eleven twelve thirteen

default:
	g++ -o out FreeTheUnicorns.cpp
	./out

clean:
	rm -rvf out

one:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/1.csv 2

two:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/2.csv 4

three:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/3.csv 4

four:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/4.csv 4
	
five:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/5.csv 4
	
six:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/6.csv 9
	
seven: 
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/7.csv 9
	
eight:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/8.csv 9
	
nine: 
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/9.csv 9
	
ten: 
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/10.csv 16
	
eleven:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/11.csv 16
	
twelve: 
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/12.csv 16

thirteen:
	g++ -o out FreeTheUnicorns.cpp 
	./out $(FOLDERPATH)/13.csv 16