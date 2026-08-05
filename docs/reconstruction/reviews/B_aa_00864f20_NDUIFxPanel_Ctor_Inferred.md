# Review B (skeptical / adversarial): `aa_00864f20` NDUIFxPanel_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00864f20` |
| **VA** | `0x00864f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00864f20_NDUIFxPanel_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Combat threat calculator | **Falsified** | UI ctor; CreateChildWidgets FX chrome only |
| 2 | Same as base window | **Falsified** | Own vtbl + extra scale/mode fields |
| 3 | Loads `wnd_fx.xml` itself | **Falsified** | Caller loads after attach |
| 4 | Cookie free / multi-arg | **Falsified** | Base always called with 0 |

---

## 2. Surviving contract

```
fx = NDUIFxPanel_Ctor(mem):
  NDUIWindow_BaseCtor(mem, 0)
  vtbl = FX panel
  init scale from screen height, mode=3, flags
  return mem
```

**Verdict:** **accept-with-gaps**
