//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <string>

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;
TForm2 *Form2;

//---------------------------------------------------------------------------

vector<TPoint> points; // Вектор для хранения координат точек
//---------------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

/*
	//brief Вычисление площади треугольника
	//Вычисляется площадь треугольников
	//param const TPoint& p1 - 1 точка, const TPoint& p2 - 2 точка, const TPoint& p3 - 3 точка
*/
double __fastcall CalculateTriangleArea(const TPoint& p1, const TPoint& p2, const TPoint& p3)
{
	return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}
//---------------------------------------------------------------------------

/*
	//brief Постановка задачи
	//Выводится постановка задачи
	//param TObject *Sender
*/
void __fastcall TForm2::N1Click(TObject *Sender)
{
	String message = "Дано множество точек (больше 3),"
					 " необходимо найти треугольник с самой большой площадью,"
					 " который можно из них построить.";

	// Выводим сообщение с объединенным текстом
	ShowMessage(message);
}
//---------------------------------------------------------------------------

/*
	//brief Построение осей координат
	//Функция строит оси координат и деления на них по пикселям
	//param TCanvas* Canvas, int Width - ширина PaintBox, int Height - высота PaintBox
*/
const int AxisOffset = 30; // Смещение осей от края PaintBox
const int TickSize = 5; // Длина засечек на осях
const int TickTextOffset = 10; // Отступ меток делений от осей

void DrawAxes(TCanvas* Canvas, int Width, int Height)
{

	// Очистка Canvas
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(Rect(0, 0, Width, Height));

	// Рисование осей X и Y
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(AxisOffset, Height / 2);
	Canvas->LineTo(Width - AxisOffset, Height / 2);
	Canvas->MoveTo(AxisOffset, AxisOffset);
	Canvas->LineTo(AxisOffset, Height - AxisOffset);

	// Рисование делений на осях X и Y
	int Step = 50; // Шаг делений на осях
	int XPos = AxisOffset + Step;
	int YPos = Height / 2;
	int TextOffset = TickSize + TickTextOffset;

	while (XPos < Width - AxisOffset)
	{
		// Рисование положительных делений на оси X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
		Canvas->LineTo(XPos, Height / 2 + TickSize);
		Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(XPos - AxisOffset));
		XPos += Step; // Переход к следующему делению
	}

	while (YPos > AxisOffset)
	{
		// Рисование положительных делений на оси Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
		Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(Height / 2 - YPos));
		YPos -= Step; // Переход к следующему делению
	}

	// Отрицательные значения на осях
	XPos = AxisOffset - Step; // Начальная позиция X (слева)
	YPos = Height / 2; // Начальная позиция Y (снизу)

	while (XPos > 0)
	{
		// Рисование отрицательных делений на оси X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
		Canvas->LineTo(XPos, Height / 2 + TickSize);
		Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(-(AxisOffset - XPos)));
		XPos -= Step; // Переход к следующему делению слева
	}

	while (YPos < Height)
	{
		// Рисование отрицательных делений на оси Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
		Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(-(YPos - Height / 2)));
		YPos += Step; // Переход к следующему делению сверху
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
	Form1->Caption="Добавление вручную" ;
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

/*
	//brief Удаление координат точек
	//Функция удаляет координаты точки в StringGrid
	//param TCanvas* Canvas, int Width - ширина PaintBox, int Height - высота PaintBox
*/
void __fastcall TForm2::N6Click(TObject *Sender)
{
    int nm= StringGrid1->Selection.Top;
	for(int i=nm; i < StringGrid1->RowCount-1; ++i)
	{
		StringGrid1->Rows[i] = StringGrid1->Rows[i+1];
		StringGrid1->Cells[0][i] = i ;  // Затереть текущую строку следующей
	}
	StringGrid1->RowCount--;     //уменьшить кол-во строк
	ShowMessage("Удаление строки произошло успешно.");
}
//---------------------------------------------------------------------------

