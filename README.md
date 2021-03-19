# Creation and Checking Mechanism for Promo Coupon Codes
Project by Mustafa Can Aydin \
Notes: I have written and tested this code in C++11 using MacOS Big Sur version 11.2.3

# Explanation


Main idea of the project is to generate 10,000,000 promo coupon codes to be distributed to company's customers as a gift. Each promo code has to be unique with length of 8 characters taken from the set {A,C,D,E,F,G,H,K,L,M,N,P,R,T,X,Y,Z,2,3,4,5,7,9}. These codes will be given to authorized people and printed out to be distributed to customers. Customers who have taken the a promo code may use it through a mobile app or similar application. To protect these codes from thief codes should not be stored in a database and should be check algorithmically. This project aims to generate a unique hash for each code which cannot be decrypted and checks codes by passing each code into hash function and comparing hash values to verified hash values. The has function that is used in this project is md5. The algorithm used in md5 uses four variables of 32-bit length in a round-robin fashion to create a value that is then used to generate the hash. Md5 have fallen out of use due to security problems it faces and largely replaced by SHA-2 hash algorithm. Considering the aims and scope of this application I find md5 to be suitable to use. 


# Compiling and Running of the Project

In order to run program first one has to compile main.cpp, md5.cpp, and md5.h files into executable. To achive this this project utilizes Makefile. Running below command in directory containing main.cpp, md5.cpp, md5.h, and Makefile will give the desired executable file. 
~~~~~~~~~~~~~~~{.cpp}
    make
~~~~~~~~~~~~~~~
After compilation is done, one has an executable file named output.

~~~~~~~~~~~~~~~{.cpp}
    ./output
~~~~~~~~~~~~~~~
Then running output executable will give the desired outcome of the program to the PromoCodes.txt file. Program will print out 1,000 unique promo codes to PromoCodes.txt file and after creating each code program will pass it to CheckCode() function and will continue generating codes only if outcome of the CheckCode() is true. 

# Conclusion


To sum it up, this projects creates unique promo codes and for each of the promo code it implement a secure verification mechanism. 
