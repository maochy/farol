#include "FSobre.h"
#include "Idioma.h"
#include <stdio.h>
#pragma once

namespace Farol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Farol;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		array< String^, 2 >^ MatClass;
		array< String^, 2 >^ MatAssoc;
		array< String^, 2 >^ MatHer;
		array< String^, 2 >^ MatDepend;
		array< String^, 1 >^ lstClass;
		array< int, 1 >^ FI;
		array< int, 1 >^ LCOTI;
		
		int numClass;
		int classInt;
		int NumStubsOriginal;
		int NumStubsAtual;
		int ComplexidadeOriginal;
		int ComplexidadeAtual;
		
		int Num_Idioma;
		int Num_palavra;
		int IDIOMA;
		array< String^, 2 > ^Dicionario;
		array< String^, 1> ^Idiomas;
		array< String^, 1> ^HelpFile;
		array< String^, 1 > ^ReportsFile;
		array< String^, 1 > ^Tags;


	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;




	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;





















	public: 
		array< int, 2 >^ MatrizInfluencia;
System::String ^getTag(String ^Tag)
{
	//IDIOMA = Farol::Idioma::ID;
	return(Dicionario[IDIOMA,consultarTag(Tag)]);
}

/*---------------------------------------------------------------------------
Procedimento respons�vel por consultar uma tag para um componente na biblioteca de textos
---------------------------------------------------------------------------*/
int consultarTag(String ^Tag)
{
        for(int i=0;i<Num_palavra;i++)
		{
			if(Tag==Tags[i]) return(i);
        }
        return(-1);
}

System::Void carregarIdioma()
{
	//Form1 ^ordenador;
	String^ path = "./language.dll";
	String^ ArqLine;
	String^ delimStr;
	System::IO::StreamReader ^Arq = gcnew System::IO::StreamReader(path,System::Text::Encoding::Default);
	//FILE *Arq;
	
	array< String^, 1 > ^line;
	
	array< wchar_t> ^delimiter;
	

	ArqLine = Arq->ReadLine();
	delimStr = "%d %d";
	delimiter = delimStr->ToCharArray();
	line = ArqLine->Split(delimiter);

	Num_Idioma = Convert::ToInt32(line[0]);
	Num_palavra = Convert::ToInt32(line[1]);

	ArqLine = Arq->ReadLine();
	delimStr = "%d";
	delimiter = delimStr->ToCharArray();
	line = ArqLine->Split(delimiter);

	IDIOMA = Convert::ToInt32(line[0]);
	
	Dicionario = gcnew array< String^, 2 >(Num_Idioma,Num_palavra);
    Idiomas = gcnew array< String^, 1 >(Num_Idioma);
    HelpFile = gcnew array< String^, 1 >(Num_Idioma);
    ReportsFile = gcnew array< String^, 1 >(Num_Idioma);
	Tags = gcnew array< String^, 1 >(Num_palavra);

	for(int i=0;i<Num_Idioma;i++)
	{
		ArqLine = Arq->ReadLine();
		delimStr = "%s %s %s";
		delimiter = delimStr->ToCharArray();
		line = ArqLine->Split(delimiter);
		Idiomas[i] = line[0];
		HelpFile[i] = line[1];
		ReportsFile[i] = line[2];
	}

	for(int i=0;i<Num_palavra;i++)
	{
		ArqLine = Arq->ReadLine()->Normalize(System::Text::NormalizationForm::FormD);
		
		delimStr = "%[^=]";
		//delimStr = "=%s=";
		delimiter = delimStr->ToCharArray();
		line = ArqLine->Split(delimiter);

		Tags[i] = line[0];

		delimStr = "=%[=\n]";
		delimiter = delimStr->ToCharArray();
		line = ArqLine->Split(delimiter);
        
		for(int j=0;j<Num_Idioma;j++)
		{
			Dicionario[j,i] = line[j+1];
			//String::Format(Arq->ReadLine(),"{=:[^=\n]s}",Dicionario[j,i]);
        }
    }

	//ordenador->label4->Text = Dicionario[1,3];
	//label4->Text = Dicionario[0,2];
}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fun��esToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  op��esToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  configura��esToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirArquivoXMIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gerarOrdena��oCtrlGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fecharArquivoCtrlFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  slavarResultadoCtrlBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importarResultadoCtrlIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  imprimirResultadoCtrlToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  painelDeModeloDeClasseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  painelDeSequ�nciaDeOrdena��oToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  mudarIdiomaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  conte�doToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;











	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton8;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;





	private: System::Windows::Forms::SplitContainer^  splitContainer3;

	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::SplitContainer^  splitContainer4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Button^  moverBaixo;

