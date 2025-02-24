# Warehouse and Delivery Management System

## Introduction

This project is a warehouse and delivery management system that facilitates the purchase and delivery of various types of products. The system manages customers, couriers, manufacturers, and warehouses while ensuring smooth order fulfillment. It operates similarly to Amazon by enabling the shipment of diverse products through different delivery companies.

## System Structure

The system consists of the following main components:

### 1. Customer

- Address
- Available credit for purchases
- Linked list of purchased products

### 2. Courier

- Unique identifier
- Average rating
- Array of all received ratings
- Number of deliveries completed
- Delivery time per order

### 3. Delivery

- Specific courier handling the delivery
- Delivery company responsible
- Delivery date
- List of products being shipped
- Associated customer

### 4. Delivery Company

- Name of the company
- Number of couriers
- Operating regions

### 5. Manufacturer

- Unique identifier
- Name
- Types of products manufactured

### 6. Warehouse

- Responsible for managing stored products and deliveries
- Stores manufacturers and their products
- Stores delivery companies and their couriers
- Number of manufacturers, delivery companies, and products

## Product Types

The warehouse supports various product categories, including:

- Electronics
- Furniture
- Clothing
- Books
- Beauty products
- Sports equipment
- Toys

## Features

- Efficient tracking of available credits for customer purchases
- Management of delivery assignments to couriers
- Organization of multiple delivery companies handling shipments
- Integration of manufacturers producing various product types
- Optimized warehouse storage and shipment processes

## How to Use

1. Add new manufacturers and define their product types.
2. Store products in the warehouse and link them to the respective manufacturers.
3. Manage customer purchases and track available credits.
4. Assign deliveries to couriers based on location and availability.
5. Rate couriers based on delivery performance.

