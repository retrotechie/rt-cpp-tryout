<h1 align="center">Finite State Machine</h1>

> Developed in [GCC](https://gcc.gnu.org/)

![Screenshot](./FMS_Screenshot.png)

## Contents

-   [Project Configuration](#1-project-configuration)
-   [Features](#2-features)
-   [Class Diagram](#3-class-diagram)

---

### 1. Project Configuration

-   GCC: 14.0.0

### 2. Features

Navigates between states (`Menu`, `About`, `Exit`).

### 3. Class Diagram

```mermaid
classDiagram
    class AState
        <<Abstract>> AState
        AState : -bool isFinished
        AState : -int nextState
        AState : +AState() constructor
        AState : +setIsFinished(bool) void
        AState : +getIsFinished() int
        AState : +setNextState(int) void
        AState : +getNextState() int
        AState : +update()* virtual
        AState : +render()* virtual

    class CMenu
        CMenu : +CMenu() constructor
        CMenu : +update() virtual override
        CMenu : +render() virtual override

    class CAbout
        CAbout : +CAbout() constructor
        CAbout : +update() virtual override
        CAbout : +render() virtual override

    class CStateManager
        CStateManager : -bool isRunning
        CStateManager : -int state
        CStateManager : -CMenu menu
        CStateManager : -CAbout about
        CStateManager : +CStateManager() constructor
        CStateManager : +setIsRunning(bool) void
        CStateManager : +getIsRunning() int
        CStateManager : +setState(int) void
        CStateManager : +getState() int
        CStateManager : +runState() void
        CStateManager : +updateState() void
        CStateManager : +exitState() void

    CMenu --|> AState: inherits
    CAbout --|> AState: inherits

    CStateManager --> CMenu: implements
    CStateManager --> CAbout: implements
```
