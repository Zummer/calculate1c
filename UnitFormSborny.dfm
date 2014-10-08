object fSbornyZakaz: TfSbornyZakaz
  Left = 343
  Top = 257
  Caption = #1057#1073#1086#1088#1085#1099#1081' '#1079#1072#1082#1072#1079
  ClientHeight = 389
  ClientWidth = 888
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSplitter1: TAdvSplitter
    Left = 0
    Top = 247
    Width = 888
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    Appearance.BorderColor = clNone
    Appearance.BorderColorHot = clNone
    Appearance.Color = clWhite
    Appearance.ColorTo = clSilver
    Appearance.ColorHot = clWhite
    Appearance.ColorHotTo = clGray
    GripStyle = sgDots
    ExplicitTop = 320
    ExplicitWidth = 921
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 888
    Height = 89
    Align = alTop
    TabOrder = 0
    object btnAddIzdelie: TButton
      Left = 7
      Top = 7
      Width = 82
      Height = 75
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1079#1076#1077#1083#1080#1077
      TabOrder = 0
      WordWrap = True
      OnClick = btnAddIzdelieClick
    end
    object btnCollapseIzdelies: TButton
      Left = 183
      Top = 60
      Width = 33
      Height = 22
      Caption = '<>'
      TabOrder = 1
      OnClick = btnCollapseIzdeliesClick
    end
    object btnDeleteIzdelie: TButton
      Left = 95
      Top = 7
      Width = 82
      Height = 75
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079#1076#1077#1083#1080#1077
      TabOrder = 2
      WordWrap = True
      OnClick = btnDeleteIzdelieClick
    end
    object GroupBox1: TGroupBox
      Left = 222
      Top = 6
      Width = 395
      Height = 76
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
      TabOrder = 3
      object lTypePrice: TLabel
        Left = 263
        Top = 50
        Width = 39
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085
      end
      object Label8: TLabel
        Left = 146
        Top = 51
        Width = 22
        Height = 13
        Caption = #1058#1077#1083'.'
      end
      object Label11: TLabel
        Left = 9
        Top = 51
        Width = 46
        Height = 13
        Caption = #1060#1072#1084'. '#1048#1084#1103
      end
      object cbAgents: TComboBox
        Left = 9
        Top = 18
        Width = 168
        Height = 21
        TabOrder = 0
        Text = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090#1099
        OnSelect = cbAgentsSelect
      end
      object btFindAgents: TButton
        Left = 183
        Top = 16
        Width = 75
        Height = 25
        Caption = #1053#1072#1081#1090#1080
        TabOrder = 1
        OnClick = btFindAgentsClick
      end
      object eFamilia: TEdit
        Left = 59
        Top = 47
        Width = 84
        Height = 21
        TabOrder = 2
        OnChange = eFamiliaChange
      end
      object ePhone: TEdit
        Left = 169
        Top = 47
        Width = 88
        Height = 21
        NumbersOnly = True
        TabOrder = 3
        OnChange = ePhoneChange
      end
    end
    object btSum: TButton
      Left = 631
      Top = 8
      Width = 82
      Height = 75
      Caption = #1055#1077#1088#1077#1089#1095#1080#1090#1072#1090#1100' '#1079#1072#1082#1072#1079
      TabOrder = 4
      WordWrap = True
      OnClick = btSumClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 321
    Width = 888
    Height = 68
    Align = alBottom
    TabOrder = 1
    object lbAllPrice: TLabel
      Left = 263
      Top = 28
      Width = 102
      Height = 19
      Caption = #1057#1091#1084#1084#1072': 0 '#1088#1091#1073'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 95
      Top = 28
      Width = 57
      Height = 19
      Caption = #1050#1086#1083'-'#1074#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 227
      Top = 28
      Width = 25
      Height = 19
      Caption = #1096#1090'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object btSavePrint: TButton
      Left = 432
      Top = 16
      Width = 94
      Height = 41
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1085#1072#1087#1077#1095#1072#1090#1072#1090#1100
      TabOrder = 0
      WordWrap = True
      OnClick = btSavePrintClick
    end
    object Button2: TButton
      Left = 7
      Top = 16
      Width = 75
      Height = 41
      Caption = #1053#1086#1074#1099#1081
      TabOrder = 1
      OnClick = Button2Click
    end
    object btSaveZakaz: TButton
      Left = 532
      Top = 16
      Width = 77
      Height = 41
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 2
      WordWrap = True
      OnClick = btSaveZakazClick
    end
    object btPrintZakaz: TButton
      Left = 615
      Top = 16
      Width = 81
      Height = 41
      Caption = #1053#1072#1087#1077#1095#1072#1090#1072#1090#1100
      TabOrder = 3
      WordWrap = True
      OnClick = btPrintZakazClick
    end
    object memoPrim: TMemo
      Left = 712
      Top = 1
      Width = 175
      Height = 66
      Align = alRight
      TabOrder = 4
    end
    object spCount: TAdvSpinEdit
      Left = 156
      Top = 25
      Width = 64
      Height = 29
      AutoFocus = True
      Value = 1
      FloatValue = 1.000000000000000000
      TimeValue = 0.041666666666666660
      HexValue = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 19
      Font.Name = 'Tahoma'
      Font.Style = []
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      MaxValue = 10000
      MinValue = 1
      ParentFont = False
      TabOrder = 5
      Visible = True
      Version = '1.5.3.4'
      OnChange = spCountChange
      OnKeyPress = spCountKeyPress
    end
  end
  object sbForSelFrame: TScrollBox
    Left = 0
    Top = 89
    Width = 888
    Height = 158
    Align = alClient
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 0
    Top = 250
    Width = 888
    Height = 71
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object frxReport1: TfrxReport
    Version = '4.13.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Copies = 2
    PrintOptions.PageNumbers = '1'
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintMode = pmJoin
    PrintOptions.PrintOnSheet = 9
    ReportOptions.CreateDate = 41294.654720208300000000
    ReportOptions.LastChange = 41908.183114467600000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 776
    Top = 16
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object mZakaz: TfrxMemoView
        Left = 3.779530000000000000
        Top = 81.267780000000000000
        Width = 729.449290000000000000
        Height = 34.015770000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        HAlign = haCenter
        Memo.UTF8W = (
          #1047#1072#1082#1072#1079' '#8470' ____')
        ParentFont = False
      end
      object mAgent: TfrxMemoView
        Left = 3.779530000000000000
        Top = 153.177257500000000000
        Width = 453.543600000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090': '#1054#1089#1080#1085#1094#1077#1074' '#1042#1083#1072#1076#1080#1084#1080#1088' '#1053#1080#1082#1086#1083#1072#1077#1074#1080#1095)
        ParentFont = False
      end
      object mPhone: TfrxMemoView
        Left = 3.779530000000000000
        Top = 178.968615000000000000
        Width = 453.543600000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1058#1077#1083#1077#1092#1086#1085': 89139995544')
        ParentFont = False
      end
      object mManager: TfrxMemoView
        Left = 3.779530000000000000
        Top = 204.759972500000000000
        Width = 449.764070000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1052#1077#1085#1077#1076#1078#1077#1088': '#1043#1086#1083#1091#1073#1082#1086#1074#1072' '#1040#1085#1085#1072' '#1090#1077#1083'.: 89139995522')
      end
      object mFinance: TfrxMemoView
        Left = 3.779530000000000000
        Top = 127.385900000000000000
        Width = 449.764070000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1062#1077#1085#1072': 3500 '#1088#1091#1073'. '#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086': 1 '#1096#1090'. '#1057#1091#1084#1084#1072': 3500 '#1088#1091#1073'.')
        ParentFont = False
      end
      object Memo2: TfrxMemoView
        Left = 3.779530000000000000
        Top = 3.779530000000000000
        Width = 714.331170000000000000
        Height = 71.811070000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          
            #1054#1054#1054' "'#1050#1086#1084#1092#1086#1090#1086'", '#1056#1086#1089#1089#1080#1103', 630004, '#1075'. '#1053#1086#1074#1086#1089#1080#1073#1080#1088#1089#1082', '#1042#1086#1082#1079#1072#1083#1100#1085#1072#1103' '#1084#1072#1075#1080#1089#1090 +
            #1088#1072#1083#1100', 10.'
          
            #1090#1077#1083'. 8(383)2178741, 8(383)2178745, e-mail: info@comefoto.ru, www' +
            '.comefoto.ru')
        ParentFont = False
      end
      object mPrim: TfrxMemoView
        Left = 3.779530000000000000
        Top = 230.551330000000000000
        Width = 714.331170000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077': '#1090#1072#1082#1086#1077' '#1090#1086' '#1080#1079#1076#1077#1083#1080#1077', '#1090#1086' '#1090#1086' '#1080' '#1090#1086' '#1090#1086)
        ParentFont = False
      end
      object MemoIzd: TfrxMemoView
        Top = 298.582870000000000000
        Width = 718.110700000000000000
        Height = 102.047310000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        LineSpacing = 8.000000000000000000
        Memo.UTF8W = (
          #1079#1076#1077#1089#1100' '#1089#1090#1088#1086#1082#1080' '#1079#1072#1082#1072#1079#1072
          'gjhgjhg')
        ParentFont = False
      end
    end
  end
end
