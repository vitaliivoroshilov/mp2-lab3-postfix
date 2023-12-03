#include "Postfix.h"
#include <gtest.h>

TEST(Postfix, can_create_postfix_without_argument)
{
	EXPECT_NO_THROW(Postfix p);
}

TEST(Postfix, can_create_postfix_with_argument)
{
	EXPECT_NO_THROW(Postfix p("1+2*3-4/2"));
}

TEST(Postfix, can_create_postfix_with_spaces_in_argument)
{
	EXPECT_NO_THROW(Postfix p("1 + 2 * 3 - 4 / 2"));
}

TEST(Postfix, GetInfix_works_correct)
{
	Postfix p("1+2*3-4/2");
	EXPECT_EQ(p.GetInfix(), "1+2*3-4/2");
}

TEST(Postfix, GetPostfix_works_correct)
{
	Postfix p("1+2*3-4/2");
	EXPECT_EQ(p.GetPostfix(), "123*+42/-");
}

TEST(Postfix, GetPostfix_works_correct_with_spaces_in_argument)
{
	Postfix p("1 + 2 * 3 - 4 / 2");
	EXPECT_EQ(p.GetPostfix(), "123*+42/-");
}

TEST(Postfix, Calculate_works_correct)
{
	Postfix p("1+2*3-4/2");
	EXPECT_EQ(p.Calculate(), 5);
}

TEST(Postfix, Calculate_works_correct_with_spaces_in_argument)
{
	Postfix p(" 1 + 2 * 3 - 4 / 2");
	EXPECT_EQ(p.Calculate(), 5);
}