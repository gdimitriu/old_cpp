2. (*3.5) Implement a simple graphics system using whatever graphics facilities are available on
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

3. (*2) Important aspects of a S h a p e appear on the screen as a set of line segments. Implement
operations to vary the appearance of these segments: s .t h i c k n e s s (n ) sets the line thickness to
0 , 1 , 2 , or 3 , where 2 is the default and 0 means invisible. In addition, a line segment can be
s o l i d , d a s h e d , or d o t t e d . This is set by the function S h a p e :: o u t l i n e ().

(*2.5) Provide a function L i n e :: a r r o w h e a d () that adds arrow heads to an end of a line. A
line has two ends and an arrowhead can point in two directions relative to the line, so the argument
or arguments to a r r o w h e a d () must be able to express at least four alternatives.

5. (*3.5) Make sure that points and line segments that fall outside the W i n d o w do not appear on
the screen. This is often called ‘‘clipping.’’ As an exercise only, do not rely on the implementation
graphics system for this.

6. (*2.5) Add a T e x t type to the graphics system. A T e x t is a rectangular S h a p e displaying characters.
By default, a character takes up one coordinate unit along each coordinate axis.

7. (*2) Define a function that draws a line connecting two shapes by finding the two closest ‘‘contact
points’’ and connecting them.

8. (*3) Add a notion of color to the simple graphics system. Three things can be colored: the
background, the inside of a closed shape, and the outlines of shapes.

10. (*2.5) Given classes C i r c l e , S q u a r e , and T r i a n g l e derived from a class S h a p e , define a function
i n t e r s e c t () that takes two S h a p e * arguments and calls suitable functions to determine if
the two shapes overlap. It will be necessary to add suitable (virtual) functions to the classes to
achieve this. Don’t bother to write the code that checks for overlap; just make sure the right
functions are called. This is commonly referred to as double d i s p a t c h or a multimethod.