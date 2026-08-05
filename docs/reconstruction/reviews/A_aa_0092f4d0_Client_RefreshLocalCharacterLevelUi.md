# Review A (reconstruction fidelity): `aa_0092f4d0` Client_RefreshLocalCharacterLevelUi

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f4d0` |
| **VA** | `0x0092f4d0` |
| **Canonical name** | `Client_RefreshLocalCharacterLevelUi` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0092f4d0_Client_RefreshLocalCharacterLevelUi.md` |
| **System tag** | `client-net` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_RefreshLocalCharacterLevelUi.cpp` |
| Raw | `docs/reconstruction/raw/aa_0092f4d0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** After CharacterLevel applies to local player, refresh level/rank UI fields from character clonebase (not money). Writes game+0xeec, +0xee4, +0xee8 from clonebase bytes +0x531/+0x532 and vtbl+0x27c. Called from RecvCharacterLevel when TFID matches local character.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Requires local char game+0xe98 | High | Body |
| game+0xeec from clonebase +0x531 | High | Body |
| game+0xee4 from vtbl+0x27c() | High | Body |
| game+0xee8 from clonebase +0x532 | High | Body |
| Not money refresh | High | Plate |
| Local-only CharacterLevel path | High | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if local char: copy level/rank UI fields from clonebase | Yes |

---

## 4. Gaps

1. Semantic names for +0x531/+0x532 bytes (rank icons?).
2. vtbl+0x27c return meaning.

**Verdict:** **accept-with-gaps**
