/*
 * textgen.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: Matthew
 */
#include "textgen.h"


/*USAGE GUIDE
 *
 * All the processes that load the structure are called by the constructor
 * Once the object has been declared, it can be called to give sentences for any difficulty
 *
 * Example Code:
 *
 * TextGen generator;
 * generator.setDifficulty(2);
 * std::cout << generator.generateSentence(2);
 * generator.dumpStruct(2);
 */


TextGen::TextGen(){

	seedFolder = "data";
	keyLength = 1;
	diff = 0;

	last = "";
	current = "";

	//Initialize randomizer based on current system time (pseudorandom)
	srand( unsigned( time( 0 ) ) );
	this->createDictionary();

}

void TextGen::loadText(int difficulty){

	std::string word, key;
	size_t wc = 0, pos, next;
	next = fileBuffer.find_first_not_of( 32, 0 );

	if( next == std::string::npos ){
		return;
	}


	//Construct the initial key from the file buffer
	while( wc < (unsigned)keyLength ) {
		pos = fileBuffer.find_first_of( ' ', next );
		word = fileBuffer.substr( next, pos - next );
		key += word + " ";
		next = fileBuffer.find_first_not_of( 32, pos + 1 );

		if( next == std::string::npos ){
			return;
		}
		wc++;
	}

	//Trim the key to size
	key = key.substr( 0, key.size() - 1 );

	while( true ) {
		//Look for the next new word
		next = fileBuffer.find_first_not_of( 32, pos + 1 );

		//If the position is at the end of the string, stop looking
		if( pos == std::string::npos ){
			return;
		}

		//Copy word from buffer
		pos = fileBuffer.find_first_of( 32, next );
		word = fileBuffer.substr( next, pos - next );

		if( word.size() < 1 ){
			break;
		}

		//If the word is not already added as a suffix, push it to the vector that corresponds to the right key and difficulty
		if( std::find( mStruct[difficulty][key].begin(), mStruct[difficulty][key].end(), word ) == mStruct[difficulty][key].end() ){
			mStruct[difficulty][key].push_back( word );
		}


		//Set the next key
		key = word;
	}

}

void TextGen::createDictionary(){

	//This method creates the dictionary

	for(int i=0; i<3; i++){

		//create the fileName, and add the proper extension
		std::string fileName = std::to_string(i+1);
		fileName.append(".txt");

		//Append that fileName to the seed folder with a slash
		std::string file = seedFolder;
		file.append("\\");
		file.append(fileName);

		//Load a file stream from the file, store it in a string , then close the file stream
		std::ifstream f( file.c_str(), std::ios_base::in );
		fileBuffer = std::string( ( std::istreambuf_iterator<char>( f ) ), std::istreambuf_iterator<char>() );
		f.close();
		if( fileBuffer.length() < 1 ){
			//If the fileBuffer is empty, something has gone wrong
			//Therefore, return
			return;
		}

		this->loadText(i);

	}
}


std::string TextGen::generateSentence(){

	int sLength;
	//This is where sentence length is defined

	switch(diff){

	case 0:
		sLength = 20;
		break;

	case 1:
		sLength = 25;
		break;

	case 2:
		sLength = 30;
		break;

	default:
		sLength = 30;
		diff = 2;
		break;
	}

	//Set the last sentence field to the current sentence before it is overwritten
	this->last = this->current;
	this->current = "";

	std::string key, first, second;
	//Construct iterator over map that corresponds to the correct difficulty
	std::map<std::string, std::vector<std::string> >::iterator it = mStruct[diff].begin();

	//Begin the key as a random member of the array
	std::advance( it, rand() % mStruct[diff].size() );
	key = ( *it ).first;

	//Begin the sentence with the key
	this->current = key;

	while( true ) {

		//store the suffix vector of the given key in the given difficulty
		std::vector<std::string> suffixes = mStruct[diff][key];
		//If there are no suffixes, end the sentence
		if( suffixes.size() < 1 ){
			break;
		}

		//Pick a random suffix option
		second = suffixes[rand() % suffixes.size()];
		//If there is no second, end the sentence
		if( second.length() < 1 ) {
			break;
		}

		//Add the option to the sentence separated by a space
		this->current.append(" ");
		this->current.append(second);

		//Decrement sentence length and if the maximum length has been reached, end the sentence
		if( --sLength < 0 ) {
			break;
		}

		//Set the new key
		key = second;
	}

	//return the finished sentence
	return this->current;

}


void TextGen::dumpStruct(int difficulty){
	//Dumps the contents of the specified difficulty's structure to cout
	//Used for testing purposes

	std::map<std::string, std::vector<std::string> >::iterator it;

	for ( it = this->mStruct[difficulty].begin(); it != this->mStruct[difficulty].end(); it++ )
	{
		std::cout << it->first << ':' << std::endl ;
		std::vector<std::string> d = it->second;
		for(size_t i=0; (unsigned)i< d.size(); i++){
			std::cout << d[i];
			std::cout << std::endl;
		}
	}

}

std::string TextGen::getLast(){
	return this->last;

}

std::string TextGen::getCurrent(){
	return this->current;

}

void TextGen::setDifficulty(int newDif){
	this->diff = newDif;
}

int TextGen::getDifficulty(){
	return this->diff;

}