/*
	//brief Редактирование координат точек
	//Функция изменяет координаты точки в строке StringGrid
	//param TObject *Sender
*/
void __fastcall TForm2::N5Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Top;//Определяем номер выделенной строки
	Form1->Caption="Редактирование" ;
	Form1->Edit1->Text= Form2->StringGrid1->Cells[1][nm];
	Form1->Edit2->Text= Form2->StringGrid1->Cells[2][nm];
	Form1->Show();
	Form1->Button1->Enabled = false;
}
//---------------------------------------------------------------------------

/*
	//brief Заполниение таблицы заголовками
	//Функция заполняет заголовки в таблице StringGrid
	//param TObject *Sender
*/
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "№ точки"; //колонка-строка
	StringGrid1->Cells[1][0] = "X";
	StringGrid1->Cells[2][0] = "Y";
}
//---------------------------------------------------------------------------

/*
	//brief Выход осей координат
	//Вывод осей координат с помощью функции DrawAxes
	//param TObject *Sender
*/
void __fastcall TForm2::PaintBox1Paint(TObject *Sender)
{
	DrawAxes(PaintBox1->Canvas, PaintBox1->Width, PaintBox1->Height);
}
//---------------------------------------------------------------------------



/*
	//brief Построение треугольника
	//Построение треугольника из точек в таблице StringGrid
	//param TObject *Sender
*/
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	DrawAxes(PaintBox1->Canvas, PaintBox1->Width, PaintBox1->Height);
	PaintBox1->Canvas->Brush->Color = clBlue;
	PaintBox1->Canvas->Pen->Color = clBlack;

	points.clear();

	for (int i = 1; i < StringGrid1->RowCount; i++)
	{
		int x, y;
		if (TryStrToInt(StringGrid1->Cells[1][i], x) && TryStrToInt(StringGrid1->Cells[2][i], y))
		{
			int paintBoxX = AxisOffset + x;
			int paintBoxY = PaintBox1->Height / 2 - y;

			PaintBox1->Canvas->Ellipse(paintBoxX - 3, paintBoxY - 3, paintBoxX + 3, paintBoxY + 3);
		}
	}

	int rowCount = StringGrid1->RowCount - 1;

	if (rowCount < 3)
	{
		ShowMessage("Минимальное количество точек должно быть 3");
		return;
	}

	// Заполняем вектор точками из StringGrid1
	for (int i = 1; i < rowCount; i++)
	{
		int x, y;
		if (TryStrToInt(StringGrid1->Cells[1][i], x) && TryStrToInt(StringGrid1->Cells[2][i], y))
		{
			TPoint point;
			point.x = x;
			point.y = y;
			points.push_back(point);
		}
	}

	double maxArea = 0.0;
	TPoint maxP1, maxP2, maxP3;

	// Перебираем все комбинации из трех точек
	for (int i = 0; i < points.size() - 2; ++i)
	{
		for (int j = i + 1; j < points.size() - 1; ++j)
		{
			for (int k = j + 1; k < points.size(); ++k)
			{
				// Вычисляем площадь треугольника, образованного текущими тремя точками
				double area = CalculateTriangleArea(points[i], points[j], points[k]);

				// Если площадь больше максимальной найденной площади,
				// обновляем максимальную площадь и сохраняем координаты точек треугольника
				if (area > maxArea)
				{
					maxArea = area;
					maxP1 = points[i];
					maxP2 = points[j];
					maxP3 = points[k];
				}
			}
		}
	}

	// Отрисовываем найденный треугольник на PaintBox1
	PaintBox1->Canvas->Brush->Color = clBlue;
	PaintBox1->Canvas->Pen->Color = clBlack;
	PaintBox1->Canvas->MoveTo(AxisOffset + maxP1.x, PaintBox1->Height / 2 - maxP1.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP2.x, PaintBox1->Height / 2 - maxP2.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP3.x, PaintBox1->Height / 2 - maxP3.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP1.x, PaintBox1->Height / 2 - maxP1.y);

	ShowMessage("Площадь треугольника равна:" + FloatToStr(maxArea));

}
//---------------------------------------------------------------------------










