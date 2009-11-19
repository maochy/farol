//---------------------------------------------------------------------------
#include <string.h>
#pragma hdrstop

#include "Modelo.h"
#include "Principal.h"
//---------------------------------------------------------------------------
Model *_modelo;
//---------------------------------------------------------------------------
Model::Model(AnsiString nam)
{
 name=nam;
 numClass=0;
 numConector=0;
 numHeranca=0;
 numDependency=0;
 tClass=0;
 tConector=0;
 tHeranca=0;
 tDependency=0;
 classInt=0;
}
//---------------------------------------------------------------------------
Model::Model(AnsiString nam, int numClasse, int numAssociacao, int numHer, int numDependencia)
{
 name=nam;
 numClass=numClasse;
 numConector=numAssociacao;
 numHeranca=numHer;
 numDependency=numDependencia;
 tClass=0;
 tConector=0;
 tHeranca=0;
 tDependency=0;
 classInt=0;
}
//---------------------------------------------------------------------------
void Model::setName(AnsiString nam)
{
 name=nam;
}
//---------------------------------------------------------------------------
AnsiString Model::getName()
{
 return name;
}
//---------------------------------------------------------------------------
void Model::setNumClass(int num)
{
 numClass=num;
}
//---------------------------------------------------------------------------
int Model::getNumClass()
{
 return numClass;
}
//---------------------------------------------------------------------------
void Model::setNumConector(int num)
{
 numConector=num;
}
//---------------------------------------------------------------------------
int Model::getNumConector()
{
 return numConector;
}
//---------------------------------------------------------------------------
void Model::setNumInheritance(int num)
{
 numHeranca=num;
}
//---------------------------------------------------------------------------
int Model::getNumInheritance()
{
 return numHeranca;
}
//---------------------------------------------------------------------------
void Model::setNumDependency(int num)
{
 numDependency=num;
}
//---------------------------------------------------------------------------
int Model::getNumDependency()
{
 return numDependency;
}
//---------------------------------------------------------------------------
void Model::addClass(AnsiString nam,AnsiString Id, AnsiString isAbst)
{
 lstClass[tClass] = new Class(nam,Id,isAbst,tClass);
 tClass++;
}
//---------------------------------------------------------------------------
void Model::addConector(AnsiString nam,AnsiString Id,AnsiString tpCon)
{
 lstConector[tConector] = new Conector(nam,Id,tpCon);
 tConector++;
}
//---------------------------------------------------------------------------
void Model::addInheritance(AnsiString nam,AnsiString Id,AnsiString pai,AnsiString filho)
{
 lstHeranca[tHeranca] = new Inheritance(nam,Id,pai,filho);
 tHeranca++;
}
//---------------------------------------------------------------------------
void Model::addDependency(AnsiString nam,AnsiString Id,AnsiString sup,AnsiString child)
{
 lstDependency[tDependency] = new Dependency(nam,Id,sup,child);
 tDependency++;
}
//---------------------------------------------------------------------------
void Model::alocarListas()
{
        lstClass = (Class **) malloc(sizeof(Class *)*numClass);
        lstConector = (Conector **) malloc(sizeof(Conector *)*numConector);
        lstHeranca = (Inheritance **) malloc(sizeof(Inheritance *)*numHeranca);
        lstDependency = (Dependency **) malloc(sizeof(Dependency *)*numDependency);
        LCOTI = (int *) malloc(sizeof(int)*numClass);
        FI = (int *) malloc(sizeof(int)*numClass);
}
//---------------------------------------------------------------------------
Conector * Model::getConectorAtual()
{
 return(lstConector[tConector-1]);
}
//---------------------------------------------------------------------------
Class * Model::getClassAtual()
{
 return(lstClass[tClass-1]);
}
//---------------------------------------------------------------------------
Conector * Model::getConector(int ind)
{
 return(lstConector[ind]);
}
//---------------------------------------------------------------------------
Class * Model::getClass(int ind)
{
 return(lstClass[ind]);
}
//---------------------------------------------------------------------------
Class ** Model::getClasses()
{
 return(lstClass);
}
//---------------------------------------------------------------------------
Inheritance * Model::getInheritance(int ind)
{
 return(lstHeranca[ind]);
}
//---------------------------------------------------------------------------
Dependency * Model::getDependency(int ind)
{
 return(lstDependency[ind]);
}
//---------------------------------------------------------------------------
void Model::gerarTreeView(AnsiString nameModel){
        TTreeNode *Raiz,*Filho,*Node;
        Class *classe,*classe2;
        MatrizInfluencia=(int**)malloc(sizeof(int*)*(numClass));
        inicializaTabela();
        FOrdenador->TreeXML->Items->Add(FOrdenador->TreeXML->Items->GetFirstNode(),FOrdenador->getTag("MODELO")+nameModel);
        Raiz=FOrdenador->TreeXML->Items->GetFirstNode();
        Raiz->ImageIndex = 7;
        Raiz->SelectedIndex = 7;
        Filho=FOrdenador->TreeXML->Items->AddChild(Raiz,FOrdenador->getTag("ASSOCIACOES"));
        Raiz->Expand(true);
        Filho->ImageIndex = 5;
        Filho->SelectedIndex = 5;
        for(int i=0;i<numConector;i++){
                if(lstConector[i]->isAssociation()){
                        classe=buscaClasse(lstConector[i]->getStartClass(),lstClass,numClass);
                        classe->setCountConector(classe->getCountConector()+1);
                        classe2=buscaClasse(lstConector[i]->getEndClass(),lstClass,numClass);
                        classe2->setCountConector(classe2->getCountConector()+1);
                        if(lstConector[i]->getNavStart()==lstConector[i]->getNavEnd()){
                                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("ASSOCIACAO")+classe->getName()+" -- "+classe2->getName()+":"+lstConector[i]->getName());
                                classe->setFatorInfluencia(classe->getFatorInfluencia()+(1-MatrizInfluencia[classe->getContador()][classe2->getContador()]));
                                classe2->setFatorInfluencia(classe2->getFatorInfluencia()+(1-MatrizInfluencia[classe2->getContador()][classe->getContador()]));
                                MatrizInfluencia[classe->getContador()][classe2->getContador()]=1;
                                MatrizInfluencia[classe2->getContador()][classe->getContador()]=1;
                        }
                        else if(lstConector[i]->getNavStart()=="true"){
                                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("ASSOCIACAO")+classe2->getName()+" -> "+classe->getName()+":"+lstConector[i]->getName());
                                classe->setFatorInfluencia(classe->getFatorInfluencia()+(1-MatrizInfluencia[classe->getContador()][classe2->getContador()]));
                                MatrizInfluencia[classe->getContador()][classe2->getContador()]=1;
                        }
                        else{
                                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("ASSOCIACAO")+classe->getName()+" -> "+classe2->getName()+":"+lstConector[i]->getName());
                                classe2->setFatorInfluencia(classe2->getFatorInfluencia()+(1-MatrizInfluencia[classe2->getContador()][classe->getContador()]));
                                MatrizInfluencia[classe2->getContador()][classe->getContador()]=1;
                        }
                        Node->ImageIndex = 6;
                        Node->SelectedIndex = 6;
                        FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("ORIGEM")+classe->getName()+FOrdenador->getTag("NAVEGAVEL")+lstConector[i]->getNavStart());
                        FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("DESTINO")+classe2->getName()+FOrdenador->getTag("NAVEGAVEL")+lstConector[i]->getNavEnd());

                }
        }
        Filho=FOrdenador->TreeXML->Items->AddChild(Raiz,FOrdenador->getTag("COMPOSICAO"));
        Filho->ImageIndex = 4;
        Filho->SelectedIndex = 4;
        for(int i=0;i<numConector;i++){
                if(lstConector[i]->isAggregation()){
                        classe=buscaClasse(lstConector[i]->getStartClass(),lstClass,numClass);
                        classe->setCountConector(classe->getCountConector()+1);
                        classe2=buscaClasse(lstConector[i]->getEndClass(),lstClass,numClass);
                        classe2->setCountConector(classe2->getCountConector()+1);
                        Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("COMPOSICAO")+": "+classe2->getName()+" <>-- "+classe->getName()+":"+lstConector[i]->getName());
                        Node->ImageIndex = 6;
                        Node->SelectedIndex = 6;
                        FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("PARTE")+classe->getName());
                        classe->setFatorInfluencia(classe->getFatorInfluencia()+(1-MatrizInfluencia[classe->getContador()][classe2->getContador()]));
                        FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("TODO")+classe2->getName());
                        MatrizInfluencia[classe->getContador()][classe2->getContador()]=1;
                }
        }
        Filho=FOrdenador->TreeXML->Items->AddChild(Raiz,FOrdenador->getTag("HERANCAS"));
        Filho->ImageIndex = 3;
        Filho->SelectedIndex = 3;
        for(int i=0;i<numHeranca;i++){
                classe=buscaClasse(lstHeranca[i]->getParentClass(),lstClass,numClass);
                classe->setCountConector(classe->getCountConector()+1);
                classe2=buscaClasse(lstHeranca[i]->getChildClass(),lstClass,numClass);
                classe2->setCountConector(classe2->getCountConector()+1);
                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("HERANCA")+classe->getName()+" <|-- "+classe2->getName()+":"+lstHeranca[i]->getName());
                Node->ImageIndex = 6;
                Node->SelectedIndex = 6;
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("PAI")+classe->getName());
                classe->setFatorInfluencia(classe->getFatorInfluencia()+(1-MatrizInfluencia[classe->getContador()][classe2->getContador()]));
                MatrizInfluencia[classe->getContador()][classe2->getContador()]=1;
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("FILHO")+classe2->getName());
        }
        Filho=FOrdenador->TreeXML->Items->AddChild(Raiz,FOrdenador->getTag("DEPENDENCIAS"));
        Filho->ImageIndex = 2;
        Filho->SelectedIndex = 2;
        for(int i=0;i<numDependency;i++){
                classe=buscaClasse(lstDependency[i]->getSupplierClass(),lstClass,numClass);
                classe->setCountConector(classe->getCountConector()+1);
                classe2=buscaClasse(lstDependency[i]->getClientClass(),lstClass,numClass);
                classe->setFatorInfluencia(classe->getFatorInfluencia()+(1-MatrizInfluencia[classe->getContador()][classe2->getContador()]));
                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("DEPENDENCIA")+classe->getName()+" <-- "+classe2->getName()+":"+lstDependency[i]->getName());
                Node->ImageIndex = 6;
                Node->SelectedIndex = 6;
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("CLIENTE")+classe->getName());
                classe2->setCountConector(classe2->getCountConector()+1);
                MatrizInfluencia[classe->getContador()][classe2->getContador()]=1;
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("FORNECEDOR")+classe2->getName());
        }
        Filho->ImageIndex = 2;

        Filho=FOrdenador->TreeXML->Items->AddChildFirst(Raiz,FOrdenador->getTag("CLASSES"));
        Filho->ImageIndex = 1;
        Filho->SelectedIndex = 1;

        for(int i=0;i<numClass;i++){
                Node=FOrdenador->TreeXML->Items->AddChild(Filho,FOrdenador->getTag("CLASSE")+lstClass[i]->getName());
                Node->ImageIndex = 6;
                Node->SelectedIndex = 6;
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("FATORINF")+IntToStr(lstClass[i]->getFatorInfluencia()));
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("TAMANHO")+": "+IntToStr(lstClass[i]->getTamanho()));
                FOrdenador->TreeXML->Items->AddChild(Node,FOrdenador->getTag("NUMEROCONECTOR")+IntToStr(lstClass[i]->getCountConector()));
        }
}
//---------------------------------------------------------------------------
void Model::inicializaTabela(){
        for(int i=0;i<numClass;i++){
                MatrizInfluencia[i]= (int*) malloc(sizeof(int)*(numClass));
                for(int j=0; j<numClass; j++)
                        MatrizInfluencia[i][j]=0;
        }
}

