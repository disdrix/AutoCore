# Review B (skeptical / adversarial): `aa_00404600` CombatFloater_ConstructN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404600_CombatFloater_ConstructN_0x38_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grows capacity | **Falsified** — construct-in-place only; grow is `00402e20`/`00403680` |
| 2 | Element size 0x10 | **Falsified** — **0x38** |
| 3 | Zero-fills slots | **Falsified** — dword copy from source via `004046f0` |
| 4 | XP math | **Falsified** — no formulas |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| count×pod-copy×0x38 | High | Overwrite adjacent queue memory |
| Fast-path only | High | Miss grow path bugs |

---

## 3. Surviving contract for AutoCore

```
CombatFloater.ConstructN(dst, count, src):
  for i in 0..count-1: memcpy-like 0x38 dwords from src to dst+i*0x38
Enqueue uses count=1 when size < capacity.
```

**Verdict:** **accept**
