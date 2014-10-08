object fPass: TfPass
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #1057#1084#1077#1085#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
  ClientHeight = 148
  ClientWidth = 293
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 25
    Top = 35
    Width = 76
    Height = 13
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
  end
  object Label2: TLabel
    Left = 25
    Top = 62
    Width = 41
    Height = 13
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object cbUsers: TComboBox
    Left = 112
    Top = 32
    Width = 145
    Height = 21
    DropDownCount = 25
    TabOrder = 1
    OnSelect = cbUsersSelect
  end
  object ePass: TEdit
    Left = 112
    Top = 59
    Width = 145
    Height = 21
    PasswordChar = #8226
    TabOrder = 0
    OnKeyPress = ePassKeyPress
  end
  object Button1: TButton
    Left = 72
    Top = 104
    Width = 145
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1077
    TabOrder = 2
    OnClick = Button1Click
  end
  object chek: TCheckBox
    Left = 128
    Top = 8
    Width = 49
    Height = 17
    Caption = 'chek'
    TabOrder = 3
    Visible = False
  end
end
