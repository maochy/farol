#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Farol {

	/// <summary>
	/// Summary for Idioma
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Idioma : public System::Windows::Forms::Form
	{
	public:
		int ID;
		Idioma(void)
		{
			InitializeComponent();
			IdiomaBox->SelectedIndex = 0;
			ID = 1;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Idioma()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OKButton;
	protected: 

	protected: 

	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::ComboBox^  IdiomaBox;



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
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->IdiomaBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// OKButton
			// 
			this->OKButton->Location = System::Drawing::Point(259, 28);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 1;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &Idioma::OKButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(361, 28);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 2;
			this->CancelButton->Text = L"Cancelar";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &Idioma::CancelButton_Click);
			// 
			// IdiomaBox
			// 
			this->IdiomaBox->FormattingEnabled = true;
			this->IdiomaBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Português", L"Inglês"});
			this->IdiomaBox->Location = System::Drawing::Point(31, 28);
			this->IdiomaBox->Name = L"IdiomaBox";
			this->IdiomaBox->Size = System::Drawing::Size(185, 21);
			this->IdiomaBox->TabIndex = 3;
			// 
			// Idioma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 73);
			this->Controls->Add(this->IdiomaBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OKButton);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Idioma";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Selecionar um idioma";
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	Idioma::Close();
}

private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	ID = IdiomaBox->SelectedIndex;
	Idioma::Close();
}
};
}
