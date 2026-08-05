# Review A (reconstruction fidelity): `aa_0053c560` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c560` |
| **VA** | `0x0053c560` |
| **Canonical name** | `CNDHash_Insert` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053c560_CNDHash_Insert.md` |
| **Residual scratch** | `reviews/a_0053c560.md` |
| **System** | container / missions-progression (continent unlock hash callers) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object:

1. Reject null `value` → **HRESULT `0x80004003`** (`E_POINTER`; decompiler signed `-0x7fffbffd`).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort** (continues insert).
3. If `allowDuplicate != 0` and `CNDHash_LookupByKey` hits → **return 1** (soft success, **no insert**).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **HRESULT `0x80004005`** (`E_FAIL`; signed `-0x7fffbffb`).
5. Allocate hash **node** via `FUN_0053ada0` (slab freelist of **0x1c** / 7-dword nodes).
6. Init node: vtbl `PTR_FUN_009cefd4`, touch-flag byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket-next `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; bucket table `*(this+0x10)`; head-insert at sentinel `+4`; call `FUN_00537d30` (bucket-chain integrity walk).
8. Append to global list: head `this+0x14`, tail `this+0x18`; bump count `this+0xc`; return **0**.

Plate / callers: **continent unlock** hash (`char+0x534`) via `CVOGReaction_UnlockContinentObject`; CreateCharacterExtended continent slots via `CVOGCharacter_ApplyCreateFromPacket`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053c560_CNDHash_Insert.md` |
| Annotated | `docs/reconstruction/raw/aa_0053c560_CNDHash_Insert.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Insert.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053c560_CNDHash_Insert.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0053c560` (2026-07-29) |
| Force redecompile | Ghidra `force_decompile` @ `0x0053c560` — **identical CF** |
| Complete analysis | `analyze_function_complete` — 2 xrefs, callees listed |
| Twin inserts (evidence only) | `FUN_0053c360` / `FUN_0053c660` — same CF, different node vtbl |
| Lookup sibling | `CNDHash_LookupByKey` — confirms node key `+0x10`, value `+0x08`, chain `+0x0c` |
| Allocator | `FUN_0053ada0` — 700-byte slabs, carve `+7` dwords (0x1c) |
| Bucket repair | `FUN_00537d30` — walk `+0xc`, mark byte `+0x04` |
| Callers | `CVOGReaction_UnlockContinentObject` `0x00531c80`; `CVOGCharacter_ApplyCreateFromPacket` `0x00534bd0` |
| Vtbl bytes | `read_memory` @ `0x009cefd4` (node vtbl slot used by this insert) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void *value, char allowDuplicate)` | **High** | complete analysis params: ECX + Stack 4/8/c |
| Null value → `0x80004003` / signed `-0x7fffbffd` | **Confirmed** | body; ≡ twin `0x80004003`; u32(`-0x7fffbffd`)=`0x80004003` |
| Hard duplicate → `0x80004005` / signed `-0x7fffbffb` | **Confirmed** | body + twin unsigned form |
| Soft path `allowDuplicate!=0` + hit → return **1** (no insert) | **High** | body; name is Ghidra’s — semantics = soft-skip-if-exists |
| Lock byte `this+0x1d` only logs (no early return) | **High** | body falls through after dual log |
| Mask `this+8`, count `this+0xc`, buckets `this+0x10`, list head `+0x14`, tail `+0x18` | **High** | body + Lookup sibling |
| Node: vtbl+0, flag+4, value+8, nextBucket+0xc, key+0x10, listNext+0x14, listPrev+0x18 | **High** | insert writes + Lookup reads key/value/next |
| Node vtbl this variant = `PTR_FUN_009cefd4` | **High** | body; twins use `009cf024` / `009cefe4` |
| Head-insert at `bucketSentinel+4` | **High** | insert + Lookup first node |
| `FUN_0053ada0` = freelist node alloc (0x1c) | **High** (role) | freelist ECX source / this-offset **Open** |
| `FUN_00537d30` = bucket chain touch-flag integrity | **High** (role) | strings `"HashListError: Went to node…"` |
| Success return **0**; count++ | **Confirmed** | both list arms |
| Callers only UnlockContinent + ApplyCreate (this VA) | **Confirmed** | 2 xrefs; mission inserts use twin VAs |
| Twin family (same CF, different vtbl) `0053c360` / `0053c660` | **High** | batch_decompile; **not** this VA |
| Product English for `allowDuplicate` | **Probable** | soft-skip; callers pass `'\0'` |
| clean ≡ raw ≡ live ≡ force CF | **High** | spot-check 2026-07-29 |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ force

