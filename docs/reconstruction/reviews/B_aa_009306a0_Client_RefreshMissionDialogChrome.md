# Review B (skeptical / adversarial): `Client_RefreshMissionDialogChrome` @ `0x009306a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009306a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_009306a0_Client_RefreshMissionDialogChrome.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creates dialog | Falsified — refresh if open |
| 2 | Completes objectives | Falsified — chrome only |
| 3 | Uses +0x107c only | Falsified — +0x10b0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x10b0 chrome slot | High | Stale dialog UI |
| Visible gate | High | Wasted work / crash if wrong |

---

## 3. Cross-check against raw

```
RefreshMissionDialogChrome(game):
  chrome=*(game+0x10b0);
  if chrome && visible(+0x3d8): FUN_008a05a0();
```

---

## 4. Surviving contract for AutoCore

```
RefreshMissionDialogChrome:
  pairs CompleteDynamicObjective / ObjectiveState refresh paths;
  UI only.
```

---

## 5. Open questions

1. Name FUN_008a05a0.

**Verdict:** **accept**
