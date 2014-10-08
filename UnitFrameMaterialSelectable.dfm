inherited frMaterialSelectable: TfrMaterialSelectable
  Width = 921
  Height = 57
  ExplicitHeight = 57
  inherited BasePanel: TPanel
    Width = 921
    Height = 27
    ExplicitHeight = 27
    object lbInfo: TLabel
      Left = 16
      Top = 6
      Width = 28
      Height = 13
      Caption = 'lbInfo'
    end
  end
  inherited pnlSelect: TPanel
    Width = 921
    inherited LabelSelect: TLabel
      Top = 7
      ExplicitTop = 7
    end
    object Label3: TLabel [1]
      Left = 609
      Top = 8
      Width = 39
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086':'
    end
    object labelUnitW: TLabel [2]
      Left = 709
      Top = 8
      Width = 18
      Height = 13
      Caption = #1096#1090'.'
    end
    object cbMaterial: TComboBox
      Left = 112
      Top = 4
      Width = 353
      Height = 21
      TabOrder = 1
      Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1084#1072#1090#1077#1088#1080#1072#1083
      OnChange = cbMaterialChange
      OnMouseEnter = cboxMouseEnter
    end
    object chekMatZak: TCheckBox
      Left = 473
      Top = 6
      Width = 131
      Height = 17
      Caption = #1052#1072#1090#1077#1088#1080#1072#1083' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
      TabOrder = 2
      OnClick = chekMatZakClick
    end
    object eMatZak: TEdit
      Left = 112
      Top = 4
      Width = 332
      Height = 21
      TabOrder = 3
      Text = #1052#1072#1090#1077#1088#1080#1072#1083' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
      Visible = False
      OnChange = eMatZakChange
    end
    object spCount: TAdvSpinEdit
      Left = 651
      Top = 4
      Width = 54
      Height = 22
      AutoFocus = True
      Value = 1
      FloatValue = 1.000000000000000000
      TimeValue = 0.041666666666666660
      HexValue = 0
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      MinValue = 1
      TabOrder = 4
      Visible = True
      Version = '1.5.3.4'
      OnChange = spCountChange
      OnKeyPress = spCountKeyPress
    end
    object btFindMaterials: TButton
      Left = 834
      Top = 3
      Width = 52
      Height = 25
      Caption = #1053#1072#1081#1090#1080
      TabOrder = 5
      OnClick = btFindMaterialsClick
    end
    object eFind: TEdit
      Left = 730
      Top = 5
      Width = 100
      Height = 21
      TabOrder = 6
      OnKeyPress = eFindKeyPress
    end
  end
end
