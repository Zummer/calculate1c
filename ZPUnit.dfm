object fZP: TfZP
  Left = 0
  Top = 0
  Caption = #1052#1086#1103' '#1079#1072#1088#1072#1073#1086#1090#1085#1072#1103' '#1087#1083#1072#1090#1072
  ClientHeight = 445
  ClientWidth = 868
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 868
    Height = 169
    Align = alTop
    TabOrder = 0
    object Label3: TLabel
      Left = 225
      Top = 150
      Width = 151
      Height = 13
      Caption = #1047#1072#1082#1072#1079#1099' '#1085#1077' '#1087#1086#1087#1072#1074#1096#1080#1077' '#1074' '#1086#1090#1095#1077#1090':'
    end
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
    object Label1: TLabel
      Left = 225
      Top = 132
      Width = 546
      Height = 16
      Caption = 
        #1062#1080#1092#1088#1099' '#1074' '#1088#1072#1089#1095#1077#1090#1077' '#1085#1077' '#1103#1074#1083#1103#1102#1090#1089#1103' '#1086#1082#1086#1085#1095#1072#1090#1077#1083#1100#1085#1099#1084#1080', '#1089#1080#1089#1090#1077#1084#1072' '#1047#1055' '#1077#1097#1077' '#1085#1072#1089#1090#1088 +
        #1072#1080#1074#1072#1077#1090#1089#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 13
      Top = 58
      Width = 139
      Height = 25
      Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
      TabOrder = 0
    end
    object Button2: TButton
      Left = 13
      Top = 117
      Width = 124
      Height = 31
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      TabOrder = 1
      OnClick = UpdateData
    end
    object DateTimePicker1: TDateTimePicker
      Left = 412
      Top = 41
      Width = 113
      Height = 21
      Date = 41206.000000000000000000
      Time = 41206.000000000000000000
      Enabled = False
      TabOrder = 2
      OnChange = DateTimePickerChange
    end
    object DateTimePicker2: TDateTimePicker
      Left = 531
      Top = 41
      Width = 113
      Height = 21
      Date = 41206.999988425930000000
      Time = 41206.999988425930000000
      Enabled = False
      TabOrder = 3
      OnChange = DateTimePickerChange
    end
    object cbUsers: TComboBox
      Left = 499
      Top = 14
      Width = 145
      Height = 21
      TabOrder = 4
      OnSelect = cbUsersSelect
    end
    object GroupBox1: TGroupBox
      Left = 672
      Top = 9
      Width = 113
      Height = 38
      Caption = #1057#1077#1075#1086#1076#1085#1103
      TabOrder = 5
      object LabelDay: TLabel
        Left = 16
        Top = 17
        Width = 26
        Height = 13
        Caption = #1044#1077#1085#1100
      end
      object LabelMonth: TLabel
        Left = 48
        Top = 17
        Width = 31
        Height = 13
        Caption = #1052#1077#1089#1103#1094
      end
      object LabelYear: TLabel
        Left = 75
        Top = 17
        Width = 19
        Height = 13
        Caption = #1043#1086#1076
      end
    end
    object cbMonth: TComboBox
      Left = 412
      Top = 88
      Width = 125
      Height = 21
      DropDownCount = 12
      ItemIndex = 0
      TabOrder = 6
      Text = #1071#1085#1074#1072#1088#1100
      OnSelect = PeriodSelect
      Items.Strings = (
        #1071#1085#1074#1072#1088#1100
        #1060#1077#1074#1088#1072#1083#1100
        #1052#1072#1088#1090
        #1040#1087#1088#1077#1083#1100
        #1052#1072#1081
        #1048#1102#1085#1100
        #1048#1102#1083#1100
        #1040#1074#1075#1091#1089#1090
        #1057#1077#1085#1090#1103#1073#1088#1100
        #1054#1082#1090#1103#1073#1088#1100
        #1053#1086#1103#1073#1088#1100
        #1044#1077#1082#1072#1073#1088#1100)
    end
    object spYear: TAdvSpinEdit
      Left = 552
      Top = 88
      Width = 49
      Height = 22
      Value = 2013
      FloatValue = 2013.000000000000000000
      HexValue = 19
      IncrementFloat = 0.100000000000000000
      IncrementFloatPage = 1.000000000000000000
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      TabOrder = 7
      Visible = True
      Version = '1.5.3.4'
      OnUpClick = PeriodSelect
      OnDownClick = PeriodSelect
    end
    object Button3: TButton
      Left = 672
      Top = 80
      Width = 113
      Height = 30
      Caption = #1053#1086#1074#1072#1103#1042#1077#1076#1086#1084#1086#1089#1090#1100
      TabOrder = 8
      OnClick = Button3Click
    end
  end
  object ValueListEditor1: TValueListEditor
    Left = 0
    Top = 169
    Width = 225
    Height = 276
    Align = alLeft
    FixedCols = 1
    Strings.Strings = (
      #1050#1086#1083'-'#1074#1086' '#1088#1072#1073#1086#1095#1080#1093' '#1076#1085#1077#1081'='
      #1054#1082#1083#1072#1076'='
      #1041#1086#1085#1091#1089' '#1084#1077#1085#1077#1076#1078#1077#1088#1072'='
      #1041#1086#1085#1091#1089' '#1080#1089#1087#1086#1083#1085#1080#1090#1077#1083#1103'='
      #1053#1072#1095#1080#1089#1083#1077#1085#1086'='
      #1059#1076#1077#1088#1078#1072#1085#1086'='
      #1047#1072#1088#1087#1083#1072#1090#1072'='
      #1054#1090#1087#1091#1089#1082#1085#1099#1077'='
      #1053#1077' '#1089#1076#1072#1085#1099' '#1076#1086#1082'-'#1090#1099'='
      #1057#1091#1084#1084#1072' '#1082' '#1074#1099#1076#1072#1095#1077'='
      #1042#1099#1076#1072#1085#1086'='
      #1054#1089#1090#1072#1090#1086#1082'=')
    TabOrder = 1
    TitleCaptions.Strings = (
      #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      #1057#1091#1084#1084#1072', '#1088#1091#1073'.')
    ColWidths = (
      127
      92)
  end
  object PageControl1: TPageControl
    Left = 225
    Top = 169
    Width = 643
    Height = 276
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 2
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 635
        Height = 248
        Align = alClient
        ColCount = 3
        DefaultColWidth = 100
        DefaultRowHeight = 18
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
        OnMouseMove = StringGrid1MouseMove
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
    object TabSheet3: TTabSheet
      Caption = 'TabSheet3'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
    object TabSheet4: TTabSheet
      Caption = 'TabSheet4'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
    end
  end
end
