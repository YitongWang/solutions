GCC = gcc
CFLAGS = -g -Wall -Wshadow
SOURCES = answer06.c pa06.c
pa06:pa06.o answer06.o
	$(GCC) $(CFLAGS) pa06.o answer06.o -o pa06
answer06.o: answer06.c pa06.h
	$(GCC) $(CFLAGS) -c answer06.c
pa06.o:pa06.o pa06.h
	$(GCC) $(CFLAGS) -c pa06.c

test: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14


test1: 
	./pa06 images/01-unnormalized-smile.ee264 outputs/output1 
	diff outputs/output1 expected/01-smile.ppm
	valgrind --leak-check=full --verbose --log-file=valgrindlog1 ./pa06 images/01-unnormalized-smile.ee264 outputs/output1

test2: 
	./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output2 
	diff outputs/output2 expected/02-cat-chess.ppm
	valgrind --leak-check=full --verbose --log-file=valgrindlog2 ./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output2
test3: 
	./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output3 
	diff outputs/output3 expected/03-hawkes-bay-NZ.ppm
	valgrind --leak-check=full --verbose --log-file=valgrindlog3 ./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output3
test4: 
	./pa06 images/04-unnormalized-nelsonmandela.ee264 outputs/output4 
	diff outputs/output4 expected/04-nelsonmandela.ppm
	valgrind --leak-check=full --verbose --log-file=valgrindlog4 ./pa06 images/04-unnormalized-nelsonmandela.ee264 outputs/output4
test5: 
	./pa06 images/05-unnormalized-sagan-stamp.ee264 outputs/output5 
	diff outputs/output5 expected/05-sagan-stamp.ppm
	valgrind --leak-check=full --verbose --log-file=valgrindlog5 ./pa06 images/05-unnormalized-sagan-stamp.ee264 outputs/output5

test6:
	! ./pa06 images/corrupt-testcases/bad-comment-len.ee264 outputs/output6
	! valgrind --leak-check=full --verbose --log-file=valgrindlog6 ./pa06 images/corrupt-testcases/bad-comment-len.ee264 outputs/output6
test7:
	! ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/output7
	! valgrind --leak-check=full --verbose --log-file=valgrindlog7 ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/output7
test8:
	! ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 outputs/output8
	! valgrind --leak-check=full --verbose --log-file=valgrindlog8 ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 outputs/output8
test9:
	! ./pa06 images/corrupt-testcases/height0.ee264 outputs/output9
	! valgrind --leak-check=full --verbose --log-file=valgrindlog9 ./pa06 images/corrupt-testcases/height0.ee264 outputs/output9
test10:
	! ./pa06 images/corrupt-testcases/height-wrong.ee264 outputs/output10
	! valgrind --leak-check=full --verbose --log-file=valgrindlog10 ./pa06 images/corrupt-testcases/height-wrong.ee264 outputs/output10
test11:
	! ./pa06 images/corrupt-testcases/incomplete-header.ee264 outputs/output11
	! valgrind --leak-check=full --verbose --log-file=valgrindlog11 ./pa06 images/corrupt-testcases/incomplete-header.ee264 outputs/output11
test12:
	! ./pa06 images/corrupt-testcases/incomplete-image.ee264 outputs/output12
	! valgrind --leak-check=full --verbose --log-file=valgrindlog12 ./pa06 images/corrupt-testcases/incomplete-image.ee264 outputs/output12
test13:
	! ./pa06 images/corrupt-testcases/width0.ee264 outputs/output13
	! valgrind --leak-check=full --verbose --log-file=valgrindlog13 ./pa06 images/corrupt-testcases/width0.ee264 outputs/output13
test14:
	! ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/output14
	! valgrind --leak-check=full --verbose --log-file=valgrindlog14 ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/output14

