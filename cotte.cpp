#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_N (int)1e7+5
using namespace std;

class FileReader {
	private:
	FileReader(const FileReader& fr) {}
	
	int maxBufferSize, bufferSize, bufferPointer;
	int fileNo;
	char* buffer;
	
	/** 
	 * Load the buffer and replace the old one
	 */
	void loadBuffer() {
		bufferSize = read(fileNo, buffer, maxBufferSize);
		// reset the pointer to the begin
		bufferPointer = 0;
	}
	/**
	 * Get the next char from the buffer, if the buffer finish reload it
	 */ 
	inline char nextChar() {
		// reload the buffer if needed
		if (bufferPointer >= bufferSize) 
			loadBuffer();
		
		return buffer[bufferPointer++];
	}
	/**
	 * Skip all spaces (spaces, end line, tabulation). If the file finish
	 * return false
	 */ 
	bool skipSpaces() {
		char c;
		while (((c = nextChar()) == ' ' || c == '\n' || c == '\t') && c != '\0') 
			;
		if (c == '\0')
			return 0;
		// un-get the last chat
		bufferPointer--;
		return 1;
	}
	
	public:
	/**
	 * Load the file and the buffer
	 * _name is the file name
	 * _bufferSize is the maximum amuount of memory used for the buffer
	 */ 
	FileReader(const char* _name, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = open(_name, O_RDONLY);
		maxBufferSize = _bufferSize;
		
		loadBuffer();
	}
	/**
	 * Load from a file descriptor
	 * _fileNo is the file descriptor (must be opened in read mode! try STDIN_FILENO ;)
	 * _bufferSize is the maximum amount of memory used for the buffer
	 */ 
	FileReader(int _fileNo, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = _fileNo;
		maxBufferSize = _bufferSize;
		
		loadBuffer();
	}
	/**
	 * Release the buffer
	 */ 
	~FileReader() {
		free(buffer);
		close(fileNo);
	}
	
	/**
	 * Read the next integer from the buffer. Negative numbers are allowed
	 */ 
	int readInt() {
		int n = 0, mul = 1;
		char c;
		
		// if the file ends there isn't a number. So yeah
		if (!skipSpaces()) abort();
		
		// try to parse the sign
		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else // if the sign is not present, un-get the read char
			bufferPointer--;
		
		do {
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10 + (c-'0');
		} while (c >= '0' && c <= '9');
		return n * mul;
	}
	
	/**
	 * Read a long long from the buffer. Negative #s are ok!
	 */ 
	long long readLongLong() {
		long long n = 0;
		int mul = 1;
		char c;
		
		if (!skipSpaces()) abort();
		
		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else 
			bufferPointer--;
		
		do {
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10 + (c-'0');
		} while (c >= '0' && c <= '9');
		return n * mul;
	}
	
	/**
	 * Read a double from the buffer. Formats allowed are:
	 *  0.1
	 *  1
	 *  -1
	 *  -1.0
	 *  .0
	 *  -.0
	 */ 
	double readDouble() {
		double n = 0;
		int mul = 1, i = 0;
		int dotpos = 0;
		char c;
		
		if (!skipSpaces()) abort();
				
		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else 
			bufferPointer--;
			
		do {
			i++;
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10.0 + (c-'0');
			if (c == '.')
				dotpos = i;
		} while ((c >= '0' && c <= '9') || c == '.');
		
		// if there is the dot
		if (dotpos > 0) 
			for (; dotpos < i-1; dotpos++)
				n /= 10.0;
		
		return n * mul;
	}
	
	/**
	 * Read a string from the buffer. Spaces, tabs, endlines, EOF 
	 * terminate the string
	 */ 
	int readString(char* str) {
		// no string, no party
		if (!skipSpaces())
			return str[0] = 0;		
		
		char c;
		int l = 0;
		
		do {
			c = nextChar();
			str[l++] = c;
		} while (c != ' ' && c != '\n' && c != '\t' && c != '\0');
		str[--l] = '\0';
		return l;
	}
	
	/**
	 * Read a single char (skipping spaces before)
	 */ 
	char readChar() {
		if (!skipSpaces())
			return '\0';
		return nextChar();
	}
};


class FileWriter {
	private:
	FileWriter(const FileWriter& fr) {}
	char* buffer;
	int bufferPointer, bufferSize;
	int fileNo;
	
