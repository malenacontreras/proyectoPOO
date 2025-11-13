#include "class.h";


persona::persona() {}
persona::persona(int _dni, string _nombre) { 
    dni = _dni; nombre = _nombre; 
}
void persona::setdni(int _dni) { 
    dni = _dni; 
}
int persona::getdni() { 
    return dni; 
}
int persona::validardni(string entrada) {
    try { 
        stoi(entrada); return 1; 
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

// AUTOR
autor::autor(){}
autor::autor(int _dni, string _nombre, string _medio): persona(_dni, _nombre) { 
    medio = _medio; 
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
    cout << "******AUTOR*****" << endl;
    mostrarpersona();
    cout << "Medio: " << medio << endl;
}

// USUARIO
usuario::usuario(){}
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
    cout << getnombre() << " realizo un comentario." << endl;
}
void usuario::mostrarusuario() {
    cout << "----USUARIO----" << endl;
    mostrarpersona();
    cout << "Edad: " << edad << endl;
    c1.mostrarcomentario();
}

// COMENTARIO
comentario::comentario() {}
comentario::comentario(int _numero, string _texto, string _usuarioAutor) { 
    numero = _numero; 
    texto = _texto; 
    usuarioAutor=_usuarioAutor;
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
    cout << "Comentario #" << numero << " (" << usuarioAutor << "): " << texto << endl;
}
void comentario::setusuarioAutor(string _usuario) { 
        usuarioAutor = _usuario; 
    }
string comentario::getusuarioAutor() {
    return usuarioAutor; 
}


// NOTICIA
noticia::noticia() {}
noticia::noticia(string _titulo, string _detalle, int _dia, int _mes, int _anio, autor _a1) {
    titulo = _titulo; 
    detalle = _detalle; 
    dia = _dia; 
    mes = _mes; 
    anio = _anio; 
    a1=_a1;
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
        if (d >= 1 && d <= 31) 
        return 1; 
        return 0; 
    }
    catch (...) { 
        return 0; 
    }
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
    }
    catch (...) { 
        return 0; 
    }
}
void noticia::setanio(int _anio) { 
    anio = _anio; 
}
int noticia::getanio() { 
    return anio; 
}
int noticia::validaranio(string entrada) {
    try { int a = stoi(entrada); 
        if (a > 1900 && a <= 2025) return 1; 
        return 0; 
    }
    catch (...) { 
        return 0; 
    }
}
void noticia::agregarComentario(comentario nuevo) { 
    comentarios.push_back(nuevo); 
}
autor noticia::getautor() { 
    return a1; 
}
void noticia::mostrarnoticia() {
    cout << "****NOTICIA****" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Comentarios:" << endl;
    if (comentarios.empty()) cout << "No hay comentarios." << endl;
    else for (auto &c : comentarios) c.mostrarcomentario();
    a1.mostrarautor();
}