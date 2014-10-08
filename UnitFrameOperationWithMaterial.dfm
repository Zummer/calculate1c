inherited frOperationWithMaterial: TfrOperationWithMaterial
  Width = 815
  Height = 256
  ExplicitHeight = 256
  inherited BasePanel: TPanel
    Width = 815
    Height = 99
    Align = alTop
    ExplicitHeight = 99
    inherited cbHalfs: TComboBox
      TabOrder = 2
    end
    object chkEveryDetailHasOwnMaterial: TCheckBox
      Left = 400
      Top = 8
      Width = 201
      Height = 17
      Caption = #1059' '#1082#1072#1078#1076#1086#1081' '#1076#1077#1090#1072#1083#1080' '#1089#1074#1086#1081' '#1084#1072#1090#1077#1088#1080#1072#1083
      TabOrder = 1
      OnClick = chkEveryDetailHasOwnMaterialClick
    end
  end
  inherited pnlSelect: TPanel
    Width = 815
  end
  object sbForMatFrame: TScrollBox
    Left = 0
    Top = 129
    Width = 815
    Height = 127
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 2
    ExplicitWidth = 451
  end
end
