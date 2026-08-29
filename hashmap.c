#include<stdio.h>

// so the idea is to get any specific element from the array without actually iterating over it
// this is a slower approach
// so what we want is something like we can search it via any specific key and get the value in that key
// we don't need numeric index for this that is the difference
// so hash function is the black box where we give a key and it gives some random value for our surprise it isn't that random
// it is actually calculated in such a way that collision is reduced.
// what is collision you may ask. well, it is basically when 2 key have same unique value which came out of the blackbox see it isn't unique anymore.
// 1st convert all key into a number and do some math and get final value out of it but this can get us some collision. 
// True, but the whole idea is to get as less collision as possible we will try to get there.
// the key is converted to a single value and putting key always in that hash function give us that deterministic value only
// and we will store value of that key in that index in array which we got from the prev calculation.
// there are some problems here as you can see the number produced by hash function is actually very big and if 
// we are using 32 bit int hash func value can range from 0 to 4.2  billion which is 128 GB for the array not feasible right? that's what researcher thought..
// then also we can have collision 
// first thing we can do is reduce 4.2 billion numbers to something practical like 10,000 which might be number of usser that's gonna use the app..
// 32b *10000 ~ around 32kb previously we needed 128 GB dude now 32kb yayyyyy? not really..
// so next question is how do we map those 4.2 billion indices onto 10,000 stuffs. we can use modulo for this
// so next thing is moduling(hope thats a word) 4.2 billion by n makes n different buckets so 4.2 billion % 10,000 makes 10k buckets
// so we basically represented 4.2 billion stuff onto 10k stuff. now let's try to deal with another problem collision
// if 2 key have same index then what? simple strategy is to make it search for nearest empty place and because of that we need to change our lookup strategy.
// decode it and look if it is the same key that we are looking for or not?? if yes yayyy found it, if no iterate more if nothing found there is nothing. usually known as linear probing.
// This solution what we have built is called open addressing..

int main(){
    

    int a[12][12];
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            a[i][j] = i*10+j;

        }
    }
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){

            printf("%d\t",a[i][j]);
        }
    printf("\n");
    }

    printf("\n%d \t%d \t %d ", a[10][0], a[0][10], a[1][0]);
}