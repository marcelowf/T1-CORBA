#ifndef CONTAI_B00D87_H_
#define CONTAI_B00D87_H_

#include "ContaS.h"

#if !defined(ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class Conta_i : public virtual POA_Conta
{
private:
  float meu_saldo;

public:
  Conta_i();

  virtual ~Conta_i();

  virtual std::string id();
  virtual ::CORBA::Float saldo();
  virtual void deposito(::CORBA::Float valor);
  virtual void saque(::CORBA::Float valor);
  virtual void transfere(
      ::CORBA::Float valor,
      ::Conta_ptr dest);

  virtual void shutdown(const std::string senha);
};

#endif
