package controller;

import java.lang.Exception;
import view.ConsoleView;

public class Gerenciador
{
    public Gerenciador()
    {

    }

    public void iniciar()
    {
        ConsoleView view = new ConsoleView();
        try
        {
            view.carregar();
        }
        catch (Exception e)
        {
            System.out.println("Impossivel carregar a aplicacao");
        }
    }
}