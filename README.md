# cs32-pa01

Spring 2016
Michael Costanzo's CS32 Class @ UCSB

1. Write table.h to define class Table as it is used in the demonstration program named tabledemo.cpp. Your Table must hold Entry objects     as defined in entry.h (and implemented in entry.cpp). For the demonstration program to compile successfully, your table.h must define     at least the following public functions:

One constructor that builds an empty Table designed to hold a maximum number of entries equal to the only parameter. This parameter should have a default value of 100: 
    Table(unsigned int max_entries = 100)
    
Another constructor that builds a Table designed to hold the number of entries specified by the first parameter, and puts that many entries into the Table by reading them one at a time from the input stream that is the second parameter: 
    Table(unsigned int entries, std::istream &input) 
    
Do not input more than the specified number of entries. If you always read all of input, you will lose points for not satisfying this requirement.

Two (overloaded) member functions named put, each of which puts a new Entry into the Table: 
   void put(unsigned int key, std::string data) 
   void put(Entry e) 
   
The first of these functions creates a new Entry to put in the Table. The second one puts a copy of the parameter in the Table. In cases where the Table already contains an Entry with the given key, these functions act to update the Entry for that key. The Table is not allowed to contain duplicate keys.

A constant member function named get that returns the string associated with the parameter: 
   std::string get(unsigned int key) const 
   
This function returns an empty string if the Table has no Entry with the given key.
A member function named remove that removes the Entry containing the given key: 
   bool remove(unsigned int key) 
   
This function returns true if it removes an Entry, or false if the Table has no such Entry.
A non-member output function that overloads the << operator to print the Table: 
   std::ostream& operator<< (std::ostream &out, const Table &t) 
   
This function is expected to print each Entry in the Table to a separate line of the given output stream in the order of their key values.

Your class may define other functions too, either public or private ones. In particular, you will probably want to add a hashing function to transform the key values - in our version, function hashkey is a private function. And of course, your class must define the private data a Table object stores.

Write table.cpp to implement your class Table. You may use tools from any of the standard libraries except <map>, <set>, <unordered_map> and <unordered_set>. In planning your implementations, keep in mind the following requirements:

Each of the functions put, get and remove must execute in constant O(1) time. That means your implementation must be a hash table. By the way, you should carefully choose the size of the table you create in the constructors - our version makes the size of the table equal to twice the maximum number of entries.
Your output function must output the entries in the order of the key values, and it must execute in no more than O(n log n) time, and certainly not O(n2) time.



Clarification about Big-O restrictions: 
It is important that you store and manipulate Entry objects (i.e., instances of class Entry), and not separately handle the integer keys and string data. That is because we assess the efficiency of your functions by using the Entry::access_count() function before and after various operations. The time tests used by submit.cs will fail if they detect impossibly small counts of Entry accesses. Do notice that sorting Entry objects is no more complicated than sorting numbers, thanks to the operator conversion function that allows an Entry object to be treated like an int when appropriate. So, for example, if e1 and e2 are both entry objects, then (e1 < e2) will evaluate to true if e1.key() is less than e2.key(). All of the other relational operators work too. Cool, huh?
