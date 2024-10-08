#ifndef _TAO_IDL_CONTAS_ZA2THQ_CPP_
#define _TAO_IDL_CONTAS_ZA2THQ_CPP_

#include "ContaS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"
#include "cstring"

class TAO_Conta_Perfect_Hash_OpTable
    : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash(const char *str, unsigned int len) override;

public:
  const TAO_operation_db_entry *lookup(const char *str, unsigned int len) override;
};

unsigned int
TAO_Conta_Perfect_Hash_OpTable::hash(const char *str, unsigned int len)
{
  static constexpr unsigned char asso_values[] =
      {
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          0,
          29,
          0,
          29,
          29,
          5,
          5,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          5,
          10,
          29,
          29,
          29,
          15,
          0,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
          29,
      };
  return len + asso_values[static_cast<int>(str[len - 1])] + asso_values[static_cast<int>(str[0])];
}

const TAO_operation_db_entry *
TAO_Conta_Perfect_Hash_OpTable::lookup(const char *str, unsigned int len)
{
  enum
  {
    TOTAL_KEYWORDS = 11,
    MIN_WORD_LENGTH = 5,
    MAX_WORD_LENGTH = 14,
    MIN_HASH_VALUE = 5,
    MAX_HASH_VALUE = 28,
    HASH_VALUE_RANGE = 24,
    DUPLICATES = 0,
    WORDLIST_SIZE = 16
  };

  static const TAO_operation_db_entry wordlist[] =
      {
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"_is_a", std::addressof(TAO_ServantBase::_is_a_thru_poa_skel), nullptr},
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"_component", std::addressof(TAO_ServantBase::_component_thru_poa_skel), nullptr},
          {"", 0, 0},
          {"_get_id", std::addressof(POA_Conta::_get_id_skel), 0},
          {"_non_existent", std::addressof(TAO_ServantBase::_non_existent_thru_poa_skel), nullptr},
          {"transfere", std::addressof(POA_Conta::transfere_skel), nullptr},
          {"_interface", std::addressof(TAO_ServantBase::_interface_skel), nullptr},
          {"", 0, 0},
          {"", 0, 0},
          {"", 0, 0},
          {"_repository_id", std::addressof(TAO_ServantBase::_repository_id_thru_poa_skel), nullptr},
          {"_get_saldo", std::addressof(POA_Conta::_get_saldo_skel), 0},
          {"", 0, 0},
          {"", 0, 0},
          {"deposito", std::addressof(POA_Conta::deposito_skel), nullptr},
          {"", 0, 0},
          {"saque", std::addressof(POA_Conta::saque_skel), nullptr},
          {"", 0, 0},
          {"", 0, 0},
          {"shutdown", std::addressof(POA_Conta::shutdown_skel), nullptr},
      };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
  {
    unsigned int const key = hash(str, len);

    if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
    {
      const char *s = wordlist[key].opname;

      if (*str == *s && !ACE_OS::strncmp(str + 1, s + 1, len - 1))
        return &wordlist[key];
    }
  }
  return 0;
}

static TAO_Conta_Perfect_Hash_OpTable tao_Conta_optable;

POA_Conta::POA_Conta()
    : TAO_ServantBase()
{
  this->optable_ = std::addressof(tao_Conta_optable);
}

POA_Conta::POA_Conta(const POA_Conta &rhs)
    : TAO_Abstract_ServantBase(rhs),
      TAO_ServantBase(rhs)
{
}

class _get_id_Conta
    : public TAO::Upcall_Command
{
public:
  inline _get_id_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<std::string>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg<std::string>(
            this->operation_details_,
            this->args_);

    retval =
        this->servant_->id();
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::_get_id_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
  TAO::SArg_Traits<std::string>::ret_val retval;

  TAO::Argument *const args[] =
      {
          std::addressof(retval)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  _get_id_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 1, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, nullptr, 0
#endif
  );
}

class _get_saldo_Conta
    : public TAO::Upcall_Command
{
public:
  inline _get_saldo_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<::CORBA::Float>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg<::CORBA::Float>(
            this->operation_details_,
            this->args_);

    retval =
        this->servant_->saldo();
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::_get_saldo_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
  TAO::SArg_Traits<::CORBA::Float>::ret_val retval;

  TAO::Argument *const args[] =
      {
          std::addressof(retval)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  _get_saldo_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 1, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, nullptr, 0
#endif
  );
}

