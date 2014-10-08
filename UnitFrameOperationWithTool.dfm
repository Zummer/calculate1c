inherited frOperationWithTool: TfrOperationWithTool
  Height = 127
  ExplicitHeight = 127
  inherited BasePanel: TPanel
    Height = 97
    ExplicitHeight = 97
  end
  inherited pnlSelect: TPanel
    object cbTool: TComboBox [3]
      Left = 151
      Top = 5
      Width = 153
      Height = 21
      TabOrder = 1
      Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1090#1072#1085#1086#1082
      OnChange = cbToolChange
      OnMouseEnter = cboxMouseEnter
    end
    inherited cbHalfs: TComboBox
      TabOrder = 2
      OnChange = nil
    end
  end
end
