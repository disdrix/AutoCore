# Review A (reconstruction fidelity): `aa_0064d900` hkAngularVelocityDamper_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d900` |
| **VA** | `0x0064d900` |
| **Canonical name** | `hkAngularVelocityDamper_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064d900_hkAngularVelocityDamper_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Thin AVD ctor: flag word at +6 = 1, vtable ``PTR_FUN_009e4a68``, copy three floats from desc → +0x08 normalSpinDamping, +0x0c collisionSpinDamping, +0x10 collisionThreshold. Size 0x14. No math.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064d900_hkAngularVelocityDamper_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_0064d900_hkAngularVelocityDamper_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkAngularVelocityDamper_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064d900_hkAngularVelocityDamper_ctor.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064d900` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4a68` | High | Body |
| `Three desc floats +8/+c/+10` | High | Asm/verified |
| `No damping math in ctor` | High | Stores only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| + | 6 |
| Y | e |

---

## 5. Gaps / open

1. None critical; English strings already in verified note.

**Verdict:** accept-with-gaps
