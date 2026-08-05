# Review A (reconstruction fidelity): `aa_0064e510` hkDefaultSuspension_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064e510` |
| **VA** | `0x0064e510` |
| **Canonical name** | `hkDefaultSuspension_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064e510_hkDefaultSuspension_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Suspension ctor (size 0x68): base ``FUN_0065e070``, vtbl ``PTR_FUN_009e4c00``, init three empty hkArrays (strength / compDamp / extDamp at +0x44/+0x50/+0x5c with cap 0x80000000), then ``FUN_0064df10`` copies desc arrays. Verified ``fn_0064e510_suspCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064e510_FUN_0064e510.md` |
| Annotated | `docs/reconstruction/raw/aa_0064e510_FUN_0064e510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064e510.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064e510_FUN_0064e510.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064e510` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4c00` | High | Body |
| `Three empty hkArray triples` | High | 0x80000000 sentinel |
| `FUN_0064df10 desc copy` | High | Callee |
| `Heap size 0x68 external` | High | Alloc site |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. Exact desc element types residual in copy helper.
2. Pair susp update dual present.

**Verdict:** accept-with-gaps
