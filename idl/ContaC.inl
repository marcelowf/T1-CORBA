ACE_INLINE
Conta::Conta(
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
    : ::CORBA::Object(objref, _tao_collocated, servant, oc)
{
}

ACE_INLINE
Conta::Conta(
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
    : ::CORBA::Object(ior, oc)
{
}
