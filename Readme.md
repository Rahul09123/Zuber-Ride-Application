# Zuber: A Ride-Sharing Application (Low-Level Design Hackathon Project)

## Table of Contents

1.  [Introduction](#1-introduction)
2.  [Features](#2-features)
3.  [Design Principles & Patterns](#3-design-principles--patterns)
4.  [Project Structure](#4-project-structure)
5.  [How to Compile & Run](#5-how-to-compile--run)
6.  [Known Limitations & Future Enhancements](#6-known-limitations--future-enhancements)
7.  [Authors & Acknowledgements](#7-authors--acknowledgements)

---

## 1. Introduction

Zuber is a simplified ride-sharing application designed as a Low-Level Design (LLD) hackathon project. Its core purpose is to demonstrate robust software architecture, design patterns, and adherence to object-oriented programming principles in building a scalable and maintainable system. The application addresses the fundamental problem of connecting riders with available drivers for on-demand transportation, incorporating features like driver management, ride booking, dynamic fare calculation, and flexible payment processing.

## 2. Features

The Zuber application provides the following core functionalities:

* **Driver Management:** Allows for the addition of new drivers and listing of currently available vehicles/drivers.
* **Ride Request & Acceptance:** Riders can request a ride specifying their preferred vehicle type, and the system attempts to find a matching driver who then "accepts" the ride. As of now Ride is always accepted.
* **Dynamic Fare Calculation:** Computes ride fares based on a base charge and distance, with the ability to apply discounts and surcharges dynamically.
* **Flexible Payment Processing:** Supports various payment methods (e.g., Credit Card, UPI) through an extensible payment system.
* **Notifications:** Provides basic notifications to riders (e.g., ride status, driver arrival) and drivers (e.g., new ride requests, payment received).
* **Ride Creation:** Supports different ride categories such as Bike, SUV, Sedan managed by a factory.
* **Zuber:** It is a orchestartor class which binds the whole application together.

## 3. Design Principles & Patterns

The primary goal of this project was to create extensible and maintainable codebase adhering to key Low-Level Design (LLD) principles and demonstrating the effective use of design patterns.

### Implemented Design Patterns:

- **Singleton Pattern:**
  - **Applied to:** `DriverManager` and `RiderManager`
  - **Why:** Ensures that there is only one instance of the `DriverManager` and `RiderManager` responsible for managing all drivers
    and Riders respectively throughout the application's lifecycle, providing a single point of access and preventing inconsistent states.
- **Decorator Pattern:**
  - **Applied to:** `FareDecorator` hierarchy (`Fare`, `Discount`, `SurplusCharge`)
  - **Why:** Dynamically adds responsibilities (discounts, surcharges) to the base fare calculation (`Fare`) without altering its core structure. This promotes adherence to the Open/Closed Principle, allowing new fare adjustments to be introduced easily.
  There is seperate class for Fare calculation which calculates the fare and gives back to Decorator class.
- **Strategy Pattern:**
  - **Applied to:**
    - `PaymentStrategy` hierarchy (`UpiPaymentStrategy`, `CreditCardPaymentStrategy`)
    - `BookRideStrategy` hierarchy (`BookRideByVehicleStrategy`)
  - **Why:** Defines a family of algorithms (different payment methods, different ride booking approaches), encapsulates each one, and makes them interchangeable at runtime. This allows new payment or booking strategies to be added without modifying the client code.
- **Factory Design Pattern:**
  - **Applied to:** `RideFactory`
  - **Why:** Provides an interface for creating objects (`Ride` types like `BikeRide`, `SuvRide`, etc.) without specifying their concrete classes. This decouples the client (`BookRideByVehicleStrategy`) from the specific implementation details of the `Ride` objects being created.

### Key LLD Principles Demonstrated:

- **Single Responsibility Principle (SRP):** Each class is designed to have a single, well-defined responsibility. For example, `NotificationService` focuses solely on sending notifications, and `PaymentStrategy` handles only payment processing.
- **Open/Closed Principle (OCP):** Illustrated effectively by the Decorator and Strategy patterns, allowing new functionalities (e.g., a new fare type, a new payment gateway, a new booking algorithm) to be introduced by adding new classes without modifying existing, tested code.
- **Encapsulation:** Data members are generally kept private (`private`) and accessed via public getter methods, controlling external access and maintaining data integrity.
- **Modularity & Separation of Concerns:** The project is divided into logical modules (`models`, `services`, `managers`, `strategies`, `factories`,`decorator`), ensuring clear boundaries and reducing inter-module dependencies.

## 4. Compile and Run

Use a C++ compiler
execute the `main.cpp` file
There is one rider already provided.
Create a new rider with available vehicle options - suv ,sedan, bike, carpool.
Available payment options are CreditCard and UPI.

## 5. Known Limitations & Future Enhancements

While demonstrating core LLD principles, this project has certain limitations and areas for future enhancement:

* **Memory Management:** The current implementation relies heavily on raw pointers (new and delete). Manual memory management for dynamically allocated objects (e.g., Driver, Rider, BookRideStrategy, PaymentStrategy, RideFactory, Ride) is not fully robust, leading to potential memory leaks if delete calls are missed.
* **Limited Location:** There are only 26 locations taken from 'a' to 'z' and for 
fare calculations hard coded the logic for each type. So further upgradability
requires some modification in CalculateFare.

* **Total Fare Calculation:** The Fare Calculation are hard coded for simplicity. 


### Feature Expansion:

* More sophisticated driver matching (e.g., by location, real-time availability)with the help of `BookRideStrategy`
* Ride cancellation and dispute resolution.
* Adding More Type of Vehicles. 
* Real-time ride updates with also Schedule Ride for the future time
* A more interactive command-line interface or a graphical user interface.

## 7. Authors & Acknowledgements

Author: Rahul Raman
Development Environment: `C++17, g++`
Special Thanks: To the mentors **_Rohit Negi and Aditya Tandon_** for the LLD Hackathon for providing this valuable learning opportunity.
#### Feedback would be really appreciated
