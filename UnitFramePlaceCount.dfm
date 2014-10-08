object FramePlaceCount: TFramePlaceCount
  Left = 0
  Top = 0
  Width = 503
  Height = 117
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 503
    Height = 60
    Align = alTop
    Color = clSilver
    ParentBackground = False
    TabOrder = 0
    ExplicitWidth = 587
    object Label1: TLabel
      Left = 10
      Top = 10
      Width = 73
      Height = 13
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
    end
    object Label3: TLabel
      Left = 126
      Top = 9
      Width = 85
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086' '#1076#1077#1090#1072#1083#1077#1081':'
    end
    object Label4: TLabel
      Left = 273
      Top = 9
      Width = 42
      Height = 13
      Caption = #1060#1080#1083#1100#1090#1088':'
    end
    object Label16: TLabel
      Left = 126
      Top = 35
      Width = 11
      Height = 13
      Caption = 'c'#1084
    end
    object Label15: TLabel
      Left = 10
      Top = 29
      Width = 58
      Height = 26
      Caption = #1054#1090' '#1082#1088#1072#1103' '#1084#1072#1090#1077#1088#1080#1072#1083#1072':'
      WordWrap = True
    end
    object Label11: TLabel
      Left = 148
      Top = 29
      Width = 53
      Height = 26
      Caption = #1052#1077#1078#1076#1091' '#1076#1077#1090#1072#1083#1103#1084#1080':'
      WordWrap = True
    end
    object Label12: TLabel
      Left = 258
      Top = 35
      Width = 11
      Height = 13
      Caption = 'c'#1084
    end
    object Label2: TLabel
      Left = 298
      Top = 29
      Width = 39
      Height = 26
      Caption = #1055#1086#1083#1077' '#1074#1086#1082#1088#1091#1075':'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 394
      Top = 35
      Width = 11
      Height = 13
      Caption = 'c'#1084
    end
    object spDetailsCount: TAdvSpinEdit
      Left = 215
      Top = 6
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
      TabOrder = 0
      Visible = True
      Version = '1.5.3.4'
      OnChange = spDetailsCountChange
    end
    object eFilter: TEdit
      Left = 321
      Top = 6
      Width = 120
      Height = 21
      TabOrder = 1
    end
    object spFromEdge: TAdvSpinEdit
      Left = 74
      Top = 32
      Width = 46
      Height = 22
      AutoFocus = True
      SpinType = sptFloat
      Value = 0
      DateValue = 41915.590908391200000000
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
    end
    object spBetween: TAdvSpinEdit
      Left = 206
      Top = 32
      Width = 46
      Height = 22
      AutoFocus = True
      SpinType = sptFloat
      Value = 0
      DateValue = 41915.590908391200000000
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
      TabOrder = 3
      Visible = True
      Version = '1.5.3.4'
    end
    object spAround: TAdvSpinEdit
      Left = 342
      Top = 32
      Width = 46
      Height = 22
      AutoFocus = True
      SpinType = sptFloat
      Value = 0
      DateValue = 41915.590908391200000000
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
      TabOrder = 4
      Visible = True
      Version = '1.5.3.4'
      OnChange = spAroundChange
    end
    object Button1: TButton
      Left = 443
      Top = 4
      Width = 49
      Height = 25
      Caption = #1055#1086#1083#1103'...'
      TabOrder = 5
      OnClick = Button1Click
    end
  end
  object sb: TScrollBox
    Left = 0
    Top = 60
    Width = 503
    Height = 57
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 1
    ExplicitTop = 59
    ExplicitWidth = 587
    ExplicitHeight = 58
  end
end
