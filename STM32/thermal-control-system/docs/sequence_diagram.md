```mermaid
sequenceDiagram
    participant Main
    participant HAL_ADC
    participant Filter
    participant StateMachine
    participant Safety
    participant PID
    participant PWM
    participant Logger
    participant Watchdog

    Main->>HAL_ADC: Read temperature
    HAL_ADC-->>Main: raw temp

    Main->>Filter: Smooth signal
    Filter-->>Main: filtered temp

    Main->>StateMachine: Update state
    StateMachine-->>Main: system state

    Main->>Safety: Check faults
    Safety-->>Main: OK / FAULT

    alt System OK
        Main->>PID: Compute output
        PID-->>Main: PWM value
        Main->>PWM: Set duty cycle
    else Fault
        Main->>PWM: Set 0%
    end

    Main->>Logger: Store telemetry
    Main->>Watchdog: Kick watchdog
