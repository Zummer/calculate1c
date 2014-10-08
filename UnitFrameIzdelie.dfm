inherited frIzdelie: TfrIzdelie
  Height = 133
  ParentFont = False
  OnMouseDown = FrameMouseDown
  ExplicitHeight = 133
  object Image1: TImage [0]
    Left = 383
    Top = 95
    Width = 171
    Height = 173
  end
  inherited BasePanel: TPanel
    Height = 103
    ExplicitHeight = 103
    object sbForSelFrame: TScrollBox
      Left = 1
      Top = 1
      Width = 449
      Height = 101
      Align = alClient
      TabOrder = 0
    end
  end
  inherited pnlSelect: TPanel
    object btAddTechnos: TButton
      Left = 216
      Top = 3
      Width = 137
      Height = 24
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1087#1077#1088#1072#1094#1080#1102
      TabOrder = 1
      OnClick = btAddTechnosClick
    end
    object btnDeleteTechnos: TButton
      Left = 425
      Top = 3
      Width = 208
      Height = 24
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1086#1089#1083#1077#1076#1085#1102#1102' '#1086#1087#1077#1088#1072#1094#1080#1102
      TabOrder = 2
      OnClick = btnDeleteTechnosClick
    end
    object btnCollapseTechnos: TButton
      Left = 383
      Top = 3
      Width = 24
      Height = 24
      Caption = '<>'
      TabOrder = 3
      OnClick = btnCollapseTechnosClick
    end
  end
end
