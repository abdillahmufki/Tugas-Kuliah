Public Class formmatrix
    Sub bersih()
        Result_1.Text = ""
        Result_2.Text = ""
        Result_3.Text = ""
        Result_4.Text = ""
    End Sub

    Private Sub btnhitung_Click(sender As Object, e As EventArgs) Handles btnhitung.Click
        If matrixA_1.Text = "" Or matrixA_2.Text = "" Or matrixA_3.Text = "" Or matrixA_4.Text = "" Or MatrixB_1.Text = "" Or MatrixB_2.Text = "" Or MatrixB_3.Text = "" Or MatrixB_4.Text = "" Then
            MsgBox("Tolong isi semua value Matriks!")
        Else
            Call bersih()
            Result_1.Text = matrixA_1.Text * MatrixB_1.Text + matrixA_1.Text * MatrixB_2.Text
            Result_2.Text = matrixA_2.Text * MatrixB_1.Text + matrixA_2.Text * MatrixB_2.Text
            Result_3.Text = matrixA_3.Text * MatrixB_3.Text + matrixA_3.Text * MatrixB_4.Text
            Result_4.Text = matrixA_4.Text * MatrixB_3.Text + matrixA_4.Text * MatrixB_4.Text
        End If
    End Sub

    Private Sub btnreset_Click(sender As Object, e As EventArgs) Handles btnreset.Click
        Result_1.Text = ""
        Result_2.Text = ""
        Result_3.Text = ""
        Result_4.Text = ""
        matrixA_1.Text = ""
        matrixA_2.Text = ""
        matrixA_3.Text = ""
        matrixA_4.Text = ""
        MatrixB_1.Text = ""
        MatrixB_2.Text = ""
        MatrixB_3.Text = ""
        MatrixB_4.Text = ""
    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub
End Class