# Review A (reconstruction fidelity): `aa_005ffd80` hkAnalogDI_vtbl1

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffd80` |
| **VA** | `0x005ffd80` |
| **Canonical name** | `hkAnalogDI_vtbl1` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005ffd80_hkAnalogDI_vtbl1.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Vtbl method on analog DI: if ``*(byte*)(this+5) & 0x80`` set, forwards to ``FUN_005ffc90(this, a2, a3)``; else returns 0. Thin gate over heavier analog path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ffd80_hkAnalogDI_vtbl1.md` |
| Annotated | `docs/reconstruction/raw/aa_005ffd80_hkAnalogDI_vtbl1.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkAnalogDI_vtbl1.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ffd80_hkAnalogDI_vtbl1.md` |
| Fresh Ghidra | `batch_decompile` @ `0x005ffd80` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Flag gate this+5 bit7` | High | Body |
| `Forward FUN_005ffc90 when set` | High | Callee |
| `Return 0 when clear` | High | Else path |
| `English role of FUN_005ffc90` | Medium | Callee residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| i | f |
| Y | e |

---

## 5. Gaps / open

1. Decompose FUN_005ffc90 body.
2. Map this+5 flag source writers.

**Verdict:** accept-with-gaps
