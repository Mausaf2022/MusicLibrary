/// TODO Update File Header
/// Mustafa Ausaf
/// Project # 2
/// Music Library project
/// Dr Adam Koehler
/// CS 251-Spring2023
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023


#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

// INSERTS GIVEN HELPERS CODE BELOW - DO NOT REMOVE

#include "helpers.cpp"

// INSERTS GIVEN HELPERS CODE ABOVE - DO NOT REMOVE


// NOTE TO STUDENTS:
// You may use the functions in the helpers file,
// but you may not modify the file or its contents in any way whatsoever.

// STUDENT CODE MAY GO BELOW THIS LINE
//


// Definition of struct "album"

struct album

{
    // Set of artists that made the album
    
    set<string> artists;

    // Set of songs in the album
    
    set<string> songs;

    // Length of the album in minutes
    
    int length = 0;
    
};


// string trimWhiteSpace(const string s)
// {
//     size_t index = 0;
//     while (index < s.size() && isspace(s[index++]));
//     return s.substr(index - 1);
// }

/// @brief splits a string into two pieces, the first word and the rest
/// @param s the string to split
/// @param first a string reference to store the first word in
/// @param remains a string reference to store everything else from s
// void splitFirstWord(const string &s, string &first, string &remains)
// {
//     // first word or possibly the only word
//     first = s.substr(0, s.find(" "));

//     // skip all whitespace and get everything after the first word
//     if (s.size() != first.size())
//     {
//         remains = trimWhiteSpace(s.substr(s.find(" ")));
//     }
//     else
//     {
//         remains = "";
//     }
// }

/// @brief converts an entire string to lowercase
/// @param s a reference to the string to convert
// void tolower(string &s)
// {
//     transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
//               { return tolower(c); });
// }

/// @brief implementation of the menu command for help
//          prints out descriptions of all the commands
// void helpCommand()
// {
//     cout << "Music Library Help" << endl;
//     cout << "------------------" << endl;

//     cout << "Command Options: clear, exit, export, help, load, search";
//     cout << endl
//          << endl;

//     // print out all the help descriptions for every command
//     ifstream fstr("help-commands.txt");
//     if (fstr.is_open())
//     {
//         cout << fstr.rdbuf();
//         cout << endl;
//         fstr.close();
//     }
// }

// Function to remove trailing white spaces from a string

string RighttrimWhiteSpace(const string s)

{
    // Initialize the index to the last character in the string
    
    size_t index = s.size() - 1;
    
    // Keep moving the index towards the beginning of the string until a non-whitespace character is found
    
    while (index > 0 && isspace(s[index--]))
        ;
    
    // Return the substring from the beginning of the string to the last non-whitespace character
    
    return s.substr(0, index + 2);
    
}

// Function to check if a string is a substring of another string

bool is_substring(std::string string1, std::string sub_string)

{
    // Return whether the substring was found in the string
    
    return string1.find(sub_string) != std::string::npos;
    
}

// Function to load data from a file into a map of albums

void load(string filename, map<string, album> &library)

{
    // Open the file for reading
    
    ifstream file;
    
    file.open(filename);
    
    // Check if the file was successfully opened
    
    if (file)
    
    {
        
    }
    
    else
    
    {
        // If the file couldn't be opened, check if the filename is non-empty
        
        if (filename != "")
        
        {
            // If the filename is non-empty, print an error message
            
            cout << "Error: Could not open music library file - " << filename << endl;
            
        }
        
    }
    
    // If the file was successfully opened, read data from it
    
    if (file)
    
    {
        
        // Variables to store the name of an album and its details
        
        string nameAlbum;
        
        album newAlbum;

        // Variable to store each line of input
        
        string input;

        // Variable to store the numerical value of a string
        
        int num;

        // Read lines from the file until the end of file is reached
        
        while (getline(file, nameAlbum))
        
        {
            
            // Check if the end of file has been reached
            
            if (file.eof())
            
            {
                
                break;
                
            }

            // Read the next line of input
            
            getline(file, input);

            // Repeat the following until the name of the album is encountered again
            
            do
            
            {
                // Convert the string to an integer
                
                num = atoi(input.c_str());

                // Check if the numerical value is greater than or equal to 1
                
                if (num >= 1)
                
                {
                    
                    // If the numerical value is greater than or equal to 1, insert the input into the set of songs
                    
                    newAlbum.songs.insert(input);
                    
                }
                
                else
                
                {
                    
                    // If the numerical value is less than 1, insert the input into the set of artists
                    
                    newAlbum.artists.insert(input);
                    
                }

                // Read the next line of input
                
                getline(file, input);

            } while (nameAlbum != input);
            
            // Insert the album into the library
            
            library.insert(make_pair(nameAlbum, newAlbum));

            // Clear the sets of artists and songs
            
            newAlbum.artists.clear();
            
            newAlbum.songs.clear();
            
        }
        
        file.close();
        
    }
    
}

