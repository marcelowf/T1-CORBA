//
// CLIENTE DE CONTA BANCÁRIA SIMPLES
//
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// (C) Prof. Luiz Lima Jr. (luiz.lima@pucpr.br)
//

#include <iostream>
#include <string>
#include <ContaC.h>

using namespace std;
using namespace CORBA;

int main(int argc, char* argv[])
{
    try {
	    // 1. Inicializa ORB
        ORB_var orb = ORB_init(argc, argv,"ORB");
	
        // 2. Obtém referência para objeto distirbuído (da IOR)
        Object_ptr obj = orb->string_to_object(argv[1]);
        Conta_var conta = Conta::_narrow(obj);
	
        // 3. Usa objeto (chama métodos)

        conta->deposito(123.);
        try {
            conta->saque(23.);
        } catch (const SaldoInsuficiente& ) {
            cerr << "Saldo insuficiente!\n";
        }
        cout << "saldo = " << conta->saldo() << endl;
	
        // 4. Finalizações
        orb->destroy();
    } catch (const CORBA::Exception& e) {
        cerr << "Erro CORBA: " << e << endl;
    }

	return 0;
}
