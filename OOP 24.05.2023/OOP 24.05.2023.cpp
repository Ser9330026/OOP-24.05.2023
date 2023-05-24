// OOP 24.05.2023.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

class Client {
private:
    std::string _name;
    int _age;
    double _bill;
public:
    Client(std::string name, int age, double bill) {
        _name = name;
        _age = age;
        _bill = bill;
    }

void ShowData() {
        std::cout << _name << '\n';
        std::cout << _age << '\n';
        std::cout << _bill << '\n';
     }
};


    class Bank {
    private:
        std::vector<Client*>_clients;
    public:
        void AddClient(Client* client) {
            _clients.push_back(client);
        }

        void ShowClients() {
            /*std::vector<Client*>::iterator it;
            for (it = _clients.begin(); it != _clients.end(); ++it)
                (*it)->ShowData();*/

            for (const auto& it : _clients)//Такой синтаксис работает быстрее
                it->ShowData();
        }

        void ShowClient(int index) {
            if (index > _clients.size())
                return;
            _clients.at(index - 1)->ShowData();
        }
    };

    

int main()
{
    Bank* bank = new Bank();
    Client* client1 = new Client("Bob", 20, 655450);
    Client* client2 = new Client("Alex", 25, 655455);
    Client* client3 = new Client("Null", 30, 44444);
    Client* client4 = new Client("DDD", 28, 5456);

    bank->AddClient(client1);
    bank->AddClient(client2);
    bank->AddClient(client3);
    bank->AddClient(client4);

    bank->ShowClients();
    bank->ShowClient(2);

    return 0;
}