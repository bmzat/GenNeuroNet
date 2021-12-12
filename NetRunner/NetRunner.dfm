object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 765
  ClientWidth = 1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object InputGrid: TStringGrid
    Left = 8
    Top = 179
    Width = 201
    Height = 561
    ColCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 215
    Top = 179
    Width = 417
    Height = 561
    ColCount = 3
    TabOrder = 1
    ColWidths = (
      64
      93
      64)
  end
  object StringGrid2: TStringGrid
    Left = 638
    Top = 179
    Width = 185
    Height = 561
    ColCount = 2
    FixedCols = 0
    TabOrder = 2
  end
  object HexCodeEdit: TEdit
    Left = 8
    Top = 8
    Width = 937
    Height = 21
    TabOrder = 3
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 746
    Width = 1077
    Height = 19
    Panels = <
      item
        Text = 'Inputs: 0'
        Width = 80
      end
      item
        Text = 'Neurons: 0'
        Width = 80
      end
      item
        Text = 'Outputs: 0'
        Width = 80
      end
      item
        Text = 'Synthese N/A'
        Width = 80
      end
      item
        Text = 'Axone N/A'
        Width = 80
      end
      item
        Text = 'Step XXXYYYZZZ'
        Width = 150
      end
      item
        Text = 'Started fresh'
        Width = 300
      end>
  end
  object Memo1: TMemo
    Left = 852
    Top = 179
    Width = 217
    Height = 561
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object SyntheseButton: TButton
    Left = 951
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Synthese'
    TabOrder = 6
  end
  object NumInputs: TTrackBar
    Left = 89
    Top = 35
    Width = 961
    Height = 45
    Max = 255
    Position = 10
    TabOrder = 7
  end
  object NumNeurons: TTrackBar
    Left = 89
    Top = 74
    Width = 961
    Height = 45
    Max = 255
    Position = 10
    TabOrder = 8
  end
  object NumOutputs: TTrackBar
    Left = 89
    Top = 114
    Width = 961
    Height = 45
    Max = 255
    Position = 10
    TabOrder = 9
  end
  object Button1: TButton
    Left = 8
    Top = 74
    Width = 75
    Height = 25
    Caption = 'Prepare'
    TabOrder = 10
  end
end
