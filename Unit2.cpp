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

vector<TPoint> points; // ������ ��� �������� ��������� �����
//---------------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

/*
	//brief ���������� ������� ������������
	//����������� ������� �������������
	//param const TPoint& p1 - 1 �����, const TPoint& p2 - 2 �����, const TPoint& p3 - 3 �����
*/
double __fastcall CalculateTriangleArea(const TPoint& p1, const TPoint& p2, const TPoint& p3)
{
	return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}
//---------------------------------------------------------------------------

/*
	//brief ���������� ������
	//��������� ���������� ������
	//param TObject *Sender
*/
void __fastcall TForm2::N1Click(TObject *Sender)
{
	String message = "���� ��������� ����� (������ 3),"
					 " ���������� ����� ����������� � ����� ������� ��������,"
					 " ������� ����� �� ��� ���������.";

	// ������� ��������� � ������������ �������
	ShowMessage(message);
}
//---------------------------------------------------------------------------

/*
	//brief ���������� ���� ���������
	//������� ������ ��� ��������� � ������� �� ��� �� ��������
	//param TCanvas* Canvas, int Width - ������ PaintBox, int Height - ������ PaintBox
*/
const int AxisOffset = 30; // �������� ���� �� ���� PaintBox
const int TickSize = 5; // ����� ������� �� ����
const int TickTextOffset = 10; // ������ ����� ������� �� ����

void DrawAxes(TCanvas* Canvas, int Width, int Height)
{

	// ������� Canvas
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(Rect(0, 0, Width, Height));

	// ��������� ���� X � Y
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(AxisOffset, Height / 2);
	Canvas->LineTo(Width - AxisOffset, Height / 2);
	Canvas->MoveTo(AxisOffset, AxisOffset);
	Canvas->LineTo(AxisOffset, Height - AxisOffset);

	// ��������� ������� �� ���� X � Y
	int Step = 50; // ��� ������� �� ����
	int XPos = AxisOffset + Step;
	int YPos = Height / 2;
	int TextOffset = TickSize + TickTextOffset;

	while (XPos < Width - AxisOffset)
	{
		// ��������� ������������� ������� �� ��� X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
		Canvas->LineTo(XPos, Height / 2 + TickSize);
		Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(XPos - AxisOffset));
		XPos += Step; // ������� � ���������� �������
	}

	while (YPos > AxisOffset)
	{
		// ��������� ������������� ������� �� ��� Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
		Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(Height / 2 - YPos));
		YPos -= Step; // ������� � ���������� �������
	}

	// ������������� �������� �� ����
	XPos = AxisOffset - Step; // ��������� ������� X (�����)
	YPos = Height / 2; // ��������� ������� Y (�����)

	while (XPos > 0)
	{
		// ��������� ������������� ������� �� ��� X
		Canvas->MoveTo(XPos, Height / 2 - TickSize);
		Canvas->LineTo(XPos, Height / 2 + TickSize);
		Canvas->TextOutW(XPos - TextOffset, Height / 2 + TextOffset, IntToStr(-(AxisOffset - XPos)));
		XPos -= Step; // ������� � ���������� ������� �����
	}

	while (YPos < Height)
	{
		// ��������� ������������� ������� �� ��� Y
		Canvas->MoveTo(AxisOffset - TickSize, YPos);
		Canvas->LineTo(AxisOffset + TickSize, YPos);
		Canvas->TextOutW(AxisOffset + TickSize + 5, YPos - TextOffset, IntToStr(-(YPos - Height / 2)));
		YPos += Step; // ������� � ���������� ������� ������
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
	Form1->Caption="���������� �������" ;
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

/*
	//brief �������� ��������� �����
	//������� ������� ���������� ����� � StringGrid
	//param TCanvas* Canvas, int Width - ������ PaintBox, int Height - ������ PaintBox
*/
void __fastcall TForm2::N6Click(TObject *Sender)
{
    int nm= StringGrid1->Selection.Top;
	for(int i=nm; i < StringGrid1->RowCount-1; ++i)
	{
		StringGrid1->Rows[i] = StringGrid1->Rows[i+1];
		StringGrid1->Cells[0][i] = i ;  // �������� ������� ������ ���������
	}
	StringGrid1->RowCount--;     //��������� ���-�� �����
	ShowMessage("�������� ������ ��������� �������.");
}
//---------------------------------------------------------------------------

/*
	//brief �������������� ��������� �����
	//������� �������� ���������� ����� � ������ StringGrid
	//param TObject *Sender
*/
void __fastcall TForm2::N5Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Top;//���������� ����� ���������� ������
	Form1->Caption="��������������" ;
	Form1->Edit1->Text= Form2->StringGrid1->Cells[1][nm];
	Form1->Edit2->Text= Form2->StringGrid1->Cells[2][nm];
	Form1->Show();
	Form1->Button1->Enabled = false;
}
//---------------------------------------------------------------------------

/*
	//brief ����������� ������� �����������
	//������� ��������� ��������� � ������� StringGrid
	//param TObject *Sender
*/
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "� �����"; //�������-������
	StringGrid1->Cells[1][0] = "X";
	StringGrid1->Cells[2][0] = "Y";
}
//---------------------------------------------------------------------------

/*
	//brief ����� ���� ���������
	//����� ���� ��������� � ������� ������� DrawAxes
	//param TObject *Sender
*/
void __fastcall TForm2::PaintBox1Paint(TObject *Sender)
{
	DrawAxes(PaintBox1->Canvas, PaintBox1->Width, PaintBox1->Height);
}
//---------------------------------------------------------------------------



/*
	//brief ���������� ������������
	//���������� ������������ �� ����� � ������� StringGrid
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
		ShowMessage("����������� ���������� ����� ������ ���� 3");
		return;
	}

	// ��������� ������ ������� �� StringGrid1
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

	// ���������� ��� ���������� �� ���� �����
	for (int i = 0; i < points.size() - 2; ++i)
	{
		for (int j = i + 1; j < points.size() - 1; ++j)
		{
			for (int k = j + 1; k < points.size(); ++k)
			{
				// ��������� ������� ������������, ������������� �������� ����� �������
				double area = CalculateTriangleArea(points[i], points[j], points[k]);

				// ���� ������� ������ ������������ ��������� �������,
				// ��������� ������������ ������� � ��������� ���������� ����� ������������
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

	// ������������ ��������� ����������� �� PaintBox1
	PaintBox1->Canvas->Brush->Color = clBlue;
	PaintBox1->Canvas->Pen->Color = clBlack;
	PaintBox1->Canvas->MoveTo(AxisOffset + maxP1.x, PaintBox1->Height / 2 - maxP1.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP2.x, PaintBox1->Height / 2 - maxP2.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP3.x, PaintBox1->Height / 2 - maxP3.y);
	PaintBox1->Canvas->LineTo(AxisOffset + maxP1.x, PaintBox1->Height / 2 - maxP1.y);

	ShowMessage("������� ������������ �����:" + FloatToStr(maxArea));

}
//---------------------------------------------------------------------------










