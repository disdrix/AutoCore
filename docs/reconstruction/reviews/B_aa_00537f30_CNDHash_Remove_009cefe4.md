# Review B (skeptical / adversarial): `aa_00537f30` CNDHash_Remove_009cefe4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537f30` |
| **VA** | `0x00537f30` |
| **Canonical name** | `CNDHash_Remove_009cefe4` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537f30_CNDHash_Remove_009cefe4.md` |
| **Live tools** | Independent `force_decompile` + xrefs + twin bodies |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This remove frees the value payload | Value cleared **before** `if (puVar1[2]) operator_delete` — arm dead | **Falsified** free-in-remove |
| 2 | Destroy and remove share one VA | Destroy `00538e00` calls this then `operator_delete(out)` on success | **Falsified** merge — separate owning wrapper |
| 3 | Lock aborts | Log only | **Falsified** |
| 4 | Same as Lookup | `FUN_004e2ca0` unlinks bucket | **Falsified** Lookup alias |
| 5 | Miss returns 0 | Returns `0x80004005` | **Falsified** |
| 6 | Freelist separate next field | Freelist reuses vtbl dword | **Attack fails** — vtbl-as-next |
| 7 | Only mission hash uses this | Callers: Destroy @ `00538e30`, EndQuest @ `00530beb` (state-blob / reward family) | **Attack partial** — not exclusive to one char offset |
| 8 | force changes CF | force ≡ batch 2026-07-29 | **Attack fails** |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove CF + HRESULT | **Confirmed** | Stale map entries |
| Dead delete after clear | **Confirmed** | Double-free if “fixed” wrongly |
| Ownership free in Destroy only | **High** | Leak state blobs |
| Vtbl family `009cefe4` | **High** | Wrong dtor / twin merge |
| Bucket elision encoding | **Open** | Hook placement |

---

## 3. Cross-check

```
raw ≡ batch ≡ force (2026-07-29).

Xrefs (2):
  00538e30  CNDHash_Destroy (FUN_00538e00) — out slot = key; free on hr>=0
  00530beb  FUN_005307e0 / EndQuest path

Strings: "HashError:remove, already locked for traversal", "VOG_DEBUG_STOP"

Twin deltas (same CF):
  00538b20 → vtbl 009cf024
  00538000 → vtbl 009cefec + same dead-delete shape
  00537f30 → vtbl 009cefe4 + same dead-delete shape
```

### Traps

1. **Do not** port `operator_delete` in remove — value is zeroed first; Destroy owns free.
2. **Do not** merge this VA with `00538b20` — different node vtbls.
3. **Do not** skip freelist push — nodes return to `hash+0x20` for `FUN_0053ada0`.

---

## 4. Surviving contract

```
hr = CNDHash_Remove_009cefe4(hash, key, outOpt):
  if outOpt: *outOpt = 0
  lock: log only
  n = bucket_find_unlink(key)
  if !n: return E_FAIL
  if outOpt: *outOpt = n->value
  n->value = 0
  list_unlink; stamp vtbl 009cefe4; freelist_push(+0x20); count--
  return 0
// never frees value here
```

**Verdict:** **accept-with-gaps.** Accept A.
