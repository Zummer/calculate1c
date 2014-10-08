object fDesignOrder: TfDesignOrder
  Left = 286
  Top = 193
  Caption = #1044#1080#1079#1072#1081#1085#1077#1088#1089#1082#1080#1081' '#1079#1072#1082#1072#1079
  ClientHeight = 517
  ClientWidth = 755
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSplitter1: TAdvSplitter
    Left = 0
    Top = 333
    Width = 755
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
    ExplicitTop = 335
    ExplicitWidth = 582
  end
  object Panel2: TPanel
    Left = 0
    Top = 451
    Width = 755
    Height = 66
    Align = alBottom
    TabOrder = 0
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
    object btReport: TButton
      Left = 449
      Top = 9
      Width = 127
      Height = 48
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' 1'#1089
      TabOrder = 0
      OnClick = btReportClick
    end
    object Button1: TButton
      Left = 360
      Top = 9
      Width = 83
      Height = 48
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1085#1072#1087#1077#1095#1072#1090#1072#1090#1100
      TabOrder = 1
      WordWrap = True
      OnClick = Button1Click
    end
    object btNew: TButton
      Left = 7
      Top = 9
      Width = 75
      Height = 48
      Caption = #1053#1086#1074#1099#1081
      TabOrder = 2
      OnClick = btNewClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 755
    Height = 113
    Align = alTop
    TabOrder = 1
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
      Left = 7
      Top = 37
      Width = 139
      Height = 25
      Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
      TabOrder = 0
    end
    object GroupBox1: TGroupBox
      Left = 308
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
  end
  object Memo1: TMemo
    Left = 0
    Top = 336
    Width = 755
    Height = 115
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 113
    Width = 755
    Height = 220
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 3
    OnDrawTab = PageControl1DrawTab
    object TabSheet1: TTabSheet
      Caption = #1060#1086#1090#1086' '#1085#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
      object sg1: TStringGrid
        Left = 0
        Top = 0
        Width = 747
        Height = 192
        Align = alClient
        ColCount = 4
        DefaultColWidth = 100
        DefaultRowHeight = 20
        FixedCols = 3
        TabOrder = 0
        OnDrawCell = sgDrawCell
        OnMouseEnter = sgMouseEnter
        OnMouseMove = sgMouseMove
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1044#1080#1079#1072#1081#1085
      ImageIndex = 1
      object sg2: TStringGrid
        Left = 0
        Top = 0
        Width = 747
        Height = 192
        Align = alClient
        ColCount = 4
        DefaultColWidth = 100
        DefaultRowHeight = 20
        FixedCols = 3
        TabOrder = 0
        OnDrawCell = sgDrawCell
        OnMouseEnter = sgMouseEnter
        OnMouseMove = sgMouseMove
        RowHeights = (
          20
          20
          20
          20
          20)
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1056#1077#1090#1091#1096#1100
      ImageIndex = 2
      object sg3: TStringGrid
        Left = 0
        Top = 0
        Width = 747
        Height = 192
        Align = alClient
        ColCount = 4
        DefaultColWidth = 100
        DefaultRowHeight = 20
        FixedCols = 3
        TabOrder = 0
        OnDrawCell = sgDrawCell
        OnMouseEnter = sgMouseEnter
        OnMouseMove = sgMouseMove
        RowHeights = (
          20
          20
          20
          20
          20)
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1057#1082#1072#1085#1080#1088#1086#1074#1072#1085#1080#1077
      ImageIndex = 3
      object sg4: TStringGrid
        Left = 0
        Top = 0
        Width = 747
        Height = 192
        Align = alClient
        ColCount = 4
        DefaultColWidth = 100
        DefaultRowHeight = 20
        FixedCols = 3
        TabOrder = 0
        OnDrawCell = sgDrawCell
        OnMouseEnter = sgMouseEnter
        OnMouseMove = sgMouseMove
        RowHeights = (
          20
          20
          20
          20
          20)
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1055#1086#1076#1075#1086#1090#1086#1074#1082#1072
      ImageIndex = 4
      object sg5: TStringGrid
        Left = 0
        Top = 0
        Width = 747
        Height = 192
        Align = alClient
        ColCount = 4
        DefaultColWidth = 100
        DefaultRowHeight = 20
        FixedCols = 3
        TabOrder = 0
        OnDrawCell = sgDrawCell
        OnMouseEnter = sgMouseEnter
        OnMouseMove = sgMouseMove
      end
    end
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
    ReportOptions.CreateDate = 41294.654720208330000000
    ReportOptions.LastChange = 41294.654720208330000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 240
    Top = 56
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 148.000000000000000000
      PaperHeight = 210.000000000000000000
      PaperSize = 11
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object mZakaz: TfrxMemoView
        Left = 22.677180000000000000
        Top = 64.252010000000000000
        Width = 442.205010000000000000
        Height = 34.015770000000010000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        HAlign = haCenter
        Memo.UTF8W = (
          #1047#1072#1082#1072#1079' '#1085#1072' '#1076#1080#1079#1072#1081#1085' '#8470' ____')
        ParentFont = False
      end
      object mAgent: TfrxMemoView
        Left = 22.677180000000000000
        Top = 134.165430000000000000
        Width = 434.645950000000000000
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
        Left = 22.677180000000000000
        Top = 154.842610000000000000
        Width = 434.645950000000000000
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
      object mDesigner: TfrxMemoView
        Left = 22.677180000000000000
        Top = 186.401670000000000000
        Width = 430.866420000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1044#1080#1079#1072#1081#1085#1077#1088': '#1043#1086#1083#1091#1073#1082#1086#1074#1072' '#1040#1085#1085#1072' '#1090#1077#1083'.: 89139995522')
      end
      object mFinance: TfrxMemoView
        Left = 22.677180000000000000
        Top = 110.370130000000000000
        Width = 430.866420000000000000
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
        Left = 0.779530000000000000
        Top = 219.212740000000000000
        Width = 480.000310000000000000
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
        Left = 18.897650000000000000
        Top = 3.779530000000000000
        Width = 449.764070000000000000
        Height = 37.795300000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
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
    end
  end
end
