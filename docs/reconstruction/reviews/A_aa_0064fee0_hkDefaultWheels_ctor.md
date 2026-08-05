# Review A (reconstruction fidelity): `aa_0064fee0` hkDefaultWheels_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fee0` |
| **VA** | `0x0064fee0` |
| **Canonical name** | `hkDefaultWheels_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064fee0_hkDefaultWheels_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Wheels ctor (size 0x390): base ``FUN_005fbbb0`` does empty hkArrays + descriptor grow/copy, then install ``PTR_FUN_009e5010``. Thin derived vtbl swap. Verified ``fn_0064fee0_wheelsCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064fee0_FUN_0064fee0.md` |
| Annotated | `docs/reconstruction/raw/aa_0064fee0_FUN_0064fee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064fee0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064fee0_FUN_0064fee0.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064fee0` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e5010` | High | Body |
| `Base FUN_005fbbb0 owns storage` | High | Verified |
| `Heap 0x390 external` | High | Alloc site |
| `Wheel array stride 0xC0 residual in base` | Medium | Runtime consumers |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. Full wheel element layout in base copy residual.
2. Axle histogram details in FUN_005fa9b0.

**Verdict:** accept-with-gaps
