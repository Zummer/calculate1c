inherited frOperationWithMat: TfrOperationWithMat
  Width = 770
  Height = 177
  ExplicitHeight = 177
  inherited BasePanel: TPanel
    Width = 770
    Height = 100
    Align = alTop
    ExplicitHeight = 100
    object chkEveryDetailHasOwnMaterial: TCheckBox
      Left = 400
      Top = 8
      Width = 201
      Height = 17
      Caption = #1059' '#1082#1072#1078#1076#1086#1081' '#1076#1077#1090#1072#1083#1080' '#1089#1074#1086#1081' '#1084#1072#1090#1077#1088#1080#1072#1083
      TabOrder = 2
      OnClick = chkEveryDetailHasOwnMaterialClick
    end
  end
  inherited pnlSelect: TPanel
    Width = 770
  end
  object sbForMatFrame: TScrollBox
    Left = 0
    Top = 130
    Width = 770
    Height = 47
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 2
    ExplicitWidth = 451
  end
end
