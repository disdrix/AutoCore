# Review B (skeptical / adversarial): `aa_00825e00` QuickBar_BuildItemButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00825e00_QuickBar_BuildItemButtonWidgets.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Skill-only builder | Falsified — item strings |
| 2 | Network packet | Falsified — UI construct |
| 3 | Finished all slots | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| XML widget load order | High | Blank QB buttons |
| Offset store map | High | Wrong child ptrs |
| Gauge attach | Tentative | No CD chrome |

---

## 3. Cross-check against raw

```
load item QB widget XMLs into button fields; bump child counts.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
BuildItemButtonWidgets(btn):
  item QB chrome; pair BuildSkillButtonWidgets + UpdateSlotCooldownOverlay
  AutoCore client UI
```

---

## 5. Open questions

1. List all XML names in body.
2. Screenshot parity check.

**Verdict:** **accept-with-gaps**
