# Review B (skeptical / adversarial): `aa_0041bf70` AdoRowsetHolder_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041bf70` |
| **VA** | `0x0041bf70` |
| **Canonical name** | `AdoRowsetHolder_Teardown_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md` |
| **System** | COM / ADO-OLEDB DB load teardown |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is constructor / open | Only release/delete paths | **Falsified** |
| 2 | Does not touch accessors | Calls 00422de0 + vtbl+0x18 | **Falsified** |
| 3 | Skill-only | Medal/achievement loaders also call | **Falsified skill-only** |
| 4 | Returns HRESULT | void fall-through | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x0041bf70` (autoassault.exe, 2026-07-29) matches `raw/aa_0041bf70_FUN_0041bf70.md` control flow and callees.

---

## 3. Surviving contract

```
// void teardown(holder*) // this in EDI (decompiler)
// Unbind accessors, free slab, Release primary+secondary COM.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
