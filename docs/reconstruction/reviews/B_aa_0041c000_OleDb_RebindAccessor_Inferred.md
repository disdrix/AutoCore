# Review B (skeptical / adversarial): `aa_0041c000` OleDb_RebindAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c000` |
| **VA** | `0x0041c000` |
| **Canonical name** | `OleDb_RebindAccessor_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041c000_OleDb_RebindAccessor_Inferred.md` |
| **System** | COM / OLE DB accessor bind |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always creates without releasing old | Explicit release when h[3]!=0 | **Falsified** |
| 2 | flag is bool 0/1 passed through | Converted to -1/+1 | **Falsified raw bool** |
| 3 | Ignores FUN_004205e0 | Uses it to roll back bind | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x0041c000` (autoassault.exe, 2026-07-29) matches `raw/aa_0041c000_FUN_0041c000.md` control flow and callees.

---

## 3. Surviving contract

```
// HRESULT rebind(holder, bindArgs, optionalFlag)
// optionalFlag -> ±1; on post-check fail, release handle again.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
