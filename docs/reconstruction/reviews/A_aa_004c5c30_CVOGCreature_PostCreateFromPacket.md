# Review A (reconstruction fidelity): `aa_004c5c30` CVOGCreature_PostCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5c30` |
| **VA** | `0x004c5c30` |
| **Canonical name** | `CVOGCreature_PostCreateFromPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c5c30_CVOGCreature_PostCreateFromPacket.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-create hook after creature/character packet apply: optional graphics path, interact/map hooks for type 0x12, elite special FX (`generic_elite`), HBAI-missing debug. Negative this-offsets indicate dual-base layout.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c5c30_CVOGCreature_PostCreateFromPacket.md` |
| Annotated | `docs/reconstruction/raw/aa_004c5c30_CVOGCreature_PostCreateFromPacket.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_PostCreateFromPacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c5c30_CVOGCreature_PostCreateFromPacket.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `param_7 char gate → FUN_005c93f0 early path` | **High** | Conditional first call |
| `Negative this layout (−0x4f8 family)` | **High** | Dual-base creature framing |
| `Type 0x12 interact/owner bind branches` | **High** | Template kind check |
| `Elite FX load generic_elite when flag −0x1f5` | **High** | NDSpecialFX + vtbl+0xf8 |
| `HBAI missing debug when −0x304==0 and TFID all-ones` | **High** | FUN_007a4480 log |
| `Many FUN_* still unresolved` | **High** | Scaffold residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Entry branches preserved | **Yes** |
| Elite FX + HBAI log | **Yes** |
| No invented simplification of owner bind | **Yes** |

---

## 5. Gaps / open

1. Full dual-base offset map to named fields.
2. Owner TFID bind FUN_004bafe0 / name sprintf path.
3. param_3==2 mode meaning.
4. Runtime create-from-packet capture.

**Verdict:** **accept-with-gaps**
