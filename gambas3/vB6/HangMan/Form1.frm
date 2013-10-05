VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   8505
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5400
   LinkTopic       =   "Form1"
   ScaleHeight     =   8505
   ScaleWidth      =   5400
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtMessage 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   120
      TabIndex        =   21
      Top             =   7560
      Width           =   5175
   End
   Begin VB.Timer tmrControl 
      Interval        =   100
      Left            =   3360
      Top             =   240
   End
   Begin VB.CommandButton cmdGuessLetter 
      Caption         =   "Guess Letter"
      Height          =   495
      Left            =   3000
      TabIndex        =   20
      Top             =   6000
      Width           =   1335
   End
   Begin VB.TextBox txtGuessLetter 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   3600
      TabIndex        =   15
      Top             =   4680
      Width           =   735
   End
   Begin VB.PictureBox picOutput 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   6015
      Left            =   120
      ScaleHeight     =   5955
      ScaleWidth      =   915
      TabIndex        =   14
      Top             =   480
      Width           =   975
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "GTFO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   120
      TabIndex        =   13
      Top             =   6600
      Width           =   5175
   End
   Begin VB.CommandButton cmdRestart 
      Caption         =   "Restart"
      Height          =   495
      Left            =   1200
      TabIndex        =   12
      Top             =   5400
      Width           =   3135
   End
   Begin VB.PictureBox picLetters 
      Height          =   6015
      Left            =   4440
      ScaleHeight     =   5955
      ScaleWidth      =   795
      TabIndex        =   11
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton cmdGuessWord 
      Caption         =   "&Guess Word"
      Height          =   495
      Left            =   1200
      TabIndex        =   10
      Top             =   6000
      Width           =   1695
   End
   Begin VB.TextBox txtGuessWord 
      Height          =   615
      Left            =   1200
      TabIndex        =   9
      Text            =   "Guess the word here."
      Top             =   4680
      Width           =   2295
   End
   Begin VB.PictureBox Picture1 
      Height          =   135
      Index           =   8
      Left            =   2640
      ScaleHeight     =   75
      ScaleWidth      =   315
      TabIndex        =   8
      Top             =   600
      Width           =   375
   End
   Begin VB.PictureBox Picture1 
      Height          =   135
      Index           =   7
      Left            =   2880
      ScaleHeight     =   75
      ScaleWidth      =   75
      TabIndex        =   7
      Top             =   360
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   135
      Index           =   6
      Left            =   2640
      ScaleHeight     =   75
      ScaleWidth      =   75
      TabIndex        =   6
      Top             =   360
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   1335
      Index           =   5
      Left            =   3000
      ScaleHeight     =   1275
      ScaleWidth      =   75
      TabIndex        =   5
      Top             =   3120
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   1335
      Index           =   4
      Left            =   2520
      ScaleHeight     =   1275
      ScaleWidth      =   75
      TabIndex        =   4
      Top             =   3120
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   135
      Index           =   3
      Left            =   2880
      ScaleHeight     =   75
      ScaleWidth      =   1155
      TabIndex        =   3
      Top             =   1440
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   135
      Index           =   2
      Left            =   1560
      ScaleHeight     =   75
      ScaleWidth      =   1155
      TabIndex        =   2
      Top             =   1440
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   2295
      Index           =   1
      Left            =   2760
      ScaleHeight     =   2235
      ScaleWidth      =   75
      TabIndex        =   1
      Top             =   840
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   615
      Index           =   0
      Left            =   2520
      ScaleHeight     =   555
      ScaleWidth      =   555
      TabIndex        =   0
      Top             =   240
      Width           =   615
   End
   Begin VB.Label Label4 
      Caption         =   "Guess Letter"
      Height          =   255
      Left            =   3600
      TabIndex        =   19
      Top             =   4440
      Width           =   615
   End
   Begin VB.Label Label3 
      Caption         =   "Guess Word"
      Height          =   255
      Left            =   1200
      TabIndex        =   18
      Top             =   4440
      Width           =   1815
   End
   Begin VB.Label Label2 
      Caption         =   "Letters Guessed"
      Height          =   375
      Left            =   4440
      TabIndex        =   17
      Top             =   0
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "Word"
      Height          =   255
      Left            =   120
      TabIndex        =   16
      Top             =   120
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim wordLength As Integer, guessLetter As String
Dim guessWord As String, display As String, word As String
Dim gameEnd As Integer, indvLetters(1 To 15) As String
Dim displayLetters(1 To 15) As String, hangman As Integer
Dim equal As Integer, notEqual As Integer, guessed(1 To 15) As Integer


