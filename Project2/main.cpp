#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Library {
public:
    // �����������
    Library(string ���������, string ����, vector<string> ������, double ������, double �������, double ��������_����������, string �����_�����, string ����) : ���������_(���������), ����_(����), ������_(������), ������_(������), �������_(�������), ��������_����������_(��������_����������), �����_�����_(�����_�����), ����_(����) {}

    // ������ ������� �� �����
    string ��������_���������() const { return ���������_; }
    string ��������_����() const { return ����_; }
    vector<string> ��������_������() const { return ������_; }
    double ��������_������() const { return ������_; }
    double ��������_�������() const { return �������_; }
    double ��������_��������_����������() const { return ��������_����������_; }
    string ��������_�����_�����() const { return �����_�����_; }
    string ��������_����() const { return ����_; }

    // ���������� (������'�������)
    ~Library() {}

private:
    string ���������_;
    string ����_;
    vector < string> ������_;
    double ������_;
    double �������_;
    double ��������_����������_;
    string �����_�����_;
    string ����_;
};

class ��������� {
public:
    // �����������
    ���������() {}

    // ����� ��� ��������� ������ �� �������� ����������
    void ������_�����(Library �����)
    {
        ��������_.push_back(�����);
    }

    // ����� ��� ������ ������ �� ��������
    vector<Library> �����_��_��������(string �����)
    {
        vector<Library> ���������;
        for (const Library& ����� : ��������_)
        {
            vector<string> ������ = �����.��������_������();
            if (find(������.begin(), ������.end(), �����) != ������.end())
            {
                ���������.push_back(�����);
            }
        }
        return ���������;
    }

    // ����� ��� ������ ������ �� ������
    vector<Library> �����_��_������(string �����)
    {
        vector<Library> ���������;
        for (const Library& ����� : ��������_)
        {
            if (�����.��������_���������() == �����)
            {
                ���������.push_back(�����);
            }
        }
        return ���������;
    }

    // ����� ��� ������ ������ �� �����
    vector<Library> �����_��_�����(string ����)
    {
        vector<Library> ���������;
        for (const Library& ����� : ��������_)
        {
            if (�����.��������_����() == ����)
            {
                ���������.push_back(�����);
            }
        }
        return ���������;
    }

private:
    vector<Library> ��������_;
};

int main() {
    setlocale(LC_ALL, "ukr");
    ��������� ����;

    // ������ ������ �� ��������
    Library �����1("Գ��� 1", "������", { "�����1", "�����2" }, 8.0, 120, 1.0, "�����1.mp4", "2023-09-19");
    Library �����2("Գ��� 2", "����", { "�����3", "�����4" }, 7.5, 150, 1.2, "�����2.mp4", "2023-09-20");
    ����.������_�����(�����1);
    ����.������_�����(�����2);

    int choice;
    while (true) {
        cout << "���� ������:" << endl;
        cout << "1. ����� �� ��������" << endl;
        cout << "2. ����� �� ������" << endl;
        cout << "3. ����� �� �����" << endl;
        cout << "4. ����� � ��������" << endl;
        cout << "������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string actor;
            cout << "������ ��'� ������: ";
            cin >> actor;
            vector<Library> ������_��_������� = ����.�����_��_��������(actor);
            cout << "Գ���� �� ������� '" << actor << "':" << endl;
            for (const Library& ����� : ������_��_�������) {
                cout << "���������: " << �����.��������_���������() << endl;
            }
            break;
        }
        case 2: {
            string title;
            cout << "������ ����� ������: ";
            cin.ignore();
            getline(cin, title);
            vector<Library> ������_��_������ = ����.�����_��_������(title);
            cout << "Գ���� �� ������ '" << title << "':" << endl;
            for (const Library& ����� : ������_��_������) {
                cout << "���������: " << �����.��������_���������() << endl;
            }
            break;
        }
        case 3: {
            string theme;
            cout << "������ ���� ������: ";
            cin.ignore();
            getline(cin, theme);
            vector<Library> ������_��_����� = ����.�����_��_�����(theme);
            cout << "Գ���� �� ����� '" << theme << "':" << endl;
            for (const Library& ����� : ������_��_�����) {
                cout << "���������: " << �����.��������_���������() << endl;
            }
            break;
        }
        case 4:
            cout << "����� � ��������." << endl;
            return 0;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
            break;
        }
    }

    return 0;
}
