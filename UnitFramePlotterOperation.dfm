inherited frPlotterOperation: TfrPlotterOperation
  Width = 451
  Height = 89
  ExplicitHeight = 89
  inherited BasePanel: TPanel
    Width = 451
    Height = 64
    ExplicitHeight = 64
    inherited lbCount: TLabel
      Left = 646
      Top = 9
      ExplicitLeft = 646
      ExplicitTop = 9
    end
    object Label3: TLabel [2]
      Left = 16
      Top = 36
      Width = 68
      Height = 13
      Caption = #1044#1083#1080#1085#1072' '#1088#1077#1079#1082#1080':'
    end
    object Label4: TLabel [3]
      Left = 156
      Top = 36
      Width = 6
      Height = 13
      Caption = #1084
    end
    object spLength: TAdvSpinEdit
      Left = 90
      Top = 33
      Width = 60
      Height = 22
      Value = 0
      DateValue = 41548.939876990740000000
      HexValue = 0
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      TabOrder = 3
      Visible = True
      Version = '1.5.3.4'
      OnChange = spLengthChange
    end
    object GroupBox3: TGroupBox
      Left = 232
      Top = 81
      Width = 361
      Height = 64
      Caption = #1056#1072#1079#1084#1077#1088#1099' '#1080' '#1082#1086#1083'-'#1074#1086' '#1084#1072#1090'-'#1083#1072':'
      Enabled = False
      TabOrder = 4
      Visible = False
      object Label19: TLabel
        Left = 81
        Top = 39
        Width = 6
        Height = 13
        Caption = 'x'
      end
      object Label2: TLabel
        Left = 152
        Top = 39
        Width = 11
        Height = 13
        Caption = #1089#1084
      end
      object lbMatSq: TLabel
        Left = 233
        Top = 40
        Width = 121
        Height = 13
        Caption = #1055#1083#1086#1097#1072#1076#1100': 123,55454 '#1084'2'
      end
      object Label6: TLabel
        Left = 238
        Top = 16
        Width = 39
        Height = 13
        Caption = #1050#1086#1083'-'#1074#1086':'
      end
      object Label7: TLabel
        Left = 336
        Top = 16
        Width = 18
        Height = 13
        Caption = #1096#1090'.'
      end
      object Label8: TLabel
        Left = 7
        Top = 16
        Width = 77
        Height = 13
        Caption = #1042#1099#1089#1086#1090#1072'/'#1044#1083#1080#1085#1072':'
      end
      object Label9: TLabel
        Left = 101
        Top = 15
        Width = 44
        Height = 13
        Caption = #1064#1080#1088#1080#1085#1072':'
      end
      object spMatHeight: TAdvSpinEdit
        Left = 18
        Top = 34
        Width = 57
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
      end
      object spMatWidth: TAdvSpinEdit
        Left = 93
        Top = 34
        Width = 57
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
      end
      object spMatCount: TAdvSpinEdit
        Left = 283
        Top = 12
        Width = 49
        Height = 22
        Value = 0
        DateValue = 41548.939877013890000000
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
      end
      object btnRotate: TButton
        Left = 181
        Top = 34
        Width = 27
        Height = 22
        Caption = '<>'
        TabOrder = 3
      end
    end
  end
  inherited pnlSelect: TPanel
    Width = 451
    ExplicitWidth = 901
  end
end
