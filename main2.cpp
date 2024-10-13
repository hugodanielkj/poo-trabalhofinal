#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe que representa uma peça de roupa
class Roupa {
private:
    string nome;      // Nome da peça de roupa
    int quantidade;   // Quantidade disponível no estoque
    string tamanho;   // Tamanho da peça (P, M, G, GG, etc.)

public:
    // Construtor para inicializar os atributos
    Roupa(string n, int q, string t) : nome(n), quantidade(q), tamanho(t) {}

    // Funções para acessar os dados
    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    string getTamanho() const { return tamanho; }

    // Função para modificar a quantidade
    void setQuantidade(int q) { quantidade = q; }

    // Função para exibir informações da peça de roupa
    void exibir() const {
        cout << "Nome: " << nome << ", Quantidade: " << quantidade << ", Tamanho: " << tamanho << endl;
    }
};

// Função para adicionar uma nova roupa ao estoque
void adicionarRoupa(vector<Roupa>& estoque) {
    string nome;
    int quantidade;
    string tamanho;

    cout << "Digite o nome da peça de roupa: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);
    cout << "Digite a quantidade disponível: ";
    cin >> quantidade;
    cout << "Digite o tamanho da peça (P, M, G, etc.): ";
    cin >> tamanho;

    Roupa novaRoupa(nome, quantidade, tamanho);
    estoque.push_back(novaRoupa); // Adiciona a nova roupa ao estoque
}

// Função para exibir o estoque completo
void exibirEstoque(const vector<Roupa>& estoque) {
    if (estoque.empty()) {
        cout << "O estoque está vazio." << endl;
    } else {
        cout << "Estoque atual:" << endl;
        for (const Roupa& roupa : estoque) {
            roupa.exibir();
        }
    }
}

// Função para modificar a quantidade de uma peça de roupa
void modificarQuantidade(vector<Roupa>& estoque) {
    string nome;
    cout << "Digite o nome da peça de roupa para modificar a quantidade: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);

    // Procurar a roupa no estoque
    for (Roupa& roupa : estoque) {
        if (roupa.getNome() == nome) {
            int novaQuantidade;
            cout << "Digite a nova quantidade: ";
            cin >> novaQuantidade;
            roupa.setQuantidade(novaQuantidade);
            cout << "Quantidade atualizada com sucesso!" << endl;
            return;
        }
    }
    cout << "Peça de roupa não encontrada no estoque." << endl;
}

int main() {
    vector<Roupa> estoque; // Vetor que armazena as roupas

    int opcao;

    do {
        // Menu simples
        cout << "\nMenu de Estoque de Roupas" << endl;
        cout << "1. Adicionar nova roupa ao estoque" << endl;
        cout << "2. Exibir estoque completo" << endl;
        cout << "3. Modificar quantidade de uma peça" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            adicionarRoupa(estoque);
            break;
        case 2:
            exibirEstoque(estoque);
            break;
        case 3:
            modificarQuantidade(estoque);
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}