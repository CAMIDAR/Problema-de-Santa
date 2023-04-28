#include <iostream>
#include <map>
#include <vector>

using namespace std;

void mayor(int peso_total, vector<int> pesos, vector<int> alegrias) {
    map<int, int> alegrias_por_peso;
    int n = pesos.size();
    for (int i = 0; i < (1 << n); i++)
    {
        int peso_actual = 0, alegria_actual = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                peso_actual += pesos[j];
                alegria_actual += alegrias[j];
            }
        }
        if (peso_actual <= peso_total && alegria_actual > alegrias_por_peso[peso_actual])
        {
            alegrias_por_peso[peso_actual] = alegria_actual;
        }
    }
    int mayor_alegria = 0;
    for (auto it = alegrias_por_peso.begin(); it != alegrias_por_peso.end(); it++)
    {
        mayor_alegria = max(mayor_alegria, it->second);
    }
    cout << "Mayor alegria posible: " << mayor_alegria << endl;
}

int main() {
    int peso_total = 85;
    vector<int> pesos = {10, 25, 35, 10, 5};
    vector<int> alegrias = {25, 2, 30, 100, 2};
    mayor(peso_total, pesos, alegrias);
    return 0;
}
