object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1090#1086#1095#1077#1082' '#1074#1088#1091#1095#1085#1091#1102
  ClientHeight = 197
  ClientWidth = 264
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 24
    Width = 159
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1086#1088#1076#1080#1085#1072#1090#1099' '#1090#1086#1095#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 62
    Width = 49
    Height = 16
    Caption = #1055#1086' '#1086#1089#1080' x'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 32
    Top = 96
    Width = 49
    Height = 16
    Caption = #1055#1086' '#1086#1089#1080' y'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 104
    Top = 68
    Width = 87
    Height = 21
    TabOrder = 0
    OnExit = Edit1Exit
    OnKeyDown = Edit1KeyDown
  end
  object Edit2: TEdit
    Left = 104
    Top = 95
    Width = 87
    Height = 21
    TabOrder = 1
    OnExit = Edit2Exit
    OnKeyDown = Edit2KeyDown
  end
  object Button1: TButton
    Left = 32
    Top = 137
    Width = 89
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1077#1097#1105
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 137
    Width = 79
    Height = 25
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
end
