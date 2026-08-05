# Review A (reconstruction fidelity): `aa_0064da90` hkDefaultAerodynamics_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064da90` |
| **VA** | `0x0064da90` |
| **Canonical name** | `hkDefaultAerodynamics_ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064da90_hkDefaultAerodynamics_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Aero component ctor (size 0x50): base ``FUN_0065d880`` on this (Ghidra may show desc as arg — thiscall on ECX), install ``PTR_FUN_009e4b20``, copy 8 dwords desc→this+0x30..+0x4c (airDensity, frontalArea, drag/lift, extraGravity xyz/w). Verified ``fn_0064da90_aeroCtor.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064da90_FUN_0064da90.md` |
| Annotated | `docs/reconstruction/raw/aa_0064da90_FUN_0064da90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0064da90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064da90_FUN_0064da90.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064da90` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009e4b20` | High | Body |
| `8-dword desc copy to +0x30` | High | Verified map |
| `Base is thiscall on ECX not desc` | High | Binary-corrected |
| `Field English airDensity/drag/lift` | High | Builder dual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| b | a |
| Y | e |

---

## 5. Gaps / open

1. Ghidra base-arg illusion residual only.
2. extraGravity.w often uninit from builder.

**Verdict:** accept-with-gaps
