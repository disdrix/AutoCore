# Review A (reconstruction fidelity): `aa_00509410` CVOGLootGenerator_GetTypeFromIDPrefix_00509410

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509410` |
| **VA** | `0x00509410` |
| **Canonical name** | `CVOGLootGenerator_GetTypeFromIDPrefix_00509410` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00509410_CVOGLootGenerator_GetTypeFromIDPrefix_00509410.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Loot prefix **type→modifier-name string** sibling of `CVOGLootGenerator_GetTypeFromIDPrefix` (`0x005092b0`). `Map_LowerBoundFindByIntKey` on map **`DAT_00b041dc`** / end **`DAT_00b041e0`**; type dword at node **+0x10**. Switch types **10, 0xc, 0xe, 0x1c, 0x44, 0x46** → lookup FUN_00508* then return pointer **entry+0x11** (name). Miss: log invalid prefix, type 0; default: `GetModifierName() invalid` + empty string `DAT_00a1419b`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00509410_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00509410_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetTypeFromIDPrefix_00509410.cpp` |
| Function record | `docs/reconstruction/functions/aa_00509410_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Shared map DAT_00b041dc / +0x10 type | High | Body |
| Return offset +0x11 name field | High | Body |
| Type switch 10/0xc/0xe/0x1c/0x44/0x46 | High | Body |
| Distinct from primary 005092b0 GetType | High | Different VA/return |
| Lookup FUN_00508* table sealed | Medium | Per-type tables |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lower_bound → type switch → +0x11 or empty | Yes |

---

## 5. Gaps / open

1. Map type codes to clonebase item families.
2. Diff return offset vs siblings +0x44/+0x10/+0x70.

**Verdict:** **accept-with-gaps**
