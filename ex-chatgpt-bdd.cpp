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

int main() {
    vector<Roupa> estoque;

    // Adiciona algumas roupas
    estoque.push_back(Roupa("Camisa", 10, "M"));
    estoque.push_back(Roupa("Calça", 5, "G"));

    // Salva o estoque em um arquivo
    salvarEstoque(estoque, "estoque.csv");

    // Carrega o estoque do arquivo
    vector<Roupa> estoqueCarregado = carregarEstoque("estoque.csv");

    // Exibe o estoque carregado
    for (const Roupa& roupa : estoqueCarregado) {
        cout << "Nome: " << roupa.getNome() << ", Quantidade: " << roupa.getQuantidade() << ", Tamanho: " << roupa.getTamanho() << endl;
    }

    return 0;
}
