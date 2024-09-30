#include "ContaI.h"
#include <iostream>

using namespace std;
using namespace CORBA;

extern ORB_var orb; // definido no arquivo servidor.cpp

// Implementation skeleton constructor
Conta_i::Conta_i ()
{
    meu_saldo = 0.0;
}

// Implementation skeleton destructor
Conta_i::~Conta_i ()
{
}

std::string Conta_i::id ()
{
    return string("1234-56");
}

::CORBA::Float Conta_i::saldo ()
{
    return meu_saldo;
}

void Conta_i::deposito (::CORBA::Float valor)
{
    cout << "deposito " << valor << endl;
    meu_saldo += valor;
}

void Conta_i::saque (::CORBA::Float valor)
{
    if (valor <= meu_saldo) {
        cout << "saque " << valor << endl;
        meu_saldo -= valor;
    } else
        throw SaldoInsuficiente();
}

void Conta_i::transfere (
  ::CORBA::Float valor,
  ::Conta_ptr dest)
{
  // Add your implementation here
}

void Conta_i::shutdown (const std::string senha)
{
    if (senha == "12345")
        orb->shutdown();
}

