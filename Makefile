bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp


bin/testHashTable: testHashtable.cpp HashTable.h
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSTree.h
	g++ -o bin/testBSTree testBSTree.cpp

clean:
	rm -rf *.o *.gch bin
