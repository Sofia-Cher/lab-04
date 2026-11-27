# ЛР 5. Полиморфизм — Java

Интерфейсы `Taxable`, `TaxPolicy`; `Comparable<Soldier>`; раннее/позднее связывание;
`instanceof`; конфигурирование; исключения, `finally` и try-with-resources.
Нужна Java 16+ (pattern matching для `instanceof`).

## Сборка и запуск

Linux / macOS:

    mkdir -p out
    javac -encoding UTF-8 -d out *.java
    java -cp out Main

Windows (cmd):

    mkdir out
    javac -encoding UTF-8 -d out *.java
    chcp 65001
    java -Dfile.encoding=UTF-8 -Dstdout.encoding=UTF-8 -cp out Main
