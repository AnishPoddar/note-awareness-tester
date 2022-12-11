# note-awareness-tester
C++ program to test your mental ability to build chords as quickly as possible in your head.

How to run via command line (Windows):
> g++ note_awareness.cpp
> a

# Introduction

Welcome to the Note Awareness Tester! This is a simple, fun game designed to test your music theory knowledge and mental ability. The premise is simple: You, the player, will be asked to name all the notes in a ramdomly generated chord in the correct order as fast as possible. You can attempt this as many times as you like. You can also make it more challenging for yourself by generating a random inversion for each chord. Good luck, and have fun!

# Some basics (for music theory beginners)

There are 12 *notes* in music. They are:
C, C#, D, D#, E, F, F#, G, G#, A, A#, B

A *chord* is a group of 2 or more notes played simultaneously. For example, the set of notes (C, E, G) is one such chord.
(For this game, we limit ourselves to 3-note chords.)

Each set of consecutive notes (eg: F, F# or B, C) is one *semitone* or one *half-step* apart.

An *interval* is a distance between two notes measured in half-steps.
We'll only be using 2 types of intervals in this game:
- *major third*: Notes are 4 half-steps apart (eg: C and E)
- *minor third*: Notes are 3 half-steps apart (eg: C and D#)

Given all the above, there are 4 main types of 3-note chords (expressed using intervals):
- *major chords*:        major third, then minor third (i.e. note, note + 4, (note + 4) + 3), eg: C major is C, E, G
- *minor chords*:        minor third, then major third (i.e. note, note + 3, (note + 3) + 4), eg: C minor is C, D#, G
- *augmented chords*:    major third, then major third (i.e. note, note + 4, (note + 4) + 4), eg: C augmented is C, E, G#
- *diminished chords*:   minor third, then minor third (i.e. note, note + 3, (note + 3) + 3), eg: C diminished is C, D#, F#

A *chord inversion* is a chord where the order of the notes have been changed by rotating them.
A 3-note chord can therefore only have 3 rotations, i.e. 3 inversions (eg: C major can have CEG, EGC and GCE as possible inversions).
These inversions are called the *root, 1st and 2nd inversions* respectively.

Therefore, the root inversion of F diminished would be (F, G#, B) while the 2nd inversion of F diminished would be (B, F, G#).

# Scope for improvement
- Answers are currently case-sensitive and require uppercase input (eg: entering 'g#' instead of 'G#' will cause a score of 0 for a question)
- No existing functionality to only play based on specific types of chords (eg: if you only want to test yourself on major chords)
- No concept of flats (treating G# and Ab as the same note and marking answers based on which of the two is used depending on the chord)
- No memory of lowest time taken to answer a question within a session
- No memory of older scores
- Not currently storing total time taken to attempt all questions
- Input is via command line; no GUI to increase input speed
