VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   10230
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   3615
   LinkTopic       =   "Form1"
   ScaleHeight     =   10230
   ScaleWidth      =   3615
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdScan 
      Caption         =   "Scan for Primes"
      Height          =   615
      Left            =   1200
      TabIndex        =   3
      Top             =   9480
      Width           =   2295
   End
   Begin VB.TextBox txtBound 
      Height          =   735
      Left            =   1200
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   8640
      Width           =   2295
   End
   Begin VB.PictureBox picDisplay 
      Height          =   9495
      Left            =   120
      ScaleHeight     =   9435
      ScaleWidth      =   915
      TabIndex        =   0
      Top             =   600
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "Prime Numbers"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   120
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Upper Bound"
      Height          =   255
      Left            =   1200
      TabIndex        =   2
      Top             =   8400
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'Jeffrey-David Kapp



Dim Number(2 To 150) As Integer, primeStatus(2 To 150) As Boolean, upperBound As Integer, multiple As Integer
Dim LowerBound As Integer


Private Sub cmdScan_Click()

upperBound = txtBound.Text


'will decide if number are prime or not by dividing the numbers continuosly until less than to equal to 1
'if less than one, it is not a multiple, and not eliminated, likewisem if it is one, then it is eliminated


For z = 2 To upperBound
    
    If primeStatus(z) = True Then
    
        'starting with 3
        LowerBound = 3
        
        For x = LowerBound To upperBound
            
            'will only work with varibles that have not been eliminated
            If primeStatus(x) = True Then

            Do While multiple < Number(x)
            multiple = multiple * Number(z)
            Loop
            
                If multiple = Number(x) Then
                    primeStatus(x) = False
                End If
                
                If multiple > Number(x) Then
                    primeStatus(x) = True
                End If
            
        
            End If
           
           
            multiple = 1
            LowerBound = Number(x) + 2
         
         Next x
     
    End If
     
Next z


'updates display


    For y = 2 To upperBound
        If primeStatus(y) = True Then
        picDisplay.Print Number(y)
        End If
    Next y

End Sub

Private Sub Form_Load()

'intialises the two tracking variables

For i = 2 To 150
    Number(i) = i
    primeStatus(i) = True
Next i


multiple = 1

End Sub


