#include <project.h>
#include "replies.h"

static char	*s = NULL;

static int	is_the_same(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (s1 == s2);
	return (strcmp(s1, s2) == 0);
}

static void	iter_fn(void *data, int i)
{
	printf("  params[%i]:  %s\n", i, data);
}

#define tokenizer_test(num, input, _servername, _nick, _user, _host, _command, num_param, debug)\
static void	test_## num(t_test *test) \
{ \
	t_rpl_cnt	*content = rpl_tokenizer_tokenize(input); \
	if (debug) { \
		printf("=====> tokenize(\"%s\")\n", input); \
		printf("  servername: %s(%s)\n", content->servername, _servername); \
		printf("  nick:       %s(%s)\n", content->nick, _nick); \
		printf("  user:       %s(%s)\n", content->user, _user); \
		printf("  host:       %s(%s)\n", content->host, _host); \
		printf("  command:    %s(%s)\n", content->command, _command); \
		vector_iteri0(content->params, iter_fn); puts("}"); \
	} \
	mt_assert(is_the_same(content->servername, _servername)); \
	mt_assert(is_the_same(content->nick, _nick)); \
	mt_assert(is_the_same(content->user, _user)); \
	mt_assert(is_the_same(content->host, _host)); \
	mt_assert(is_the_same(content->command, _command)); \
	mt_assert(vector_len(content->params) == num_param); \
	reply_del(content); \
}

tokenizer_test(num01, ":aaa cmd aa bb :cc dd\r\n", "aaa", s, s, s, "cmd", 3, false);
tokenizer_test(num02, ":a!b@c cmd aa bb :cc dd\r\n", s, "a", "b", "c", "cmd", 3, false);
tokenizer_test(num03, "cmd aa bb :cc dd\r\n", s, s, s, s, "cmd", 3, false);
tokenizer_test(num04, ":b@c cmd\r\n", "b@c", s, s, s, "cmd", 0, false);
tokenizer_test(num05, ":a@c!b cmd\r\n", s, "a@c", "b", s, "cmd", 0, false);

void		suite_tokenizer_test(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
}
