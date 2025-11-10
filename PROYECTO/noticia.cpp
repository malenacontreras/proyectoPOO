#include <iostream>
#include <vector>
using namespace std;

class persona{
    private:
    int dni;
    string nombre;
    public:
    persona();
    persona(int, string);
    void setdni(int);
    int getdni();
    int validardni(string);
    void setnombre(string);
    string getnombre();
    string validarnombte(string);
    void mostrarpersona();
};

class comentario{
    private:
    int numero;
    string texto;
    public:
    comentario();
    comentario(int,string);
    void setnumero(int);
    int getnumero();
    void settexto(string);
    string gettexto();
    void mostrarcomentario();
};

class noticia{
    private:
    string titulo, detalle;
    int dia, mes, anio;
    vector<comentario> comentarios;
    public:
    noticia();
    noticia(string, string, int, int, int);
    void settitulo(string);
    string gettitulo();
    void setdetalle(string);
    string getdetalle();
    void setdia(int);
    int getdia();
    int validardia(string);
    void setmes(int);
    int getmes();
    int validarmes(string);
    void setanio(int);
    int getanio();
    int validaranio(string);
    void agregarComentario(comentario nuevo); //REVISAR
    void mostrarnoticia();
};
class autor:public persona{
    public:
    string medio;
    noticia n1;
    private:
    autor();
    autor(int, string,string, noticia);
    void setmedio(string);
    string getmedio();
    void publicarnoticia();
    void mostrarautor();
};
class usuario: public persona{
    public:
    int edad;
    comentario c1;
    private:
    usuario();
    usuario(int, string, int, comentario);
    void setedad(int);
    int getedad();
    void realizarcomentario();
    void mostrarusuario();
};

//IMPLEMENTACIONES
persona::persona() {}

persona::persona(int _dni, string _nombre) {
    dni = _dni;
    nombre = _nombre;
}

void persona::setdni(int _dni) { 
    dni = _dni; 
}
int persona::getdni() { 
    return dni; 
}

int persona::validardni(string entrada) {
    try {
        stoi(entrada);
        return 1;
    } catch (...) {
        return 0;
    }
}

void persona::setnombre(string _nombre) { 
    nombre = _nombre; 
}
string persona::getnombre() { 
    return nombre; 
}


void persona::mostrarpersona() {
    cout << "DNI: " << dni << " | Nombre: " << nombre << endl;
}
//AUTOR
autor::autor() : persona() {}

autor::autor(int _dni, string _nombre, string _medio, noticia _n1): persona(_dni, _nombre) {
    medio = _medio;
    n1 = _n1;
}

void autor::setmedio(string _medio) { 
    medio = _medio; 
}
string autor::getmedio() { 
    return medio; 
}

void autor::publicarnoticia() {
    cout << "El autor " << getnombre() << " ha publicado una noticia." << endl;
}

void autor::mostrarautor() {
    cout << "\n--- AUTOR ---" << endl;
    mostrarpersona();
    cout << "Medio: " << medio << endl;
    n1.mostrarnoticia();
}

//USUARIO
usuario::usuario() : persona(){}
usuario::usuario(int _dni, string _nombre, int _edad, comentario _c1): persona(_dni, _nombre) {
    edad = _edad;
    c1 = _c1;
}
void usuario::setedad(int _edad) { 
    edad = _edad; 
}
int usuario::getedad() { 
    return edad; 
}
void usuario::realizarcomentario() {
    cout << getnombre() << " realizó un comentario." << endl;
}
void usuario::mostrarusuario() {
    cout << "\n--- USUARIO ---" << endl;
    mostrarpersona();
    cout << "Edad: " << edad << endl;
    c1.mostrarcomentario();
}


//COMENTARIO
comentario::comentario() {}

comentario::comentario(int _numero, string _texto) {
    numero = _numero;
    texto = _texto;
}

void comentario::setnumero(int _numero) { 
    numero = _numero; 
}
int comentario::getnumero() { 
    return numero; 
}

void comentario::settexto(string _texto) { 
    texto = _texto; 
}
string comentario::gettexto() { 
    return texto; 
}

void comentario::mostrarcomentario() {
    cout << "Comentario #" << numero << ": " << texto << endl;
}

//NOTICIA
noticia::noticia() {}

noticia::noticia(string _titulo, string _detalle, int _dia, int _mes, int _anio) {
    titulo = _titulo;
    detalle = _detalle;
    dia = _dia;
    mes = _mes;
    anio = _anio;
}

void noticia::settitulo(string _titulo) { 
    titulo = _titulo; 
}
string noticia::gettitulo() { 
    return titulo; 
}

void noticia::setdetalle(string _detalle) { 
    detalle = _detalle; 
}
string noticia::getdetalle() { 
    return detalle; 
}

void noticia::setdia(int _dia) { 
    dia = _dia; 
}
int noticia::getdia() { 
    return dia; 
}

int noticia::validardia(string entrada) {
    try {
        int d = stoi(entrada);
        if (d >= 1 && d <= 31) return 1;
        return 0;
    } catch (...) { return 0; }
}

void noticia::setmes(int _mes) { 
    mes = _mes; 
}
int noticia::getmes() { 
    return mes; 
}

int noticia::validarmes(string entrada) {
    try {
        int m = stoi(entrada);
        if (m >= 1 && m <= 12) return 1;
        return 0;
    } catch (...) { return 0; }
}

void noticia::setanio(int _anio) { 
    anio = _anio; 
}
int noticia::getanio() { 
    return anio; 
}

int noticia::validaranio(string entrada) {
    try {
        int a = stoi(entrada);
        if (a > 1900 && a <= 2025) return 1;
        return 0;
    } catch (...) { 
        return 0; 
    }
}

void noticia::agregarComentario(comentario nuevo) {
    comentarios.push_back(nuevo);
}//REVISAR


void noticia::mostrarnoticia() {
    cout << "\n--- NOTICIA ---" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Comentarios:" << endl;

    if (comentarios.empty()) cout << "No hay comentarios." << endl;
    else for (auto &c : comentarios) c.mostrarcomentario();
}
