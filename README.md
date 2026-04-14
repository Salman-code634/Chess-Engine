# Vice Chess Engine
The VICE chess engine is an instructional, open-source engine designed to demonstrate the core principles of chess programming and engine development. Originally developed as a learning project, it implements fundamental techniques such as board representation, move generation, and search algorithms in a clear and structured way. The engine uses a 120-square board representation along with additional optimizations, making it a practical starting point for understanding how modern chess engines operate internally

## What is Vice?

Vice is a **V**ideo **I**nstructional **C**hess **E**ngine, written in C.

Vice is deliberately simplified - the code structure is by no means to be considered best practice, rather a quick start into understanding the world of computer chesss engine programming.

## I want to copy it, can I?

You can do whatever you want with the code. A lot of engines have been inspired by Vice - not all give credit. Probably it's better to give credit than not.

## What are the main features?

Vice is simple, with the following features:

- Alpha beta search
- Iterative deepening
- Quiescence search
- Transposition table
  - Always replace
- Polyglot opening books
- MVV/LVA move ordering
- Basic evaluation

## bugs to fix:
- The PickMove function needs a BestScore of -(very low) instead of 0
- Time management for x moves in x minutes causes losses
- ID loop needs to only exit when it has a legal move (i.e done depth 1 at least)

## Who actually did this?

The real person behind the series is Muhammad Salman Saeed.  
[LinkedIn](https://www.linkedin.com/in/muhammad-salman-saeed-896520333/)