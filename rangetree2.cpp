#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
 
/**
 * Read a file (a lot) faster than scanf/cin
 */ 
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








struct mod{
    mod() { zero = uno = due = 0; }
    int zero;
    int uno;
    int due;
};
mod st[2*MAX_N];
int lazy[MAX_N];

int left(int p){ return (p << 1); }
int right(int p){ return ((p << 1) +1); }

void turn(int p){
    swap(st[p].zero, st[p].due);
    swap(st[p].uno, st[p].due);
}

void propagate(int p, int L, int R){
    if(lazy[p] != 0){
        lazy[p] %= 3;
        for(int i=0;i<lazy[p];i++){
            turn(p);
        }
        if(L != R){
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 3;
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 3;
        }
    lazy[p] = 0;
    }
}

void build(int p, int L, int R){
    st[p].zero = R - L + 1;
    if(L != R){
        int mid = (L + R) /2;
        build(left(p), L, mid);
        build(right(p), mid + 1, R);
    }
}

void update(int p, int L, int R, int i, int j){
//    cout<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
    propagate(p, L, R);
    if(L > j || R < i)
        return;
    if(L >= i && R <= j){
        turn(p);
        if(L != R){
            lazy[left(p)] = (lazy[left(p)]+1) % 3;
            lazy[right(p)] = (lazy[right(p)]+1) % 3;
        }
        return;
    }
    int mid = (L + R)/2;
    update(left(p), L, mid, i, j);
    update(right(p), mid + 1, R, i, j);
    st[p].uno = st[left(p)].uno + st[right(p)].uno;
    st[p].due = st[left(p)].due + st[right(p)].due;
    st[p].zero = st[left(p)].zero + st[right(p)].zero;
}

int query(int p, int L, int R, int i, int j){
    propagate(p, L, R);
    if(L > j || R < i)
        return 0;
    if(L >= i && R <= j){
//        cout<<L<<" "<<R<<" "<<st[p].zero<<endl;
        return st[p].zero;
    }
    int mid = (L + R) / 2;
    return query(left(p), L, mid, i, j) + query(right(p), mid+1, R, i, j);
}

int n, m;

int main(){
//    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
	FileReader fr("input.txt");
	FileWriter fw("output.txt");
    n = fr.readInt(); m = fr.readInt(); //scanf("%d %d",&n, &m);
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        int t,t2,t3;
        t = fr.readInt(); t2 = fr.readInt(); t3 = fr.readInt();//scanf("%d %d %d",&t,&t2,&t3);
        if(t == 0)
            update(1,0,n-1,t2,t3);
        else
		fw.writeInt(query(1,0,n-1,t2,t3), '\n');
            //printf("%d\n",query(1,0,n-1,t2,t3));
    }

    return 0;
}

