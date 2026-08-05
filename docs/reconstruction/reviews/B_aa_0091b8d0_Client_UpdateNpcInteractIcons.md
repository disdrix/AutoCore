# Review B (skeptical / adversarial): `Client_UpdateNpcInteractIcons` @ `0x0091b8d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091b8d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0091b8d0_Client_UpdateNpcInteractIcons.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server sets interact icons | Falsified — client periodic FX |
| 2 | State 6==7 always | Falsified — CoreMission +0x169 splits |
| 3 | Always reloads FX | Falsified — only when object+0x4c==0 |
| 4 | Safe always after CompleteObjective | Falsified — MSXML race note |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State 6/7 core mission icons | High | Wrong offer icons |
| FX attach gate +0x4c | High | FX thrash/leaks |
| MSXML race with turn-in | High | Client crash |
| entry+0x10 cache | High | Stale icons |

---

## 3. Cross-check against raw

```
UpdateNpcInteractIcons:
  for interactive objects in scope:
    compute state 0..8 (6 vs 7 via CoreMission +0x169)
    cache entry+0x10
    if obj+0x4c==0: load script FX + SetInteractSpecialFX
  client presentation only.
```

---

## 4. Surviving contract for AutoCore

```
UpdateNpcInteractIcons:
  client interact icon/FX refresh;
  pairs CVOGObject_EvalInteractState* and SetInteractSpecialFX;
  avoid racing CompleteObjective MSXML.
```

---

## 5. Open questions

1. Align state enum with EvalOfferableMissionInteractState duals.
2. Document script name table per state.

**Verdict:** **accept-with-gaps**
