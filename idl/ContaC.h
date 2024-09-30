#ifndef _TAO_IDL_CONTAC_Z7IFWF_H_
#define _TAO_IDL_CONTAC_Z7IFWF_H_

#include "ace/config-all.h"

#if !defined(ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

#include <string>
#include <vector>

#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Version.h"
#include "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 4 || TAO_MINOR_VERSION != 0 || TAO_MICRO_VERSION != 1
#error This file should be regenerated with TAO_IDL
#endif

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  template <typename T>
  class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL

class SaldoInsuficiente : public ::CORBA::UserException
{
public:
  SaldoInsuficiente();
  SaldoInsuficiente(const SaldoInsuficiente &);
  ~SaldoInsuficiente() = default;

  SaldoInsuficiente &operator=(const SaldoInsuficiente &);

  static void _tao_any_destructor(void *);

  static SaldoInsuficiente *_downcast(::CORBA::Exception *);
  static const SaldoInsuficiente *_downcast(::CORBA::Exception const *);

  static ::CORBA::Exception *_alloc();

  virtual ::CORBA::Exception *_tao_duplicate() const;

  virtual void _raise() const;

  virtual void _tao_encode(TAO_OutputCDR &cdr) const;
  virtual void _tao_decode(TAO_InputCDR &cdr);

  virtual ::CORBA::TypeCode_ptr _tao_type() const;
};

extern ::CORBA::TypeCode_ptr const _tc_SaldoInsuficiente;

#if !defined(_CONTA__VAR_OUT_CH_)
#define _CONTA__VAR_OUT_CH_

class Conta;
using Conta_ptr = Conta *;
using Conta_var = TAO_Objref_Var_T<Conta>;
using Conta_out = TAO_Objref_Out_T<Conta>;

#endif

class Conta
    : public virtual ::CORBA::Object
{
public:
  friend class TAO::Narrow_Utils<Conta>;

  using _ptr_type = Conta_ptr;
  using _var_type = Conta_var;
  using _out_type = Conta_out;

  static void _tao_any_destructor(void *);

  static Conta_ptr _duplicate(Conta_ptr obj);

  static void _tao_release(Conta_ptr obj);

  static Conta_ptr _narrow(::CORBA::Object_ptr obj);
  static Conta_ptr _unchecked_narrow(::CORBA::Object_ptr obj);
  static Conta_ptr _nil();

  virtual std::string id();

  virtual ::CORBA::Float saldo();

  virtual void deposito(
      ::CORBA::Float valor);

  virtual void saque(
      ::CORBA::Float valor);

  virtual void transfere(
      ::CORBA::Float valor,
      ::Conta_ptr dest);

  virtual void shutdown(
      const std::string senha);

  virtual ::CORBA::Boolean _is_a(const char *type_id);
  virtual const char *_interface_repository_id() const;
  virtual ::CORBA::Boolean marshal(TAO_OutputCDR &cdr);

protected:
  Conta();

  Conta(::IOP::IOR *ior, TAO_ORB_Core *orb_core);

  Conta(
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = false,
      TAO_Abstract_ServantBase *servant = nullptr,
      TAO_ORB_Core *orb_core = nullptr);

  virtual ~Conta() = default;

private:
  Conta(const Conta &) = delete;
  Conta(Conta &&) = delete;
  Conta &operator=(const Conta &) = delete;
  Conta &operator=(Conta &&) = delete;
};

extern ::CORBA::TypeCode_ptr const _tc_Conta;

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
#if !defined(_CONTA__ARG_TRAITS_)
#define _CONTA__ARG_TRAITS_

  template <>
  class Arg_Traits<::Conta>
      : public Object_Arg_Traits_T<
            ::Conta_ptr,
            ::Conta_var,
            ::Conta_out,
            TAO::Objref_Traits<Conta>,
            TAO::Any_Insert_Policy_Stream>
  {
  };
#endif
}

TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{

#if !defined(_CONTA__TRAITS_)
#define _CONTA__TRAITS_

  template <>
  struct Objref_Traits<::Conta>
  {
    static ::Conta_ptr duplicate(::Conta_ptr p);
    static void release(::Conta_ptr p);
    static ::Conta_ptr nil();
    static ::CORBA::Boolean marshal(const ::Conta_ptr p, TAO_OutputCDR &cdr);
  };

#endif
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA
{

  void operator<<=(::CORBA::Any &, const SaldoInsuficiente &);
  void operator<<=(::CORBA::Any &, SaldoInsuficiente *);
  ::CORBA::Boolean operator>>=(const ::CORBA::Any &, const SaldoInsuficiente *&);
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA
{

  void operator<<=(::CORBA::Any &, Conta_ptr);
  void operator<<=(::CORBA::Any &, Conta_ptr *);
  ::CORBA::Boolean operator>>=(const ::CORBA::Any &, Conta_ptr &);
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<<(TAO_OutputCDR &, const SaldoInsuficiente &);
::CORBA::Boolean operator>>(TAO_InputCDR &, SaldoInsuficiente &);

TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<<(TAO_OutputCDR &, const Conta_ptr);
::CORBA::Boolean operator>>(TAO_InputCDR &, Conta_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
#include "ContaC.inl"
#endif

#endif
