#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

  std::string arquivo;
  std::string palavraArquivo;
  std::string palavraBusca;
  std::string confirmaSaida;

  bool loop = true;

  auto rng = std::default_random_engine {};

  vector<std::string> vectorSAM;
  vector<std::string> vectorRAM;

  cout << "Escreva o nome do arquivo:" << endl;
  cin >> arquivo;

  ifstream infile(arquivo + ".txt");

  while (loop)
  {
    while (infile >> palavraArquivo)
    {
      vectorSAM.push_back(palavraArquivo);
      vectorRAM.push_back(palavraArquivo);
    }
    
    shuffle(std::begin(vectorRAM), std::end(vectorRAM), rng);

    cout << "Digite 'end' para sair..." << endl;
    cout << "Escreva a palavra da Busca: ";
    cin >> palavraBusca;

    if(palavraBusca == "end"){
      cout << "Deseja mesmo sair? (y/n)" << endl;
      cin >> confirmaSaida;

      if(confirmaSaida == "y"){
        loop = false;
        break;
      }
    }

    //RAM
    auto startRAM = high_resolution_clock::now();

    for(int i = 0; i < vectorRAM.size(); i++){
      cout << "- " << vectorRAM[i] << endl;
      if (palavraBusca == vectorRAM[i])
      {
        cout << "Palavra achada: " << palavraBusca << " na posicao " << i << endl;
        break;
      }
      if(i == vectorRAM.size()-1 || i == vectorRAM.size()){
        cout << "Palavra nao encontrada" << endl;
        break;
      }
    }

    auto stopRAM = high_resolution_clock::now();
    auto durationRAM = duration_cast<microseconds>(stopRAM - startRAM);

    cout << endl;
    cout << "RAM Demorou " << durationRAM.count() << " microsegundos"<< endl;

    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

    //SAM
    auto startSAM = high_resolution_clock::now();

    for(int i = 0; i < vectorSAM.size(); i++){
      cout << "- " << vectorSAM[i] << endl;
      if (palavraBusca == vectorSAM[i])
      {
        cout << "Palavra achada: " << palavraBusca << " na posicao " << i << endl;
        break;
      }
      if(i == vectorSAM.size()-1 || i == vectorSAM.size()){
        cout << "Palavra nao encontrada" << endl;
        break;
      }
    }

    auto stopSAM = high_resolution_clock::now();
    auto durationSAM = duration_cast<microseconds>(stopSAM - startSAM);

    cout << endl;
    cout << "SAM Demorou " << durationSAM.count() << " microsegundos"<< endl;

    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Resultados: " << endl;
    cout << "RAM: " << durationRAM.count() << " microsegundos" << endl;
    cout << "SAM: " << durationSAM.count() << " microsegundos" << endl;
    cout << endl;

  }

  cout << "Saiu" << endl;
  vectorSAM.clear();
  vectorRAM.clear();

  return 0;
}