private: System::Windows::Forms::Button^  moverCima;

	private: System::Windows::Forms::GroupBox^  groupBox3;


	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::Label^  label4;
	private: System::String ^path;
























	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			carregarIdioma();
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fun��esToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirArquivoXMIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gerarOrdena��oCtrlGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fecharArquivoCtrlFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->op��esToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->slavarResultadoCtrlBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importarResultadoCtrlIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->imprimirResultadoCtrlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configura��esToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->painelDeModeloDeClasseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mudarIdiomaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->conte�doToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->moverBaixo = (gcnew System::Windows::Forms::Button());
			this->moverCima = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fun��esToolStripMenuItem, 
				this->op��esToolStripMenuItem, this->configura��esToolStripMenuItem, this->ajudaToolStripMenuItem, this->sairToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(874, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fun��esToolStripMenuItem
			// 
			this->fun��esToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->abrirArquivoXMIToolStripMenuItem, 
				this->gerarOrdena��oCtrlGToolStripMenuItem, this->fecharArquivoCtrlFToolStripMenuItem});
			this->fun��esToolStripMenuItem->Name = L"fun��esToolStripMenuItem";
			this->fun��esToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->fun��esToolStripMenuItem->Tag = L"FUNCAO";
			//this->fun��esToolStripMenuItem->Text = L"Fun��es";
			this->fun��esToolStripMenuItem->Text = Farol::Form1::getTag("FUNCAO");
			this->fun��esToolStripMenuItem->TextChanged += gcnew System::EventHandler(this, &Form1::fun��esToolStripMenuItem_TextChanged);
			// 
			// abrirArquivoXMIToolStripMenuItem
			// 
			this->abrirArquivoXMIToolStripMenuItem->Name = L"abrirArquivoXMIToolStripMenuItem";
			this->abrirArquivoXMIToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->abrirArquivoXMIToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			//this->abrirArquivoXMIToolStripMenuItem->Text = L"Abrir Arquivo XMI ";
			this->abrirArquivoXMIToolStripMenuItem->Text = Farol::Form1::getTag("ABRIR");
			this->abrirArquivoXMIToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// gerarOrdena��oCtrlGToolStripMenuItem
			// 
			this->gerarOrdena��oCtrlGToolStripMenuItem->Name = L"gerarOrdena��oCtrlGToolStripMenuItem";
			this->gerarOrdena��oCtrlGToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->gerarOrdena��oCtrlGToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			//this->gerarOrdena��oCtrlGToolStripMenuItem->Text = L"Gerar Ordena��o ";
			this->gerarOrdena��oCtrlGToolStripMenuItem->Text = Farol::Form1::getTag("GERARORD");
			// 
			// fecharArquivoCtrlFToolStripMenuItem
			// 
			this->fecharArquivoCtrlFToolStripMenuItem->Name = L"fecharArquivoCtrlFToolStripMenuItem";
			this->fecharArquivoCtrlFToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->fecharArquivoCtrlFToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			//this->fecharArquivoCtrlFToolStripMenuItem->Text = L"Fechar Arquivo";
			this->fecharArquivoCtrlFToolStripMenuItem->Text = Farol::Form1::getTag("FECHAR");
			// 
			// op��esToolStripMenuItem
			// 
			this->op��esToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->slavarResultadoCtrlBToolStripMenuItem, 
				this->importarResultadoCtrlIToolStripMenuItem, this->toolStripSeparator1, this->imprimirResultadoCtrlToolStripMenuItem});
			this->op��esToolStripMenuItem->Name = L"op��esToolStripMenuItem";
			this->op��esToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			//this->op��esToolStripMenuItem->Text = L"Op��es";
			this->op��esToolStripMenuItem->Text = Farol::Form1::getTag("OPCAO");
			// 
			// slavarResultadoCtrlBToolStripMenuItem
			// 
			this->slavarResultadoCtrlBToolStripMenuItem->Name = L"slavarResultadoCtrlBToolStripMenuItem";
			this->slavarResultadoCtrlBToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->slavarResultadoCtrlBToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			//this->slavarResultadoCtrlBToolStripMenuItem->Text = L"Salvar Resultado";
			this->slavarResultadoCtrlBToolStripMenuItem->Text = Farol::Form1::getTag("SALVAR");
			// 
			// importarResultadoCtrlIToolStripMenuItem
			// 
			this->importarResultadoCtrlIToolStripMenuItem->Name = L"importarResultadoCtrlIToolStripMenuItem";
			this->importarResultadoCtrlIToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			this->importarResultadoCtrlIToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			//this->importarResultadoCtrlIToolStripMenuItem->Text = L"Importar Resultado";
			this->importarResultadoCtrlIToolStripMenuItem->Text = Farol::Form1::getTag("IMPORTAR");
			this->importarResultadoCtrlIToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::importarResultadoCtrlIToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(213, 6);
			// 
			// imprimirResultadoCtrlToolStripMenuItem
			// 
			this->imprimirResultadoCtrlToolStripMenuItem->Name = L"imprimirResultadoCtrlToolStripMenuItem";
			this->imprimirResultadoCtrlToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->imprimirResultadoCtrlToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			//this->imprimirResultadoCtrlToolStripMenuItem->Text = L"Imprimir Resultado";
			this->imprimirResultadoCtrlToolStripMenuItem->Text = Farol::Form1::getTag("IMPRIMIR");
			// 
			// configura��esToolStripMenuItem
			// 
			this->configura��esToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->painelDeModeloDeClasseToolStripMenuItem, 
				this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem, this->toolStripSeparator2, this->mudarIdiomaToolStripMenuItem});
			this->configura��esToolStripMenuItem->Name = L"configura��esToolStripMenuItem";
			this->configura��esToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::M));
			this->configura��esToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			//this->configura��esToolStripMenuItem->Text = L"Configura��es";
			this->configura��esToolStripMenuItem->Text = Farol::Form1::getTag("CONFIGURACAO");
			// 
			// painelDeModeloDeClasseToolStripMenuItem
			// 
			this->painelDeModeloDeClasseToolStripMenuItem->Checked = true;
			this->painelDeModeloDeClasseToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->painelDeModeloDeClasseToolStripMenuItem->Name = L"painelDeModeloDeClasseToolStripMenuItem";
			this->painelDeModeloDeClasseToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			//this->painelDeModeloDeClasseToolStripMenuItem->Text = L"Painel de Modelo de Classes";
			this->painelDeModeloDeClasseToolStripMenuItem->Text = Farol::Form1::getTag("PMOC");
			// 
			// painelDeSequ�nciaDeOrdena��oToolStripMenuItem
			// 
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->Checked = true;
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->Name = L"painelDeSequ�nciaDeOrdena��oToolStripMenuItem";
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			//this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->Text = L"Painel de Sequ�ncia de Ordena��o";
			this->painelDeSequ�nciaDeOrdena��oToolStripMenuItem->Text = Farol::Form1::getTag("PSEO");
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(253, 6);
			// 
			// mudarIdiomaToolStripMenuItem
			// 
			this->mudarIdiomaToolStripMenuItem->Name = L"mudarIdiomaToolStripMenuItem";
			this->mudarIdiomaToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::M));
			this->mudarIdiomaToolStripMenuItem->Size = System::Drawing::Size(256, 22);
            //this->mudarIdiomaToolStripMenuItem->Text = L"Mudar Idioma";
			this->mudarIdiomaToolStripMenuItem->Text = Farol::Form1::getTag("MUDARIDIOMA");
			this->mudarIdiomaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mudarIdiomaToolStripMenuItem_Click);
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->conte�doToolStripMenuItem, 
				this->sobreToolStripMenuItem});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			//this->ajudaToolStripMenuItem->Text = L"Ajuda";
			this->ajudaToolStripMenuItem->Text = Farol::Form1::getTag("AJUDA");
			// 
			// conte�doToolStripMenuItem
			// 
			this->conte�doToolStripMenuItem->Name = L"conte�doToolStripMenuItem";
			this->conte�doToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->conte�doToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			//this->conte�doToolStripMenuItem->Text = L"Conte�do";
			this->conte�doToolStripMenuItem->Text = Farol::Form1::getTag("CONTEUDO");
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			//this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Text = Farol::Form1::getTag("SOBRE");
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sobreToolStripMenuItem_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			//this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Text = Farol::Form1::getTag("SAIR");
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sairToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->toolStripButton1, 
				this->toolStripButton3, this->toolStripButton2, this->toolStripSeparator4, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6, 
				this->toolStripSeparator5, this->toolStripButton7, this->toolStripButton8});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(874, 46);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			this->toolStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::toolStrip1_ItemClicked);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(36, 43);
			this->toolStripButton1->Text = L"toolStripButton1";
			//this->toolStripButton1->ToolTipText = L"Abrir Arquivo XMI";
			this->toolStripButton1->ToolTipText = Farol::Form1::getTag("ABRIR");
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Enabled = false;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(39, 43);
			this->toolStripButton3->Text = L"toolStripButton1";
			//this->toolStripButton3->ToolTipText = L"Gerar Ordena��o";
			this->toolStripButton3->ToolTipText = Farol::Form1::getTag("GERARORD");
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Enabled = false;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(39, 43);
			this->toolStripButton2->Text = L"toolStripButton1";
			//this->toolStripButton2->ToolTipText = L"Fechar Arquivo";
			this->toolStripButton2->ToolTipText = Farol::Form1::getTag("FECHAR");
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 46);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Enabled = false;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(38, 43);
			this->toolStripButton4->Text = L"toolStripButton1";
			//this->toolStripButton4->ToolTipText = L"Salvar Resultado";
			this->toolStripButton4->ToolTipText = Farol::Form1::getTag("SALVAR");
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(37, 43);
			this->toolStripButton5->Text = L"toolStripButton1";
			//this->toolStripButton5->ToolTipText = L"Importar Resultado";
			this->toolStripButton5->ToolTipText = Farol::Form1::getTag("IMPORTAR");
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Enabled = false;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(41, 43);
			this->toolStripButton6->Text = L"toolStripButton1";
			//this->toolStripButton6->ToolTipText = L"Imprimir Resultado";
			this->toolStripButton6->ToolTipText = Farol::Form1::getTag("IMPRIMIR");
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 46);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(38, 43);
			this->toolStripButton7->Text = L"toolStripButton1";
			//this->toolStripButton7->ToolTipText = L"Ajuda";
			this->toolStripButton7->ToolTipText = Farol::Form1::getTag("AJUDA");
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(39, 43);
			this->toolStripButton8->Text = L"toolStripButton1";
			//this->toolStripButton8->ToolTipText = L"Sair";
			this->toolStripButton8->ToolTipText = Farol::Form1::getTag("SAIR");
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &Form1::toolStripButton8_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(17, 2);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label1->Size = System::Drawing::Size(99, 19);
			this->label1->TabIndex = 0;
			//this->label1->Text = L"Arquivo XMI";
			this->label1->Text = Farol::Form1::getTag("ARQUIVOXMI");
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// splitContainer2
			// 
			this->splitContainer2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(0, 70);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->label1);
			this->splitContainer2->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->splitContainer2->Panel2->Controls->Add(this->label4);
			this->splitContainer2->Panel2->Controls->Add(this->label2);
			this->splitContainer2->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer2->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer2_Panel2_Paint);
			this->splitContainer2->Size = System::Drawing::Size(874, 27);
			this->splitContainer2->SplitterDistance = 137;
			this->splitContainer2->TabIndex = 3;
			this->splitContainer2->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Form1::splitContainer2_SplitterMoved);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 2);
			this->label4->Name = L"label4";
			this->label4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label4->Size = System::Drawing::Size(0, 19);
			this->label4->TabIndex = 1;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 22);
			this->label2->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer1->Location = System::Drawing::Point(0, 101);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::SystemColors::Window;
			this->splitContainer1->Panel1->Controls->Add(this->treeView1);
			this->splitContainer1->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer1->Panel2->Controls->Add(this->groupBox2);
			this->splitContainer1->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel2_Paint);
			this->splitContainer1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer1->Size = System::Drawing::Size(874, 439);
			this->splitContainer1->SplitterDistance = 243;
			this->splitContainer1->TabIndex = 4;
			// 
			// treeView1
			// 
			this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView1->Location = System::Drawing::Point(-2, -2);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(242, 437);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterSelect);
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->splitContainer4);
			this->groupBox2->Controls->Add(this->splitContainer3);
			this->groupBox2->Location = System::Drawing::Point(-1, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(624, 437);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			//this->groupBox2->Text = L"Sequ�ncia de Ordena��o";
			this->groupBox2->Text = Farol::Form1::getTag("SEQUENCIAORD");
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form1::groupBox2_Enter);
			// 
			// splitContainer4
			// 
			this->splitContainer4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer4->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer4->IsSplitterFixed = true;
			this->splitContainer4->Location = System::Drawing::Point(3, 18);
			this->splitContainer4->Name = L"splitContainer4";
			this->splitContainer4->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->panel1);
			this->splitContainer4->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer4_Panel1_Paint);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->label3);
			this->splitContainer4->Size = System::Drawing::Size(621, 218);
			this->splitContainer4->SplitterDistance = 179;
			this->splitContainer4->TabIndex = 5;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->dataGridView2);
			this->panel1->Location = System::Drawing::Point(-2, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(621, 182);
			this->panel1->TabIndex = 9;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column0, 
				this->Column1});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView2->RowTemplate->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(617, 178);
			this->dataGridView2->TabIndex = 0;
			this->dataGridView2->Visible = false;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView2_CellContentClick);
			// 
			// Column0
			// 
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Yellow;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Yellow;
			this->Column0->DefaultCellStyle = dataGridViewCellStyle6;
			this->Column0->Frozen = true;
			//this->Column0->HeaderText = L"Classe / Itera��o";
			this->Column0->HeaderText = Farol::Form1::getTag("CLASSEITERACAO");
			this->Column0->Name = L"Column0";
			this->Column0->ReadOnly = true;
			this->Column0->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column0->Width = 115;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::LightYellow;
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::LightYellow;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Column1->DefaultCellStyle = dataGridViewCellStyle7;
			//this->Column1->HeaderText = L"Valor de FI";
			this->Column1->HeaderText = Farol::Form1::getTag("VALORFI");
			this->Column1->MinimumWidth = 83;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column1->Width = 83;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(193, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 24);
			this->label3->TabIndex = 0;
			//this->label3->Text = L"Ordem de Integra��o";
			this->label3->Text = Farol::Form1::getTag("ORDEMINT");
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click_1);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer3->IsSplitterFixed = true;
			this->splitContainer3->Location = System::Drawing::Point(3, 241);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->splitContainer3->Panel1->Controls->Add(this->dataGridView1);
			this->splitContainer3->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer3->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer3_Panel1_Paint);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer3->Panel2->Controls->Add(this->moverBaixo);
			this->splitContainer3->Panel2->Controls->Add(this->moverCima);
			this->splitContainer3->Panel2->Controls->Add(this->groupBox3);
			this->splitContainer3->Panel2->Controls->Add(this->groupBox1);
			this->splitContainer3->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer3->Size = System::Drawing::Size(621, 196);
			this->splitContainer3->SplitterDistance = 430;
			this->splitContainer3->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(426, 192);
			this->dataGridView1->TabIndex = 0;
			// 
			// moverBaixo
			// 
			this->moverBaixo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->moverBaixo->Enabled = false;
			this->moverBaixo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"moverBaixo.Image")));
			this->moverBaixo->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->moverBaixo->Location = System::Drawing::Point(0, 167);
			this->moverBaixo->Name = L"moverBaixo";
			this->moverBaixo->Size = System::Drawing::Size(183, 25);
			this->moverBaixo->TabIndex = 3;
			//this->moverBaixo->Text = L"mover para baixo";
			this->moverBaixo->Text = Farol::Form1::getTag("MOVERBAIXO");
			this->moverBaixo->UseVisualStyleBackColor = true;
			this->moverBaixo->Click += gcnew System::EventHandler(this, &Form1::moverBaixo_Click);
			// 
			// moverCima
			// 
			this->moverCima->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->moverCima->Enabled = false;
			this->moverCima->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"moverCima.Image")));
			this->moverCima->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->moverCima->Location = System::Drawing::Point(0, 141);
			this->moverCima->Name = L"moverCima";
			this->moverCima->Size = System::Drawing::Size(183, 26);
			this->moverCima->TabIndex = 2;
			//this->moverCima->Text = L"mover para cima";
			this->moverCima->Text = Farol::Form1::getTag("MOVERCIMA");
			this->moverCima->UseVisualStyleBackColor = true;
			this->moverCima->Click += gcnew System::EventHandler(this, &Form1::moverCima_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->panel3);
			this->groupBox3->Location = System::Drawing::Point(3, 70);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(180, 69);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			//this->groupBox3->Text = L"Ordem alterada";
			this->groupBox3->Text = Farol::Form1::getTag("ORDEMALTERADA");
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->dataGridView3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(3, 16);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(174, 50);
			this->panel3->TabIndex = 1;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->AllowUserToResizeColumns = false;
			this->dataGridView3->AllowUserToResizeRows = false;
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2});
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->RowHeadersVisible = false;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView3->RowsDefaultCellStyle = dataGridViewCellStyle9;
			this->dataGridView3->Size = System::Drawing::Size(170, 46);
			this->dataGridView3->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			//this->dataGridViewTextBoxColumn1->HeaderText = L"Total Stubs";
			this->dataGridViewTextBoxColumn1->HeaderText = Farol::Form1::getTag("TOTSTUBS");
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 90;
			// 
			// dataGridViewTextBoxColumn2
			// 
			//this->dataGridViewTextBoxColumn2->HeaderText = L"Tamanho";
			this->dataGridViewTextBoxColumn2->HeaderText = Farol::Form1::getTag("TAMANHO");
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 76;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Location = System::Drawing::Point(3, 1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(180, 69);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			//this->groupBox1->Text = L"Ordem original";
			this->groupBox1->Text = Farol::Form1::getTag("ORDEMORIGINAL");
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->dataGridView4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 16);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(174, 50);
			this->panel2->TabIndex = 0;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->AllowUserToResizeColumns = false;
			this->dataGridView4->AllowUserToResizeRows = false;
			this->dataGridView4->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->dataGridViewTextBoxColumn3, 
				this->dataGridViewTextBoxColumn4});
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView4->Location = System::Drawing::Point(0, 0);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->ReadOnly = true;
			this->dataGridView4->RowHeadersVisible = false;
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView4->RowsDefaultCellStyle = dataGridViewCellStyle10;
			this->dataGridView4->Size = System::Drawing::Size(170, 46);
			this->dataGridView4->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn3
			// 
			//this->dataGridViewTextBoxColumn3->HeaderText = L"Total Stubs";
			this->dataGridViewTextBoxColumn3->HeaderText = Farol::Form1::getTag("TOTSTUBS");
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 90;
			// 
			// dataGridViewTextBoxColumn4
			// 
			//this->dataGridViewTextBoxColumn4->HeaderText = L"Tamanho";
			this->dataGridViewTextBoxColumn4->HeaderText = Farol::Form1::getTag("TAMANHO");
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 76;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk_1);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 543);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(874, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 565);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Farol Tool: Ordenador de Classes para Teste de Integra��o";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->Panel2->PerformLayout();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel1->PerformLayout();
			this->splitContainer4->Panel2->ResumeLayout(false);
			this->splitContainer4->Panel2->PerformLayout();
			this->splitContainer4->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void toolStripComboBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void importarResultadoCtrlIToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }

