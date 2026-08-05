# Review B (skeptical / adversarial): `aa_00795f20` NDUIEdit_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00795f20` |
| **VA** | `0x00795f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00795f20_NDUIEdit_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Button ctor | **Falsified** | Vtbl `00a98b1c` ≠ button `00a97c34`; metrics `d1e7a8/ac` ≠ `b0/b4` |
| 2 | Sets digit index / max length | **Falsified** | Callers set via vtbl after construct |
| 3 | No base | **Falsified** | Calls `FUN_007b5dd0` |
| 4 | XML load | **Falsified** | None in body |

---

## 2. Surviving contract

```
edit = NDUIEdit_Ctor(mem, cookie):
  base NDUIWindow_BaseCtor
  clear edit flags / buffers
  vtbl = edit
  font metrics from DAT_00d1e7a8/ac
```

**Verdict:** **accept-with-gaps**
