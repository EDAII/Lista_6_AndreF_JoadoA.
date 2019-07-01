#include <iostream>
#include <list>
using namespace std;

class Grafo
{
    int V;
    list<int> *adj;

    void printaCaminhosUtil(int, int, bool[], int[], int &);

public:
    Grafo(int V);
    void addNo(int u, int v);
    void printaCaminhos(int s, int d);
};

Grafo::Grafo(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::addNo(int u, int v)
{
    adj[u].push_back(v);
}

void Grafo::printaCaminhos(int s, int d)
{

    bool *visited = new bool[V];

    int *path = new int[V];
    int path_index = 0;

    for (int i = 0; i < V; i++)
        visited[i] = false;

    printaCaminhosUtil(s, d, visited, path, path_index);
}

void Grafo::printaCaminhosUtil(int u, int d, bool visited[],
                               int path[], int &path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    if (u == d)
    {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printaCaminhosUtil(*i, d, visited, path, path_index);
    }

    path_index--;
    visited[u] = false;
}

int main()
{

    Grafo g(4);
    cout << "Seu grafo pode ser no maximo 20 nós\n";
    cout << "Agora, digite quantos caminhos deseja informar\n";
    int x;
    cin >> x;
    cout << "\nBeleza, agora digite as " + x << "ligações que seu grafo terá!\n";
    cout << "Digite 2 numeros e aparte enter. Se quiser que nó 1 se ligue com nó 2, digite '1 2'\n";
    while (x--)
    {
        int y, z;
        cin >> y >> z;
        g.addNo(y, z);
    }

    cout << "Agora, você que saber todos os caminhos possiveis de qual nó para qual nó?\n";
    int s, d;
    cin >> s >> d;

    cout << "Caminhos de  " << s
         << " para " << d << endl;
    g.printaCaminhos(s, d);

    return 0;
}