//---------------------------------------------------------------------------
Class * Model::buscaClasse(AnsiString ID,Class *lista[],int nElem){
        bool achou=false;
        int cont=0;
        while(cont<nElem && !achou){
                if(ID==lista[cont]->getIdRef())
                        achou=true;
                cont++;
        }
        return lista[cont-1];
}
//---------------------------------------------------------------------------
Class * Model::buscaContClasse(int ID,Class *lista[],int nElem){
        bool achou=false;
        int cont=0;
        while(cont<nElem && !achou){
                if(ID==lista[cont]->getContador())
                        achou=true;
                cont++;
        }
        return lista[cont-1];
}

//---------------------------------------------------------------------------
void Model:: mostrarClasses(){
        FOrdenador->Iteracao->RowCount=numClass+1;
        FOrdenador->Iteracao->Cells[0][0]=FOrdenador->getTag("CLASSEITERACAO");
        for(int i=0;i<numClass;i++){
                FOrdenador->Iteracao->Cells[0][i+1]=lstClass[i]->getName();
        }
}
//---------------------------------------------------------------------------
void Model::calcularFI(){
  FOrdenador->Iteracao->ColCount=2;
  FOrdenador->Iteracao->Cells[1][0]=FOrdenador->getTag("VALORFI");
  for(int i=0;i<numClass;i++){
      FI[i]=0;
    for(int j=0;j<numClass;j++){
      FI[i]+=MatrizInfluencia[i][j];
    }
    FOrdenador->Iteracao->Cells[1][i+1]=IntToStr(FI[i]);
  }
}
//---------------------------------------------------------------------------
int Model::calcularStubs(){
  int *Integrar=(int*)malloc(sizeof(int)*numClass);
  int Resp=0;
  for(int i=0;i<numClass;i++) Integrar[i]=0;

  for(int i=0;i<numClass;i++){
        for(int j=0;j<numClass;j++){
              if(!Integrar[j])
                Resp+=MatrizInfluencia[j][LCOTI[i]];
        }
        Integrar[LCOTI[i]]=1;
  }
  return Resp;
}
//---------------------------------------------------------------------------
int Model::calcularComplexidade(){
  int *Integrar=(int*)malloc(sizeof(int)*numClass);
  int Resp=0;
  for(int i=0;i<numClass;i++) Integrar[i]=0;

  for(int i=0;i<numClass;i++){
        for(int j=0;j<numClass;j++){
              if(!Integrar[j])
                Resp+=(MatrizInfluencia[j][LCOTI[i]]*lstClass[j]->getTamanho());
        }
        Integrar[LCOTI[i]]=1;
  }
  return Resp;
}
//---------------------------------------------------------------------------
void Model::saidaStubs(_di_IReportIntegrationTestType outputXML){
  int *Integrar=(int*)malloc(sizeof(int)*numClass);
  int *TotStubs=(int*)malloc(sizeof(int)*numClass);
  int *S=(int*)malloc(sizeof(int)*numClass);
  int  stubs;
  for(int i=0;i<numClass;i++){
        Integrar[i]=0;
        TotStubs[i]=0;
  }

  for(int i=0;i<numClass;i++){
        stubs=0;
        for(int j=0;j<numClass;j++){
              if(!Integrar[j]){
                TotStubs[i]+=MatrizInfluencia[j][LCOTI[i]];
                if(MatrizInfluencia[j][LCOTI[i]]==1){
                        S[stubs]=j;
                        stubs++;
                }
              }
        }
        outputXML->Result->Order->Add();
        outputXML->Result->Order->Get_Class(i)->Set_name(lstClass[LCOTI[i]]->getName());
        outputXML->Result->Order->Get_Class(i)->Set_stubs(TotStubs[i]);
        for(int j=0;j<stubs;j++){
                outputXML->Result->Order->Get_Class(i)->Add();
                outputXML->Result->Order->Get_Class(i)->Get_Stubs(j)->Set_name(lstClass[S[j]]->getName());
        }
        Integrar[LCOTI[i]]=1;
  }
}