	/**
	 * Write the buffer to file
	 */ 
	inline void flushBuffer() {
		if (write(fileNo, buffer, bufferPointer) == -1)
			abort();
		bufferPointer = 0;
	}
	/**
	 * Write a char into the buffer. Flush it if needed
	 */ 
	inline void writeCharBuffer(char c) {
		if (c != 0)	
			buffer[bufferPointer++] = c;
		if (bufferPointer+5 >= bufferSize) 
			flushBuffer();
	}
	
	public:
	/**
	 * Open the file for writing. If the file doesn't exists, it will be
	 * created
	 * path: the file path
	 * bufSize: the size of the buffer
	 */ 
	FileWriter(const char* path, int bufSize = 100000) {
		fileNo = open(path, O_CREAT|O_TRUNC|O_WRONLY, S_IRWXU|S_IRWXG|S_IRWXO);
		buffer = (char*)malloc(bufSize);
		bufferSize = bufSize;
		bufferPointer = 0;
	}
	/**
	 * Use an already open file descriptor. Warning! if the same file
	 * is used with an other library it could become incoerent
	 * fd: the file descriptor open in writing
	 * bufSize: the size of the buffer
	 */ 
	FileWriter(int fd, int bufSize = 100000) {
		fileNo = fd;
		buffer = (char*)malloc(bufSize);
		bufferSize = bufSize;
		bufferPointer = 0;
	}
	/**
	 * Release the buffer and close the file
	 */ 
	~FileWriter() {
		flushBuffer();
		free(buffer);
		close(fileNo);
	}
	/**
	 * Write an integer into the buffer. sep will be appended after
	 */ 
	void writeInt(int val, char sep = '\n') {
		writeLongLong(val, sep);
	}
	/**
	 * Write a long integer into the buffer. sep will be appended after
	 */ 
	void writeLongLong(long long val, char sep = '\n') {
		char buf[21]; int point = 0;
		bool neg = val < 0;
		if (neg) val = -val;
		while (val > 0) {
			buf[point++] = (val % 10) + '0';
			val /= 10;
		}
		
		if (neg) writeCharBuffer('-');
		for (int i = point-1; i >= 0; i--)
			writeCharBuffer(buf[i]);
		if (point == 0) writeCharBuffer('0');
		writeCharBuffer(sep);
	}
	/**
	 * Write a char into the buffer. sep will be appended after
	 */ 
	void writeChar(char c, char sep = '\n') {
		writeCharBuffer(c);
		writeCharBuffer(sep);
	}
	/**
	 * Write a string of l charaters into the buffer. sep will be 
	 * appended after
	 */ 
	void writeString(char* str, int l, char sep = '\n') {
		while (l--) {
			writeCharBuffer(str[0]);
			str++;
		}
		writeCharBuffer(sep);
	}
	/**
	 * Flush the buffer
	 */ 
	void flush() {
		flushBuffer();
	}
};

typedef pair< int, int > ii;

int M, F, C, sol[MAX_N];
vector<int> s;
ii cottarelle[MAX_N];
bool cmp(ii a, ii b){
    if(a.first != b.first)
    	return a.first < b.first;
    else
    	return a.second > b.second;
}

int lis[MAX_N];

int main(){
    /*#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    //ios_base::sync_with_stdio(false);
    //cin>>M>>F>>C;
    FileReader fr("input.txt");
    //scanf("%d %d %d",&M,&F,&C);
    M = fr.readInt(); F = fr.readInt(); C = fr.readInt();
    for(int i=0;i<C;i++){
        int m,f; //scanf("%d %d",&m,&f);//in>>m>>f;
        cottarelle[i].first = fr.readInt(); //m;
        cottarelle[i].second = fr.readInt(); //f;
    }
    sort(cottarelle, cottarelle + C ,cmp);
    
    for(int i=0;i<C;i++){
        vector<int>::iterator it = lower_bound(s.begin(),s.end(),cottarelle[i].second);
        if(it == s.end())
            s.push_back(cottarelle[i].second);
        else
            *it = cottarelle[i].second;

    }
	int k = s.size()*2;
	FileWriter fw("output.txt", 100000);
    fw.writeInt(k);//printf("%d",k);


    //in.close(); out.close();
    return 0;
}
