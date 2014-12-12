inherited frPlaceOperation: TfrPlaceOperation
  Height = 211
  ExplicitHeight = 211
  inherited BasePanel: TPanel
    object LabelIzdelieSize: TLabel [0]
      Left = 791
      Top = 86
      Width = 197
      Height = 13
      Caption = #1055#1077#1095#1072#1090#1085#1099#1081' '#1088#1072#1079#1084#1077#1088' '#1080#1079#1076#1077#1083#1080#1103': 150*150 '#1089#1084
      Visible = False
    end
    object LabelSq: TLabel [1]
      Left = 791
      Top = 56
      Width = 175
      Height = 13
      Caption = #1056#1072#1089#1095#1077#1090#1085#1072#1103' '#1087#1083#1086#1097#1072#1076#1100' '#1087#1077#1095#1072#1090#1080': 20 '#1084'2'
      Visible = False
    end
    object lbBaseCount: TLabel [2]
      Left = 805
      Top = 48
      Width = 42
      Height = 13
      Caption = #1088#1091#1083#1086#1085#1086#1074
      Visible = False
    end
    object Label26: TLabel [3]
      Left = 805
      Top = 67
      Width = 64
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      Visible = False
    end
    object lbOstatokBase: TLabel [4]
      Left = 791
      Top = 67
      Width = 41
      Height = 13
      Caption = #1086#1089#1090#1072#1090#1086#1082
      Visible = False
    end
    object lbSheetCount: TLabel [5]
      Left = 805
      Top = 37
      Width = 35
      Height = 13
      Caption = #1083#1080#1089#1090#1086#1074
      Visible = False
    end
    object GroupBox5: TGroupBox [6]
      Left = 792
      Top = 6
      Width = 122
      Height = 87
      Caption = #1044#1086#1087#1086#1083#1085'. '#1087#1072#1088#1072#1084#1077#1090#1088#1099': '
      TabOrder = 0
      object Label11: TLabel
        Left = 8
        Top = 43
        Width = 39
        Height = 13
        Caption = #1052#1077#1078#1076#1091':'
      end
      object Label15: TLabel
        Left = 8
        Top = 19
        Width = 45
        Height = 13
        Caption = #1054#1090' '#1082#1088#1072#1103':'
      end
      object Label16: TLabel
        Left = 106
        Top = 20
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object Label12: TLabel
        Left = 106
        Top = 43
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object Label2: TLabel
        Left = 8
        Top = 66
        Width = 29
        Height = 13
        Caption = #1055#1086#1083#1103':'
      end
      object Label4: TLabel
        Left = 106
        Top = 66
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object spBetween: TAdvSpinEdit
        Left = 54
        Top = 38
        Width = 49
        Height = 22
        AutoFocus = True
        SpinType = sptFloat
        Value = 0
        DateValue = 41980.901257118060000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        IncrementSmart = True
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxFloatValue = 10000.000000000000000000
        TabOrder = 0
        Visible = True
        Version = '1.5.3.4'
        OnChange = spBetweenChange
      end
      object spFromEdge: TAdvSpinEdit
        Left = 54
        Top = 15
        Width = 49
        Height = 22
        AutoFocus = True
        SpinType = sptFloat
        Value = 0
        DateValue = 41980.901257118060000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        IncrementSmart = True
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxFloatValue = 10000.000000000000000000
        TabOrder = 1
        Visible = True
        Version = '1.5.3.4'
        OnChange = spFromEdgeChange
      end
      object spAround: TAdvSpinEdit
        Left = 54
        Top = 61
        Width = 49
        Height = 22
        AutoFocus = True
        SpinType = sptFloat
        Value = 0
        DateValue = 41980.901257118060000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        IncrementSmart = True
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxFloatValue = 10000.000000000000000000
        TabOrder = 2
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAroundChange
      end
    end
    object Button1: TButton [7]
      Left = 636
      Top = 67
      Width = 22
      Height = 22
      Caption = '<>'
      TabOrder = 1
    end
    object groupSheet: TGroupBox [8]
      Left = 658
      Top = 6
      Width = 127
      Height = 59
      TabOrder = 2
      Visible = False
      object Label14: TLabel
        Left = 7
        Top = 12
        Width = 79
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088#1099' '#1083#1080#1089#1090#1072':'
      end
      object Label19: TLabel
        Left = 57
        Top = 37
        Width = 6
        Height = 13
        Caption = 'x'
      end
      object Label1: TLabel
        Left = 117
        Top = 37
        Width = 11
        Height = 13
        Caption = #1089#1084
      end
      object spListHeight: TAdvSpinEdit
        Left = 5
        Top = 32
        Width = 49
        Height = 22
        AutoFocus = True
        SpinType = sptFloat
        Value = 25
        FloatValue = 25.000000000000000000
        HexValue = 0
        CheckMinValue = True
        CheckMaxValue = True
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        IncrementSmart = True
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        TabOrder = 0
        Visible = True
        Version = '1.5.3.4'
      end
      object spListWidth: TAdvSpinEdit
        Left = 66
        Top = 32
        Width = 49
        Height = 22
        AutoFocus = True
        SpinType = sptFloat
        Value = 100
        FloatValue = 100.000000000000000000
        HexValue = 0
        CheckMinValue = True
        CheckMaxValue = True
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        IncrementSmart = True
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MinFloatValue = 10.000000000000000000
        MaxFloatValue = 10000.000000000000000000
        TabOrder = 1
        Visible = True
        Version = '1.5.3.4'
      end
    end
    object chboxSplitRoll: TCheckBox [9]
      Left = 665
      Top = -1
      Width = 113
      Height = 17
      Caption = #1044#1077#1083#1077#1085#1080#1077' '#1085#1072' '#1083#1080#1089#1090#1099':'
      TabOrder = 3
      Visible = False
    end
    inherited ListBoxOfOperations: TListBox
      TabOrder = 4
    end
    object ScrollBox1: TScrollBox [11]
      Left = 1
      Top = 1
      Width = 562
      Height = 97
      Align = alLeft
      TabOrder = 5
    end
    inherited cbHalfs: TComboBox
      Left = 584
      Width = 113
      TabOrder = 8
      ExplicitLeft = 584
      ExplicitWidth = 113
    end
    object chbAutoPlace: TCheckBox [13]
      Left = 795
      Top = 6
      Width = 106
      Height = 17
      Caption = #1040#1074#1090#1086' '#1088#1072#1079#1084#1077#1097#1077#1085#1080#1077
      TabOrder = 7
      OnClick = chbAutoPlaceClick
    end
    inherited chkEveryDetailHasOwnMaterial: TCheckBox
      Left = 569
      Top = 6
      Width = 90
      Height = 55
      TabOrder = 6
      Visible = False
      WordWrap = True
      ExplicitLeft = 569
      ExplicitTop = 6
      ExplicitWidth = 90
      ExplicitHeight = 55
    end
  end
  inherited pnlSelect: TPanel
    inherited LabelSelect: TLabel
      OnMouseDown = pnlSelectMouseDown
    end
    inherited lbCount: TLabel
      OnMouseDown = pnlSelectMouseDown
    end
    inherited cbTool: TComboBox
      Width = 138
      ExplicitWidth = 138
    end
    object spDetailsCount: TAdvSpinEdit
      Left = 304
      Top = 4
      Width = 52
      Height = 22
      AutoFocus = True
      Value = 1
      FloatValue = 1.000000000000000000
      TimeValue = 0.041666666666666660
      HexValue = 0
      CheckMinValue = True
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      MaxValue = 10000
      MinValue = 1
      TabOrder = 2
      Visible = True
      Version = '1.5.3.4'
      OnChange = spDetailsCountChange
      OnKeyPress = spDetailsCountKeyPress
    end
  end
  inherited sbForMatFrame: TScrollBox
    Height = 82
    ExplicitWidth = 928
    ExplicitHeight = 82
  end
end
