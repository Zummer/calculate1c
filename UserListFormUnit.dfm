object fUserList: TfUserList
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = ' '#1057#1086#1090#1088#1091#1076#1085#1080#1082#1080
  ClientHeight = 259
  ClientWidth = 150
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object clUsers: TCheckListBox
    Left = 0
    Top = 0
    Width = 150
    Height = 259
    Align = alClient
    ItemHeight = 13
    TabOrder = 0
    ExplicitHeight = 168
  end
end
