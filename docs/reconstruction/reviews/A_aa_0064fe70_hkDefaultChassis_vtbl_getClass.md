# Review A (reconstruction fidelity): `aa_0064fe70` hkDefaultChassis_vtbl_getClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fe70` |
| **VA** | `0x0064fe70` |
| **Canonical name** | `hkDefaultChassis_vtbl_getClass` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064fe70_hkDefaultChassis_vtbl_getClass.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Class-info getter for hkDefaultChassis: returns ``&DAT_00d032ac`` (static type blob). Pattern matches other Havok getClass / type slots (compare analog DI candidate / chassis component method).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064fe70_FUN_0064fe70.md` |
| Annotated | `docs/reconstruction/raw/aa_0064fe70_FUN_0064fe70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064fe70.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064fe70_FUN_0064fe70.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064fe70` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Returns &DAT_00d032ac only` | High | Body |
| `No mutation` | High | Single return |
| `Type blob for DefaultChassis` | Probable | Name + slot pattern |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| r | e |
| Y | e |

---

## 5. Gaps / open

1. Confirm class name string near DAT_00d032ac.
2. Artifact clean still FUN-named residual.

**Verdict:** accept-with-gaps
