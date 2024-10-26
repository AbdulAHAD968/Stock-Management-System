# 📦 Inventory Management System Using Binary Search Tree

This project implements an **Inventory Management System** using a Binary Search Tree (BST) in C++. Designed for a warehouse setting, the BST stores items based on unique item IDs, allowing efficient stock management, price queries, and bulk data handling.

## 🚀 Features and Requirements

The project consists of four main tasks, each addressing crucial aspects of warehouse inventory management.

---

### 🧩 Task 1: Basic Inventory Operations.

Each node in the BST represents an item with attributes including:
- **item_id**: Unique integer (key for BST).
- **item_name**: Product name (string).
- **item_description**: Description of the item.
- **quantity**: Units available in stock.
- **price**: Price per unit.

#### Operations
1. **Insert an Item**: Adds a new item to the inventory, maintaining BST structure using `item_id`.
2. **Search for an Item**: Retrieves item details using `item_id`.
3. **Delete an Item**: Removes an item from the inventory based on `item_id`.
4. **Update Item Information**: Allows updating the quantity and price of an item by searching via `item_id`.

---

### 📊 Task 2: Stock Management Operations.

1. **Check Stock Availability**: Verifies if an item is in stock and returns its quantity.
2. **Low Stock Alert**: Lists items with fewer than 3 units, enabling proactive restocking.
3. **Restock Item**: Allows restocking an item by adding a specified quantity to the existing amount.

---

### 💰 Task 3: Price and Range Queries.

1. **Find Items within a Price Range**: Returns items within a specified price range `[min_price, max_price]`.
2. **Find the Cheapest Item**: Finds and returns the item with the lowest price.
3. **Find the Most Expensive Item**: Finds and returns the item with the highest price.

---

### 📂 Task 4: Bulk Insertions and Updates from CSV.

The system supports bulk data operations from a CSV file, with each entry including item information. 
- **Existing Items**: If the item exists, updates attributes if values differ.
- **New Items**: Adds new items if not found in the tree.

---

## 📜 System Requirements

- **Programming Language**: C++
- **Data Structure**: Binary Search Tree (BST)

---

## 🛠️ Setup and Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/InventoryManagementBST.git

2. Command for execution:
   ```bash
   g++ 23i-2014_B.cpp [To compile]
   ./a.out or ./a.exe [To Execute]
   
## ⚠️ Errors and Omissions

If you encounter any errors, bugs, or have suggestions for improvements, feel free to reach out to me.

You can contact me via email at: [ahad06074@gmail.com](mailto:ahad06074@gmail.com)

## 💬 Let's Connect!

I’m open to **collaborative projects** in cybersecurity, programming, or **knowledge-sharing** initiatives. Feel free to reach out if you’d like to discuss ideas or explore ways we can work together.

- **LinkedIn**: [linkedin.com/in/abdul-ahad-988305286](https://www.linkedin.com/in/abdul-ahad-988305286)
- **Email**: [ahad06074@gmail.com](mailto:ahad06074@gmail.com)

Looking forward to connecting!
