object frSelectable: TfrSelectable
  Left = 0
  Top = 0
  Width = 451
  Height = 60
  Align = alTop
  Color = clBtnFace
  ParentBackground = False
  ParentColor = False
  TabOrder = 0
  OnResize = FrameResize
  object BasePanel: TPanel
    Left = 0
    Top = 30
    Width = 451
    Height = 30
    Align = alClient
    TabOrder = 0
  end
  object pnlSelect: TPanel
    Left = 0
    Top = 0
    Width = 451
    Height = 30
    Align = alTop
    ParentBackground = False
    TabOrder = 1
    OnMouseDown = pnlSelectMouseDown
    object LabelSelect: TLabel
      Left = 36
      Top = 8
      Width = 54
      Height = 13
      Caption = 'LabelSelect'
      OnMouseDown = LabelSelectMouseDown
    end
    object btnMinimize: TButton
      Left = 5
      Top = 7
      Width = 25
      Height = 15
      Caption = '<>'
      TabOrder = 0
      OnClick = btnMinimizeToggleClick
    end
  end
end
