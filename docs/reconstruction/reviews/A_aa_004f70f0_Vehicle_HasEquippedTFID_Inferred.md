# Review A (reconstruction fidelity): `aa_004f70f0` Vehicle_HasEquippedTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f70f0` |
| **VA** | `0x004f70f0` |
| **Canonical name** | `Vehicle_HasEquippedTFID_Inferred` (Ghidra `FUN_004f70f0`) |
| **Ghidra name** | `FUN_004f70f0` |
| **Prior alias** | `Named_CalleeOf_Named_VOGClient_004f70f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md` |
| **System** | vehicle equip / inventory destroy residual |
| **Live tools** | `batch_decompile`, callees, CompletelyDestroyObject parent |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Predicate: does this vehicle currently hold an equipped object matching TFID `(hi, lo)`?**

```c
// __thiscall  → bool-as-int
int Vehicle_HasEquippedTFID_Inferred(Vehicle *this, int tfid_a, int tfid_b);
```

Returns **1** if any of the following matches both TFID dwords at object dual-base `+0x164/+0x168`; else **0**.

### Match sources

| Source | Offsets on vehicle | Notes |
|---|---|---|
| Weapon-mount helper | `FUN_004f5680(tfid_a, tfid_b)` | Scans `this+0x260` array **3** slots (indices 0..2); returns mount ptr or 0 |
| Race item / mod | `+0x270` | Same TFID fields via dual-base |
| Equip slot | `+0x26c` | |
| Equip slot | `+0x268` | |
| Equip slot | `+0x258` (600) | |
| Equip slot | `+0x254` | |
| Equip slot | `+0x264` | |

Match rule per non-null slot object `obj`:

```
base = *( *(obj+4) + 4 )
(base + 0x164 + obj) == tfid_a  &&  (base + 0x168 + obj) == tfid_b
```

**Production use:** CompletelyDestroyObject (`FUN_009440e0`) — when destroying a non-vehicle object with a parent at `obj+0x2b`, if parent's equip set contains the destroyed TFID → `FUN_00504f60` unequip/cleanup path. Also skill range resolve (`Skill_RangeCheckTargetForResolveList_Inferred`) and UI `FUN_00944d50`.

Garage UI (`FUN_008801b0`) binds the **same** slot offsets (`+0x260` weapons, `+0x270` race kit, `+0x26c`…`+0x254`) — strong equip-layout seal.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004f70f0` ≡ raw |
| Mount helper | `FUN_004f5680` (3-slot `+0x260` scan) |
| Parent destroy | `FUN_009440e0` |
| Garage slot map | `FUN_008801b0` |
| Raw / clean | `raw/aa_004f70f0_*`, `reconstructed-exact/FUN_004f70f0.cpp` |

---

## 3. Control flow

```
if FUN_004f5680(a,b) != 0 → return 1
for each slot in {0x270,0x26c,0x268,0x258,0x254,0x264}:
  if slot != null && TFID match → return 1
return 0
```

Decompiler emits a single giant `if` of ANDed negatives ending in `return 0` else `return 1` — same predicate.

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| TFID compare at `+0x164/+0x168` | **Confirmed** |
| Includes 3 weapon mounts via `004f5680` | **Confirmed** |
| Slot set matches garage UI offsets | **High** |
| Returns bool 0/1 only | **Confirmed** |
| Product slot English names | **Probable** (garage strings for mounts/kits; residual) |
| Does **not** modify equip state | **Confirmed** |

**Verdict:** **accept-with-gaps.**
