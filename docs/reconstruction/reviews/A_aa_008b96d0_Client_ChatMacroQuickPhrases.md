# Review A (reconstruction fidelity): `aa_008b96d0` Client_ChatMacroQuickPhrases

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b96d0` |
| **VA** | `0x008b96d0` |
| **Canonical name** | `Client_ChatMacroQuickPhrases` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008b96d0_Client_ChatMacroQuickPhrases.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ChatMacroQuickPhrases.cpp` |
| Raw | `docs/reconstruction/raw/aa_008b96d0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Client chat macro / quick-phrase UI strings: combat calls ('I need cooldown!', 'I need power!', 'I need repair!', 'Attack!', 'Ready!') plus convoy/search phrases. Skill-adjacent social UI.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Combat callout strings present | High | String table in body |
| Convoy/search phrases included | High | Plate |
| UI/string table; not cast pipeline | High | No skill cast callees as primary |
| Large table-driven loop CF | High | do/while ×50 pattern |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Iterate macro slots / register phrases | Yes |

---

## 4. Gaps

1. Exact send path for selected macro (chat opcode) open.
2. Localization vs hard-coded English table.

**Verdict:** **accept-with-gaps**
