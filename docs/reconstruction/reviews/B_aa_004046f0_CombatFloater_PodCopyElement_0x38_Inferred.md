# Review B (skeptical / adversarial): `aa_004046f0` CombatFloater_PodCopyElement_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004046f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004046f0_CombatFloater_PodCopyElement_0x38_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Deep-copies heap strings inside floater | **Unsupported** — plain dword walk; if strings exist they are shallow |
| 2 | Size 0x20 | **Falsified** — **0x38** |
| 3 | Constructs with side effects | **Falsified** — memory copy only |

---

## 2. Surviving contract for AutoCore

```
PodCopyFloater(dst, src):
  if dst: copy 14×u32 from src
Combat floater element size sealed at 0x38 for queue math.
```

**Verdict:** **accept**