/************************ Funcao que marca as classes que possuem FI nulo ***********************/
int Model::marcarFInulo(int *LCOTI,int *ListaUltimos){
  int cont=0;
  //LCOTI = Lista de Classes Ordenadas Integradas
  for(int i=0;i<numClass;i++){
    if(!FI[i]){
    	LCOTI[i]=1;
	ListaUltimos[cont]=i;
	cont++;
    }
  }
  return cont;
}

/*************************** Procedimento que busca resolver Deadlock ***************************/
void Model::deadLockCaso3(int Num,int *Classes){
  int *Tamanho=(int*)malloc(sizeof(int)*Num);

  for(int i=0;i<Num;i++){
        Tamanho[i]=buscaContClasse(Classes[i],lstClass,numClass)->getTamanho();
  }

  for(int i=0;i<Num-1;i++)
        for(int j=i+1;j<Num;j++)
                if(Tamanho[i]>Tamanho[j]){
                        int aux=Tamanho[i];
                        Tamanho[i]=Tamanho[j];
                        Tamanho[j]=aux;
                        aux=Classes[i];
                        Classes[i]=Classes[j];
                        Classes[j]=aux;
                }

  for(int i=0;i<Num;i++){
        LCOTI[classInt]=Classes[i];
        classInt++;
  }
}
/*************************** Procedimento que busca resolver Deadlock ***************************/
int Model::deadLockCaso2(int Num,int numStubs,int *Classes,int *Integradas){
  int *LCD=(int*)malloc(sizeof(int)*Num); // LCD - Lista de Classes Dependentes
  int deadlock,menor;
       menor=(numStubs*Num)+1;
       deadlock=0;
       for(int x=0;x<Num;x++){
          if(!Integradas[Classes[x]]){
          int total=0;
          for(int i=0;i<Num;i++){
            if(!Integradas[Classes[i]] && i!=x){
                for(int j=0;j<numClass;j++){
                        if(!Integradas[j] && Classes[x]!=j) total+=MatrizInfluencia[j][Classes[i]];
                }

            }
          }
          if(total<menor){
                   menor=total;
                   deadlock=0;
                   LCD[deadlock]=Classes[x];
          }
          else if(total==menor){
                    deadlock++;
        	    LCD[deadlock]=Classes[x];
          }
        }
       }
          if(deadlock==0){
                LCOTI[classInt]=LCD[0];
                Integradas[LCD[0]]=1;
                classInt++;
          }
          else{

                deadLockCaso3(deadlock+1,LCD);
                for(int x=0;x<=deadlock;x++){
                        Integradas[LCD[x]]=1;
                }
          }
          return (deadlock+1); //nova linha
}

