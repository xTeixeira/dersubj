#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

class FileReader{
	
	streamsize size;
	ifstream fileStream;
	vector<char> buf;

	public:
		FileReader();
		void openFile(string);
		void openFileToBuffer(string);
		vector<char>* getBuffer();
		streamsize getBufferSize();


};