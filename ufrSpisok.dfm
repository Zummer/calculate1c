object frSpisok: TfrSpisok
  Left = 0
  Top = 0
  Width = 185
  Height = 97
  TabOrder = 0
  object CheckListBox1: TCheckListBox
    Left = 0
    Top = 33
    Width = 185
    Height = 64
    Align = alClient
    ItemHeight = 13
    TabOrder = 0
    ExplicitWidth = 235
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 33
    Align = alTop
    TabOrder = 1
    ExplicitWidth = 235
    object Label1: TLabel
      Left = 9
      Top = 9
      Width = 36
      Height = 13
      Caption = #1057#1087#1080#1089#1086#1082
    end
    object btCheckAll: TButton
      Left = 97
      Top = 4
      Width = 33
      Height = 25
      Caption = 'V'
      TabOrder = 0
      OnClick = btCheckAllClick
    end
    object btDeleteCkecked: TButton
      Left = 131
      Top = 4
      Width = 33
      Height = 25
      Caption = 'X'
      TabOrder = 1
    end
  end
end
