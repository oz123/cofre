Cofre 
=====

Cofre means "safe" in Portuguese. Cofre is a project to re-implement
pwman3 again in Python. 

What? 

wait, I just said I am implementing a software which is already 
written in Python in C. 
Well, now you know why Cofre begins with C. 

[Pwman3][python-pwman3] is quite a mature software. 
It started as C project written with Curses. It didn't use a database 
as a backend, rather it used an XML file to store all the sensitive information. 
(See [original pwman here][c-pwman] )
The goal of this project is to produce a small ncurses C program that can 
read and interact with pwman3 database. 

Why? 
Well, I have been reading books about C programming, and I have been 
programming with C for quite a while. However ... I always worked on 
existing projects. So, I thought, here is something I know quite well,
and I think it could be a cool way to learn more about C. 
To be exact, this project should serve as an introduction for how to 
_develop software_ with C, and continue where most books on C stop. 

To be more exact, C books always spend about 2 pages (sometimes just a
boxed frame) about compilers and how to work with 3rd party software. 

So the goals of this project is to learn:

 * How to use make files
 * How to use autotools. 
 * How to use a compiler and C debugger. 
 * How to use Valgrind. 
 * How to include 3rd party libraries like SQLite. 

If everything goes well, a working software will arise and more knowledge 
will be acquired. 

[python-pwman3]: https://github.com/pwman3/pwman3
[c-pwman]: http://pwman.sourceforge.net/

