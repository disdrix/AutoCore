# Review A (reconstruction fidelity): `aa_004ff350` Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff350` |
| **VA** | `0x004ff350` |
| **Canonical name** | `Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred` |
| **Ghidra symbol** | `FUN_004ff350` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md` |
| **System** | vehicle equip / enter-world (nested from `setDrivingInputs` → `Vehicle_ActivateEnterWorld`) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Vehicle **thiscall** walker that applies one of two equip-path helpers to **every occupied equipment slot**:

| `param_2` (byte / char) | Per-item callee |
|---|---|
| **0** | `Vehicle_ClearItemGfxBindings` `0x004fbb50` |
| **non-zero** | `Vehicle_CastItemSkillsOnEquip` `0x004fdcb0` |

**Slots visited (in order):**

1. **3 hardpoints** at `*(vehicle+0x260)` offs `{0,4,8}` (null-skip)
2. **Vehicle self** via multi-inherit adjust `*( *(vehicle+4)+4 ) + 4 + vehicle`
3. **`vehicle+0x254`** if non-null (same MI adjust on the item)
4. **`vehicle+0x268`** if non-null
5. **`vehicle+0x26c`** if non-null — **also** `Vehicle_ApplyItemStatusHooksOnEquip` `0x004fe380(item, param_2)`
6. **`vehicle+0x270`** if non-null — **also** `FUN_004fe380(item, param_2)`
7. **Turret `vehicle+0x264`** if non-null (clear or cast only; **no** status-hooks twin)

Caller of note: `Vehicle_ActivateEnterWorld` `0x00503f30` with **`param_2=1`** when map flag `+0x7e != 0` (cast path on enter). Also called from `FUN_00502380`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004ff350_*`, `reconstructed-exact/FUN_004ff350.cpp` |
| Function record | `functions/aa_004ff350_FUN_004ff350.md` |
| Callee duals | `A_aa_004fbb50_Vehicle_ClearItemGfxBindings`, `A_aa_004fdcb0_Vehicle_CastItemSkillsOnEquip`, `A_aa_004fe380_*` |
| Parent | `Vehicle_ActivateEnterWorld` / chain from `Vehicle_setDrivingInputs` `0x00504c70` |
| Ghidra | `decompile_function` @ `0x004ff350`; callers |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = vehicle thiscall; stack `param_2` bool-ish | **High** | Decompile + ActivateEnterWorld `FUN_004ff350(1)` |
| Hardpoint loop 3× via `+0x260` | **High** | Same table family as fire walkers |
| Branch 0 → clear gfx; else → cast skills | **High** | Named dual callees |
| Self + 0x254/268/26c/270/264 coverage | **High** CF | Body enumerates all |
| Status hooks only on **0x26c** and **0x270** | **High** | Only those arms call `004fe380` |
| Turret has no status-hooks call | **High** | Tail only clear/cast |
| MI adjust `*( *(obj+4)+4 ) + 4 + obj` | **High** CF | Repeated pattern; product type residual |
| Slot English names (armor/PP/…) for +0x254.. | **Probable / Tentative** | Layout residual |
| Product method name | **Probable** | `_Inferred` |

---

## 4. Control flow seal

```
Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred(vehicle, doCast):
  fn = doCast ? CastItemSkillsOnEquip : ClearItemGfxBindings
  for off in {0,4,8}:
    w = *( *(vehicle+0x260) + off )
    if w: fn( MI_adjust(w) )
  fn( MI_adjust(vehicle) )                    // self always
  for slot in {+0x254, +0x268}:
    if *slot: fn( MI_adjust(*slot) )
  for slot in {+0x26c, +0x270}:
    if *slot:
      item = MI_adjust(*slot)
      fn(item)
      ApplyItemStatusHooksOnEquip(item, doCast)
  if turret = *(vehicle+0x264):
    fn( MI_adjust(turret) )
```

Clean scaffold ≡ raw ≡ live decompile CF.

---

## 5. Callers / callees

| Direction | Addr | Role |
|---|---|---|
| Caller | `Vehicle_ActivateEnterWorld` `0x00503f30` | Enter with cast=1 when map+0x7e |
| Caller | `FUN_00502380` | Equip/related path |
| Callee | `0x004fbb50` clear gfx | doCast==0 |
| Callee | `0x004fdcb0` cast skills | doCast!=0 |
| Callee | `0x004fe380` status hooks | slots +0x26c / +0x270 only |

---

## 6. Gaps / open

1. Name product fields for +0x254 / +0x268 / +0x26c / +0x270 / +0x264.
2. Exact MI-adjust type (Item* subobject).
3. Why enter-world only casts when map `+0x7e`.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps**
