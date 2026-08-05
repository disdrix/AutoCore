# Review A (reconstruction fidelity): `aa_005fe020` hkDefaultAnalogDriverInput_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe020` |
| **VA** | `0x005fe020` |
| **Canonical name** | `hkDefaultAnalogDriverInput_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe020_hkDefaultAnalogDriverInput_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Constructs hkDefaultAnalogDriverInput: zeros runtime state bytes, installs vtable ``PTR_FUN_009dd368``, copies descriptor (deadzone/slope params), precomputes slope/intercept floats using ``g_flOne``. ~25-line body; no per-tick input apply here.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fe020_hkDefaultAnalogDriverInput_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_005fe020_hkDefaultAnalogDriverInput_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fe020_hkDefaultAnalogDriverInput_ctor.md` |
| Fresh Ghidra | `batch_decompile` @ `0x005fe020` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl install PTR_FUN_009dd368` | High | Body *this |
| `Copies desc floats + flag` | High | param_2[0..3] → this+0x28.. |
| `Slope precompute with g_flOne` | High | fVar2 / intercept formula |
| `English field names for +0x28 block` | Medium | Havok reflection residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| z | e |
| Y | e |

---

## 5. Gaps / open

1. Full semantic labels for deadzone / slope / intercept fields.
2. Pair with analog update path consumers.

**Verdict:** accept-with-gaps
