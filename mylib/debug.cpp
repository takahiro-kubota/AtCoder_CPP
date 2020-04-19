void prvll(vvll& mp) {
  printf("    ");
  for (size_t j = 0; j < mp[0].size(); j++)
    printf("%4lu%c", j, ((j == mp[0].size() - 1) ? '\n' : ' '));
  for (size_t i = 0; i < mp.size(); i++) {
    printf("%2lu: ", i);
    for (size_t j = 0; j < mp[i].size(); j++)
      printf("%4lld%c", mp[i][j], ((j == mp[i].size() - 1) ? '\n' : ' '));
  }
  cout << endl;
}