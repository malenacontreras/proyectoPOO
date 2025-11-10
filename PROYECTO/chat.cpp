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
public:
    comentario();
    comentario(int, string);
    void setnumero(int);
    int getnumero();
    void settexto(string);
    string gettexto();
    void mostrarcomentario();
};

class noticia {
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
    void agregarComentario(comentario nuevo);
    void mostrarnoticia();
};

class autor : public persona {
private:
    string medio;
    noticia n1;
public:
    autor();
    autor(int, string, string, noticia);
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

// -------- IMPLEMENTACIONES --------
persona::persona() {}
persona::persona(int _dni, string _nombre) { dni = _dni; nombre = _nombre; }

void persona::setdni(int _dni) { dni = _dni; }
int persona::getdni() { return dni; }

int persona::validardni(string entrada) {
    try { stoi(entrada); return 1; } catch (...) { return 0; }
}
void persona::setnombre(string _nombre) { nombre = _nombre; }
string persona::getnombre() { return nombre; }

void persona::mostrarpersona() {
    cout << "DNI: " << dni << " | Nombre: " << nombre << endl;
}

// AUTOR
autor::autor() : persona() {}
autor::autor(int _dni, string _nombre, string _medio, noticia _n1)
    : persona(_dni, _nombre) { medio = _medio; n1 = _n1; }

void autor::setmedio(string _medio) { medio = _medio; }
string autor::getmedio() { return medio; }

void autor::publicarnoticia() {
    cout << "El autor " << getnombre() << " ha publicado una noticia." << endl;
}
void autor::mostrarautor() {
    cout << "\n--- AUTOR ---" << endl;
    mostrarpersona();
    cout << "Medio: " << medio << endl;
    n1.mostrarnoticia();
}

// USUARIO
usuario::usuario() : persona() {}
usuario::usuario(int _dni, string _nombre, int _edad, comentario _c1)
    : persona(_dni, _nombre) { edad = _edad; c1 = _c1; }

void usuario::setedad(int _edad) { edad = _edad; }
int usuario::getedad() { return edad; }

void usuario::realizarcomentario() {
    cout << getnombre() << " realizó un comentario." << endl;
}
void usuario::mostrarusuario() {
    cout << "\n--- USUARIO ---" << endl;
    mostrarpersona();
    cout << "Edad: " << edad << endl;
    c1.mostrarcomentario();
}

// COMENTARIO
comentario::comentario() {}
comentario::comentario(int _numero, string _texto) { numero = _numero; texto = _texto; }
void comentario::setnumero(int _numero) { numero = _numero; }
int comentario::getnumero() { return numero; }
void comentario::settexto(string _texto) { texto = _texto; }
string comentario::gettexto() { return texto; }
void comentario::mostrarcomentario() {
    cout << "Comentario #" << numero << ": " << texto << endl;
}

// NOTICIA
noticia::noticia() {}
noticia::noticia(string _titulo, string _detalle, int _dia, int _mes, int _anio) {
    titulo = _titulo; detalle = _detalle; dia = _dia; mes = _mes; anio = _anio;
}
void noticia::settitulo(string _titulo) { titulo = _titulo; }
string noticia::gettitulo() { return titulo; }
void noticia::setdetalle(string _detalle) { detalle = _detalle; }
string noticia::getdetalle() { return detalle; }
void noticia::setdia(int _dia) { dia = _dia; }
int noticia::getdia() { return dia; }
int noticia::validardia(string entrada) {
    try { int d = stoi(entrada); if (d >= 1 && d <= 31) return 1; return 0; }
    catch (...) { return 0; }
}
void noticia::setmes(int _mes) { mes = _mes; }
int noticia::getmes() { return mes; }
int noticia::validarmes(string entrada) {
    try { int m = stoi(entrada); if (m >= 1 && m <= 12) return 1; return 0; }
    catch (...) { return 0; }
}
void noticia::setanio(int _anio) { anio = _anio; }
int noticia::getanio() { return anio; }
int noticia::validaranio(string entrada) {
    try { int a = stoi(entrada); if (a > 1900 && a <= 2025) return 1; return 0; }
    catch (...) { return 0; }
}
void noticia::agregarComentario(comentario nuevo) { comentarios.push_back(nuevo); }
void noticia::mostrarnoticia() {
    cout << "\n--- NOTICIA ---" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Comentarios:" << endl;
    if (comentarios.empty()) cout << "No hay comentarios." << endl;
    else for (auto &c : comentarios) c.mostrarcomentario();
}

// -------------------- MAIN --------------------
int main() {
    vector<autor> autores;
    vector<usuario> usuarios;
    vector<noticia> noticias;

    string entrada;
    int opcion;

    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Registrar Autor" << endl;
        cout << "2. Registrar Usuario" << endl;
        cout << "3. Publicar Noticia" << endl;
        cout << "4. Registrar Comentario" << endl;
        cout << "5. Consultar Noticias (año)" << endl;
        cout << "6. Consultar Noticias (último mes)" << endl;
        cout << "7. Mostrar una Noticia y sus comentarios" << endl;
        cout << "8. Mostrar artículos por Autor" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        getline(cin, entrada);

        try { opcion = stoi(entrada); }
        catch (...) { opcion = -1; }

        switch (opcion) {
        case 1: { // REGISTRO DE AUTOR
            persona p;
            autor a;
            string dniStr, nombre, medio;
            int dniValido = 0;

            do {
                cout << "Ingrese DNI del autor: ";
                getline(cin, dniStr);
                dniValido = p.validardni(dniStr);
            } while (!dniValido);
            p.setdni(stoi(dniStr));

            cout << "Ingrese nombre del autor: ";
            getline(cin, nombre);
            p.setnombre(nombre);

            cout << "Ingrese medio del autor: ";
            getline(cin, medio);

            a.setdni(p.getdni());
            a.setnombre(p.getnombre());
            a.setmedio(medio);

            autores.push_back(a);
            cout << "Autor registrado correctamente.\n";
            break;
        }

        case 2: { // REGISTRO DE USUARIO
            usuario u;
            persona p;
            string dniStr, nombre, edadStr;
            int dniValido = 0, edadValida = 0;

            do {
                cout << "Ingrese DNI del usuario: ";
                getline(cin, dniStr);
                dniValido = p.validardni(dniStr);
            } while (!dniValido);
            p.setdni(stoi(dniStr));

            cout << "Ingrese nombre del usuario: ";
            getline(cin, nombre);
            p.setnombre(nombre);

            do {
                cout << "Ingrese edad del usuario: ";
                getline(cin, edadStr);
                try { stoi(edadStr); edadValida = 1; } catch (...) { edadValida = 0; }
            } while (!edadValida);

            u.setdni(p.getdni());
            u.setnombre(p.getnombre());
            u.setedad(stoi(edadStr));

            usuarios.push_back(u);
            cout << "Usuario registrado correctamente.\n";
            break;
        }

        case 3: { // PUBLICAR NOTICIA
            if (autores.empty()) { cout << "No hay autores registrados.\n"; break; }

            noticia n;
            string titulo, detalle, diaStr, mesStr, anioStr;
            int dValido = 0, mValido = 0, aValido = 0;

            cout << "Ingrese título de la noticia: ";
            getline(cin, titulo);
            cout << "Ingrese detalle de la noticia: ";
            getline(cin, detalle);

            do { cout << "Ingrese día: "; getline(cin, diaStr); dValido = n.validardia(diaStr); } while (!dValido);
            do { cout << "Ingrese mes: "; getline(cin, mesStr); mValido = n.validarmes(mesStr); } while (!mValido);
            do { cout << "Ingrese año: "; getline(cin, anioStr); aValido = n.validaranio(anioStr); } while (!aValido);

            n.settitulo(titulo);
            n.setdetalle(detalle);
            n.setdia(stoi(diaStr));
            n.setmes(stoi(mesStr));
            n.setanio(stoi(anioStr));

            noticias.push_back(n);
            cout << "Noticia publicada correctamente.\n";
            break;
        }

        case 4: { // REGISTRAR COMENTARIO
            if (usuarios.empty() || noticias.empty()) {
                cout << "Debe haber usuarios y noticias registradas.\n";
                break;
            }
            cout << "Seleccione número de noticia para comentar:\n";
            for (size_t i = 0; i < noticias.size(); i++) {
                cout << i + 1 << ". " << noticias[i].gettitulo() << endl;
            }
            string opcionNoticiaStr;
            int indice = -1;
            do {
                getline(cin, opcionNoticiaStr);
                try { indice = stoi(opcionNoticiaStr) - 1; } catch (...) { indice = -1; }
            } while (indice < 0 || indice >= (int)noticias.size());

            comentario c;
            string numeroStr, texto;
            int nValido = 0;
            do {
                cout << "Ingrese número de comentario: ";
                getline(cin, numeroStr);
                try { stoi(numeroStr); nValido = 1; } catch (...) { nValido = 0; }
            } while (!nValido);

            cout << "Ingrese texto del comentario: ";
            getline(cin, texto);

            c.setnumero(stoi(numeroStr));
            c.settexto(texto);
            noticias[indice].agregarComentario(c);

            cout << "Comentario agregado correctamente.\n";
            break;
        }

        case 5: { // CONSULTAR NOTICIAS POR AÑO
            if (noticias.empty()) { cout << "No hay noticias cargadas.\n"; break; }

            string anioStr;
            int aValido = 0;
            noticia temp;
            do {
                cout << "Ingrese el año a consultar: ";
                getline(cin, anioStr);
                aValido = temp.validaranio(anioStr);
            } while (!aValido);

            cout << "\nNoticias del año " << anioStr << ":\n";
            for (auto &n : noticias)
                if (n.getanio() == stoi(anioStr))
                    n.mostrarnoticia();
            break;
        }

        case 6: { // CONSULTAR NOTICIAS DEL ÚLTIMO MES
            if (noticias.empty()) { cout << "No hay noticias cargadas.\n"; break; }

            time_t t = time(0);
            tm* now = localtime(&t);
            int mesActual = now->tm_mon + 1;
            int anioActual = now->tm_year + 1900;

            cout << "\nNoticias del último mes (" << mesActual << "/" << anioActual << "):\n";
            for (auto &n : noticias)
                if (n.getmes() == mesActual && n.getanio() == anioActual)
                    n.mostrarnoticia();
            break;
        }

        case 7: { // MOSTRAR UNA NOTICIA Y SUS COMENTARIOS
            if (noticias.empty()) { cout << "No hay noticias cargadas.\n"; break; }
            cout << "Seleccione número de noticia a mostrar:\n";
            for (size_t i = 0; i < noticias.size(); i++)
                cout << i + 1 << ". " << noticias[i].gettitulo() << endl;

            string opcionStr;
            int idx = -1;
            do {
                getline(cin, opcionStr);
                try { idx = stoi(opcionStr) - 1; } catch (...) { idx = -1; }
            } while (idx < 0 || idx >= (int)noticias.size());

            noticias[idx].mostrarnoticia();
            break;
        }

        case 8: { // ARTÍCULOS POR AUTOR
            if (autores.empty() || noticias.empty()) {
                cout << "No hay autores o noticias cargadas.\n";
                break;
            }
            cout << "Autores disponibles:\n";
            for (size_t i = 0; i < autores.size(); i++)
                cout << i + 1 << ". " << autores[i].getnombre() << endl;

            string opcStr;
            int idA = -1;
            do {
                getline(cin, opcStr);
                try { idA = stoi(opcStr) - 1; } catch (...) { idA = -1; }
            } while (idA < 0 || idA >= (int)autores.size());

            cout << "\nArtículos publicados por " << autores[idA].getnombre() << ":\n";
            for (auto &n : noticias) n.mostrarnoticia();
            break;
        }

        case 0:
            cout << "Saliendo del sistema...\n";
            break;

        default:
            cout << "Opción no válida.\n";
        }

    } while (opcion != 0);

    return 0;
}
