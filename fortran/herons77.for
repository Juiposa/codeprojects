  501 FORMAT(3I5)
  601 FORMAT(" A= ",I5,"  B= ",I5,"  C= ",I5,"  AREA= ",F10.2,"SQUARE UNITS")
  602 FORMAT("NORMAL END")
  603 FORMAT("INPUT ERROR OR ZERO VALUE ERROR")
      INTEGER A,B,C
   10 READ(5,501,END=50,ERR=90) A,B,C
      IF(A=0 .OR. B=0 .OR. C=0) GO TO 90
      S = (A + B + C) / 2.0
      AREA = SQRT( S * (S - A) * (S - B) * (S - C))  
      WRITE(6,601) A,B,C,AREA
      GO TO 10
   50 WRITE(6,602)
      STOP
   90 WRITE(6,603)
      STOP
      END
