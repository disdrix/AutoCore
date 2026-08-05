# Review A (reconstruction fidelity): `aa_00416260` Math_QuatNearlyEqual_DoubleCover

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416260` |
| **VA** | `0x00416260`–`0x0041634e` |
| **Canonical name** | `Math_QuatNearlyEqual_DoubleCover` |
| **Ghidra name** | `FUN_00416260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-A) |
| **Counterpart** | `reviews/B_aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` |
| **System** | math / quaternion compare |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + call-site context |
| **Verdict** | **accept** |

---

## 1. Purpose

Quaternion nearness with **double-cover** acceptance:

1. If all of `(w,x,y,z)` of `b` nearly equal corresponding components of `a` → return **1**.
2. Else if all of `(w,x,y,z)` of `b` nearly equal corresponding components of **`-a`** → return **1**.
3. Else return **0**.

Each component uses sealed `Math_FloatNearlyEqual_AbsRel`. Caller uses **0.002f** for both tols when comparing object quats at `+0x590` vs `+0x5e0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00416260_FUN_00416260.md` (+ 2026-07-29 W26-A append) |
| Annotated | `docs/reconstruction/raw/aa_00416260_FUN_00416260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_QuatNearlyEqual_DoubleCover.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416260.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416260_FUN_00416260.md` |
| Named record | `docs/reconstruction/functions/aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` |
| Leaf dual | `Math_FloatNearlyEqual_AbsRel` (W25-T sealed) |
| Live | decompile ≡ raw; `read_memory` 239 B; `RET 8` epilogues |

---

## 3. Signature (sealed)

```c
// ESI = a, EDI = b; stack relTol, absTol; RET 8; EAX bool
// layout xyzw: [0]=x [1]=y [2]=z [3]=w
uint32_t Math_QuatNearlyEqual_DoubleCover(const float a[4], const float b[4],
                                          float relTol, float absTol);
```

| Formal | Source | Conf |
|---|---|---|
| a | ESI → float[4] | **High** |
| b | EDI → float[4] | **High** |
| relTol / absTol | stack; `RET 8` | **High** |
| return | EAX 0\|1 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
// Path 1 order: w, x, y, z
if NearlyEqual(b[3],a[3]) && NearlyEqual(b[0],a[0])
   && NearlyEqual(b[1],a[1]) && NearlyEqual(b[2],a[2]): return 1
// Path 2: negate a components (SSE zero - a[i])
if NearlyEqual(b[3],-a[3]) && NearlyEqual(b[0],-a[0])
   && NearlyEqual(b[1],-a[1]) && NearlyEqual(b[2],-a[2]): return 1
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Positive 4-comp path | **Yes** | **High** |
| Negative double-cover path | **Yes** | **High** |
| w-first component order | **Yes** | **High** |
| Sole callee FUN_0040d450 ×8 | **Yes** | **High** |
| Same ABI family as vec3 helper | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (239 B) stored in raw append; epilogues match vec3 family (`POP EBP; {MOV EAX,1|XOR EAX,EAX}; POP EBX; RET 8`). Negative path uses `0F 57 C0` (`XORPS`) + `F3 0F 5C` (`SUBSS`) + `F3 0F 11 04 24` (`MOVSS [esp],…`) before each leaf call.

---

## 6. Gaps

- Product English / original name — residual naming only.
- Axis labels (x/y/z/w) are conventional for float[4] with w at [3]; no product string.
- Runtime bit-exact — open.

---

## 7. Verdict

CF (including double-cover), ABI, component order, and caller role are sealed. Naming is evidence-backed inference. → **accept**.
