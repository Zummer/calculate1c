inherited frMaterialSquareBase: TfrMaterialSquareBase
  Width = 815
  Height = 76
  ExplicitHeight = 76
  inherited Panel1: TPanel
    Width = 815
    Height = 76
    ExplicitHeight = 76
    inherited lbInfo: TLabel
      Left = 5
      Top = 32
      ExplicitLeft = 5
      ExplicitTop = 32
    end
    object LabelCountOfBases: TLabel [1]
      Left = 5
      Top = 51
      Width = 135
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086' '#1101#1083#1077#1084#1077#1085#1090#1086#1074' '#1086#1089#1085#1086#1074#1099':'
    end
    inherited cbMaterial: TComboBox
      Left = 5
      Top = 5
      Width = 432
      ExplicitLeft = 5
      ExplicitTop = 5
      ExplicitWidth = 432
    end
    inherited eMatZak: TEdit
      Left = 14
      Top = 5
      ExplicitLeft = 14
      ExplicitTop = 5
    end
    inherited chekMatZak: TCheckBox
      Left = 443
      Top = 7
      ExplicitLeft = 443
      ExplicitTop = 7
    end
    inherited eFind: TEdit
      Left = 580
      Width = 125
      ExplicitLeft = 580
      ExplicitWidth = 125
    end
    inherited btFindMaterials: TButton
      TabOrder = 6
    end
    inherited spWidth: TAdvSpinEdit
      TabOrder = 4
    end
    inherited spHeightLength: TAdvSpinEdit
      TabOrder = 5
    end
  end
end
