#include <iostream>
int main() {
  // 1.9 - Write a program that uses a while to sum the numbers from 50 to 100
  // int sum = 0, val = 50;
  // while (val <= 100) {
  //   sum += val;
  //   ++val;
  // }
  // std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;

  // 1.10 - Write a program that uses a while to print the numbers
  // from ten down to zero
  // int val = 10;
  // while (val >= 0) {
  //   std::cout << val << std::endl;
  //   --val;
  // }

  // 1.11 - Write a program that prints each number in the range of
  // two input integers
  // int a = 0, b = 0;
  // std::cout << "Give two integers, and I will print the numbers "
  //           << "within their range (inclusive). Smaller one first!"
  //           << std::endl;
  // std::cin >> a >> b;

  // while (a <= b) {
  //   std::cout << a << std::endl;
  //   ++a;
  // }

  // 1.12 - skip
  // 1.13 - Rewrite 1.9 - 1.11 using for loops
  // int sum = 0;
  // for (int val = 50; val <= 100; ++val) {
  //   sum += val;
  // }
  // std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;


  // for (int val = 10; val >= 0; --val) {  // don't use ++! be careful!
  //   std::cout << val << std::endl;
  // }


  // int c = 0, d = 0;
  // std::cout << "Give two integers, and I will print the numbers "
  //           << "within their range (inclusive). Smaller one first!"
  //           << std::endl;
  // std::cin >> c >> d;

  // for (int val = c; c <= d; ++c) {
  //   std::cout << c << std::endl;
  // }

  // 1.14 1.15 1.16 - skip



  // summing a set of numbers with an unknown set size
  // int sum = 0, value = 0;

  // the condition depends on std::cin, which returns true as long as
  // the end-of-file or invalid input is not read
  // EOF is usually CTRL+Z on windows and CTRL+D on Mac/UNIX
  // while (std::cin >> value)
  //   sum += value;
  
  // std::cout << "Sum is: " << sum << std::endl;



  // count how many consecutive times each distinct value appears
  // TODO: optimize and fix possible errors?
  // int currVal = 0, nextVal = 0;
  // if (std::cin >> currVal) {  // get first val (or terminate if empty input)
  //   int cnt = 1;
  //   while (std::cin >> nextVal) {  // compare next values
  //     if (currVal == nextVal) {  // match -> increase count
  //       ++cnt;
  //     }
  //     else {  // no match, count new value
  //       std::cout << currVal << " occurs " << cnt << " times." << std::endl;
  //       currVal = nextVal;  // change currVal to new val
  //       cnt = 1;
  //     }
  //   }
  //   std::cout << currVal << " occurs " << cnt << " times." << std::endl;
  // }
  // note: make sure base cases/possible errors are accounted for
  // (e.g. empty input is accounted for with if() and final std::cout statement)



  // Rewrite 1.11 so that the program only executes when the first
  // input number is smaller than the second
  // int startVal = 0, endVal = 0;
  // if (std::cin >> startVal >> endVal) {
  //   while (startVal <= endVal) {
  //     std::cout << startVal << std::endl;
  //     ++startVal;
  //   }
  // }



  // Print the factorial of the given integer (nth term)
  // int facTerm = 0, facVal = 1;
  // if (std::cin >> facTerm) {
  //   if (facTerm >= 0) {
  //     for (int term = 1; term <= facTerm; term++) {
  //       facVal *= term;
  //     }
  //     std::cout << facTerm << "! is equal to " << facVal << std::endl;
  //   } else {
  //     std::cout << "Invalid input. Please pick a term that is 0+" << std::endl;
  //   }
  // }



  // Often, writing inputs into the terminal can be tedious (e.g. writing ISBNs)
  // So, one alternative is to use input and output files with this format:
  // $ ./Program < input_file > output_file
  // input_file is read by Program using the standard input
  // and the resulting output from Program is saved to output_file

  // nvm, I guess this only works on UNIX. but > still works for output files

  // Write a program that calculates the Nth term of the fibonacci sequence
  // Then, try using an input and output file to save calculations
  int fibTerm = 0;

  while (std::cin >> fibTerm) {
    std::cout << "Term: " << fibTerm << std::endl;
    int fibValuePrev = 0, fibValue = 1;  // need to reset for each new term!!!!

    if (fibTerm < 0) {
      std::cout << "The term cannot be less than 0." << std::endl << std::endl;
    }
    else if (fibTerm == 0) {
      std::cout << "Value: 0" << std::endl << std::endl;
    }

    else {  // need else statement so that other erronous conditions don't exec
      int termCount = 1;
      while (termCount < fibTerm) {
        int temp = fibValue;
        fibValue += fibValuePrev;
        fibValuePrev = temp;

        ++termCount;  // don't forget to increment counter in while loop!!!
      }
      std::cout << "Value: " << fibValue << std::endl << std::endl;
    }
  }

  return 0;
}