private: System::Void toolStripButton8_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ msg("Confirmar a sa�da do programa?");

			 if (MessageBox::Show(msg,"Sa�da do Programa",MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
				 Application::Exit();
			 }
		 }
private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ msg("Confirmar a sa�da do programa?");

			 if (MessageBox::Show(msg,"Sa�da do Programa",MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
				 Application::Exit();
			 }
		 }
private: System::Void openFileDialog1_FileOk_1(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }

//Retorna o nome da classe a partir do ID da classe fornecido
private: System::String ^ getClassName(array<String ^,2> ^Mat, System::String ^ id){

			  for(int i=0; i<Mat->Length/2; i++)
			  {
				  if(Mat[i,1]==id)
				  {
					  return Mat[i,0];
				  }
			  }
			  //TO DO: Adicionar uma exce��o
}

System::String ^getClass(int ind)
{
	return(lstClass[ind]);
}

//Retorna o n�mero de conectores de uma classe c
private: System::Int32 ^ getConectorsNumber(System::String ^ c)
{
	int conectN = 0;

	for(int i=0;i<MatAssoc->Length/5;i++)
	{
		if(MatAssoc[i,1]==c)
		{
			conectN++;
		}
		if(MatAssoc[i,2]==c)
		{
			conectN++;
		}
	}

	for(int i=0;i<MatHer->Length/2;i++)
	{
		if(MatHer[i,0]==c)
		{
			conectN++;
		}
		if(MatHer[i,1]==c)
		{
			conectN++;
		}
	}

	for(int i=0;i<MatDepend->Length/2;i++)
	{
		if(MatDepend[i,0]==c)
		{
			conectN++;
		}
		if(MatDepend[i,1]==c)
		{
			conectN++;
		}
	}

	return conectN;
}

