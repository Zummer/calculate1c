object fBook: TfBook
  Left = 0
  Top = 0
  Caption = #1047#1072#1082#1072#1079' '#1092#1086#1090#1086#1082#1085#1080#1075#1080
  ClientHeight = 392
  ClientWidth = 553
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label10: TLabel
    Left = 277
    Top = 316
    Width = 49
    Height = 13
    Caption = #1044#1080#1079#1072#1081#1085#1077#1088
  end
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
  object Label14: TLabel
    Left = 249
    Top = 333
    Width = 18
    Height = 13
    Caption = #1096#1090'.'
  end
  object Label17: TLabel
    Left = 139
    Top = 333
    Width = 60
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbAllPrice: TLabel
    Left = 141
    Top = 355
    Width = 128
    Height = 19
    Caption = #1057#1091#1084#1084#1072', 3500 '#1088#1091#1073'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label15: TLabel
    Left = 318
    Top = 341
    Width = 91
    Height = 13
    Caption = #1044#1072#1090#1072' '#1075#1086#1090#1086#1074#1085#1086#1089#1090#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 7
    Top = 63
    Width = 265
    Height = 94
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
    TabOrder = 0
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
  object GroupBox2: TGroupBox
    Left = 278
    Top = 219
    Width = 264
    Height = 90
    Caption = #1041#1083#1086#1082
    TabOrder = 1
    object Label5: TLabel
      Left = 8
      Top = 18
      Width = 106
      Height = 13
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083' '#1088#1072#1079#1074#1086#1088#1086#1090#1072
    end
    object cbSpread: TComboBox
      Left = 120
      Top = 14
      Width = 138
      Height = 21
      ItemIndex = 1
      TabOrder = 0
      Text = #1052#1072#1090#1086#1074#1099#1081
      OnChange = cbSpreadChange
      Items.Strings = (
        #1043#1083#1103#1085#1094#1077#1074#1099#1081
        #1052#1072#1090#1086#1074#1099#1081
        #1064#1077#1083#1082
        #1052#1077#1090#1072#1083#1083#1080#1082)
    end
    object chForzac: TCheckBox
      Left = 49
      Top = 40
      Width = 65
      Height = 17
      Caption = #1060#1086#1088#1079#1072#1094
      TabOrder = 1
      OnMouseUp = chForzacMouseUp
    end
    object cbForzac: TComboBox
      Left = 120
      Top = 38
      Width = 138
      Height = 21
      TabOrder = 2
      Text = #1041#1072#1088#1093#1072#1090#1085#1099#1081
      OnChange = cbForzacChange
      Items.Strings = (
        #1041#1072#1088#1093#1072#1090#1085#1099#1081
        #1044#1080#1079#1072#1081#1085#1077#1088#1089#1082#1072#1103' '#1073#1091#1084#1072#1075#1072
        #1064#1077#1083#1082)
    end
    object chRound: TCheckBox
      Left = 49
      Top = 62
      Width = 122
      Height = 17
      Caption = #1057#1082#1088#1091#1075#1083#1077#1085#1080#1077' '#1091#1075#1083#1086#1074
      TabOrder = 3
      OnMouseUp = chMouseUp
    end
  end
  object GroupBox3: TGroupBox
    Left = 278
    Top = 63
    Width = 264
    Height = 110
    Caption = #1054#1073#1083#1086#1078#1082#1072
    TabOrder = 2
    object Label4: TLabel
      Left = 66
      Top = 16
      Width = 46
      Height = 13
      Caption = #1054#1073#1083#1086#1078#1082#1072
    end
    object Label6: TLabel
      Left = 11
      Top = 40
      Width = 50
      Height = 13
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083
    end
    object cbTypeCover: TComboBox
      Left = 118
      Top = 10
      Width = 137
      Height = 21
      ItemIndex = 0
      TabOrder = 0
      Text = #1052#1103#1075#1082#1072#1103' '#1060#1086#1090#1086
      OnChange = cbTypeCoverChange
      Items.Strings = (
        #1052#1103#1075#1082#1072#1103' '#1060#1086#1090#1086
        #1058#1074#1077#1088#1076#1072#1103' '#1060#1086#1090#1086
        #1058#1074#1077#1088#1076#1072#1103' '#1050#1086#1078#1072)
    end
    object chLaminat: TCheckBox
      Left = 49
      Top = 62
      Width = 59
      Height = 17
      Caption = #1051#1072#1084#1080#1085#1072#1090
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnMouseUp = chLaminatMouseUp
    end
    object cbLaminat: TComboBox
      Left = 120
      Top = 61
      Width = 136
      Height = 21
      ItemIndex = 0
      TabOrder = 4
      Text = #1043#1083#1103#1085#1094#1077#1074#1099#1081
      OnChange = cbLaminatChange
      Items.Strings = (
        #1043#1083#1103#1085#1094#1077#1074#1099#1081
        #1052#1072#1090#1086#1074#1099#1081
        #1040#1090#1083#1072#1089#1085#1099#1081
        #1058#1086#1085#1082#1080#1081' '#1083#1105#1085)
    end
    object cbMaterialCover: TComboBox
      Left = 67
      Top = 37
      Width = 103
      Height = 21
      TabOrder = 1
      OnChange = cbMaterialCoverChange
    end
    object chPorolon: TCheckBox
      Left = 10
      Top = 84
      Width = 59
      Height = 17
      Caption = #1055#1086#1088#1086#1083#1086#1085
      TabOrder = 5
      OnMouseUp = chMouseUp
    end
    object chCorners: TCheckBox
      Left = 109
      Top = 84
      Width = 59
      Height = 17
      Caption = #1059#1075#1086#1083#1082#1080
      TabOrder = 6
      OnMouseUp = chMouseUp
    end
    object cbMaterialCoverHarakt: TComboBox
      Left = 176
      Top = 37
      Width = 80
      Height = 21
      TabOrder = 2
      OnChange = cbMaterialCoverHaraktChange
    end
    object cbCorners: TComboBox
      Left = 169
      Top = 84
      Width = 87
      Height = 21
      ItemIndex = 0
      TabOrder = 7
      Text = #1047#1086#1083#1086#1090#1086
      Visible = False
      Items.Strings = (
        #1047#1086#1083#1086#1090#1086
        #1057#1077#1088#1077#1073#1088#1086)
    end
  end
  object btReport: TButton
    Left = 418
    Top = 339
    Width = 127
    Height = 47
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' 1'#1089
    TabOrder = 10
    OnClick = CreateReport
  end
  object GroupBox4: TGroupBox
    Left = 7
    Top = 163
    Width = 265
    Height = 87
    Caption = #1060#1086#1090#1086#1082#1085#1080#1075#1072
    TabOrder = 3
    object Label1: TLabel
      Left = 94
      Top = 15
      Width = 19
      Height = 13
      Caption = #1042#1080#1076
    end
    object Label2: TLabel
      Left = 75
      Top = 39
      Width = 38
      Height = 13
      Caption = #1060#1086#1088#1084#1072#1090
    end
    object Label3: TLabel
      Left = 17
      Top = 63
      Width = 97
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086' '#1088#1072#1079#1074#1086#1088#1086#1090#1086#1074
    end
    object cbBookType: TComboBox
      Left = 119
      Top = 12
      Width = 138
      Height = 21
      ItemIndex = 0
      TabOrder = 0
      Text = #1060#1086#1090#1086#1082#1085#1080#1075#1072
      OnSelect = cbBookTypeSelect
      Items.Strings = (
        #1060#1086#1090#1086#1082#1085#1080#1075#1072
        #1060#1086#1090#1086#1087#1083#1072#1085#1096#1077#1090)
    end
    object cbFormat: TComboBox
      Left = 120
      Top = 36
      Width = 137
      Height = 21
      TabOrder = 1
      Text = '10x15 '#1072#1083#1100#1073#1086#1084
      OnChange = cbFormatChange
      Items.Strings = (
        '10x15 '#1072#1083#1100#1073#1086#1084
        '10x15 '#1087#1086#1088#1090#1088#1077#1090
        '15x15'
        '15x20 '#1072#1083#1100#1073#1086#1084
        '15x20 '#1087#1086#1088#1090#1088#1077#1090
        '20x20'
        '25x25'
        '20x30 '#1072#1083#1100#1073#1086#1084
        '20x30 '#1087#1086#1088#1090#1088#1077#1090
        '30x30')
    end
    object advSpreadCount: TAdvSpinEdit
      Left = 120
      Top = 60
      Width = 137
      Height = 22
      Value = 10
      FloatValue = 10.000000000000000000
      TimeValue = 0.416666666666666700
      HexValue = 0
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      TabOrder = 2
      Visible = True
      Version = '1.5.3.4'
      OnChange = advSpreadCountChange
    end
  end
  object cbDesigner: TComboBox
    Left = 332
    Top = 314
    Width = 209
    Height = 21
    TabOrder = 8
    Text = #1053#1077' '#1091#1082#1072#1079#1072#1085
    Items.Strings = (
      #1053#1077' '#1091#1082#1072#1079#1072#1085
      #1047#1072#1082#1072#1079#1095#1080#1082)
  end
  object GroupBox5: TGroupBox
    Left = 277
    Top = 179
    Width = 265
    Height = 41
    TabOrder = 5
    object Label12: TLabel
      Left = 19
      Top = 16
      Width = 38
      Height = 13
      Caption = #1060#1086#1088#1084#1072#1090
    end
    object Label13: TLabel
      Left = 229
      Top = 15
      Width = 18
      Height = 13
      Caption = #1096#1090'.'
    end
    object ComboBox1: TComboBox
      Left = 63
      Top = 13
      Width = 116
      Height = 21
      Enabled = False
      ItemIndex = 0
      TabOrder = 0
      Text = '10x15 '#1089#1084
      Items.Strings = (
        '10x15 '#1089#1084
        '15x20 '#1089#1084
        '20x30 '#1089#1084)
    end
    object AdvSpinEdit1: TAdvSpinEdit
      Left = 189
      Top = 12
      Width = 37
      Height = 22
      Value = 1
      FloatValue = 1.000000000000000000
      TimeValue = 0.041666666666666660
      HexValue = 0
      Color = clSilver
      Enabled = False
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      TabOrder = 1
      Visible = True
      Version = '1.5.3.4'
      OnChange = advSpreadCountChange
    end
  end
  object chCutt: TCheckBox
    Left = 288
    Top = 172
    Width = 117
    Height = 17
    Caption = #1042#1099#1088#1091#1073#1082#1072' '#1087#1086#1076' '#1092#1086#1090#1086
    TabOrder = 4
    OnMouseUp = chMouseUp
  end
  object btUserChange: TButton
    Left = 7
    Top = 37
    Width = 139
    Height = 25
    Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 11
  end
  object advspBookCount: TAdvSpinEdit
    Left = 206
    Top = 330
    Width = 37
    Height = 22
    Value = 1
    FloatValue = 1.000000000000000000
    TimeValue = 0.041666666666666660
    HexValue = 0
    IncrementFloat = 0.100000000000000000
    IncrementFloatPage = 1.000000000000000000
    LabelFont.Charset = DEFAULT_CHARSET
    LabelFont.Color = clWindowText
    LabelFont.Height = -11
    LabelFont.Name = 'Tahoma'
    LabelFont.Style = []
    TabOrder = 7
    Visible = True
    Version = '1.5.3.4'
    OnChange = advspBookCountChange
  end
  object GroupBox6: TGroupBox
    Left = 7
    Top = 296
    Width = 122
    Height = 79
    Caption = #1062#1077#1085#1072' '#1079#1072' 1 '#1096#1090'., '#1088#1091#1073'.'
    TabOrder = 6
    object lbBookPrice: TLabel
      Left = 11
      Top = 21
      Width = 61
      Height = 13
      Caption = #1050#1085#1080#1075#1072': 3200'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lbSpreadPrice: TLabel
      Left = 10
      Top = 55
      Width = 75
      Height = 13
      Caption = #1044#1086#1087' '#1088#1072#1079#1074'.: 200'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lbCoverPrice: TLabel
      Left = 10
      Top = 38
      Width = 77
      Height = 13
      Caption = #1054#1073#1083#1086#1078#1082#1072': 1200'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object DateTimePicker1: TDateTimePicker
    Left = 318
    Top = 360
    Width = 90
    Height = 21
    Date = 41270.583333333340000000
    Time = 41270.583333333340000000
    TabOrder = 9
  end
  object chStitch: TCheckBox
    Left = 389
    Top = 24
    Width = 59
    Height = 17
    Caption = #1057#1090#1088#1086#1095#1082#1072
    TabOrder = 12
    Visible = False
    OnMouseUp = chMouseUp
  end
  object chCord: TCheckBox
    Left = 454
    Top = 24
    Width = 59
    Height = 17
    Caption = #1058#1077#1089#1100#1084#1072
    TabOrder = 13
    Visible = False
    OnMouseUp = chMouseUp
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
    ReportOptions.CreateDate = 41258.678105347200000000
    ReportOptions.LastChange = 41898.678870567130000000
    ScriptLanguage = 'C++Script'
    ScriptText.Strings = (
      ''
      '{'
      ''
      '}')
    Left = 262
    Top = 14
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
      LeftMargin = 5.000000000000000000
      RightMargin = 5.000000000000000000
      TopMargin = 5.000000000000000000
      BottomMargin = 5.000000000000000000
      object Shape3: TfrxShapeView
        Left = 30.236240000000000000
        Top = 195.283550000000000000
        Width = 442.205010000000000000
        Height = 60.472480000000000000
        ShowHint = False
      end
      object Shape1: TfrxShapeView
        Left = 30.236240000000000000
        Top = 272.315090000000000000
        Width = 442.205010000000000000
        Height = 238.110390000000000000
        ShowHint = False
      end
      object chCorners: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 406.039580000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object mZakaz: TfrxMemoView
        Left = 30.236240000000000000
        Top = 49.338589999999990000
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
          #1047#1072#1082#1072#1079' '#1060#1086#1090#1086#1082#1085#1080#1075#1072' '#8470' ____')
        ParentFont = False
      end
      object mAgent: TfrxMemoView
        Left = 37.795300000000000000
        Top = 134.370130000000000000
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
      object mFormat: TfrxMemoView
        Left = 37.795300000000000000
        Top = 207.622140000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1086#1088#1084#1072#1090': 10x15 '#1072#1083#1100#1073#1086#1084)
        ParentFont = False
      end
      object mSpreadCount: TfrxMemoView
        Left = 37.795300000000000000
        Top = 230.299320000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1072#1079#1074#1086#1088#1086#1090#1086#1074': 10 '#1088#1072#1079#1074#1086#1088#1086#1090#1086#1074)
        ParentFont = False
      end
      object mCoverType: TfrxMemoView
        Left = 37.795300000000000000
        Top = 284.212740000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1058#1080#1087' '#1086#1073#1083#1086#1078#1082#1080': '#1052#1103#1075#1082#1072#1103' '#1060#1086#1090#1086)
        ParentFont = False
      end
      object mCoverMaterial: TfrxMemoView
        Left = 37.795300000000000000
        Top = 306.889920000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1052#1072#1090#1077#1088#1080#1072#1083':')
        ParentFont = False
      end
      object chLaminat: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 353.126160000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object mLaminatMaterial: TfrxMemoView
        Left = 60.472480000000000000
        Top = 353.126160000000000000
        Width = 411.968770000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1051#1072#1084#1080#1085#1072#1090': '#1043#1083#1103#1085#1094#1077#1074#1099#1081' '#1050#1086#1085#1092#1083#1077#1082#1089' '#1050#1080#1090#1072#1081)
      end
      object chPorolon: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 379.582870000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object Memo2: TfrxMemoView
        Left = 60.472480000000000000
        Top = 379.582870000000000000
        Width = 64.252010000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1055#1086#1088#1086#1083#1086#1085)
      end
      object MemoCorners: TfrxMemoView
        Left = 60.472480000000000000
        Top = 406.039580000000000000
        Width = 166.299320000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1059#1075#1086#1083#1082#1080)
      end
      object chStitch: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 432.496290000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object Memo4: TfrxMemoView
        Left = 60.472480000000000000
        Top = 432.496290000000000000
        Width = 64.252010000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1057#1090#1088#1086#1095#1082#1072)
      end
      object chCord: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 458.953000000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object Memo5: TfrxMemoView
        Left = 60.472480000000000000
        Top = 458.953000000000000000
        Width = 64.252010000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1058#1077#1089#1100#1084#1072)
      end
      object chCutt: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 485.409710000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object Memo6: TfrxMemoView
        Left = 60.472480000000000000
        Top = 485.409710000000000000
        Width = 158.740260000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1042#1099#1088#1091#1073#1082#1072' '#1087#1086#1076' '#1092#1086#1090#1086)
      end
      object Memo1: TfrxMemoView
        Left = 37.795300000000000000
        Top = 262.315090000000000000
        Width = 71.811070000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1054#1073#1083#1086#1078#1082#1072)
        ParentFont = False
      end
      object Shape2: TfrxShapeView
        Left = 30.236240000000000000
        Top = 523.425480000000000000
        Width = 442.205010000000000000
        Height = 113.385900000000000000
        ShowHint = False
      end
      object Memo7: TfrxMemoView
        Left = 37.795300000000000000
        Top = 513.425480000000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1041#1083#1086#1082)
        ParentFont = False
      end
      object mSpreadMaterial: TfrxMemoView
        Left = 37.795300000000000000
        Top = 536.882190000000100000
        Width = 427.086890000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1052#1072#1090#1077#1088#1080#1072#1083':')
        ParentFont = False
      end
      object chForzac: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 585.118430000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object mForzacMaterial: TfrxMemoView
        Left = 60.472480000000000000
        Top = 585.118430000000000000
        Width = 411.968770000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1060#1086#1088#1079#1072#1094': '#1050#1072#1088#1090#1086#1085' '#1041#1072#1088#1093#1072#1090' '#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072)
      end
      object chRound: TfrxCheckBoxView
        Left = 37.795300000000000000
        Top = 611.575140000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        ShowHint = False
        CheckColor = clBlack
        CheckStyle = csCheck
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
      end
      object Memo8: TfrxMemoView
        Left = 60.472480000000000000
        Top = 611.575140000000000000
        Width = 120.944960000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1057#1082#1088#1091#1075#1083#1077#1085#1080#1077' '#1091#1075#1083#1086#1074)
      end
      object mPhone: TfrxMemoView
        Left = 37.795300000000000000
        Top = 155.047310000000000000
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
      object mManager: TfrxMemoView
        Left = 37.795300000000000000
        Top = 643.504330000000000000
        Width = 430.866420000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1052#1077#1085#1077#1076#1078#1077#1088': '#1055#1077#1088#1077#1075#1086#1077#1076#1086#1074' '#1040#1083#1077#1082#1089#1077#1081' '#1090#1077#1083'.: 89139995522')
      end
      object Memo10: TfrxMemoView
        Left = 37.795300000000000000
        Top = 185.283550000000000000
        Width = 132.283550000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1054#1073#1097#1080#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099)
        ParentFont = False
      end
      object Line4: TfrxLineView
        Left = 30.236240000000000000
        Top = 726.417750000000000000
        Width = 445.984540000000000000
        ShowHint = False
        Frame.Typ = [ftTop]
      end
      object Line5: TfrxLineView
        Left = 30.236240000000000000
        Top = 749.094930000000000000
        Width = 445.984540000000000000
        ShowHint = False
        Frame.Typ = [ftTop]
      end
      object mDesigner: TfrxMemoView
        Left = 37.795300000000000000
        Top = 667.165740000000000000
        Width = 430.866420000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Memo.UTF8W = (
          #1044#1080#1079#1072#1081#1085#1077#1088': '#1043#1086#1083#1091#1073#1082#1086#1074#1072' '#1040#1085#1085#1072' '#1090#1077#1083'.: 89139995522')
      end
      object mFinance: TfrxMemoView
        Left = 37.795300000000000000
        Top = 110.574830000000000000
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
      object Line1: TfrxLineView
        Left = 30.236240000000000000
        Top = 703.740570000000000000
        Width = 445.984540000000000000
        ShowHint = False
        Frame.Typ = [ftTop]
      end
      object mSpreadHarakt: TfrxMemoView
        Left = 37.795300000000000000
        Top = 561.338899999999900000
        Width = 427.086890000000000000
        Height = 18.897650000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072':')
        ParentFont = False
      end
      object mDataX: TfrxMemoView
        Left = 37.795300000000000000
        Top = 85.354360000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1075#1086#1090#1086#1074#1085#1086#1089#1090#1080':'
          '')
        ParentFont = False
      end
      object mCoverHarakt: TfrxMemoView
        Left = 37.795300000000000000
        Top = 331.244280000000000000
        Width = 434.645950000000000000
        Height = 22.677180000000000000
        ShowHint = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          #1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072':')
        ParentFont = False
      end
      object Memo9: TfrxMemoView
        Left = 26.456710000000000000
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
