# Review A (reconstruction fidelity): `aa_0053c460` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c460` |
| **VA** | `0x0053c460` |
| **Canonical name** | `CNDHash_Insert` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053c460_CNDHash_Insert.md` |
| **System** | container / missions-progression (active-objective **def** hash) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object (**objective-def node vtbl** family):

1. Reject null `value` → **HRESULT `0x80004003`** (`E_POINTER`).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort**.
3. If `allowDuplicate != 0` and `CNDHash_LookupByKey` hits → **return 1** (soft success, **no insert**).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **HRESULT `0x80004005`** (`E_FAIL`).
5. Allocate hash **node** via `FUN_0053ada0` (slab freelist, **0x1c** nodes).
6. Init node: vtbl **`PTR_LAB_009cf02c`**, touch-flag byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket-next `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; bucket table `*(this+0x10)`; head-insert at sentinel `+4`; call `FUN_00537d30` (bucket-chain integrity walk).
8. Append to global list: head `this+0x14`, tail `this+0x18`; bump count `this+0xc`; return **0**.

**Only CF difference vs twin family (`0x0053c360` / `0x0053c660` / `0x0053c560` / `0x0053c760`):** node vtbl constant (`009cf02c` here).

Primary plate: `CVOGMission_AddActiveObjective` inserts objective **def** into **`char+0x548`** (active-objectives hash), key=`objId`, value=`objDef*`, soft=`0`. Also ApplyCreateFromPacket + grant helpers `FUN_0060b870` / `FUN_0060bb80`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053c460_FUN_0053c460.md` |
| Annotated | `docs/reconstruction/raw/aa_0053c460_FUN_0053c460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053c460.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053c460_FUN_0053c460.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0053c460` (2026-07-29) |
| Twin inserts | `0x0053c360` (`009cf024`), `0x0053c660` (`009cefe4`), `0x0053c560` (`009cefd4`), `0x0053c760` (`009cefec`) — same CF |
| Lookup sibling | `CNDHash_LookupByKey` |
| Allocator | `FUN_0053ada0` |
| Bucket repair | `FUN_00537d30` |
| Callers (complete analysis) | `CVOGMission_AddActiveObjective`, `CVOGCharacter_ApplyCreateFromPacket`, `FUN_0060b870`, `FUN_0060bb80` |
| Xrefs (4) | `00531b15`, `00535465`, `0060bad8`, `0060bd87` |
| Vtbl bytes | `read_memory` @ `0x009cf02c` → method0 `0x00537d10` |
| Prior residual | `reviews/a_00531b00.md` (AddActiveObjective ECX map +0x548) |

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
| Node vtbl this variant = `PTR_LAB_009cf02c` | **High** | body; `read_memory` first dword `0x00537d10` |
| Head-insert at `bucketSentinel+4` | **High** | insert |
| `FUN_0053ada0` = freelist node alloc (0x1c) | **High** (role) | freelist ECX source Open |
| `FUN_00537d30` = bucket chain touch-flag integrity | **High** (role) | |
| Success return **0**; count++ | **Confirmed** | both list arms |
| CF bitwise-equivalent to twin family except vtbl imm | **Confirmed** | batch_decompile side-by-side vs `0053c360`/`0053c760` |
| AddActiveObjective `this` = `char+0x548` | **High** | residual asm `0x00531b0b`–`0x00531b15` |
| Payload role = objective **def** pointer (not state node) | **High** | residual: push ESI=objDef |
| Soft flag at this call site = `0` | **High** | residual `push 0` |
| 4 static xrefs | **Confirmed** | complete analysis |
| clean ≡ raw ≡ live CF | **High** | 2026-07-29 re-decompile |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null value → E_POINTER | Y | Y | Y |
| Lock log + continue | Y | Y | Y |
| Soft allowDuplicate early return 1 | Y | Y | Y |
| Hard duplicate log + E_FAIL | Y | Y | Y |
| Alloc + node init + vtbl **009cf02c** | Y | Y | Y |
| Bucket head-insert + FUN_00537d30 | Y | Y | Y |
| Non-empty list: link at tail | Y | Y | Y |
| Empty list: head=tail=new | Y | Y | Y |
| count++ ; return 0 | Y | Y | Y |
| Invented branches / deleted arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// Node vtbl = PTR_LAB_009cf02c (objective-def family; twin of 009cf024 mission-def)

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
n->vtbl = PTR_LAB_009cf02c;
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
| `param_2` | `key` | stored node+0x10; AddActiveObjective = objId |
| `param_3` | `value` / `objDef*` | null-check; stored node+0x08 |
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

### Node (vtbl `009cf02c` family)

| Off | Field | Evidence |
|---|---|---|
| +0x00 | vtbl | `PTR_LAB_009cf02c` |
| +0x04 | touch flag (byte) | init 0 |
| +0x08 | value* | payload (obj def*) |
| +0x0c | next in bucket | head-insert |
| +0x10 | key (uint) | objId |
| +0x14 | list next | toward tail |
| +0x18 | list prev | toward head |

`read_memory @ 0x009cf02c`: method0 = `0x00537d10` (adjacent to mission-def method0 `0x00537cf0` @ `009cf024`).

---

## 7. Callers / objective map (this VA)

| Caller | Role of `this` / payload (evidence) | Conf |
|---|---|---|
| `CVOGMission_AddActiveObjective` @ `00531b15` | `char+0x548`; key=objId; value=objDef*; soft=0 | **High** (residual asm) |
| `CVOGCharacter_ApplyCreateFromPacket` @ `00535465` | create-path active-objective def hash | **High** (xref); exact off Open |
| `FUN_0060b870` @ `0060bad8` | secondary grant/import path | **Probable** |
| `FUN_0060bb80` @ `0060bd87` | secondary grant/import path | **Probable** |

**Do not** merge call sites with twin VA `0x0053c760` — same CF, different node vtbl / value ownership (`char+0x55c` state node).

---

## 8. Gaps / open questions

1. Freelist ECX into `FUN_0053ada0` — decompiler elides; this-offset of freelist header **Open** (remove twin seals freelist at `hash+0x20` for reclaim).
2. Product English for `char+0x548` vs `+0x55c` pair beyond residual “active objectives / pending”.
3. Soft-flag product name beyond Ghidra `allowDuplicate`; static AddActiveObjective sites pass 0.
4. Exact hash root offsets for ApplyCreateFromPacket / `0060b870` / `0060bb80` sites.
5. Full node vtbl method table at `009cf02c` (dtor / free) — method0 only sealed.
6. Runtime insert success/fail capture not observed; bit-exact deferred.

**Verdict:** **accept-with-gaps** — CF + vtbl `009cf02c` + AddActiveObjective `+0x548` def-insert role sealed High; freelist this-link + secondary-caller offsets residual.
