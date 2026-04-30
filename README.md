# CplusplusFinalProject
We will be completing the default project as assigned by our professor. Here is the project outline and expectations:

Basic Information The purpose of this project is to create a simple program to handle inventory and customer transactions for a store. Different objects sold by this store will have their own associated name, cost, and stock. Customers can choose items to purchase and the program will keep track of their ‘cart’. When the customer wishes to check out, they will be told how much their transaction will cost and the store will update its stock. Items which are out of stock will not be available for purchase by customers.

Minimal Viable Product [70pts] The minimum viable product of this project will satisfy the following criteria:

At least eight (8) different types of item* are available to purchase. Each item has an associated name, price, and number available (stock)

At the main menu of your program, the user can choose from the following options (let them enter a number): a) Add an item to their cart (allow the user to type the name of the item they want to purchase) b) View the items in their cart c) View all items (and their prices and stock) available for purchase d) Check out (print a receipt of all items purchased and the total cost to the user) e) Exit the program

The program loops the main menu until the user enters '5' to exit

The entire program must compile and run to completion without any unhandled exceptions. This includes protection against a malicious user trying to break the program.

The entire program must be free of infinite loops, crashes, segmentation faults, or other undesirable behaviors

*You must utilize arrays! Don't use individual variables like item1, item2, etc. when an array could be used instead.

Stretch Goals [30pts] Any 3 Stretch Goals can be delivered for full credit. 10pts per Stretch Goal, up to 3.
You must make note in your submission comments which stretch goals were attempted (simply writing the numbers is sufficient, for example "attempted stretch goals #1, 2, 4, and 6")

Allow the cart to resize dynamically to grow or shrink to fit the size of its contents (hint: research the vector (https://cplusplus.com/reference/vector/vector/.) class)

Allow the user to remove items from their cart (either present them a numbered list or allow them to remove an item by name)

Allow the user the option of sorting their cart from the most expensive item to the least

Suppose your store restocks every Tuesday. If the user attempts to purchase an item which is out of stock, print out the number of days until it will be in stock again (hint: you'll need to get the system time, research the time (https://cplusplus.com/reference/ctime/time/) reference)

Suppose your store is closed for at least three (3) holidays every year. Choose any three dates, they can be entirely fictional holidays. When the program starts, check the date (see the time (https://cplusplus.com/reference/ctime/time/) reference). If it's a holiday, print that the store is currently closed and to come back tomorrow.

Include the sales tax for at least 5 states in your program (these can be fictional). When the user checks out, prompt them for their state of residence and apply the applicable sales tax to their total.

When the user checks out, print their receipt to a .txt file as well as the console (hint: research the ofstream (https://cplusplus.com/reference/ostream/ostream/) class)

Instead of hard-coding the store's inventory into your program, read it in and parse it at runtime (hint: research the ifstream (https://cplusplus.com/reference/fstream/ifstream/) class)

Utilize a switch (https://en.cppreference.com/w/cpp/language/switch.html) when implementing your main menu instead of an if/else chain

Safeguard your program against ANY input the user enters- malicious or otherwise. Attempting this stretch goal with negate the assumption in MVP #4- I will actively attempt to break your program by doing everything short of modifying the code itself. For example, entering text when a number was requested.
