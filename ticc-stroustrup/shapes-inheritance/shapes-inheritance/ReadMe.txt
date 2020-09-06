========================================================================
    CONSOLE APPLICATION : shapes-inheritance Project Overview
========================================================================

AppWizard has created this shapes-inheritance application for you.

This file contains a summary of what you will find in each of the files that
make up your shapes-inheritance application.


shapes-inheritance.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

shapes-inheritance.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

shapes-inheritance.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
AppWizard has created the following resources:

shapes-inheritance.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named shapes-inheritance.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

the goal is:

3.5) Implement a simple graphics system using whatever graphics facilities are available on
your system (if you don’t have a good graphics system or have no experience with one, you
might consider a simple ‘‘huge bit ASCII implementation’’ where a point is a character position
and you write by placing a suitable character, such as * in a position): W i n d o w (n ,m ) creates
an area of size n times m on the screen. Points on the screen are addressed using (x,y) coordinates
(Cartesian). A W i n d o w w has a current position w .c u r r e n t (). Initially, c u r r e n t is
P o i n t (0 ,0 ). The current position can be set by w .c u r r e n t (p ) where p is a P o i n t . A P o i n t is
specified by a coordinate pair: P o i n t (x ,y ). A L i n e is specified by a pair of P o i n t s:
L i n e (w .c u r r e n t (), p 2 ); class S h a p e is the common interface to D o t s, L i n e s, R e c t a n g l e s,
C i r c l e s, etc. A P o i n t is not a S h a p e . A D o t , D o t (p ) can be used to represent a P o i n t p on the
screen. A Shape is invisible unless draw()n. For example:
w .d r a w (C i r c l e (w .c u r r e n t (), 1 0 )). Every S h a p e has 9 contact points: e (east), w (west), n
(north), s (south), n e , n w , s e , s w , and c (center). For example, L i n e (x .c (), y .n w ()) creates
a line from x ’s center to y ’s top left corner. After d r a w ()ing a S h a p e the current position is the
S h a p e ’s s e (). A R e c t a n g l e is specified by its bottom left and top right corner:
R e c t a n g l e (w .c u r r e n t (), P o i n t (1 0 ,1 0 )). As a simple test, display a simple ‘‘child’s drawing
of a house’’ with a roof, two windows, and a door.
/////////////////////////////////////////////////////////////////////////////////////////////////