/*************************** Procedimento que busca resolver Deadlock ***************************/
void Model::resolverDeadlock(int Num,int *Classes,int *Integradas){
  int *NumStubs=(int*)malloc(sizeof(int)*Num);
  int *LCD=(int*)malloc(sizeof(int)*Num); //LCD - Lista de Classes Dependentes
  int menor,deadlock,tot;

  for(int i=0;i<Num;i++)       NumStubs[i]=0;
  tot=0;
  while(tot<Num){
          menor=numClass*numClass;
          deadlock=0;
          for(int i=0;i<Num;i++){
            if(!Integradas[Classes[i]]){
                  for(int j=0;j<numClass;j++){
                        if(!Integradas[j]) NumStubs[i]+=MatrizInfluencia[j][Classes[i]];
                  }

                if(NumStubs[i]<menor){
                        menor=NumStubs[i];
                        deadlock=0;
                        LCD[deadlock]=Classes[i];
                }
                else if(NumStubs[i]==menor){
        	    deadlock++;
        	    LCD[deadlock]=Classes[i];
                }
            }
          }
          if(deadlock==0){
                LCOTI[classInt]=LCD[0];
                Integradas[LCD[0]]=1;
                classInt++;
                tot++;
          }
          else{
                int clas = deadLockCaso2(deadlock+1,menor,LCD,Integradas);
                tot+=clas;
          }
  }
}

