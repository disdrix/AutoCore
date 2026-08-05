# Review B (skeptical / adversarial): `aa_008274c0` QuickBar_ClearActiveSlot_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_008274c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008274c0_QuickBar_ClearActiveSlot_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server-only clear | Falsified — local SetQuickBar* |
| 2 | Only clears skills | Falsified — item+skill |
| 3 | Finished UI side effects | Overstated — INFERRED |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual clear item+skill | High | Stale QB entry |
| Slot index math | High | Wrong slot cleared |
| Payload layout | Tentative | Bad update pkt |

---

## 3. Cross-check against raw

```
zero payload; SetQuickBarItem/Skill -1; optional refresh.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
ClearActiveSlot(ui):
  local QB clear; pair Client_SendQuickBarUpdateFromUi
  AutoCore QuickBarUpdate semantics
```

---

## 5. Open questions

1. Confirm 10-wide bar layout.
2. Capture clear packet once.

**Verdict:** **accept-with-gaps**
