# Review A (reconstruction fidelity): `aa_0053c760` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c760` |
| **VA** | `0x0053c760` |
| **Canonical name** | `CNDHash_Insert` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053c760_CNDHash_Insert.md` |
| **System** | container / missions-progression (objective **state-node** hash) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object (**objective state-node vtbl** family):

1. Reject null `value` → **HRESULT `0x80004003`** (`E_POINTER`).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort**.
3. If `allowDuplicate != 0` and `CNDHash_LookupByKey` hits → **return 1** (soft success, **no insert**).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **HRESULT `0x80004005`** (`E_FAIL`).
5. Allocate hash **node** via `FUN_0053ada0` (slab freelist, **0x1c** nodes).
6. Init node: vtbl **`PTR_FUN_009cefec`**, touch-flag byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket-next `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; bucket table `*(this+0x10)`; head-insert at sentinel `+4`; call `FUN_00537d30`.
8. Append to global list head/tail; bump count; return **0**.

**Only CF difference vs twin family (`0x0053c360` / `0x0053c460` / `0x0053c560` / `0x0053c660`):** node vtbl constant (`009cefec` here).

Primary plate: `CVOGMission_AddActiveObjective` inserts runtime **state node** into **`char+0x55c`** (pending/objective-state hash), key=`objId`, value=`stateNode*`, soft=`0`. Also `FUN_00531bd0` (2 xrefs total).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053c760_FUN_0053c760.md` |
| Annotated | `docs/reconstruction/raw/aa_0053c760_FUN_0053c760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053c760.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053c760_FUN_0053c760.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0053c760` (2026-07-29) |
| Twin inserts | `0x0053c460` (`009cf02c` def), `0x0053c360` (`009cf024`), `0x0053c660` (`009cefe4`), `0x0053c560` (`009cefd4`) |
| Vtbl bytes | `read_memory` @ `0x009cefec` → method0 `0x00537550`, method2 `0x00537630`, … |
| Callers | `CVOGMission_AddActiveObjective`, `FUN_00531bd0` (2 xrefs) |
| Xrefs | `00531b77`, `00531c72` |
| Prior residual | `reviews/a_00531b00.md` (AddActiveObjective ECX map +0x55c) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void *value, char allowDuplicate)` | **High** | ECX + Stack 4/8/c |
| Null → `0x80004003`; hard dup → `0x80004005`; soft hit → 1; success → 0 | **Confirmed** | body ≡ twin |
| Lock `+0x1d` warn-only | **High** | |
| Hash fields mask/count/buckets/list | **High** | identical to twin |
| Node layout 0x1c | **High** | identical write pattern |
| Node vtbl = `PTR_FUN_009cefec` | **High** | sole CF delta vs 0053c460; `read_memory` method0=`0x00537550` |
| CF bitwise-equivalent to 0053c460 except vtbl imm | **Confirmed** | batch_decompile side-by-side |
| AddActiveObjective `this` = `char+0x55c` | **High** | residual asm `0x00531b6f`–`0x00531b77` |
| Payload role = objective **state node** (not def) | **High** | residual: push EBX=node |
| Soft flag at this call site = `0` | **High** | residual `push 0` |
| Failed insert at AddActiveObjective → `operator_delete` node + fall-through | **High** | residual (caller CF; not this body) |
| Only 2 static xrefs | **Confirmed** | complete analysis |
| clean ≡ raw ≡ live | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null / lock / soft / hard / alloc / bucket / list / count | Y | Y | Y |
| Node vtbl **009cefec** (not 009cf02c) | Y | Y | Y |
| Invented branches | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// IDENTICAL to 0x0053c460 except:
//   n->vtbl = PTR_FUN_009cefec;   // not PTR_LAB_009cf02c

if (value == NULL) return 0x80004003;
if (this->lockedForTraversal) { log lock; log VOG_DEBUG_STOP; }
if (softIfExists && Lookup(this, key)) return 1;
if (Lookup(this, key)) { log duplicate; return 0x80004005; }
Node *n = NodeAlloc();
n->vtbl = PTR_FUN_009cefec;
// ... same init, bucket head-insert, list append, count++ ...
return 0;
```

---

## 5. Param / local renames

| Raw | Preferred | Evidence |
|---|---|---|
| `this` | `hash` / `CNDHash*` | ECX |
| `param_2` | `key` | node+0x10; AddActiveObjective objId |
| `param_3` | `value` / `stateNode*` | node+0x08; residual EBX |
| `param_4` | soft-skip-if-exists | same as twin |
| `puVar3` | `node` | freelist |

---

## 6. Layout

Same partial **CNDHash** and **node** layout as `0x0053c460` (see twin dual), except:

| Off | This VA | Twin `0053c460` |
|---|---|---|
| node+0x00 vtbl | **`009cefec`** | `009cf02c` |

`read_memory @ 0x009cefec` first slots (LE dwords):

| Slot | Address |
|---|---|
| method0 | `0x00537550` |
| slot1 | `0x00aad148` |
| method2 | `0x00537630` |
| slot3 | `0x00aad190` |
| method4 | `0x00537650` |
| slot5 | `0x00aad1d8` |
| method6 | `0x00537670` |
| slot7 | `0x00aad220` |

Distinct from `009cf02c` (method0 `0x00537d10`) and from mission state-blob `009cefe4` (method0 `0x00537510`).

---

## 7. Callers

| Caller | `this` / payload (evidence) | Conf |
|---|---|---|
| `CVOGMission_AddActiveObjective` @ `00531b77` | `char+0x55c`; key=objId; value=stateNode*; soft=0 | **High** |
| `FUN_00531bd0` @ `00531c72` | sibling objective-state path | **High** (xref); exact off Open |

---

## 8. Gaps / open questions

1. Freelist ECX into `FUN_0053ada0` Open.
2. Full product English for `char+0x55c` bind blob / state-node fields.
3. Full vtbl method semantics at `009cefec` (why separate from def node `009cf02c`).
4. Soft flag ever non-zero on this VA (static sites: 0).
5. Exact hash root for `FUN_00531bd0` (likely `+0x55c` or sibling).
6. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — twin insert role High; **vtbl `009cefec` + `+0x55c` state-node ownership is the port-critical seal**.
