# Review B (skeptical / adversarial): `aa_004231d0` OleDb_CreateAccessorFromBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004231d0` |
| **VA** | `0x004231d0` |
| **Canonical name** | `OleDb_CreateAccessorFromBindings_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Only releases | Create path + active flag | **Falsified release-only** |
| 2 | Different IID family | Same IAccessor GUID | **Falsified** |
| 3 | param_3 unused | Used for slot index math | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x004231d0` (autoassault.exe, 2026-07-29) matches `raw/aa_004231d0_FUN_004231d0.md` control flow and callees.

---

## 3. Surviving contract

```
// QI IAccessor; prep bindings; CreateAccessor (vtbl+0x10); binding flags.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
