# Review A (reconstruction fidelity): `aa_0050f940` Map_LowerBoundFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050f940` |
| **VA** | `0x0050f940` |
| **Canonical name** | `Map_LowerBoundFindByIntKey` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0050f940_Map_LowerBoundFindByIntKey.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **std::map lower_bound** for int keys. Node nil/red-black flag at **+0x15** (differs from `StdMap_LowerBoundByIntKey_INFERRED` **+0x1d**). Walks from root `this+4`, compares key at node slot **[3]**. Writes iterator out (annotated raw sets `*pMap` to node or end). Used by loot prefix maps and quest XP/credit lookups (`Mission_ComputeObjectiveXp` dependency). Critical shared helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0050f940_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0050f940_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByIntKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_0050f940_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Node flag +0x15 (not +0x1d) | High | Clean + annotated |
| Key compare at node[3] | High | Body |
| Distinct layout vs StdMap_LowerBoundByIntKey_INFERRED | High | Plate |
| Loot DAT_00b041dc consumers call this | High | Sibling call sites |
| Decompiler param naming messy (this/pMap/pOutIt) | Medium | Annotated fixes write |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| walk tree by key → write iterator or end | Yes |

---

## 5. Gaps / open

1. Seal full signature against callers (this vs map root).
2. Catalog all DAT_* maps using +0x15 nodes.

**Verdict:** **accept-with-gaps**
