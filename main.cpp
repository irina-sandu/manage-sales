#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#pragma warning(disable : 4996)

using namespace std;
int val = 0;
class Produs
{
    const int id;
    string denumire;
    float pret;
public:
    Produs() : id(val) {
        this->pret = 0;
    }
    Produs(string denumire, float pret) : id(val)
    {
        val++;
        this->denumire = denumire;
        this->pret = pret;
    }
    Produs(const Produs& obj) : id(obj.id)
    {
        this->pret = obj.pret;
        this->denumire = obj.denumire;
    }
    ~Produs() {
        cout << endl << "Destructor";
    }
    float get_pret() {
        return pret;
    }
    string get_denumire()
    {
        return this->denumire;
    }
    void set_denumire(string newDenumire) {
        denumire = newDenumire;
    }
    void set_pret(float newPret) {
        if (newPret > 0) { pret = newPret; }
    }
    void printID() {
        cout << "This is:" << this << endl;
        cout << "Id:" << this->id << endl;
    }
    void printDenumire() {
        cout << "Denumire:" << denumire << endl;
    }
    Produs& operator=(const Produs& obj) {
        this->pret = obj.pret;
        this->denumire = obj.denumire;
        return *this;
    }
    friend istream& operator>>(istream& input, Produs& produs);
};
istream& operator>>(istream& input, Produs& produs)
{
    cout << "Introduceti datele pentru produs in urmatoarea ordine: denumire, pret:\n";
    input >> produs.denumire >> produs.pret;
    return input;
}
class Haine : public Produs
{
    string culoare;
    string sezon;
public:
    static string categorie;
    Haine()
    {
    }
    Haine(string denumire, float pret, string culoare, string sezon) : Produs(denumire, pret)
    {

        this->culoare = culoare;
        this->sezon = sezon;
    }
    Haine(const Haine& obj)
    {
        this->culoare = obj.culoare;
        this->sezon = obj.sezon;
    }
    ~Haine()
    {
    }
    string get_culoare() {
        return culoare;
    }
    void set_culoare(string newCuloare) {
        culoare = newCuloare;
    }

