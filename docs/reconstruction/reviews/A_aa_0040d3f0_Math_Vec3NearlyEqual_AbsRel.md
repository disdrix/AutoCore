# Review A (reconstruction fidelity): `aa_0040d3f0` Math_Vec3NearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d3f0` |
| **VA** | `0x0040d3f0`–`0x0040d44a` |
| **Canonical name** | `Math_Vec3NearlyEqual_AbsRel` |
| **Ghidra name** | `FUN_0040d3f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-A) |
| **Counterpart** | `reviews/B_aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` |
| **System** | math / vec3 compare |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + call-site context |
| **Verdict** | **accept** |

---

## 1. Purpose

Component-wise **vec3** nearness predicate:

1. For `i = 0,1,2`: if `!Math_FloatNearlyEqual_AbsRel(b[i], a[i], relTol, absTol)` → return **0**.
2. If all three succeed → return **1**.

Used by client code comparing live object position (`+0x90`) against a cached position (`+0x4fc`) with eps ≈ **1e-6**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d3f0_FUN_0040d3f0.md` (+ 2026-07-29 W26-A append) |
| Annotated | `docs/reconstruction/raw/aa_0040d3f0_FUN_0040d3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_Vec3NearlyEqual_AbsRel.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d3f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d3f0_FUN_0040d3f0.md` |
| Named record | `docs/reconstruction/functions/aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` |
| Leaf dual | `Math_FloatNearlyEqual_AbsRel` (W25-T sealed) |
| Live | decompile ≡ raw; `read_memory` 91 B; `RET 8` epilogues |

---

## 3. Signature (sealed)

```c
// ESI = a, EDI = b; stack relTol, absTol; RET 8; EAX bool
uint32_t Math_Vec3NearlyEqual_AbsRel(const float a[3], const float b[3],
                                     float relTol, float absTol);
```

| Formal | Source | Conf |
|---|---|---|
| a | ESI | **High** |
| b | EDI | **High** |
| relTol | Stack[0x4] | **High** |
| absTol | Stack[0x8] | **High** |
| return | EAX 0\|1 | **High** |
| cleanup | `RET 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if !NearlyEqual(b[0], a[0], rel, abs): return 0
if !NearlyEqual(b[1], a[1], rel, abs): return 0
if !NearlyEqual(b[2], a[2], rel, abs): return 0
return 1
```

| Stage | Match | Conf |
|---|---|---|
| 3 sequential component tests | **Yes** | **High** |
| Short-circuit on fail | **Yes** | **High** |
| Sole callee FUN_0040d450 | **Yes** | **High** |
| No globals / no side effects | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (91 B):
```
8b068b0f538b5c240c558b6c240c53555051e84900000083c41084c074368b56048b470453555250e83300000083c41084c074208b4e088b570853555152e81d00000083c41084c0740a5db8010000005bc208005d33c05bc20800
```

Epilogues: `B8 01 00 00 00 5B C2 08 00` (true) / `33 C0 5B C2 08 00` (false), both after `POP EBP`.

---

## 6. Gaps

- Product English / original Torque name — residual naming only.
- Runtime FPU CW / bit-exact differential — open.
- Single known caller; broader use may be inlined elsewhere (not observed as additional xrefs).

---

## 7. Verdict

CF, register+stack ABI, component-wise semantics, and caller role are sealed. Naming is evidence-backed inference from role + leaf. → **accept**.
