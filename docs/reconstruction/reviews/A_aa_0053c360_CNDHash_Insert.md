# Review A (reconstruction fidelity): `aa_0053c360` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c360` |
| **VA** | `0x0053c360` |
| **Canonical name** | `CNDHash_Insert` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053c360_CNDHash_Insert.md` |
| **System** | container / missions-progression (active-mission hash inserts) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object (mission-node vtbl family):

1. Reject null `value` → **HRESULT `0x80004003`** (`E_POINTER`).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort**.
3. If `allowDuplicate != 0` and `CNDHash_LookupByKey` hits → **return 1** (soft success, **no insert**).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **HRESULT `0x80004005`** (`E_FAIL`).
5. Allocate hash **node** via `FUN_0053ada0` (slab freelist, **0x1c** nodes).
6. Init node: vtbl **`PTR_LAB_009cf024`**, touch-flag byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket-next `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; bucket table `*(this+0x10)`; head-insert at sentinel `+4`; call `FUN_00537d30` (bucket-chain integrity walk).
8. Append to global list: head `this+0x14`, tail `this+0x18`; bump count `this+0xc`; return **0**.

Primary GiveMission sites: **`char+0x540`** then optional **`char+0x544`** (paired active hashes; not same-hash double). Also CompleteObjective / ApplyCreateFromPacket / `FUN_0060b870`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053c360_FUN_0053c360.md` |
| Annotated | `docs/reconstruction/raw/aa_0053c360_FUN_0053c360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053c360.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053c360_FUN_0053c360.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0053c360` (2026-07-29) |
| Twin inserts | `0x0053c660` (vtbl `009cefe4`), `0x0053c560` (vtbl `009cefd4`) — same CF |
| Lookup sibling | `CNDHash_LookupByKey` |
| Allocator | `FUN_0053ada0` |
| Bucket repair | `FUN_00537d30` |
| Callers (complete analysis) | `CVOGReaction_GiveMission`, `CVOGReaction_CompleteObjective`, `CVOGCharacter_ApplyCreateFromPacket`, `FUN_0060b870` |
| Vtbl bytes | `read_memory` @ `0x009cf024` |
| Prior residual | `reviews/a_005327c0.md` (call-site this map) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void *value, char allowDuplicate)` | **High** | locals: ECX + Stack 4/8/c |
| Null value → `0x80004003` | **Confirmed** | body |
| Hard duplicate → `0x80004005` | **Confirmed** | body + string |
| Soft path `allowDuplicate!=0` + hit → return **1** (no insert) | **High** | body |
| Lock byte `this+0x1d` only logs (no early return) | **High** | fall-through after dual log |
| Mask `this+8`, count `this+0xc`, buckets `this+0x10`, list head `+0x14`, tail `+0x18` | **High** | body |
| Node: vtbl+0, flag+4, value+8, nextBucket+0xc, key+0x10, listNext+0x14, listPrev+0x18 | **High** | insert writes |
| Node vtbl this variant = `PTR_LAB_009cf024` | **High** | body; `read_memory` first dword `0x00537cf0` |
| Head-insert at `bucketSentinel+4` | **High** | insert |
| `FUN_0053ada0` = freelist node alloc (0x1c) | **High** (role) | freelist ECX source Open |
| `FUN_00537d30` = bucket chain touch-flag integrity | **High** (role) | |
| Success return **0**; count++ | **Confirmed** | both list arms |
| Twin family same CF, different vtbl (`0053c660` / `0053c560`) | **High** | batch_decompile |
| GiveMission: +0x540 then optional +0x544 (not double +0x540) | **High** | residual asm + end-quest dual remove |
| Product English for soft flag | **Probable** | soft-skip; known grant sites pass 0 |
| clean ≡ raw ≡ live CF | **High** | 2026-07-29 re-decompile |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null value → E_POINTER | Y | Y | Y |
| Lock log + continue | Y | Y | Y |
| Soft allowDuplicate early return 1 | Y | Y | Y |
| Hard duplicate log + E_FAIL | Y | Y | Y |
| Alloc + node init + vtbl 009cf024 | Y | Y | Y |
| Bucket head-insert + FUN_00537d30 | Y | Y | Y |
| Non-empty list: link at tail | Y | Y | Y |
| Empty list: head=tail=new | Y | Y | Y |
| count++ ; return 0 | Y | Y | Y |
| Invented branches / deleted arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// Node vtbl = PTR_LAB_009cf024 (mission-style family)

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
n->vtbl = PTR_LAB_009cf024;
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
| `param_2` | `key` | stored node+0x10 |
| `param_3` | `value` | null-check; stored node+0x08 |
| `param_4` / `allowDuplicate` | soft-skip-if-exists | `!=0` + hit → return 1 |
| `puVar3` | `node` | freelist 0x1c |
| `iVar1` | `bucketSentinel` | `buckets[key&mask]` |
| `pvVar2` | `existing` | Lookup result |

---

## 6. Layout (sealed from this body + Lookup)

### CNDHash (partial)

| Off | Field | Evidence |
|---|---|---|
| +0x08 | `mask` | `key & *(this+8)` |
| +0x0c | `count` | ++ on success |
| +0x10 | `buckets*` | array of sentinels |
| +0x14 | `listHead` | empty-list init |
| +0x18 | `listTail` | append path |
| +0x1d | `lockedForTraversal` | char; warn only |

### Node (vtbl `009cf024` family)

| Off | Field | Evidence |
|---|---|---|
| +0x00 | vtbl | `PTR_LAB_009cf024` |
| +0x04 | touch flag (byte) | init 0 |
| +0x08 | value* | payload |
| +0x0c | next in bucket | head-insert |
| +0x10 | key (uint) | |
| +0x14 | list next | toward tail |
| +0x18 | list prev | toward head |

---

## 7. Callers / mission map (this VA)

| Caller | Role of `this` (evidence) | Conf |
|---|---|---|
| `CVOGReaction_GiveMission` | `char+0x540` then optional `char+0x544` | **High** (residual asm) |
| `CVOGReaction_CompleteObjective` | mission hash roots on character | **High** (xref) |
| `CVOGCharacter_ApplyCreateFromPacket` | create-path mission hashes | **High** (xref) |
| `FUN_0060b870` | secondary grant/import path | **Probable** |

**Do not** merge call sites with twin VAs `0x0053c660` / `0x0053c560` — same CF, different node vtbl / value ownership.

---

## 8. Gaps / open questions

1. Freelist ECX into `FUN_0053ada0` — decompiler elides; this-offset of freelist header **Open** (remove twin seals freelist at `hash+0x20` for reclaim).
2. Product English for `char+0x544` (paired active vs journal-shadow).
3. Soft-flag product name beyond Ghidra `allowDuplicate`.
4. Runtime insert success/fail capture not observed.
5. Bit-exact vs retail image deferred.
6. Full node vtbl method table at `009cf024` (dtor / free) — sibling dual.

**Verdict:** **accept-with-gaps** — CF + vtbl + mission insert role sealed High; freelist this-link + product names residual.