/***************** Procedimento que Busca a ordem de integracao de classes *********************/
void Model::ordemIntegrar(){
  int *ListaClassesIntegradas=(int*)malloc(sizeof(int)*numClass);
  int *ListaUltimos=(int*)malloc(sizeof(int)*numClass);
  int *ListaDeadLock=(int*)malloc(sizeof(int)*numClass);
  int menor,total,classeMenor,NumClasInteg,deadlock,totUltimos;

  for(int i=0;i<numClass;i++)
     ListaClassesIntegradas[i]=0;

  totUltimos=marcarFInulo(ListaClassesIntegradas,ListaUltimos);

  NumClasInteg=totUltimos;
  int it=1;
  while(NumClasInteg<numClass){
    it++;
    if(FOrdenador->Iteracao->ColCount<=it)    FOrdenador->Iteracao->ColCount=it+1;
    FOrdenador->Iteracao->Cells[it][0]=FOrdenador->getTag("FITITERACAO")+IntToStr(it-1);
    menor=numClass*numClass;
    deadlock=0;
    for(int i=0;i<numClass; i++){
       if(!ListaClassesIntegradas[i]){
         total=0;
         for(int j=0; j<numClass; j++)
 	   if(!ListaClassesIntegradas[j])     total+=MatrizInfluencia[j][i]*FI[j];
         FOrdenador->Iteracao->Cells[it][i+1]=IntToStr(total);
  	 if(total<menor){
	    menor=total;
	    deadlock=0;
            ListaDeadLock[deadlock]=i;
	 }
	 else if(total==menor){
	    deadlock++;
	    ListaDeadLock[deadlock]=i;
	 }
       }
       else{
         FOrdenador->Iteracao->Cells[it][i+1]="-";
       }
    }
    if(NumClasInteg<numClass){
      if(deadlock==0){
                LCOTI[classInt]=ListaDeadLock[0];
                classInt++;
                ListaClassesIntegradas[ListaDeadLock[0]]=1;

        }
      else{
         resolverDeadlock(deadlock+1,ListaDeadLock,ListaClassesIntegradas);
      }
      NumClasInteg+=deadlock+1;
    }

  }

  for(int i=0;i<totUltimos; i++){
        LCOTI[classInt]=ListaUltimos[i];
        classInt++;
  }
}
//---------------------------------------------------------------------------

