inherited frPrint: TfrPrint
  Height = 213
  ExplicitHeight = 213
  inherited BasePanel: TPanel
    Top = 19
    Width = 649
    Height = 194
    Align = alLeft
    ExplicitTop = 19
    ExplicitWidth = 649
    ExplicitHeight = 194
    object Label4: TLabel
      Left = 289
      Top = 53
      Width = 86
      Height = 13
      Caption = #1053#1072' '#1089#1082#1083#1072#1076#1077': 100 '#1084
    end
    object Label6: TLabel
      Left = 8
      Top = 12
      Width = 54
      Height = 13
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083':'
    end
    object lbWidth: TLabel
      Left = 381
      Top = 53
      Width = 79
      Height = 13
      Caption = #1064#1080#1088#1080#1085#1072': 152 '#1089#1084
    end
    object Label9: TLabel
      Left = 381
      Top = 128
      Width = 11
      Height = 13
      Caption = #1089#1084
    end
    object Label10: TLabel
      Left = 381
      Top = 101
      Width = 18
      Height = 13
      Caption = #1096#1090'.'
    end
    object cbPrinter: TComboBox
      Left = 161
      Top = 49
      Width = 93
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      OnChange = cbPrinterChange
    end
    object cbMaterial: TComboBox
      Left = 68
      Top = 9
      Width = 517
      Height = 21
      TabOrder = 1
      Text = #1052#1072#1090#1077#1088#1080#1072#1083
      OnSelect = cbMaterialSelect
    end
    object GroupBox1: TGroupBox
      Left = 471
      Top = 36
      Width = 172
      Height = 74
      Caption = #1055#1086#1089#1083#1077#1076#1091#1102#1097#1080#1077' '#1086#1087#1077#1088#1072#1094#1080#1080': '
      TabOrder = 2
      object SpeedButton1: TSpeedButton
        Left = 144
        Top = 12
        Width = 23
        Height = 19
        Caption = '+'
        Enabled = False
      end
      object CheckBox2: TCheckBox
        Left = 8
        Top = 14
        Width = 87
        Height = 17
        Caption = #1051#1072#1084#1080#1085#1072#1094#1080#1103
        TabOrder = 0
        OnClick = CheckBox2Click
      end
      object CheckBox3: TCheckBox
        Left = 8
        Top = 52
        Width = 143
        Height = 17
        Caption = #1053#1072#1090#1103#1078#1082#1072' '#1085#1072' '#1087#1086#1076#1088#1072#1084#1085#1080#1082
        TabOrder = 1
        OnClick = CheckBox3Click
      end
      object CheckBox4: TCheckBox
        Left = 8
        Top = 32
        Width = 130
        Height = 17
        Caption = #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
        TabOrder = 2
        OnClick = CheckBox4Click
      end
    end
    object GroupBox4: TGroupBox
      Left = 160
      Top = 74
      Width = 146
      Height = 124
      Caption = #1056#1091#1083#1086#1085': '
      TabOrder = 3
      object Label20: TLabel
        Left = 8
        Top = 35
        Width = 86
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088#1099' '#1088#1091#1083#1086#1085#1072':'
      end
      object Label22: TLabel
        Left = 63
        Top = 55
        Width = 6
        Height = 13
        Caption = 'x'
      end
      object Label21: TLabel
        Left = 126
        Top = 55
        Width = 11
        Height = 13
        Caption = #1089#1084
      end
      object Label27: TLabel
        Left = 8
        Top = 17
        Width = 44
        Height = 13
        Caption = #1064#1080#1088#1080#1085#1072':'
      end
      object Label28: TLabel
        Left = 10
        Top = 77
        Width = 64
        Height = 13
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      end
      object lbRollsCount: TLabel
        Left = 12
        Top = 96
        Width = 41
        Height = 13
        Caption = '0,1 '#1088#1091#1083'.'
      end
      object spRollHeight: TAdvSpinEdit
        Left = 8
        Top = 51
        Width = 49
        Height = 22
        AutoFocus = True
        Value = 0
        DateValue = 41830.690802222220000000
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
        TabOrder = 0
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
      end
      object ComboBox5: TComboBox
        Left = 54
        Top = 14
        Width = 84
        Height = 21
        Enabled = False
        TabOrder = 1
        Text = 'ComboBox3'
      end
      object spRollWidth: TAdvSpinEdit
        Left = 73
        Top = 51
        Width = 49
        Height = 22
        AutoFocus = True
        Value = 60
        FloatValue = 60.000000000000000000
        HexValue = 0
        Color = clWhite
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 160
        MinValue = 60
        TabOrder = 2
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
    end
    object GroupBox5: TGroupBox
      Left = 471
      Top = 111
      Width = 169
      Height = 92
      Caption = #1044#1086#1087#1086#1083#1085'. '#1087#1072#1088#1072#1084#1077#1090#1088#1099': '
      TabOrder = 4
      object Label11: TLabel
        Left = 8
        Top = 67
        Width = 87
        Height = 13
        Caption = #1052#1077#1078'. '#1080#1079#1076#1077#1083#1080#1103#1084#1080':'
      end
      object Label15: TLabel
        Left = 8
        Top = 19
        Width = 83
        Height = 13
        Caption = #1054#1090#1089#1090#1091#1087' '#1086#1090' '#1082#1088#1072#1103':'
      end
      object Label16: TLabel
        Left = 150
        Top = 19
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object Label17: TLabel
        Left = 150
        Top = 43
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object Label18: TLabel
        Left = 8
        Top = 43
        Width = 84
        Height = 13
        Caption = #1042#1086#1082#1088#1091#1075' '#1080#1079#1076#1077#1083#1080#1103':'
      end
      object Label12: TLabel
        Left = 150
        Top = 67
        Width = 11
        Height = 13
        Caption = 'c'#1084
      end
      object spBetween: TAdvSpinEdit
        Left = 98
        Top = 62
        Width = 49
        Height = 22
        AutoFocus = True
        Value = 0
        DateValue = 41830.690802280090000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 10000
        TabOrder = 0
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object spFromEdge: TAdvSpinEdit
        Left = 97
        Top = 15
        Width = 49
        Height = 22
        AutoFocus = True
        Value = 0
        DateValue = 41830.690802280090000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 10000
        TabOrder = 1
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object spTechPole: TAdvSpinEdit
        Left = 98
        Top = 39
        Width = 49
        Height = 22
        AutoFocus = True
        Value = 0
        DateValue = 41830.690802280090000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 10000
        TabOrder = 2
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
    end
    object chboxAgentMat: TCheckBox
      Left = 161
      Top = 31
      Width = 136
      Height = 17
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
      TabOrder = 5
      Visible = False
      OnClick = chboxAgentMatClick
    end
    object eAgentMat: TEdit
      Left = 286
      Top = 31
      Width = 117
      Height = 21
      TabOrder = 6
      Visible = False
    end
    object CheckBox1: TCheckBox
      Left = 323
      Top = 74
      Width = 137
      Height = 17
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1083#1102#1074#1077#1088#1089#1086#1074
      TabOrder = 7
      OnClick = CheckBox1Click
    end
    object spLuversCount: TAdvSpinEdit
      Left = 323
      Top = 97
      Width = 52
      Height = 22
      AutoFocus = True
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
      MaxValue = 10000
      MinValue = 1
      TabOrder = 8
      Visible = True
      Version = '1.5.3.4'
      OnChange = spAllChange
      OnEnter = spEnter
      OnExit = spExit
      OnKeyPress = spKeyPress
    end
    object advBetweenLuvers: TAdvSpinEdit
      Left = 323
      Top = 125
      Width = 52
      Height = 22
      AutoFocus = True
      Value = 30
      FloatValue = 30.000000000000000000
      HexValue = 0
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      MaxValue = 10000
      MinValue = 5
      TabOrder = 9
      Visible = True
      Version = '1.5.3.4'
      OnChange = spAllChange
      OnEnter = spEnter
      OnExit = spExit
      OnKeyPress = spKeyPress
    end
    object GroupBox2: TGroupBox
      Left = 6
      Top = 36
      Width = 149
      Height = 161
      Caption = #1048#1079#1076#1077#1083#1080#1077': '
      TabOrder = 10
      object Label24: TLabel
        Left = 10
        Top = 16
        Width = 42
        Height = 13
        Caption = #1060#1086#1088#1084#1072#1090':'
      end
      object Label7: TLabel
        Left = 10
        Top = 35
        Width = 92
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088#1099' '#1080#1079#1076#1077#1083#1080#1103':'
      end
      object Label1: TLabel
        Left = 52
        Top = 54
        Width = 6
        Height = 13
        Caption = 'x'
      end
      object Label3: TLabel
        Left = 101
        Top = 54
        Width = 11
        Height = 13
        Caption = #1089#1084
      end
      object Label8: TLabel
        Left = 10
        Top = 113
        Width = 132
        Height = 13
        Caption = #1050#1086#1083'-'#1074#1086': '#1080#1079#1076#1077#1083#1080#1081' / '#1092#1072#1081#1083#1086#1074
      end
      object lbRealSize: TLabel
        Left = 10
        Top = 92
        Width = 64
        Height = 13
        Caption = 'h30 x w40 '#1089#1084
      end
      object Label5: TLabel
        Left = 10
        Top = 76
        Width = 123
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088' '#1087#1077#1095#1072#1090#1080' '#1080#1079#1076#1077#1083#1080#1103':'
      end
      object ComboBox3: TComboBox
        Left = 55
        Top = 13
        Width = 87
        Height = 21
        Enabled = False
        TabOrder = 0
        Text = 'ComboBox3'
      end
      object spH: TAdvSpinEdit
        Left = 10
        Top = 51
        Width = 40
        Height = 22
        AutoFocus = True
        Value = 30
        FloatValue = 30.000000000000000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 10000
        MinValue = 5
        TabOrder = 1
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object spW: TAdvSpinEdit
        Left = 60
        Top = 51
        Width = 40
        Height = 22
        AutoFocus = True
        Value = 40
        FloatValue = 40.000000000000000000
        HexValue = 0
        IncrementFloat = 0.100000000000000000
        IncrementFloatPage = 1.000000000000000000
        LabelFont.Charset = DEFAULT_CHARSET
        LabelFont.Color = clWindowText
        LabelFont.Height = -11
        LabelFont.Name = 'Tahoma'
        LabelFont.Style = []
        MaxValue = 10000
        MinValue = 5
        TabOrder = 2
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object spIzdCount: TAdvSpinEdit
        Left = 10
        Top = 130
        Width = 52
        Height = 22
        AutoFocus = True
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
        MaxValue = 10000
        MinValue = 1
        TabOrder = 3
        Visible = True
        Version = '1.5.3.4'
        OnChange = spAllChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object Button1: TButton
        Left = 116
        Top = 49
        Width = 25
        Height = 25
        Caption = '<>'
        TabOrder = 4
        OnClick = Button1Click
      end
      object spFilesCount: TAdvSpinEdit
        Left = 89
        Top = 130
        Width = 52
        Height = 22
        AutoFocus = True
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
        MaxValue = 10000
        TabOrder = 5
        Visible = True
        Version = '1.5.3.4'
        OnChange = spFilesCountChange
        OnEnter = spEnter
        OnExit = spExit
        OnKeyPress = spKeyPress
      end
      object chIzdFiles: TCheckBox
        Left = 68
        Top = 132
        Width = 15
        Height = 17
        Checked = True
        State = cbChecked
        TabOrder = 6
        OnClick = chIzdFilesClick
      end
      object chboxRezIzd: TCheckBox
        Left = 94
        Top = 92
        Width = 48
        Height = 17
        Caption = #1056#1077#1079#1082#1072
        Checked = True
        State = cbChecked
        TabOrder = 7
        OnClick = chboxRezClick
      end
    end
  end
  inherited pnlSelect: TPanel
    Height = 19
    ExplicitWidth = 898
    ExplicitHeight = 19
  end
  object btFindAgents: TButton
    Left = 591
    Top = 25
    Width = 52
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    Enabled = False
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 649
    Top = 19
    Width = 249
    Height = 194
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 3
    object sbForPrint: TScrollBox
      Left = 1
      Top = 1
      Width = 247
      Height = 192
      HorzScrollBar.Visible = False
      VertScrollBar.Visible = False
      Align = alClient
      BevelInner = bvNone
      BorderStyle = bsNone
      TabOrder = 0
      OnMouseEnter = sbForPrintMouseEnter
      OnMouseLeave = sbForPrintMouseLeave
      OnMouseWheel = sbForPrintMouseWheel
      object Edit1: TEdit
        Left = 247
        Top = 165
        Width = 52
        Height = 21
        Color = clBtnFace
        TabOrder = 0
        Text = 'Edit1'
      end
      object GroupBox3: TGroupBox
        Left = 80
        Top = 69
        Width = 152
        Height = 118
        Enabled = False
        TabOrder = 1
        Visible = False
        object Label14: TLabel
          Left = 10
          Top = 30
          Width = 79
          Height = 13
          Caption = #1056#1072#1079#1084#1077#1088#1099' '#1083#1080#1089#1090#1072':'
        end
        object Label19: TLabel
          Left = 63
          Top = 49
          Width = 6
          Height = 13
          Caption = 'x'
        end
        object Label2: TLabel
          Left = 126
          Top = 49
          Width = 11
          Height = 13
          Caption = #1089#1084
        end
        object lbCountOfPrintList: TLabel
          Left = 10
          Top = 93
          Width = 50
          Height = 13
          Caption = '10 '#1083#1080#1089#1090#1086#1074
        end
        object Label25: TLabel
          Left = 10
          Top = 11
          Width = 42
          Height = 13
          Caption = #1060#1086#1088#1084#1072#1090':'
        end
        object Label26: TLabel
          Left = 10
          Top = 72
          Width = 64
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
        end
        object spPrintListHeight: TAdvSpinEdit
          Left = 8
          Top = 44
          Width = 49
          Height = 22
          AutoFocus = True
          Value = 100
          FloatValue = 100.000000000000000000
          HexValue = 0
          IncrementFloat = 0.100000000000000000
          IncrementFloatPage = 1.000000000000000000
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          MaxValue = 10000
          MinValue = 10
          TabOrder = 0
          Visible = True
          Version = '1.5.3.4'
          OnChange = spAllChange
          OnEnter = spEnter
          OnExit = spExit
          OnKeyPress = spKeyPress
        end
        object spPrintListWidth: TAdvSpinEdit
          Left = 71
          Top = 44
          Width = 49
          Height = 22
          AutoFocus = True
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
          MaxValue = 10000
          MinValue = 10
          TabOrder = 1
          Visible = True
          Version = '1.5.3.4'
          OnChange = spAllChange
          OnEnter = spEnter
          OnExit = spExit
          OnKeyPress = spKeyPress
        end
        object Button2: TButton
          Left = 116
          Top = 83
          Width = 25
          Height = 25
          Caption = '<>'
          TabOrder = 2
          OnClick = Button2Click
        end
        object ComboBox4: TComboBox
          Left = 55
          Top = 8
          Width = 87
          Height = 21
          Enabled = False
          TabOrder = 3
          Text = 'ComboBox3'
        end
        object chboxRezList: TCheckBox
          Left = 80
          Top = 68
          Width = 48
          Height = 17
          Caption = #1056#1077#1079#1082#1072
          Checked = True
          State = cbChecked
          TabOrder = 4
          OnClick = chboxRezClick
        end
      end
      object chboxSplitRoll: TCheckBox
        Left = 90
        Top = 60
        Width = 101
        Height = 17
        Caption = #1055#1077#1095#1072#1090#1085#1099#1081' '#1083#1080#1089#1090':'
        Enabled = False
        TabOrder = 2
        Visible = False
        OnClick = chboxSplitRollClick
      end
    end
  end
end
