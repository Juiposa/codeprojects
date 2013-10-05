VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5385
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   2520
   LinkTopic       =   "Form1"
   ScaleHeight     =   5385
   ScaleWidth      =   2520
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdSort 
      Caption         =   "sort"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   4320
      Width           =   1935
   End
   Begin VB.PictureBox Picture1 
      Height          =   4095
      Left            =   120
      ScaleHeight     =   4035
      ScaleWidth      =   2235
      TabIndex        =   0
      Top             =   120
      Width           =   2295
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim dwarf(1 To 7) As String

Private Sub cmdSort_Click()
dwarf(1) = "Doc"
dwarf(2) = "Grumpy"
dwarf(3) = "Sleepy"
dwarf(4) = "Happy"
dwarf(5) = "Bashful"
dwarf(6) = "Sneezy"
dwarf(7) = "Dopey"

Call Sorter

For i = 1 To 7
Picture1.Print dwarf(i)
Next i

End Sub

Private Sub Sorter()

Dim x As Integer

Do While x = 0
    Do
        Dim temp As String
        x = 1
        For i = 1 To 6
            If dwarf(i) > dwarf(i + 1) Then
                temp = dwarf(i)
                dwarf(i) = dwarf(i + 1)
                dwarf(i + 1) = temp
                x = 0
            End If
        Next i
    Loop Until x = 1
Loop
End Sub
