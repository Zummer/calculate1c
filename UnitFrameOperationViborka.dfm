inherited frOperationViborka: TfrOperationViborka
  Width = 839
  Height = 123
  ExplicitHeight = 123
  inherited BasePanel: TPanel
    Width = 839
    Height = 93
    ExplicitHeight = 93
  end
  inherited pnlSelect: TPanel
    Width = 839
    inherited lbCount: TLabel
      Left = 485
      Top = 9
      ExplicitLeft = 485
      ExplicitTop = 9
    end
    inherited cbHalfs: TComboBox
      OnChange = nil
    end
    object chbSimpleForms: TCheckBox
      Left = 144
      Top = 7
      Width = 97
      Height = 17
      Caption = #1055#1088#1086#1089#1090#1099#1077' '#1092#1086#1088#1084#1099
      TabOrder = 2
      OnClick = chbSimpleFormsClick
    end
    object chbLittleDetails: TCheckBox
      Left = 247
      Top = 7
      Width = 97
      Height = 17
      Caption = #1052#1077#1083#1082#1080#1077' '#1076#1077#1090#1072#1083#1080
      TabOrder = 3
      OnClick = chbLittleDetailsClick
    end
    object chbTermo: TCheckBox
      Left = 360
      Top = 8
      Width = 97
      Height = 17
      Caption = #1058#1077#1088#1084#1086#1087#1083#1077#1085#1082#1072
      TabOrder = 4
      OnClick = chbTermoClick
    end
  end
end
