#include "ContaC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/SystemException.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "cstring"

#if !defined(__ACE_INLINE__)
#include "ContaC.inl"
#endif /* !defined INLINE */

SaldoInsuficiente::SaldoInsuficiente()
    : ::CORBA::UserException(
          "IDL:SaldoInsuficiente:1.0",
          "SaldoInsuficiente")
{
}

SaldoInsuficiente::SaldoInsuficiente(const ::SaldoInsuficiente &_tao_excp)
    : ::CORBA::UserException(
          _tao_excp._rep_id(),
          _tao_excp._name())
{
}

SaldoInsuficiente &
SaldoInsuficiente::operator=(const ::SaldoInsuficiente &_tao_excp)
{
  this->::CORBA::UserException::operator=(_tao_excp);
  return *this;
}

void SaldoInsuficiente::_tao_any_destructor(void *_tao_void_pointer)
{
  SaldoInsuficiente *_tao_tmp_pointer =
      static_cast<SaldoInsuficiente *>(_tao_void_pointer);
  delete _tao_tmp_pointer;
}

SaldoInsuficiente *
SaldoInsuficiente::_downcast(::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<SaldoInsuficiente *>(_tao_excp);
}

const SaldoInsuficiente *
SaldoInsuficiente::_downcast(::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const SaldoInsuficiente *>(_tao_excp);
}

::CORBA::Exception *SaldoInsuficiente::_alloc()
{
  ::CORBA::Exception *retval{};
  ACE_NEW_RETURN(retval, ::SaldoInsuficiente, nullptr);
  return retval;
}

::CORBA::Exception *
SaldoInsuficiente::_tao_duplicate() const
{
  ::CORBA::Exception *result{};
  ACE_NEW_RETURN(result, ::SaldoInsuficiente(*this), nullptr);
  return result;
}

void SaldoInsuficiente::_raise() const
{
  throw *this;
}

void SaldoInsuficiente::_tao_encode(TAO_OutputCDR &cdr) const
{
  if (!(cdr << *this))
  {
    throw ::CORBA::MARSHAL();
  }
}

void SaldoInsuficiente::_tao_decode(TAO_InputCDR &cdr)
{
  if (!(cdr >> *this))
  {
    throw ::CORBA::MARSHAL();
  }
}

::CORBA::TypeCode_ptr SaldoInsuficiente::_tao_type() const
{
  return ::_tc_SaldoInsuficiente;
}

static TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *const
    _tao_fields_SaldoInsuficiente = nullptr;

static TAO::TypeCode::Struct<
    char const *,
    ::CORBA::TypeCode_ptr const *,
    TAO::TypeCode::Struct_Field<
        char const *,
        ::CORBA::TypeCode_ptr const *> const *,
    TAO::Null_RefCount_Policy>
    _tao_tc_SaldoInsuficiente(
        ::CORBA::tk_except,
        "IDL:SaldoInsuficiente:1.0",
        "SaldoInsuficiente",
        _tao_fields_SaldoInsuficiente,
        0);

::CORBA::TypeCode_ptr const _tc_SaldoInsuficiente =
    &_tao_tc_SaldoInsuficiente;

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

Conta_ptr
TAO::Objref_Traits<Conta>::duplicate(Conta_ptr p)
{
  return Conta::_duplicate(p);
}

void TAO::Objref_Traits<Conta>::release(Conta_ptr p)
{
  ::CORBA::release(p);
}

Conta_ptr
TAO::Objref_Traits<Conta>::nil()
{
  return Conta::_nil();
}

::CORBA::Boolean
TAO::Objref_Traits<Conta>::marshal(const Conta_ptr p, TAO_OutputCDR &cdr)
{
  return ::CORBA::Object::marshal(p, cdr);
}

TAO_END_VERSIONED_NAMESPACE_DECL

std::string
Conta::id()
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<std::string>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval)};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      1,
      "_get_id",
      7,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false);

  _invocation_call.invoke(nullptr, 0);

  return _tao_retval.retn();
}

::CORBA::Float
Conta::saldo()
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<::CORBA::Float>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval)};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      1,
      "_get_saldo",
      10,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false);

  _invocation_call.invoke(nullptr, 0);

  return _tao_retval.retn();
}

void Conta::deposito(
    ::CORBA::Float valor)
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<::CORBA::Float>::in_arg_val _tao_valor(valor);

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval),
          std::addressof(_tao_valor)};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      2,
      "deposito",
      8,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY

  );

  _invocation_call.invoke(nullptr, 0);
}

void Conta::saque(
    ::CORBA::Float valor)
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<::CORBA::Float>::in_arg_val _tao_valor(valor);

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval),
          std::addressof(_tao_valor)};

  static TAO::Exception_Data
      _tao_Conta_saque_exceptiondata[] =
          {
              {"IDL:SaldoInsuficiente:1.0",
               SaldoInsuficiente::_alloc
#if TAO_HAS_INTERCEPTORS == 1
               ,
               _tc_SaldoInsuficiente
#endif /* TAO_HAS_INTERCEPTORS */
              }};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      2,
      "saque",
      5,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY

  );

  _invocation_call.invoke(
      _tao_Conta_saque_exceptiondata,
      1);
}

void Conta::transfere(
    ::CORBA::Float valor,
    ::Conta_ptr dest)
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<::CORBA::Float>::in_arg_val _tao_valor(valor);
  TAO::Arg_Traits<::Conta>::in_arg_val _tao_dest(dest);

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval),
          std::addressof(_tao_valor),
          std::addressof(_tao_dest)};

  static TAO::Exception_Data
      _tao_Conta_transfere_exceptiondata[] =
          {
              {"IDL:SaldoInsuficiente:1.0",
               SaldoInsuficiente::_alloc
#if TAO_HAS_INTERCEPTORS == 1
               ,
               _tc_SaldoInsuficiente
#endif /* TAO_HAS_INTERCEPTORS */
              }};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      3,
      "transfere",
      9,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY

  );

  _invocation_call.invoke(
      _tao_Conta_transfere_exceptiondata,
      1);
}

