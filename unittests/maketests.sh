#todo: compile this one and the linkedlist.c
#remove the old executables. 
#run the executable
rm ./testlinkedlist
gcc -Wall  testlinkedlist.c ../linkedlistint.c -o testlinkedlist

rm ./testlinkedlistpointer
gcc -Wall  testlinkedlistintpointer.c ../linkedlistintpointer.c -o testlinkedlistpointer

