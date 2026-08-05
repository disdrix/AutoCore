# Review A (reconstruction fidelity): `aa_0076e5e0` Math_QuatNormalize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076e5e0` |
| **VA** | `0x0076e5e0`–`0x0076e6ab` |
| **Canonical name** | `Math_QuatNormalize` |
| **Ghidra name** | `FUN_0076e5e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-B) |
| **Counterpart** | `reviews/B_aa_0076e5e0_Math_QuatNormalize.md` |
| **System** | math / quaternion |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callees/callers |
| **Verdict** | **accept** |

---

## 1. Purpose

4-float quaternion normalize with two skip gates:

1. Compute `lenSq = |in|²`.
2. If `−1e-6 < lenSq < +1e-6` → return `out` unchanged.
3. If `Math_FloatNearlyEqual_AbsRel(lenSq, 1.0, 1e-6, 1e-6)`:
   - `out != in` → copy 4 floats; else no-op.
4. Else `scale = 1/sqrt(lenSq)` and scale **`out[0..3]`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076e5e0_FUN_0076e5e0.md` (+ 2026-07-29 W26-B append) |
| Annotated | `docs/reconstruction/raw/aa_0076e5e0_FUN_0076e5e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_QuatNormalize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076e5e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076e5e0_FUN_0076e5e0.md` |
| Named record | `docs/reconstruction/functions/aa_0076e5e0_Math_QuatNormalize.md` |
| Live | decompile ≡ raw; body 203 B; constants via `read_memory` |
| Peer | `Math_FloatNearlyEqual_AbsRel` (`aa_0040d450`, W25-T) — lists this as skip-normalize caller |

---

## 3. Signature (sealed)

```c
// cdecl; 2 stack pointers; EAX = out
float * Math_QuatNormalize(float *out, float *in);
```

| Formal | Source | Conf |
|---|---|---|
| out | Stack[0x4] | **High** |
| in | Stack[0x8] (`ESI`) | **High** |
| return | EAX = out | **High** |
| cleanup | `POP ESI; RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
lenSq = in·in
if -1e-6 < lenSq < +1e-6: return out
if !FloatNearlyEqual(lenSq, 1, 1e-6, 1e-6):
  scale = 1/sqrt(lenSq); out *= scale
else if out != in:
  out = *in
return out
```

| Stage | Match | Conf |
|---|---|---|
| lenSq from `in` (4 components) | **Yes** | **High** |
| Near-zero band ±1e-6 | **Yes** | **High** |
| Near-unit via `FUN_0040d450` | **Yes** | **High** |
| Scale `out` on miss | **Yes** | **High** |
| Copy on hit + alias | **Yes** | **High** |
| Sole callee `FUN_0040d450` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **203 B** `0x0076e5e0`–`0x0076e6ab`; pad `CC`.

Constants sealed:

| Symbol | VA | Bits | Value |
|---|---|---|---|
| `_DAT_00a240ec` | `0x00a240ec` | `0x358637BD` | ≈ +1e-6 |
| `DAT_00aaa640` | `0x00aaa640` | `0xB58637BD` | ≈ −1e-6 |
| one imm / `g_flOne` | push / `0x00a0f2a0` | `0x3F800000` | 1.0f |
| tol imm | stack pushes | `0x358637BD` | ≈ 1e-6 |

Prologue: `PUSH ESI; mov esi, [esp+0xC]` (`in`). Near-equal call: four stack args + `ADD ESP,0x10`. Normalize path: `FLD lenSq; FSQRT; FDIVR [g_flOne]; FMUL/FSTP` on `out`.

---

## 6. Gaps

- Product English / original Torque name — residual naming only.
- Runtime FPU CW / MXCSR bit-exact — open.
- Out-of-place (`out != in`) non-unit path scales `out` without prior copy — machine fact; typical callers pass identical pointers.

---

## 7. Verdict

CF, ABI, constants, and near-unit skip linkage to `Math_FloatNearlyEqual_AbsRel` are sealed. → **accept**.
