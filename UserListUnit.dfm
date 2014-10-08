object frUserList: TfrUserList
  Left = 0
  Top = 0
  Width = 157
  Height = 183
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 157
    Height = 183
    Align = alClient
    Color = clInactiveCaption
    ParentBackground = False
    TabOrder = 0
    ExplicitWidth = 142
    ExplicitHeight = 113
    object Label1: TLabel
      Left = 7
      Top = 4
      Width = 62
      Height = 13
      Caption = #1057#1086#1090#1088#1091#1076#1085#1080#1082#1080
    end
    object Button1: TButton
      Left = 130
      Top = 1
      Width = 25
      Height = 20
      Caption = #1061
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 105
      Top = 1
      Width = 25
      Height = 20
      Caption = 'V'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object clUsers: TCheckListBox
      Left = 3
      Top = 21
      Width = 151
      Height = 159
      Align = alCustom
      ItemHeight = 13
      TabOrder = 2
    end
  end
end
