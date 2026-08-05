# Review B (skeptical / adversarial): `aa_00538b20` CNDHash_Remove

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538b20` |
| **VA** | `0x00538b20` |
| **Canonical name** | `CNDHash_Remove` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00538b20_CNDHash_Remove.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Remove only unlinks list, leaks bucket | `FUN_004e2ca0` splices bucket next@+0xc before return | **Falsified** leak — bucket unlink in helper |
| 2 | `FUN_004e2ca0` is plain Lookup (returns value) | Returns **node***; walks key@+0x10; mutates chain | **Falsified** Lookup alias |
| 3 | Lock aborts remove | Log only | **Falsified** |
| 4 | Out-param required | Null out skips zero/copy; still removes | **Falsified** required |
| 5 | Freelist uses separate next field | Freelist overwrites vtbl dword | **Attack fails** — vtbl-as-next sealed |
| 6 | Miss returns 0 / success | Returns `0x80004005` | **Falsified** |
| 7 | Same as insert soft path | No soft-skip; binary hit/miss | **Attack fails** |
| 8 | GiveMission double-remove is same hash twice | Residual: single site on `+0x538` for completed strip | **Agree** one remove at grant (not double) |
| 9 | Bucket index visible in remove decompile | Elided; helper proves sentinel framing | **Attack partial** — encoding residual, role sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove role + E_FAIL miss | **Confirmed** | Leave stale entries |
| Bucket unlink in 004e2ca0 | **High** | Lookup desync after remove |
| List unlink + freelist +0x20 | **High** | Leak / double-free pool |
| Optional out value | **High** | Null deref if forced |
| Freelist ECX for insert alloc | **High** link via +0x20 | Wrong pool pop |
| Bit-exact bucket load sequence | **Open** | Hook placement |
| Runtime | **Open** | |

---

## 3. Cross-check

```
raw/clean ≡ live (2026-07-29).

Xrefs (3):
  00532973  CVOGReaction_GiveMission           — char+0x538 completed
  005347b6 / 005347c6  CVOGReaction_CompleteObjective

Callees: FUN_004e2ca0, FUN_007a4480

Strings:
  "HashError:remove, already locked for traversal"
  "VOG_DEBUG_STOP"

FUN_004e2ca0:
  walk *(this+4) while key != node+0x10; next = node+0xc
  on hit: if prev: prev+0xc = found+0xc; else this+4 = found+0xc
  FUN_00537d30(); return found|0
```

### Traps

1. **Do not** implement remove as “Lookup then free” without bucket splice — Lookup would still find freelist-stale nodes if only list unlinked.
2. **Do not** treat `FUN_004e2ca0` as `CNDHash_LookupByKey` — Lookup does not unlink; this helper does.
3. **Do not** free with `operator_delete` — node returns to `hash+0x20` freelist for `FUN_0053ada0`.
4. Out-param is **optional** (GiveMission residual passes 0).

---

## 4. Surviving contract for AutoCore

```
CNDHash_Remove(hash, key, outValueOpt) -> int
  if outValueOpt: *outValueOpt = 0
  lock+0x1d: log only
  n = bucket_find_unlink(hash, key)   // via FUN_004e2ca0 on sentinel
  if !n: return 0x80004005
  if outValueOpt: *outValueOpt = n->value
  n->value = 0
  list_unlink(hash, n)
  freelist_push(hash+0x20, n)         // vtbl dword as next
  hash->count--
  return 0

GiveMission re-grant:
  Remove(char+0x538, missionId, NULL)  // strip completed

AutoCore must NOT:
  - skip bucket unlink
  - operator_delete nodes
  - require non-null out
  - hard-fail on lock without logging
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Signature + optional out | **Agree High** |
| E_FAIL miss / 0 hit | **Agree Confirmed** |
| List + freelist +0x20 | **Agree High** |
| FUN_004e2ca0 bucket unlink | **Agree High** |
| ECX=sentinel framing | **Agree High** (role); encoding Open |
| GiveMission +0x538 | **Agree High** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed policy.

---

## 6. Open questions

1. Assembly-level bucket index before 004e2ca0 (bit-exact).
2. Other remove twin VAs / vtbl families.
3. Whether freelist nodes need vtbl restore on pop (insert sets vtbl after alloc — **yes** insert path resets).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; **block Lookup-only remove and plain free**.
