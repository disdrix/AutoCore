# Review A (reconstruction fidelity): `aa_005b30a0` VehicleNet_SkillsHBNodeVector_InsertOrGrow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b30a0` |
| **VA** | `0x005b30a0` |
| **Canonical name** | `VehicleNet_SkillsHBNodeVector_InsertOrGrow_Inferred` (was `FUN_005b30a0`) |
| **Ghidra symbol** | `FUN_005b30a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills path) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b30a0_VehicleNet_SkillsHBNodeVector_InsertOrGrow_Inferred.md` |
| **System** | input-drive-control / GhostVehicle SkillsMask pack |
| **Parent** | `VehicleNet_SkillsHBNodeVector_Push` `0x005b3110` ← `PackOwnerSkillsHB` `0x005b2830` ← PackUpdate |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Slow path for 0xC-stride vector push:** when the collector vector is empty or at capacity, insert one element via grow helper and rebind an iterator to the inserted slot.

Live CF (`__thiscall` on vector):

```
// this+4 = begin, this+8 = end, this+0xc = capacity end
index = 0
if begin != 0 AND size = (end-begin)/0xC != 0:
  index = (insert_pos - begin) / 0xC
FUN_005b2df0(insert_pos, 1, value)   // insert count=1 (realloc path)
*out_it = begin + index * 0xC
```

**Sole caller:** `FUN_005b3110` (fast path uses `FUN_00538710` when room remains).

**Not** BitStream I/O. **Not** the element layout English fields (opaque 12-byte pack records).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b30a0` |
| Callers | `get_function_callers` → sole `FUN_005b3110` |
| Callees | `FUN_005b2df0` |
| Parent dual | `A_aa_005b3110_VehicleNet_SkillsHBNodeVector_Push_Inferred.md` |

---

## 3. Signature

```c
void __thiscall SkillsHBNodeVector_InsertOrGrow(
  Vec12 *this, int *out_it /*rebind*/, int insert_pos, /*value*/ ...);
// decomp may collapse value as undefined4 / multi-arg
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Cap-full / empty → grow insert of **1** | **High** |
| Stride **0xC** index math | **High** |
| Rebinds `*out_it` to begin+index | **High** |
| Sole caller = Push | **High** |
| Full grow body | **Open** → `0x005b2df0` dual |

**Verdict:** **accept-with-gaps**