    string get_sezon() {
        return sezon;
    }
    void set_sezon(string newSezon) {
        sezon = newSezon;
    }
    friend istream& operator>>(istream& input, Haine& haine);
};
string Haine::categorie = "haine";
istream& operator>>(istream& input, Haine& haine)
{
    cout << "Introduceti datele pentru haina in urmatoarea ordine: denumire, pret,culoare, sezon: \n";
    string denumire; 
    int pret;
    input >> denumire >>pret>> haine.culoare >> haine.sezon;
    haine.set_denumire(denumire);
    haine.set_pret(pret);
    return input;
}
class Haine_femei : public Haine
{
    int marime;
public:
    Haine_femei()
    {
        this->marime = 0;
    }
    Haine_femei(string denumire, float pret, string culoare, string sezon, int marime) : Haine(denumire, pret, culoare, sezon)
    {

        this->marime = marime;
    }
    Haine_femei(const Haine_femei& obj)
    {
        this->marime = obj.marime;
    }
    ~Haine_femei()
    {
    }
    int get_marime() {
        return marime;
    }
    void set_marime(int newMarime) {
        if (newMarime > 0 and newMarime < 61) { marime = newMarime; }
    }
    friend istream& operator>>(istream& input, Haine_femei& haine_fem);
};
istream& operator>>(istream& input, Haine_femei& haine_fem)
{
    cout << "Introduceti datele pentru haina_femei in urmatoarea ordine: denumire, pret, culoare, sezon, marime\n";
    string denumire;
    int pret;
    string culoare;
    string sezon;
    input >> denumire >> pret >> culoare >> sezon >> haine_fem.marime;
    haine_fem.set_denumire(denumire);
    haine_fem.set_pret(pret);
    haine_fem.set_culoare(culoare);
    haine_fem.set_sezon(sezon);
    return input;
}
class Accesorii : public Produs
{
    string material;

public:
    static string categorie;
    Accesorii()
    {
    }
    Accesorii(string denumire, float pret, string material) : Produs(denumire, pret)
    {
        this->material = material;

    }
    Accesorii(const Accesorii& obj)
    {
        this->material = obj.material;
    }
    ~Accesorii()
    {
    }
    string get_material() {
        return material;
    }
    void set_material(string newMaterial) {
        material = newMaterial;
    }
    friend istream& operator>>(istream& input, Accesorii& accesorii);
};
string Accesorii::categorie = "accesorii";
istream& operator>>(istream& input, Accesorii& accesorii)
{
    cout << "Introduceti datele pentru accesoriu in urmatoarea ordine: denumire, pret, material\n";
    string denumire;
    int pret;
    input >> denumire >> pret >> accesorii.material;
    accesorii.set_denumire(denumire);
    accesorii.set_pret(pret);
    return input;
}
class Bijuterii : public Accesorii
{
    string tip_pietre;
public:
    Bijuterii()
    {
    }
    Bijuterii(string denumire, float pret, string material, string tip_pietre) : Accesorii(denumire, pret, material)
    {
        this->tip_pietre = tip_pietre;
    }
    Bijuterii(const Bijuterii& obj)
    {
        this->tip_pietre = obj.tip_pietre;
    }
    ~Bijuterii()
    {
    }
    string get_tip_pietre() {
        return tip_pietre;
    }
    void set_tip_pietre(string newTip_pietre) {
        tip_pietre = newTip_pietre;
    }
    friend istream& operator>>(istream& input, Bijuterii& bijuterii);
};
istream& operator>>(istream& input, Bijuterii& bijuterii)
{
    cout << "Introduceti datele pentru bijuterie in urmatoarea ordine: denumire, pret, material, tip_pietre\n";
    string denumire;
    int pret;
    string material;
    input >> denumire >> pret >> material >> bijuterii.tip_pietre;
    bijuterii.set_denumire(denumire);
    bijuterii.set_pret(pret);
    bijuterii.set_material(material);

    return input;

}
class Curele : public Accesorii
{
    string marime;
public:
    Curele()
    {
    }
    Curele(string denumire, float pret, string material, string marime) : Accesorii(denumire, pret, material)
    {
        this->marime = marime;
    }
    Curele(const Curele& obj)
    {
        this->marime = obj.marime;
    }
    ~Curele()
    {
    }
    string get_marime() {
        return marime;
    }
    void set_marime(string newmarime) {
        marime = newmarime;
    }
    friend istream& operator>>(istream& input, Curele& curele);
};
istream& operator>>(istream& input, Curele& curele)
{
    cout << "Introduceti datele pentru curea in urmatoarea ordine: denumire, pret, material, marime\n";
    string denumire;
    int pret;
    string material;
    input >> denumire >> pret >> material >> curele.marime;
    curele.set_denumire(denumire);
    curele.set_pret(pret);
    curele.set_material(material);
    return input;
}
struct date {
    int zi;
    int luna;
    int an;
};
class Comanda
{
    Produs** lista_produse;
    int nrproduse;
    date data_comanda;
public:
    Comanda()
    {
        this->lista_produse = NULL;
        nrproduse = 0;
        this->data_comanda.zi = 0;
        this->data_comanda.luna = 0;
        this->data_comanda.an = 0;
    }
    Comanda(Produs** lista_produse, int nrproduse,date data_comanda)
    {
        this->nrproduse = nrproduse;
        this->lista_produse = new Produs * [nrproduse];
        for (int i = 0; i < nrproduse; i++)
            this->lista_produse[i] = lista_produse[i];
        this->data_comanda = data_comanda;
    }
    ~Comanda()
    {
        if (this->lista_produse != NULL)
            delete[] this->lista_produse;
        delete[] this->lista_produse;
    }
    Produs** get_lista_produse()
    {
        return lista_produse;
    }
    int get_nrproduse() {
        return nrproduse;
    }

