#include <openssl/x509.h>
#include <fstream>
using std::streamsize;

class DerHandler {

	X509* internal_cert;
	public:
		DerHandler();
		void interpretDer(char*, streamsize);
		char* getSubjectData();

};