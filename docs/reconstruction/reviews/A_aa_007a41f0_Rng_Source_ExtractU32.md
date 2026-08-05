# Review A (reconstruction fidelity): `aa_007a41f0` Rng_Source_ExtractU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a41f0` |
| **VA** | `0x007a41f0` |
| **Body** | `0x007a41f0`–`0x007a41f7` (7 bytes) |
| **Canonical name** | `Rng_Source_ExtractU32` |
| **Prior scaffold** | `FUN_007a41f0` |
| **Review date** | `2026-07-29` (W21-L dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007a41f0_Rng_Source_ExtractU32.md` |
| **System** | RNG / MT19937 |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Minimal **thiscall adapter**: pull `Mt19937State*` from **`source+0x14`**, tail into sealed **`Rng_Mt19937_Extract`**. Used by loot catalog roll helpers as the integer RNG step.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x007a41f0` (collapses load) |
| Bytes | `read_memory` 7 B body — `8B 41 14 E9 …` |
| Bounds | `get_function_by_address` `007a41f0`–`007a41f7` |
| Callee | `get_function_callees` → `00424830`; rel32 target verified |
| Callers | `get_function_callers` → `005e1030`, `005e1150` only |
| Sibling | decompile `007a4200` (same +0x14 MT field) |
| Extract | sealed `aa_00424830` Rng_Mt19937_Extract |
| Raw / clean | `aa_007a41f0_*`, `Rng_Source_ExtractU32.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **7 bytes** | **Confirmed** | bounds + hex |
| `mov eax,[ecx+0x14]` | **Confirmed** | `8B 41 14` |
| Tail jmp to `0x00424830` | **Confirmed** | rel32 math |
| Extract = sealed MT temper | **Confirmed** | dual-sealed callee |
| Returns u32 in EAX | **High** | extract contract |
| Not a vector indexer | **Confirmed** | no second arg / no scale |
| Decompiler omits +0x14 | **Confirmed residual** | must prefer bytes |
| Product class name | **Inferred** | source object |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `[this+0x14]` | Yes in bytes/clean; **missing** in raw decompile text |
| Tail to extract | Yes (clean may show call for readability) |
| No extra math | Yes |

---

## 5. Gaps / open

1. Product English name of source class / field at +0x14.
2. Loot parent selection math (index = f(u32, count)) — **out of owned scope**.
3. Runtime / differential against retail RNG stream.
4. Table-path vs live-extract policy (`007a4200` buffer).

**Verdict:** **accept**
