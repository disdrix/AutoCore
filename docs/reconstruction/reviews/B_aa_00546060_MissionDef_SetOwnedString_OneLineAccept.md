# Review B (skeptical / adversarial): `aa_00546060` MissionDef_SetOwnedString_OneLineAccept

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546060` |
| **VA** | `0x00546060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00546060_MissionDef_SetOwnedString_OneLineAccept.md` |
| **System** | `missions-progression` |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same slot as Title `+0x14c` | **Falsified** — body uses **`+0x154`** only |
| 2 | In-place overwrite without free | **Falsified** — delete-old path present |
| 3 | Parses / tokenizes XML | **Falsified** — pure string replace |
| 4 | Tag is Description not OneLineAccept | **Falsified** — parent dual maps Description→`00545ff0`, OneLineAccept→`00546060` |
| 5 | Multiple independent callers invent meaning | **Falsified** — sole caller EnsureXml |
| 6 | Runtime / bit-exact sealed | **Fail** — not run (matrix policy) |

---

## 2. Port risks

| Risk | Impact |
|---|---|
| Collapse string twins into one field | Clobber OneLineAccept vs Title/Description |
| Skip free on reload | Leak on re-EnsureXml |
| Wide-string store | Wrong width — body is narrow `char*` |

---

## 3. Independence note

Reviewed live decompile + parent tag table without trusting prior `Named_CalleeOf_Mission_lacking_child_nodes` plate prose.

**Verdict:** Accept. Mechanics and tag binding hold under attack.