| Stage | Raw | Clean | Live/force |
|---|---|---|---|
| Null value → E_POINTER | Y | Y | Y |
| Lock log + continue | Y | Y | Y |
| Soft allowDuplicate early return 1 | Y | Y | Y |
| Hard duplicate log + E_FAIL | Y | Y | Y |
| Alloc + node init + vtbl 009cefd4 | Y | Y | Y |
| Bucket head-insert + FUN_00537d30 | Y | Y | Y |
| Non-empty list: link at tail | Y | Y | Y |
| Empty list: head=tail=new | Y | Y | Y |
| count++ ; return 0 | Y | Y | Y |
| Invented branches / deleted arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// Ghidra name allowDuplicate == softIfExists (skip insert, return 1 if key present)

if (value == NULL) return 0x80004003;           // E_POINTER
if (this->lockedForTraversal /* +0x1d */) {
  log("HashError:insert, already locked for traversal");
  log("VOG_DEBUG_STOP");
  // continue — no return
}
if (softIfExists && CNDHash_LookupByKey(this, key)) return 1;
if (CNDHash_LookupByKey(this, key)) {
  log("Duplicate hash insert %u, failing out", key);
  return 0x80004005;                            // E_FAIL
}
Node *n = NodeAlloc(/* freelist via FUN_0053ada0 */);
n->vtbl = PTR_FUN_009cefd4;
n->touched = 0;                                 // +0x04
n->value = value;                               // +0x08
n->key = key;                                   // +0x10
// bucket head-insert at sentinel+4; n->bucketNext = old first
BucketRepair(sentinel);                         // FUN_00537d30
// append to doubly-linked list head(+0x14)/tail(+0x18); count(+0xc)++
return 0;
```

---

## 5. Param / local renames (evidence only)

| Raw / Ghidra | Clean / preferred | Evidence |
|---|---|---|
| `this` | `hash` / `CNDHash*` | thiscall ECX; fields +8..+1d |
| `key` | `key` | stack; stored node+0x10; Lookup compare |
| `value` | `value` | null-check; stored node+0x08; Lookup returns this |
| `allowDuplicate` | keep Ghidra name; **semantic** soft-skip-if-exists | `!=0` + hit → return 1 without insert |
| `puVar3` | `node` | 0x1c node from freelist |
| `iVar1` | `bucketSentinel` | `buckets[key&mask]`; `+4` chain head |
| `pvVar2` | `existingValue` | Lookup result |

Callees stay `FUN_*` except already-named `CNDHash_LookupByKey`.

---

## 6. Layout (sealed from this body + Lookup)

### CNDHash (partial)

| Off | Field | Evidence |
|---|---|---|
| +0x08 | `mask` (power-of-2 − 1) | `key & *(this+8)` |
| +0x0c | `count` | incremented on success |
| +0x10 | `buckets*` | array of sentinels |
| +0x14 | `listHead` | empty-list init |
| +0x18 | `listTail` | append path |
| +0x1d | `lockedForTraversal` | char; insert warns only |

### CNDHash node (this vtbl family)

| Off | Field | Evidence |
|---|---|---|
| +0x00 | vtbl | `PTR_FUN_009cefd4` |
| +0x04 | touch flag (byte) | init 0; `FUN_00537d30` marks |
| +0x08 | value* | Lookup return |
| +0x0c | next in bucket | Lookup walk |
| +0x10 | key (uint) | Lookup compare |
| +0x14 | list next (toward newer / tail) | tail→+0x14 = new |
| +0x18 | list prev (toward older / head) | new→+0x18 = old tail |

---

## 7. Gaps / open questions

1. **Freelist ECX** into `FUN_0053ada0` — decompiler elides; this-offset of freelist header **Open**.
2. Exact stack cleanup (`ret` size) not byte-sealed this pass (signature High from Ghidra prototype; callers push 3 stack args).
3. Full CNDHash header before +0x08 (ctor / capacity / freelist embedding) — sibling unit.
4. Product name for soft flag beyond Ghidra `allowDuplicate`.
5. Runtime insert success/fail capture not observed.
6. Bit-exact vs retail image deferred.
7. Twin VAs `0053c360` / `0053c660` are **separate** dual owners (mission active / state-blob); do not merge into this unit.

**Verdict:** **accept-with-gaps** — CF sealed High; freelist this-link + full header residual.