private: int getTamanho(System::String ^classe)
{
	//for(int i=0;i<MatClass->Length/5;i++)
	for(int i=0;i<numClass;i++)
	{
		if(MatClass[i,0]==classe)
		{
			return Convert::ToInt32(MatClass[i,3]);
		}
	}
}

private: int getContador(System::String ^classe)
{
	for(int i=0;i<MatClass->Length/5;i++)
	{
		if(MatClass[i,0]==classe)
		{
			return i;
		}
	}
}
/*
void ordenarClasses()
{
	String ^Aux;
	int contador;
	for(int i=0;i<numClass-1;i++)
	{
		for(int j=i+1;j<numClass;j++)
		{
			if(lstClass[i]->operator>(lstClass[j]))
			{
				Aux = lstClass[i];
				lstClass[i]=lstClass[j];
				lstClass[j]=Aux;
				//lstClass[i]->setContador(i);
				//lstClass[j]->setContador(j);
			}
		}
	}
}*/

//Retorna um valor booleano indicando se a classe � naveg�vel ou n�o
private: System::Boolean ^ isNavigable(System::String ^ nav){

			  return nav->Contains("Navigable=Navigable");
}

private: System::Void updateMatClass()
{
	//int numClass = MatClass->Length/5;
	int undef = 0;
	bool onlyLastOne = true;

	//TODO: Verificar o par�metro Tamanho das classes
	for(int i=0;i<numClass;i++)
	{
		//if(MatClass[i,0]=="<undefined>")
		if(String::IsNullOrEmpty(MatClass[i,0]) || MatClass[i,0]=="<undefined>")
		{
			undef++;
			if(i==numClass-1 && onlyLastOne)
			{
				for(int k=0;k<5;k++)
				{
					MatClass[i,k]=String::Empty;
				}
			}
			else
			{
				for(int j=i;j<numClass-1;j++)
				{
					for(int k=0;k<5;k++)
					{
						MatClass[j,k]=MatClass[j+1,k];
					}
					if(j==numClass-2)
					{
						for(int k=0;k<5;k++)
						{
							MatClass[j+1,k] = String::Empty;
						}
					}
					
				}
				onlyLastOne = false;
			}

		}
	}
	if(onlyLastOne)
	{
		numClass=numClass-(undef);
	}
	else
	{
		numClass=numClass-(undef-1);
	}
}

private: int undefinedClasses()
{
	int n = 0;
	//int numClass = MatClass->Length/5;

	for(int i=0;i<numClass;i++)
	{
		if(MatClass[i,0]->IsNullOrEmpty(MatClass[i,0]))
		{
			n++;
		}
	}
	return n;
}

int getOrdemClass(int ind)
{
	return(LCOTI[ind]);
}
//---------------------------------------------------------------------------
void setOrdemClass(int ind, int val)
{
	LCOTI[ind]=val;
}

private: System::Void setFICol()
{
	//int numClass = MatClass->Length/5;
	int j = 0;

	for(int i=0;i<numClass;i++)
	{
		if(j<numClass)
		{
			if(MatClass[j,0]->IsNullOrEmpty(MatClass[j,0]))
			{
				j=i+1;
			}
			if(j<numClass)
			{
				dataGridView2->Rows[i]->Cells[1]->Value = MatClass[j,2];
				j++;
			}
		}
		else
		{
			break;
		}
	}
}

private: System::Void calcularFI()
{
	//int numClass = MatClass->Length/5;
	FI = gcnew array< int, 1 >(numClass);
	for(int i=0;i<numClass;i++)
	{
		FI[i]=0;
		for(int j=0;j<numClass;j++)
		{
			FI[i]+=MatrizInfluencia[i,j];
		}
	//FOrdenador->Iteracao->Cells[1][i+1]=IntToStr(FI[i]);
	}
}

private: System::String ^buscaContClasse(int ID, array< String^, 1 >^lista, int nElem){
        bool achou=false;
        int cont=0;
        while(cont<nElem && !achou){
                if(ID==getContador(lista[cont]))
                        achou=true;
                cont++;
        }
        return lista[cont-1];
}

/*************************** Procedimento que busca resolver Deadlock ***************************/
private: System::Void deadLockCaso3(int Num, array< int, 1 >^ Classes)
{
	array< int, 1 >^ Tamanho = gcnew array< int, 1 >(Num);
	//int numClass = MatClass->Length/5;

	for(int i=0;i<numClass;i++)
	{
		lstClass[i] = MatClass[i,0]; 
	}

	for(int i=0;i<Num;i++)
	{
		//Tamanho[i]=buscaContClasse(Classes[i],lstClass,numClass)->getTamanho();
		Tamanho[i]=getTamanho(buscaContClasse(Classes[i],lstClass,numClass));
	}

	for(int i=0;i<Num-1;i++)
	{
		for(int j=i+1;j<Num;j++)
		{
			if(Tamanho[i]>Tamanho[j])
			{
				int aux=Tamanho[i];
				Tamanho[i]=Tamanho[j];
				Tamanho[j]=aux;
				aux=Classes[i];
				Classes[i]=Classes[j];
				Classes[j]=aux;
			}
		}
	}

	for(int i=0;i<Num;i++)
	{
		LCOTI[classInt]=Classes[i];
		classInt++;
	}
}

/*************************** Procedimento que busca resolver Deadlock ***************************/
private: int deadLockCaso2(int Num,int numStubs,array< int, 1 >^ Classes, array< int, 1 >^ Integradas)
{
	array< int, 1 >^ LCD = gcnew array< int, 1 >(Num); //LCD - Lista de Classes Dependentes
	int deadlock,menor;
	menor=(numStubs*Num)+1;
	deadlock=0;
	//int numClass = MatClass->Length/5;

	for(int x=0;x<Num;x++)
	{
		if(!Integradas[Classes[x]])
		{
			int total=0;
			for(int i=0;i<Num;i++)
			{
				if(!Integradas[Classes[i]] && i!=x)
				{
					for(int j=0;j<numClass;j++)
					{
						if(!Integradas[j] && Classes[x]!=j)
						{
							total+=MatrizInfluencia[j, Classes[i]];
						}
					}

				}
			}
			if(total<menor)
			{
				menor=total;
				deadlock=0;
				LCD[deadlock]=Classes[x];
			}
			else if(total==menor)
			{
				deadlock++;
    			LCD[deadlock]=Classes[x];
			}
		}
	}
	if(deadlock==0)
	{
		LCOTI[classInt]=LCD[0];
		//Integradas[classInt]=LCD[0];
		Integradas[LCD[0]]=1;
		classInt++;
	}
	else
	{
		deadLockCaso3(deadlock+1,LCD);
		for(int x=0;x<=deadlock;x++)
		{
			Integradas[LCD[x]]=1;
		}
	}
	return (deadlock+1); //nova linha
}

