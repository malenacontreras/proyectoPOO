#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
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
    vector<comentario> getComentarios();
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
vector<comentario> noticia::getComentarios() {
    return comentarios;
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


void guardarAutores(vector<autor>& autores) {
    ofstream archivo("autores.txt");//abre o crea el archivo autores.txt
    if (archivo.is_open()) {//verifica que el archivo abrio
        for (size_t i = 0; i < autores.size(); i++) {//recorre el vector de autores y lo escribe uno por uno
            archivo <<"AUTOR " <<i+1<<endl<<"Dni: "<<autores[i].getdni() <<endl
                    <<"Nombre: "<< autores[i].getnombre() <<endl
                    <<"Medio: "<< autores[i].getmedio() << endl;
        }
        archivo.close();//cierra el archivo y guarda los cambios.
        cout << "Autores guardados correctamente en autores.txt" << endl;
    } else {
        cout << "Error al abrir archivo autores.txt" << endl;
    }
}

void guardarUsuarios(vector<usuario>& usuarios) {
    ofstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < usuarios.size(); i++) {
            archivo <<"USUARIO "<<i+1<<endl 
                    <<"Dni: "<< usuarios[i].getdni() <<endl
                    <<"Nombre: "<< usuarios[i].getnombre() <<endl
                    <<"Edad: "<< usuarios[i].getedad() << endl;
        }
        archivo.close();
        cout << "Usuarios guardados correctamente en usuarios.txt" << endl;
    } else {
        cout << "Error al abrir archivo usuarios.txt" << endl;
    }
}

void guardarComentarios(vector<noticia>& noticias) {
    ofstream archivo("comentarios.txt");//abre o crea el archivo de comentarios
    if (archivo.is_open()) {
        for (size_t i = 0; i < noticias.size(); i++) {//recorre todas las noticias
            vector<comentario> coments = noticias[i].getComentarios();//obtiene los comentarios de cada noticia
            for (size_t j = 0; j < coments.size(); j++) {//recorre los comentarios de esa noticia. Copia sus datos
                archivo << "COMENTARIO " << j+1 << endl
                        << "Noticia: " << noticias[i].gettitulo() << endl
                        << "Numero: " << coments[j].getnumero() << endl
                        << "Texto: " << coments[j].gettexto() << endl
                        << "Usuario: " << coments[j].getusuarioAutor() << endl
                        << endl;
            }
        }
        archivo.close();
        cout << "Comentarios guardados correctamente en comentarios.txt" << endl;
    } else {
        cout << "Error al abrir archivo comentarios.txt" << endl;
    }
}


void guardarNoticias(vector<noticia>& noticias) {
    ofstream archivo("noticias.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < noticias.size(); i++) {
            archivo <<"NOTICIA "<<i+1<<endl<<"Titulo: "<< noticias[i].gettitulo() <<endl
                    <<"Detalle: "<< noticias[i].getdetalle() <<endl
                    <<"Fecha: "<< noticias[i].getdia() <<"/"
                    << noticias[i].getmes() <<"/"
                    << noticias[i].getanio() <<endl
                    <<"Autor: "<< noticias[i].getautor().getnombre()<<endl;
                    vector<comentario> coments = noticias[i].getComentarios();//obtenemos la lista de comentarios de la noticia
                    archivo << "Comentarios:" << endl;
                    if (coments.empty()) {//por si no hay comentarios
                        archivo << "   (No hay comentarios)" << endl;
                    } else {
                        for (size_t j = 0; j < coments.size(); j++) {//muestra los comentarios uno por uno
                            archivo << "   - Numero: " << coments[j].getnumero() << endl
                                    << "     Texto: " << coments[j].gettexto() << endl
                                    << "     Usuario: " << coments[j].getusuarioAutor() << endl;
                        }
                    }
                    archivo << endl;
                    
        }
        archivo.close();
        cout << "Noticias guardadas correctamente en noticias.txt" << endl;
    } else {
        cout << "Error al abrir archivo noticias.txt" << endl;
    }
}

