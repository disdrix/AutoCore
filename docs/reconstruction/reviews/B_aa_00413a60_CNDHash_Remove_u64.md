# Review B (skeptical / adversarial): `aa_00413a60` CNDHash_Remove_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413a60` |
| **VA** | `0x00413a60` |
| **Canonical name** | `CNDHash_Remove_u64` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00413a60_CNDHash_Remove_u64.md` |
| **Live tools** | Independent `force_decompile` + caller decompile + memory |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always destroys value via vtbl | **Falsified** — out-path clears `+0xc` first so dtor skipped |
| 2 | Decompiler "always dtor after clear" is live | **Falsified as semantics** — early clear is intentional transfer |
| 3 | `__thiscall` ECX=hash | **Falsified** — hash in **EDI**; 3 stack args; `ret 0xc` |
| 4 | Returns removed node* | **Falsified** — HRESULT; value via out-param |
| 5 | Same as mission `CNDHash_Remove` `0x00538b20` body | **Overstated** — same product class, different node/key size |
| 6 | Lock error prevents remove | **Falsified** — log only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ownership transfer when out≠null | **High** | Double-free widget |
| Freelist push at hash+0x20 | **High** | UAF node |
| count-- only on hit | **High** | Sheet occupancy drift |
| EDI convention required | **High** | Silent wrong-hash remove |
| Full bucket edge cases (empty sentinel) | **Tentative** | Rare miss |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `FUN_0085fcc0` | That remove **is** the UI detach — detach is `vtbl+0xbc` after out-value returned |
| `FUN_007fbb70` after remove | That remove clears selection — separate helper |

---

## 4. CF challenge of Review A

- Dual identity: **agree**
- Transfer-vs-dtor: **agree** (B strengthens ownership rule)
- E_FAIL on miss: **agree**

---

## 5. Surviving contract

```
hr = CNDHash_Remove_u64(hash /*EDI*/, keyLo, keyHi, outValue*):
  if out: *out = 0
  if locked: log; // continue
  node = bucket_unlink(key)
  if !node: return E_FAIL
  if out: *out = node.value; node.value = null   // transfer
  list_unlink(node); freelist_push(node); count--
  if node.value: node.value->dtor(1)             // only if no out
  return 0
```

**Verdict:** **accept-with-gaps.** Accept A.
