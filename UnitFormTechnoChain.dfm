object FormTechnoChain: TFormTechnoChain
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = ' '#1058#1077#1093#1085#1086#1083#1086#1085#1080#1095#1077#1089#1082#1072#1103' '#1094#1077#1087#1086#1095#1082#1072
  ClientHeight = 195
  ClientWidth = 135
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 8
    Top = 33
    Width = 121
    Height = 125
    ItemHeight = 13
    Items.Strings = (
      #1056#1077#1079#1082#1072
      #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
      #1051#1072#1084#1080#1085#1080#1088#1086#1074#1072#1085#1080#1077)
    TabOrder = 0
  end
  object btnAdd: TButton
    Left = 31
    Top = 164
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '
    TabOrder = 1
    OnClick = btnAddClick
  end
  object SpinButton2: TSpinButton
    Left = 109
    Top = 2
    Width = 20
    Height = 25
    DownGlyph.Data = {
      0E010000424D0E01000000000000360000002800000009000000060000000100
      200000000000D800000000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000008080000080800000808000000000000080800000808000008080000080
      8000008080000080800000808000000000000000000000000000008080000080
      8000008080000080800000808000000000000000000000000000000000000000
      0000008080000080800000808000000000000000000000000000000000000000
      0000000000000000000000808000008080000080800000808000008080000080
      800000808000008080000080800000808000}
    TabOrder = 2
    UpGlyph.Data = {
      0E010000424D0E01000000000000360000002800000009000000060000000100
      200000000000D800000000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000000000000000000000000000000000000000000000000000000000000080
      8000008080000080800000000000000000000000000000000000000000000080
      8000008080000080800000808000008080000000000000000000000000000080
      8000008080000080800000808000008080000080800000808000000000000080
      8000008080000080800000808000008080000080800000808000008080000080
      800000808000008080000080800000808000}
  end
end