int * Model::getOrdemSaida()
{
 return(LCOTI);
}
//---------------------------------------------------------------------------
int Model::getOrdemClass(int ind)
{
 return(LCOTI[ind]);
}
//---------------------------------------------------------------------------
void Model::setOrdemClass(int ind, int val)
{
 LCOTI[ind]=val;
}
//---------------------------------------------------------------------------
int Model::getNumStubsOriginal()
{
 return(NumStubsOriginal);
}
//---------------------------------------------------------------------------
void Model::setNumStubsOriginal(int num)
{
 NumStubsOriginal=num;
}
//---------------------------------------------------------------------------
int Model::getNumStubsAtual()
{
 return(NumStubsAtual);
}
//---------------------------------------------------------------------------
void Model::setNumStubsAtual(int num)
{
 NumStubsAtual=num;
}
//---------------------------------------------------------------------------
int Model::getComplexidadeAtual()
{
 return(ComplexidadeAtual);
}
//---------------------------------------------------------------------------
void Model::setComplexidadeAtual(int num)
{
 ComplexidadeAtual=num;
}
//---------------------------------------------------------------------------
int Model::getComplexidadeOriginal()
{
 return(ComplexidadeOriginal);
}
//---------------------------------------------------------------------------
void Model::setComplexidadeOriginal(int num)
{
 ComplexidadeOriginal=num;
}
//---------------------------------------------------------------------------
void Model::ordenarClasses(){
        Class *Aux;
        int contador;
        for(int i=0;i<numClass-1;i++){
              for(int j=i+1;j<numClass;j++){
                      if(lstClass[i]->getName().operator >(lstClass[j]->getName())){
                        Aux = lstClass[i];
                        lstClass[i]=lstClass[j];
                        lstClass[j]=Aux;
                        lstClass[i]->setContador(i);
                        lstClass[j]->setContador(j);
                      }
              }
        }
}
//---------------------------------------------------------------------------