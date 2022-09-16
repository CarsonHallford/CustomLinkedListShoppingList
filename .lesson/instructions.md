# Instructions  

The purpose of this project is to let you implement your own `LinkedList` class and use it in your shopping list program.

The input/output/tests are all exactly the same as the previous shopping list project.

## Recommended steps

**Note: depending on how you implemented the Shopping List assignment, these steps may not work exactly. Critical thinking is required.**

First, I would copy your Grocery class from the Shopping List assignment to this assignment.

Define the `LinkedList`, `Iterator`, and `Node` classes from the definitions given in the slide deck. Stub out each function, so that it does nothing. Create a `LinkedList<Grocery>` and make sure the code compiles, the tests run, and the tests fail.

**Note: I recommend defining these in a separate `linked_list.h` file so that it can be used for multiple assignments. Use templates if you can.**

Temporarily, hardcode `LinkedList::insert()` so that it always inserts at the head, then hardcode a couple of insertions to test it out. Use the debugger to ensure that the insert works.

Implement `LinkedList::begin()` and `Iterator::end()`.

Implement `LinkedList::operator++()` and `Iterator::operator->()` and ensure you can iterate over every item in the list and print out the value.

Implement `LinkedList::erase()` and ensure you can remove groceries from the list.

Copy your shopping list logic from the previous assignment to your `main.cpp`, and replace the usage of `std::list` with your `LinkedList` and `Iterator`.

Run the tests, and debug if anything fails.

## Running

Click the `Run` button at the top of repl.it.

## Testing

Click the checkmark in the left sidebar, then click `Run tests`.

## Style

Make sure your code conforms to the style guide by running:
```
bash scripts/style.sh
```

If you need to fix your style, run:
```
bash scripts/style.sh fix
```