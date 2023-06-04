# BINGEN

* [English](./README.md)

BINGEN é uma ferramenta simples para gerar arquivos binários preenchidos com 0xFF, já que este é o valor padrão para memórias flash apagadas.	

## Como usar

```
$ bingen <output> <size>
```
    argumentos:
        output: nome do arquivo de saída
        size: tamanho em bytes do arquivo de saída

## Compilando

```
$ make
$ sudo make install
```