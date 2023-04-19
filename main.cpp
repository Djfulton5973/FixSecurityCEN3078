#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <fstream>
#include <array>
using namespace std;
double alpha(int n){
    if(n == 0)
        return sqrt(0.5);
    else
        return 1;
}
double pi = 3.1415926535897932384626433832795;
double **dct(double **m) {
    auto **final = new double*[8];
    for(int v=0;v<8;++v) {
        final[v] = new double[8];
        for(int u=0;u<8;++u) {
            double sub = 0;
            for(int i=0;i<8;++i) {
                for(int j=0;j<8;++j) {
                    sub += m[i][j] * cos((2 * j + 1) * u * pi / 16) * cos((2 * i + 1) * v * pi / 16);
                }
            }
            final[v][u] = (round(sub * alpha(u) * alpha(v) / 4));
        }
    }

    return final;
}
double *conv(const double *a) {
    auto *final = new double[3]{0.299 * a[0] + 0.587 * a[1] + 0.114 * a[2],128 - 0.168736 * a[0] - 0.331264 * a[1] + 0.5 * a[2],128 + 0.5 * a[0] - 0.418688 * a[1] - 0.081312 * a[2]};
    return final;
}
string decToBit(int num) {
    string final;
    int l = static_cast<int>(floor(log(abs(num))/log(2))+1);
    for(int i=0;i<l;++i) {
        if(num >= 0)
            final += static_cast<char>((floor(static_cast<int>(num / pow(2, (l - 1) - i)) % 2))+48);
        else {
            if(floor(static_cast<int>(abs(num) / pow(2, (l - 1) - i)) % 2) == 0)
                final.append("1");
            else
                final.append("0");
        }
    }
    return final;
}
string showBitsL(int num,int l) {
    string final;
    for(int i=0;i<l;++i) {
        final += static_cast<char>((floor(static_cast<int>(num / pow(2, (l - 1) - i)) % 2))+48);
    }
    return final;
}
int bitToDec(const string& s) {
    int final = 0;
    for(int i=0;i<8;++i) {
        if(s[i] == 49) {
            final += static_cast<int>(pow(2, 7 - i));
        }
    }
    return final;
}
int* push(const int* l, int n, int s){
    auto l2 = new int[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = n;
    //delete l;
    return l2;
}
int** push(int** l, int *n, int s){
    auto l2 = new int*[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = n;
    //delete l;
    return l2;
}
string* push([[maybe_unused]]const string* l, string n, int s){
    auto* l2 = new string[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = std::move(n);
    //delete l;
    return l2;
}
double*** push(double*** l, double** n, int s){
    auto*** l2 = new double**[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = n;
    //delete l;
    return l2;
}
double** push(double** l, double* n, int s){
    auto** l2 = new double*[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = n;
    //delete l;
    return l2;
}
double* push(const double* l, double n, int s){
    auto l2 = new double[s+1];
    for(int i=0;i<s;++i){
        *(l2+i)=*(l+i);
    }
    *(l2+s) = n;
    //delete l;
    return l2;
}
int* splice(const int* l, int st, int e, int s){
    auto l2 = new int[s-(st-e+1)];
    for(int i=0;i<st;++i){
        l2[i]=l[i];
    }
    for(int i=e;i<s;++i){
        l2[i-e+st]=l[i];
    }
    //delete l;
    return l2;
}
int main() {
    int **header = new int*[12];
    header[0] = new int[]{255, 216};
    header[1] = new int[]{255, 224, 0, 16, 74, 70, 73, 70, 0, 1, 1, 1, 0, 96, 0, 96, 0, 0};
    header[2] = new int[]{255, 225, 0, 34, 69, 120, 105, 102, 0, 0, 77, 77, 0, 42, 0, 0, 0, 8, 0, 1, 1, 18, 0, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0};
    header[3] = new int[]{255, 219, 0, 67, 0};
    header[4] = new int[]{255, 219, 0, 67, 1};
    header[5] = new int[]{255, 192, 0, 17, 8, 0, 0, 0, 0, 3, 1, 34, 0, 2, 17, 1, 3, 17, 1};
    header[6] = new int[]{255, 196, 0, 31, 0, 0, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    header[7] = new int[]{255, 196, 0, 181, 16, 0, 2, 1, 3, 3, 2, 4, 3, 5, 5, 4, 4, 0, 0, 1, 125, 1, 2, 3, 0, 4, 17, 5, 18, 33, 49, 65, 6, 19, 81, 97, 7, 34, 113, 20, 50, 129, 145, 161, 8, 35, 66, 177, 193, 21, 82, 209, 240, 36, 51, 98, 114, 130, 9, 10, 22, 23, 24, 25, 26, 37, 38, 39, 40, 41, 42, 52, 53, 54, 55, 56, 57, 58, 67, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 90, 99, 100, 101, 102, 103, 104, 105, 106, 115, 116, 117, 118, 119, 120, 121, 122, 131, 132, 133, 134, 135, 136, 137, 138, 146, 147, 148, 149, 150, 151, 152, 153, 154, 162, 163, 164, 165, 166, 167, 168, 169, 170, 178, 179, 180, 181, 182, 183, 184, 185, 186, 194, 195, 196, 197, 198, 199, 200, 201, 202, 210, 211, 212, 213, 214, 215, 216, 217, 218, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250};
    header[8] = new int[]{255, 196, 0, 31, 1, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    header[9] = new int[]{255, 196, 0, 181, 17, 0, 2, 1, 2, 4, 4, 3, 4, 7, 5, 4, 4, 0, 1, 2, 119, 0, 1, 2, 3, 17, 4, 5, 33, 49, 6, 18, 65, 81, 7, 97, 113, 19, 34, 50, 129, 8, 20, 66, 145, 161, 177, 193, 9, 35, 51, 82, 240, 21, 98, 114, 209, 10, 22, 36, 52, 225, 37, 241, 23, 24, 25, 26, 38, 39, 40, 41, 42, 53, 54, 55, 56, 57, 58, 67, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 90, 99, 100, 101, 102, 103, 104, 105, 106, 115, 116, 117, 118, 119, 120, 121, 122, 130, 131, 132, 133, 134, 135, 136, 137, 138, 146, 147, 148, 149, 150, 151, 152, 153, 154, 162, 163, 164, 165, 166, 167, 168, 169, 170, 178, 179, 180, 181, 182, 183, 184, 185, 186, 194, 195, 196, 197, 198, 199, 200, 201, 202, 210, 211, 212, 213, 214, 215, 216, 217, 218, 226, 227, 228, 229, 230, 231, 232, 233, 234, 242, 243, 244, 245, 246, 247, 248, 249, 250};
    header[10] = new int[]{255, 218, 0, 12, 3, 1, 0, 2, 17, 3, 17, 0, 63, 0};
    header[11] = new int[]{255, 217};
    int *hl = new int[]{2,18,36,5,5,19,33,183,33,183,14,2};
    array<int,4> l = {33,183,33,183}; // for use with huffman table value representation
    int ***hTables = new int**[4]; // where all the data goes, 4 huffman tables total
    for(int i=6;i<10;++i) { // for values 6, 7, 8 and 9 in the header bytes array
        hTables[i-6] = new int*[2]; // each entry in hTables is split in two parts, the first containing the amounts for
        // each code length, and the second containing which numerical value each code represents
        for(int j=5;j<21;++j) { // first entry always contains 16 values to represent code length values
            // from 0 to 15
            hTables[i-6][0] = push(hTables[i-6][0],header[i][j],j-5); // applies the byte value from the header
            // array to the list
        }
        for(int j=21;j<l[i-6];++j) { // second array contains the numerical values associated with the codes defined by
            // the first entry. since the actual amount of values represented varies, a simple static array l is used to
            // represent the lengths
            hTables[i-6][1] = push(hTables[i-6][1],header[i][j],j-21);
        }
    }
    auto **hCodesVal = new int*[4]; // integers for the numerical values
    auto **hCodesStr = new string*[4]; // strings for the bitstream string
    for(int k=0;k<4;++k) { // loop for 4 huffman tables
        int e = 0; // sample integer value to use to make the bitstream
        int off = 0; // offset that is used to scroll through the list of numerical values
        for (int i=0;i<16;++i) { // loop for 16 code lengths
            for(int j=0;j<hTables[k][0][i];++j) { // loop for how many codes of each length, can sometimes be 0, which
                // means there are no codes of the particular length
                hCodesVal[k] = push(hCodesVal[k],hTables[k][1][off + j],off+j); // add the value to the list of
                // values
                hCodesStr[k] = push(hCodesStr[k],showBitsL(e, i + 1),off+j); // add the string returned
                // by showBitsL to the list of strings using sample integer e
                e += 1; // sample integer increases by 1 for every entry added
            }
            off += hTables[k][0][i]; // offset increases for every time all the codes of a specific length are added
            e *= 2; // since all codes of a specific length are added, the length shifts, and the sample integer
            // e doubles
        }
    }
    ifstream file{R"(C:\Users\Darren Fulton\CLionProjects\BitmapConverter\start.bmp)",ios::binary};
    file.seekg(0, ios::end);
    long long length = file.tellg();
    file.seekg(0, ios::beg);
    char *rawData = new char[length];
    file.read(rawData, length);
    double ***ybr; // defines YCbCr matrix
    int width = int(static_cast<unsigned char>(rawData[19]))*256+int(static_cast<unsigned char>(rawData[18])); // defines width
    int height = int(static_cast<unsigned char>(rawData[23]))*256+int(static_cast<unsigned char>(rawData[22])); // defines height
    int pW = (static_cast<int>(length)-54)/height; // important value that uses the length of the file minus the header bytes(54)
    // divided by the height. this is used because the format of the bitmap file uses padding bytes of value 0 when the width is
    // not divisible by 4, and could cause complications when reading the data
    for(int i=height-1;i>-1;--i) { // bitmaps are recorded bottom-to-top, whereas jpegs are read top-to-bottom. a backwards loop is implemented
        ybr = push(ybr,new double*[0],height-1-i); // new empty array to represent a row of pixels
        for(int j=0;j<width;++j) { // loops for each pixel in the row
            auto *sub = new double[3]; // short for substitute, a data holder for the pixel data for future use
            for (int k = 0; k < 3; ++k) { // loops for three values, red, green, and blue
                sub[k] = int(static_cast<unsigned char>(rawData[54 + i * pW + j * 3 + 2 - k])); // add the color data for the specific pixel
                // at row i, column j(the expression 2 - k is used because chronologically, bitmaps store the byte data for each pixel
                // as blue, green, red)
            }
            double *samp = conv(sub); // converts RGB data to YCbCr
            ybr[height-1-i] = push(ybr[height-1-i],samp,j); // adds converted data to matrix
        }
    }
    int rX = int(width/16)+1;
    int rY = int(height/16)+1;
    if(width%16 == 0)
        rX--;
    if(height%16 == 0)
        rY--;
    int runs = rX*rY;
    string bitStr;
    int *pConstY;
    int yL=0;
    int *pConstB;
    int bL=0;
    int *pConstR;
    int rL=0;
    int qt=1;
    cout << "Enter custom quantization from 1-254: " << endl;
    cin >> qt;
    while (qt <= 0 or qt > 254){
        cout << "Invalid input, enter custom quantization from 1-254: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> qt;
    }
    for(int x=0;x<runs;++x) {
        double ***y; // array is defined
        for(int i=0;i<4;++i) { // 4 blocks of luminance for every run of 16x16 pixels
            y = push(y,new double*[0],i); // pushes an empty array
            for(int j=0;j<8;++j) { // 8 pixels
                y[i] = push(y[i],new double[0],j); // pushes an empty array
                for(int k=0;k<8;++k) { // 8 pixels(making 8x8)
                    int sampX = k + (i % 2) * 8 + (x % rX) * 16;
                    int sampY = int(i / 2) * 8 + j + int(x / rX) * 16; // since the blocks for luminance are half the size of the
                    // 16x16 area, they are analyzed in the order of top-left, top-right, bottom-left, bottom right
                    if (sampY >= height)
                        sampY = height-1; // fail-safe in case the sample y value is greater than the height
                    if (sampX >= width)
                        sampX = width-1; // fail-safe in case the sample x value is greater than the width
                    y[i][j] = push(y[i][j],ybr[sampY][sampX][0],k); // adds the luminance value for the row and column specified
                } // similar methods are used for the Cb and Cr matrices
            }
        }
        double **b;
        double **r;
        for(int i=0;i<8;++i) {
            b = push(b,new double[0],i);
            r = push(r,new double[0],i);
            for(int j=0;j<8;++j) {
                double ab = 0;
                double ar = 0;
                for(int k=0;k<2;++k) {
                    for(int m=0;m<2;++m) {
                        int sampX = j * 2 + m + (x % rX) * 16;
                        int sampY = i * 2 + k + 16 * int(x / rX);
                        if(sampY >= height)
                            sampY = height-1;
                        if(sampX >= width)
                            sampX = width-1;
                        ab += ybr[sampY][sampX][1] / 4;
                        ar += ybr[sampY][sampX][2] / 4;
                    }
                }
                b[i] = push(b[i],ab,j);
                r[i] = push(r[i],ar,j);
            }
        }
        double ***mList;
        for(int i=0;i<4;++i) {
            mList = push(mList,y[i],i);
        }
        mList = push(mList,b,4);
        mList = push(mList,r,5);
        for(int z=0;z<6;++z){ // 6 matrices
            double **s = mList[z]; // sample matrix depending on the iteration
            for(int i=0;i<8;++i) {
                for (int j = 0; j < 8; ++j) {
                    s[i][j] -= 128; // 128 is subtracted from each value in the 8x8 matrix so that the data is centered around 0
                }
            }
            double **g = dct(s); // dct is performed
            for(int i=0;i<8;++i) {
                for (int j = 0; j < 8; ++j) {
                    g[i][j] = round(g[i][j] / qt); // quantization value determines how compressed the image should be
                }
            }
            int *ec= new int[64];
            int count = 0;
            int cL=0;
            while(count < 15) {
                int count2 = abs(7 - abs(7 - count));
                while(count2 >= 0) {
                    int *ind=new int[2];
                    if(count < 8) {
                        if(count % 2 == 0) {
                            ind[0] = count2;
                            ind[1] = abs(7 - abs(7 - count)) - count2;
                        }
                        else {
                            ind[0] = abs(7 - abs(7 - count)) - count2;
                            ind[1] = count2;
                        }
                    }
                    else {
                        if(count % 2 == 0) {
                            ind[0] = count2 + 7 - abs(7 - abs(7 - count));
                            ind[1] = 7 - count2;
                        }
                        else {
                            ind[0] = 7 - count2;
                            ind[1] = count2 + 7 - abs(7 - abs(7 - count));
                        }
                    }
                    ec[cL] = static_cast<int>(g[ind[0]][ind[1]]);
                    cL++;
                    count2 -= 1;
                }
                count += 1;
            }
            count = -1;
            while(ec[count+64] == 0 and count > -64)
                count -= 1;
            count += 65;
            ec = splice(ec,count,64,64);
            cL = count;
            int **bitPairs = nullptr;
            int *sub = new int[2]{0,0};
            if(z == 4) {
                if (bL == 0) {
                    if (ec[0] != 0){
                        sub[0] = int(log(abs(ec[0]))/log(2) + 1);
                        sub[1] = ec[0];
                    }
                }
                else {
                    if(ec[0] - pConstB[bL-1] != 0) {
                        sub[0] = int(log(abs(ec[0] - pConstB[bL-1]))/log(2) + 1);
                        sub[1] = ec[0] - pConstB[bL-1];
                    }
                }
                pConstB = push(pConstB,ec[0],bL);
                bL++;
            }
            else if(z == 5) {
                if (rL == 0) {
                    if (ec[0] != 0){
                        sub[0] = int(log(abs(ec[0]))/log(2) + 1);
                        sub[1] = ec[0];
                    }
                }
                else {
                    if(ec[0] - pConstR[rL-1] != 0) {
                        sub[0] = int(log(abs(ec[0] - pConstR[rL-1]))/log(2) + 1);
                        sub[1] = ec[0] - pConstR[rL-1];
                    }
                }
                pConstR = push(pConstR,ec[0],rL);
                rL++;
            }
            else{
                if(yL > 0){
                    if (ec[0] - pConstY[yL-1] != 0) {
                        sub[0] = int(log(abs(ec[0] - pConstY[yL-1]))/log(2) + 1);
                        sub[1] = ec[0] - pConstY[yL-1];
                    }
                }
                else {
                    if (ec[0] != 0) {
                        sub[0] = int(log(abs(ec[0]))/log(2) + 1);
                        sub[1] = ec[0];
                    }
                }
                pConstY = push(pConstY,ec[0],yL);
                yL++;
            }
            bitPairs = push(bitPairs,sub,0);
            int bpl = 1;
            int pre = 0;
            for(int i=1;i<cL;++i) {
                if (ec[i] != 0) {
                    while(pre >= 16) {
                        bitPairs = push(bitPairs,new int[2]{240,0},bpl);
                        bpl++;
                        pre -= 16;
                    }
                    bitPairs = push(bitPairs,new int[2]{int(log(abs(ec[i]))/log(2) + 1) + pre * 16, ec[i]},bpl);
                    bpl++;
                    pre = 0;
                }
                else
                    pre++;
            }
            if(cL < 64) {
                bitPairs = push(bitPairs, new int[2]{0, 0}, bpl);
                bpl++;
            }
            for(int i=0;i<bpl;++i) {
                if(z < 4) { // luminance is being analyzed here because z < 4
                    if (i == 0) { // first value means DC coefficient
                        bitStr += hCodesStr[0][bitPairs[i][0]]; // takes the string associated with the value
                        if (bitPairs[i][1] != 0) // length of 0 means no need to write anything extra
                            bitStr += decToBit(bitPairs[i][1]); // writes the string returned by decToBit
                    } else { // anything other than first value is AC coefficient
                        for (int j = 0; j < 162; ++j) { // there are more values to analyze, and they are not ordered,
                            // so a loop is implemented to search for the proper value
                            if (hCodesVal[1][j] == bitPairs[i][0]) { // finds the one specific string from the huffman table
                                bitStr += hCodesStr[1][j]; // writes the string
                                if (bitPairs[i][1] != 0) // length of 0 means no need to write anything extra
                                    bitStr += decToBit(bitPairs[i][1]); // writes the string returned by decToBit
                            }
                        } // similar method is used for chrominance
                    }
                }
                else {
                    if (i == 0) {
                        bitStr += hCodesStr[2][bitPairs[i][0]];
                        if(bitPairs[i][1] != 0)
                            bitStr += decToBit(bitPairs[i][1]);
                    }
                    else {
                        for (int j = 0; j < 162; ++j) {
                            if(hCodesVal[3][j] == bitPairs[i][0]) {
                                bitStr += hCodesStr[3][j];
                                if (bitPairs[i][1] != 0)
                                    bitStr += decToBit(bitPairs[i][1]);
                            }
                        }
                    }
                }
            }
            delete s;
            delete g;
            delete[] sub;
            delete bitPairs;
            delete[] ec;
        }
        delete mList;
    }
    while (bitStr.size()%8 != 0)
        bitStr += "1";
    int *byteStr=new int[0];
    int bsl=0;
    string sample;
    for(char i : bitStr) {
        sample += i;
        if(sample.size() == 8) {
            byteStr = push(byteStr, bitToDec(sample), bsl);
            bsl++;
            if (byteStr[bsl - 1] == 255) {
                byteStr = push(byteStr, 0, bsl);
                bsl++;
            }
            sample = "";
        }
    }
    for(int i=0;i<bsl;++i) {
        header[10] = push(header[10], byteStr[i], hl[10]);
        hl[10]++;
    }
    header[5][5] = static_cast<unsigned char>(rawData[23]);
    header[5][6] = static_cast<unsigned char>(rawData[22]);
    header[5][7] = static_cast<unsigned char>(rawData[19]);
    header[5][8] = static_cast<unsigned char>(rawData[18]);
    for(int i=0;i<64;++i) {
        header[3] = push(header[3],qt,hl[3]);
        hl[3]++;
        header[4] = push(header[4],qt,hl[4]);
        hl[4]++;
    }
    ofstream rFile{R"(C:\Users\Darren Fulton\CLionProjects\BitmapConverter\result.jpg)",ios::binary};
    for(int i=0;i<12;++i){
        for(int j=0;j<hl[i];++j){
            rFile << static_cast<unsigned char>(header[i][j]);
        }
    }
    cout << "Done";
    return 0;
}
