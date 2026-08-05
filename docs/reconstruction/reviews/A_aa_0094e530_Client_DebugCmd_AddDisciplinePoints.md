# Review A (reconstruction fidelity): `aa_0094e530` Client_DebugCmd_AddDisciplinePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094e530` |
| **VA** | `0x0094e530`–`0x0094e617` exclusive (**231 B**) |
| **Canonical name** | `Client_DebugCmd_AddDisciplinePoints` |
| **Ghidra symbol** | `FUN_0094e530` |
| **Review date** | `2026-07-29` (W31-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md` |
| **System** | missions-progression / client debug slash |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Debug slash-command handler registered as **`adddisciplinepoints`**:

1. Continue `strtok(NULL, delim)` → `atoi` key; missing → return **1**.
2. Continue → `atoi` amount; missing → return **1**.
3. Optional third token → flag = (`atoi == 1`).
4. Require `*(client+0xe98)` character.
5. `CVOGCharacter_SetMissionCounter(char, key, amount)` (W30-I sealed absolute `+0x14` set).
6. If flag: `FUN_0052ade0(char, key, amount)` sets mapped `+0x10` (max) clamped to `+0x14`, dirty `char+0x634 |= 0x40`.
7. If `client+0x1074` UI active (`vtbl+0x3d8`) → `vtbl+0x448` refresh.
8. Return **0**.

Help plate seals intent: `"Set discipline [x] to [y], [1] to set max as well"`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.md` |
| Annotated | `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_DebugCmd_AddDisciplinePoints.cpp` |
| Twin | `reconstructed-exact/FUN_0094e530.cpp` |
| Function records | `functions/aa_0094e530_*` |
| Live decompile | Ghidra @ `0x0094e530` |
| Live body bytes | full 231 B via `read_memory` |
| Nested dual | `A/B_aa_005305b0_CVOGCharacter_SetMissionCounter` (W30-I) |
| Registration | `Client_RegisterDebugSlashCommands` imm + strings |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `SUB ESP,8; PUSH ESI; MOV ESI,[ESP+0x14]` (delim) |
| strtok IAT | `MOV EDI,[0x009c6684]; PUSH delim; PUSH 0; CALL` |
| atoi IAT | `MOV EBP,[0x009c667c]` |
| Fail returns | `MOV EAX,1; ... RET 8` (`C2 08 00`) |
| Char gate | `MOV ECX,[ESI+0xe98]; TEST ECX` |
| SetMissionCounter | `PUSH amount; PUSH key; CALL 0x005305b0` with ECX=char |
| Optional max | `TEST BL; JZ; MOV ECX,[ESI+0xe98]; PUSH amount; PUSH key; CALL 0x0052ade0` |
| UI | `[ESI+0x1074]` → `CALL [vtbl+0x3d8]` / `[vtbl+0x448]` |
| Success | `XOR EAX,EAX; ... RET 8` |
| Body end | exclusive `0x0094e617` (pad `CC`) |
| Command name | `"adddisciplinepoints"` @ `0x00a2bd08` |
| Help | `"Set discipline [x] to [y], [1] to set max as well"` @ `0x00a2bd1c` |

Full body hex: raw W31-T (231 B).

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (`0094e617`, 231 B) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=client | **pass** |
| strtok×3 + atoi | **pass** |
| Set then optional max | **pass** |
| Registration string bind | **pass** |
| Clean typed path | **pass** |
| Product key-domain catalog | **gap** |
| Stack[0x4] unused role | **gap** (documented) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full body hex; ret 8 |
| Command plate | **High** | literal strings + register imm |
| SetMissionCounter integration | **High** | W30-I callee sealed |
| Flag → max `+0x10` | **High** | help + `FUN_0052ade0` CF |
| Product English | **Inferred** | slash name / help only |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle / full discipline key catalog.  
2. Exact identity of stack formal 0 (unused).  
3. `FUN_0052ade0` product English (not OWN; CF observed only).  
4. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
