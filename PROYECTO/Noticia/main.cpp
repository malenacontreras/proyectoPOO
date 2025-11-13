#include "class.h";


int main() {
    vector<autor> autores;
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
        getline(cin, entrada);

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
                try { stoi(edadStr); edadValida = 1; } catch (...) { edadValida = 0; }
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
                break; 
            }
            cout << "Seleccione el autor que publicara la noticia:" << endl;
            for (size_t i = 0; i < autores.size(); i++) {
                cout << i + 1 << ". " << autores[i].getnombre() << endl;
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
            // --- FIN: SELECCIÓN DE AUTOR ---

            noticia n_para_validar; // Objeto temporal solo para usar los métodos de validación
            string titulo, detalle, diaStr, mesStr, anioStr;
            int dValido = 0, mValido = 0, aValido = 0;

            cout << "Ingrese titulo de la noticia: ";
            getline(cin, titulo);
            cout << "Ingrese detalle de la noticia: ";
            getline(cin, detalle);

            // Usamos el objeto temporal para llamar a los métodos de validación
            do { cout << "Ingrese dia: "; getline(cin, diaStr); dValido = n_para_validar.validardia(diaStr); } while (!dValido);
            do { cout << "Ingrese mes: "; getline(cin, mesStr); mValido = n_para_validar.validarmes(mesStr); } while (!mValido);
            do { cout << "Ingrese anio: "; getline(cin, anioStr); aValido = n_para_validar.validaranio(anioStr); } while (!aValido);

            noticia n_final(
                titulo, 
                detalle, 
                stoi(diaStr), 
                stoi(mesStr), 
                stoi(anioStr), 
                autorSeleccionado
            );

            noticias.push_back(n_final);
            autorSeleccionado.publicarnoticia();
            
            cout << "Noticia publicada correctamente.";
            break;
        }

        case 4: { // REGISTRAR COMENTARIO
        if (usuarios.empty() || noticias.empty()) {
        cout << "Debe haber usuarios y noticias registradas.";
        break;
    }

    cout << "Seleccione numero de noticia para comentar:";
    for (size_t i = 0; i < noticias.size(); i++) {
        cout << i + 1 << ". " << noticias[i].gettitulo() << endl;
    }

    string opcionNoticiaStr;
    int indiceNoticia = -1;
    do {
        getline(cin, opcionNoticiaStr);
        try { indiceNoticia = stoi(opcionNoticiaStr) - 1; } catch (...) { indiceNoticia = -1; }
    } while (indiceNoticia < 0 || indiceNoticia >= (int)noticias.size());

    cout << "Seleccione el usuario que hara el comentario:\n";
    for (size_t i = 0; i < usuarios.size(); i++) {
        cout << i + 1 << ". " << usuarios[i].getnombre() << endl;
    }

    string opcionUsuarioStr;
    int indiceUsuario = -1;
    do {
        getline(cin, opcionUsuarioStr);
        try { indiceUsuario = stoi(opcionUsuarioStr) - 1; } catch (...) { indiceUsuario = -1; }
    } while (indiceUsuario < 0 || indiceUsuario >= (int)usuarios.size());

    comentario c;
    string numeroStr, texto;
    int nValido = 0;

    do {
        cout << "Ingrese numero de comentario: ";
        getline(cin, numeroStr);
        try { stoi(numeroStr); nValido = 1; } catch (...) { nValido = 0; }
    } while (!nValido);

    cout << "Ingrese texto del comentario: ";
    getline(cin, texto);

    c.setnumero(stoi(numeroStr));
    c.settexto(texto);
    c.setusuarioAutor(usuarios[indiceUsuario].getnombre()); // 👈 guarda el nombre del usuario

    noticias[indiceNoticia].agregarComentario(c);

    cout << "Comentario agregado correctamente por " << usuarios[indiceUsuario].getnombre() << ".\n";
    break;
}


        case 5: { // CONSULTAR NOTICIAS POR AÑO
            if (noticias.empty()) { cout << "No hay noticias cargadas."; break; }

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

        case 6: { // CONSULTAR NOTICIAS DEL ÚLTIMO MES
            if (noticias.empty()) { cout << "No hay noticias cargadas."; break; }

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

        case 7: { // MOSTRAR UNA NOTICIA Y SUS COMENTARIOS
            if (noticias.empty()) { cout << "No hay noticias cargadas.\n"; break; }
            cout << "Seleccione numero de noticia a mostrar:\n";
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
        if (n.getautor().getnombre() == nombreAutor) { // 🔹 usa el getter nuevo
            n.mostrarnoticia();
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "Este autor no tiene noticias publicadas.\n";

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