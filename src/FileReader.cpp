#include "FileReader.h"


FileReader::FileReader() {


}

void FileReader::openFile(string filePath) {
	//Checa se o arquivo enviado por parâmetro possui a extensão correta, joga um erro caso negativo
	if(filePath.substr(filePath.find_last_of(".") + 1) != "der"){
		throw runtime_error("O arquivo " + filePath + " não pode ser aberto (Extensão inválida).");
	}
	else{
		//Tenta abrir uma stream do conteúdo do arquivo, joga um erro em caso de falha.
		fileStream = ifstream(filePath);
		if(!fileStream.is_open()){
			throw runtime_error("O arquivo " + filePath + " não pode ser aberto (Arquivo não encontrado ou permissões insuficientes).");
		}
	}

}

void FileReader::openFileToBuffer(string filePath) {
	openFile(filePath);

	//Vai até o fim da stream e volta para checar o tamanho necessário de buffer a ser alocado em memória
	fileStream.seekg(0, fileStream.end);
	size = fileStream.tellg();
	fileStream.seekg(0, fileStream.beg);

	//Inicializa o buffer com o tamanho necessário
	buf = vector<char>(size);
	//Lê todo o conteúdo do arquivo para a memória
	fileStream.read(buf.data(), size);

}

vector<char>* FileReader::getBuffer(){
	return &buf;

}

streamsize FileReader::getBufferSize(){
	return size; 
}


