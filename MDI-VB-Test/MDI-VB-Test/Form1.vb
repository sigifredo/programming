Public Class MDIForm

    Private Sub NuevoToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles NuevoToolStripMenuItem.Click
        Dim NewMDIChild As New Form2()

        NewMDIChild.MdiParent = Me

        NewMDIChild.Show()
    End Sub

End Class
