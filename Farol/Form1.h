#include "FSobre.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^  funçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  opçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  configuraçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirArquivoXMIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gerarOrdenaçãoCtrlGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fecharArquivoCtrlFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  slavarResultadoCtrlBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importarResultadoCtrlIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  imprimirResultadoCtrlToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  painelDeModeloDeClasseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  painelDeSequênciaDeOrdenaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  mudarIdiomaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  conteúdoToolStripMenuItem;
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
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TreeView^  treeView1;
























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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->funçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirArquivoXMIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gerarOrdenaçãoCtrlGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fecharArquivoCtrlFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->slavarResultadoCtrlBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importarResultadoCtrlIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->imprimirResultadoCtrlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configuraçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->painelDeModeloDeClasseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mudarIdiomaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->conteúdoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
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
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->funçõesToolStripMenuItem, 
				this->opçõesToolStripMenuItem, this->configuraçõesToolStripMenuItem, this->ajudaToolStripMenuItem, this->sairToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(836, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// funçõesToolStripMenuItem
			// 
			this->funçõesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->abrirArquivoXMIToolStripMenuItem, 
				this->gerarOrdenaçãoCtrlGToolStripMenuItem, this->fecharArquivoCtrlFToolStripMenuItem});
			this->funçõesToolStripMenuItem->Name = L"funçõesToolStripMenuItem";
			this->funçõesToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->funçõesToolStripMenuItem->Text = L"Funções";
			// 
			// abrirArquivoXMIToolStripMenuItem
			// 
			this->abrirArquivoXMIToolStripMenuItem->Name = L"abrirArquivoXMIToolStripMenuItem";
			this->abrirArquivoXMIToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->abrirArquivoXMIToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->abrirArquivoXMIToolStripMenuItem->Text = L"Abrir Arquivo XMI ";
			this->abrirArquivoXMIToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// gerarOrdenaçãoCtrlGToolStripMenuItem
			// 
			this->gerarOrdenaçãoCtrlGToolStripMenuItem->Name = L"gerarOrdenaçãoCtrlGToolStripMenuItem";
			this->gerarOrdenaçãoCtrlGToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->gerarOrdenaçãoCtrlGToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->gerarOrdenaçãoCtrlGToolStripMenuItem->Text = L"Gerar Ordenação ";
			// 
			// fecharArquivoCtrlFToolStripMenuItem
			// 
			this->fecharArquivoCtrlFToolStripMenuItem->Name = L"fecharArquivoCtrlFToolStripMenuItem";
			this->fecharArquivoCtrlFToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->fecharArquivoCtrlFToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->fecharArquivoCtrlFToolStripMenuItem->Text = L"Fechar Arquivo";
			// 
			// opçõesToolStripMenuItem
			// 
			this->opçõesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->slavarResultadoCtrlBToolStripMenuItem, 
				this->importarResultadoCtrlIToolStripMenuItem, this->toolStripSeparator1, this->imprimirResultadoCtrlToolStripMenuItem});
			this->opçõesToolStripMenuItem->Name = L"opçõesToolStripMenuItem";
			this->opçõesToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->opçõesToolStripMenuItem->Text = L"Opções";
			// 
			// slavarResultadoCtrlBToolStripMenuItem
			// 
			this->slavarResultadoCtrlBToolStripMenuItem->Name = L"slavarResultadoCtrlBToolStripMenuItem";
			this->slavarResultadoCtrlBToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->slavarResultadoCtrlBToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->slavarResultadoCtrlBToolStripMenuItem->Text = L"Salvar Resultado";
			// 
			// importarResultadoCtrlIToolStripMenuItem
			// 
			this->importarResultadoCtrlIToolStripMenuItem->Name = L"importarResultadoCtrlIToolStripMenuItem";
			this->importarResultadoCtrlIToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			this->importarResultadoCtrlIToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->importarResultadoCtrlIToolStripMenuItem->Text = L"Importar Resultado";
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
			this->imprimirResultadoCtrlToolStripMenuItem->Text = L"Imprimir Resultado";
			// 
			// configuraçõesToolStripMenuItem
			// 
			this->configuraçõesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->painelDeModeloDeClasseToolStripMenuItem, 
				this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem, this->toolStripSeparator2, this->mudarIdiomaToolStripMenuItem});
			this->configuraçõesToolStripMenuItem->Name = L"configuraçõesToolStripMenuItem";
			this->configuraçõesToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::M));
			this->configuraçõesToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->configuraçõesToolStripMenuItem->Text = L"Configurações";
			// 
			// painelDeModeloDeClasseToolStripMenuItem
			// 
			this->painelDeModeloDeClasseToolStripMenuItem->Checked = true;
			this->painelDeModeloDeClasseToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->painelDeModeloDeClasseToolStripMenuItem->Name = L"painelDeModeloDeClasseToolStripMenuItem";
			this->painelDeModeloDeClasseToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->painelDeModeloDeClasseToolStripMenuItem->Text = L"Painel de Modelo de Classes";
			// 
			// painelDeSequênciaDeOrdenaçãoToolStripMenuItem
			// 
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem->Checked = true;
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem->Name = L"painelDeSequênciaDeOrdenaçãoToolStripMenuItem";
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->painelDeSequênciaDeOrdenaçãoToolStripMenuItem->Text = L"Painel de Sequência de Ordenação";
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
			this->mudarIdiomaToolStripMenuItem->Text = L"Mudar Idioma";
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->conteúdoToolStripMenuItem, 
				this->sobreToolStripMenuItem});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// conteúdoToolStripMenuItem
			// 
			this->conteúdoToolStripMenuItem->Name = L"conteúdoToolStripMenuItem";
			this->conteúdoToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->conteúdoToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->conteúdoToolStripMenuItem->Text = L"Conteúdo";
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sobreToolStripMenuItem_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->sairToolStripMenuItem->Text = L"Sair";
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
			this->toolStrip1->Size = System::Drawing::Size(836, 46);
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
			this->toolStripButton1->ToolTipText = L"Abrir Arquivo XMI";
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
			this->toolStripButton3->ToolTipText = L"Gerar Ordenação";
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
			this->toolStripButton2->ToolTipText = L"Fechar Arquivo";
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
			this->toolStripButton4->ToolTipText = L"Salvar Resultado";
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
			this->toolStripButton5->ToolTipText = L"Importar Resultado";
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
			this->toolStripButton6->ToolTipText = L"Imprimir Resultado";
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
			this->toolStripButton7->ToolTipText = L"Ajuda";
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
			this->toolStripButton8->ToolTipText = L"Sair";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &Form1::toolStripButton8_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(15, 2);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label1->Size = System::Drawing::Size(99, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Arquivo XMI";
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
			this->splitContainer2->Panel2->Controls->Add(this->label2);
			this->splitContainer2->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer2->Size = System::Drawing::Size(836, 27);
			this->splitContainer2->SplitterDistance = 132;
			this->splitContainer2->TabIndex = 3;
			this->splitContainer2->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Form1::splitContainer2_SplitterMoved);
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
			this->splitContainer1->IsSplitterFixed = true;
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
			this->splitContainer1->Size = System::Drawing::Size(836, 326);
			this->splitContainer1->SplitterDistance = 231;
			this->splitContainer1->TabIndex = 4;
			// 
			// treeView1
			// 
			this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView1->Location = System::Drawing::Point(-2, -2);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(230, 324);
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
			this->groupBox2->Location = System::Drawing::Point(3, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(594, 324);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sequência de Ordenação";
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
			this->splitContainer4->Size = System::Drawing::Size(584, 136);
			this->splitContainer4->SplitterDistance = 97;
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
			this->panel1->Location = System::Drawing::Point(-2, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(584, 100);
			this->panel1->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(186, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Ordem de Integração";
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
			this->splitContainer3->Location = System::Drawing::Point(3, 160);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer3->Panel1->Controls->Add(this->dataGridView1);
			this->splitContainer3->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer3->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer3_Panel1_Paint);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer3->Panel2->Controls->Add(this->button2);
			this->splitContainer3->Panel2->Controls->Add(this->button1);
			this->splitContainer3->Panel2->Controls->Add(this->groupBox3);
			this->splitContainer3->Panel2->Controls->Add(this->groupBox1);
			this->splitContainer3->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer3->Size = System::Drawing::Size(584, 164);
			this->splitContainer3->SplitterDistance = 414;
			this->splitContainer3->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(-2, -2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(412, 162);
			this->dataGridView1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Enabled = false;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(3, 135);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(158, 25);
			this->button2->TabIndex = 3;
			this->button2->Text = L"mover para baixo";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Enabled = false;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(3, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"mover para cima";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->panel3);
			this->groupBox3->Location = System::Drawing::Point(3, 53);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(158, 54);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ordem alterada";
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Location = System::Drawing::Point(2, 14);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(153, 36);
			this->panel3->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Location = System::Drawing::Point(3, -1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(158, 54);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ordem original";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(2, 14);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(153, 37);
			this->panel2->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk_1);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 430);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(836, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 452);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Farol Tool: Ordenador de Classes para Teste de Integração";
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
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
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
			 String^ msg("Confirmar a saída do programa?");

			 if (MessageBox::Show(msg,"Saída do Programa",MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
				 Application::Exit();
			 }
		 }
private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ msg("Confirmar a saída do programa?");

			 if (MessageBox::Show(msg,"Saída do Programa",MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
				 Application::Exit();
			 }
		 }
private: System::Void openFileDialog1_FileOk_1(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }

private: System::Void AddNode(System::Xml::XmlNode^ inXmlNode, Windows::Forms::TreeNode^ inTreeNode)
   {
	  System::Xml::XmlNode ^xNode;
      System::Windows::Forms::TreeNode ^tNode;
	  System::Xml::XmlNodeList ^nodeList;
      int i;

      // Loop through the XML nodes until the leaf is reached.
      // Add the nodes to the TreeView during the looping process.
	  if (inXmlNode->HasChildNodes)
      {
		 nodeList = inXmlNode->ChildNodes;
         for(i = 0; i<=nodeList->Count - 1; i++)
         {
            xNode = inXmlNode->ChildNodes[i];
			System::Windows::Forms::TreeNode ^NewNode = gcnew TreeNode (xNode->Name);

            inTreeNode->Nodes->Add(NewNode);
            tNode = inTreeNode->Nodes[i];
            AddNode(xNode, tNode);
         }
      }
      else
      {
         // Here you need to pull the data from the XmlNode based on the
         // type of node, whether attribute values are required, and so forth.
         inTreeNode->Text = (inXmlNode->OuterXml)->Trim();
      }

		 }
private: System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
   {            
	  
	  // Abre a caixa para selecionar arquivo
      // Displays an OpenFileDialog so the user can select a Cursor.
      OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
      openFileDialog1->Filter = "XML Files|*.xml";
      openFileDialog1->Title = "Selecione o arquivo XMI";
	  System::String ^filename;

      // Show the Dialog.
      // If the user clicked OK in the dialog and
      // a .XML file was selected, open it.
      if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
         // Assign the cursor in the Stream to
         // the Form's Cursor property.
		  filename = openFileDialog1->FileName::get();
		  try 
         {
            // SECTION 1. Create a DOM Document and load the XML data into it.
			System::Xml::XmlDocument ^dom = gcnew System::Xml::XmlDocument();
			dom->Load(filename);

            // SECTION 2. Initialize the TreeView control.
			treeView1->Nodes->Clear();
			//To do
			//tNode->Name("Olá");

			ImageList^ myImageList = gcnew ImageList;
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/xml.bmp"));
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/classe.bmp"));
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/associacao.bmp"));
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/agregacao.bmp"));
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/heranca.bmp"));
			myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/dependencia.bmp"));
						myImageList->Images->Add(Image::FromFile("E:/Documents/Visual Studio 2008/Projects/Farol 2.0/Farol/icons/atributo.bmp"));

			treeView1->ImageList = myImageList;
			// Set the TreeView control's default image and selected image indexes.
			treeView1->ImageIndex = 0;

			System::Windows::Forms::TreeNode ^root = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Collaboration"]["UML:Namespace.ownedElement"]["UML:ClassifierRole"]->GetAttribute("name"));
			root->ImageIndex = 0;
			root->SelectedImageIndex = 0;

			treeView1->Nodes->Add("Modelo: "+root->Text);
			
            String ^cname = "";
			//Classes
			System::Windows::Forms::TreeNode ^classes = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));
			classes = treeView1->Nodes[0]->Nodes->Add("Classes");
			classes->ImageIndex = 1;
			classes->SelectedImageIndex = 1;

			System::Windows::Forms::TreeNode ^classe = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));

			System::Xml::XmlNodeList ^lclasses = dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Class");

			//classe = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));

			//for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->ChildNodes->Count-1;i++)
			for(int i=0; i<dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]->GetElementsByTagName("UML:Class")->Count;i++)
			{				
				
					//classe = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Package"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));
					//classe = gcnew System::Windows::Forms::TreeNode(lclasses[i]->ChildNodes->Item(0)->OwnerDocument::get());
					//classe = classes->Nodes->Add("Classe: "+classe->Text);
					int start = lclasses[i]->OuterXml::get()->IndexOf("=")+2;
					int end = lclasses[i]->OuterXml::get()->IndexOf("xmi.id")-19;
					classe = classes->Nodes->Add("Classe: "+lclasses[i]->OuterXml::get()->Substring(start,end));
					classe->ImageIndex = 6;
					classe->SelectedImageIndex = 6;
					//cname = classe->Text;
					//TO DO: reconhecer todas as classes
					
				
			}
			//System::Windows::Forms::TreeNode ^classesf = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]["UML:Namespace.ownedElement"]["UML:Class"]->GetAttribute("name"));
			//classesf = treeView1->Nodes[0]->Nodes->Add("Classes "+classesf->Text);

			classes->ImageIndex = 1;
			classes->SelectedImageIndex = 1;

			//classes->Expand();

			//Associações
			System::Windows::Forms::TreeNode ^assoc = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			assoc = treeView1->Nodes[0]->Nodes->Add("Associações: ");
			
			assoc->ImageIndex = 2;
			assoc->SelectedImageIndex = 2;

			//Composição/Agregação
			System::Windows::Forms::TreeNode ^agreg = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			agreg = treeView1->Nodes[0]->Nodes->Add("Composição/Agregação: ");
			
			agreg->ImageIndex = 3;
			agreg->SelectedImageIndex = 3;

			//Heranças
			System::Windows::Forms::TreeNode ^her = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			her = treeView1->Nodes[0]->Nodes->Add("Heranças: ");
			
			her->ImageIndex = 4;
			her->SelectedImageIndex = 4;

			//Dependência
			System::Windows::Forms::TreeNode ^depend = gcnew System::Windows::Forms::TreeNode(dom->ChildNodes[2]["XMI.content"]["UML:Model"]->GetAttribute("name"));
			depend = treeView1->Nodes[0]->Nodes->Add("Dependência: ");
			
			depend->ImageIndex = 5;
			depend->SelectedImageIndex = 5;

            // SECTION 3. Populate the TreeView with the DOM nodes.
			//treeView1->ExpandAll();
         }
		  catch(System::Xml::XmlException ^xmlEx)
         {
			 MessageBox::Show(xmlEx->Message);
         }
		  catch(System::Exception ^ex)
         {
			 MessageBox::Show(ex->Message);
         }
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
};
}

