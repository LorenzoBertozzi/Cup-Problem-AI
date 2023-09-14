#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct Estado
{
    int qtdAgua_a;
    int qtdAgua_b;
    int qtdAgua_c;

    bool operator<(const Estado& other) const
    {
        if (qtdAgua_a != other.qtdAgua_a)
            return qtdAgua_a < other.qtdAgua_a;
        if (qtdAgua_b != other.qtdAgua_b)
            return qtdAgua_b < other.qtdAgua_b;
        return qtdAgua_c < other.qtdAgua_c;
    }

    bool operator==(const Estado& other) const
    {
        return qtdAgua_a == other.qtdAgua_a &&
               qtdAgua_b == other.qtdAgua_b &&
               qtdAgua_c == other.qtdAgua_c;
    }
};

bool isObjetivo(const Estado& estado)
{
    return (estado.qtdAgua_a == 4 && estado.qtdAgua_b == 4);
}

vector<Estado> GerarProxEstado(const Estado& atual)
{
    vector<Estado> proxEstados;

    // Pour water from jug a to jug b
    if (atual.qtdAgua_a > 0 && atual.qtdAgua_b < 5)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 5 - proxEstado.qtdAgua_b;

        if (proxEstado.qtdAgua_a <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_b += proxEstado.qtdAgua_a;
            proxEstado.qtdAgua_a = 0;
        }
        else
        {
            proxEstado.qtdAgua_b = 5;
            proxEstado.qtdAgua_a -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    // Pour water from jug b to jug a
    if (atual.qtdAgua_b > 0 && atual.qtdAgua_a < 8)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 8 - proxEstado.qtdAgua_a;

        if (proxEstado.qtdAgua_b <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_a += proxEstado.qtdAgua_b;
            proxEstado.qtdAgua_b = 0;
        }
        else
        {
            proxEstado.qtdAgua_a = 8;
            proxEstado.qtdAgua_b -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    // Pour water from jug a to jug c
    if (atual.qtdAgua_a > 0 && atual.qtdAgua_c < 3)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 3 - proxEstado.qtdAgua_c;

        if (proxEstado.qtdAgua_a <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_c += proxEstado.qtdAgua_a;
            proxEstado.qtdAgua_a = 0;
        }
        else
        {
            proxEstado.qtdAgua_c = 3;
            proxEstado.qtdAgua_a -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    // Pour water from jug c to jug a
    if (atual.qtdAgua_c > 0 && atual.qtdAgua_a < 8)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 8 - proxEstado.qtdAgua_a;

        if (proxEstado.qtdAgua_c <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_a += proxEstado.qtdAgua_c;
            proxEstado.qtdAgua_c = 0;
        }
        else
        {
            proxEstado.qtdAgua_a = 8;
            proxEstado.qtdAgua_c -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    // Pour water from jug b to jug c
    if (atual.qtdAgua_b > 0 && atual.qtdAgua_c < 3)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 3 - proxEstado.qtdAgua_c;

        if (proxEstado.qtdAgua_b <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_c += proxEstado.qtdAgua_b;
            proxEstado.qtdAgua_b = 0;
        }
        else
        {
            proxEstado.qtdAgua_c = 3;
            proxEstado.qtdAgua_b -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    // Pour water from jug c to jug b
    if (atual.qtdAgua_c > 0 && atual.qtdAgua_b < 5)
    {
        Estado proxEstado = atual;
        int capacidadeSobrando = 5 - proxEstado.qtdAgua_b;

        if (proxEstado.qtdAgua_c <= capacidadeSobrando)
        {
            proxEstado.qtdAgua_b += proxEstado.qtdAgua_c;
            proxEstado.qtdAgua_c = 0;
        }
        else
        {
            proxEstado.qtdAgua_b = 5;
            proxEstado.qtdAgua_c -= capacidadeSobrando;
        }
        proxEstados.push_back(proxEstado);
    }

    return proxEstados;
}

void BREADTH_FIRST_SEARCH()
{
    queue<Estado> filaEstados;
    map<Estado, Estado> EstadoAnterior;

    Estado estadoInicial = {8, 0, 0};
    filaEstados.push(estadoInicial);

    while (!filaEstados.empty())
    {
        Estado atual = filaEstados.front();
        filaEstados.pop();

        if (isObjetivo(atual))
        {
            cout << "Sequencia" << endl;
            vector<Estado> sequencia;

            while (!(atual == estadoInicial))
            {
                sequencia.push_back(atual);
                atual = EstadoAnterior[atual];
            }
            sequencia.push_back(estadoInicial);

            for (int i = sequencia.size() - 1; i >= 0; i--)
            {
                Estado aux = sequencia[i];
                cout << aux.qtdAgua_a << " " << aux.qtdAgua_b << " " << aux.qtdAgua_c << endl;
            }
            return;
        }

        vector<Estado> proxEstados = GerarProxEstado(atual);

        for (const auto& proxEstado : proxEstados)
        {
            if (EstadoAnterior.find(proxEstado) == EstadoAnterior.end())
            {
                EstadoAnterior[proxEstado] = atual;
                filaEstados.push(proxEstado);
            }
        }
    }

    cout << "Nao foi possivel resolver" << endl;
}

int main()
{
    BREADTH_FIRST_SEARCH();
    return 0;
}
