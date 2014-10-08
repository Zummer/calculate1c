object fConnect: TfConnect
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077' '#1082' 1'#1089
  ClientHeight = 117
  ClientWidth = 350
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 25
    Top = 58
    Width = 76
    Height = 13
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
  end
  object Label2: TLabel
    Left = 25
    Top = 85
    Width = 41
    Height = 13
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object LabelCurUser: TLabel
    Left = 22
    Top = 10
    Width = 299
    Height = 33
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object cbUser: TComboBox
    Left = 120
    Top = 55
    Width = 201
    Height = 21
    DropDownCount = 25
    TabOrder = 1
    Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    OnSelect = cbUserSelect
  end
  object ePass: TEdit
    Left = 120
    Top = 82
    Width = 201
    Height = 21
    PasswordChar = #8226
    TabOrder = 0
    OnKeyPress = ePassKeyPress
  end
end