/*************************** Procedimento que busca resolver Deadlock ***************************/
private: System::Void resolverDeadlock(int Num,array< int, 1 >^ Classes, array< int, 1 >^ Integradas)
{
	array< int, 1 >^ NumStubs = gcnew array< int, 1 >(Num);
	array< int, 1 >^ LCD = gcnew array< int, 1 >(Num); //LCD - Lista de Classes Dependentes
	int menor, deadlock, tot;
	//int numClass = MatClass->Length/5;
	

	for(int i=0;i<Num;i++)
	{
		NumStubs[i]=0;
	}
	tot=0;
	while(tot<Num)
	{
		menor = numClass*numClass;
		deadlock=0;

		for(int i=0;i<Num;i++)
		{
			if(!Integradas[Classes[i]])
			{
				for(int j=0;j<numClass;j++)
				{
					if(!Integradas[j])
					{
						NumStubs[i]+=MatrizInfluencia[j, Classes[i]];
					}
				}

				if(NumStubs[i]<menor)
				{
					menor=NumStubs[i];
					deadlock=0;
					LCD[deadlock]=Classes[i];
				}
				else if(NumStubs[i]==menor)
				{
					deadlock++;
    				LCD[deadlock]=Classes[i];
				}
			}
		}
		if(deadlock==0)
		{
			LCOTI[classInt]=LCD[0];
			//Integradas[classInt]=LCD[0];
			Integradas[LCD[0]]=1;
			classInt++;
			tot++;
		}
		else
		{
			int clas = deadLockCaso2(deadlock+1,menor,LCD,Integradas);
			tot+=clas;
		}
	}
}

/************************ Funcao que marca as classes que possuem FI nulo ***********************/
private: int marcarFInulo(array< int, 1 >^ LCOTI, array< int, 1 >^ ListaUltimos)
{
	//int numClass = MatClass->Length/5;
	FI = gcnew array< int, 1 >(numClass);

	for(int i=0;i<numClass;i++)
	{
		FI[i]=0;
		for(int j=0;j<numClass;j++)
		{
			FI[i]+=MatrizInfluencia[i,j];
		}
	//FOrdenador->Iteracao->Cells[1][i+1]=IntToStr(FI[i]);
	}
	int cont=0;
	//int numClass = MatClass->Length/5;
	//LCOTI = Lista de Classes Ordenadas Integradas
	for(int i=0;i<numClass;i++)
	{
		if(!FI[i])
		{
			LCOTI[i] = 1;
			ListaUltimos[cont] = i;
			cont++;
		}
	}
	return cont;
}

private: int calcularStubs()
{
	array< int, 1 >^ Integrar = gcnew array< int, 1 >(numClass);
	int Resp = 0;

	for(int i=0;i<numClass;i++)
	{
		Integrar[i]=0;
	}

	for(int i=0;i<numClass;i++)
	{
		for(int j=0;j<numClass;j++)
		{
			if(!Integrar[j])
			{
				Resp+=MatrizInfluencia[j,LCOTI[i]];
			}
		}
		Integrar[LCOTI[i]]=1;
	}
	return Resp;
}

private: int calcularComplexidade()
{
	array< int, 1 >^ Integrar = gcnew array< int, 1 >(numClass);
	int Resp = 0;

	for(int i=0;i<numClass;i++)
	{
		Integrar[i]=0;
	}

	for(int i=0;i<numClass;i++)
	{
		for(int j=0;j<numClass;j++)
		{
			if(!Integrar[j])
			{
				Resp+=(MatrizInfluencia[j,LCOTI[i]]*getTamanho(lstClass[j]));
			}
		}
		Integrar[LCOTI[i]]=1;
	}
	return Resp;
}

int getNumStubsOriginal()
{
	return(NumStubsOriginal);
}
//---------------------------------------------------------------------------
void setNumStubsOriginal(int num)
{
	NumStubsOriginal=num;
}
//---------------------------------------------------------------------------
int getNumStubsAtual()
{
	return(NumStubsAtual);
}
//---------------------------------------------------------------------------
void setNumStubsAtual(int num)
{
	NumStubsAtual=num;
}
//---------------------------------------------------------------------------
int getComplexidadeAtual()
{
	return(ComplexidadeAtual);
}
//---------------------------------------------------------------------------
void setComplexidadeAtual(int num)
{
	ComplexidadeAtual=num;
}
//---------------------------------------------------------------------------
int getComplexidadeOriginal()
{
	return(ComplexidadeOriginal);
}
//---------------------------------------------------------------------------
void setComplexidadeOriginal(int num)
{
	ComplexidadeOriginal=num;
}

/*---------------------------------------------------------------------------
Procedimento respons�vel pela visualiza��o da ordem de classe gerada na tela do programa
---------------------------------------------------------------------------*/
void imprimeSaida(int NC)
{
	dataGridView1->Enabled = true;
	dataGridView1->Visible = true;
	dataGridView1->RowCount = numClass;
	dataGridView1->ColumnCount = 1;
	dataGridView1->Columns[0]->Width = 423;
    for(int i=0;i<NC;i++)
	{
		dataGridView1->Rows[i]->Cells[0]->Value = getClass(LCOTI[i]);
	}
}

private: System::Void ordemIntegrar()
{
	classInt = 0;
	//int numClass = MatClass->Length/5;
	array< int, 1 >^ ListaClassesIntegradas = gcnew array< int, 1 >(numClass);
	array< int, 1 >^ ListaUltimos = gcnew array< int, 1 >(numClass);
	array< int, 1 >^ ListaDeadLock = gcnew array< int, 1 >(numClass);
	int menor,total,classeMenor,NumClasInteg,deadlock,totUltimos;

	for(int i=0;i<numClass;i++)
	{
		ListaClassesIntegradas[i]=0;
	}

	totUltimos = marcarFInulo(ListaClassesIntegradas,ListaUltimos);

	NumClasInteg = totUltimos;
	int it=1;

	while(NumClasInteg<numClass)
	{
		it++;
		if(dataGridView2->Columns->Count<=it)
		{
			dataGridView2->ColumnCount = it + 1;
			dataGridView2->Columns[it]->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridView2->Columns[it]->DefaultCellStyle->BackColor = System::Drawing::Color::LightYellow;
			dataGridView2->Columns[it]->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightYellow;
			dataGridView2->Columns[it]->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			

		}

		dataGridView2->Columns[it]->HeaderText = "FIT Itera��o "+Convert::ToString(it-1);
		menor=numClass*numClass;
		deadlock=0;
		for(int i=0;i<(numClass-undefinedClasses()); i++)
		{
			if(!ListaClassesIntegradas[i])
			{
				total=0;
				for(int j=0; j<numClass; j++)
				{
					if(!ListaClassesIntegradas[j])
					{
						total+=MatrizInfluencia[j,i]*FI[j];
					}
				}
				dataGridView2->Rows[i]->Cells[it]->Value = Convert::ToString(total);
					
				if(total<menor)
				{
					menor=total;
					deadlock=0;
					ListaDeadLock[deadlock]=i;
				}
				else if(total==menor)
				{
					deadlock++;
					ListaDeadLock[deadlock]=i;
				}
			}
		   else
		   {
			   //FOrdenador->Iteracao->Cells[it][i+1]="-";
			   dataGridView2->Rows[i]->Cells[it]->Value = "-"; 
		   }
		}
		if(NumClasInteg<numClass)
		{
			if(deadlock==0)
			{
				LCOTI[classInt] = ListaDeadLock[0];
				//ListaClassesIntegradas[classInt] = ListaDeadLock[0];
				classInt++;
				ListaClassesIntegradas[ListaDeadLock[0]]=1;
			}
			else
			{
				resolverDeadlock(deadlock+1,ListaDeadLock,ListaClassesIntegradas);
			}
			 NumClasInteg+=deadlock+1;
		}

	}

	for(int i=0;i<totUltimos; i++)
	{
		LCOTI[classInt]=ListaUltimos[i];
		//ListaClassesIntegradas[classInt]=ListaUltimos[i];
		classInt++;
	}
}

