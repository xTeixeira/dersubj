#include <iostream>
#include <vector>
#include "FileReader.h"
#include "DerHandler.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {

	if(argc <= 1){
		cout << "Nenhum certificado especificado.\nUso: dersubj [ARQUIVO1] [ARQUIVO2] ... [ARQUIVOn]" << endl;
		return 1;
	}
	else{
		//Construção de vetor com os argumentos (removendo o nome do executável)
		vector<string> arguments(argv+1, argv+1 + argc-1);
		
		//Inicialização dos objetos leitor de arquivos e decodificador do formato DER
		FileReader reader = FileReader();
		DerHandler handler = DerHandler();

		for(auto arg : arguments){
			//Tenta abrir o conteúdo do arquivo para buffer em memória
			try{reader.openFileToBuffer(arg);}
			catch(exception& e){
				cout << e.what() << endl;
				return 1;
			}
			//Interpreta o DER
			handler.interpretDer(reader.getBuffer()->data(), reader.getBufferSize());
			cout << "Dados do titular para o certificado " +arg + ":" << endl;
			
			//Recebe os dados do titular formatados em uma linha
			cout << handler.getSubjectData() << endl;
		}
	}

	return 0;

}