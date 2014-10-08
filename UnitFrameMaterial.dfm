object frMaterial: TfrMaterial
  Left = 0
  Top = 0
  Width = 821
  Height = 56
  Align = alTop
  TabOrder = 0
  ExplicitWidth = 451
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 821
    Height = 56
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 451
    object lbInfo: TLabel
      Left = 6
      Top = 33
      Width = 300
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086': 123 '#1084'2('#1096#1090'). '#1062#1077#1085#1072': 140 '#1088#1091#1073'. '#1054#1089#1090#1072#1090#1086#1082': 19000,999 '#1084'2'
    end
    object cbMaterial: TComboBox
      Left = 6
      Top = 6
      Width = 451
      Height = 21
      TabOrder = 0
      Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1084#1072#1090#1077#1088#1080#1072#1083
      OnChange = cbMaterialChange
      OnMouseEnter = ComboBoxMouseEnter
    end
    object eMatZak: TEdit
      Left = 26
      Top = 6
      Width = 394
      Height = 21
      TabOrder = 1
      Text = #1052#1072#1090#1077#1088#1080#1072#1083' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
      Visible = False
      OnChange = eMatZakChange
    end
    object chekMatZak: TCheckBox
      Left = 463
      Top = 8
      Width = 131
      Height = 17
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
      TabOrder = 2
      OnClick = chekMatZakClick
    end
    object eFind: TEdit
      Left = 600
      Top = 6
      Width = 105
      Height = 21
      TabOrder = 3
      OnKeyPress = eFindKeyPress
    end
    object btFindMaterials: TButton
      Left = 711
      Top = 4
      Width = 75
      Height = 25
      Caption = #1053#1072#1081#1090#1080
      TabOrder = 4
      OnClick = btFindMaterialsClick
    end
  end
end
