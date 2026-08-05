# Review B (skeptical / adversarial): `aa_004044e0` CombatFloater_FillRangeFromTemplate_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004044e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004044e0_CombatFloater_FillRangeFromTemplate_0x38_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Copies range→range (src advances) | **Falsified** — `puVar3 = param_3` every outer iteration |
| 2 | Element size 0x4 | **Falsified** — 14 dwords / +0xE ptr step |
| 3 | Count-N API | **Falsified** — end iterator API (`cur != end`) |
| 4 | Allocates | **Falsified** — leaf stores only |
| 5 | Floater-only forever | **Weak** — two extra callers; size-matched POD only proven |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Template fill (not move) | High | Wrong insert overwrite |
| 0x38 | High | Buffer overrun |
| Multi-caller reuse | Medium | Over-narrow naming |

---

## 3. Cross-check

```
raw ≡ live while/for 0xe dword copy.
Distinct from 004044c0 (src range advances with dst in worker).
Parent InsertN uses for assign-range style overwrite.
```

---

## 4. Surviving contract for AutoCore

```
CombatFloater_FillRangeFromTemplate_0x38(cur, end, tmpl):
  for each 0x38 slot in [cur,end): memcpy14dwords(slot, tmpl)
```

---

## 5. Open questions

1. Type identity at `0x005e99d0` / `0x00690ee0` (same POD class?).

**Verdict:** **accept**
