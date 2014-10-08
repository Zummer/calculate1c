inherited frFirstOperationPrint: TfrFirstOperationPrint
  Width = 829
  inherited BasePanel: TPanel
    Width = 829
    object PrintDensity: TAdvTrackBar [12]
      Left = 543
      Top = 66
      Width = 123
      Height = 24
      BorderColor = clNone
      BorderColorDisabled = clNone
      Buttons.BorderColor = 9262895
      Buttons.BorderColorHot = 10079963
      Buttons.BorderColorDown = 4548219
      Buttons.Color = 15653832
      Buttons.ColorTo = 16178633
      Buttons.ColorHot = 15465983
      Buttons.ColorHotTo = 11332863
      Buttons.ColorDown = 7778289
      Buttons.ColorDownTo = 4296947
      Buttons.ColorMirror = 15586496
      Buttons.ColorMirrorTo = 16245200
      Buttons.ColorMirrorHot = 5888767
      Buttons.ColorMirrorHotTo = 10807807
      Buttons.ColorMirrorDown = 946929
      Buttons.ColorMirrorDownTo = 5021693
      Buttons.GradientMirror = ggVertical
      ColorTo = clNone
      ColorDisabled = clNone
      ColorDisabledTo = clNone
      Direction = gdHorizontal
      Color = clNone
      Position = 5
      Slider.BorderColor = 12752500
      Slider.BorderColorDisabled = clBlack
      Slider.Color = clWhite
      Slider.ColorTo = clBlack
      Slider.ColorDisabled = clBlack
      Slider.ColorDisabledTo = clBlack
      Slider.ColorCompleted = clNone
      Slider.ColorCompletedTo = clNone
      Slider.ColorCompletedDisabled = clNone
      Slider.ColorCompletedDisabledTo = clNone
      Slider.Direction = gdHorizontal
      TabOrder = 6
      Thumb.BorderColor = 10317632
      Thumb.BorderColorHot = 10079963
      Thumb.BorderColorDown = 4548219
      Thumb.BorderColorDisabled = clBlack
      Thumb.Color = 15653832
      Thumb.ColorTo = 16178633
      Thumb.ColorDown = 7778289
      Thumb.ColorDownTo = 4296947
      Thumb.ColorHot = 15465983
      Thumb.ColorHotTo = 11332863
      Thumb.ColorDisabled = clBlack
      Thumb.ColorDisabledTo = clBlack
      Thumb.ColorMirror = 15586496
      Thumb.ColorMirrorTo = 16245200
      Thumb.ColorMirrorHot = 5888767
      Thumb.ColorMirrorHotTo = 10807807
      Thumb.ColorMirrorDown = 946929
      Thumb.ColorMirrorDownTo = 5021693
      Thumb.ColorMirrorDisabled = clBlack
      Thumb.ColorMirrorDisabledTo = clBlack
      Thumb.Gradient = ggVertical
      Thumb.GradientMirror = ggRadial
      Thumb.Shape = tsPointer
      TickMark.Color = clBlack
      TickMark.ColorDisabled = clBlack
      TickMark.Font.Charset = DEFAULT_CHARSET
      TickMark.Font.Color = clWindowText
      TickMark.Font.Height = -11
      TickMark.Font.Name = 'Tahoma'
      TickMark.Font.Style = []
      TrackHint = False
      TrackLabel.Font.Charset = DEFAULT_CHARSET
      TrackLabel.Font.Color = clWindowText
      TrackLabel.Font.Height = -11
      TrackLabel.Font.Name = 'Tahoma'
      TrackLabel.Font.Style = []
      TrackLabel.Format = 'Pos: %d'
      Version = '1.6.5.0'
      Visible = False
    end
    inherited cbHalfs: TComboBox
      Left = 742
      Top = 56
      ExplicitLeft = 742
      ExplicitTop = 56
    end
    inherited chkEveryDetailHasOwnMaterial: TCheckBox
      TabOrder = 9
    end
  end
  inherited pnlSelect: TPanel
    Width = 829
    inherited lbCount: TLabel
      Left = 581
      Top = 9
      ExplicitLeft = 581
      ExplicitTop = 9
    end
    inherited spDetailsCount: TAdvSpinEdit
      Left = 293
      Top = 5
      ExplicitLeft = 293
      ExplicitTop = 5
    end
    object chbFotoPrint: TCheckBox
      Left = 461
      Top = 7
      Width = 92
      Height = 17
      Caption = #1060#1086#1090#1086#1087#1077#1095#1072#1090#1100
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnClick = chbFotoPrintClick
    end
  end
  inherited sbForMatFrame: TScrollBox
    Width = 829
  end
end
