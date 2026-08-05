# Review B (skeptical / adversarial): `aa_00545ff0` MissionDef_SetOwnedString_plus150

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545ff0` |
| **VA** | `0x00545ff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00545ff0_MissionDef_SetOwnedString_plus150.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Alias of Title setter `+0x14c` | **Falsified** — distinct offset **`+0x150`** |
| 2 | In-place strcpy without free | **Falsified** — delete-old path present |
| 3 | Parses XML tags | **Falsified** — assign only |
| 4 | Product name sealed | **Fail** — English open |
| 5 | Runtime/bit-exact | **Fail** |

---

## 2. Port risks

| Risk | Impact |
|---|---|
| Collapse twins into one offset | Field clobber across Title/Description/etc. |
| Leak on reload | Memory growth |

**Verdict:** Accept twin setter. Require offset-accurate ports.
