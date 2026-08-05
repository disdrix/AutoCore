# Review A (reconstruction fidelity): `aa_005092b0` CVOGLootGenerator_GetTypeFromIDPrefix

| Field | Value |
|---|---|
| **Stable ID** | `aa_005092b0` |
| **VA** | `0x005092b0` |
| **Canonical name** | `CVOGLootGenerator_GetTypeFromIDPrefix` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005092b0_CVOGLootGenerator_GetTypeFromIDPrefix.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Map **IDPrefix → loot modifier type** for loot generator. Uses `Map_LowerBoundFindByIntKey` on `DAT_00b041dc`; logs `GetTypeFromIDPrefix() passed an invalid prefix` / `GetModifierLevelOffset() passed an invalid IDPrefix` on miss. ~130 lines. Sibling VAs exist (`00509410` etc.) — keep split.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005092b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005092b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetTypeFromIDPrefix.cpp` |
| Function record | `docs/reconstruction/functions/aa_005092b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| IDPrefix lower_bound map lookup | High | Clean |
| Invalid prefix error strings | High | Embedded |
| Map DAT_00b041dc | High | Clean |
| Sibling VA family | High | Domain aliases |
| Exact return type semantics | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lower_bound prefix → type or error log | Yes |

---

## 5. Gaps / open

1. Seal prefix→type table contents.
2. Document sibling GetTypeFromIDPrefix_* differences.

**Verdict:** **accept-with-gaps**
