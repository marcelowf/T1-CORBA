#include <iostream>
#include <fstream>
#include <string>
#include "ContaI.h"

using namespace std;
using namespace CORBA;
using namespace PortableServer;

ORB_var orb;

int main(int argc, char *argv[])
{
    try
    {
        orb = ORB_init(argc, argv, "ORB");

        Object_ptr tmp = orb->resolve_initial_references("RootPOA");
        POA_var poa = POA::_narrow(tmp);
        POAManager_var ger = poa->the_POAManager();
        ger->activate();

        Conta_i ci;

        Conta_var conta = ci._this();

        String_var ior = orb->object_to_string(conta.in());
        ofstream arq("conta.ior");
        arq << ior;
        arq.close();
        cout << "IOR salva: conta.ior\n";

        cout << "Aguardando requisicoes...\n";
        orb->run();

        poa->destroy(true, true);
        orb->destroy();
    }
    catch (const CORBA::Exception &e)
    {
        cerr << "Erro CORBA: " << e << endl;
    }
    return 0;
}
