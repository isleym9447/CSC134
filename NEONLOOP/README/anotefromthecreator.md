# Developer Notes & Full Disclosure

Before anything else:
I want to include a brief full disclosure statement about the development process for this project.

SFML on Windows was a Boss Fight.

Like… a full RPG final boss, with phases.

This project originally began as a multi-file, text-based C++ narrative game, which worked perfectly in the console.
However, I wanted to push myself and evolve it into a visual novel–style UI using SFML — and that’s where the difficulties started.

# What I struggled with (and what I learned):

--- 1. Compiler / Runtime Mismatches ---

SFML’s Windows libraries are compiled with very specific MinGW/GCC versions, and my existing compiler didn’t match them.
This caused:

“Entry Point Not Found” errors

Missing symbol errors

Crashes when loading DLLs

The classic “it works on my machine, but not really” scenario

I learned that for SFML on Windows:

The MinGW version must exactly match the one SFML was built with.

Even minor differences (13.1 vs 13.2) break binary compatibility.

--- 2. 32-bit vs 64-bit Confusion ---

At one point I downloaded a 64-bit SFML ZIP…
and it unzipped into 32-bit DLLs.
(Windows, I love you but why?)

This caused even more crashes when the 64-bit EXE tried to load 32-bit DLLs.

I learned:

You cannot mix 32- and 64-bit binaries. Ever.

File size does not indicate architecture.

The SFML website quietly puts multiple similarly named packages together — and you must check the “SEH / DW2 / 64-bit” very carefully.

--- 3. PATH Confusion & Toolchain Isolation ---

I originally tried adding multiple versions of MinGW to PATH.
This caused different terminals to use different compilers without warning.

I learned:

Never mix multiple MinGW versions in PATH.

Best practice: don’t put MinGW in PATH at all — call it by absolute path.

Creating a dedicated folder (like C:\mingw64_sfml) is the safest way.

--- 4. DLL Hell ---

Oh boy.

SFML requires both:

the SFML DLLs themselves

the MinGW runtime DLLs that match the compiler

I learned:

The EXE must sit next to:

sfml-graphics-2.dll

sfml-window-2.dll

sfml-system-2.dll

libstdc++-6.dll

libgcc_s_seh-1.dll

libwinpthread-1.dll

If even one is the wrong version, Windows throws cryptic popup errors.

--- 5. Persistence ---

This entire build process involved:

multiple reinstallations

several MinGW versions

switching architectures

compiler errors

linker errors

runtime errors

DLL mismatches

and a LOT of “why is this happening???” moments

But I also learned:

How C++ toolchains actually work under the hood

How binary compatibility differs from language compatibility

How libraries are linked and loaded

How to diagnose Windows DLL issues without guesswork

And how to set up a proper C++ multimedia project on Windows — from scratch

Why I’m including this

Transparency is important.
This wasn’t a simple “follow a tutorial and it runs” project — this was a real-world debugging gauntlet, and working through it genuinely expanded my understanding of C++, compilation, linking, runtime dependencies, and software distribution.

Despite the challenges, I’m proud of the final result:
A functional, expandable C++ SFML game framework that can grow into a full visual novel.






some of the funniest prompts from when I was crying into my coffee:

1. Existential Crisis Over a Font

"whats the all the quesion marks??? is that a font thing???????"


2. When my soul left my body

"oh my god echo its completly broken now. im gonan combust."

3. When things broke AGAIN immediately after fixing something

"dude no its still broken :( it just goes black when main menu is clicked. it was workling before wtf happeneddddddd"

4. When i tried making the engine more complex and i said ABSOLUTELY NOT

"NO. no creating new files can we just fix the ones we had PLEASE. they were working so good :("

5. Trying to figure out why we were editing UI systems

"why are we correcting the ui button tho? we didnt even change that? hello???"

6. When main.cpp suddenly grew 200 lines

"that gives me hella errors. its 200 lines while my last main is 35 lines. is that right??"

and my favorite, 

staring into the void after another compile error dump...

"broke it."