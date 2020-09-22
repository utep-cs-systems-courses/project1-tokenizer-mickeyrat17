#include <stdio.h>
#include <stdlib.h>

/*Return true (non-zero) if c is whitespace character
  Zeroterminators are not printable (therefore false) */
int space_char(char c)
{
  if(c == '\t' || c == ' ')
    return 1;
  return 0;
}

/*returns true (non-zero) if c is a non-whitespace char
  Zero terminators are not printable (therefore false)*/
int non_space_char(char c)
{
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  return 1;
}

/*returns pointer to first char of next space sperated word
  return zero pointer if str doesn't contain any words */
char *word_start(char *str)
{
  if(str == NULL)
    return NULL;

  int i = 0;
  while(space_char(str[i]))
    i++;

  return str+i;
}

/*returns pointer to terminator char for *word*/
char *word_terminator(char *word)
{
  if(word == NULL)
    return NULL;
  word = word_start(word);

  int i = 0;
  while(non_space_char(word[i]))
    i++;

  return word+i;
}

/*counts number of words in the str argument*/
int count_words(char *str)
{
  if(str == NULL || str == "" || str == "\0")
    return 0;

  int count = 0;
  while (str[0] != '\0')
  {
    if(word_start(str)[0] == '\0')
      break;
    str = word_terminator(str);
    count++;
  }
  return count;
}