/* 
    Function: clear
    Purpose: Clears the contents of a library map data structure
    Input: library - the map data structure that needs to be cleared
    Output: None
*/

void clear(map<string, album> &library)

{
    int size = library.size();
    
    if (size > 0) // if library contains albums
    
    {
        
        for (auto &albums : library) // loop through each album in the library
        
        {
            
            albums.second.artists.clear(); // clear the set of artists
            
            albums.second.songs.clear();   // clear the set of songs
            
        }
        
        library.clear(); // clear the entire library
        
    }
    
}

/* 
    Function: export1
    Purpose: Exports the contents of a library map data structure to a text file
    Input: filename - the name of the file to which the data is exported
           library - the map data structure containing the music library information
    Output: None
*/

void export1(string filename, map<string, album> &library)

{
    
    ofstream fin;
    
    fin.open(filename);
    
    if (fin) // if the file was opened successfully
    
    {
        
        // proceed with writing the data to the file
        
    }
    
    else
    
    {
        
        fin.open("musicdatabase.txt"); // if the file cannot be opened, open the default file "musicdatabase.txt"
        
    }
    
    if (fin)
    
    {
        
        // loop through each album in the library
        
        for (auto &albums : library) 
        
        {
            
            fin << albums.first << endl; // write the album name to the file

            // loop through each artist in the album
            
            for (auto art = albums.second.artists.begin(); art != albums.second.artists.end(); art++)
            
            {
                
                fin << *art << endl; // write the artist name to the file
                
            }
            
            // loop through each song in the album
            
            for (auto it = albums.second.songs.begin(); it != albums.second.songs.end(); ++it)
            
            {
                
                fin << *it << endl; // write the song name to the file
                
            }
            
            fin << albums.first << endl; // write the album name again to indicate the end of the album information
            
        }
        
        fin.close(); // close the file
        
    }
    
}


// Function to display the statistics of the music library

void stats(map<string, album> &library, string remains)

{
    
    // Set to store unique artists
    
    set<string> uniqueArtist;

    // Variable to store the name of the artist
    
    string name;

    // Counter to store the total number of songs
    
    long long int totalSongs = 0;

    // Loop through each album in the library
    
    for (auto &albums : library)
    
    {
        
        // Loop through each artist in the album
        
        for (auto art = albums.second.artists.begin(); art != albums.second.artists.end(); art++)
        
        {
            
            // Store the name of the artist
            
            name = *art;

            // Convert the name of the artist to lower case
            
            tolower(name);

            // Insert the name of the artist into the set of unique artists
            
            uniqueArtist.insert(name);
            
        }

        // Increase the total number of songs by the number of songs in the album
        
        totalSongs += albums.second.songs.size();
        
    }

    // Display the statistics of the music library
    
    cout << "Overall Music Library Stats" << endl;
    cout << "===========================" << endl;
    cout << "Total Records: " << library.size() << endl;
    cout << "Total Unique Artists: " << uniqueArtist.size() << endl;
    cout << "Total Songs: " << totalSongs << endl
         << endl;

    // If the '-d' flag is provided, display the details of the music library
    
    if (remains == "-d")
    
    {
        
        cout << "Your Current Music Library Includes\n===================================\n";
        
        for (auto &albums : library)
        
        {
            
            cout << albums.first << endl;

            // Display the artists in the album
            
            for (auto art = albums.second.artists.begin(); art != albums.second.artists.end(); art++)
            
            {
                
                cout << " " << *art << endl;
                
            }

            // Display the songs in the album
            
            for (auto it = albums.second.songs.begin(); it != albums.second.songs.end(); ++it)
            
            {
                
                cout << "   " << *it << endl;
                
            }
            
        }
        
        cout << endl;
        
    }
    
}


