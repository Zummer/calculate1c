object fMainClient: TfMainClient
  Left = 0
  Top = 0
  Caption = #1043#1083#1072#1074#1085#1072#1103' '#1092#1086#1088#1084#1072
  ClientHeight = 190
  ClientWidth = 303
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LabelCurUser: TLabel
    Left = 16
    Top = 9
    Width = 74
    Height = 33
    Caption = #1051#1086#1075#1080#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object bMyBonus: TButton
    Left = 8
    Top = 111
    Width = 139
    Height = 25
    Caption = #1052#1086#1103' '#1079#1072#1088#1087#1083#1072#1090#1072
    TabOrder = 0
    OnClick = bMyBonusClick
  end
  object btFindOrders: TButton
    Left = 8
    Top = 142
    Width = 139
    Height = 25
    Caption = #1055#1086#1080#1089#1082' '#1079#1072#1082#1072#1079#1086#1074
    TabOrder = 1
    OnClick = btFindOrdersClick
  end
  object GroupBox1: TGroupBox
    Left = 153
    Top = 63
    Width = 139
    Height = 120
    Caption = #1050#1072#1083#1100#1082#1091#1083#1103#1090#1086#1088#1099' : '
    TabOrder = 2
    object Button4: TButton
      Left = 14
      Top = 17
      Width = 115
      Height = 25
      Caption = #1047#1072#1082#1072#1079' '#1085#1072' '#1076#1080#1079#1072#1081#1085
      TabOrder = 0
      OnClick = Button4Click
    end
    object Button2: TButton
      Left = 14
      Top = 48
      Width = 115
      Height = 25
      Caption = #1047#1072#1082#1072#1079' '#1092#1086#1090#1086#1082#1085#1080#1075
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button1: TButton
      Left = 14
      Top = 79
      Width = 115
      Height = 25
      Caption = #1057#1073#1086#1088#1085#1099#1081' '#1079#1072#1082#1072#1079
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object btUserChange: TButton
    Left = 8
    Top = 66
    Width = 139
    Height = 25
    Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 3
  end
end