private: System::Void createTable()
{
	dataGridView2->Visible = true;
	
	//int numClass = MatClass->Length/5;
	int j = 0;

	for(int n=0;n<(numClass-undefinedClasses()-1);n++)
	{
		dataGridView2->Rows->Add();
	}

	for(int i=0;i<numClass;i++)
	{
		if(j<numClass)
		{
			if(MatClass[j,0]->IsNullOrEmpty(MatClass[j,0]))
			{
				j=i+1;
			}
			if(j<numClass)
			{
				dataGridView2->Rows[i]->Cells[0]->Value = MatClass[j,0];
				j++;
			}
		}
		else
		{
			break;
		}
	}

	LCOTI = gcnew array< int, 1 >(numClass);
	setFICol();
	calcularFI();
	ordemIntegrar();
	imprimeSaida(numClass);
	setNumStubsOriginal(calcularStubs());
	setNumStubsAtual(getNumStubsOriginal());
	setComplexidadeOriginal(calcularComplexidade());
	setComplexidadeAtual(getComplexidadeOriginal());
	
	dataGridView3->Enabled = true;
	dataGridView3->Visible = true;
	dataGridView3->RowCount = 1;
	dataGridView3->ColumnCount = 2;
	dataGridView3->RowHeadersVisible = false;
	dataGridView3->Columns[0]->HeaderText = "Total Stubs";
	dataGridView3->Columns[1]->HeaderText = "Tamanho";
	dataGridView3->Columns[0]->Width = 90;
	dataGridView3->Columns[1]->Width = 76;

	dataGridView4->Enabled = true;
	dataGridView4->Visible = true;
	dataGridView4->RowCount = 1;
	dataGridView4->ColumnCount = 2;
	dataGridView4->RowHeadersVisible = false;
	dataGridView4->Columns[0]->HeaderText = "Total Stubs";
	dataGridView4->Columns[1]->HeaderText = "Tamanho";
	dataGridView4->Columns[0]->Width = 90;
	dataGridView4->Columns[1]->Width = 76;

	dataGridView3->Rows[0]->Cells[0]->Value = getNumStubsOriginal();
	dataGridView3->Rows[0]->Cells[1]->Value = getComplexidadeOriginal();
	dataGridView4->Rows[0]->Cells[0]->Value = getNumStubsAtual();
	dataGridView4->Rows[0]->Cells[1]->Value = getComplexidadeAtual();


}

