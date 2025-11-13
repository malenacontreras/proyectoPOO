#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class persona {
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
    void mostrarpersona();
};

class comentario {
private:
    int numero;
    string texto;
    string usuarioAutor; 
public:
    comentario();
    comentario(int, string,string);
    void setnumero(int);
    int getnumero();
    void settexto(string);
    string gettexto();
    void mostrarcomentario();
    void setusuarioAutor(string);
    string getusuarioAutor();
};


class autor : public persona {
private:
    string medio;
public:
    autor();
    autor(int, string, string);
    void setmedio(string);
    string getmedio();
    void publicarnoticia();
    void mostrarautor();
};

class usuario : public persona {
private:
    int edad;
    comentario c1;
public:
    usuario();
    usuario(int, string, int, comentario);
    void setedad(int);
    int getedad();
    void realizarcomentario();
    void mostrarusuario();
};
class noticia {
private:
    string titulo, detalle;
    int dia, mes, anio;
    vector<comentario> comentarios;
    autor a1;
public:
    noticia();
    noticia(string, string, int, int, int, autor);
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
    void agregarComentario(comentario nuevo);
    autor getautor();
    void mostrarnoticia();
};