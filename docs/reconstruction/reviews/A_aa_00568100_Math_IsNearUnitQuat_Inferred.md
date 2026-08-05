# Review A (reconstruction fidelity): `aa_00568100` Math_IsNearUnitQuat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568100` |
| **VA** | `0x00568100` |
| **Canonical name** | `Math_IsNearUnitQuat_Inferred` (was `FUN_00568100`) |
| **Ghidra symbol** | `FUN_00568100` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00568100_Math_IsNearUnitQuat_Inferred.md` |
| **System** | math / vehicle soft-pose gate |
| **Dual status** | **Present** |
| **Verdict** | **accept** — unit-length gate sealed |

---

## 1. Purpose

Boolean gate used by soft network apply before writing **rotation** into the soft buffer:

1. Call validity helper `FUN_005d68b0` on the quat pointer (finite/non-nan style residual).
2. If valid **and** `abs(‖q‖ − 1) < 0.001` (`_DAT_009d2f1c`) → write **1** to out byte.
3. Else write **0**.

Non-unit wire quaternions are **dropped** from soft buffer rot (pos/vel/ω still apply in parent).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00568100` |
| Raw | `raw/aa_00568100_FUN_00568100.md` |
| `read_memory` | `_DAT_009d2f1c` @ `0x009d2f1c` → **≈0.001** |
| Parent | soft path of `FUN_0053eec0` |

---

## 3. Body

```c
// framing: decomp shows thiscall-ish; used as (quat*, outByte*)
void IsNearUnitQuat(float *q, uint8_t *outOk) {
  float *tmp = q;
  FUN_005d68b0(&tmp);           // validity → result in low byte of tmp
  if ((char)tmp != 0
      && fabsf(sqrtf(q[0]*q[0]+q[1]*q[1]+q[2]*q[2]+q[3]*q[3]) - 1.0f)
         < 0.001f) {
    *outOk = 1;
    return;
  }
  *outOk = 0;
}
```

**Note:** parent soft path decompile calls `FUN_00568100(&local_21)` and reads `*pcVar4` — ABI of out-byte vs return residual, but **predicate** is sealed.

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| ‖q‖−1 threshold 0.001 | **High** |
| Requires FUN_005d68b0 pass | **High** |
| Soft rot write gated by this | **High** (parent) |
| Hard path also gates | **Falsified** (hard writes rot blindly) |

**Verdict:** **accept**
