#include <iostream>

using namespace std;

int findIndex4(string s, int pos = 0);
bool is4CharWord(string s, int pos);
bool isWordElement(char c);

int main() {
	string text;
	getline(cin, text);
	
	int index = -1;
	do {
		index = findIndex4(text, index + 1);
		if (index != -1)
			text.replace(index, 4, "best");
	} while (index != -1);
	
	cout << text;
}

int findIndex4(string s, int pos) {
	for (; pos < s.length(); ++pos)
		if (isWordElement(s[pos]) && is4CharWord(s, pos))
			return pos;
	return -1;
}

bool is4CharWord(string s, int pos) {
	bool is4char_word = true;
	for (int i = 0; i < 4; ++i)
		if (pos + i >= s.length() || !isWordElement(s[pos + i])) {
			is4char_word = false;
			break;
		}
	
	is4char_word = is4char_word && ( pos + 4 >= s.length() || !isWordElement(s[pos + 4]) );
	return is4char_word;
}

inline bool isWordElement(char c) {
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}
