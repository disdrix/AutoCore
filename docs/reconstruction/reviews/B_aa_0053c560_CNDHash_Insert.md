# Review B (skeptical / adversarial): `aa_0053c560` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c560` |
| **VA** | `0x0053c560` |
| **Canonical name** | `CNDHash_Insert` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053c560_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `allowDuplicate` means multi-value / multi-node same key allowed | Soft path returns 1 **without** linking a second node; hard path always fails on hit | **Falsified** multi-insert — soft-skip only |
| 2 | Locked traversal aborts insert | Body logs then falls through to lookup/alloc | **Falsified** hard abort — warn-only |
| 3 | Signed returns `-0x7fffbffd` / `-0x7fffbffb` are unique error domain | u32 form `0x80004003` / `0x80004005`; twins print HRESULT hex | **Attack fails** — same E_POINTER / E_FAIL |
| 4 | This VA is the only CNDHash insert in the client | GiveMission uses `0053c360` / `0053c660` (same CF, different vtbl) | **Falsified** exclusivity — **twin family** |
| 5 | Same vtbl as mission inserts | This body writes `PTR_FUN_009cefd4`; twins `009cf024` / `009cefe4` | **Falsified** shared vtbl |
| 6 | `FUN_0053ada0()` is parameterless global malloc | Allocator is freelist/slab (`_aligned_malloc(700)`, carve 7 dwords); ECX freelist context elided | **Attack partial** — role High; ECX source Open |
| 7 | `FUN_00537d30` is rehash / grow | Walks bucket chain marking `node+4`; repair on re-touch | **Falsified** grow — integrity only |
| 8 | List links are bucket links | Bucket uses `+0x0c`; list uses `+0x14/+0x18` + hash `+0x14/+0x18` | **Attack fails** — dual linkage sealed |
| 9 | Callers pass soft flag | Unlock + ApplyCreate both pass `'\0'` | **Agree** hard-duplicate path only at known sites |
| 10 | force_decompile would change CF | force ≡ first decompile 2026-07-29 | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert role + HRESULT returns | **Confirmed** | Wrong error handling on null/dup |
| Soft vs hard duplicate policy | **High** | Port multi-insert bug if misread name |
| Hash fields +8/+c/+10/+14/+18/+1d | **High** | Corrupt wrong offsets on port |
| Node layout 0x1c + vtbl 009cefd4 | **High** | Wrong node size / dtor |
| Bucket head-insert sentinel+4 | **High** | Break Lookup walk |
| Twin insert VAs are separate | **High** | Conflate mission vs continent node types |
| Freelist this-offset | **Open** | Wrong allocator context for hooks |
| Full hash ctor / mask origin | **Open** | Capacity / rehash unknown |
| Runtime | **Open** | No live insert capture |

---

## 3. Cross-check against raw / live / twins

```
raw/clean scaffold CF ≡ live decompile ≡ force_decompile (2026-07-29).

HRESULT:
  -0x7fffbffd → 0x80004003 (E_POINTER)
  -0x7fffbffb → 0x80004005 (E_FAIL)
  twins 0053c360 / 0053c660 return unsigned 0x80004003 / 0x80004005 — same bits.

Xrefs (this VA only):
  00531ce9  CVOGReaction_UnlockContinentObject  — char+0x534, allowDup=0
  0053504f  CVOGCharacter_ApplyCreateFromPacket — continent slot payload, allowDup=0

Strings (body):
  "HashError:insert, already locked for traversal"
  "VOG_DEBUG_STOP"
  "Duplicate hash insert %u, failing out"
```

### Soft-flag trap

Do **not** implement `allowDuplicate` as “push another node with same key.” Policy is:

- flag **0**: key present → fail `E_FAIL`
- flag **≠0**: key present → **return 1**, leave map unchanged

Known callers of **this** VA always pass 0.

### Twin trap

Do **not** redirect mission `FUN_0053c360` / `FUN_0053c660` call sites to `0x0053c560`. Control flow matches; **node vtbl differs** (likely different node methods / value ownership). Continent unlock / create-packet path owns this vtbl `009cefd4`.

### Allocator trap

`FUN_0053ada0` is **not** `operator_new(sizeof node)`. It pops from a freelist built in 700-byte aligned slabs, nodes stride **0x1c**. Hooking with plain malloc without freelist semantics will desync the pool.

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert(hash, key, value, softIfExists) -> int
  value==null           -> 0x80004003
  softIfExists && hit   -> 1   (no mutation)
  !soft && hit          -> 0x80004005 (+ log)
  else                  -> alloc node (vtbl 009cefd4), bucket head-insert,
                           list append, count++, return 0

// lock +0x1d: log only; insert still proceeds

Node (0x1c):
  +00 vtbl  +04 touch  +08 value*  +0c bucketNext  +10 key
  +14 listNext  +18 listPrev

Hash (partial):
  +08 mask  +0c count  +10 buckets*  +14 listHead  +18 listTail  +1d lock

This VA callers:
  UnlockContinentObject(char+0x534)
  ApplyCreateFromPacket(continent slot hash)

AutoCore must NOT:
  - treat allowDuplicate as multi-map insert
  - abort on lock without logging (or invent hard fail)
  - merge twin insert VAs / vtbls
  - use operator_new for these nodes
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Signature thiscall key/value/flag → int | **Agree High** |
| HRESULTs E_POINTER / E_FAIL | **Agree Confirmed** |
| Soft-skip semantics of allowDuplicate | **Agree High** (name misleading) |
| Lock warn-only | **Agree High** |
| Layout mask/count/buckets/list/lock | **Agree High** |
| Node fields + vtbl 009cefd4 | **Agree High** |
| Twin family separate | **Agree High** |
| Freelist this-offset Open | **Agree** |
| clean ≡ raw ≡ live ≡ force | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed CF. Naming nit only — prefer documenting soft-skip over literal “allow duplicate.”

---

## 6. Open questions

1. Freelist header offset relative to `CNDHash*` for `FUN_0053ada0` ECX.
2. Whether any non-decompiled site calls this VA with soft flag ≠ 0 (static xrefs: only hard).
3. Node vtbl method table contents at `009cefd4` (dtor / free path) — sibling dual.
4. Runtime continent unlock insert success path.
5. Bit-exact vs retail.

**Verdict:** **accept-with-gaps** — agree with A; block multi-insert misread, twin merge, and plain-malloc node alloc.
