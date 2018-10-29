# QTrace

QTrace is a proof of concept project aiming at using concurrency to render fractal images with an emphasis on logic and graphric interfaces separation, using Qt for the logic interface and Qml for the graphic interface. QTrace can easily be extended to handle any kind of raytracing methods.

![Screenshot](http://jwintz.me/assets/img/qtrace.png)

## Build

    $ cmake /path/to/qtr/source/tree -D Ninja
    $ ninja

## Apps

### Newton solver

Computes root of z^3-20 in R and roots of z^3-20 in C.

    $ ./bin/qtrNewtonSolver

### Newton writer single threaded

Computes fractal image z^3-1 in C.

    $ time ./bin/qtrNewtonWriter-st 5 800 800 qtrNewton-st.png # [UNIX]
    $ time ./bin/qtrNewtonWriter-st 5 800 800 qtrNewton-st.png && qlmanage -p qtrNewton-st.png >& /dev/null # [MACX]

### Newton writer multi threaded

Computes fractal image z^3-1 in C.

    $ time ./bin/qtrNewtonWriter-mt 3 800 800 qtrNewton-mt.png # [UNIX]
    $ time ./bin/qtrNewtonWriter-mt 3 800 800 qtrNewton-mt.png && qlmanage -p qtrNewton-st.png >& /dev/null # [MAXC]

### Newton viewer

Renders fractal image in viewport multi threaded.

#### Using wrapper application

    $ ./bin/qtrNewtonViewer 5

#### Using qmlscene from source tree root

    $ qmlscene -I qml/ app/qtrNewtonViewer/main.qml
