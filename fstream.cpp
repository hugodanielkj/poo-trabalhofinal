#include <iostream>
#include <fstream>
using namespace std;

void imprimeArquivo(string x){
  ifstream arquivo(x);
  string linha;

  if(arquivo.is_open()){
    while(getline(arquivo, linha)){
      cout << linha << endl;
    }
    arquivo.close();
  } else {
    cout << "Erro ao abrir o arquivo" << endl;
  }
}

void adicionaLinhaAoArquivo(string x){
  string novaLinha;
  cout << "Adicione nova linha ao arquivo: ";
  cin.ignore();
  getline(cin,novaLinha);

  fstream arquivo(x, ios::in | ios::out);
  if(arquivo.is_open()){
    arquivo.clear();  // Limpa os flags de erro após a leitura
    arquivo.seekp(0, ios::end);  // Move o ponteiro para o final
    arquivo << endl << novaLinha;
    arquivo.close();  // Fecha o arquivo
  } else {
    cout << "erro ao abrir" << endl;
  }
}

int main(){
  string nomeArquivo;
  cout << "Digite o nome do arquivo: ";
  cin >> nomeArquivo;
  adicionaLinhaAoArquivo(nomeArquivo);
  cout << endl;
  imprimeArquivo(nomeArquivo);

  return 0;
}