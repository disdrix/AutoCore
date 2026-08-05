# Review A (reconstruction fidelity): `aa_0052ade0` CVOGCharacter_SetMissionCounterMax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ade0` |
| **VA** | `0x0052ade0` |
| **Body** | `0x0052ade0`–`0x0052ae21` inclusive (**66 B** / `0x42`) |
| **Canonical name** | `CVOGCharacter_SetMissionCounterMax_Inferred` |
| **Ghidra symbol** | `FUN_0052ade0` |
| **Review date** | `2026-08-04` (W37-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md` |
| **System** | `missions-progression` (mission-adjacent) |
| **Live tools** | `batch_decompile`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Hit-only write of Val12 mapped **`node+0x10`** for character map @ **`+0x584`**, clamped to **`node+0x14`**, with dirty **`+0x634 |= 0x40`**. Miss = no-op (no insert). Inferred "max" from debug slash help pairing with SetMissionCounter.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.md` (+ W37-P append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_SetMissionCounterMax_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_0052ade0.cpp` |
| Live decompile | ≡ 2026-07-23 raw CF |
| Live body bytes | full 66 B via `read_memory` |
| Sibling duals | SetMissionCounter W30-I; AddMissionCounter; lower_bound `00418b80` |
| Caller dual | `Client_DebugCmd_AddDisciplinePoints` W31-T |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body span | inclusive end `0052ae21`; 66 B; pad `CC` |
| this → ESI | `8B F1` |
| Map | `8D 8E 84 05 00 00` → `+0x584` |
| Find | rel32 → `00418b80` |
| End compare | `3B 86 88 05 00 00` → `+0x588`; `JE` skip |
| Store +0x10 | `89 50 10` |
| Clamp | `8B 48 14; 3B D1; JLE; 89 48 10` |
| Dirty | `83 8E 34 06 00 00 40` → `+0x634 \|= 0x40` |
| Epilog | `5E 59 C2 08 00` → **ret 8** |

Full body hex (66 B):

```
51568bf18d44240c508d4c2408518d8e84050000e887ddeeff8b4424043b868805000074188b5424108950108b48143bd17e03894810838e34060000405e59c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size | **pass** (66 B) |
| thiscall + ret 8 | **pass** |
| Miss no-op (no operator[]) | **pass** |
| +0x10 write + clamp to +0x14 | **pass** |
| Dirty 0x40 | **pass** |
| "Max" product English | **gap** (inferred) |
| Dual-field policy with Get/Set | **gap** |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full hex |
| Hit-only +0x10 | **High** | |
| Dirty bit 0x40 | **High** | family uses other bits too |
| Name Max | **Inferred** | slash help only |
| Runtime | Open | |

---

## 6. Gaps

1. Product demangle; confirm "max" vs other +0x10 English.  
2. Why Get reads +0x10 while Set writes +0x14 — sync policy open.  
3. No non-debug callers found; production path may be elsewhere or unused.  
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