void Conta::shutdown(
    const std::string senha)
{
  if (!this->is_evaluated())
  {
    ::CORBA::Object::tao_object_initialize(this);
  }

  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<std::string>::in_arg_val _tao_senha(senha);

  TAO::Argument *_the_tao_operation_signature[] =
      {
          std::addressof(_tao_retval),
          std::addressof(_tao_senha)};

  TAO::Invocation_Adapter _invocation_call(
      this,
      _the_tao_operation_signature,
      2,
      "shutdown",
      8,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_ONEWAY_INVOCATION

  );

  _invocation_call.invoke(nullptr, 0);
}

Conta::Conta()
{
}
void Conta::_tao_any_destructor(void *_tao_void_pointer)
{
  Conta *_tao_tmp_pointer =
      static_cast<Conta *>(_tao_void_pointer);
  ::CORBA::release(_tao_tmp_pointer);
}

Conta_ptr
Conta::_narrow(::CORBA::Object_ptr _tao_objref)
{
  return TAO::Narrow_Utils<Conta>::narrow(_tao_objref, "IDL:Conta:1.0");
}

Conta_ptr
Conta::_unchecked_narrow(::CORBA::Object_ptr _tao_objref)
{
  return TAO::Narrow_Utils<Conta>::unchecked_narrow(_tao_objref);
}

Conta_ptr
Conta::_nil()
{
  return nullptr;
}

Conta_ptr
Conta::_duplicate(Conta_ptr obj)
{
  if (!::CORBA::is_nil(obj))
  {
    obj->_add_ref();
  }
  return obj;
}

void Conta::_tao_release(Conta_ptr obj)
{
  ::CORBA::release(obj);
}

::CORBA::Boolean
Conta::_is_a(const char *value)
{
  if (
      std::strcmp(value, "IDL:Conta:1.0") == 0 ||
      std::strcmp(value, "IDL:omg.org/CORBA/Object:1.0") == 0)
  {
    return true;
  }
  else
  {
    return this->::CORBA::Object::_is_a(value);
  }
}

const char *Conta::_interface_repository_id() const
{
  return "IDL:Conta:1.0";
}

::CORBA::Boolean
Conta::marshal(TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
    _tao_tc_Conta(
        ::CORBA::tk_objref,
        "IDL:Conta:1.0",
        "Conta");

::CORBA::TypeCode_ptr const _tc_Conta =
    &_tao_tc_Conta;

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  template <>
  ::CORBA::Boolean
  Any_Dual_Impl_T<SaldoInsuficiente>::demarshal_value(TAO_InputCDR &cdr)
  {
    ::CORBA::String_var id;

    if (!(cdr >> id.out()))
    {
      return false;
    }

    try
    {
      this->value_->_tao_decode(cdr);
    }
    catch (const ::CORBA::Exception &)
    {
      return false;
    }

    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA
{

  void operator<<=(
      ::CORBA::Any &_tao_any,
      const SaldoInsuficiente &_tao_elem)
  {
    TAO::Any_Dual_Impl_T<SaldoInsuficiente>::insert_copy(
        _tao_any,
        SaldoInsuficiente::_tao_any_destructor,
        _tc_SaldoInsuficiente,
        _tao_elem);
  }

  void operator<<=(
      ::CORBA::Any &_tao_any,
      SaldoInsuficiente *_tao_elem)
  {
    TAO::Any_Dual_Impl_T<SaldoInsuficiente>::insert(
        _tao_any,
        SaldoInsuficiente::_tao_any_destructor,
        _tc_SaldoInsuficiente,
        _tao_elem);
  }

  ::CORBA::Boolean operator>>=(
      const ::CORBA::Any &_tao_any,
      const SaldoInsuficiente *&_tao_elem)
  {
    return TAO::Any_Dual_Impl_T<SaldoInsuficiente>::extract(
        _tao_any,
        SaldoInsuficiente::_tao_any_destructor,
        _tc_SaldoInsuficiente,
        _tao_elem);
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  template <>
  ::CORBA::Boolean
  Any_Impl_T<Conta>::to_object(
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate(this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA
{

  void
  operator<<=(
      ::CORBA::Any &_tao_any,
      Conta_ptr _tao_elem)
  {
    Conta_ptr _tao_objptr =
        Conta::_duplicate(_tao_elem);
    _tao_any <<= std::addressof(_tao_objptr);
  }

  void
  operator<<=(
      ::CORBA::Any &_tao_any,
      Conta_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<Conta>::insert(
        _tao_any,
        Conta::_tao_any_destructor,
        _tc_Conta,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>=(
      const ::CORBA::Any &_tao_any,
      Conta_ptr &_tao_elem)
  {
    return TAO::Any_Impl_T<Conta>::extract(
        _tao_any,
        Conta::_tao_any_destructor,
        _tc_Conta,
        _tao_elem);
  }

}
TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<<(
    TAO_OutputCDR &strm,
    const SaldoInsuficiente &_tao_aggregate)
{

  return (strm << _tao_aggregate._rep_id());
}

::CORBA::Boolean operator>>(
    TAO_InputCDR &,
    SaldoInsuficiente &)
{
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<<(
    TAO_OutputCDR &strm,
    const Conta_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>>(
    TAO_InputCDR &strm,
    Conta_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout()))
  {
    return false;
  }

  _tao_objref = TAO::Narrow_Utils<::Conta>::unchecked_narrow(obj.in());

  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL
