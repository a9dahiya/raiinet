Do not modify the test harness. It is important to look over the code of the test harness to understand exactly what it does, so that you can create appropriate test input. Do not test the test harness or test with invalid input.

In this test harness, you will have an array of 4 StringBags you can work with by calling the commands below. They are indexed by 0, 1, 2, and 3. The idx/idx1/idx2 arguments below should be one of these four integers. The ele argument should be a string.

COMMAND        | arg1 | arg 2 | description
print            idx            : prints bag idx using the << operator.
debugPrint       idx            : prints bag idx using the debugPrint method.
arity            idx    ele     : prints the int returned by calling bag idx's arity method with argument ele.
getNumElements   idx            : prints the int returned by calling bag idx's getNumElements method.
getNumValues     idx            : prints the int returned by calling bag idx's getNumValues method.
add              idx    ele     : calls bag idx's add method with argument ele.
remove           idx    ele     : calls bag idx's remove method with argument ele.
removeAll        idx    ele     : calls bag idx's removeAll method with argument ele.
+                idx1   idx2    : prints using << the result of using bag idx1's + operator method with argument bag idx2.
-                idx1   idx2    : prints using << the result of using bag idx1's - operator method with argument bag idx2.
+=               idx1   idx2    : calls bag idx1's += operator method with argument bag idx2.
-=               idx1   idx2    : calls bag idx1's -= operator method with argument bag idx2.
==               idx1   idx2    : prints the result of using bag idx1's == operator method with argument bag idx2.
dezombify        idx            : calls bag idx's dezombify method.
copyconstruct    idx            : creates tmp by copying bag idx, then prints tmp using <<.
moveconstruct                   : creates tmp by moving from the bag returned by genTempBag, then prints tmp using <<.
copy=            idx1   idx2    : copies bag idx2 to bag idx1 using copy assignment.
move=            idx            : moves the bag returned by genTempBag to bag idx using move assignment.

The genTempBag function returns a StringBar with contents: { ("one", 1), ("two", 2), ("three", 3), }.

Here is an example of some test input:
// test1.in
add 0 moon
add 0 luna
print 0
