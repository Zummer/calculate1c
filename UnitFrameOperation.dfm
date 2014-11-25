inherited frOperation: TfrOperation
  Width = 804
  Height = 125
  ExplicitHeight = 125
  inherited BasePanel: TPanel
    Width = 804
    Height = 95
    ExplicitHeight = 95
    object ListBoxOfOperations: TListBox
      Left = 664
      Top = 6
      Width = 121
      Height = 83
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 0
      OnClick = ListBoxOfOperationsClick
    end
    object cbHalfs: TComboBox
      Left = 553
      Top = 67
      Width = 105
      Height = 21
      TabOrder = 1
      Text = 'cbHalfs'
      OnChange = cbHalfsChange
    end
  end
  inherited pnlSelect: TPanel
    Width = 804
    Color = clSilver
    object lbCount: TLabel [1]
      Left = 365
      Top = 8
      Width = 139
      Height = 13
      Caption = #1055#1083#1086#1097#1072#1076#1100' '#1080#1083#1080' '#1082#1086#1083'-'#1074#1086': 14 '#1084'2'
    end
  end
end
