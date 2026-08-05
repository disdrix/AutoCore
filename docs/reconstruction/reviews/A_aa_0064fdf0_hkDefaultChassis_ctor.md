# Review A (reconstruction fidelity): `aa_0064fdf0` hkDefaultChassis_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fdf0` |
| **VA** | `0x0064fdf0` |
| **Canonical name** | `hkDefaultChassis_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064fdf0_hkDefaultChassis_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Chassis ctor (size 0x40): base ``FUN_0065eac0`` (hkChassisComponent + CCS fill), install ``PTR_FUN_009e4fd0``. No RB pointer store here. Verified ``fn_0064fdf0_chassisCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064fdf0_FUN_0064fdf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0064fdf0_FUN_0064fdf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064fdf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064fdf0_FUN_0064fdf0.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064fdf0` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4fd0` | High | Body |
| `Base FUN_0065eac0 fills CCS` | High | Callee chain |
| `No RB write in this unit` | High | Body stores only vtbl after base |
| `Alloc 0x40 at framework` | High | Call site |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. CCS descriptor field map residual in base.
2. RB attach elsewhere (wire/post).

**Verdict:** accept-with-gaps
