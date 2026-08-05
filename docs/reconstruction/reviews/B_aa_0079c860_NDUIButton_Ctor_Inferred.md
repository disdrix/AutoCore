# Review B (skeptical / adversarial): `aa_0079c860` NDUIButton_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079c860` |
| **VA** | `0x0079c860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0079c860_NDUIButton_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Standalone (no base) | **Falsified** | Always calls `FUN_007b5dd0` first |
| 2 | Same as base vtbl | **Falsified** | Overwrites to `PTR_FUN_00a97c34` |
| 3 | Loads button XML | **Falsified** | Callers load via child vtbl+0x28 after attach |
| 4 | Sets command id | **Falsified** | Command ids set later (`vtbl+0x74` etc. in CreateChildWidgets) |
| 5 | Edit-box ctor | **Falsified** | Edit uses `FUN_00795f20` / vtbl `00a98b1c` |

---

## 2. Surviving contract

```
btn = NDUIButton_Ctor(mem, cookie):
  NDUIWindow_BaseCtor(mem, cookie)
  vtbl = button
  default button colors/flags/scale/font metrics
```

**Verdict:** **accept-with-gaps**
