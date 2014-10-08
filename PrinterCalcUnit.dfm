object fPrinterCalc: TfPrinterCalc
  Left = 0
  Top = 0
  Caption = #1064#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1072#1103' '#1087#1077#1095#1072#1090#1100
  ClientHeight = 474
  ClientWidth = 921
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSplitter1: TAdvSplitter
    Left = 0
    Top = 277
    Width = 921
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
  end
  object sbForSelFrame: TScrollBox
    Left = 0
    Top = 161
    Width = 921
    Height = 116
    Align = alClient
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 921
    Height = 161
    Align = alTop
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 560
      Height = 159
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      object LabelCurUser: TLabel
        Left = 7
        Top = 1
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
      object btUserChange: TButton
        Left = 6
        Top = 40
        Width = 139
        Height = 25
        Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
        TabOrder = 0
        OnClick = btUserChangeClick
      end
      object GroupBox1: TGroupBox
        Left = 279
        Top = 6
        Width = 265
        Height = 94
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
        TabOrder = 1
        object lTypePrice: TLabel
          Left = 9
          Top = 45
          Width = 39
          Height = 13
          Caption = #1058#1080#1087' '#1094#1077#1085
        end
        object Label8: TLabel
          Left = 146
          Top = 69
          Width = 22
          Height = 13
          Caption = #1058#1077#1083'.'
        end
        object Label11: TLabel
          Left = 9
          Top = 69
          Width = 46
          Height = 13
          Caption = #1060#1072#1084'. '#1048#1084#1103
        end
        object cbAgent: TComboBox
          Left = 9
          Top = 18
          Width = 168
          Height = 21
          TabOrder = 0
          Text = 'cbAgent'
          OnSelect = cbAgentSelect
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
          Top = 65
          Width = 84
          Height = 21
          TabOrder = 2
        end
        object ePhone: TEdit
          Left = 169
          Top = 65
          Width = 88
          Height = 21
          NumbersOnly = True
          TabOrder = 3
          OnChange = ePhoneChange
        end
      end
      object Button1: TButton
        Left = 10
        Top = 106
        Width = 113
        Height = 25
        Caption = '+ '#1096#1080#1088#1086#1082#1086#1092'. '#1087#1077#1095#1072#1090#1100
        TabOrder = 2
        OnClick = Button1Click
      end
      object Button5: TButton
        Left = 129
        Top = 106
        Width = 75
        Height = 25
        Caption = #1091#1076#1072#1083#1080#1090#1100
        TabOrder = 3
        OnClick = Button5Click
      end
    end
    object sg1: TStringGrid
      Left = 561
      Top = 1
      Width = 359
      Height = 159
      Align = alClient
      DefaultRowHeight = 18
      FixedCols = 3
      TabOrder = 1
      OnMouseMove = sg1MouseMove
      RowHeights = (
        18
        18
        18
        18
        18)
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 408
    Width = 921
    Height = 66
    Align = alBottom
    TabOrder = 2
    object lbAllPrice: TLabel
      Left = 101
      Top = 23
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
      Left = 505
      Top = 6
      Width = 65
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Button4: TButton
      Left = 360
      Top = 9
      Width = 83
      Height = 48
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1085#1072#1087#1077#1095#1072#1090#1072#1090#1100
      TabOrder = 0
      WordWrap = True
      OnClick = Button4Click
    end
    object btNew: TButton
      Left = 7
      Top = 9
      Width = 75
      Height = 48
      Caption = #1053#1086#1074#1099#1081
      TabOrder = 1
      OnClick = btNewClick
    end
    object Memo2: TMemo
      Left = 576
      Top = 1
      Width = 344
      Height = 64
      Align = alRight
      TabOrder = 2
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 280
    Width = 921
    Height = 128
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
    ReportOptions.LastChange = 41346.539635555600000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 224
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
          #1047#1072#1082#1072#1079' '#1085#1072' '#1096#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1091' '#1087#1077#1095#1072#1090#1100' '#8470' ____')
        ParentFont = False
      end
      object mAgent: TfrxMemoView
        Left = 3.779530000000000000
        Top = 151.181200000000000000
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
        Top = 173.858380000000000000
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
        Top = 203.417440000000000000
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
      object Memo1: TfrxMemoView
        Left = 0.779529999999999900
        Top = 292.921460000000000000
        Width = 714.331170000000000000
        Height = 26.456710000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        GapX = 10.000000000000000000
        GapY = 5.000000000000000000
        Memo.UTF8W = (
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10')
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
      object Prim: TfrxMemoView
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
    end
  end
end
