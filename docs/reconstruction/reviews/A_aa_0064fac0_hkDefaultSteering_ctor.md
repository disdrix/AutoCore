# Review A (reconstruction fidelity): `aa_0064fac0` hkDefaultSteering_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fac0` |
| **VA** | `0x0064fac0` |
| **Canonical name** | `hkDefaultSteering_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064fac0_hkDefaultSteering_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Default wheeled steering ctor (size 0x38): base ``FUN_0065e5f0``, vtbl ``PTR_FUN_009e4ee4``, empty doesWheelSteer hkArray @ +0x2c, ``FUN_0064f920`` copies maxAngle/speedLimit/flags. Parent of TankSteering. Verified ``fn_0064fac0_steeringCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064fac0_FUN_0064fac0.md` |
| Annotated | `docs/reconstruction/raw/aa_0064fac0_FUN_0064fac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064fac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064fac0_FUN_0064fac0.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064fac0` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4ee4` | High | Body |
| `doesWheelSteer empty then copy` | High | +0x2c triple |
| `FUN_0064f920 desc fields` | High | Callee |
| `Tank path calls this first` | High | 0x64fc80 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. Exact maxAngle product ownership (entity mult already in desc).

**Verdict:** accept-with-gaps
