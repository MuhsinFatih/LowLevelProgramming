int mystery(int x, int y) {
  if (x<0)
    x-=y;
  else
    x+=y;

  return x;
}
