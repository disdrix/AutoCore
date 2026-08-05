# Review A (reconstruction fidelity): `aa_0058ab60` Rng_CloneSeededTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058ab60` |
| **VA** | `0x0058ab60` |
| **Canonical name** | `Rng_CloneSeededTable_Inferred` (was `FUN_0058ab60`) |
| **Review date** | `2026-07-29` (dual A/B — wave3 skills helper) |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated to decompile + RNG singleton layout + callers) |
| **Counterpart** | `reviews/B_aa_0058ab60_Rng_CloneSeededTable_Inferred.md` |
| **System** | `skills-abilities` (primary consumers: HB ctor / skill apply / cast spawn; RNG is global) |
| **Verdict** | **accept-with-gaps** (behavior + ABI + sizes **sealed**; product C++ name open → `_Inferred`) |

---

## 1. Purpose

**Seeded clone of a fixed-size window out of the global MT-backed RNG word table.**

1. `operator_new[](0x4b0)` → heap buffer of **300 dwords** / **600 ushorts** / **1200 bytes**.
2. `CVOGReaction_RandomUnitScalar()` → global RNG singleton `&DAT_00d20c1c`.
3. Write `param_1` into singleton **cursor** at `+0x0C` (seed index).
4. Wrap: if `cursor + 600 > 0xFFFFF`, force `cursor = 0` (room for 600 ushorts in a 0x100000-ushort table).
5. Source byte address = `*(singleton+0x08) + cursor * 2` (ushort-index → byte offset into 2 MiB table).
6. Copy **300** dwords source → heap.
7. `cursor += 1` (global side effect for later unseeded draws).
8. Return heap pointer (caller owns; free with `operator_delete[]` / `operator_delete__`).

Not a pure function: mutates the global RNG cursor. Not identity / no-op (HB ctor residual already falsified that).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058ab60_FUN_0058ab60.md` |
| Annotated | `docs/reconstruction/raw/aa_0058ab60_Rng_CloneSeededTable_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_CloneSeededTable_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058ab60_Rng_CloneSeededTable_Inferred.md` |
| RNG accessor | `CVOGReaction_RandomUnitScalar` @ `0x007a4330` → `&DAT_00d20c1c` |
| Table fill | `FUN_007a4200` @ `0x007a4200` — `new[] 0x200000`, fill `0x80000` tempered u32, cursor `+0x0C=0` |
| MT helpers | `FUN_00424890` (init 624× `0x6c078965`), `FUN_004248c0` (twist `0x9908b0df`) |
| HB owner | `CVOGHBSkillBase_ctor` @ `0x005788d0` — `arg7 → +0x6a8`; clone → `+0x6a0` |
| Live Ghidra | `decompile_function` `0x0058ab60` / `0x007a4330` / `0x007a4200` / `0x00424890` / `0x004248c0`; `get_function_callers`; `get_xrefs_to`; `get_assembly_context`; `analyze_function_complete`; `read_memory` `DAT_00d20c1c` (BSS zeros static) |
| Scratch | `tmp/a_0058ab60.md` |

**Live re-decompile + singleton chain + caller asm performed** (not review-from-scaffold-only).

---

## 3. Signature (sealed)

```c
// __cdecl  (asm: PUSH seed; CALL; ADD ESP,4; result in EAX)
std::uint32_t* /* heap: 0x4b0 bytes, often read as uint16_t* */ Rng_CloneSeededTable_Inferred(
    std::uint32_t seedIndex);  // written to RNG singleton +0x0C before clone
