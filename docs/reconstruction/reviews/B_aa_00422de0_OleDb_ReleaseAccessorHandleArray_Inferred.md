# Review B (skeptical / adversarial): `aa_00422de0` OleDb_ReleaseAccessorHandleArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422de0` |
| **VA** | `0x00422de0` |
| **Canonical name** | `OleDb_ReleaseAccessorHandleArray_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | IID is IUnknown only | GUID matches IAccessor | **Falsified** |
| 2 | Critical-section sandwich | Helpers are com_ptr zero/Release | **Falsified CS claim** |
| 3 | Leaves count non-zero on success | count forced 0 before free | **Falsified** |
| 4 | Handles are 4-byte only | index * 8 | **Falsified 4-byte** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x00422de0` (autoassault.exe, 2026-07-29) matches `raw/aa_00422de0_FUN_00422de0.md` control flow and callees.

---

## 3. Surviving contract

```
// QI IAccessor; ReleaseAccessor each handle; delete[] array; Release iface.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
