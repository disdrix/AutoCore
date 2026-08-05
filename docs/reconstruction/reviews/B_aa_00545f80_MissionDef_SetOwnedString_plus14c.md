# Review B (skeptical / adversarial): `aa_00545f80` MissionDef_SetOwnedString_plus14c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545f80` |
| **VA** | `0x00545f80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00545f80_MissionDef_SetOwnedString_plus14c.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same offset as `FUN_00545f10` | **Falsified** — **`+0x14c`** vs `+0x148` |
| 2 | Formats toast itself | **Falsified** — assign only; GiveMission formats later |
| 3 | Word field `+0xF8` toast gate is this string | **Falsified** — `+0xF8` is separate **word** gate; `+0x14c` is title **pointer** |
| 4 | Product “Title” proven without tag xref | **Overstated** — Probable from consumer, not string at this VA |
| 5 | Bit-exact | **Fail** |

---

## 2. Separation of concerns (GiveMission)

| Field | Role |
|---|---|
| `word def+0xF8` | Whether to show toast / audio at all |
| `ptr def+0x14c` | Title string for toast body |
| This function | How EnsureXml fills `+0x14c` |

Collapsing these three is a common dual error — **reject**.

---

## 3. Port risks

| Risk | Impact |
|---|---|
| Write title to `+0x148` | Wrong field / blank toast title |
| Skip free on re-load | Leak |
| Treat as wide string API | Truncation / encoding bugs |

**Verdict:** Accept setter. Keep Title English at Probable until EnsureXml tag site sealed.