// returns: non-null expected; no null-check on new[] in body
```

| Item | Sealed |
|---|---|
| Stack arg count **1** | **Confirmed** (`ADD ESP,4` at all sampled call sites) |
| Return in **EAX** | **Confirmed** |
| Convention **cdecl** | **Confirmed** |
| Alloc size **`0x4b0`** | **Confirmed** |
| Copy count **300** dwords | **Confirmed** |
| Wrap threshold **`0xFFFFF`** with **`+600`** | **Confirmed** |
| Source scale **`cursor * 2`** (ushort index) | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| VA body @ `0x0058ab60` | **Confirmed** | live decompile ≡ raw |
| Alloc `0x4b0` via `operator_new[]` | **Confirmed** | decompile + callee list |
| Singleton via `CVOGReaction_RandomUnitScalar` → `DAT_00d20c1c` | **Confirmed** | callee decompile |
| Singleton `+0x08` = table base (`uint8_t*` / word stream) | **Confirmed** | `FUN_007a4200` writes `operator_new__(0x200000)` there |
| Singleton `+0x0C` = cursor / seed index | **Confirmed** | set from `param_1`; wrap; +1 at end |
| Table size 2 MiB / `0x80000` u32 / `0x100000` ushort capacity | **Confirmed** | fill loop `iVar5 < 0x80000` |
| Wrap ensures 600-ushort headroom | **High** | `cursor+600 > 0xFFFFF` → 0; 600 ushorts = 300 dwords |
| Clone is 600 ushorts viewed as 300 dwords | **Confirmed** | sizes match; consumers cast to `uint16_t*` |
| Global cursor **mutated** (`+1` after copy) | **Confirmed** | even when seed was forced |
| Product C++ / PDB name | **Inferred** | no string/RTTI on unit |
| HB stores clone @ `hb+0x6a0`, seed @ `+0x6a8` | **Confirmed** | asm `0x005789dc` + ctor dual |
| ApplyEffects uses first ushort of slice for accuracy | **Confirmed** | `MOV DX,[EAX]` then `FUN_00553240` |
| Table filled from tempered MT19937 stream | **High** | constants `0x6c078965` / `0x9908b0df` / state 624 |
| English “dice table” product word | Tentative | behavior High; marketing name open |

---

## 5. Callers (xref sealed)

**12** unconditional CALL xrefs (`get_xrefs_to` + asm context):

| Call site | Containing function | Role (brief) |
|---|---|---|
| `0x005789dc` | `CVOGHBSkillBase_ctor` `0x005788d0` | HB path: seed=`arg7` → `+0x6a8`; clone → `+0x6a0` |
| `0x0055396c` | `Skill_ApplyEffectsOnTarget_Inferred` `0x005538a0` | accuracy bit0: first ushort → `FUN_00553240`; free slice |
| `0x0054c789` | `FUN_0054c720` | skill path (seed from stack) |
| `0x006151f9` | `FUN_00615020` | multi-shot / spawn; walks slice as ushort* |
| `0x006189f9` | `FUN_006189d0` | skill HB/list path |
| `0x0061c0c0` | `FUN_0061c090` | skill path (tests skill+0x624 bit0 after) |
| `0x0061cde5` | `FUN_0061cdc0` | skill path |
| `0x0061dfe7` | `FUN_0061dfc0` | skill path |
| `0x0061e2c1` | `FUN_0061e2a0` | skill path |
| `0x0054ef92` | *(unnamed region)* | same push-seed pattern; no Ghidra function symbol |
| `0x0061e909` | *(unnamed region)* | same pattern |
| `0x0061ea62` | *(unnamed region)* | same pattern |

**Named callers via `get_function_callers`:** 9 (the three orphan sites above are extra xrefs without function records).

**Callees:** `operator_new[]` / `operator_new__`, `CVOGReaction_RandomUnitScalar` ×2 (set seed + re-read for wrap/copy).

---

## 6. Control flow: clean ≡ decompile

| Stage | Match |
|---|---|
| `new[](0x4b0)` | **Yes** |
| singleton → write seed `+0x0C` | **Yes** |
| re-get singleton → wrap | **Yes** |
| src = base + seed\*2; 300-dword copy | **Yes** |
| cursor++ ; return buffer | **Yes** |

---

## 7. Dual residual seals (this pass)

### R1 — Not a no-op / identity (HB residual)

| Item | Sealed |
|---|---|
| Allocates heap `0x4b0` | **Confirmed** |
| Copies 300 dwords from seeded ring | **Confirmed** |
| Returns **new** pointer, not `param_1` | **Confirmed** |

### R2 — Index domain is ushort-oriented

| Item | Sealed |
|---|---|
| Scale `* 2` (not `* 4`) | **Confirmed** |
| Wrap headroom **600** matches 300-dword / 600-ushort window | **Confirmed** |
| Consumers treat buffer as `uint16_t*` | **Confirmed** (ApplyEffects, `FUN_00615020`) |

### R3 — HB ctor storage contract

| Item | Sealed |
|---|---|
| `arg7` stored `hb+0x6a8` **before** clone | **Confirmed** (asm order) |
| Clone pointer stored `hb+0x6a0` | **Confirmed** |
| Seed formal is the clone seed | **Confirmed** |

### R4 — Global singleton layout (static)

| Offset | Field | Sealed |
|---|---|---|
| `DAT_00d20c1c + 0x00` | vtbl (`PTR_FUN_00a97168` after init) | **High** (`FUN_007a42d0`) |
| `+0x04` | byte flag (table ready) | **High** |
| `+0x08` | table base ptr | **Confirmed** |
| `+0x0C` | cursor / seed index | **Confirmed** |
| `+0x10` | seed param for rebuild | **High** |
| `+0x14` | MT state object (`0x9c8` alloc) | **High** |

---

## 8. Gaps / open (acceptable)

1. Product / PDB C++ name (keep `_Inferred`).
2. Product English for “dice” vs “rng slice” vs “reaction table”.
3. Orphan call sites `0x0054ef92` / `0x0061e909` / `0x0061ea62` — parent function names.
4. Full consumer glossary of every ushort walk in multi-shot paths (out of unit).
5. Whether `new[]` failure is possible / SEH-covered (body has no null check).
6. Runtime / bit-exact verification of table contents vs MT seed.
7. Owner of free for HB-stored clone (dtor path; not in this unit).

**Verdict:** **accept-with-gaps** — behavior, ABI, sizes, wrap, singleton offsets, and HB storage **sealed**; product name Inferred.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile ≡ raw body | **Pass** |
| Clean CF matches decompile | **Pass** |
| Alloc/copy/wrap constants sealed | **Pass** |
| HB `+0x6a0`/`+0x6a8` sealed | **Pass** |
| Callers catalogued (12 xrefs) | **Pass** |
| Product name not over-claimed | **Pass** (`_Inferred`) |
| Verdict | **accept-with-gaps** |
