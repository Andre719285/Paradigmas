/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

class Atleta {
    String nome;
    char sexo;
    double altura;
    double peso;

    // Construtor
    public Atleta(String nome, char sexo, double altura, double peso) {
        this.nome = nome;
        this.sexo = sexo;
        this.altura = altura;
        this.peso = peso;
    }

    // Métodos getters
    public String getNome() {
        return nome;
    }

    public char getSexo() {
        return sexo;
    }

    public double getAltura() {
        return altura;
    }

    public double getPeso() {
        return peso;
    }
}

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US); // Para garantir que use ponto como separador decimal
        Scanner scanner = new Scanner(System.in);

        System.out.print("Qual a quantidade de atletas? ");
        int n = scanner.nextInt();
        scanner.nextLine(); // Limpar o buffer

        // Lista para armazenar os atletas
        ArrayList<Atleta> atletas = new ArrayList<>();

        // Leitura dos dados dos atletas
        for (int i = 0; i < n; i++) {
            System.out.println("Digite os dados do atleta numero " + (i + 1) + ":");

            System.out.print("Nome: ");
            String nome = scanner.nextLine();

            // Validação do sexo
            char sexo;
            while (true) {
                System.out.print("Sexo (M/F): ");
                sexo = scanner.nextLine().toUpperCase().charAt(0);
                if (sexo == 'M' || sexo == 'F') {
                    break;
                }
                System.out.println("Valor invalido! Favor digitar F ou M.");
            }

            // Validação da altura
            double altura;
            while (true) {
                System.out.print("Altura: ");
                altura = scanner.nextDouble();
                if (altura > 0) {
                    break;
                }
                System.out.println("Valor invalido! Favor digitar um valor positivo.");
            }

            // Validação do peso
            double peso;
            while (true) {
                System.out.print("Peso: ");
                peso = scanner.nextDouble();
                if (peso > 0) {
                    break;
                }
                System.out.println("Valor invalido! Favor digitar um valor positivo.");
            }
            scanner.nextLine(); // Limpar o buffer

            // Adiciona o atleta na lista
            atletas.add(new Atleta(nome, sexo, altura, peso));
        }

        // Cálculos para o relatório
        double pesoTotal = 0;
        int homens = 0;
        int mulheres = 0;
        double alturaTotalMulheres = 0;
        Atleta atletaMaisAlto = atletas.get(0);

        for (Atleta atleta : atletas) {
            pesoTotal += atleta.getPeso();

            // Encontrar o atleta mais alto
            if (atleta.getAltura() > atletaMaisAlto.getAltura()) {
                atletaMaisAlto = atleta;
            }

            // Contabilizar homens e mulheres
            if (atleta.getSexo() == 'M') {
                homens++;
            } else if (atleta.getSexo() == 'F') {
                mulheres++;
                alturaTotalMulheres += atleta.getAltura();
            }
        }

        // Cálculos de médias e porcentagens
        double pesoMedio = pesoTotal / n;
        double porcentagemHomens = (homens * 100.0) / n;
        double alturaMediaMulheres = mulheres > 0 ? alturaTotalMulheres / mulheres : 0;

        // Exibição do relatório
        System.out.println("\n### RELATÓRIO ###");
        System.out.printf("Peso médio dos atletas: %.2f%n", pesoMedio);
        System.out.println("Atleta mais alto: " + atletaMaisAlto.getNome());
        System.out.printf("Porcentagem de homens: %.1f %% %n", porcentagemHomens);
        
        if (mulheres > 0) {
            System.out.printf("Altura média das mulheres: %.2f%n", alturaMediaMulheres);
        } else {
            System.out.println("Não há mulheres cadastradas.");
        }

        scanner.close();
    }
}
