object fFindOrders: TfFindOrders
  Left = 0
  Top = 0
  Caption = #1055#1086#1080#1089#1082' '#1079#1072#1082#1072#1079#1086#1074
  ClientHeight = 503
  ClientWidth = 1008
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 829
    Height = 503
    Align = alClient
    TabOrder = 0
    object Splitter2: TSplitter
      Left = 1
      Top = 355
      Width = 827
      Height = 5
      Cursor = crVSplit
      Align = alBottom
      ExplicitLeft = -4
      ExplicitTop = 277
      ExplicitWidth = 652
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 827
      Height = 156
      Align = alTop
      TabOrder = 0
      object LabelCurUser: TLabel
        Left = 16
        Top = 9
        Width = 74
        Height = 33
        Caption = #1051#1086#1075#1080#1085
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object eZakazNumber: TEdit
        Left = 16
        Top = 114
        Width = 232
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnKeyPress = eZakazNumberKeyPress
      end
      object Button3: TButton
        Left = 254
        Top = 110
        Width = 113
        Height = 32
        Caption = #1053#1072#1081#1090#1080' '#1079#1072#1082#1072#1079
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = FindOrders
      end
      object DateTimePicker1: TDateTimePicker
        Left = 16
        Top = 83
        Width = 113
        Height = 21
        Date = 41206.000000000000000000
        Time = 41206.000000000000000000
        TabOrder = 2
      end
      object DateTimePicker2: TDateTimePicker
        Left = 135
        Top = 83
        Width = 113
        Height = 21
        Date = 41206.999988425930000000
        Time = 41206.999988425930000000
        TabOrder = 3
      end
      object Button2: TButton
        Left = 373
        Top = 110
        Width = 113
        Height = 32
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1047#1072#1082#1072#1079
        TabOrder = 4
        OnClick = SaveOrder
      end
      object cbZakazChanged: TCheckBox
        Left = 373
        Top = 87
        Width = 129
        Height = 17
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1080#1079#1084#1077#1085#1077#1085'!'
        Enabled = False
        TabOrder = 5
      end
      object Button4: TButton
        Left = 492
        Top = 110
        Width = 113
        Height = 32
        Caption = #1047#1072#1087#1080#1089#1072#1090#1100' '#1041#1088#1072#1082
        TabOrder = 6
        OnClick = SaveRemake
      end
      object btUserChange: TButton
        Left = 16
        Top = 48
        Width = 139
        Height = 25
        Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
        TabOrder = 7
      end
    end
    object sgg: TStringGrid
      Left = 1
      Top = 360
      Width = 827
      Height = 142
      Align = alBottom
      ColCount = 12
      DefaultRowHeight = 22
      Enabled = False
      FixedCols = 0
      RowCount = 2
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
      TabOrder = 1
      OnClick = sgRowSelect
      OnDrawCell = sggDrawCell
      OnMouseMove = sgMouseMove
      ColWidths = (
        47
        37
        46
        55
        54
        57
        52
        55
        45
        64
        64
        64)
    end
    object sgo: TStringGrid
      Left = 1
      Top = 157
      Width = 827
      Height = 198
      Align = alClient
      ColCount = 6
      DefaultRowHeight = 22
      Enabled = False
      RowCount = 2
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
      TabOrder = 2
      OnClick = sgRowSelect
      OnMouseMove = sgMouseMove
      OnMouseUp = sgMouseUp
      OnSelectCell = sgoSelectCell
      ColWidths = (
        64
        110
        95
        64
        64
        64)
    end
  end
  object Panel3: TPanel
    Left = 829
    Top = 0
    Width = 179
    Height = 503
    Align = alRight
    TabOrder = 1
    inline frSpisokManagers: TfrSpisok
      Left = 1
      Top = 1
      Width = 177
      Height = 97
      Align = alTop
      TabOrder = 0
      ExplicitLeft = 1
      ExplicitTop = 1
      ExplicitWidth = 177
      inherited CheckListBox1: TCheckListBox
        Width = 177
        ExplicitWidth = 177
      end
      inherited Panel1: TPanel
        Width = 177
        ExplicitWidth = 177
        inherited Label1: TLabel
          Width = 61
          Caption = #1052#1077#1085#1077#1076#1078#1077#1088#1099
          ExplicitWidth = 61
        end
      end
    end
    inline frSpisokPerformers: TfrSpisok
      Left = 1
      Top = 98
      Width = 177
      Height = 97
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 1
      ExplicitTop = 98
      ExplicitWidth = 177
      inherited CheckListBox1: TCheckListBox
        Width = 177
        ExplicitWidth = 177
      end
      inherited Panel1: TPanel
        Width = 177
        ExplicitWidth = 177
        inherited Label1: TLabel
          Width = 66
          Caption = #1048#1089#1087#1086#1083#1085#1080#1090#1077#1083#1080
          ExplicitWidth = 66
        end
      end
    end
    inline frSpisokBunglers: TfrSpisok
      Left = 1
      Top = 195
      Width = 177
      Height = 97
      Align = alTop
      TabOrder = 2
      ExplicitLeft = 1
      ExplicitTop = 195
      ExplicitWidth = 177
      inherited CheckListBox1: TCheckListBox
        Width = 177
        ExplicitWidth = 177
      end
      inherited Panel1: TPanel
        Width = 177
        ExplicitWidth = 177
        inherited Label1: TLabel
          Width = 57
          Caption = #1041#1088#1072#1082#1086#1076#1077#1083#1099
          ExplicitWidth = 57
        end
      end
    end
    inline frSpisokNotes: TfrSpisok
      Left = 1
      Top = 292
      Width = 177
      Height = 97
      Align = alTop
      TabOrder = 3
      ExplicitLeft = 1
      ExplicitTop = 292
      ExplicitWidth = 177
      inherited CheckListBox1: TCheckListBox
        Width = 177
        OnClick = frSpisokNotesCheckListBox1Click
        ExplicitWidth = 177
      end
      inherited Panel1: TPanel
        Width = 177
        ExplicitWidth = 177
        inherited Label1: TLabel
          Width = 41
          Caption = #1047#1072#1087#1080#1089#1082#1080
          ExplicitWidth = 41
        end
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 389
      Width = 177
      Height = 36
      Align = alTop
      TabOrder = 4
      object Button5: TButton
        Left = 35
        Top = 4
        Width = 113
        Height = 28
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1082#1091
        TabOrder = 0
        OnClick = Button5Click
      end
    end
    object MemoNote: TMemo
      Left = 1
      Top = 425
      Width = 177
      Height = 77
      Align = alClient
      TabOrder = 5
    end
  end
end
