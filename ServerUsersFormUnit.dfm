object fUsers: TfUsers
  Left = 0
  Top = 0
  Caption = #1057#1087#1080#1089#1086#1082' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
  ClientHeight = 338
  ClientWidth = 529
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 529
    Height = 57
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 631
    object DBNavigator1: TDBNavigator
      Left = 16
      Top = 16
      Width = 240
      Height = 25
      DataSource = MyDataSource1
      TabOrder = 0
    end
  end
  object DBGridUsers: TDBGrid
    Left = 0
    Top = 57
    Width = 529
    Height = 281
    Align = alClient
    DataSource = MyDataSource1
    DrawingStyle = gdsGradient
    Options = [dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'idlogin_table'
        ReadOnly = True
        Title.Caption = 'ID'
        Width = 38
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'login'
        Title.Caption = #1051#1086#1075#1080#1085
        Width = 158
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'role'
        PickList.Strings = (
          #1040#1076#1084#1080#1085
          #1052#1077#1085#1077#1076#1078#1077#1088
          #1054#1087#1077#1088#1072#1090#1086#1088
          #1041#1072#1075#1077#1090#1095#1080#1082
          #1044#1080#1079#1072#1081#1085#1077#1088)
        Title.Caption = #1056#1086#1083#1100
        Width = 103
        Visible = True
      end>
  end
  object MyConnection1: TMyConnection
    Database = 'zp_sboi'
    Options.Charset = 'cp1251'
    Username = 'root'
    Server = 'localhost'
    Connected = True
    LoginPrompt = False
    Left = 288
    Top = 8
  end
  object MyQuery1: TMyQuery
    Connection = MyConnection1
    SQL.Strings = (
      'select * from login_table;')
    Active = True
    Left = 440
    Top = 8
  end
  object MyDataSource1: TMyDataSource
    DataSet = MyQuery1
    Left = 360
    Top = 8
  end
end
