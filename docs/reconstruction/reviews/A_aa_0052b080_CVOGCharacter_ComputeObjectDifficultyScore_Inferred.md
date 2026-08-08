# Review A (reconstruction fidelity): `aa_0052b080` CVOGCharacter_ComputeObjectDifficultyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b080` |
| **VA** | `0x0052b080`–`0x0052b13b` |
| **Canonical name (Ghidra)** | `FUN_0052b080` |
| **Proposed name** | `CVOGCharacter_ComputeObjectDifficultyScore_Inferred` |
| **Review date** | `2026-08-05` (R13-035 OWN-ONLY dual A; dual start 2686) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0052b080_CVOGCharacter_ComputeObjectDifficultyScore_Inferred.md` |
| **System** | `skills-abilities` (partition parent VA `0x0052b040`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character **`__thiscall`** leaf that returns a **float difficulty score** for a target world/UI object:

1. Null-check `target` and `target+0xa8`.
2. Read clone base `*(*(target+0xa8)+0x3c)`; take **type id** `@+0x4ac` and **required** `@+0x4b0`.
3. Exact/lower-bound find type id on **`character+0x584`** via `FUN_00418b80`; player value = `node+0x10` or **−1** if end `character+0x588`.
4. Score:
   - player < required → **0.0**
   - player == required → **100.0** (`DAT_00aaa7ac`)
   - gap = player − required; gap > **15** (`DAT_00aaa7a4`) → **0.0**
   - else → **100 − gap × 6** (`DAT_00aaa8dc`)

Sole direct consumer: dualed `UI_FormatObjectDifficultyTier_Inferred` (`0x008e4430`) ladder {90,70,50,30,0} → Very Hard…Trivial (Impossible uses a separate `GetResourceBalanceByType` compare).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0052b080` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/disasm) |
| Assembly | `disassemble_function` (body through all `RET 4`; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 192 B @ entry — body + `CC` pad before `FUN_0052b140` |
| Constants | `read_memory` @ `0x00aaa7ac` / `0x00aaa8dc` / `0x00aaa7a4` / `0x00a0f518` |
| Callers / xrefs | `get_function_callers name=FUN_0052b080` (1) + `get_xrefs_to` (1 UNCONDITIONAL_CALL) |
| Call site | `disassemble_function` @ `0x008e4430` site `0x008e4484` (`MOV ECX,[DAT_00d1b6d8]; PUSH target; CALL; FSTP`) |
| Callee | `decompile_function` @ `FUN_00418b80` |
| Sibling | dualed `CVOGCharacter_GetResourceBalanceByType` (`aa_0052ada0`) — same map, int return |
| Parent UI dual | `aa_008e4430` / W29J (context only) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` for `aa_0052b080` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledger edits, other VAs.

---

## 3. Signature

```c
float __thiscall CVOGCharacter_ComputeObjectDifficultyScore_Inferred(
    void *character /* ECX */,
    void *targetObject /* stack0 */);
// RET 4; float on x87 ST0
```

| Item | Evidence |
|---|---|
| Convention | entry `MOV EDI,ECX`; all three exits `RET 4` (`C2 04 00`) |
| Call site cleanup | caller pushes 1 arg; no `ADD ESP` (callee cleans) |
| This = character | call site `MOV ECX,[DAT_00d1b6d8]`; map `LEA ECX,[EDI+0x584]` |
| Stack = object* | used as pointer (`[EAX+0xa8]`); decompiler `float` is wrong |
| Return | `FLD` then `RET 4`; caller `FSTP` |
| Body size | 188 B (`0xBC`); pad `CC` before `0x0052b140` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null target / null `+0xa8` → 0.0 via `g_flZero` | **Yes** |
| Load required `@+0x4b0`, type `@+0x4ac` from clone | **Yes** |
| Map find on `character+0x584` via `FUN_00418b80` | **Yes** |
| Miss → player −1; hit → `node+0x10` | **Yes** |
| player < required → 0.0 | **Yes** |
| player == required → 100.0 | **Yes** |
| gap > 15 → 0.0; else 100 − 6·gap | **Yes** |
| thiscall + RET 4 + float ST0 | **Yes** (asm overrides decompiler noise) |

### Layout (sealed)

| Off | Role |
|----:|------|
| `character+0x584` | resource/currency ordered-map header |
| `character+0x588` | map end sentinel |
| `target+0xa8` → `+0x3c` | clone base pointer chain |
| `clone+0x4ac` | resource type id (key) |
| `clone+0x4b0` | required amount |
| `node+0x10` | player balance value |
| `DAT_00aaa7ac` | 100.0f base |
| `DAT_00aaa8dc` | 6.0f per-overlevel |
| `DAT_00aaa7a4` | 15.0f max gap |
| `0x00a0f518` (`g_flZero`) | 0.0f |

### Call-site sample

| Site | Args | Follow-on |
|---|---|---|
| `0x008e4484` `FUN_008e4430` | ECX=`DAT_00d1b6d8` (global character), stack=target object | `FSTP` score; separate `GetResourceBalanceByType` for Impossible; tier by score vs 90/70/50/30/0 |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + score formula | **High** | disasm + constant floats |
| ABI thiscall + RET 4 + ST0 float | **High** | entry + all rets + call site |
| Map/clone field offsets | **High** | immediates |
| Role = difficulty score for UI tier | **High** | sole caller + prior dual context |
| Product method English | **Open** | `_Inferred` hygiene |
| Full resource-type schema | **Open** | only type/required pair sealed |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB character method English.  
2. Formal type names for `clone+0x4ac` / `+0x4b0` beyond dualed UI “requirement” pairing.  
3. Whether gap>15 → 0.0 (same numeric as under-level) is product-intended (UI still gates Impossible separately).  
4. Runtime Confirmed / differential / live balances.  
5. `FUN_00418b80` full dual not OWN (find helper shared with resource balance).

**Verdict:** **accept-with-gaps** — CF/ABI/constants/domain High; product English + runtime open.
