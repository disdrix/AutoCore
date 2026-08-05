# Review A (reconstruction fidelity): `aa_005210b0` Character_ClearEquippedRaceItemTfId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005210b0` |
| **VA** | `0x005210b0` |
| **Body** | `0x005210b0`–`0x0052112b` (124 bytes) |
| **Canonical name** | `Character_ClearEquippedRaceItemTfId_Inferred` |
| **Prior scaffold** | `FUN_005210b0` |
| **Review date** | `2026-07-29` (W21-E dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` |
| **System** | character race-item equip / inventory / ghost |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Character **equipped race-item TFID teardown**:

1. Gate: TFID at `this+0x518` looks live **and** host component at multi-base `+0xa8` non-null.
2. Resolve world object for TFID (`Object_ResolveFromTFID`, bytes via `*(host+0xe4e8)`).
3. If object non-null: `Object_EnqueueDeferredOnce(host, obj)` — deferred queue, not free-now.
4. Write null TFID template `{0xffffffff,0xffffffff,0,0}` from `DAT_009cee98` into `this+0x518`..`+0x524`.

Parent `Character_SyncEquippedRaceItemFromCbid_Inferred` (`0x00522f70`) calls this on CBID/object mismatch before optional re-give. Does **not** clear CBID `this+0x514`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005210b0` |
| Bytes | `read_memory` 130 B @ entry — ECX this, gates, resolve, enqueue, clear |
| Null template | `read_memory` @ `0x009cee98` → `ff..ff ff..ff 00..00 00..00` |
| Bounds | `get_function_by_address` body `005210b0`–`0052112b` |
| Callers | `get_function_callers` → `FUN_00522f70`, `FUN_0052f260` |
| Callees | `Object_ResolveFromTFID`, `FUN_004d0e90` / `Object_EnqueueDeferredOnce` |
| Parent dual | `A_aa_00522f70_Character_SyncEquippedRaceItemFromCbid_Inferred.md` |
| Raw / clean | `aa_005210b0_*`, `Character_ClearEquippedRaceItemTfId_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX this / no stack formals | **Confirmed** | `mov edi,ecx`; plain `ret` |
| TFID field `+0x518` | **Confirmed** | lea + stores; parent dual agrees |
| Present gate (and / byte) | **Confirmed** | decompile ≡ bytes |
| Host component gate | **Confirmed** | `*( *(this+4)+4 + this + 0xa8)` |
| Resolve + enqueue callees | **Confirmed** | `get_function_callees` + call sites |
| Null template exact | **Confirmed** | `read_memory` 16 B |
| Body **124 bytes** | **Confirmed** | bounds + byte count |
| Role = race-item binding clear | **High** | parent sync + fields |
| Product English “race item” | **Inferred** | vehicle race-item parallel; no plate string here |
| Immediate free/dtor | **Falsified** | enqueue deferred only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| TFID present gate | Yes |
| Host non-null gate | Yes |
| Resolve TFID | Yes (bytes add `host+0xe4e8` intermediate; clean documents) |
| Enqueue deferred once | Yes (ABI corrected vs surface decompile of `FUN_004d0e90`) |
| Write null template 16 B | Yes |
| Early returns when clear/no host | Yes |

---

## 5. Gaps / open

1. Product/PDB symbol for this helper.
2. Full type of `*(host+0xe4e8)` resolve context — out of owned scope.
3. Runtime / bit-exact / differential.
4. Exhaustive caller set beyond current xrefs.

**Verdict:** **accept**
