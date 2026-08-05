# Review A (reconstruction fidelity): `aa_005b3110` VehicleNet_SkillsHBNodeVector_Push_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3110` |
| **VA** | `0x005b3110` |
| **Canonical name** | `VehicleNet_SkillsHBNodeVector_Push_Inferred` (was `FUN_005b3110`) |
| **Ghidra symbol** | `FUN_005b3110` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b3110_VehicleNet_SkillsHBNodeVector_Push_Inferred.md` |
| **System** | input-drive-control / GhostVehicle SkillsMask pack |
| **Parent** | `VehicleNet_PackOwnerSkillsHB` `0x005b2830` ← PackUpdate |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Push one 0xC-byte node record** onto a growable vector used while collecting active skill/HB entries during PackOwnerSkillsHB.

Layout of vector object (`this`):

| Offset | Field |
|---|---|
| `+0x04` | begin pointer |
| `+0x08` | end / write cursor |
| `+0x0c` | capacity end |

CF:

```
if (begin != 0) AND (end-begin)/0xC < (cap-begin)/0xC:
  FUN_00538710(end, 1, value, this, value)   // in-place construct at end
  end += 0xC
else:
  FUN_005b30a0(&value, end, value)           // reallocate / insert path
```

Element stride **0xC** matches parent count formula `(end-begin)/0xC` as u8 wire count.

**Caller:** only `FUN_005b2830`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b3110` |
| Callers | `get_function_callers` → `FUN_005b2830` |
| Raw / clean | `raw/aa_005b3110_*`, `FUN_005b3110.cpp` |
| Parent dual | `A_aa_005b2830_VehicleNet_PackOwnerSkillsHB.md` |

---

## 3. Signature

```c
void __thiscall SkillsHBNodeVector_Push(Vector12 *this, void *nodeOrPtr /*param_2*/);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Stride 0xC vector push | **High** |
| Cap-full → grow helper `0x005b30a0` | **High CF** |
| Parent uses result for SkillsMask count | **High** (parent dual) |
| Element payload English fields | **Low** residual |
| Full body of grow helpers | **Open** (out of unit) |

**Verdict:** **accept-with-gaps**
