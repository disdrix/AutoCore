# Review A (reconstruction fidelity): `aa_0065eb00` hkChassisComponent_method

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eb00` |
| **VA** | `0x0065eb00` |
| **Canonical name** | `hkChassisComponent_method` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0065eb00_hkChassisComponent_method.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Base chassis-component class/type getter: returns ``&DAT_00d039b4``. Sibling pattern to ``hkDefaultChassis_vtbl_getClass`` (DAT_00d032ac). No mutation; not a tick method despite generic name.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0065eb00_FUN_0065eb00.md` |
| Annotated | `docs/reconstruction/raw/aa_0065eb00_FUN_0065eb00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0065eb00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0065eb00_FUN_0065eb00.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0065eb00` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Returns &DAT_00d039b4 only` | High | Body |
| `Base class type blob` | Probable | Name + pattern |
| `Not CCS fill` | High | CCS is FUN_0065e6c0 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| r | e |
| Y | e |

---

## 5. Gaps / open

1. Confirm class string near DAT_00d039b4 (hkChassisComponent).
2. Artifact clean still FUN-named residual.

**Verdict:** accept-with-gaps
