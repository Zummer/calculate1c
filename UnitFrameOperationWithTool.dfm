inherited frOperationWithTool: TfrOperationWithTool
  Width = 722
  Height = 127
  ExplicitHeight = 127
  inherited BasePanel: TPanel
    Width = 722
    Height = 97
    ExplicitHeight = 97
    inherited cbHalfs: TComboBox
      OnChange = nil
    end
  end
  inherited pnlSelect: TPanel
    Width = 722
    object cbTool: TComboBox
      Left = 151
      Top = 5
      Width = 153
      Height = 21
      TabOrder = 1
      Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1090#1072#1085#1086#1082
      OnChange = cbToolChange
      OnMouseEnter = cboxMouseEnter
    end
  end
end
