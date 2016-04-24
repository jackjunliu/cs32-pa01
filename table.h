//table.h                                                                       
//Jack Liu, April 19th, 2016                                                    

#ifndef TABLE_H
#define ENTRY_H

#include <string>
#include <iostream>

class Table {

 public:
  //constructor                                                                 
  Table(unsigned int max_entries = 100);
  Table(unsigned int entries, std::istream &input);

  //overload member functions                                                   
  void put(unsigned int key, std::string data);
  void put(Entry e);

  //constant member functions                                                   
  std::string get(unsigned int key) const;

  //member functions                                                            
  bool remove(unsigned int key);

  //output function                                                             
  std::ostream& operator<<
    (std::ostream &out, const Table &t);

 private:
  unsigned int key;
  std::string data;
  static unsigned int entries;
};

#endif
