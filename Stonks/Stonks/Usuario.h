#pragma once
using namespace System;
public ref class Usuario {

public:

    int ID;
    String^ Username;
    String^ Email;
    String^ Password;
    bool Visible;

    Usuario() : ID(0), Username(""), Email(""), Password(""), Visible(true) {  }
    Usuario(int id, String^ username, String^ email, String^ password) : ID(id), Username(username), Email(email), Password(password), Visible(true) {  }
};
