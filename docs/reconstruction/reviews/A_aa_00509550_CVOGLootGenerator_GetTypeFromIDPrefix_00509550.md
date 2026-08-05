# Review A (reconstruction fidelity): `aa_00509550` CVOGLootGenerator_GetTypeFromIDPrefix_00509550

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509550` |
| **VA** | `0x00509550` |
| **Canonical name** | `CVOGLootGenerator_GetTypeFromIDPrefix_00509550` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00509550_CVOGLootGenerator_GetTypeFromIDPrefix_00509550.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Loot prefix sibling returning field **+0x44** after type switch (same map `DAT_00b041dc`, types 10/0xc/0xe/0x1c/0x44/0x46, same FUN_00508* lookups). Default returns empty `DAT_00a1419b` without GetModifierName log (differs from 00509410). Miss prefix logs invalid type map. Not primary type int API.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00509550_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00509550_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetTypeFromIDPrefix_00509550.cpp` |
| Function record | `docs/reconstruction/functions/aa_00509550_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Return offset +0x44 | High | Body |
| Shared type switch + map | High | Body |
| Default silent empty (no GetModifierName log) | High | Body |
| Sibling distinct from +0x11/+0x10/+0x70 | High | VA family |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lower_bound → switch → +0x44 or empty | Yes |

---

## 5. Gaps / open

1. Identify +0x44 field (display/icon path?).

**Verdict:** **accept-with-gaps**
