object fMainServer: TfMainServer
  Left = 0
  Top = 0
  Caption = #1057#1077#1088#1074#1077#1088' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1081' 1c'
  ClientHeight = 266
  ClientWidth = 445
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 328
    Top = 72
    Width = 97
    Height = 25
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object btSettings: TButton
    Left = 328
    Top = 103
    Width = 97
    Height = 25
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    TabOrder = 1
    OnClick = btSettingsClick
  end
  object MyConnection1: TMyConnection
    Database = 'zp_sboi'
    Options.Charset = 'cp1251'
    Username = 'root'
    Server = 'localhost'
    Connected = True
    LoginPrompt = False
    Left = 280
    Top = 8
  end
end
