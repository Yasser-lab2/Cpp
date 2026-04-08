#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    int  m_length;
    char* m_ptr;

public:

    // Constructeur par defaut
    MyString() {
        m_length = 0;
        m_ptr    = new char[1];
        m_ptr[0] = '\0';
    }

    // Constructeur II - a partir d'une chaine
    MyString(const char* c) {
        m_length = strlen(c);
        m_ptr    = new char[m_length + 1];
        strcpy(m_ptr, c);
    }

    // Constructeur de recopie
    MyString(const MyString& s) {
        m_length = s.m_length;
        m_ptr    = new char[m_length + 1];
        strcpy(m_ptr, s.m_ptr);
    }

    // Destructeur
    ~MyString() {
        delete[] m_ptr;
    }

    // GetLength
    int GetLength() const {
        return m_length;
    }

    // Print
    void Print() const {
        cout << m_ptr << endl;
    }

    // operator= (affectation)
    MyString& operator=(const MyString& s) {
        if (this == &s) return *this;   // auto-affectation
        delete[] m_ptr;
        m_length = s.m_length;
        m_ptr    = new char[m_length + 1];
        strcpy(m_ptr, s.m_ptr);
        return *this;
    }

    // operator== (egalite)
    int operator==(MyString& s) {
        return strcmp(m_ptr, s.m_ptr) == 0;
    }

    // operator+ (concatenation)
    MyString operator+(const MyString& s) {
        MyString result;
        result.m_length = m_length + s.m_length;
        delete[] result.m_ptr;
        result.m_ptr = new char[result.m_length + 1];
        strcpy(result.m_ptr, m_ptr);
        strcat(result.m_ptr, s.m_ptr);
        return result;
    }

    // operator[] (acces a un caractere)
    char& operator[](int n) {
        return m_ptr[n];
    }

    // soustraire - supprime la premiere occurrence d'un caractere
    void soustraire(char c) {
        int pos = -1;
        for (int i = 0; i < m_length; i++) {
            if (m_ptr[i] == c) { pos = i; break; }
        }
        if (pos == -1) return;

        char* nouveau = new char[m_length];   // m_length - 1 + 1
        for (int i = 0, j = 0; i < m_length; i++)
            if (i != pos) nouveau[j++] = m_ptr[i];
        nouveau[m_length - 1] = '\0';

        delete[] m_ptr;
        m_ptr = nouveau;
        m_length--;
    }

    // positionner - compare longueurs : 1 si this>s, 0 si egal, -1 si this<s
    int positionner(const MyString& s) const {
        if (m_length > s.m_length) return  1;
        if (m_length < s.m_length) return -1;
        return 0;
    }
};


int main() {
    // Constructeurs
    MyString s1("Bonjour");
    MyString s2(" Monde");
    MyString s3(s1);          // constructeur de recopie

    cout << "s1 = "; s1.Print();
    cout << "s2 = "; s2.Print();
    cout << "s3 = "; s3.Print();

    // operator+
    MyString s4 = s1 + s2;
    cout << "s1 + s2 = "; s4.Print();

    // operator==
    cout << "s1 == s3 ? " << (s1 == s3 ? "oui" : "non") << endl;
    cout << "s1 == s2 ? " << (s1 == s2 ? "oui" : "non") << endl;

    // operator[]
    cout << "s1[0] = " << s1[0] << endl;
    s1[0] = 'b';
    cout << "s1 apres s1[0]='b' : "; s1.Print();

    // operator=
    MyString s5;
    s5 = s2;
    cout << "s5 = s2 : "; s5.Print();

    // soustraire
    MyString s6("Bonjour");
    s6.soustraire('o');
    cout << "Bonjour - 'o' = "; s6.Print();

    // positionner
    MyString A("chat");
    MyString B("éléphant");
    int res = A.positionner(B);
    if      (res ==  1) cout << "A plus long que B"  << endl;
    else if (res == -1) cout << "A plus court que B" << endl;
    else                cout << "A et B meme longueur" << endl;

    return 0;
}