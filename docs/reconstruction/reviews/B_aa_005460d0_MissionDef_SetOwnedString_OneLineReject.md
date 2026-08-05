# Review B (skeptical / adversarial): `aa_005460d0` MissionDef_SetOwnedString_OneLineReject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005460d0` |
| **VA** | `0x005460d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005460d0_MissionDef_SetOwnedString_OneLineReject.md` |
| **System** | `missions-progression` |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Alias of OneLineAccept `+0x154` | **Falsified** — distinct **`+0x158`** |
| 2 | No free-old | **Falsified** |
| 3 | Tag = FailText | **Falsified** — FailText is `00546220` / `+0x164` |
| 4 | Product name inventable from body alone | **Partial** — body has no string; tag from parent only |
| 5 | Runtime sealed | **Fail** |

---

## 2. Port risks

| Risk | Impact |
|---|---|
| Off-by-4 vs Accept twin | Wrong dialog line shown |
| Leak on re-hydrate | Memory growth |

**Verdict:** Accept twin with parent-tag binding.
