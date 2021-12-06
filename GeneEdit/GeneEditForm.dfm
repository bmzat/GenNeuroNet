object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'GenomeEdit'
  ClientHeight = 675
  ClientWidth = 1100
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 128
    Top = 19
    Width = 24
    Height = 13
    Caption = 'From'
  end
  object Label2: TLabel
    Left = 128
    Top = 46
    Width = 12
    Height = 13
    Caption = 'To'
  end
  object Label3: TLabel
    Left = 128
    Top = 78
    Width = 26
    Height = 13
    Caption = 'Value'
  end
  object Label4: TLabel
    Left = 128
    Top = 124
    Width = 46
    Height = 13
    Caption = 'Reserved'
  end
  object Axon: TCheckBox
    Left = 8
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Axon'
    TabOrder = 0
  end
  object FromInput: TCheckBox
    Left = 8
    Top = 31
    Width = 97
    Height = 17
    Caption = 'FromInput'
    TabOrder = 1
  end
  object ToOutput: TCheckBox
    Left = 8
    Top = 54
    Width = 97
    Height = 17
    Caption = 'ToOutput'
    TabOrder = 2
  end
  object IsFeature: TCheckBox
    Left = 8
    Top = 77
    Width = 97
    Height = 17
    Caption = 'IsFeature'
    TabOrder = 3
  end
  object IsParam: TCheckBox
    Left = 8
    Top = 100
    Width = 97
    Height = 17
    Caption = 'IsParam'
    TabOrder = 4
  end
  object IsValue: TCheckBox
    Left = 8
    Top = 123
    Width = 97
    Height = 17
    Caption = 'IsValue'
    TabOrder = 5
  end
  object From: TEdit
    Left = 176
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object To: TEdit
    Left = 176
    Top = 43
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Reserved1: TCheckBox
    Left = 8
    Top = 146
    Width = 97
    Height = 17
    Caption = 'Reserved1'
    TabOrder = 8
  end
  object Reserved2: TCheckBox
    Left = 8
    Top = 169
    Width = 97
    Height = 17
    Caption = 'Reserved2'
    TabOrder = 9
  end
  object Value: TEdit
    Left = 176
    Top = 75
    Width = 121
    Height = 21
    TabOrder = 10
    Text = '0,0'
  end
  object Reserved: TEdit
    Left = 180
    Top = 121
    Width = 117
    Height = 19
    TabOrder = 11
    Text = '0'
  end
  object Button1: TButton
    Left = 358
    Top = 27
    Width = 75
    Height = 25
    Caption = 'Random'
    TabOrder = 12
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 254
    Top = 169
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 13
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 240
    Width = 801
    Height = 329
    Lines.Strings = (
      'Memo1')
    TabOrder = 14
  end
  object ReverseInput: TEdit
    Left = 776
    Top = 29
    Width = 121
    Height = 21
    TabOrder = 15
    Text = 'ReverseInput'
  end
  object Button3: TButton
    Left = 912
    Top = 27
    Width = 75
    Height = 25
    Caption = 'Reverse'
    TabOrder = 16
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 358
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Cook'
    TabOrder = 17
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 216
    Top = 200
    Width = 113
    Height = 25
    Caption = 'Compile C-String'
    TabOrder = 18
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 344
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 19
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 120
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Compile HEX'
    TabOrder = 20
    OnClick = Button7Click
  end
end
