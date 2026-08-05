# Review A (reconstruction fidelity): `aa_0064feb0` hkDefaultChassis_vtbl_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064feb0` |
| **VA** | `0x0064feb0` |
| **Canonical name** | `hkDefaultChassis_vtbl_0x18` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064feb0_hkDefaultChassis_vtbl_0x18.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Chassis vtbl slot ~0x18: if ``param_1 != 0`` call ``FUN_0065eb10()`` then return; else return. Null-safe forward to teardown/reset helper also used on stack-descriptor teardown paths (wheels/aero notes).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064feb0_hkDefaultChassis_vtbl_0x18.md` |
| Annotated | `docs/reconstruction/raw/aa_0064feb0_hkDefaultChassis_vtbl_0x18.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultChassis_vtbl_0x18.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064feb0_hkDefaultChassis_vtbl_0x18.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064feb0` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Null check before FUN_0065eb10` | High | Body |
| `FUN_0065eb10 is cleanup helper` | High | Shared teardown notes |
| `No other side effects` | High | Branch only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| i | f |
| Y | e |

---

## 5. Gaps / open

1. Exact FUN_0065eb10 body (byte clear + 1000.0f pattern per wheels note).
2. Whether this is dtor-like vs desc reset.

**Verdict:** accept-with-gaps
