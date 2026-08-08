# Function record: WorldClock_GetQuarterPhase01_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553dd0` |
| **Canonical name** | `WorldClock_GetQuarterPhase01_Inferred` |
| **Ghidra name** | `FUN_00553dd0` |
| **Address** | `0x00553dd0`–`0x00553f30` (**352 B**) |
| **Module** | `autoassault.exe` (base `0x400000`) |
| **System** | environment / world clock |
| **Dual** | A/B **accept-with-gaps** (WQ9D-J 2026-08-04) |
| **Bit-for-bit / runtime** | Open |

## Purpose

```
if clock[+0x24] != -1.0f: return clock[+0x24]
secOfHour = localtime(now - clock.i64[+0x160]).(min*60+sec)
phase = (secOfHour - quarterOffset[clock[+0x154]]) * (1/900)
// + sub-second from g_dwClientTickMs when same second
return clamp(phase, 0, 1)
```

Quarter offsets: 0, 900, 1800, 2700 seconds. **Not** skill accuracy (distinct from `aa_00553240`).

## Signature

```c
float __fastcall WorldClock_GetQuarterPhase01_Inferred(void *clock /*ECX*/);
```

## See also

Scaffold `aa_00553dd0_FUN_00553dd0.md`; dual A/B; clean `WorldClock_GetQuarterPhase01_Inferred.cpp`; sibling `FUN_00553cd0` (`+0x15c` getter).
