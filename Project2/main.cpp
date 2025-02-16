#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Library {
public:
    // Конструктор
    Library(string заголовок, string тема, vector<string> актори, double оцінка, double довжина, double швидкість_відтворення, string назва_файла, string дата) : заголовок_(заголовок), тема_(тема), актори_(актори), оцінка_(оцінка), довжина_(довжина), швидкість_відтворення_(швидкість_відтворення), назва_файла_(назва_файла), дата_(дата) {}

    // Методи доступу до даних
    string отримати_заголовок() const { return заголовок_; }
    string отримати_тему() const { return тема_; }
    vector<string> отримати_акторів() const { return актори_; }
    double отримати_оцінку() const { return оцінка_; }
    double отримати_довжину() const { return довжина_; }
    double отримати_швидкість_відтворення() const { return швидкість_відтворення_; }
    string отримати_назву_файла() const { return назва_файла_; }
    string отримати_дату() const { return дата_; }

    // Деструктор (необов'язковий)
    ~Library() {}

private:
    string заголовок_;
    string тема_;
    vector < string> актори_;
    double оцінка_;
    double довжина_;
    double швидкість_відтворення_;
    string назва_файла_;
    string дата_;
};

class ПРОГРАВАЧ {
public:
    // Конструктор
    ПРОГРАВАЧ() {}

    // Метод для додавання фільму до бібліотеки мультимедіа
    void додати_фільм(Library фільм)
    {
        бібліотека_.push_back(фільм);
    }

    // Метод для пошуку фільмів за акторами
    vector<Library> пошук_за_акторами(string актор)
    {
        vector<Library> результат;
        for (const Library& фільм : бібліотека_)
        {
            vector<string> актори = фільм.отримати_акторів();
            if (find(актори.begin(), актори.end(), актор) != актори.end())
            {
                результат.push_back(фільм);
            }
        }
        return результат;
    }

    // Метод для пошуку фільмів за назвою
    vector<Library> пошук_за_назвою(string назва)
    {
        vector<Library> результат;
        for (const Library& фільм : бібліотека_)
        {
            if (фільм.отримати_заголовок() == назва)
            {
                результат.push_back(фільм);
            }
        }
        return результат;
    }

    // Метод для пошуку фільмів за темою
    vector<Library> пошук_за_темою(string тема)
    {
        vector<Library> результат;
        for (const Library& фільм : бібліотека_)
        {
            if (фільм.отримати_тему() == тема)
            {
                результат.push_back(фільм);
            }
        }
        return результат;
    }

private:
    vector<Library> бібліотека_;
};

int main() {
    setlocale(LC_ALL, "ukr");
    ПРОГРАВАЧ плеєр;

    // Додати фільми до бібліотеки
    Library фільм1("Фільм 1", "Комедія", { "Актор1", "Актор2" }, 8.0, 120, 1.0, "фільм1.mp4", "2023-09-19");
    Library фільм2("Фільм 2", "Жахи", { "Актор3", "Актор4" }, 7.5, 150, 1.2, "фільм2.mp4", "2023-09-20");
    плеєр.додати_фільм(фільм1);
    плеєр.додати_фільм(фільм2);

    int choice;
    while (true) {
        cout << "Меню пошуку:" << endl;
        cout << "1. Пошук за акторами" << endl;
        cout << "2. Пошук за назвою" << endl;
        cout << "3. Пошук за темою" << endl;
        cout << "4. Вийти з програми" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string actor;
            cout << "Введіть ім'я актора: ";
            cin >> actor;
            vector<Library> фільми_за_актором = плеєр.пошук_за_акторами(actor);
            cout << "Фільми за актором '" << actor << "':" << endl;
            for (const Library& фільм : фільми_за_актором) {
                cout << "Заголовок: " << фільм.отримати_заголовок() << endl;
            }
            break;
        }
        case 2: {
            string title;
            cout << "Введіть назву фільму: ";
            cin.ignore();
            getline(cin, title);
            vector<Library> фільми_за_назвою = плеєр.пошук_за_назвою(title);
            cout << "Фільми за назвою '" << title << "':" << endl;
            for (const Library& фільм : фільми_за_назвою) {
                cout << "Заголовок: " << фільм.отримати_заголовок() << endl;
            }
            break;
        }
        case 3: {
            string theme;
            cout << "Введіть тему фільму: ";
            cin.ignore();
            getline(cin, theme);
            vector<Library> фільми_за_темою = плеєр.пошук_за_темою(theme);
            cout << "Фільми за темою '" << theme << "':" << endl;
            for (const Library& фільм : фільми_за_темою) {
                cout << "Заголовок: " << фільм.отримати_заголовок() << endl;
            }
            break;
        }
        case 4:
            cout << "Вихід з програми." << endl;
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }
    }

    return 0;
}
