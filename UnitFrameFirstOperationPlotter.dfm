inherited frFirstOperationPlotter: TfrFirstOperationPlotter
  Width = 869
  inherited BasePanel: TPanel
    Width = 869
  end
  inherited pnlSelect: TPanel
    Width = 869
    inherited lbCount: TLabel
      Left = 374
      Top = 11
      ExplicitLeft = 374
      ExplicitTop = 11
    end
    object Label3: TLabel [2]
      Left = 631
      Top = 7
      Width = 6
      Height = 13
      Caption = #1084
    end
    inherited cbTool: TComboBox
      TabOrder = 3
    end
    object spCount: TAdvSpinEdit
      Left = 576
      Top = 4
      Width = 49
      Height = 22
      AutoFocus = True
      Value = 0
      DateValue = 41902.531986539350000000
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
  inherited sbForMatFrame: TScrollBox
    Width = 869
  end
end
