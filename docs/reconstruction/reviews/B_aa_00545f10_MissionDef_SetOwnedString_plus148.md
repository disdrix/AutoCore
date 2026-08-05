# Review B (skeptical / adversarial): `aa_00545f10` MissionDef_SetOwnedString_plus148

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545f10` |
| **VA** | `0x00545f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00545f10_MissionDef_SetOwnedString_plus148.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | In-place overwrite without free | **Falsified** — always delete old if non-null |
| 2 | Stores at `+0x14c` (Title) | **Falsified** — imm **`0x148`** only |
| 3 | Parses XML itself | **Falsified** — pure string assign; parsing is EnsureXml |
| 4 | Grants missions | **Falsified** |
| 5 | Product name proven “ExternalText” | **Unproven** — offset sealed; English open |
| 6 | Bit-exact | **Fail** |

---

## 2. Port risks

| Risk | Impact |
|---|---|
| Leak old buffer | Memory growth on reload |
| Wrong offset | Clobber adjacent string field |
| Treat as Title | Toast/title confusion with `+0x14c` twin |

**Verdict:** Accept owned-string mechanics. Do not invent field English without tag xref.
