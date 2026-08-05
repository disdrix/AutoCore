# Review A (reconstruction fidelity): `aa_005b17b0` Net_UnpackGhostUpdate_005b17b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b17b0` |
| **VA** | `0x005b17b0` |
| **Canonical name** | `Net_UnpackGhostUpdate_005b17b0` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b17b0_Net_UnpackGhostUpdate_005b17b0.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Alternate / base **GhostObject unpack update** at `0x005b17b0` (domain alias `Net_UnpackGhostUpdate_*`). `__thiscall` read path with `BitStream_readBits`/`readInt` and callees `FUN_005b0e30`, `FUN_004c00f0`, `FUN_004d0e90`, `FUN_0053dd40`, `FUN_00780a80`. Sibling to character-focused `0x0060a820` — keep VAs distinct. ~332-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b17b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005b17b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_UnpackGhostUpdate_005b17b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b17b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| GhostObject-family unpack (distinct VA from 0060a820) | High | Registry + body |
| BitStream read path | High | Callees |
| Touches physics helper FUN_0053dd40 on some branch | Medium | Callee list |
| Exact object-type dispatch table | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| readBits/Int → branch → helpers | Yes |
| Not 0060a820 body | Yes |

---

## 5. Gaps / open

1. Clarify when 005b17b0 vs 0060a820 is entered (vtbl/type).
2. Seal physics reinit branch conditions.

**Verdict:** **accept-with-gaps**
