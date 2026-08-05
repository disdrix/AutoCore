# Review A (reconstruction fidelity): `aa_00516a00` Object_RefreshActiveSkillEffects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516a00` |
| **VA** | `0x00516a00` |
| **Canonical name** | `Object_RefreshActiveSkillEffects_Inferred` |
| **Ghidra symbol** | `FUN_00516a00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md` |
| **System** | skills / object activate (nested from `Vehicle_ActivateEnterWorld` via `setDrivingInputs`) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Object **thiscall** that **re-applies / refreshes skill effects** on active skill instances by calling **`FUN_00514e70(skillId)`** for each eligible skill found in two collections:

### Gate: clonebase type early-out

Reads `*(this[0x2a] + 0x38)` (clonebase type id). **Immediate return** for types:

`6, 0xA, 0xC, 0x10, 0x1C, 0x44, 0x46`

Type **`0xE`**: return if `this[0x2b] == 0` (extra null gate).

### Pass 1 — hash / list at `this[0x1c]`

If non-null:

1. Assert/set traversal lock byte `hash+0x1d` (logs `HashError:TraversalLock…` / `VOG_DEBUG_STOP` via `NDError_Log` if already locked or unlocked mid-walk).
2. Walk nodes via `+0x14` chain; skill object at `node+0x8`.
3. For each skill with **`skill+0x615 & 1`** and (`param_2 != 0` **OR** `*(short*)(skill+0x5f6) > 0`):
   - `FUN_00514e70( *(skill+0x5fc) )`  // skill id / token
4. Clear traversal lock.

### Pass 2 — array from vtbl **`+0x1DC`**

Call `this->vtbl[+0x1DC]()` twice (null → return). Walk array at result **`+0x550`..`+0x554`** with **0xC** stride:

- Entry `*(base + i*0xC)` non-null skill*
- Same `+0x615` bit0 + `param_2` / `+0x5f6` filter
- Same `FUN_00514e70(*(skill+0x5fc))`

### `param_2` filter

| `param_2` | Meaning (inferred) |
|---|---|
| **0** | Only skills with **positive** `short +0x5f6` (rank/stack residual) |
| **non-zero** | All skills with active bit `+0x615&1` |

ActivateEnterWorld calls **`FUN_00516a00(0)`** (restrictive filter) when owner present.

Also called from creature post-create, several `FUN_00516be0` / `00517400` / `0053dd40` / `005dac00` paths.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00516a00_*`, `reconstructed-exact/FUN_00516a00.cpp` |
| Function record | `functions/aa_00516a00_FUN_00516a00.md` |
| Ghidra | live decompile; callers list |
| Strings | `HashError:TraversalLock…`, `VOG_DEBUG_STOP` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Type early-out set CF | **High** | Switch cases exact |
| Traversal lock at hash `+0x1d` | **High** | Strings + body |
| Filter `+0x615&1` and `+0x5f6` / `param_2` | **High** CF | Both passes |
| Refresh callee `FUN_00514e70(id@+0x5fc)` | **High** CF | Dual residual for product name |
| Two collection sources (hash + vfunc array) | **High** | Body structure |
| Product names for offsets / type ids | **Tentative** | Layout residual |
| “RefreshActiveSkillEffects” English | **Probable** | Role from CF + enter-world timing |

---

## 4. Control flow seal (sketch)

```
Object_RefreshActiveSkillEffects_Inferred(obj, includeZeroRank):
  t = clonebase_type(obj)
  if t in {6,0xA,0xC,0x10,0x1C,0x44,0x46}: return
  if t == 0xE and obj.field_2b == 0: return

  if hash = obj[0x1c]:
    lock_traverse(hash)
    for skill in hash_nodes:
      if (skill+0x615 & 1) and (includeZeroRank or skill+0x5f6 > 0):
        FUN_00514e70(skill+0x5fc)
    unlock_traverse(hash)

  bag = obj.vtbl[+0x1DC]()
  if !bag: return
  for each 0xC-stride entry in bag[+0x550..+0x554):
    skill = entry.ptr
    if skill && (skill+0x615 & 1) && (includeZeroRank or skill+0x5f6 > 0):
      FUN_00514e70(skill+0x5fc)
```

---

## 5. Gaps / open

1. Dual/name `FUN_00514e70` product semantics (apply effect? re-cast passive?).
2. Clonebase type id product table for early-out set.
3. Why ActivateEnterWorld uses `param_2=0`.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps**
