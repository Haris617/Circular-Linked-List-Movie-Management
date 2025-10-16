# 🎬 Movie Management System

A C++ implementation of a **circular doubly linked list** for managing movie records with full CRUD operations.

## 📋 Features

- ✅ **Add** new movies to the list
- 🔍 **Search** movies by ID
- 📖 **Display** movies in forward direction
- 📖 **Display** movies in backward direction  
- 🗑️ **Delete** movies by ID
- 🔄 **Circular navigation** - seamless traversal

## 🏗️ Data Structure

**Circular Doubly Linked List**:
- Each node contains:
  - Movie Name
  - Movie ID  
  - Duration
  - Next pointer
  - Previous pointer
- Last node points to head, creating circular structure

## 🎮 Menu Options

1. **Add Movie** - Insert new movie record
2. **Display Forward** - Show all movies from head to tail
3. **Display Backward** - Show all movies from tail to head  
4. **Search Movie** - Find movie by ID
5. **Delete Movie** - Remove movie by ID
6. **Exit** - Close program
