//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <algorithm>
#include <vector>

#include "Unit3.h"
#include "Unit2.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

/*
	//brief ���������� ��������� ��������� �����
	//������� ��������� ��������� ���������� ����� � StringGrid
	//param TObject *Sender
*/
vector<int> numbersX;
vector<int> numbersY;
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	int minX = StrToInt(Edit1->Text);
	int maxX = StrToInt(Edit2->Text);
	int minY = StrToInt(Edit3->Text);
	int maxY = StrToInt(Edit4->Text);
	int countPoint = StrToInt(Edit5->Text);

	// ��������� � ������������� �����

	for (int i = minX; i <= maxX; ++i)
	{
		numbersX.push_back(i);
	}
	for (int i = minY; i <= maxY; ++i)
	{
		numbersY.push_back(i);
	}
	random_shuffle(numbersX.begin(), numbersX.end());
	random_shuffle(numbersY.begin(), numbersY.end());

	// ����� ����� � �������
	for (int i = 0; i < countPoint; ++i)
	{
		Form2->StringGrid1->Cells[0][i + 1] = IntToStr(i + 1);
		Form2->StringGrid1->Cells[1][i + 1] = IntToStr(numbersX[i]);
		Form2->StringGrid1->Cells[2][i + 1] = IntToStr(numbersY[i]);
		++Form2->StringGrid1->RowCount;
	}

	Form3->Edit1->Clear();
	Form3->Edit2->Clear();
	Form3->Edit3->Clear();
	Form3->Edit4->Clear();
	Form3->Edit5->Clear();

	Form3->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit2->SetFocus();
}

void __fastcall TForm3::Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Button1->SetFocus();
}

//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit4->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit5->SetFocus();
}
//---------------------------------------------------------------------------


/*
	//brief �������� ��������� �� ��� X
	//������� ��������� �� ������������ ����� ��������� ����� ��������� ������������� �� ��� X
	//param TObject *Sender
*/
void __fastcall TForm3::Edit1Exit(TObject *Sender)
{
    TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) { // ���������, �������� �� ������ ������
			containsLetters = true;
			containsSymbols = true;
			break;
		}
	}

	if (containsLetters || containsSymbols) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 650) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 650");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------


/*
	//brief �������� ��������� �� ��� X
	//������� ��������� �� ������������ ����� ��������� ����� ��������� ������������� �� ��� X
	//param TObject *Sender
*/
void __fastcall TForm3::Edit2Exit(TObject *Sender)
{
	TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) { // ���������, �������� �� ������ ������
			containsLetters = true;
			containsSymbols = true;
			break;
		}
	}

	if (containsLetters || containsSymbols) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������");
		edit->Text = "";
		return;
	}

	if (StrToInt(Edit2->Text) <= StrToInt(Edit1->Text)) {
		edit->SetFocus();
		ShowMessage("maxX �� ����� ���� ������ ��� ����� minX");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 650) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 650");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------


/*
	//brief �������� ��������� �� ��� Y
	//������� ��������� �� ������������ ����� ��������� ����� ��������� ������������� �� ��� Y
	//param TObject *Sender
*/
void __fastcall TForm3::Edit3Exit(TObject *Sender)
{
    TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	bool containsDigits = false; // ���� ��� �������� ������� �����
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i]))
		{
			if (edit->Text[i] != '-')
			{
				containsLetters = true;
				containsSymbols = true;
				break;
			}

			if (i != 1)
			{
				containsSymbols = true;
				break;
			}
		}

		else
		{
			containsDigits = true; // ���� ������� �����, ������������� ����
		}
	}

	if (containsLetters || containsSymbols || !containsDigits) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 250 || number < -250) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 250 � �� ����� ���� ������ -250");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------


/*
	//brief �������� ��������� �� ��� Y
	//������� ��������� �� ������������ ����� ��������� ����� ��������� ������������� �� ��� Y
	//param TObject *Sender
*/
void __fastcall TForm3::Edit4Exit(TObject *Sender)
{
	TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	bool containsDigits = false; // ���� ��� �������� ������� �����
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) {
			if (edit->Text[i] != '-') {
				containsLetters = true;
				containsSymbols = true;
				break;
			}
			if (i != 1) {
				containsSymbols = true;
				break;
			}
		} else {
			containsDigits = true; // ���� ������� �����, ������������� ����
		}
	}

	if (containsLetters || containsSymbols || !containsDigits) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������");
		edit->Text = "";
		return;
	}

	if (StrToInt(Edit4->Text) <= StrToInt(Edit3->Text)) {
		edit->SetFocus();
		ShowMessage("maxY �� ����� ���� ������ ��� ����� minY");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	if (number > 250 || number < -250) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ��������� 250 � �� ����� ���� ������ -250");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------


/*
	//brief �������� ����� ���������� �����
	//������� ��������� �� ������������ ����� ���������� �����
	//param TObject *Sender
*/
void __fastcall TForm3::Edit5Exit(TObject *Sender)
{
    TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("��������� ����");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) { // ���������, �������� �� ������ ������
			containsLetters = true;
			containsSymbols = true;
			break;
		}
	}

	if (containsLetters || containsSymbols) {
		edit->SetFocus();
		ShowMessage("�� ����������� ���� ���� � ��������. ����� ������ ���� ���������������");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // ����������� ������ � ����� �����
	 if (number < 3 || number > 500) {
		edit->SetFocus();
		ShowMessage("����� �� ����� ���� ������ 3 � ������ 500");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------







