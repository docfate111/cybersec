We know that the readflag() with allocated two buffers of size 746(with 16 bytes of metadata)

So we can malloc 2 chunks of that size and free them

Then we know the flag will be read into the second buffer

    Index 0        Index 1
+------------+-----------+
|   768      |  768      |
+------------+-----------+ 