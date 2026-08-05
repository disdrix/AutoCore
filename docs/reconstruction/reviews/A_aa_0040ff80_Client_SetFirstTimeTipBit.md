# Review A (reconstruction fidelity): `aa_0040ff80` Client_SetFirstTimeTipBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ff80` |
| **VA** | `0x0040ff80` |
| **Canonical name** | `Client_SetFirstTimeTipBit` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040ff80_Client_SetFirstTimeTipBit.md` |
| **System tag** | `first-time-tips` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_SetFirstTimeTipBit.cpp` |
| Raw | `docs/reconstruction/raw/aa_0040ff80_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** OR tip bit into FirstTimeFlags at character+0xD30. AL/tip id; only for tip id < 0x80: flags[id>>5] |= 1<<(id&0x1f). Pure bit set; no network, no UI.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Base character+0xD30 | High | Plate |
| id < 0x80 gate | High | Plate |
| flags[id>>5] |= 1<<(id&0x1f) | High | Standard bitfield |
| No SendUpdate here | High | No callees net |
| fastcall tip id + character | High | ABI plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if id<0x80: OR bit; return | Yes |

---

## 4. Gaps

1. Whether ids >=0x80 are silently ignored only (yes).
2. Array length (4 dwords for 0x80 bits).

**Verdict:** **accept**
