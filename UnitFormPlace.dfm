object FormPlace: TFormPlace
  Left = 0
  Top = 0
  BorderIcons = [biMinimize, biMaximize]
  Caption = #1056#1072#1079#1084#1077#1097#1077#1085#1080#1077' '#1076#1077#1090#1072#1083#1077#1081' '#1080#1079#1076#1077#1083#1080#1103
  ClientHeight = 322
  ClientWidth = 347
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object sbForPlace: TScrollBox
    Left = 0
    Top = 0
    Width = 347
    Height = 322
    Align = alClient
    Color = clSilver
    ParentColor = False
    TabOrder = 0
    object GuidLine: TShape
      Left = 327
      Top = -2
      Width = 5
      Height = 100
      Brush.Color = clRed
      Pen.Color = clRed
      OnMouseDown = GuidLineMouseDown
      OnMouseMove = GuidLineMouseMove
      OnMouseUp = GuidLineMouseUp
    end
  end
end
