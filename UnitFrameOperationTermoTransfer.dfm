inherited frOperationTermoTransfer: TfrOperationTermoTransfer
  inherited BasePanel: TPanel
    inherited cbHalfs: TComboBox
      TabOrder = 2
    end
    object radioTechnos: TRadioGroup
      Left = 328
      Top = 6
      Width = 153
      Height = 67
      Caption = #1058#1077#1093#1085#1086#1083#1086#1075#1080#1080
      ItemIndex = 0
      Items.Strings = (
        #1057#1091#1073#1083#1080#1084#1072#1094#1080#1103
        #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
        #1054#1074#1072#1083#1099'-'#1090#1072#1073#1083#1080#1095#1082#1080)
      TabOrder = 1
      OnClick = radioTechnosClick
    end
  end
  inherited pnlSelect: TPanel
    inherited lbCount: TLabel
      Left = 477
      Top = 7
      ExplicitLeft = 477
      ExplicitTop = 7
    end
  end
end
