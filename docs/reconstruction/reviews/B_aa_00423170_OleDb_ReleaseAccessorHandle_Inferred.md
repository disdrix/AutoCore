# Review B (skeptical / adversarial): `aa_00423170` OleDb_ReleaseAccessorHandle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423170` |
| **VA** | `0x00423170` |
| **Canonical name** | `OleDb_ReleaseAccessorHandle_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Creates accessors | Only QI + ReleaseAccessor + Release | **Falsified create** |
| 2 | Uses different IID than array path | Same DAT_00a860ac | **Falsified** |
| 3 | Critical section | com_ptr helpers only | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x00423170` (autoassault.exe, 2026-07-29) matches `raw/aa_00423170_FUN_00423170.md` control flow and callees.

---

## 3. Surviving contract

```
// if handle: QI IAccessor -> ReleaseAccessor(handle) -> Release iface; always Release owner.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
