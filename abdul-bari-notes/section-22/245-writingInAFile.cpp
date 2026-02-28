#include <iostream>
#include <fstream>  // input/output file stream  (ifstream, ofstream)

int main() {
    // create output file stream for opening/creating a new file name
    // "My.txt". if the file already exists, trunc will remove its existing
    // contents and insert new content
    std::ofstream ofs("My.txt", std::ios::trunc);
        //std::ios::app will keep existing contents (i.e., append the new stuff)

    ofs << "John" << std::endl;  // write content onto My.txt
    ofs << 25 << std::endl;
    ofs << "cs" << std::endl;

    ofs.close();  // close the file stream (release it for other programs)
    return 0;
}