    void set_nrproduse(int newNrProduse) {
        if (newNrProduse > 0) nrproduse = newNrProduse;
    }
    int get_data_zi() {
        return data_comanda.zi;
    }
    int get_data_luna() {
        return data_comanda.luna;
    }
    int get_data_an() {
        return data_comanda.an;
    }
    void set_data_comanda(date newData_comanda) {
        data_comanda = newData_comanda;
    }
    void set_data_zi(int zi) {
        data_comanda.zi = zi;
    }
    void set_data_luna(int luna) {
        data_comanda.luna = luna;
    }
    void set_data_an(int an) {
        data_comanda.an = an;
    }
    friend ostream& operator<<(ostream& output, Comanda*comanda);
    friend void introdu_vanzari(Comanda* comanda);
    friend float total_ch_data(int nr,Comanda** comenzi,date data);
    friend float total_lunar(int nr, Comanda** comenzi, int luna);
    friend float total_anual(int nr, Comanda** comenzi, int an);
    friend float total_categorie(int nr, Comanda** comenzi, string categorie_dorita);
};
void introdu_vanzari(Comanda* comanda)
{   
    ifstream fin;
    ofstream fout;
    fin.open("fisier.txt");
    fout.open("fisier.txt", ios::app);

    int nr = comanda->get_nrproduse();
    for (int i = 0; i < nr; i++)
    {
        fout << comanda->get_lista_produse()[i]->get_denumire()<< " " << comanda->get_lista_produse()[i]->get_pret()<< "\n";
    }
    fout << comanda->get_data_zi() << "." << comanda->get_data_luna() << "." << comanda->get_data_an() << "\n\n";

    fin.close();
    fout.close();
}
float total_ch_data(int nr,Comanda** comenzi,date data)
{
    float S = 0;
    for (int i = 0; i < nr; i++)
    {
        if ((data.zi == comenzi[i]->get_data_zi()) && (data.luna == comenzi[i]->get_data_luna()) && (data.an == comenzi[i]->get_data_an()))
        {
            int nr = comenzi[i]->get_nrproduse();
            for (int j = 0; j < nr; j++)
            {
                S += comenzi[i]->get_lista_produse()[j]->get_pret();
            }
        }
    }
    return S;
}
float total_lunar(int nr, Comanda** comenzi, int luna)
{
    float S = 0;
    for (int i = 0; i < nr; i++)
    {
        if ((luna == comenzi[i]->get_data_luna()))
        {
            int nr = comenzi[i]->get_nrproduse();
            for (int j = 0; j < nr; j++)
            {
                S += comenzi[i]->get_lista_produse()[j]->get_pret();
            }
        }
    }
    return S;
}
float total_anual(int nr, Comanda** comenzi, int an)
{
    float S = 0;
    for (int i = 0; i < nr; i++)
    {
        if ((an == comenzi[i]->get_data_an()))
        {
            int nr = comenzi[i]->get_nrproduse();
            for (int j = 0; j < nr; j++)
            {
                S += comenzi[i]->get_lista_produse()[j]->get_pret();
            }
        }
    }
    return S;
}
ostream& operator<<(ostream& output, Comanda* cos)
{
    if (cos->get_nrproduse() != 0)
    {
        for (int i = 0; i < cos->get_nrproduse(); i++)
        {
            output << "Produs: " << cos->get_lista_produse()[i]->get_denumire() << "Pret:" << cos->get_lista_produse()[i]->get_pret() << endl;
        }
    }
    return output;
}

