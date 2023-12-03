#include "TStack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_without_argument)
{
	EXPECT_NO_THROW(TStack<int> st);
}

TEST(TStack, can_create_stack_with_positive_length)
{
	EXPECT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st1(5);
	EXPECT_NO_THROW(TStack<int> st2(st1););
}

TEST(TStack, copy_constructor_works_correct)
{
	TStack<int> st1(5);
	TStack<int> st2(st1);
	EXPECT_EQ(true, (st1 == st2));
}

TEST(TStack, throw_when_create_stack_with_negative_length)
{
	EXPECT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, throw_when_create_stack_with_big_length)
{
	EXPECT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, getMemSize_works_correct)
{
	TStack<int> st(5);
	EXPECT_EQ(5, st.getMemSize());
}

TEST(TStack, getSize_works_correct)
{
	TStack<int> st(5);
	EXPECT_EQ(0, st.getSize());
}

TEST(TStack, isEmpty_works_correct)
{
	TStack<int> st(5);
	EXPECT_EQ(true, st.isEmpty());
}

TEST(TStack, throw_when_try_to_getTop_if_isEmpty)
{
	TStack<int> st(5);
	EXPECT_ANY_THROW(st.getTop());
}

TEST(TStack, throw_when_try_to_pop_if_isEmpty)
{
	TStack<int> st(5);
	EXPECT_ANY_THROW(st.pop());
}

TEST(TStack, push_adds_element)
{
	TStack<int> st(5);
	st.push(1);
	EXPECT_EQ(1, st.getTop());
}

TEST(TStack, can_push_when_stack_is_full)
{
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	EXPECT_NO_THROW(st.push(6));
}

TEST(TStack, push_adds_element_when_stack_is_full)
{
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	EXPECT_EQ(6, st.getTop());
}