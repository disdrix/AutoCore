# Review A (reconstruction fidelity): `aa_004d4790` Object_QueueDelete

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4790` |
| **VA** | `0x004d4790` |
| **Canonical name** | `FUN_004d4790` (proposed: `Object_QueueDelete` / `CVOGObject_AddToDeleteQueue`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d4790_Object_QueueDelete.md` |
| **System** | `missions-progression` (also inventory / world object lifecycle) |
| **Verdict** | **accept** on CF + string-sealed role; multi-caller lifecycle unit |

---

## 1. Purpose

Queue a **world object for delete**:

1. Read object COID dwords `this[0x58]` / `this[0x59]` (offsets 0x160 / 0x164).
2. If inactive-objects hash still holds entry (`FUN_004e23d0` + `+0xc`): log **literal**  
   `"... being added to delete cue, but still in InactiveObjectsHas.\n"` via `FUN_007a4480`, then `FUN_004bcda0`.
3. Optional deferred callback `FUN_00405920(&LAB_004cd580, obj)` if `FUN_004e15a0()` nonzero.
4. Vtable call `obj->vtbl[+0x2a8]()`.
5. `FUN_004024d0(obj)`.
6. `obj[0x5f] |= 2` (flags at +0x17c bit 1).

CompleteObjective: when local reward COID fails filter (not wildcard and not matching `rewardCoidLo/Hi`), delete the resolved reward object instead of `Client_SendInventoryAddItem`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / fn | scaffold `aa_004d4790_*` |
| Live decompile + xrefs | `analyze_function_complete` (17 xrefs) |
| Call site CO | `0x005343b8` |
| Parent residual | `reviews/a_00533f90.md` |

---

## 3. Signature

```c
void /* convention: stack this/object ptr; listing RET without n → cdecl-ish */
Object_QueueDelete(void* pObject);
```

Call sites typically `PUSH obj; CALL` (CompleteObjective) or ECX setup from inventory paths — treat **object pointer** as primary formal; verify per-site.

String seal: product English **delete queue** + **InactiveObjects** hash warning.

---

## 4. CompleteObjective use

```text
; after FUN_005875c0 unregister
; if reward filter not match wildcard and not exact COID match:
TEST entity
JZ skip
PUSH resolvedObject
CALL 0x004d4790
; else path: Client_SendInventoryAddItem(resolved, 1)
```

Role: **discard non-matching mission reward world object** rather than grant.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Delete-queue role | **High** | format string |
| Flag `\|2` at +0x17c region | **High** CF | `param_1[0x5f]` |
| Vtable +0x2a8 teardown hook | **High** CF | product name open |
| InactiveObjects warn path | **High** | |
| CompleteObjective COID filter pairing | **High** | parent dual |
| Full multi-caller inventory semantics | **Probable** | many xrefs |

---

## 6. Surviving contract

```
QueueDelete(object):
  warn if still in InactiveObjects hash
  optional deferred callback
  vcall +0x2a8
  helper FUN_004024d0
  object.flags |= 2
// Mission path: delete reward objects that fail COID filter instead of inventory add.
```
