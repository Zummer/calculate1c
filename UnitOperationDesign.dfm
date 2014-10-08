inherited frOperationDesign: TfrOperationDesign
  Height = 256
  ExplicitHeight = 256
  inherited BasePanel: TPanel
    Height = 226
    ExplicitHeight = 226
    inherited cbHalfs: TComboBox
      TabOrder = 2
    end
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 449
      Height = 224
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 1
      OnDrawTab = PageControl1DrawTab
      object TabSheet1: TTabSheet
        Caption = #1060#1086#1090#1086' '#1085#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object sg1: TStringGrid
          Left = 0
          Top = 0
          Width = 828
          Height = 196
          Align = alClient
          ColCount = 4
          DefaultColWidth = 100
          DefaultRowHeight = 20
          FixedCols = 3
          TabOrder = 0
          OnDrawCell = sgDrawCell
          OnMouseEnter = sgMouseEnter
          OnMouseMove = sgMouseMove
        end
      end
      object TabSheet2: TTabSheet
        Caption = #1044#1080#1079#1072#1081#1085
        ImageIndex = 1
        object sg2: TStringGrid
          Left = 0
          Top = 0
          Width = 441
          Height = 196
          Align = alClient
          ColCount = 4
          DefaultColWidth = 100
          DefaultRowHeight = 20
          FixedCols = 3
          TabOrder = 0
          OnDrawCell = sgDrawCell
          OnMouseEnter = sgMouseEnter
          OnMouseMove = sgMouseMove
        end
      end
      object TabSheet3: TTabSheet
        Caption = #1056#1077#1090#1091#1096#1100
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object sg3: TStringGrid
          Left = 0
          Top = 0
          Width = 828
          Height = 196
          Align = alClient
          ColCount = 4
          DefaultColWidth = 100
          DefaultRowHeight = 20
          FixedCols = 3
          TabOrder = 0
          OnDrawCell = sgDrawCell
          OnMouseEnter = sgMouseEnter
          OnMouseMove = sgMouseMove
        end
      end
      object TabSheet4: TTabSheet
        Caption = #1057#1082#1072#1085#1080#1088#1086#1074#1072#1085#1080#1077
        ImageIndex = 3
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object sg4: TStringGrid
          Left = 0
          Top = 0
          Width = 828
          Height = 196
          Align = alClient
          ColCount = 4
          DefaultColWidth = 100
          DefaultRowHeight = 20
          FixedCols = 3
          TabOrder = 0
          OnDrawCell = sgDrawCell
          OnMouseEnter = sgMouseEnter
          OnMouseMove = sgMouseMove
          RowHeights = (
            20
            20
            20
            20
            20)
        end
      end
      object TabSheet5: TTabSheet
        Caption = #1055#1086#1076#1075#1086#1090#1086#1074#1082#1072
        ImageIndex = 4
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object sg5: TStringGrid
          Left = 0
          Top = 0
          Width = 828
          Height = 196
          Align = alClient
          ColCount = 4
          DefaultColWidth = 100
          DefaultRowHeight = 20
          FixedCols = 3
          TabOrder = 0
          OnDrawCell = sgDrawCell
          OnMouseEnter = sgMouseEnter
          OnMouseMove = sgMouseMove
        end
      end
    end
  end
end
