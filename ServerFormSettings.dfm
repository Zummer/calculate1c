object FormSettings: TFormSettings
  Left = 0
  Top = 0
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 348
  ClientWidth = 720
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 720
    Height = 65
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 0
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 65
    Width = 720
    Height = 283
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1055#1088#1080#1085#1090#1077#1088#1099
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 51
        Width = 712
        Height = 204
        Align = alClient
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 712
        Height = 51
        Align = alTop
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
  end
end
