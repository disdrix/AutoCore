# Review B (skeptical / adversarial): `aa_00546220` MissionDef_SetOwnedString_FailText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546220` |
| **VA** | `0x00546220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00546220_MissionDef_SetOwnedString_FailText.md` |
| **System** | `missions-progression` |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is CheckMissionRequirements (`0x005462b0`) | **Falsified** — different function; this is 0x70-byte string setter |
| 2 | Offset `+0x160` CompleteText | **Falsified** — body **`+0x164`** |
| 3 | Fails mission on call | **Falsified** — store only |
| 4 | Runtime sealed | **Fail** |

---

## 2. Port risks

Confusing with `aa_005462b0` Requirements gate by address proximity; wrong field for fail dialog text.

**Verdict:** Accept string twin; keep separate from Requirements unit.
