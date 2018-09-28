/*
 * textgen.h
 *
 *  Created on: Mar 27, 2018
 *      Author: Matthew
 */
#include <ctime>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#ifndef TEXTGEN_H_
#define TEXTGEN_H_


class TextGen{
    
public:
    
    TextGen();
    //Constructor, initializes the fields, called automatically
    
    void createDictionary();
    /*Purposes:
     *    Loads each file into a buffer string
     *    Processes each buffer string by pulling out keys and suffixes
     *    Stores that information in the corresponding index of the mStruct array
     *
     *    Should be called only once at startup
     *    Potentially added to constructor?
     */
    
    std::string generateSentence();
    /*Used by the actual game methods to generate a sentence of a given difficulty
     * Also updates the last/current fields
     *
     */
    
    void dumpStruct(int difficulty);
    //Used to print the structure for a given difficulty to the standard output, for debug and testing
    
    std::string getLast();
    //Returns the previous sentence that was generated (if it is needed for some reason)
    
    std::string getCurrent();
    //Returns the current sentence, but does not generate a new one.
    //If a fresh sentence is needed, use generateSentence instead
    
    void setDifficulty(int newDiff);
    //Used to change the saved difficulty value
    
    int getDifficulty();
    //Used to check the current difficulty value
    
    std::string trimSentence(std::string input, int len);
    //Trims the given sentence to be at or less than a specified length
    //Used to fit sentences on screen of given size
    
    
    
private:
    
    void loadText(int difficulty);
    //Used only by createDictionary to load each difficulty's structure
    
    std::string seedFolder;
    
    int diff;
    //Stores the difficulty
    //    modified by setDifficulty
    
    int keyLength;
    //Could be modified to a longer value
    //    -would require rephrasing of the parts in loadText and generateSentence that update the key
    // - longer key lengths require much more training data to achieve noticeably different results
    //        from the training data
    
    std::string last;
    //Holds the previous sentence for reference purposes
    //    accessed by getPrevious
    
    std::string current;
    //Holds the current sentence
    //    reset and repopulated by generateSentence
    //    accessed by getCurrent
    
    std::string fileBuffer;
    //Used to hold files while they are being processed into the markov structure
    
    std::map<std::string, std::vector<std::string>> mStruct[3];
    //Array has 3 elements, one for each difficulty
    //Each element is a map between a string (a prefix) and a vector of strings (a suffix)
    
    
    
};


#endif /*TEXTGEN_H_*/



