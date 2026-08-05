# Function record: CVOGObjectiveRequirement_Collect_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611940` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Eval` |
| **Prior name** | `FUN_00611940` |
| **Address** | `0x00611940` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (+ inventory-transfer CountItems bridge) |
| **Calling convention** | MSVC `__thiscall` + **two stack dwords**; `RET 8` |
| **Completion status** | **Human-refined** — dual residual + CountItems bridge sealed 2026-07-29 (strengthen) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Return progress fraction in `[0,1]` for a **Collect** objective from **live cargo inventory**:

```
min(1.0, InventoryGrid_CountItemsByCbid(cargo, itemCbid, /*includeBroken*/0) / NumToCollect)
```

Does **not** read objective-state slot floats (unlike UseItem/Kill Eval). Server absolute Collect progress remains S2C `0x2071`.

## Signature

```c
// Shared Eval family: two stack dwords (RET 8). Collect uses character only.
float10 __thiscall CVOGObjectiveRequirement_Collect_Eval(
    void* this,          // ECX — Collect requirement
    int character,       // stack0 — cargo host (char+0x250)
    void* objState);     // stack1 — unread here (UseItem/Kill use for slot floats)
```

Domain return is f32 in `[0,1]`; decompiler `float10` = x87 ST0 return after SSE math.

## Offsets

| Offset | Field | Evidence |
|-------:|-------|----------|
| req `+0x10` | item CBID | XML `CBID` @ `0x00611a00`; Count arg |
| req `+0x14` | NumToCollect | XML `NumToCollect`; divisor; **0 → return 1.0** |
| character `+0x250` | vehicle / cargo host ptr | body load |
| host `+0x2b0` | `InventoryGrid*` cargo | same type-1 grid as DropResponse |

## Control flow

```
if NumToCollect==0: return 1.0
if no vehicle or no cargo grid: return 0.0
count = CountItemsByCbid(cargo, cbid, includeBroken=0)   // CALL @ 0x00611972
if (float)count / (float)NumToCollect >= 1.0: return 1.0  // COMISS; equality completes
count = CountItemsByCbid(cargo, cbid, includeBroken=0)   // CALL @ 0x006119a3 (incomplete only)
return (float)count / (float)NumToCollect
```

SSE (`CVTSI2SS` / `DIVSS` / `COMISS` / `MOVSS`) does the ratio; x87 `FLD` returns ST0.

## CountItems bridge (sealed)

| Item | Value | Confidence |
|------|-------|------------|
| Callee | `InventoryGrid_CountItemsByCbid` `aa_005711c0` / `0x005711c0` | **High / Confirmed** |
| this (ECX) | cargo grid | **High / Confirmed** |
| itemCbid | req+0x10 | **High / Confirmed** |
| includeBroken | **0** both CALL sites | **High / Confirmed** |
| Broken bit19 | excluded (Count residual) | **High** |
| Double CALL | real; 2nd iff ratio &lt; 1 | **High / Confirmed** |
| Sibling pattern | SlotAction `0x006124b0` also double-counts when incomplete | **High** |

Rel32 seal (body re-read 2026-07-29 strengthen):

| Site | VA | Bytes | Target |
|------|-----|-------|--------|
| 1st | `0x00611972` | `E8 49 F8 F5 FF` | `0x005711c0` |
| 2nd | `0x006119a3` | `E8 18 F8 F5 FF` | `0x005711c0` |

## Vtable + class

| Item | Value | Confidence |
|------|-------|------------|
| Collect vtable | `PTR_FUN_009e12c4` | **High** |
| Eval slot | **+0x10** → `0x00611940` (DATA xref `0x009e12d4`) | **High / Confirmed** |
| Action slot | +0x04 → `0x00611f20` | **High** |
| SlotAction slot | +0x18 → `0x006124b0` | **High** |
| type code | ctor `= 2` | **High** |
| Static CODE callers | none (virtual only) | **High** |

Vtable LE dword at `+0x10`: `40 19 61 00` → `0x00611940` (`read_memory` 2026-07-29).

## Family ABI contrast

| Formal | UseItem / Kill Eval | Collect Eval |
|--------|---------------------|--------------|
| ECX this | requirement | requirement |
| stack0 | unused | **character** (cargo) |
| stack1 | **objective state** (slot floats) | unused |
| Epilogue | `RET 8` | `RET 8` |

## Constants

| Label | VA | Bytes LE | f32 |
|-------|-----|----------|-----|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** |
| `g_flZero` | `0x00a0f518` | `00 00 00 00` | **0.0** |

## Residual seal (2026-07-29 strengthen)

| Residual | Status | Evidence |
|---|---|---|
| Stack ABI `RET 8` / character=stack0 | **Sealed High** | body bytes re-read |
| stack1 unread family formal | **Sealed High** | no load; sibling Eval |
| Double Count calls | **Sealed High** | CALL VAs + SlotAction isomorph |
| Count ECX + includeBroken=0 | **Sealed High** | asm + Count residual |
| COMISS equality completes | **Sealed High** | `JBE` when 1.0 ≤ ratio |
| g_flOne / g_flZero | **Sealed High** | `read_memory` |
| Inventory vs 0x2071 authority | **Sealed** dual-path | body + missionHandler |
| Runtime / differential | Open | needs live capture |

Scratch: `reviews/a_00611940.md`. Duals: A/B this date.

## Confidence

| Claim | Level |
|---|---|
| Cargo path `char+0x250+0x2b0` | **High / Confirmed** |
| Count callee + framing | **High / Confirmed** |
| Fraction semantics + clamp | **High / Confirmed** |
| Shared two-stack Eval ABI | **High / Confirmed** |
| Name Collect_Eval | **High** (layout/RTTI); PDB open |
| Runtime / bit-exact | Open |

## Related

- Deserialize: `aa_00611a00`
- Count: `aa_005711c0` (+ residual `a_005711c0.md`)
- SlotAction (same live count, UI string): `aa_006124b0`
- Action (event/loot, not fraction): `aa_00611f20`
- Dual A/B: `reviews/A_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md`, `reviews/B_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md`
- Residual: `reviews/a_00611940.md`
- Chain: `reviews/CHAIN_2026-07-29_inventory_collect.md`
- Clean: `reconstructed-exact/CVOGObjectiveRequirement_Collect_Eval.cpp`
- Experiment: `experiments/inventory_collect_bridge.py`
