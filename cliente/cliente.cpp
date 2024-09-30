#include <iostream>
#include <string>
#include <ContaC.h>

using namespace std;
using namespace CORBA;

int main(int argc, char *argv[])
{
    try
    {

        ORB_var orb = ORB_init(argc, argv, "ORB");

        Object_ptr obj = orb->string_to_object(argv[1]);
        Conta_var conta = Conta::_narrow(obj);

        conta->deposito(123.);
        try
        {
            conta->saque(23.);
        }
        catch (const SaldoInsuficiente &)
        {
            cerr << "Saldo insuficiente!\n";
        }
        cout << "saldo = " << conta->saldo() << endl;

        orb->destroy();
    }
    catch (const CORBA::Exception &e)
    {
        cerr << "Erro CORBA: " << e << endl;
    }

    return 0;
}