void guardarTodos(vector<autor>& autores, vector<usuario>& usuarios, vector<noticia>& noticias) {//llama a cada funcion de guardado por separado
    guardarAutores(autores);
    guardarUsuarios(usuarios);
    guardarNoticias(noticias);
    guardarComentarios(noticias);
    cout << "Todos los datos han sido guardados correctamente." << endl;
}

// MAIN 
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
        cout << "9. Guardar todos los datos en archivos" << endl;
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
        case 1: {
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

        case 2: {
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
            cout << "Usuario registrado correctamente.\n";
            break;
        }
        case 3: {
            if (autores.empty()) { 
                cout << "No hay autores registrados. Debe registrar un autor primero.\n"; 
                break;  //verifica que haya al menos un autor
            }
            cout << "Seleccione el autor que publicara la noticia:" << endl;
            for (size_t i = 0; i < autores.size(); i++) {
                cout << i + 1 << ". " << autores[i].getnombre() << endl;
            } //enlista los autores registrados hasta el momento
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

            noticia n_para_validar;
            string titulo, detalle, diaStr, mesStr, anioStr;
            int dValido = 0, mValido = 0, aValido = 0;

            cout << "Ingrese titulo de la noticia: ";
            getline(cin, titulo);
            cout << "Ingrese detalle de la noticia: ";
            getline(cin, detalle);

            // Usamos para llamar a los métodos de validación
            do { 
                cout << "Ingrese dia: "; getline(cin, diaStr); dValido = n_para_validar.validardia(diaStr); 
            } while (!dValido); //repite la pregunta cada vez que el trycatch no funciona.
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

            noticias.push_back(n_final); //guarda la nueva noticia en el vector.
            autorSeleccionado.publicarnoticia();
            
            cout << "Noticia publicada correctamente.\n";
            break;
        }

        case 4: {
            if (usuarios.empty() || noticias.empty()) {
            cout << "Debe haber usuarios y noticias registradas.\n";
            break; 
            }

            cout << "Seleccione numero de noticia para comentar:\n";
            for (size_t i = 0; i < noticias.size(); i++) {
                cout << i + 1 << ". " << noticias[i].gettitulo() << endl;
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
                    indiceUsuario = stoi(opcionUsuarioStr) - 1; 
                } catch (...) { 
                    indiceUsuario = -1; 
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
            c.setusuarioAutor(usuarios[indiceUsuario].getnombre());
        
            noticias[indiceNoticia].agregarComentario(c);
        
            cout << "Comentario agregado correctamente por " << usuarios[indiceUsuario].getnombre() << "\n";
            break;
        }        


        case 5: {
            if (noticias.empty()) { 
                cout << "No hay noticias cargadas.\n"; 
                break;
            }

            string anioStr;
            int aValido = 0;
            noticia temp;
            do {
                cout << "Ingrese el anio a consultar: ";
                getline(cin, anioStr);
                aValido = temp.validaranio(anioStr);
            } while (!aValido);

            cout << "Noticias del anio " << anioStr << ":\n";
            for (auto &n : noticias)
                if (n.getanio() == stoi(anioStr))
                    n.mostrarnoticia();
            break;
        }

        case 6: {
            if (noticias.empty()) { 
                cout << "No hay noticias cargadas.\n"; 
                break; 
            }

            time_t t = time(0);
            tm* now = localtime(&t);
            int mesActual = now->tm_mon + 1;
            int anioActual = now->tm_year + 1900;

            cout << "Noticias del ultimo mes (" << mesActual << "/" << anioActual << "):\n";
            for (auto &n : noticias)
                if (n.getmes() == mesActual && n.getanio() == anioActual)
                    n.mostrarnoticia();
            break;
        }

        case 7: {
            if (noticias.empty()) { 
                cout << "No hay noticias cargadas.\n"; 
                break; 
            }
            cout << "Seleccione numero de noticia a mostrar:\n";
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

        case 8: {
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
                if (n.getautor().getnombre() == nombreAutor) {
                    n.mostrarnoticia();
                    encontrado = true;
                }
            }
        
            if (!encontrado)
                cout << "Este autor no tiene noticias publicadas.\n";
        
            break;
        }

        case 9: {
            guardarTodos(autores, usuarios, noticias);
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
};