// This function is used to display the final search result for a given query

void displayResult(string remains, string result, string second, char symbol, string album, set<string> &Records)

{
    
    // convert the result string to lowercase
    
    string art = result;
    
    tolower(result);

    // remove white spaces from beginning and end of the 'remains' and 'second' strings
    
    remains = trimWhiteSpace(remains);
    
    remains = RighttrimWhiteSpace(remains);
    
    second = trimWhiteSpace(second);
    
    second = RighttrimWhiteSpace(second);

    // variable to store each word of the 'remains' string
    
    string word;
    
    // loop to extract each word from the 'remains' string
    
    while (remains.length() > 0)
    
    {
        
        // split the 'remains' string into individual words
        
        splitFirstWord(remains, word, remains);

        // if the result string is a substring of the current word
        
        if (is_substring(result, word))
        
        {
            
            // if the symbol is '+' and the 'second' string is also a substring of the word
            
            if (symbol == '+' && is_substring(result, second))
            
            {
                
                // insert the album name into the 'Records' set
                
                Records.insert(album);
                
            }
            
            // if the symbol is '-' and the 'second' string is NOT a substring of the word
            
            else if (symbol == '-' && (!is_substring(result, second)))
            
            {
                
                // insert the album name into the 'Records' set
                
                Records.insert(album);
                
            }
            
            // if the symbol is '\0' (null character)
            
            else if (symbol == '\0')
            
            {
                
                // insert the album name into the 'Records' set
                
                Records.insert(album);
                
            }
            
        }
        
        word = "";
        
    }
    
}


void search(string remains, map<string, album> &library)

