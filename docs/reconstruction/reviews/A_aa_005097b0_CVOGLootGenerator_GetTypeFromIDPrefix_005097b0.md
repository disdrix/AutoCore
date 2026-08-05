# Review A (reconstruction fidelity): `aa_005097b0` CVOGLootGenerator_GetTypeFromIDPrefix_005097b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005097b0` |
| **VA** | `0x005097b0` |
| **Canonical name** | `CVOGLootGenerator_GetTypeFromIDPrefix_005097b0` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005097b0_CVOGLootGenerator_GetTypeFromIDPrefix_005097b0.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Loot prefix sibling returning **entry+0x70** with null-check on lookup. Same map/types; cases fall through after failed lookup until a successful FUN_00508* then `return base+0x70`. Miss logs invalid prefix. Larger residual CF (fallthrough cases). Not GenerateLootItem.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005097b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005097b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetTypeFromIDPrefix_005097b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005097b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Return offset +0x70 after non-null lookup | High | Body |
| Null-checked double call pattern | High | Body |
| Shared map DAT_00b041dc | High | Body |
| Fallthrough switch residual risk | Medium | Decompiler CF |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lower_bound → switch null-check → +0x70 or fallthrough | Yes |

---

## 5. Gaps / open

1. Verify switch fallthrough vs break in assembly if needed.
2. Name +0x70 payload field.

**Verdict:** **accept-with-gaps**
