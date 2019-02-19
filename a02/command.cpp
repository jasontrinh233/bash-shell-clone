#include "tokenizer.hpp"
#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include <readline/readline.h> 
#include <unistd.h> // work with getcwd and chdir

using namespace std;


// Parse token list and 
// execute valid commands
void execute_commands( list<string>& tokens_list )
{

	vector<string> tokens_array;

	list<string>::iterator it;
	
	// store token list in vector 
	// for element access
	for(it = tokens_list.begin(); it != tokens_list.end(); ++it)
	{
		tokens_array.push_back( *it );
	}


	/*
	 * These following procedures will
	 * anaylize redirections char <,>
	 * and background operater &
	 */
	int strip_from = 0;

	for(int i=0; i<tokens_array.size(); ++i)
	{
		if(tokens_array.at(i) == ">" || tokens_array.at(i) == "&" ||  tokens_array.at(i) == "<")
		{
			// strip all tokens
			// from this point
			strip_from = i;
			break;

		}
	}

	if(strip_from != 0)
	{
		for(int i=tokens_array.size(); i>strip_from; --i)
		{
			tokens_array.pop_back(); 
		}

		// echo back
		cout << "Message: IO redirection and background not implemented." << endl;
	}

	/* END */



	/*
	 * Change directory cd
	 */
	if( tokens_array.at(0) == "cd" )
	{
		if(tokens_array.size() != 2)
		{
			cout << "Error: Accepts exactly one argument." << endl;
		}
		else
		{
			if( chdir(tokens_array.at(1).c_str()) != 0 )
				cout << "Error: Directory does not exit or is not accessible." << endl;
		}
	}
	/* END */


	/*
	 * Current directory pwd
	 */
	if(tokens_array.size() == 1 && tokens_array.at(0) == "pwd")
	{
		char path[2048];

		if(getcwd(path, sizeof(path)) != NULL)
			cout << "Current directory: " << path << endl;
		else 
			cout << "Error: Unable to obtain current directory." << endl;

	}
	/* END */


	// // display vector 
	// for(int i=0; i<tokens_array.size(); ++i)
	// {
	// 	cout << tokens_array.at(i) << ";";
	// }
	// cout << endl;
}


int main (int argc, char *argv[]) 
{

	// Session starting...
	while(true)
	{
		
		char* str;
		list<string> tokens_list;

		// user input
		str = readline("> ");

		if(str == NULL)
			break;

		 // cast str to type string
		string prompt = string(str);


		// tokenize user prompt into tokens_list
		tokenize(prompt, tokens_list);


		// // display list of tokens
		// display(tokens_list);


		// analyze and execute
		// command
		execute_commands(tokens_list);


	} // End session

	cout << endl;


}