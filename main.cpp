#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Roupa {
  private:
    string name;
    int amount;
    string size;

  public:
    Roupa(string n, int q, string t) : name(n), amount(q), size(t) {}

    string getName() const {return name;}
    int getAmount() const {return amount;}
    string getSize() const {return size;}

    void setAmount(int a) {amount = a;}

    void show() const {
      cout << "Nome: " << name << "Quantidade: " << amount << "Tamanho: " << size << endl;
    }
};

void addCloth(vector<Roupa>& estoque){
  string name;
  int amount;
  string size;

  cout << "Digite o nome da peça: ";
  cin.ignore();
  getline(cin,name);
  cout << "Digite quantidade disponivel: ";
  cin >> amount;
  
}

int main(){

  return 0;
}