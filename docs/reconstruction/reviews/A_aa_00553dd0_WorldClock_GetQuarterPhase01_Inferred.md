# Review A (reconstruction fidelity): `aa_00553dd0` WorldClock_GetQuarterPhase01_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553dd0` |
| **VA** | `0x00553dd0`–`0x00553f30` |
| **Canonical name (Ghidra)** | `FUN_00553dd0` |
| **Proposed name** | `WorldClock_GetQuarterPhase01_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-J OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00553dd0_WorldClock_GetQuarterPhase01_Inferred.md` |
| **System** | environment / world clock |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return a **normalized [0,1] phase** for the current **15-minute quarter** of the hour on a world-clock object. Used by env light/audio blend (`FUN_004912c0`), not by skill accuracy.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x00553dd0` |
| Bytes | `read_memory` entry (`8B F1`, `ucomiss` vs `-1.0`) + constants |
| Globals | `audit_globals_in_function` — `g_dwClientTickMs`, `g_flMsToSeconds_Inferred`, `g_flOne` |
| Callers | sole `FUN_004912c0` |
| Sibling | `FUN_00553cd0` = load `this+0x15c` only |
| Raw / annotated / clean | `docs/reconstruction/*` for `aa_00553dd0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
float __fastcall WorldClock_GetQuarterPhase01_Inferred(void *clock /*ECX*/);
// bare ret; result on x87 ST0
```

| Item | Evidence |
|---|---|
| ECX this | `8B F1` at entry |
| Cache field | `this+0x24` vs `DAT_00aaa668` = **-1.0** |
| Mode field | `this+0x154` switch 0..3 |
| Time base | int64 at `this+0x160` / `+0x164` |
| Scale | `DAT_00aaace0` ≈ **1/900** (`b4a2913a`) |
| Offsets | 900 / 1800 / 2700 f32 confirmed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Cache hit when +0x24 ≠ -1 | Yes |
| time64 − base → localtime | Yes |
| secOfHour = sec + min*60 | Yes |
| switch 0..3 subtract quarters | Yes |
| × 1/900 | Yes |
| Sub-second tick blend + wrap 2^32 | Yes |
| Clamp [0,1] | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Phase math 15-min quarters | **High** | constants + scale |
| Cache sentinel -1.0 | **High** | bytes + global |
| Sole env caller | **High** | 1 xref |
| Not skill accuracy unit | **High** | different body; only shared global -1.0 |
| Product class English | **Tentative** | `_Inferred` |
| Server vs wall-clock base | **Open** | `+0x160` source unknown |

---

## 6. Gaps / open

1. Product/PDB symbol for clock class.  
2. Who writes `+0x24` cache and `+0x160` base.  
3. Mode 0..3 product labels (dawn/day/dusk/night vs pure quarter index).  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — math/ABI High; product English open.
