//---------------------------------------------------------------------------
#ifndef ModelH
#define ModelH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include "Conector.h"
#include "Class.h"
#include "Inheritance.h"
#include "Dependency.h"
#include "orderReport.h"
#include<stdio.h>

class Model // : public Element
{
private:	// User declarations
     AnsiString name;
     int *LCOTI; //Lista de Classe Ordenada para Teste de Integracao
     int *FI;
     int numClass;
     int numConector;
     int numHeranca;
     int numDependency;
     int tClass;
     int tConector;
     int tHeranca;
     int tDependency;
     int **MatrizInfluencia;
     Dependency **lstDependency;
     Inheritance **lstHeranca;
     Conector **lstConector;
     Class **lstClass;
     int classInt;
     int NumStubsOriginal;
     int NumStubsAtual;
     int ComplexidadeOriginal;
     int ComplexidadeAtual;


public:		// User declarations
     Model();
     Model(AnsiString nam);
     Model(AnsiString nam, int numClasse, int numAssociacao, int numHer, int numDependencia);
     void setName(AnsiString nam);
     AnsiString getName();
     void setNumClass(int num);
     void setNumConector(int num);
     void setNumInheritance(int num);
     void setNumDependency(int num);
     int  getNumClass();
     int  getNumConector();
     int  getNumInheritance();
     int  getNumDependency();
     void addClass(AnsiString name, AnsiString Id, AnsiString isAbst);
     void addConector(AnsiString name, AnsiString Id, AnsiString tpConector);
     void addInheritance(AnsiString name, AnsiString Id, AnsiString pai, AnsiString filho);
     void addDependency(AnsiString name, AnsiString Id, AnsiString sup, AnsiString child);
     void alocarListas();
     void gerarTreeView(AnsiString nameModel);
     void inicializaTabela();
     Conector * getConectorAtual();
     Class * getClassAtual();
     Conector * getConector(int ind);
     Class * getClass(int ind);
     Class ** getClasses();
     Inheritance * getInheritance(int ind);
     Dependency * getDependency(int ind);
     Class * buscaClasse(AnsiString ID,Class *lista[],int nElem);
     Class * buscaContClasse(int ID,Class *lista[],int nElem);
     void mostrarClasses();
     void calcularFI();
     int  calcularStubs();
     int  calcularComplexidade();     
     void  saidaStubs(_di_IReportIntegrationTestType outputXML);     
     int  marcarFInulo(int *LClasseInteg,int *ListaUltimos);
     void deadLockCaso3(int Num,int *Classes);
     int  deadLockCaso2(int Num,int numStubs,int *Classes,int *Integradas);
     void resolverDeadlock(int Num,int *Classes,int *Integradas);
     void ordemIntegrar();
     int * getOrdemSaida();
     int  getOrdemClass(int ind);
     void setOrdemClass(int ind, int val);
     int  getNumStubsOriginal();
     void setNumStubsOriginal(int num);
     int  getNumStubsAtual();
     void setNumStubsAtual(int num);
     int  getComplexidadeOriginal();
     void setComplexidadeOriginal(int num);
     int  getComplexidadeAtual();
     void setComplexidadeAtual(int num);
     void ordenarClasses();     
};
//---------------------------------------------------------------------------
extern Model *_model;
//---------------------------------------------------------------------------
#endif