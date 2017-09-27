#include "DerHandler.h"

 
DerHandler::DerHandler(){

}

void DerHandler::interpretDer(char* data, streamsize size) {
	//Converte os dados do buffer recebido para unsigned char (necessário para a utilização das funções x509 do OpenSSL) e decodifica o arquivo DER em memória para estrutura interna do OpenSSL
	const unsigned char *u_data = reinterpret_cast<unsigned char*>(data);
	internal_cert = d2i_X509(NULL, &u_data, size);
}

char* DerHandler::getSubjectData(){
	//Obtém os dados do titular e os retorna em formato de string de uma linha
	X509_NAME* subject = X509_get_subject_name(internal_cert);
	return X509_NAME_oneline(subject, NULL, NULL);
}

