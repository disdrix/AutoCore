# Review B (skeptical / adversarial): `aa_00538000` CNDHash_Remove_009cefec

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538000` |
| **VA** | `0x00538000` |
| **Canonical name** | `CNDHash_Remove_009cefec` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00538000_CNDHash_Remove_009cefec.md` |
| **Live tools** | Independent `force_decompile` + `FUN_004e2ca0` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Body `operator_delete` frees the payload | **Falsified** — value zeroed before delete test; arm dead |
| 2 | Destroy `0x00538e50` relies on remove's delete | **Falsified** — Destroy deletes **out** value after successful remove |
| 3 | Lock aborts remove | **Falsified** — log only |
| 4 | `FUN_004e2ca0` is non-mutating Lookup | **Falsified** — splices bucket next |
| 5 | Out-param required | **Falsified** — null skips zero/copy |
| 6 | Miss returns 0 | **Falsified** — `0x80004005` |
| 7 | Freelist uses separate link field | **Falsified** — reuses vtbl dword |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove CF + HRESULT | **High** | Stale entries |
| Dead delete arm | **Confirmed** | Wrong free in port |
| Destroy ownership (out-delete) | **High** | Leak/double-free |
| Vtbl tag only differs from twins | **High** | Merge wrong specialization |

---

## 3. Surviving contract

```
hr = Remove(hash, key, outOpt):
  if outOpt: *outOpt = 0
  if locked: log; // continue
  n = bucket_find_unlink(key)  // 004e2ca0
  if !n: return E_FAIL
  if outOpt: *outOpt = n.value; n.value = 0
  list_unlink; freelist_push(n); count--; return 0
// Do NOT free n.value inside remove — caller/Destroy owns out
```

**Verdict:** **accept-with-gaps.** Accept A.
