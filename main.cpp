#include <iostream>
#include <string>
#include <vector>

class Client {
private:
    std::string nume;
    int varsta;
public:
    Client(const std::string& nume, int varsta) : nume(nume), varsta(varsta) {}
    Client(const Client& other) : nume(other.nume), varsta(other.varsta) {}
    Client& operator=(const Client& other) {
        if (this != &other) {
            nume = other.nume;
            varsta = other.varsta;
        }
        return *this;
    }
    ~Client() {}

    friend std::ostream& operator<<(std::ostream& os, const Client& client) {
        os << "Client: " << client.nume << ", Varsta: " << client.varsta;
        return os;
    }

    std::string GetNume() const { return nume; }
};

class Abonament {
private:
    std::string tip;
    int durata; // în luni
public:
    Abonament(const std::string& tip, int durata) : tip(tip), durata(durata) {}
    Abonament(const Abonament& other) : tip(other.tip), durata(other.durata) {}
    Abonament& operator=(const Abonament& other) {
        if (this != &other) {
            tip = other.tip;
            durata = other.durata;
        }
        return *this;
    }
    ~Abonament() {}

    friend std::ostream& operator<<(std::ostream& os, const Abonament& abonament) {
        os << "Abonament: " << abonament.tip << ", Durata: " << abonament.durata << " luni";
        return os;
    }
};

class SalaFitness {
private:
    std::vector<Client> clienti;
public:
    SalaFitness() {}
    ~SalaFitness() {}

    void AdaugaClient(const Client& client) {
        clienti.push_back(client);
    }

    void AfiseazaClienti() const {
        for (const Client& client : clienti) {
            std::cout << client << std::endl;
        }
    }
};

int main() {
    Client client1("Andrei Mihai", 25);
    Client client2("Vlad Manea", 20);
    Client client3("Maria Gheorghe" , 18);
    Client client4("Teodora Cujbescu" , 32);
    Abonament abonament1("Basic", 6);
    Abonament abonament2("Premium", 12);
    Abonament abodament3("Basic",6);
    Abonament abonament4("Premium",12);

    SalaFitness sala;
    sala.AdaugaClient(client1);
    sala.AdaugaClient(client2);
    sala.AdaugaClient(client3);
    sala.AdaugaClient(client4);

    std::cout << "Clientii din sala de fitness:" << std::endl;
    sala.AfiseazaClienti();

    return 0;
}
