inherited frOperationLuvers: TfrOperationLuvers
  Width = 892
  inherited BasePanel: TPanel
    Width = 892
  end
  inherited pnlSelect: TPanel
    Width = 892
    inherited lbCount: TLabel
      Left = 589
      Top = 5
      ExplicitLeft = 589
      ExplicitTop = 5
    end
    object Label1: TLabel [2]
      Left = 240
      Top = 5
      Width = 98
      Height = 13
      Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1084#1077#1078#1076#1091':'
    end
    object Label4: TLabel [3]
      Left = 407
      Top = 5
      Width = 11
      Height = 13
      Caption = #1089#1084
    end
    object spBetween: TAdvSpinEdit
      Left = 344
      Top = 2
      Width = 57
      Height = 22
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
      MinValue = 1
      TabOrder = 1
      Visible = True
      Version = '1.5.3.4'
      OnChange = spChange
    end
  end
end
