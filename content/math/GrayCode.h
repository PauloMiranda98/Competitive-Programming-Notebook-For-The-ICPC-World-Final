/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
int grayCode(int nth){
  return nth ^ (nth >> 1);
}
int revGrayCode(int g){
  int nth = 0;
  for (; g > 0; g >>= 1)
    nth ^= g;
  return nth;
}