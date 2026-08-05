# Review A (reconstruction fidelity): `aa_00513cf0` Item_HasModSlotConfig_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513cf0` |
| **VA** | `0x00513cf0` |
| **Canonical name** | `Item_HasModSlotConfig_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00513cf0`; scaffold Named_CalleeOf… |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00513cf0_Item_HasModSlotConfig_Inferred.md` |
| **System** | inventory-transfer / loot broken-roll gate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Predicate: does this item’s def expose at least one configured mod/option slot?**

```
if item->host[+0xa8]->defBlob[+0x3c] != 0:
  n = FUN_00599dd0(…)   // count of slots != -1 among five fields
  if n > 0: return 1
return 0
```

Used as a **gate on the ~11% broken roll** inside `FUN_00509c70` finish path (with zone/hash check). Also referenced from level-gated loot `FUN_004d4440` and kill-loot `FUN_0050ac80`.

`FUN_00599dd0` (live): counts how many of `+0x498, +0x49c, +0x4a0, +0x4a4, +0x4a8` are not `-1` on its object (returns char count 0..5).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00513cf0_*` |
| Live decompile | Ghidra `0x00513cf0` + helper `0x00599dd0` (2026-07-29) |
| Callers | `FUN_004d4440`, `FUN_00509c70`, `FUN_0050ac80` |
| Related | `Item_SetBroken` `0x00513de0` (broken write after this gate) |

---

## 3. Control flow

```
FUN_00513cf0(item /* ECX */):
  host = *(int*)(item + 0xa8)
  if *(int*)(host + 0x3c) == 0:
    return 0
  n = FUN_00599dd0()          // thiscall/fastcall residual — counts non -1 slots
  if n > 0: return 1
  return 0
```

Boolean return in AL via `undefined4` / low byte (decompiler `return 1` / `return 0`).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` ECX item | **High** | |
| Requires `*(item+0xa8)+0x3c != 0` | **High** | |
| Positive slot count → true | **High** | |
| `00599dd0` counts five `!= -1` fields | **High** | Live helper |
| Used as broken-eligibility gate in `00509c70` | **High** | Call site |
| Exact object passed into `00599dd0` (def vs item) | **Probable** | Decompiler drops ECX arg |
| Product name “mod slot config” | **Probable** | Five optional IDs pattern |
| Fields are specifically “mod” not “dye/skill” | **Tentative** | Offsets only |

---

## 5. Control flow: clean ≡ raw

**Yes** — two-level if, returns 0/1.

---

## 6. Gaps / open

1. Seal ECX into `00599dd0` (def blob vs item vs host+0x3c).
2. Name the five slot fields at `+0x498..+0x4a8`.
3. Confirm all three callers use return as bool the same way.

**Verdict:** Predicate CF **High**. Slot lexicon residual. **accept-with-gaps.**
