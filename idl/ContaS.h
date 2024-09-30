#ifndef _TAO_IDL_CONTAS_ZA2THQ_H_
#define _TAO_IDL_CONTAS_ZA2THQ_H_

#include "ContaC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined(ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
#if !defined(_CONTA__SARG_TRAITS_)
#define _CONTA__SARG_TRAITS_

  template <>
  class SArg_Traits<::Conta>
      : public Object_SArg_Traits_T<
            ::Conta_ptr,
            ::Conta_var,
            ::Conta_out,
            TAO::Any_Insert_Policy_Stream>
  {
  };

#endif
}

TAO_END_VERSIONED_NAMESPACE_DECL

class POA_Conta;
typedef POA_Conta *POA_Conta_ptr;

class POA_Conta
    : public virtual PortableServer::ServantBase
{
protected:
  POA_Conta();

public:
  typedef ::Conta _stub_type;
  typedef ::Conta_ptr _stub_ptr_type;
  typedef ::Conta_var _stub_var_type;

  POA_Conta(const POA_Conta &rhs);
  virtual ~POA_Conta() = default;

  virtual ::CORBA::Boolean _is_a(const char *logical_type_id);

  virtual void _dispatch(
      TAO_ServerRequest &req,
      TAO::Portable_Server::Servant_Upcall *servant_upcall);

  ::Conta *_this();

  virtual const char *_interface_repository_id() const;

  virtual std::string id() = 0;

  static void _get_id_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);

  virtual ::CORBA::Float saldo() = 0;

  static void _get_saldo_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);

  virtual void deposito(
      ::CORBA::Float valor) = 0;

  static void deposito_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);

  virtual void saque(
      ::CORBA::Float valor) = 0;

  static void saque_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);

  virtual void transfere(
      ::CORBA::Float valor,
      ::Conta_ptr dest) = 0;

  static void transfere_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);

  virtual void shutdown(
      const std::string senha) = 0;

  static void shutdown_skel(
      TAO_ServerRequest &server_request,
      TAO::Portable_Server::Servant_Upcall *servant_upcall,
      TAO_ServantBase *servant);
};

#endif
