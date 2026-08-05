# Review A (reconstruction fidelity): `aa_005d68b0` Math_Float4_IsFiniteIEEE_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d68b0` |
| **VA** | `0x005d68b0` |
| **Canonical name** | `Math_Float4_IsFiniteIEEE_Inferred` (was `FUN_005d68b0`) |
| **Ghidra symbol** | `FUN_005d68b0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of ApplyNetworkPose) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d68b0_Math_Float4_IsFiniteIEEE_Inferred.md` |
| **System** | math / vehicle soft-pose gate |
| **Parent** | `Math_IsNearUnitQuat` `0x00568100` ← soft path `VehicleNet_ApplyNetworkPose` `0x0053eec0` |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

**IEEE-754 finite check on four floats** (quaternion components). For each of 4 dwords:

```
if (word & 0x7f800000) == 0x7f800000:  // exp all-ones → Inf/NaN
  *out = 0; return
*out = 1
```

Does **not** test unit length (parent `0x00568100` does `abs(‖q‖−1) < 0.001` after this passes).

**Caller:** `FUN_00568100` / `Math_IsNearUnitQuat_Inferred` (and possibly other math sites — dual scoped to soft-pose parent).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005d68b0` |
| Callers | `get_function_callers` → `FUN_00568100` |
| Parent dual | `A_aa_00568100_Math_IsNearUnitQuat_Inferred.md` |
| Raw / clean | `raw/aa_005d68b0_*`, `FUN_005d68b0.cpp` |

---

## 3. Signature

```c
void __thiscall Float4_IsFiniteIEEE(float *q /*this*/, uint8_t *outOk);
// *outOk = 1 iff no Inf/NaN in q[0..3]
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Exp mask test `0x7f800000` | **High** |
| Exactly 4 components | **High** |
| Out byte 0/1 | **High** |
| Not unit-length test | **High** (falsified if claimed) |
| Soft rot gate requires this first | **High** (parent dual) |

**Verdict:** **accept**