private: System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
   {  
	  // Abre a caixa para selecionar arquivo
      // Displays an OpenFileDialog so the user can select a Cursor.
      OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
      openFileDialog1->Filter = "XML Files|*.xml";
      openFileDialog1->Title = "Selecione o arquivo XMI";
	  System::String ^filename;
	  bool ^Association = false;

      // Show the Dialog.
      // If the user clicked OK in the dialog and
      // a .XML file was selected, open it.
      if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
		  this->toolStripButton1->Enabled = false;

         // Assign the cursor in the Stream to the Form's Cursor property.
		  filename = openFileDialog1->FileName::get();
		  try 
         {
            // SECTION 1. Create a DOM Document and load the XML data into it.
			System::Xml::XmlDocument ^dom = gcnew System::Xml::XmlDocument();
			dom->Load(filename);
			path = System::IO::Path::GetFullPath(filename);
			this->label4->Text = path;

            // SECTION 2. Initialize the TreeView control.
			treeView1->Nodes->Clear();

			ImageList^ myImageList = gcnew ImageList;
			myImageList->Images->Add(Image::FromFile("./icons/xml.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/classe.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/associacao.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/agregacao.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/heranca.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/dependencia.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/atributo.bmp"));
			myImageList->Images->Add(Image::FromFile("./icons/objeto.bmp"));

			treeView1->ImageList = myImageList;
			// Set the TreeView control's default image and selected image indexes.
			treeView1->ImageIndex = 0;

			System::Windows::Forms::TreeNode ^root = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Collaboration"]["UML:Namespace.ownedElement"]["UML:ClassifierRole"]->GetAttribute("name"));
			root->ImageIndex = 0;
			root->SelectedImageIndex = 0;

			treeView1->Nodes->Add("Modelo: "+root->Text);

			numClass = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Class")->Count;
			
			//Classes
			System::Windows::Forms::TreeNode ^classes = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));
			classes = treeView1->Nodes[0]->Nodes->Add("Classes");
			classes->ImageIndex = 1;
			classes->SelectedImageIndex = 1;

			System::Windows::Forms::TreeNode ^classe = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));
			System::Windows::Forms::TreeNode ^classe1 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^classe2 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^classe3 = gcnew System::Windows::Forms::TreeNode;

			System::Windows::Forms::TreeNode ^assoc1 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^assoc2 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^assoc3 = gcnew System::Windows::Forms::TreeNode;

			System::Windows::Forms::TreeNode ^agreg1 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^agreg2 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^agreg3 = gcnew System::Windows::Forms::TreeNode;

			System::Windows::Forms::TreeNode ^her1 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^her2 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^her3 = gcnew System::Windows::Forms::TreeNode;

			System::Windows::Forms::TreeNode ^depend1 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^depend11 = gcnew System::Windows::Forms::TreeNode;
			System::Windows::Forms::TreeNode ^depend12 = gcnew System::Windows::Forms::TreeNode;			
			
			//Matriz de Classes
			//[Class_name, xmi.id, FI, tamanho, No conectores]
			MatClass = gcnew array< String^, 2 >(numClass, 5);

			//Lista de tags de classes
			//System::Xml::XmlNamespaceManager^ nsmgr = gcnew System::Xml::XmlNamespaceManager(dom->NameTable);
			//nsmgr->AddNamespace("", "omg.org/UML1.3");
			//System::Xml::XmlNodeList ^lclasses = dom->SelectNodes("/XMI/XMI.content/'UML:Model'/'UML:Namespace.ownedElement'/'UML:Package'/'UML:Namespace.ownedElement'/'UML:Package'/'UML:Namespace.ownedElement'/'UML:Class'",nsmgr);
			System::Xml::XmlNodeList ^lclasses = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Class");


			//TODO: Verificar como retirar classe <undefined> da lclasses antes de pegar valores da lclasses
			for(int i=0; i<numClass;i++)
			{				
				//if(lclasses[i]->Attributes->Item(0)->InnerText!="<undefined>")
				//{
					//Insere o nome de cada classe na matriz de classes
					MatClass[i,0] = lclasses[i]->Attributes->Item(0)->InnerText;
					
					//Insere a ID de cada classe na matriz de classes
					MatClass[i,1] = lclasses[i]->Attributes->Item(1)->InnerText;

					MatClass[i,2] = (0).ToString();
				//}
			}
			

			//Matriz de Associa��es e Composi��o/Agrega��o
			//[direction, source, target, src_isNavigable, tgt_isNavigable]
			MatAssoc = gcnew array< String^, 2 >(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Association")->Count, 5);

			try{
				//Lista de tags de associa��es
				System::Xml::XmlNodeList ^lassoc = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Association");

				int j = 0;

				for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Association")->Count; i++)
				{
					MatAssoc[j,0]=lassoc[i]->FirstChild->ChildNodes[2]->Attributes->Item(1)->InnerText;
					MatAssoc[j,1]=lassoc[i]->FirstChild->ChildNodes[10]->Attributes->Item(1)->InnerText;
					MatAssoc[j,2]=lassoc[i]->FirstChild->ChildNodes[11]->Attributes->Item(1)->InnerText;
					MatAssoc[j,3]=lassoc[i]->ChildNodes[1]->FirstChild->FirstChild->FirstChild->Attributes->Item(1)->InnerText;
					MatAssoc[j,4]=lassoc[i]->ChildNodes[1]->ChildNodes[1]->FirstChild->FirstChild->Attributes->Item(1)->InnerText;
					
					j++;
				}
				Association = true;
			}
			catch(Exception ^e){
			}

			//Matriz de Heran�as
			MatHer = gcnew array< String^, 2 >(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Generalization")->Count, 2);

			//Lista de tags de Heran�a
			System::Xml::XmlNodeList ^lher = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Generalization");

			for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Generalization")->Count;i++)
			{				
				String ^sub_id = lher[i]->Attributes->Item(0)->InnerText;
				String ^super_id = lher[i]->Attributes->Item(1)->InnerText;

				String ^sub = getClassName(MatClass,sub_id);
				String ^super = getClassName(MatClass,super_id);

				MatHer[i,0] = super;
				MatHer[i,1] = sub;
			}

			//Matriz de Depend�ncias
			//[supplier, client]
			MatDepend = gcnew array< String^, 2 >(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Dependency")->Count, 2);

			//Lista de tags de depend�ncias
			System::Xml::XmlNodeList ^ldepend = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Dependency");

			for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Dependency")->Count;i++)
			{	
				String ^client;
				String ^supplier;

				for(int j=0; j<numClass; j++)
				{
				  if(MatClass[j,1]==ldepend[i]->Attributes->Item(0)->InnerText)
				  {
					  client = MatClass[j,0];
				  }
				}

				for(int j=0; j<numClass; j++)
				{
				  if(MatClass[j,1]==ldepend[i]->Attributes->Item(1)->InnerText)
				  {
					  supplier = MatClass[j,0];
				  }
				}

				MatDepend[i,0] = supplier;
				MatDepend[i,1] = client;
			}



			//Reconhece Fator de Influ�ncia, Tamanho e N�mero de Conectores para cada classe

			int j = 0;
			for(int i=0; i<numClass;i++)
			{				
				

				
				if(lclasses[i]->Attributes->Item(0)->InnerText!="<undefined>")
				{
					
					int classSize = 0;
			
					try
					{
						classSize = lclasses[i]["UML:Classifier.feature"]->ChildNodes->Count;
					}
					catch(Exception ^e){
					}

					//Insere o tamanho de cada classe na matriz de classes
					MatClass[i,3] = classSize.ToString(); 
					
					//Insere o n�mero de conectores de cada classe na matriz de classes
					MatClass[i,4] = getConectorsNumber(MatClass[i,0])->ToString();
				}
						
					
			}

			updateMatClass();

			lstClass = gcnew array< String^, 1 >(numClass);
			for(int i=0;i<numClass;i++)
			{
				lstClass[i] = MatClass[i,0];
			}
			//ordenarClasses();

			MatrizInfluencia = gcnew array< int, 2 >(numClass, numClass);

			for(int i=0;i<numClass;i++)
			{
				for(int j=0;j<numClass;j++)
				{
					MatrizInfluencia[i,j] = 0;
				}
			}

			//Associa��es
			System::Windows::Forms::TreeNode ^assoc = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			assoc = treeView1->Nodes[0]->Nodes->Add("Associa��es: ");
			
			assoc->ImageIndex = 2;
			assoc->SelectedImageIndex = 2;

			if(Association)
			{
				for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Association")->Count;i++)
				{
					int c1 = getContador(MatAssoc[i,1]);
					int c2 = getContador(MatAssoc[i,2]);

					if(MatAssoc[i,0]=="Unspecified")
					{
						assoc1 = assoc->Nodes->Add("Associa��o: "+MatAssoc[i,1]+" -- "+MatAssoc[i,2]);
						assoc1->ImageIndex = 6;
						assoc1->SelectedImageIndex = 6;

						MatClass[c1,2] = (Convert::ToInt32(MatClass[c1,2])+1-MatrizInfluencia[c1,c2]).ToString();
						MatClass[c2,2] = (Convert::ToInt32(MatClass[c2,2])+1-MatrizInfluencia[c2,c1]).ToString();

						MatrizInfluencia[c1,c2] = 1;
						MatrizInfluencia[c2,c1] = 1;

						assoc2 = assoc1->Nodes->Add("Origem: "+MatAssoc[i,1]+" - Naveg�vel: "+isNavigable(MatAssoc[i,3])->ToString());
						assoc2->ImageIndex = 7;
						assoc2->SelectedImageIndex = 7;

						assoc3 = assoc1->Nodes->Add("Destino: "+MatAssoc[i,2]+" - Naveg�vel: "+isNavigable(MatAssoc[i,4])->ToString());
						assoc3->ImageIndex = 7;
						assoc3->SelectedImageIndex = 7;
					}
					else if(MatAssoc[i,0]=="Source -> Destination")
					{
						if(isNavigable(MatAssoc[i,3])->ToString()=="True")
						{
							assoc1 = assoc->Nodes->Add("Associa��o: "+MatAssoc[i,2]+" --> "+MatAssoc[i,1]);
							assoc1->ImageIndex = 6;
							assoc1->SelectedImageIndex = 6;

							MatClass[c1,2] = (Convert::ToInt32(MatClass[c1,2])+1-MatrizInfluencia[c1,c2]).ToString();

							MatrizInfluencia[c1,c2] = 1;
						}
						else
						{
							assoc1 = assoc->Nodes->Add("Associa��o: "+MatAssoc[i,1]+" --> "+MatAssoc[i,2]);
							assoc1->ImageIndex = 6;
							assoc1->SelectedImageIndex = 6;

							MatClass[c2,2] = (Convert::ToInt32(MatClass[c2,2])+1-MatrizInfluencia[c2,c1]).ToString();

							MatrizInfluencia[c2,c1] = 1;
						}

						assoc2 = assoc1->Nodes->Add("Origem: "+MatAssoc[i,1]+" - Naveg�vel: "+isNavigable(MatAssoc[i,3])->ToString());
						assoc2->ImageIndex = 7;
						assoc2->SelectedImageIndex = 7;

						assoc3 = assoc1->Nodes->Add("Destino: "+MatAssoc[i,2]+" - Naveg�vel: "+isNavigable(MatAssoc[i,4])->ToString());
						assoc3->ImageIndex = 7;
						assoc3->SelectedImageIndex = 7;
					}					
				}
			}


			//Composi��o/Agrega��o
			System::Windows::Forms::TreeNode ^agreg = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			agreg = treeView1->Nodes[0]->Nodes->Add("Composi��o/Agrega��o: ");
			
			agreg->ImageIndex = 3;
			agreg->SelectedImageIndex = 3;

			if(Association)
			{
				for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Association")->Count;i++)
				{
					int c1 = getContador(MatAssoc[i,1]);
					int c2 = getContador(MatAssoc[i,2]);

					if(MatAssoc[i,0]=="Bi-Directional")
					{
						agreg1 = agreg->Nodes->Add("Associa��o: "+MatAssoc[i,1]+" <>-- "+MatAssoc[i,2]);
						agreg1->ImageIndex = 6;
						agreg1->SelectedImageIndex = 6;

						agreg2 = agreg1->Nodes->Add("Parte: "+MatAssoc[i,2]);
						agreg2->ImageIndex = 7;
						agreg2->SelectedImageIndex = 7;

						agreg3 = agreg1->Nodes->Add("Todo: "+MatAssoc[i,1]);
						agreg3->ImageIndex = 7;
						agreg3->SelectedImageIndex = 7;

						MatClass[c2,2] = (Convert::ToInt32(MatClass[c2,2])+1-MatrizInfluencia[c2,c1]).ToString();

						MatrizInfluencia[c2,c1] = 1;
					}
				}
			}

			//Heran�as
			System::Windows::Forms::TreeNode ^her = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			
			her = treeView1->Nodes[0]->Nodes->Add("Heran�as: ");
			her->ImageIndex = 4;
			her->SelectedImageIndex = 4;

			for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Generalization")->Count;i++)
			{
				int c0 = getContador(MatHer[i,0]);
				int c1 = getContador(MatHer[i,1]);

				her1 = her->Nodes->Add("Heran�a: "+MatHer[i,0]+" <|-- "+MatHer[i,1]);
				her1->ImageIndex = 6;
				her1->SelectedImageIndex = 6;

				her2 = her1->Nodes->Add("Pai: "+MatHer[i,0]);
				her2->ImageIndex = 7;
				her2->SelectedImageIndex = 7;

				her3 = her1->Nodes->Add("Filho: "+MatHer[i,1]);
				her3->ImageIndex = 7;
				her3->SelectedImageIndex = 7;

				MatClass[c0,2] = (Convert::ToInt32(MatClass[c0,2])+1-MatrizInfluencia[c0,c1]).ToString();

				MatrizInfluencia[c0,c1] = 1;
			}

			//Depend�ncia
			System::Windows::Forms::TreeNode ^depend = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			depend = treeView1->Nodes[0]->Nodes->Add("Depend�ncia: ");
			
			depend->ImageIndex = 5;
			depend->SelectedImageIndex = 5;

			for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Dependency")->Count;i++)
			{	
				int c0 = getContador(MatDepend[i,0]);
				int c1 = getContador(MatDepend[i,1]);

				depend1 = depend->Nodes->Add("Depend�ncia: "+MatDepend[i,0]+" <-- "+MatDepend[i,1]);
				depend1->ImageIndex = 6;
				depend1->SelectedImageIndex = 6;					
				
				depend11 = depend1->Nodes->Add("Cliente: "+MatDepend[i,1]);
				depend11->ImageIndex = 7;
				depend11->SelectedImageIndex = 7;
				
				depend12 = depend1->Nodes->Add("Fornecedor: "+MatDepend[i,0]);
				depend12->ImageIndex = 7;
				depend12->SelectedImageIndex = 7;

				MatClass[c0,2] = (Convert::ToInt32(MatClass[c0,2])+1-MatrizInfluencia[c0,c1]).ToString();

				MatrizInfluencia[c0,c1] = 1;
			}

			//Classes
			for(int i=0; i<numClass;i++)
			{				
				//if(lclasses[i]->Attributes->Item(0)->InnerText!="<undefined>")
				//{
					classe = classes->Nodes->Add("Classe: "+MatClass[i,0]);
					classe->ImageIndex = 6;
					classe->SelectedImageIndex = 6;

					classe1 = classe->Nodes->Add("Fator de Influ�ncia: "+ MatClass[i,2]);
					classe1->ImageIndex = 7;
					classe1->SelectedImageIndex = 7;

					classe2 = classe->Nodes->Add("Tamanho: "+MatClass[i,3]);
					classe2->ImageIndex = 7;
					classe2->SelectedImageIndex = 7;

					classe3 = classe->Nodes->Add("N�mero de Conectores: "+MatClass[i,4]);
					classe3->ImageIndex = 7;
					classe3->SelectedImageIndex = 7;
				//}
			}
			
			classes->ImageIndex = 1;
			classes->SelectedImageIndex = 1;

			treeView1->Nodes[0]->Expand();
         }
		  catch(System::Xml::XmlException ^xmlEx)
         {
			 MessageBox::Show(xmlEx->Message);
         }
		  catch(System::Exception ^ex)
         {
			 MessageBox::Show(ex->Message);
         }

		  this->toolStripButton2->Enabled = true;
		  this->toolStripButton3->Enabled = true;
      }
	  
}