Private Sub cmdExit_Click()
'simple exit button to exit game
End
End Sub


Private Sub cmdGuessLetter_Click()

'handles checking if the letter guess is in the word

'assigns guessed letter to the working variable, and clears
'output area
guessLetter = txtGuessLetter.Text
picOutput.Cls
Dim i As Integer

'this is the FOR that checks for equalities in the letter guess and
'the letters in the word
For i = 1 To wordLength
    
    If guessLetter = indvLetters(i) Then
        
        If guessed(i) = 1 Then
        txtMessage.Text = "You've already guessed that!"
        End If
        
        If guessed(i) = 0 Then
        displayLetters(i) = indvLetters(i)
        equal = equal + 1
        guessed(i) = 1
        End If
        
        If guessLetter > indvLetters(i) Or guessLetter < indvLetters(i) Then
        notEqual = notEqual + 1
        End If
        
    End If
    
    picOutput.Print displayLetters(i)
    
Next i
    
'if the player guesses the whole word with indv letters, it will
'trigger this to state a win
If equal = wordLength Then
gameEnd = 0
txtMessage.Text = "YOU WIN!!!"
End If

'if the letter guessed is not in the word, it will trigger this
'to highlight the next part of the hangman, and print the guessed letter
'in the output box.
If notEqual = wordLength Then
    picLetters.Print guessLetter
    Picture1(hangman).BackColor = vbBlack
    hangman = hangman + 1
End If

notEqual = 0

End Sub

Private Sub cmdGuessWord_Click()
'if the player chooses to guess the whole word, this
'procedure will check for correctness

guessWord = txtGuessWord.Text

If guessWord = word Then
    txtMessage.Text = "You win!"
    picOutput.Cls
    Dim i As Integer
    For i = 1 To wordLength
    picOutput.Print indvLetters(i)
    Next i
    endGame = 0
    Else
    txtMessage.Text = "Nope!"
End If

End Sub

Private Sub cmdRestart_Click()

'refreshes all needed values to constitute a restart or start
gameEnd = 1
cmdRestart.Caption = "Restart"
picOutput.Cls
picLetters.Cls
txtGuessWord.Text = "Guess the word here."
hangman = 0
equal = 0
notEqual = 0

'adds guess lines
wordLength = Len(word)
    Dim i As Integer
    
    'assigns values to the variable that will be displayed.
    
    For i = 1 To wordLength
        displayLetters(i) = "_"
    Next i
    
    'sets display
    
    For i = 1 To wordLength
        picOutput.Print displayLetters(i)
    Next i

    'assigns each letter in the word to a varible to
    'array invdLetters()
    
    For i = 1 To wordLength
        indvLetters(i) = Mid(word, i, 1)
    Next i

    'refresh the hangman
 
    For i = 0 To 8
        Picture1(i).BackColor = vbWhite
    Next i

    'refreshes if letters have been guessed or not
    
    For i = 1 To 15
        guessed(i) = 0
    Next i
End Sub

Private Sub Form_Load()

'word selection

'doesn't work for no dicernable reason
'Open "words.txt" For Input As #1


word = "cervix"
End Sub

Private Sub tmrControl_Timer()

'checks if the game is going and refreshs based on that
If gameEnd = 0 Then
    cmdRestart.Caption = "Start"
End If


'handles game loss
If hangman = 8 Then
    gameEnd = 0
    txtMessage.Text = "YOU LOSE!!!!"
End If


End Sub
