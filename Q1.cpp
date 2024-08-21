#include <iostream>
#include <cmath> // para M_PI

// Classe base para figuras geométricas espaciais
class FiguraEspacial {
public:
    virtual double calcularArea() const = 0; // Função virtual pura para área
    virtual double calcularVolume() const = 0; // Função virtual pura para volume
    virtual ~FiguraEspacial() {}
};

// Classe derivada para o Cubo
class Cubo : public FiguraEspacial {
private:
    double aresta;
public:
    Cubo(double a) : aresta(a) {}
    double calcularArea() const override {
        return 6 * aresta * aresta;
    }
    double calcularVolume() const override {
        return aresta * aresta * aresta;
    }
};

// Classe derivada para a Esfera
class Esfera : public FiguraEspacial {
private:
    double raio;
public:
    Esfera(double r) : raio(r) {}
    double calcularArea() const override {
        return 4 * M_PI * raio * raio;
    }
    double calcularVolume() const override {
        return (4.0 / 3.0) * M_PI * raio * raio * raio;
    }
};

// Classe derivada para o Paralelepípedo
class Paralelepipedo : public FiguraEspacial {
private:
    double aresta1, aresta2, aresta3;
public:
    Paralelepipedo(double a1, double a2, double a3) : aresta1(a1), aresta2(a2), aresta3(a3) {}
    double calcularArea() const override {
        return 2 * (aresta1 * aresta2 + aresta1 * aresta3 + aresta2 * aresta3);
    }
    double calcularVolume() const override {
        return aresta1 * aresta2 * aresta3;
    }
};

// Classe derivada para a Pirâmide
class Piramide : public FiguraEspacial {
private:
    double base, altura;
public:
    Piramide(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        // Considerando que a altura lateral é fornecida na fórmula geral
        double area_base = base * base;
        double area_lateral = 4 * (base * altura / 2); // Supondo altura lateral como base
        return area_base + area_lateral;
    }
    double calcularVolume() const override {
        return (1.0 / 3.0) * base * base * altura;
    }
};

// Funções para exibir área e volume
void exibirArea(const FiguraEspacial* figura) {
    std::cout << "Área: " << figura->calcularArea() << std::endl;
}

void exibirVolume(const FiguraEspacial* figura) {
    std::cout << "Volume: " << figura->calcularVolume() << std::endl;
}

int main() {
    // Criação dos objetos
    Cubo cubo(3);
    Esfera esfera(5);
    Paralelepipedo paralelepipedo(2, 3, 4);
    Piramide piramide(4, 6);

    // Array de ponteiros para funções
    void (pFuncArea)(const FiguraEspacial) = exibirArea;
    void (pFuncVolume)(const FiguraEspacial) = exibirVolume;

    // Exibindo as áreas e volumes
    FiguraEspacial* figuras[4];
    figuras[0] = &cubo;
    figuras[1] = &esfera;
    figuras[2] = &paralelepipedo;
    figuras[3] = &piramide;

    for (int i = 0; i < 4; ++i) {
        pFuncArea(figuras[i]);
        pFuncVolume(figuras[i]);
        std::cout << std::endl;
    }

    return 0;
}