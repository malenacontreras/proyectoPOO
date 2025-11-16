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

//IMPLEMENTACIONES
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
    comentarios.push_back(nuevo); //agrega el nuevo comentario registrado al vector
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

// -------------------- MAIN --------------------
int main() {
    vector<autor> autores; //guarda todos los autores, usuarios y noticias registradas
    vector<usuario> usuarios;
    vector<noticia> noticias;

    string entrada;
    int opcion;

    do {
        cout << "=== MENU PRINCIPAL ===" << endl;
        cout << "1. Registrar Autor" << endl;
        cout << "2. Registrar Usuario" << endl;
        cout << "3. Publicar Noticia" << endl;
        cout << "4. Registrar Comentario" << endl;
        cout << "5. Consultar Noticias (anio)" << endl;
        cout << "6. Consultar Noticias (ultimo mes)" << endl;
        cout << "7. Mostrar una Noticia y sus comentarios" << endl;
        cout << "8. Mostrar articulos por Autor" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        getline(cin, entrada); //para que el sistema no se rompa, si se ingresa un string, el sistema lo agarra y convierte en int.

        try { 
            opcion = stoi(entrada); 
        }
        catch (...) { 
            opcion = -1; 
        }

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
                try { 
                    stoi(edadStr); edadValida = 1; 
                } catch (...) { 
                    edadValida = 0; 
                }
            } while (!edadValida);

            u.setdni(p.getdni());
            u.setnombre(p.getnombre());
            u.setedad(stoi(edadStr));

            usuarios.push_back(u);
            cout << "Usuario registrado correctamente.";
            break;
        }
        case 3: { // PUBLICAR NOTICIA
            if (autores.empty()) { 
                cout << "No hay autores registrados. Debe registrar un autor primero."; 
                break; //verifica que haya al menos un autor
            }
            cout << "Seleccione el autor que publicara la noticia:" << endl;
            for (size_t i = 0; i < autores.size(); i++) {
                cout << i + 1 << ". " << autores[i].getnombre() << endl;//enlista los autores registrados hasta el momento
            }
            string autorStr;
            int autorIdx = -1;
            do {
                cout << "Ingrese el numero del autor: ";
                getline(cin, autorStr);
                try { 
                    autorIdx = stoi(autorStr) - 1; // Restamos 1 para que sea índice
                } catch (...) { 
                    autorIdx = -1; 
                }
                if (autorIdx < 0 || autorIdx >= (int)autores.size()) {
                    cout << "Seleccion no valida. Intente de nuevo." << endl;
                }
            } while (autorIdx < 0 || autorIdx >= (int)autores.size());

            autor autorSeleccionado = autores[autorIdx];
            // FIN: SELECCIÓN DE AUTOR 

            noticia n_para_validar; // Objeto temporal solo para usar los métodos de validación
            string titulo, detalle, diaStr, mesStr, anioStr;
            int dValido = 0, mValido = 0, aValido = 0;

            cout << "Ingrese titulo de la noticia: ";
            getline(cin, titulo);
            cout << "Ingrese detalle de la noticia: ";
            getline(cin, detalle);

            // Usamos para llamar a los métodos de validación
            do { 
                cout << "Ingrese dia: "; getline(cin, diaStr); dValido = n_para_validar.validardia(diaStr); 
            } while (!dValido);//repite la pregunta cada vez que el trycatch no funciona.
            do { 
                cout << "Ingrese mes: "; getline(cin, mesStr); mValido = n_para_validar.validarmes(mesStr); 
            } while (!mValido);
            do { 
                cout << "Ingrese anio: "; getline(cin, anioStr); aValido = n_para_validar.validaranio(anioStr); 
            } while (!aValido);

            noticia n_final(
                titulo, 
                detalle, 
                stoi(diaStr), 
                stoi(mesStr), 
                stoi(anioStr), 
                autorSeleccionado
            );

            noticias.push_back(n_final);//guarda la nueva noticia en el vector.
            autorSeleccionado.publicarnoticia();
            
            cout << "Noticia publicada correctamente."<<endl;
            break;
        }

        case 4: { // REGISTRAR COMENTARIO
            if (usuarios.empty() || noticias.empty()) {
            cout << "Debe haber usuarios y noticias registradas.";
            break; //verifica que haya usuarios y noticias.
            }

            cout << "Seleccione numero de noticia para comentar:";
            for (size_t i = 0; i < noticias.size(); i++) {
                cout << i + 1 << ". " << noticias[i].gettitulo() << endl;//hace un indice de las noticias que hay registradas
            }
        
            string opcionNoticiaStr;
            int indiceNoticia = -1;
            do {
                getline(cin, opcionNoticiaStr);
                try { 
                    indiceNoticia = stoi(opcionNoticiaStr) - 1; 
                } catch (...) { 
                    indiceNoticia = -1; 
                }
            } while (indiceNoticia < 0 || indiceNoticia >= (int)noticias.size());
        
            cout << "Seleccione el usuario que hara el comentario:\n";
            for (size_t i = 0; i < usuarios.size(); i++) {
                cout << i + 1 << ". " << usuarios[i].getnombre() << endl;
            }
        
            string opcionUsuarioStr;
            int indiceUsuario = -1;
            do {
                getline(cin, opcionUsuarioStr);
                try { 
                    indiceUsuario = stoi(opcionUsuarioStr) - 1; } 
                    catch (...) { indiceUsuario = -1; 
                    }
            } while (indiceUsuario < 0 || indiceUsuario >= (int)usuarios.size());
        
            comentario c;
            string numeroStr, texto;
            int nValido = 0;
        
            do {
                cout << "Ingrese numero de comentario: ";
                getline(cin, numeroStr);
                try { 
                    stoi(numeroStr); nValido = 1; 
                } catch (...) { 
                    nValido = 0; 
                }
            } while (!nValido);
        
            cout << "Ingrese texto del comentario: ";
            getline(cin, texto);
        
            c.setnumero(stoi(numeroStr));
            c.settexto(texto);
            c.setusuarioAutor(usuarios[indiceUsuario].getnombre()); // Se crea el comentario y se asocia al nombre del usuario
        
            noticias[indiceNoticia].agregarComentario(c); //Se guarda el comentario dentro del vector de comentarios de la noticia
        
            cout << "Comentario agregado correctamente por " << usuarios[indiceUsuario].getnombre() <<endl;
            break;
        }        


        case 5: { // CONSULTAR NOTICIAS POR AÑO
            if (noticias.empty()) { 
                cout << "No hay noticias cargadas."; 
                break; //verifica que haya noticias
            }

            string anioStr;
            int aValido = 0;
            noticia temp;
            do {
                cout << "Ingrese el anio a consultar: ";
                getline(cin, anioStr);
                aValido = temp.validaranio(anioStr);
            } while (!aValido);//valida el año y vuelve a preguntar si es invalido

            cout << "Noticias del anio " << anioStr << ":\n";
            for (auto &n : noticias)
                if (n.getanio() == stoi(anioStr))
                    n.mostrarnoticia();
            break;//Recorre todas las noticias y muestra solo las que coinciden con el año ingresado
        }

        case 6: { // CONSULTAR NOTICIAS DEL ÚLTIMO MES
            if (noticias.empty()) { cout << "No hay noticias cargadas."; break; }

            time_t t = time(0);
            tm* now = localtime(&t);
            int mesActual = now->tm_mon + 1;
            int anioActual = now->tm_year + 1900; //Obtiene la fecha actual del sistema.

            cout << "Noticias del ultimo mes (" << mesActual << "/" << anioActual << "):\n";
            for (auto &n : noticias)
                if (n.getmes() == mesActual && n.getanio() == anioActual)
                    n.mostrarnoticia();
            break; //Muestra solo las noticias publicadas en ese mes y año
        }

        case 7: { // MOSTRAR UNA NOTICIA Y SUS COMENTARIOS
            if (noticias.empty()) { cout << "No hay noticias cargadas."<<endl; 
                break; 
            }
            cout << "Seleccione numero de noticia a mostrar:"<<endl;
            for (size_t i = 0; i < noticias.size(); i++)
                cout << i + 1 << ". " << noticias[i].gettitulo() << endl;

            string opcionStr;
            int idx = -1;
            do {
                getline(cin, opcionStr);
                try { 
                    idx = stoi(opcionStr) - 1; 
                } catch (...) { 
                    idx = -1; 
                }
            } while (idx < 0 || idx >= (int)noticias.size());

            noticias[idx].mostrarnoticia();
            break;
        }

        case 8: { // ARTÍCULOS POR AUTOR (corregido)
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
                cout << "Seleccione el número del autor: ";
                getline(cin, opcStr);
                try { idA = stoi(opcStr) - 1; } catch (...) { idA = -1; }
                if (idA < 0 || idA >= (int)autores.size())
                    cout << "Opcion inválida. Intente de nuevo.\n";
            } while (idA < 0 || idA >= (int)autores.size());
        
            string nombreAutor = autores[idA].getnombre();
            bool encontrado = false;
        
            cout << "\nArticulos publicados por " << nombreAutor << ":\n";
            for (auto &n : noticias) {
                if (n.getautor().getnombre() == nombreAutor) { //usa el getter nuevo
                    n.mostrarnoticia();
                    encontrado = true;
                }
            }
        
            if (!encontrado)
                cout << "Este autor no tiene noticias publicadas."<<endl;
        
            break;
        }


        case 0:
            cout << "Saliendo del sistema..."<<endl;
            break;
        default:
            cout << "Opción no válida."<<endl;
        }
        } while (opcion != 0);

        return 0;
};