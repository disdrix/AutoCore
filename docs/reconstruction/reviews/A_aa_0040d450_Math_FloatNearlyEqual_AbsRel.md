# Review A (reconstruction fidelity): `aa_0040d450` Math_FloatNearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d450` |
| **VA** | `0x0040d450`–`0x0040d4ac` |
| **Canonical name** | `Math_FloatNearlyEqual_AbsRel` |
| **Ghidra name** | `FUN_0040d450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-T) |
| **Counterpart** | `reviews/B_aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` |
| **System** | math / float compare |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **absolute + relative** float nearness predicate:

1. Compute `diff = a − b`.
2. If `|diff| ≤ absTol` → return **1**.
3. Else if `|diff| ≤ max(|a|,|b|) × relTol` → return **1**.
4. Else return **0**.

Used by vec3/quat equality helpers and by quaternion normalize to skip work when `lenSq ≈ 1`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d450_FUN_0040d450.md` (+ 2026-07-29 W25-T append) |
| Annotated | `docs/reconstruction/raw/aa_0040d450_FUN_0040d450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_FloatNearlyEqual_AbsRel.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d450.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d450_FUN_0040d450.md` |
| Named record | `docs/reconstruction/functions/aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` |
| Live | decompile ≡ raw; `read_memory` 93 B; `59 C3` epilogue |

---

## 3. Signature (sealed)

```c
// cdecl; 4 stack formals; EAX bool
uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);
```

| Formal | Source | Conf |
|---|---|---|
| a | Stack[0x4] (after push ecx: +8) | **High** |
| b | Stack[0x8] | **High** |
| relTol | Stack[0xC] | **High** |
| absTol | Stack[0x10] | **High** |
| return | EAX 0\|1 | **High** |
| cleanup | `POP ECX; RET` (cdecl) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
diff = a - b
if absTol < |diff|:
  maxAbs = max(|a|, |b|)   // via stack rewrite + pointer
  if maxAbs * relTol < |diff|:
    return 0
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Absolute gate first | **Yes** | **High** |
| max via \|a\| vs \|b\| | **Yes** | **High** |
| Relative gate second | **Yes** | **High** |
| Return 1 default | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (93 B):
```
51d9442408d864240cd9e1d91424d9442414dff1ddd8733ed944240c8d44240cd9e1d95c2414d9442408d9e1d95c240cd9442414d944240cdff1ddd877048d442414f30f1000f30f594424100f2f0424730433c059c3b80100000059c3
```

Epilogues: `33 C0 59 C3` (return 0) / `B8 01 00 00 00 59 C3` (return 1).

---

## 6. Gaps

- Product English / original Torque name (e.g. `mIsEqual`) — residual naming only.
- Runtime FPU CW sensitivity — open.
- Bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, dual-threshold semantics, and caller roles are sealed. Naming is evidence-backed inference. → **accept**.
