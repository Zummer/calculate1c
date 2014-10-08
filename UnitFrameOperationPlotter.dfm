inherited frOperationPlotter: TfrOperationPlotter
  inherited pnlSelect: TPanel
    inherited LabelSelect: TLabel
      Width = 93
      Caption = #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
      ExplicitWidth = 93
    end
    object Label16: TLabel [1]
      Left = 447
      Top = 8
      Width = 6
      Height = 13
      Caption = #1084
    end
    object Label1: TLabel [2]
      Left = 323
      Top = 8
      Width = 68
      Height = 13
      Caption = #1044#1083#1080#1085#1072' '#1088#1077#1079#1082#1080':'
    end
    inherited lbCount: TLabel
      Left = 477
      ExplicitLeft = 477
    end
    inherited cbTool: TComboBox
      TabOrder = 2
    end
    object spCount: TAdvSpinEdit
      Left = 392
      Top = 5
      Width = 49
      Height = 22
      AutoFocus = True
      Value = 0
      DateValue = 41902.535478437500000000
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
      OnChange = spCountChange
      OnKeyPress = spCountKeyPress
    end
  end
end
