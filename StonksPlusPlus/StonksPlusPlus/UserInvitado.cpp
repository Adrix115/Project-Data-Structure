#include "UserInvitado.h"

Users UserInvitado::login(Users users[], int tam, bool &bucle) {
    text.reset(); bucle = 0;
    string username, pass;  string txt, txt1;
    text.write("Stonks ++ Copyright 2024"); text.changealignedment("center");        text.write("LOG IN"); text.newl(1);
    text.write("INGRESAR EL USERNAME");  text.changealignedment("left");  text.newl(1);
    cout << "                           "; getline(cin, txt); text.newl(2); text.changealignedment("center");
    text.write("INGRESAR EL PASSWORD"); text.changealignedment("left"); text.newl(1);
    cout << "                           "; getline(cin, txt1);  text.newl(2); text.changealignedment("center");
    for (int i = 0; i < tam; i++) {
        if (txt == users[i].username && txt1 == users[i].password) {
            usuario.email = users[i].email; usuario.password = users[i].password;
            usuario.userID = users[i].userID; usuario.username = txt; usuario.userType = users[i].userType;
            bucle = 1;
        }
    }

    return usuario;
}

Users UserInvitado::singup() {
    text.reset();
    text.write("Por favor, ¡Querido usuario!, proporcione su nombre de Usuario :");  text.changealignedment("left");  text.newl(1);
    cout << "                           ";  getline(cin, usuario.username); text.newl(2); text.changealignedment("center");
    text.write("Por favor, proporcione un email :");  text.changealignedment("left");  text.newl(1);
    cout << "                           "; getline(cin, usuario.email); text.newl(2); text.changealignedment("center");
    text.write("¿Podria proporcionarnos su contraseña?: "); text.changealignedment("left"); text.newl(1);
    cout << "                           "; getline(cin, usuario.password);  text.newl(2); text.changealignedment("center");
    return usuario;
}

//Le enviamos en ambos casos un usuario al main, para que en singup lo guarde el main en un .txt, y login para que tenga ese usuario como usuarioactual
