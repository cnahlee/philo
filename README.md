# 🧠 Philosophers - 42 School Project

> “I never thought philosophy would be so deadly.”

This project is a simulation of the classical **Dining Philosophers Problem** using **C** and **POSIX threads (pthreads)**.  
It demonstrates **multi-threading**, **mutex synchronization**, and **deadlock avoidance** — all while trying to prevent virtual philosophers from starving to death 🥄🍝💀.

---

## 📜 Subject Summary

You must write a program that simulates philosophers who:
- Eat 🍝
- Sleep 😴
- Think 🤔

To eat, a philosopher must hold **two forks** (represented by mutexes), one on the left and one on the right.  
The goal is to **avoid deadlocks**, **synchronize threads safely**, and **end the simulation properly** under different conditions.

---

## 🧪 How to Run

```bash
make            # Build the project
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
