// OOP-Lab12-Prodan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

enum class TipContact {
    Prieten,
    Cunoscut,
    Coleg
};

class Contact {
protected:
    std::string nume;

public:
    Contact(const std::string& nume) : nume(nume) {}
    virtual ~Contact() {}

    std::string getNume() const {
        return nume;
    }

    virtual TipContact getTipContact() const = 0;
};

class Prieten : public Contact {
private:
    std::string dataNastere;
    std::string numarTelefon;
    std::string adresa;

public:
    Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa)
        : Contact(nume), dataNastere(dataNastere), numarTelefon(numarTelefon), adresa(adresa) {}

    TipContact getTipContact() const override {
        return TipContact::Prieten;
    }

    std::string getDataNastere() const {
        return dataNastere;
    }

    std::string getNumarTelefon() const {
        return numarTelefon;
    }

    std::string getAdresa() const {
        return adresa;
    }
};

class Cunoscut : public Contact {
private:
    std::string numarTelefon;

public:
    Cunoscut(const std::string& nume, const std::string& numarTelefon)
        : Contact(nume), numarTelefon(numarTelefon) {}

    TipContact getTipContact() const override {
        return TipContact::Cunoscut;
    }

    std::string getNumarTelefon() const {
        return numarTelefon;
    }
};

class Coleg : public Contact {
private:
    std::string numarTelefon;
    std::string firma;
    std::string adresa;

public:
    Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa)
        : Contact(nume), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {}

    TipContact getTipContact() const override {
        return TipContact::Coleg;
    }

    std::string getNumarTelefon() const {
        return numarTelefon;
    }

    std::string getFirma() const {
        return firma;
    }

    std::string getAdresa() const {
        return adresa;
    }
};

class Agenda {
private:
    std::vector<Contact*> contacte;

public:
    Contact* cautaContact(const std::string& nume) {
        for (Contact* contact : contacte) {
            if (contact->getNume() == nume) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Prieten*> listaPrieteni() {
        std::vector<Prieten*> prieteni;
        for (Contact* contact : contacte) {
            if (contact->getTipContact() == TipContact::Prieten) {
                prieteni.push_back(static_cast<Prieten*>(contact));
            }
        }
        return prieteni;
    }

    void stergeContact(const std::string& nume) {
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->getNume() == nume) {
                delete* it;
                contacte.erase(it);
                break;
            }
        }
    }

    void adaugaContact(Contact* contact) {
        contacte.push_back(contact);
    }

    ~Agenda() {
        for (Contact* contact : contacte) {
            delete contact;
        }
    }
};

int main() {
    Agenda agenda;

    std::cout << "Agenda telefonica\n\n";

    while (true) {
        std::cout << "Meniu:\n";
        std::cout << "1. Adauga contact\n";
        std::cout << "2. Cauta contact\n";
        std::cout << "3. Afiseaza lista de prieteni\n";
        std::cout << "4. Sterge contact\n";
        std::cout << "0. Iesire\n";

        int optiune;
        std::cout << "\nSelecteaza o optiune: ";
        std::cin >> optiune;

        if (optiune == 0) {
            break;
        }

        switch (optiune) {
        case 1: {
            system("CLS");
            std::cout << "\nAdauga contact:\n";
            std::cout << "Tip de contact (1 - Prieten, 2 - Cunoscut, 3 - Coleg): ";
            int tipContact;
            std::cin >> tipContact;

            std::string nume, dataNastere, numarTelefon, adresa, firma;
            switch (tipContact) {
            case 1: {
                system("CLS");
                std::cout << "Nume: ";
                std::cin.ignore();
                std::getline(std::cin, nume);
                std::cout << "Data nastere: ";
                std::getline(std::cin, dataNastere);
                std::cout << "Numar telefon: ";
                std::getline(std::cin, numarTelefon);
                std::cout << "Adresa: ";
                std::getline(std::cin, adresa);
                agenda.adaugaContact(new Prieten(nume, dataNastere, numarTelefon, adresa));
                break;
            }
            case 2: {
                system("CLS");
                std::cout << "Nume: ";
                std::cin.ignore();
                std::getline(std::cin, nume);
                std::cout << "Numar telefon: ";
                std::getline(std::cin, numarTelefon);
                agenda.adaugaContact(new Cunoscut(nume, numarTelefon));
                break;
            }
            case 3: {
                system("CLS");
                std::cout << "Nume: ";
                std::cin.ignore();
                std::getline(std::cin, nume);
                std::cout << "Numar telefon: ";
                std::getline(std::cin, numarTelefon);
                std::cout << "Firma: ";
                std::getline(std::cin, firma);
                std::cout << "Adresa: ";
                std::getline(std::cin, adresa);
                agenda.adaugaContact(new Coleg(nume, numarTelefon, firma, adresa));
                break;
            }
            default:
                system("CLS");
                std::cout << "Optiune invalida.\n";
            }
            std::cout << "\nContactul a fost adaugat.\n\n";
            break;
        }
        case 2: {
            system("CLS");
            std::cout << "\nCauta contact:\n";
            std::string nume;
            std::cout << "Nume: ";
            std::cin.ignore();
            std::getline(std::cin, nume);
            Contact* contact = agenda.cautaContact(nume);
            if (contact) {
                std::cout << "Contactul a fost gasit:\n";
                std::cout << "Nume: " << contact->getNume() << std::endl;
                switch (contact->getTipContact()) {
                case TipContact::Prieten: {
                    Prieten* prieten = static_cast<Prieten*>(contact);
                    std::cout << "Data nastere: " << prieten->getDataNastere() << std::endl;
                    std::cout << "Numar telefon: " << prieten->getNumarTelefon() << std::endl;
                    std::cout << "Adresa: " << prieten->getAdresa() << std::endl;
                    break;
                }
                case TipContact::Cunoscut: {
                    Cunoscut* cunoscut = static_cast<Cunoscut*>(contact);
                    std::cout << "Numar telefon: " << cunoscut->getNumarTelefon() << std::endl;
                    break;
                }
                case TipContact::Coleg: {
                    Coleg* coleg = static_cast<Coleg*>(contact);
                    std::cout << "Numar telefon: " << coleg->getNumarTelefon() << std::endl;
                    std::cout << "Firma: " << coleg->getFirma() << std::endl;
                    std::cout << "Adresa: " << coleg->getAdresa() << std::endl;
                    break;
                }
                }
            }
            else {
                std::cout << "Contactul nu a fost gasit.\n";
            }
            std::cout << std::endl;
            break;
        }
        case 3: {
            system("CLS");
            std::cout << "\nLista de prieteni:\n";
            std::vector<Prieten*> prieteni = agenda.listaPrieteni();
            for (Prieten* prieten : prieteni) {
                std::cout << "- Nume: " << prieten->getNume() << std::endl;
                std::cout << "  Data nastere: " << prieten->getDataNastere() << std::endl;
                std::cout << "  Numar telefon: " << prieten->getNumarTelefon() << std::endl;
                std::cout << "  Adresa: " << prieten->getAdresa() << std::endl;
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
            system("CLS");
            std::cout << "\nSterge contact:\n";
            std::string nume;
            std::cout << "Nume: ";
            std::cin.ignore();
            std::getline(std::cin, nume);
            agenda.stergeContact(nume);
            std::cout << "Contactul a fost sters.\n\n";
            break;
        }
        default:
            std::cout << "Optiune invalida.\n\n";
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
