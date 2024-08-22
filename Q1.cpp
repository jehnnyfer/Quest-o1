#include <iostream>
#include <cmath>
#include <iomanip> 

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
    std::cout << "Área: " << std::fixed << std::setprecision(2) << figura->calcularArea() << std::endl;
}

void exibirVolume(const FiguraEspacial* figura) {
    std::cout << "Volume: " << std::fixed << std::setprecision(2) << figura->calcularVolume() << std::endl;
}

int main() {
    while (true) {
        std::cout << "Escolha uma figura geométrica para calcular:\n";
        std::cout << "1. Cubo\n";
        std::cout << "2. Esfera\n";
        std::cout << "3. Paralelepípedo\n";
        std::cout << "4. Pirâmide\n";
        std::cout << "5. Sair\n";
        std::cout << "Opção: ";
        int opcao;
        std::cin >> opcao;

        if (opcao == 5) {
            break;
        }

        FiguraEspacial* figura = nullptr;

        switch (opcao) {
            case 1: {
                double aresta;
                std::cout << "Digite o comprimento da aresta do cubo: ";
                std::cin >> aresta;
                figura = new Cubo(aresta);
                break;
            }
            case 2: {
                double raio;
                std::cout << "Digite o raio da esfera: ";
                std::cin >> raio;
                figura = new Esfera(raio);
                break;
            }
            case 3: {
                double aresta1, aresta2, aresta3;
                std::cout << "Digite o comprimento da primeira aresta do paralelepípedo: ";
                std::cin >> aresta1;
                std::cout << "Digite o comprimento da segunda aresta do paralelepípedo: ";
                std::cin >> aresta2;
                std::cout << "Digite o comprimento da terceira aresta do paralelepípedo: ";
                std::cin >> aresta3;
                figura = new Paralelepipedo(aresta1, aresta2, aresta3);
                break;
            }
            case 4: {
                double base, altura;
                std::cout << "Digite o comprimento da base da pirâmide: ";
                std::cin >> base;
                std::cout << "Digite a altura da pirâmide: ";
                std::cin >> altura;
                figura = new Piramide(base, altura);
                break;
            }
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                continue;
        }

        if (figura != nullptr) {
            exibirArea(figura);
            exibirVolume(figura);
            delete figura; // Libera a memória alocada
        }

        std::cout << std::endl;
    }

    return 0;
}

