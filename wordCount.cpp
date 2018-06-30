/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <fstream>
using namespace std;

/**************************************************************************
 * READFILE
 * Counts the number of occurrences of each unique word in a file and
 * stores this data in a map
 **************************************************************************/
void readFile(custom::map <string, int> & counts, const string & fileName)
{
   string word;
   
   ifstream fin(fileName.c_str());
   while (fin >> word)
      ++counts[word];

   fin.close();
}
   

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   string fileName;
   custom::map <string, int> counts;

   cout << "What is the filename to be counted? ";
   cin >> fileName;

   readFile(counts, fileName);

   string word;

   cout << "What word whose frequency is to be found. Type ! when done\n";
   
   do
   {
      cout << "> ";
      cin >> word;
      
      if (word != "!")
         cout << '\t' << word << " : " << counts[word] << endl;
   }
   while (word != "!");
      
}
