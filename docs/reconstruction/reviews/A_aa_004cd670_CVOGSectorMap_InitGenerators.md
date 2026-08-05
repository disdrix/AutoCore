# Review A (reconstruction fidelity): `aa_004cd670` CVOGSectorMap_InitGenerators

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd670` |
| **VA** | `0x004cd670` |
| **Canonical name** | `CVOGSectorMap_InitGenerators` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004cd670_CVOGSectorMap_InitGenerators.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **generator singleton init**: constructs global `CVOGCreatureGenerator` (**0x2c** via `FUN_00568920` → `DAT_00b037ec`) and `CVOGLootGenerator` (**0xbc** via `FUN_0050c1b0` → `DAT_00b037e8`), both with table root `DAT_00b041fc`. Plate markers `@@CVOGSectorMap::InitGenerators CVOGCreatureGenerator/LootGenerator`. Load-time loot+spawn pipeline bring-up.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cd670_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004cd670_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_InitGenerators.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cd670_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Creature gen DAT_00b037ec size 0x2c | High | Body |
| Loot gen DAT_00b037e8 size 0xbc | High | Body |
| Shared table root DAT_00b041fc | High | Body |
| Null on OOM | High | Body |
| Ctor identities FUN_00568920 / 0050c1b0 | Medium | Names residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| new creature gen → new loot gen → return | Yes |

---

## 5. Gaps / open

1. Name FUN_0050c1b0 as CVOGLootGenerator_ctor.
2. When InitGenerators runs vs map load.

**Verdict:** **accept-with-gaps**