class deposito_Conta
    : public TAO::Upcall_Command
{
public:
  inline deposito_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<::CORBA::Float>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg<::CORBA::Float>(
            this->operation_details_,
            this->args_,
            1);

    this->servant_->deposito(
        arg_1);
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::deposito_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
  TAO::SArg_Traits<void>::ret_val retval;
  TAO::SArg_Traits<::CORBA::Float>::in_arg_val _tao_valor;

  TAO::Argument *const args[] =
      {
          std::addressof(retval),
          std::addressof(_tao_valor)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  deposito_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 2, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, nullptr, 0
#endif
  );
}

class saque_Conta
    : public TAO::Upcall_Command
{
public:
  inline saque_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<::CORBA::Float>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg<::CORBA::Float>(
            this->operation_details_,
            this->args_,
            1);

    this->servant_->saque(
        arg_1);
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::saque_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] =
      {
          _tc_SaldoInsuficiente};

#endif

  TAO::SArg_Traits<void>::ret_val retval;
  TAO::SArg_Traits<::CORBA::Float>::in_arg_val _tao_valor;

  TAO::Argument *const args[] =
      {
          std::addressof(retval),
          std::addressof(_tao_valor)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  saque_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 2, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, exceptions, 1
#endif
  );
}

class transfere_Conta
    : public TAO::Upcall_Command
{
public:
  inline transfere_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<::CORBA::Float>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg<::CORBA::Float>(
            this->operation_details_,
            this->args_,
            1);

    TAO::SArg_Traits<::Conta>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg<::Conta>(
            this->operation_details_,
            this->args_,
            2);

    this->servant_->transfere(
        arg_1, arg_2);
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::transfere_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] =
      {
          _tc_SaldoInsuficiente};

#endif

  TAO::SArg_Traits<void>::ret_val retval;
  TAO::SArg_Traits<::CORBA::Float>::in_arg_val _tao_valor;
  TAO::SArg_Traits<::Conta>::in_arg_val _tao_dest;

  TAO::Argument *const args[] =
      {
          std::addressof(retval),
          std::addressof(_tao_valor),
          std::addressof(_tao_dest)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  transfere_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 3, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, exceptions, 1
#endif
  );
}

class shutdown_Conta
    : public TAO::Upcall_Command
{
public:
  inline shutdown_Conta(
      POA_Conta *servant,
      TAO_Operation_Details const *operation_details,
      TAO::Argument *const args[])
      : servant_(servant), operation_details_(operation_details), args_(args)
  {
  }

  void execute() override
  {
    TAO::SArg_Traits<std::string>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg<std::string>(
            this->operation_details_,
            this->args_,
            1);

    this->servant_->shutdown(
        arg_1);
  }

private:
  POA_Conta *const servant_;
  TAO_Operation_Details const *const operation_details_;
  TAO::Argument *const *const args_;
};

void POA_Conta::shutdown_skel(
    TAO_ServerRequest &server_request,
    TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR(servant_upcall),
    TAO_ServantBase *servant)
{
  TAO::SArg_Traits<void>::ret_val retval;
  TAO::SArg_Traits<std::string>::in_arg_val _tao_senha;

  TAO::Argument *const args[] =
      {
          std::addressof(retval),
          std::addressof(_tao_senha)};

  POA_Conta *const impl =
      dynamic_cast<POA_Conta *>(servant);

  if (!impl)
  {
    throw ::CORBA::INTERNAL();
  }

  shutdown_Conta command(
      impl,
      server_request.operation_details(),
      args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall(server_request, args, 2, command
#if TAO_HAS_INTERCEPTORS == 1
                        ,
                        servant_upcall, nullptr, 0
#endif
  );
}

::CORBA::Boolean POA_Conta::_is_a(const char *value)
{
  return (
      std::strcmp(value, "IDL:Conta:1.0") == 0 ||
      std::strcmp(value, "IDL:omg.org/CORBA/Object:1.0") == 0);
}

const char *POA_Conta::_interface_repository_id() const
{
  return "IDL:Conta:1.0";
}

void POA_Conta::_dispatch(
    TAO_ServerRequest &req,
    TAO::Portable_Server::Servant_Upcall *servant_upcall)
{
  this->synchronous_upcall_dispatch(req, servant_upcall, this);
}

Conta *
POA_Conta::_this()
{
  TAO_Stub_Auto_Ptr stub(this->_create_stub());
  ::CORBA::Boolean const _tao_opt_colloc = stub->servant_orb_var()->orb_core()->optimize_collocation_objects();
  ::CORBA::Object_var obj = new (std::nothrow)::CORBA::Object(stub.get(), _tao_opt_colloc, this);
  if (obj.ptr())
  {
    (void)stub.release();
    return TAO::Narrow_Utils<::Conta>::unchecked_narrow(obj.in());
  }
  return {};
}

#endif