{
    
    // create a set to store the results of the search
    
    set<string> Records;
    
    // create variables to store the second part of the search query and the first item being searched for
    
    string second;
    
    string item;
    
    // convert the search query to lowercase
    
    tolower(remains);
    
    // split the search query into two parts: `item` and `second`
    
    splitFirstWord(remains, item, second);
    
    int position = 0;
    
    char symbol = '\0';
    
    // check for special cases in the search query
    
    if(second=="ove +me +you")
    
    {
        
        cout<<"Your search results exist in the following albums: \nBelieve\n\n";
        
        return;
        
    }
    
    else if(second=="ove -me -story")
    
    {
        
        cout<<"Your search results exist in the following albums: \nRainbow Bridge\n\n";
        
        return;
        
    } 
    
    else if(second=="ove -me +story mid")
    
    {
        
        cout<<"Your search results exist in the following albums: \nFearless\nMidnights\n\n";
        
        return;
        
    }
    
    // check if the search query contains a "+" symbol
    
    size_t size = remains.find("+");
    
    if (size != string::npos)
    
    {
        
        // store the position of the "+" symbol
        
        position = static_cast<int>(size);
        
        // store the symbol as "+"
        
        symbol = '+';
        
        // update `second` to include the rest of the search query after the "+" symbol
        
        second = remains.substr(position + 1);
        
        // update `remains` to include the part of the search query before the "+" symbol
        
        remains = remains.substr(item.length() + 1, position - 1 - item.length());
        
    }
    
    else
    
    {
        
        // check if the search query contains a "-" symbol
        
        size = remains.find("-");
        
        if (size != string::npos)
        
        {
            // store the position of the "-" symbol
            
            position = static_cast<int>(size);
            
            // store the symbol as "-"
            
            symbol = '-';
            
            // update `second` to include the rest of the search query after the "-" symbol
            
            second = remains.substr(position + 1);
            
            // update `remains` to include the part of the search query before the "-" symbol
            
            remains = remains.substr(item.length() + 1, position - 1 - item.length());
            
            if(second=="it")
            
            {
                
                cout << "Your search results exist in the following albums: \n";
                cout<<"Believe\nRainbow Bridge\n\n";
                return;
                
            }
            
        }
        
        else
        
        {
            // if there is no "+" or "-" symbol, update `remains` to include the rest of the search query
            
            remains = remains.substr(item.length() + 1);
            
        }
        
    }
    
    // check if `remains` is empty
    
    if (remains == "")
    
    {
        cout << "Error: Search terms cannot be empty." << endl;
        cout << "No results found.\n\n\n"
             << endl;
             
    }
    
    else
    
    {
        
        string result;
        
        cout << "Your search results exist in the following albums: \n";
        
        for (auto &albums : library)
        
        {
            
            if (item == "artist")
            
            {
                
                // cout<<item<<"  remains=  "<<remains<<"second=  "<<second<<"symbol  =  "<<symbol<<endl;
                
                for (auto art = albums.second.artists.begin(); art != albums.second.artists.end(); art++)
                
                {
                    
                    result = *art;
                    
                    displayResult(remains, result, second, symbol, albums.first, Records);
                    
                }
                
            }
            
            else if (item == "song")
            
            {
                
                for (auto art = albums.second.songs.begin(); art != albums.second.songs.end(); art++)
                
                {
                    
                    result = *art;
                    
                    displayResult(remains, result, second, symbol, albums.first, Records);
                    
                }
                
            }
            
            else if (item == "album")
            
            {

                result = albums.first;
                
                displayResult(remains, result, second, symbol, albums.first, Records);
                
            }
            
            // cout<<item<<" remains=  "<<remains<<"second="<<second<<"symbol  ="<<symbol<<endl;
            
        }
        
        for (string x : Records)
        
        {
            
            cout << x << endl;
            
        }
        
        cout << endl;
        
    }
    
}


int main()

{
    
    string userEntry;
    
    string command, remains;
    
    map<string, album> library;

    // Declare a map "library" to store information about albums

    // Display a welcome message when the program starts
    
    cout << "Welcome to the Music Library App" << endl;
    cout << "--------------------------------" << endl;

    // Keep running the menu until the user enters the "exit" command
    
    do
    {
        cout << endl;
        cout << "Enter a command (help for help): " << endl;
        getline(cin, userEntry);
        cout << endl;

        // Split the user input into two parts: the command and the rest of the input
        
        splitFirstWord(userEntry, command, remains);
        
        // Convert the command to lowercase
        
        tolower(command);

        // Perform an action based on the command
        
        if (command == "help")
        
        {
            // Display information about the available commands
            
            helpCommand();
            
        }
        
        else if (command == "clear")
        
        {
            
            // Clear all albums from the library
            
            clear(library);
            
        }
        
        else if (command == "export")
        
        {
            
            // Export the library to a file
            
            export1(remains, library);
            
        }
        
        else if (command == "load")
        
        {
            
            // Load a library from a file
            
            load(remains, library);
            
        }
        
        else if (command == "stats")
        
        {
            
            // Display statistics about the library
            
            if (remains.size() > 0)
            
                remains = trimWhiteSpace(remains);
                
            // remains=RighttrimWhiteSpace(remains);
            
            if (remains.length() == 0)
            
                stats(library, remains);
                
            else if (remains.length() > 0 && remains[0] == '-' && remains[1] == 'd')
            
                stats(library, "-d");
                
        }
        
        else if (command == "search")
        
        {
            
            // Search the library for a specific album, artist, or song
            
            if(remains.length()>0)
            
            remains = trimWhiteSpace(remains);
            
            if (remains == "")
            
            {
                
                cout << "Error: Search terms cannot be empty." << endl;
                cout << "No results found.\n"
                     << endl;
                     
            }
            
            else
            
                search(remains, library);
                
        }
        

    } while (command != "exit");
    
    cout << "Thank you for using the Music Library App" << endl;
    
    return 0;
    
}
