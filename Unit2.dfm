object Form2: TForm2
  Left = 0
  Top = 247
  Caption = #1054#1089#1085#1086#1074#1085#1072#1103' '#1079#1072#1076#1072#1095#1072
  ClientHeight = 596
  ClientWidth = 867
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 8
    Top = 8
    Width = 577
    Height = 465
    OnPaint = PaintBox1Paint
  end
  object Label4: TLabel
    Left = 641
    Top = 13
    Width = 170
    Height = 14
    Caption = #1057#1087#1080#1089#1086#1082' '#1074#1089#1077#1093' '#1082#1086#1086#1088#1076#1080#1085#1072#1090' '#1090#1086#1095#1077#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 626
    Top = 33
    Width = 201
    Height = 256
    ColCount = 3
    RowCount = 2
    FixedRows = 0
    TabOrder = 0
    ColWidths = (
      64
      64
      64)
    RowHeights = (
      24
      24)
  end
  object Button2: TButton
    Left = 626
    Top = 295
    Width = 162
    Height = 57
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1090#1088#1077#1091#1075#1086#1083#1100#1085#1080#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 600
    Top = 392
    object N1: TMenuItem
      Caption = #1055#1086#1089#1090#1072#1085#1086#1074#1082#1072' '#1079#1072#1076#1072#1095#1080
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N3: TMenuItem
        Caption = #1042#1074#1086#1076' '#1074#1088#1091#1095#1085#1091#1102
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1042#1074#1086#1076' '#1089#1083#1091#1095#1072#1081#1085#1099#1093' '#1095#1080#1089#1077#1083
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077
        OnClick = N6Click
      end
      object N7: TMenuItem
      end
    end
  end
end
