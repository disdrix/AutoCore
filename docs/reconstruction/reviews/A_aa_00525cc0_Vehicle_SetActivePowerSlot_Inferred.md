# Review A (reconstruction fidelity): `aa_00525cc0` Vehicle_SetActivePowerSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525cc0` |
| **VA** | `0x00525cc0` |
| **Canonical name** | `Vehicle_SetActivePowerSlot_Inferred` |
| **Ghidra symbol** | `FUN_00525cc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md` |
| **System** | vehicle skills / power slot (nested from `Vehicle_ActivateEnterWorld` via `setDrivingInputs`) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Vehicle **thiscall** that transitions the **active power / skill slot index** stored at **`vehicle+0xD64`** among values in **`[-1, 2]`** (i.e. −1 clear + three slots 0..2).

### Signature (decompiler)

```c
undefined4 __thiscall FUN_00525cc0(Vehicle* this, int newSlot, char forceFlag);
// returns 0 on reject, 1 on accept/no-op success paths
```

### Early reject → return **0**

- `newSlot < -1` **or** `newSlot > 2`, **or**
- `*(this+0xD64) == newSlot` **and** `forceFlag != 1`  (no-change without force)

### Continent / world gate

Reads MI-adjusted map-ish object at `*( *(this+4)+4 + this + 0xA8 ) + 0x7e` (byte). If **zero**, skip cast teardown/setup and **goto store** `+0xD64 = newSlot` (still returns 1).

### When gate byte non-zero

1. If **current** slot `old = +0xD64` is **not −1**:
   - `key = FUN_0040abd0(old)` → `CNDHash_LookupByKey(hash@ MI+0x74, key)`
   - If skill found: look up active cast binding; if binding TFID ≠ `DAT_009cee98` sentinel:
     - `Skill_SetRankAndReevaluate` + `CVOGReaction_CastSkillOnTarget(...)`
     - If cast result **≠ 0x11**, jump to after-clear without forcing `+0xD64 = −1`
   - Else / on path: set **`+0xD64 = −1`** (clear current)
2. If `newSlot == −1`: **return 1** (cleared only).
3. Lookup skill for `newSlot` via same hash key helper.
   - Missing skill → **return 1** (slot accepted without cast)
   - Found → rank reevaluate + `CastSkillOnTarget`; if cast **≠ 0** return 1 without store; if **0** fall through to store
4. Store **`+0xD64 = newSlot`**, return **1**.

ActivateEnterWorld re-applies current slot with force semantics after regen/recalc (decompiler stack association residual — unit CF sealed independently). Also called from packet path `FUN_008089a0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00525cc0_*`, `reconstructed-exact/FUN_00525cc0.cpp` |
| Function record | `functions/aa_00525cc0_FUN_00525cc0.md` |
| Ghidra | live decompile; callers |
| Related | `Skill_SetRankAndReevaluate`, `CVOGReaction_CastSkillOnTarget`, `CNDHash_LookupByKey` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Slot domain **[-1, 2]** | **High** | First compare |
| Storage **`vehicle+0xD64`** | **High** | All store/load sites |
| forceFlag **1** bypasses same-slot reject | **High** | `param_3 != 1` conjunct |
| Hash key via `FUN_0040abd0(slot)` | **High** CF | Both clear and set paths |
| Cast teardown before set when gate | **High** CF | Structure sealed; result codes partial |
| Cast result **0x11** special on clear | **High** CF / **Tentative** product meaning |
| Map/continent gate at `+0x7e` | **High** CF | Same family flag as equip cast walker |
| Product name “PowerSlot” | **Probable** | 3 slots + −1; not RTTI-proven |
| `unaff_DI` rank arg | **Low / residual** | Decompiler artifact — rank path needs asm seal |

---

## 4. Control flow seal (high level)

```
Vehicle_SetActivePowerSlot_Inferred(v, newSlot, force):
  if newSlot not in [-1,2]: return 0
  if v+0xD64 == newSlot and force != 1: return 0

  if !continent_gate(+0x7e):
    v+0xD64 = newSlot; return 1

  // tear down old skill cast if old != -1
  // if newSlot == -1: return 1 (after clear attempt)
  // set up new skill cast if present
  v+0xD64 = newSlot   // on success paths
  return 1
```

---

## 5. Gaps / open

1. Exact meaning of cast return codes **0** / **0x11** / non-zero.
2. Seal `unaff_DI` / rank operand against asm.
3. Product English for slot (power / stance / ability bar).
4. Full packet caller `008089a0` dual residual.
5. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps**
