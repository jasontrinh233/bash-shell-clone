#include "tokenizer.hpp"
#include <string>
#include <list>
#include <iterator>
#include <iostream>


using namespace std;


// tokenize() implementation
void tokenize(string& str, list<string>& tokens_list)
{

	string spacer = " \t";  // whitespace char
	string special = "|;<>&";  // special char
	string quote = "\'\"";  // quotation char
	string escape = "\\";  // escape char
	int index = 0;
	char c = 0;
	char special_buff = 0; // buffer to store any special char
	char curr_quote = 0; // carry openning quote 
	bool is_quoted = false;
	bool done = false; // signals that the token is ready to push onto list
	string token;  // string buffer for the token
	int len = str.length();  // length of the input-string


	// iterate through every character of the prompt
	while(index < len)
	{
		c = str.at(index);
		special_buff = 0;

	
		// initial conddition of adding status for each character
		bool add_status = true;


		// check if backslash involved
		bool is_backslashed = false;
		if (escape.find_first_of(c) != string::npos)
		{
			++index; // move on to the character after backslash
			// more characters in prompt to go
			if(index < len)
			{
				// asign next character to c to investigate
				c = str.at(index);

				// good to be move into token string
				add_status = true;
			}
			else // no more characters left
			{
				// ignore the backslash character
				add_status = false;
			}

			is_backslashed = true;
		}
	

		// check if quotes involved
		if(!is_backslashed)
		{
			if(quote.find_first_of(c) != string::npos)
			{
				// if there is no quote before this character
				// then make this quote become an openning quote
				if(!is_quoted)
				{
					is_quoted = true;
					curr_quote = c;

					// ignore the quote character 
					add_status = false;
				}
				else // if there is an openning quote before
				{
					// find a matching quote to close the quotation part
					if(c == curr_quote)
					{
						is_quoted = false; // ended quotation part
						curr_quote = 0;

						add_status = false;
					}
				} 
			}
		}


		// check if whitespace or tab is involved
		if(!is_backslashed && !is_quoted)
		{
			if(spacer.find_first_of(c) != string::npos)
			{
				// if c is a spacer and the token string isn't empty
				// the token is complete
				if(!token.empty())
				{
					done = true;
				}

				// ignore whitespace character to the token
				add_status = false;
			}
		}


		// check if special character is involved
		bool add_special = false;
		if(!is_backslashed && !is_quoted)
		{
			if(special.find_first_of(c) != string::npos)
			{
				// if ch is a delimiter and the token string isn't empty
				// the token is complete
				if(!token.empty())
				{
					done = true;
				}

				// ignore this special char, don't add to token
				add_status = false;

				// add this special to separate token
				special_buff = c;
				add_special = true;
			}
		}


		// add characters to token
		if(add_status == true)
		{
			token.push_back(c);
		}


		// push token into list when done
		if(done==true && !token.empty())
		{
			tokens_list.push_back(token);

			// clear the contents
			token.clear();

			// reset for next token
			done = false;
		}


		// make special character a separate token
		if(add_special == true)
		{
			// the next token is the delimiter
			string special_token;
			special_token.push_back(special_buff);
			tokens_list.push_back(special_token);
		}


		++index; // condition update for while loop


	} /* END WHILE */


	// add the final token
	if( !token.empty() )
	{
		tokens_list.push_back(token);
	}


} /* END tokenizer() */



// display() implementation
void display( list<string>& tokens_list )
{

	list<string>::iterator it; // iterator for the list

	cout << "[";

	for(it = tokens_list.begin(); it != tokens_list.end(); ++it)
	{
		// prevent print , at the end
		if( it != tokens_list.begin() )
			cout << ","; 

		cout << "{" << *it << "}";
	}

	cout << "]" << endl;


} /* END display() */
























