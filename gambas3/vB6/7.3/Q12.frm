VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdButton 
      Caption         =   "Button"
      Height          =   855
      Index           =   1
      Left            =   600
      TabIndex        =   1
      Top             =   240
      Width           =   2535
   End
   Begin VB.CommandButton cmdButton 
      Caption         =   "Button"
      Height          =   855
      Index           =   0
      Left            =   600
      TabIndex        =   0
      Top             =   1320
      Width           =   2535
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim a As Integer

Private Sub cmdButton_Click(Index As Integer)
a = cmdButton(Index).Left
cmdButton(Index).Left = a + 100
End Sub
