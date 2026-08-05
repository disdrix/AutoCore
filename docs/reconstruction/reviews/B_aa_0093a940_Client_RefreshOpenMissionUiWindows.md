# Review B (skeptical / adversarial): `Client_RefreshOpenMissionUiWindows` @ `0x0093a940`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0093a940_Client_RefreshOpenMissionUiWindows.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Completes objectives | Falsified — refresh only |
| 2 | Always destroys panels | Falsified — refresh if visible |
| 3 | Single journal window only | Falsified — multi-slot walk |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-slot panel walk | High | Stale UI |
| +0x3d8 visible gate | High | Null deref / skip |
| Re-entrancy | Medium | Client crash |

---

## 3. Cross-check against raw

```
foreach panel ptr: if vis(+0x3d8) call refresh FUN/vtbl.
Called post-objective. Clean cascade matches.
```

---

## 4. Surviving contract for AutoCore

```
RefreshOpenMissionUiWindows(client):
  refresh visible mission HUD panels only
  call after CompleteObjective / dynamic complete
  avoid nested XML loads while already loading
```

---

## 5. Open questions

1. Name panel types at client offsets.
2. Audit re-entrancy with MSXML.

**Verdict:** **accept-with-gaps**
