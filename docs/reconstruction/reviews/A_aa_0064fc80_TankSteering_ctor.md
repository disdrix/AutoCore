# Review A (reconstruction fidelity): `aa_0064fc80` TankSteering_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fc80` |
| **VA** | `0x0064fc80` |
| **Canonical name** | `TankSteering_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064fc80_TankSteering_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Thin tank subclass ctor: call full ``hkDefaultSteering_ctor(desc)``, then swap vtable to ``PTR_FUN_009e4f1c``. Same layout 0x38. Selected when ``VehSpec+0x4c0 == 4``. Verified ``fn_0064fc80_tankSteering.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064fc80_FUN_0064fc80.md` |
| Annotated | `docs/reconstruction/raw/aa_0064fc80_FUN_0064fc80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064fc80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064fc80_FUN_0064fc80.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064fc80` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Calls parent ctor then tank vtbl` | High | Body 24 bytes |
| `No extra field writes` | High | Only vtbl store |
| `Gate VehSpec+0x4c0==4 at build` | High | Framework call site |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| p | a |
| Y | e |

---

## 5. Gaps / open

1. Tank update slot English residual at tank vtbl.
2. Spec+0x4c0 enum completeness.

**Verdict:** accept-with-gaps
