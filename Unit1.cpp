//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

/*
	//brief Добавление точек вручную
	//Функция добавляет координаты точек введенных пользователем в StringGrid и завершает добавление координат
	//param TObject *Sender
*/
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int nrow;

	if (Form1->Caption =="Добавление вручную")
	{  nrow=Form2->StringGrid1->RowCount-2;

	Form2->StringGrid1->Cells[0][nrow]= IntToStr(Form2->StringGrid1->RowCount-1);
	//номер записи

	++Form2->StringGrid1->RowCount; //=Form6->StringGrid1->RowCount+1;

	}
	else  {//Определяем номер строки для редактирования
		  nrow = Form2->StringGrid1->Selection.Top;  // выделенная строка
	}

	Form2->StringGrid1->Cells[0][nrow]=nrow;
	Form2->StringGrid1->Cells[1][nrow]=Edit1->Text;
	Form2->StringGrid1->Cells[2][nrow]=Edit2->Text;
	Form1->Edit1->Clear();
	Form1->Edit2->Clear();

	Form2->Show();
	Form1->Close();
}
//---------------------------------------------------------------------------

/*
	//brief Добавление точек вручную
	//Функция добавляет координаты точек введенных пользователем в StringGrid и продолжает добавление координат
	//param TObject *Sender
*/
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int nrow;

	if (Form1->Caption =="Добавление вручную")
	{  nrow=Form2->StringGrid1->RowCount-1;

	Form2->StringGrid1->Cells[0][nrow]= IntToStr(Form2->StringGrid1->RowCount-1);
	//номер записи

	++Form2->StringGrid1->RowCount; //=Form6->StringGrid1->RowCount+1;

	}
	else  {//Определяем номер строки для редактирования
		  nrow = Form2->StringGrid1->Selection.Top;  // выделенная строка
	}

	Form2->StringGrid1->Cells[0][nrow]=nrow;
	Form2->StringGrid1->Cells[1][nrow]=Edit1->Text;
	Form2->StringGrid1->Cells[2][nrow]=Edit2->Text;
	Form1->Edit1->Clear();
	Form1->Edit2->Clear();

	Form2->Show();
	Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Button1->SetFocus();
}
//---------------------------------------------------------------------------

/*
	//brief Проверка ввода координат по Y
	//Функция проверяет на корректрость ввода координат точек введенных пользователем в StringGrid
	//param TObject *Sender
*/
void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
    TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("Заполните поле");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	bool containsDigits = false; // Флаг для проверки наличия цифры
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
			containsDigits = true; // Если найдена цифра, устанавливаем флаг
		}
	}

	if (containsLetters || containsSymbols || !containsDigits) {
		edit->SetFocus();
		ShowMessage("Не допускается ввод букв и символов");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // Преобразуем строку в целое число
	if (number > 250 || number < -250) {
		edit->SetFocus();
		ShowMessage("Число не может превышать 250 и не может быть меньше -250");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------

/*
	//brief Проверка ввода координат по X
	//Функция проверяет на корректрость ввода координат точек введенных пользователем в StringGrid
	//param TObject *Sender
*/
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	TEdit *edit = dynamic_cast<TEdit *>(Sender);

	if (edit->Text.IsEmpty()) {
		edit->SetFocus();
		ShowMessage("Заполните поле");
		return;
	}

	bool containsLetters = false;
	bool containsSymbols = false;
	for (int i = 1; i <= edit->Text.Length(); ++i) {
		if (!isdigit(edit->Text[i])) { // Проверяем, является ли символ цифрой
			containsLetters = true;
			containsSymbols = true;
			break;
		}
	}

	if (containsLetters || containsSymbols) {
		edit->SetFocus();
		ShowMessage("Не допускается ввод букв и символов");
		edit->Text = "";
		return;
	}

	int number = StrToInt(edit->Text); // Преобразуем строку в целое число
	if (number > 650 || number < 0) {
		edit->SetFocus();
		ShowMessage("Число не может превышать 650");
		edit->Text = "";
		return;
	}
}
//---------------------------------------------------------------------------






