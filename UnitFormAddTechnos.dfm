object FormAddTechnos: TFormAddTechnos
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100'...'
  ClientHeight = 435
  ClientWidth = 1022
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnMouseWheel = FormMouseWheel
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1022
    Height = 435
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 0
    object TabSheet4: TTabSheet
      Caption = #1054#1090#1076#1077#1083#1100#1085#1099#1077' '#1086#1087#1077#1088#1072#1094#1080#1080
      ImageIndex = 3
      object Label4: TLabel
        Left = 520
        Top = 8
        Width = 137
        Height = 13
        Caption = #1058#1077#1093#1085#1086#1083#1086#1075#1080#1095#1077#1089#1082#1080#1077' '#1094#1077#1087#1086#1095#1082#1080':'
      end
      object Label8: TLabel
        Left = 511
        Top = 192
        Width = 192
        Height = 13
        Caption = #1054#1087#1077#1088#1072#1094#1080#1080', '#1082#1086#1090#1086#1088#1099#1077' '#1084#1086#1078#1085#1086' '#1076#1086#1073#1072#1074#1080#1090#1100':'
      end
      object GroupBox1: TGroupBox
        Left = 3
        Top = 3
        Width = 502
        Height = 401
        Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1088#1072#1079#1084#1077#1097#1077#1085#1080#1077#1084' '
        TabOrder = 0
        object sbSingleOperations: TScrollBox
          Left = 2
          Top = 97
          Width = 498
          Height = 302
          Align = alClient
          TabOrder = 0
        end
        object Panel2: TPanel
          Left = 2
          Top = 15
          Width = 498
          Height = 82
          Align = alTop
          TabOrder = 1
          object Label3: TLabel
            Left = 14
            Top = 6
            Width = 89
            Height = 26
            Caption = #1050#1086#1083'-'#1074#1086' '#1086#1087#1077#1088#1072#1094#1080#1081' / '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074':'
            WordWrap = True
          end
          object Label15: TLabel
            Left = 9
            Top = 38
            Width = 23
            Height = 13
            Caption = #1042#1080#1076':'
          end
          object Label16: TLabel
            Left = 90
            Top = 38
            Width = 30
            Height = 13
            Caption = #1062#1074#1077#1090':'
          end
          object Label17: TLabel
            Left = 168
            Top = 38
            Width = 44
            Height = 13
            Caption = #1064#1080#1088#1080#1085#1072':'
          end
          object Label18: TLabel
            Left = 240
            Top = 38
            Width = 40
            Height = 13
            Caption = #1057#1086#1089#1090#1072#1074':'
          end
          object Label19: TLabel
            Left = 319
            Top = 38
            Width = 70
            Height = 13
            Caption = #1055#1086#1074#1077#1088#1093#1085#1086#1089#1090#1100':'
          end
          object spSingleOperationsCount: TAdvSpinEdit
            Left = 108
            Top = 9
            Width = 52
            Height = 22
            AutoFocus = True
            Value = 1
            FloatValue = 1.000000000000000000
            TimeValue = 0.041666666666666660
            HexValue = 0
            IncrementFloat = 0.100000000000000000
            IncrementFloatPage = 1.000000000000000000
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
            MaxValue = 10000
            MinValue = 1
            TabOrder = 0
            Visible = True
            Version = '1.5.3.4'
            OnChange = spSingleOperationsCountChange
          end
          object Button9: TButton
            Left = 403
            Top = 53
            Width = 88
            Height = 25
            Caption = #1054#1095#1080#1089#1090#1080#1090#1100
            TabOrder = 1
            OnClick = Button9Click
          end
          object cbKindPlaceFilter: TComboBox
            Left = 7
            Top = 55
            Width = 77
            Height = 21
            Style = csDropDownList
            TabOrder = 2
            OnChange = cbKindPlaceFilterChange
          end
          object cbColorPlaceFilter: TComboBox
            Left = 87
            Top = 55
            Width = 72
            Height = 21
            Style = csDropDownList
            TabOrder = 3
            OnChange = cbPlaceFilterChange
          end
          object cbWidthPlaceFilter: TComboBox
            Left = 165
            Top = 55
            Width = 66
            Height = 21
            TabOrder = 4
            OnChange = cbPlaceFilterChange
          end
          object cbConsistPlaceFilter: TComboBox
            Left = 237
            Top = 55
            Width = 73
            Height = 21
            Style = csDropDownList
            TabOrder = 5
            OnChange = cbPlaceFilterChange
          end
          object cbSurfacePlaceFilter: TComboBox
            Left = 316
            Top = 55
            Width = 73
            Height = 21
            Style = csDropDownList
            TabOrder = 6
            OnChange = cbPlaceFilterChange
          end
        end
      end
      object chboxOperations: TCheckListBox
        Left = 511
        Top = 211
        Width = 146
        Height = 122
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemHeight = 13
        Items.Strings = (
          #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
          #1042#1099#1073#1086#1088#1082#1072
          #1052#1086#1085#1090#1072#1078#1082#1072
          #1051#1072#1084#1080#1085#1072#1094#1080#1103
          #1053#1072#1082#1072#1090#1082#1072' '#1085#1072' '#1079#1072#1076#1085#1080#1082
          #1056#1077#1079#1082#1072
          #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1083#1102#1074#1077#1088#1089#1086#1074
          #1044#1080#1079#1072#1081#1085
          #1053#1072#1088#1077#1079#1082#1072' '#1073#1072#1075#1077#1090#1072)
        ParentFont = False
        TabOrder = 1
      end
      object GroupBox2: TGroupBox
        Left = 854
        Top = 3
        Width = 155
        Height = 359
        Caption = #1060#1080#1083#1100#1090#1088#1099' '#1087#1086'-'#1091#1084#1086#1083#1095#1072#1085#1080#1102': '
        TabOrder = 2
        object Label5: TLabel
          Left = 11
          Top = 18
          Width = 101
          Height = 13
          Caption = #1052#1086#1085#1090#1072#1078#1085#1072#1103' '#1087#1083#1077#1085#1082#1072':'
        end
        object Label6: TLabel
          Left = 11
          Top = 62
          Width = 122
          Height = 13
          Caption = #1051#1072#1084#1080#1085#1072#1090' '#1087#1086#1089#1083#1077#1076#1091#1102#1097#1080#1081':'
        end
        object Label7: TLabel
          Left = 12
          Top = 119
          Width = 116
          Height = 13
          Caption = #1047#1072#1076#1085#1080#1082' '#1087#1086#1089#1083#1077#1076#1091#1102#1097#1080#1081':'
        end
        object Label9: TLabel
          Left = 12
          Top = 191
          Width = 33
          Height = 13
          Caption = #1041#1072#1075#1077#1090':'
        end
        object eFilterMontaz: TEdit
          Left = 11
          Top = 35
          Width = 135
          Height = 21
          TabOrder = 0
          Text = 'AT-75'
        end
        object eFilterLaminat: TEdit
          Left = 11
          Top = 79
          Width = 134
          Height = 21
          TabOrder = 1
          Text = #1084#1072#1090' konflex'
        end
        object eFilterBacks: TEdit
          Left = 12
          Top = 161
          Width = 134
          Height = 21
          TabOrder = 2
          Text = '5'#1084#1084' kapa line'
        end
        object rgLaminationKind: TRadioGroup
          Left = 16
          Top = 297
          Width = 121
          Height = 54
          Caption = #1042#1080#1076' '#1083#1072#1084#1080#1085#1080#1088#1086#1074#1072#1085#1080#1103' '
          ItemIndex = 1
          Items.Strings = (
            #1061#1086#1083#1086#1076#1085#1086#1077
            #1043#1086#1088#1103#1095#1077#1077)
          TabOrder = 3
        end
        object cbBackType: TComboBox
          Left = 12
          Top = 135
          Width = 53
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 4
          Text = #1087#1077#1085
          OnChange = cbKindPlaceFilterChange
          Items.Strings = (
            #1087#1077#1085
            #1082#1072#1088#1090
            #1087#1083#1072#1089#1090)
        end
        object eFilterBaget: TEdit
          Left = 12
          Top = 234
          Width = 134
          Height = 21
          TabOrder = 5
        end
        object cbBagetType: TComboBox
          Left = 12
          Top = 208
          Width = 53
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 6
          Text = #1087#1083#1072#1089#1090
          OnChange = cbBagetTypeChange
          Items.Strings = (
            #1087#1083#1072#1089#1090
            #1072#1083#1102#1084)
        end
      end
      object lbTechnos: TListBox
        Left = 509
        Top = 24
        Width = 339
        Height = 111
        ItemHeight = 13
        Items.Strings = (
          #1055#1077#1095#1072#1090#1100' ('#1096#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1072#1103')'
          #1055#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
          #1055#1077#1095#1072#1090#1100' ('#1096#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1072#1103') + '#1087#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072
          #1055#1077#1095#1072#1090#1100' ('#1096#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1072#1103') + '#1085#1072#1082#1072#1090#1082#1072' '#1085#1072' '#1079#1072#1076#1085#1080#1082
          #1055#1077#1095#1072#1090#1100' ('#1096#1080#1088#1086#1082#1086#1092#1086#1088#1084#1072#1090#1085#1072#1103') + '#1085#1072#1082#1072#1090#1082#1072' '#1085#1072' '#1079#1072#1076#1085#1080#1082'+ '#1083#1072#1084#1080#1085#1072#1094#1080#1103
          #1051#1072#1084#1080#1085#1072#1094#1080#1103
          #1051#1072#1084#1080#1085#1072#1094#1080#1103' + '#1085#1072#1082#1072#1090#1082#1072' '#1085#1072' '#1079#1072#1076#1085#1080#1082
          #1053#1072#1082#1072#1090#1082#1072' '#1085#1072' '#1079#1072#1076#1085#1080#1082)
        TabOrder = 3
        OnClick = lbTechnosClick
      end
      object btCreate: TButton
        Left = 728
        Top = 288
        Width = 103
        Height = 108
        Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
        TabOrder = 4
        OnClick = btCreateClick
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1057#1091#1074#1077#1085#1080#1088#1082#1072
      object Splitter1: TSplitter
        Left = 425
        Top = 121
        Height = 286
        ExplicitLeft = 302
        ExplicitTop = 49
        ExplicitHeight = 342
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1014
        Height = 121
        Align = alTop
        TabOrder = 0
        object Label2: TLabel
          Left = 511
          Top = 7
          Width = 70
          Height = 39
          Caption = #1050#1086#1083'-'#1074#1086' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074' / '#1094#1074#1077#1090#1086#1074':'
          WordWrap = True
        end
        object Label1: TLabel
          Left = 18
          Top = 7
          Width = 107
          Height = 26
          Caption = #1050#1086#1083'-'#1074#1086' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088' ('#1088#1072#1079#1084#1077#1088#1099' / '#1074#1080#1076#1099'):'
          WordWrap = True
        end
        object Label10: TLabel
          Left = 18
          Top = 69
          Width = 23
          Height = 13
          Caption = #1042#1080#1076':'
        end
        object Label11: TLabel
          Left = 89
          Top = 69
          Width = 30
          Height = 13
          Caption = #1062#1074#1077#1090':'
        end
        object Label12: TLabel
          Left = 167
          Top = 69
          Width = 39
          Height = 13
          Caption = #1056#1072#1079#1084#1077#1088':'
        end
        object Label13: TLabel
          Left = 437
          Top = 67
          Width = 81
          Height = 13
          Caption = #1060#1086#1088#1084#1072#1090' '#1087#1077#1095#1072#1090#1080':'
        end
        object Label14: TLabel
          Left = 529
          Top = 67
          Width = 116
          Height = 13
          Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1086#1088#1086#1085' '#1087#1077#1095#1072#1090#1080':'
        end
        object spTshirtColorCount: TAdvSpinEdit
          Left = 587
          Top = 12
          Width = 52
          Height = 22
          AutoFocus = True
          Value = 1
          FloatValue = 1.000000000000000000
          TimeValue = 0.041666666666666660
          HexValue = 0
          IncrementFloat = 0.100000000000000000
          IncrementFloatPage = 1.000000000000000000
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          MaxValue = 10000
          MinValue = 1
          TabOrder = 0
          Visible = True
          Version = '1.5.3.4'
          OnChange = spTshirtColorCountChange
        end
        object spTshirtNomCount: TAdvSpinEdit
          Left = 137
          Top = 12
          Width = 52
          Height = 22
          AutoFocus = True
          Value = 1
          FloatValue = 1.000000000000000000
          TimeValue = 0.041666666666666660
          HexValue = 0
          CheckMinValue = True
          IncrementFloat = 0.100000000000000000
          IncrementFloatPage = 1.000000000000000000
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          MaxValue = 10000
          MinValue = 1
          TabOrder = 1
          Visible = True
          Version = '1.5.3.4'
          OnChange = spTshirtNomCountChange
        end
        object btTshirtCreate: TButton
          Left = 680
          Top = 5
          Width = 170
          Height = 52
          Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
          TabOrder = 2
          OnClick = btTshirtCreateClick
        end
        object spTshirtsFullCount: TAdvSpinEdit
          Left = 201
          Top = 12
          Width = 57
          Height = 22
          Value = 0
          DateValue = 41985.437725173610000000
          HexValue = 0
          Color = clSilver
          Enabled = False
          IncrementFloat = 0.100000000000000000
          IncrementFloatPage = 1.000000000000000000
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          TabOrder = 3
          Visible = True
          Version = '1.5.3.4'
        end
        object cbTehnosSuvenir: TComboBox
          Left = 18
          Top = 40
          Width = 199
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 4
          Text = #1060#1091#1090#1073#1086#1083#1082#1072' ('#1089#1091#1073#1083#1080#1084#1072#1094#1080#1103')'
          OnChange = cbTehnosSuvenirChange
          Items.Strings = (
            #1060#1091#1090#1073#1086#1083#1082#1072' ('#1089#1091#1073#1083#1080#1084#1072#1094#1080#1103')'
            #1060#1091#1090#1073#1086#1083#1082#1072' ('#1087#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072')'
            #1060#1091#1090#1073#1086#1083#1082#1072' ('#1087#1077#1095#1072#1090#1100' + '#1087#1083#1086#1090#1090#1077#1088#1085#1072#1103' '#1088#1077#1079#1082#1072')'
            #1058#1072#1073#1083#1080#1095#1082#1072' ('#1084#1077#1090#1072#1083#1083')'
            #1050#1088#1091#1078#1082#1072' ('#1089#1091#1073#1083#1080#1084#1072#1094#1080#1103')'
            #1055#1072#1079#1083' ('#1089#1091#1073#1083#1080#1084#1072#1094#1080#1103')')
        end
        object cbFormatFilter: TComboBox
          Left = 437
          Top = 86
          Width = 81
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 5
          Text = 'A5'
          OnChange = cbFormatFilterChange
          Items.Strings = (
            'A5'
            'A4'
            'A3')
        end
        object cbSideCount: TComboBox
          Left = 528
          Top = 86
          Width = 117
          Height = 21
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 6
          Text = #1054#1076#1085#1072' '#1089#1090#1086#1088#1086#1085#1072
          OnChange = cbSideCountChange
          Items.Strings = (
            #1054#1076#1085#1072' '#1089#1090#1086#1088#1086#1085#1072
            #1044#1074#1077' '#1089#1090#1086#1088#1086#1085#1099)
        end
        object cbMaterialKindFilter: TComboBox
          Left = 18
          Top = 86
          Width = 63
          Height = 21
          Style = csDropDownList
          TabOrder = 7
          OnChange = cbMaterialFilterChange
        end
        object cbMaterialColorFilter: TComboBox
          Left = 89
          Top = 86
          Width = 72
          Height = 21
          ItemIndex = 0
          TabOrder = 8
          Text = #1073#1077#1083#1099
          OnChange = cbMaterialFilterChange
          Items.Strings = (
            #1073#1077#1083#1099
            #1095#1077#1088#1085
            #1086#1088#1072#1085#1078
            #1089#1080#1085
            #1082#1088#1072#1089
            #1079#1077#1083
            #1087#1091#1088#1087
            #1075#1086#1083#1091#1073)
        end
        object cbMaterialSizeFilter: TComboBox
          Left = 167
          Top = 86
          Width = 66
          Height = 21
          TabOrder = 9
          OnChange = cbMaterialSizeFilterChange
        end
        object Button12: TButton
          Left = 280
          Top = 84
          Width = 115
          Height = 25
          Caption = #1054#1095#1080#1089#1090#1080#1090#1100
          TabOrder = 10
          OnClick = Button12Click
        end
      end
      object sbMaterials: TScrollBox
        Left = 0
        Top = 121
        Width = 425
        Height = 286
        Align = alLeft
        TabOrder = 1
      end
      object sbOperations: TScrollBox
        Left = 428
        Top = 121
        Width = 586
        Height = 286
        Align = alClient
        TabOrder = 2
      end
    end
  end
end
