#include<string>
#include<iostream>
#include"counter.h"
int count_words(Counter<std::string>& cnt, std::istream& source){
	for (std::string word; source >> word; cnt.usr_ad(word) );
	return 0;
}

//int count_words(Counter<string>& cnt, istream& source){
//	for (string word; source >> word; cnt.specialad(word) );
//	return 0;
//}
