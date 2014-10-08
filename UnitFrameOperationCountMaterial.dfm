inherited frOperationCountMaterial: TfrOperationCountMaterial
  Width = 755
  Height = 134
  ExplicitWidth = 757
  ExplicitHeight = 134
  inherited BasePanel: TPanel
    Width = 755
    ExplicitWidth = 451
    inherited lbCount: TLabel
      Left = 5
      ExplicitLeft = 5
    end
  end
  inherited pnlSelect: TPanel
    Width = 755
    object cbMaterial: TComboBox
      Left = 311
      Top = 5
      Width = 144
      Height = 21
      TabOrder = 2
      Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1084#1072#1090#1077#1088#1080#1072#1083
      OnMouseEnter = cboxMouseEnter
    end
  end
end
