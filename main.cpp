#include <iostream>
#include <fstream>
#include <cctype>


std::string block (std::string lower){
    std::string changed{};
    for(size_t i {0}; i<lower.size(); i++){
        lower[i] = toupper(lower[i]);
        changed+=lower[i];
    }
    return changed;
}



int main() {
    
   std::ifstream in_file;
   std::string word, choice;
   long int word_count{};
   int count{};
   
   in_file.open("romeoandjuliet.txt");
   
   //Opening the file
   if(!in_file){
       std::cerr<<"Error opening Romeo and Juliet\n";
       return 1;
   }
   
   //collecting the input from the user
   std::cout<<"What word would you like to search for in Romeo and Juliet?: ";
   std::cin>>choice;
   choice = block(choice);
   
   while( in_file>>word){
       word_count++;
       word=block(word);
       if(word==choice){
           count++;
       }
   }
   std::cout<<"A total of "<<word_count<<" words was searched"<<std::endl;
   std::cout<<choice<<" was found: "<<count<<" times. "<<std::endl;
    return 0;
}