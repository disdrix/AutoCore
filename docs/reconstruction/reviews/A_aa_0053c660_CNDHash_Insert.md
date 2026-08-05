# Review A (reconstruction fidelity): `aa_0053c660` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c660` |
| **VA** | `0x0053c660` |
| **Canonical name** | `CNDHash_Insert` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053c660_CNDHash_Insert.md` |
| **System** | container / missions-progression (mission state-blob hash) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object (**state-blob node vtbl** family):

1. Reject null `value` → **HRESULT `0x80004003`** (`E_POINTER`).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort**.
3. If `allowDuplicate != 0` and `CNDHash_LookupByKey` hits → **return 1** (soft success, **no insert**).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **HRESULT `0x80004005`** (`E_FAIL`).
5. Allocate hash **node** via `FUN_0053ada0` (slab freelist, **0x1c** nodes).
6. Init node: vtbl **`PTR_FUN_009cefe4`**, touch-flag byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket-next `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; bucket table `*(this+0x10)`; head-insert at sentinel `+4`; call `FUN_00537d30`.
8. Append to global list head/tail; bump count; return **0**.

**Only CF difference vs `0x0053c360` / `0x0053c560`:** node vtbl constant (`009cefe4` here).

GiveMission: insert into **`char+0x530`** with key=`*def`, payload=**0x30** runtime state blob (soft=0). Also ApplyCreateFromPacket.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053c660_FUN_0053c660.md` |
| Annotated | `docs/reconstruction/raw/aa_0053c660_FUN_0053c660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053c660.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053c660_FUN_0053c660.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0053c660` (2026-07-29) |
| Twin inserts | `0x0053c360` (`009cf024`), `0x0053c560` (`009cefd4`) |
| Vtbl bytes | `read_memory` @ `0x009cefe4` |
| Callers | `CVOGReaction_GiveMission`, `CVOGCharacter_ApplyCreateFromPacket` (2 xrefs) |
| Prior residual | `reviews/a_005327c0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void *value, char allowDuplicate)` | **High** | ECX + Stack 4/8/c |
| Null → `0x80004003`; hard dup → `0x80004005`; soft hit → 1; success → 0 | **Confirmed** | body ≡ twin |
| Lock `+0x1d` warn-only | **High** | |
| Hash fields mask/count/buckets/list | **High** | identical to twin |
| Node layout 0x1c | **High** | identical write pattern |
| Node vtbl = `PTR_FUN_009cefe4` | **High** | sole CF delta vs 0053c360; `read_memory` method0=`0x00537510` |
| CF bitwise-equivalent to 0053c360 except vtbl imm | **Confirmed** | batch_decompile side-by-side |
| GiveMission `this` = `char+0x530` | **High** | residual asm |
| Payload role = 0x30 state blob (not mission def) | **High** | residual; blob init `0x004111f0` |
| Key = mission id from `*def` | **High** | residual |
| Only 2 static xrefs | **Confirmed** | complete analysis |
| clean ≡ raw ≡ live | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null / lock / soft / hard / alloc / bucket / list / count | Y | Y | Y |
| Node vtbl **009cefe4** (not 009cf024) | Y | Y | Y |
| Invented branches | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// IDENTICAL to 0x0053c360 except:
//   n->vtbl = PTR_FUN_009cefe4;   // not PTR_LAB_009cf024

if (value == NULL) return 0x80004003;
if (this->lockedForTraversal) { log lock; log VOG_DEBUG_STOP; }
if (softIfExists && Lookup(this, key)) return 1;
if (Lookup(this, key)) { log duplicate; return 0x80004005; }
Node *n = NodeAlloc();
n->vtbl = PTR_FUN_009cefe4;
// ... same init, bucket head-insert, list append, count++ ...
return 0;
```

---

## 5. Param / local renames

| Raw | Preferred | Evidence |
|---|---|---|
| `this` | `hash` / `CNDHash*` | ECX |
| `param_2` | `key` | node+0x10; GiveMission `*def` |
| `param_3` | `value` / `stateBlob*` | node+0x08; 0x30 alloc path |
| `param_4` | soft-skip-if-exists | same as twin |
| `puVar3` | `node` | freelist |

---

## 6. Layout

Same partial **CNDHash** and **node** layout as `0x0053c360` (see twin dual), except:

| Off | This VA | Twin `0053c360` |
|---|---|---|
| node+0x00 vtbl | **`009cefe4`** | `009cf024` |

`read_memory @ 0x009cefe4`: method slots `0x00537510`, `0x00aad100`, `0x00537550`, `0x00aad148` — distinct from `009cf024` table.

---

## 7. Callers

| Caller | `this` / payload (evidence) | Conf |
|---|---|---|
| `CVOGReaction_GiveMission` @ `005329e2` | `char+0x530`; key=`*def`; value=0x30 blob; soft=0 | **High** |
| `CVOGCharacter_ApplyCreateFromPacket` @ `005354e6` | create-path state hash | **High** (xref); exact off Open |

---

## 8. Gaps / open questions

1. Freelist ECX into `FUN_0053ada0` Open.
2. Full product English for `char+0x530` bind blob (fields of 0x30).
3. Full vtbl method semantics at `009cefe4` (why separate from mission-def node).
4. Soft flag ever non-zero on this VA (static sites: 0).
5. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — twin insert role High; **vtbl separation is the port-critical seal**.
