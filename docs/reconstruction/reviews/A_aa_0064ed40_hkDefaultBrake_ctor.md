# Review A (reconstruction fidelity): `aa_0064ed40` hkDefaultBrake_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064ed40` |
| **VA** | `0x0064ed40` |
| **Canonical name** | `hkDefaultBrake_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064ed40_hkDefaultBrake_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Brake ctor (size 0x54): base ``FUN_0065e2d0``, vtbl ``PTR_FUN_009e4cb8``, init three empty hkArrays (maxTorque / minPedal / handbrake-connect), grow each to wheel count *desc, then ``FUN_0064e840`` deep-copy. Verified ``fn_0064ed40_brakeCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064ed40_FUN_0064ed40.md` |
| Annotated | `docs/reconstruction/raw/aa_0064ed40_FUN_0064ed40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064ed40.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064ed40_FUN_0064ed40.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064ed40` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4cb8` | High | Body |
| `Grow rule max(cap*2,n) via FUN_005b3300` | High | Three grow loops |
| `Elem sizes 4/4/1` | High | Grow calls |
| `FUN_0064e840 final copy` | High | Callee |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. minTimeToMaxTorque scalar path via copy residual.
2. Handbrake connect bool semantics.

**Verdict:** accept-with-gaps