private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void splitContainer1_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void splitContainer3_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void toolStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }


private: System::Void label3_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void splitContainer4_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void splitContainer2_SplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
		 }
private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FSobre ^ F = gcnew FSobre();
			 F->Show();
		 }

private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		 }
private: System::Void splitContainer2_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void label4_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }

/*---------------------------------------------------------------------------
Procedimento que inicializa a tela para um novo modelo, ou seja, limpa os campos existentes na tela e remove objetos
---------------------------------------------------------------------------*/
System::Void liberarMemoria()
{
	treeView1->Nodes->Clear();
	label4->Text = "";
	dataGridView2->ColumnCount = 2;
	dataGridView2->RowCount = 1;
	dataGridView2->Rows[0]->Cells[0]->Value = "";
	dataGridView2->Rows[0]->Cells[1]->Value = "";

	dataGridView3->ColumnCount = 2;
	dataGridView3->RowCount = 1;
	dataGridView3->Rows[0]->Cells[0]->Value = "";
	dataGridView3->Rows[0]->Cells[1]->Value = "";

	dataGridView4->ColumnCount = 2;
	dataGridView4->RowCount = 1;
	dataGridView4->Rows[0]->Cells[0]->Value = "";
	dataGridView4->Rows[0]->Cells[1]->Value = "";
	dataGridView2->Visible = false;
	toolStripButton1->Enabled = true;
	toolStripButton2->Enabled = false;
	toolStripButton3->Enabled = false;
	moverCima->Enabled = false;
	moverBaixo->Enabled = false;
	dataGridView1->ColumnCount = 0;
	dataGridView1->RowCount = 0;
	dataGridView1->Visible = false;
	dataGridView3->Visible = true;
	dataGridView4->Visible = true;
	dataGridView1->Enabled = false;
	dataGridView3->Enabled = false;
	dataGridView4->Enabled = false;
	LCOTI->Clear;
}
//Procedimento que inicializa a tela para um novo modelo, ou seja, limpa os campos existentes na tela e remove objetos
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e)
{
	liberarMemoria();
}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {

			 createTable();
			 toolStripButton3->Enabled = false;
			 moverCima->Enabled = true;
			 moverBaixo->Enabled = true;

		 }

/*---------------------------------------------------------------------------
Procedimento respons�vel pela troca da ordem de uma classe da lista de classes gerada
com um classe que est� acima na lista. Al�m disso, recalcula o esfor�o de teste para a nova ordem
---------------------------------------------------------------------------*/
private: System::Void moverCima_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(dataGridView1->SelectedRows[0]->Index>0)
	{
		int aux = getOrdemClass(dataGridView1->SelectedRows[0]->Index);
		int pos = dataGridView1->SelectedRows[0]->Index;

		setOrdemClass(dataGridView1->SelectedRows[0]->Index,getOrdemClass(dataGridView1->SelectedRows[0]->Index-1));
		setOrdemClass(dataGridView1->SelectedRows[0]->Index-1,aux);

		dataGridView1->ColumnCount = 1;
		dataGridView1->RowCount = 1;
		dataGridView1->Rows[0]->Cells[0]->Value = "";

		imprimeSaida(numClass);
		setNumStubsAtual(calcularStubs());
		setComplexidadeAtual(calcularComplexidade());
		dataGridView3->Rows[0]->Cells[0]->Value = Convert::ToString(getNumStubsAtual());
		dataGridView3->Rows[0]->Cells[1]->Value = Convert::ToString(getComplexidadeAtual());

		dataGridView1->Rows[pos-1]->Selected = true;

	}
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }

/*---------------------------------------------------------------------------
Procedimento respons�vel pela troca da ordem de uma classe da lista de classes gerada
com um classe que est� abaixo na lista. Al�m disso, recalcula o esfor�o de teste para a nova ordem
---------------------------------------------------------------------------*/
private: System::Void moverBaixo_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(dataGridView1->SelectedRows[0]->Index<numClass-1)
	{
		int aux = getOrdemClass(dataGridView1->SelectedRows[0]->Index);
		int pos = dataGridView1->SelectedRows[0]->Index;

		setOrdemClass(dataGridView1->SelectedRows[0]->Index,getOrdemClass(dataGridView1->SelectedRows[0]->Index+1));
		setOrdemClass(dataGridView1->SelectedRows[0]->Index+1,aux);

		dataGridView1->ColumnCount = 1;
		dataGridView1->RowCount = 1;
		dataGridView1->Rows[0]->Cells[0]->Value = "";

		imprimeSaida(numClass);
		setNumStubsAtual(calcularStubs());
		setComplexidadeAtual(calcularComplexidade());
		dataGridView3->Rows[0]->Cells[0]->Value = Convert::ToString(getNumStubsAtual());
		dataGridView3->Rows[0]->Cells[1]->Value = Convert::ToString(getComplexidadeAtual());

		dataGridView1->Rows[pos+1]->Selected = true;

	}
}
private: System::Void mudarIdiomaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Idioma ^ Id = gcnew Idioma();
			 Id->Show();
		 }
private: System::Void fun��esToolStripMenuItem_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};

}

