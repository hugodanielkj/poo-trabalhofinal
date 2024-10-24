#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Roupa {
private:
    string nome;
    int quantidade;
    string tamanho;

public:
    Roupa(string n, int q, string t) : nome(n), quantidade(q), tamanho(t) {}

    // Função para obter os dados em formato string
    string toString() const {
        return nome + "," + to_string(quantidade) + "," + tamanho;
    }

    // Funções get para cada atributo
    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    string getTamanho() const { return tamanho; }

    // Função para carregar uma peça de roupa a partir de uma string CSV
    static Roupa fromString(const string& dados) {
        size_t pos1 = dados.find(',');
        size_t pos2 = dados.find(',', pos1 + 1);
        string nome = dados.substr(0, pos1);
        int quantidade = stoi(dados.substr(pos1 + 1, pos2 - pos1 - 1));
        string tamanho = dados.substr(pos2 + 1);
        return Roupa(nome, quantidade, tamanho);
    }

    // Adicionar uma nova roupa
    Roupa adicionarRoupa(){

    }
};

// Função para salvar o estoque em um arquivo
void salvarEstoque(const vector<Roupa>& estoque, const string& arquivo) {
    ofstream file(arquivo);
    if (file.is_open()) {
        for (const Roupa& roupa : estoque) {
            file << roupa.toString() << endl;
        }
        file.close();
        cout << "Estoque salvo com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvar." << endl;
    }
}

// Função para carregar o estoque de um arquivo
vector<Roupa> carregarEstoque(const string& arquivo) {
    vector<Roupa> estoque;
    ifstream file(arquivo);
    string linha;
    if (file.is_open()) {
        while (getline(file, linha)) {
            estoque.push_back(Roupa::fromString(linha));
        }
        file.close();
        cout << "Estoque carregado com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para carregar." << endl;
    }
    return estoque;
}

int abrirMenu(){
  int escolhaDoUsuario;
  do {
    cout << "O que voce deseja fazer:\n";
    cout << "1 - Adicionar uma nova roupa\n";
    cout << "2 - Aumentar/diminuir a quantidade de uma roupa ja existente\n";
    cout << "3 - Excluir uma roupa do estoque\n";
    cout << "4 - Ver como esta o meu estoque\n";
    cout << "0 - Sair do programa\n";
    cin >> escolhaDoUsuario;
    if(escolhaDoUsuario > 4 || escolhaDoUsuario < 0)
      cout << "Erro! Escolha uma das opcoes abaixo.";
  }
  while(escolhaDoUsuario > 4 || escolhaDoUsuario < 0);

  return escolhaDoUsuario;
}

void execucaoDaEscolhaDoUsuario(const int &escolhaDoUsuario){
  switch(escolhaDoUsuario){
    case 0:
      adicionarRoupa();
      break;
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
  }
}

int main() {
    vector<Roupa> estoque;
    string nomeArquivoEstoque;

    cout << "Qual o nome do arquivo em que vai ser lido o estoque: ";
    cin >> nomeArquivoEstoque;

    vector<Roupa> estoqueCarregado = carregarEstoque(nomeArquivoEstoque);

    abrirMenu();

    // Exibe o estoque carregado
    for (const Roupa& roupa : estoqueCarregado) {
        cout << "Nome: " << roupa.getNome() << ", Quantidade: " << roupa.getQuantidade() << ", Tamanho: " << roupa.getTamanho() << endl;
    }

    return 0;
}
