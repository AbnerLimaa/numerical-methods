package view;

import java.io.IOException;
import java.util.Scanner;

import observer.Observador;

public class ConsoleView extends Observador
{
    public void carregar() throws IOException, InterruptedException
    {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Construa uma equacao utilizando os operadores a seguir:");
        exibirPainel();
        int operador = -1;
        do
        {
            operador = scanner.nextInt();
            switch (operador)
            {
                case 1:

            }
        }
        while(operador != 0)
    }

    private void exibirPainel()
    {
        System.out.println("0) fim\n1) +\n2) -\n3) *\n4) /");
        System.out.print("\nf(x) = ");
    }
}