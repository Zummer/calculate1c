object FrameSimpleCount: TFrameSimpleCount
  Left = 0
  Top = 0
  Width = 455
  Height = 26
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 455
    Height = 26
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 6
      Width = 73
      Height = 13
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
    end
    object Label2: TLabel
      Left = 110
      Top = 6
      Width = 39
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086':'
    end
    object Label3: TLabel
      Left = 210
      Top = 6
      Width = 18
      Height = 13
      Caption = #1096#1090'.'
    end
    object Label4: TLabel
      Left = 237
      Top = 6
      Width = 42
      Height = 13
      Caption = #1060#1080#1083#1100#1090#1088':'
    end
    object spCount: TAdvSpinEdit
      Left = 155
      Top = 3
      Width = 49
      Height = 22
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
      TabOrder = 0
      Visible = True
      Version = '1.5.3.4'
      OnChange = spCountChange
    end
    object eFilter: TEdit
      Left = 297
      Top = 3
      Width = 96
      Height = 21
      TabOrder = 1
    end
  end
end