int main()
{
    // COMANDA 1
    int nr_produse1;
    cout << "Introduceti nr. produse pt prima comanda:\n"; cin >> nr_produse1;
    Haine_femei* h1 = new Haine_femei();
    cin >> *h1;
    Accesorii* a1 = new Accesorii();
    cin >> *a1;
    Curele* c1 = new Curele();
    cin >> *c1;
    Produs** l1 = new Produs * [nr_produse1];
    l1[0] = h1;
    l1[1] = a1;
    l1[2] = c1; 
    date data1;
    cout << "Introduceti data:\n-zi:"; cin >> data1.zi;
    cout << "-luna:"; cin >> data1.luna;
    cout << "-an:"; cin >> data1.an;
    Comanda* comanda1 = new Comanda(l1, nr_produse1,data1);

    //COMANDA 2
    int nr_produse2;
    cout << "Introduceti nr. produse pt comanda 2:\n"; cin >> nr_produse2; 
    Haine* h2 = new Haine();
    cin >> *h2;
    Haine_femei* f2 = new Haine_femei();
    cin >> *f2;
    Produs** l2 = new Produs * [nr_produse2]; 
    l2[0] = h2;
    l2[1] = f2;
    date data2;
    cout << "Introduceti data:\n-zi:"; cin >> data2.zi;
    cout << "-luna:"; cin >> data2.luna;
    cout << "-an:"; cin >> data2.an;
    Comanda* comanda2 = new Comanda(l2, nr_produse2,data2);

    //COMANDA 3
    int nr_produse3;
    cout << "Introduceti nr. produse pt comanda 3:\n"; cin >> nr_produse3;
    Bijuterii* b3 = new Bijuterii();
    cin >> *b3;
    Haine_femei* f3 = new Haine_femei();
    cin >> *f3;
    Produs** l3 = new Produs * [nr_produse3];
    l3[0] = b3;
    l3[1] = f3;
    date data3;
    cout << "Introduceti data:\n-zi:"; cin >> data3.zi;
    cout << "-luna:"; cin >> data3.luna;
    cout << "-an:"; cin >> data3.an;
    Comanda * comanda3 = new Comanda(l3, nr_produse3,data3);

    //COMANDA 4
    int nr_produse4;
    cout << "Introduceti nr. produse pt comanda 4:\n"; cin >> nr_produse4;
    Curele* c4 = new Curele();
    cin >> *c4;
    Haine* h4 = new Haine();
    cin >> *h4;
    Bijuterii* b4 = new Bijuterii();
    cin >> *b4;
    Produs** l4 = new Produs * [nr_produse4];
    l4[0] = c4;
    l4[1] = h4;
    l4[2] = b4;
    date data4;
    cout << "Introduceti data:\n-zi:"; cin >> data4.zi;
    cout << "-luna:"; cin >> data4.luna;
    cout << "-an:"; cin >> data4.an;
    Comanda* comanda4 = new Comanda(l4, nr_produse4, data4);
    introdu_vanzari(comanda1);
    introdu_vanzari(comanda2);
    introdu_vanzari(comanda3);
    introdu_vanzari(comanda4);

    int nr_comenzi = 4;
    Comanda** comenzi = new Comanda *[nr_comenzi];
    comenzi[0] = comanda1;
    comenzi[1] = comanda2;
    comenzi[2] = comanda3;
    comenzi[3] = comanda4;
  
    date data5;
    cout << "\ntotal vanzari pt o anumita data:\nintroduceti data:\n-zi:"; cin >> data5.zi;
    cout << "-luna:"; cin >> data5.luna;
    cout << "-an:"; cin >> data5.an;
    cout << "\ntotal: "<< total_ch_data(4,comenzi,data5);

    int luna;
    cout << "\nTotal vanzari lunare:\nIntroduceti luna:"; cin >> luna;
    cout << "Total:" << total_lunar(4, comenzi, luna);

    int an;
    cout << "\nTotal vanzari anuale:\nIntroduceti an:"; cin >> an;
    cout << "Total:" << total_anual(4, comenzi, an);

    return 0;
}