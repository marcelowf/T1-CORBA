//
// SERVIDOR DE CONTA SIMPLES
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// (C) Prof. Luiz Lima Jr. (luiz.lima@pucpr.br)
//

#include <iostream>
#include <fstream>
#include <string>
#include "ContaI.h"

using namespace std;
using namespace CORBA;
using namespace PortableServer;

ORB_var orb; // global para ser usado na classe Conta_i para shutdown

int main(int argc, char* argv[])
{
    try {
	    // 1. Inicia ORB
        orb = ORB_init(argc, argv, "ORB");
	
        // 2. Ativa RootPOA
        Object_ptr tmp = orb->resolve_initial_references("RootPOA");
        POA_var poa = POA::_narrow(tmp);
        POAManager_var ger = poa->the_POAManager();
        ger->activate();
	
        // 3. Instancia "servants"
        Conta_i ci;
	
        // 4. Registra servos no POA, criando objetos distribuídos
        Conta_var conta = ci._this();
	
        // 5. Publica IOR
        String_var ior = orb->object_to_string(conta.in());
        ofstream arq("conta.ior");
        arq << ior;
        arq.close();
        cout << "IOR salva: conta.ior\n";
	
        // 6. Aguarda requisições
        cout << "Aguardando requisicoes...\n"; 
        orb->run();
	
        // 7. Finalizações
        poa->destroy(true, true);
        orb->destroy();
    } catch (const CORBA::Exception& e) {
        cerr << "Erro CORBA: " << e << endl;
    }
    return 0;
}
