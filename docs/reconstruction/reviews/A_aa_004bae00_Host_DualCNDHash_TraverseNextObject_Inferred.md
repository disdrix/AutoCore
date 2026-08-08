# Review A (reconstruction fidelity): `aa_004bae00` Host_DualCNDHash_TraverseNextObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **VA** | `0x004bae00`–`0x004bae63` inclusive (**100 B** / `0x64`) |
| **Canonical name** | `Host_DualCNDHash_TraverseNextObject_Inferred` |
| **Ghidra name** | `FUN_004bae00` |
| **Prior scaffolds** | `FUN_004bae00`; `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-011 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` |
| **System** | interaction-activation (pick-list / SelectBestPick residual) |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Single-step dual-CNDHash object enumerator** on a host that owns two hash tables:

```text
Host_DualCNDHash_TraverseNextObject(host, listSelect, cursor) -> object*|NULL
  if listSelect==0:
    gate host+0xd; hash = host+0x8
  else:
    gate host+0xc; hash = host+0x4
  if enable && hash:
    CNDHash_TraversalLock_Set(hash)          // 00402c40
    obj = TraverseToNext(hash, cursor)       // 004bc530 → node+0xc
    hash.traversalFlag (+0x1d) = 0           // inline unlock
    return obj
  return NULL
```

Does **not** multi-step under a held lock; each call lock→one step→unlock. Primary dualed consumer: `Client_Interact_SelectBestPickTarget` (two passes flag 0 then 1).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (flag branches + lock/walk/unlock) |
| Full body | `disassemble_function` + `read_memory` 100 B |
| Callee lock | dualed `CNDHash_TraversalLock_Set_Inferred` `0x00402c40` (MEGA-110) |
| Callee walk | `FUN_004bc530` — string `"HashError:TraverseToNext, not locked for traversal"` @ `0x00a27c9c` |
| Call sites | SelectBestPick `0x0049010b`/`0x0049048f` ECX=`[Client+0xBC]`; flush `0x00943d38` ECX=`[host+0xD34]`; session `+0xE4E8` family |
| Callers / xrefs | 13 callers; **28** UNCONDITIONAL_CALL |
| Parent dual | `aa_00490070` SelectBestPick (enumerator host residual closed here) |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature (sealed)

```c
// ECX=host; stack listSelect, cursor*; EAX=object*|0; RET 8
void* __thiscall Host_DualCNDHash_TraverseNextObject_Inferred(
    void* host,
    char listSelect,
    int* cursor);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → ESI (`MOV ESI,ECX`) | **Confirmed** |
| listSelect | stack `[ESP+4]` (`CMP byte [ESP+4],0`) | **Confirmed** |
| cursor | stack `[ESP+8]` → pushed to `004bc530` | **Confirmed** |
| return | EAX = payload or 0 | **Confirmed** |
| cleanup | `RET 8` (`C2 08 00`) ×3 exits | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Entry CMP listSelect / branch | bytes | **Confirmed** |
| flag≠0: gate `+0xc`, hash `+0x4` | asm order | **Confirmed** |
| flag==0: gate `+0xd`, hash `+0x8` | asm order | **Confirmed** |
| null enable / null hash → XOR EAX, RET 8 | fail path | **Confirmed** |
| CALL `00402c40` with ECX=hash | before walk | **Confirmed** |
| CALL `004bc530` PUSH cursor; ECX=hash | walk | **Confirmed** |
| `MOV byte [hash+0x1d],0` unlock | after walk | **Confirmed** |
| No CS / no throw / no multi-step hold | leaf sandwich | **Confirmed** |

### Host offsets (sealed)

| Off | Role |
|----:|------|
| `+0x4` | CNDHash* list A (`listSelect != 0`) |
| `+0x8` | CNDHash* list B (`listSelect == 0`) |
| `+0xc` | enable list A |
| `+0xd` | enable list B |

### Hash/node offsets (via callees; required for port)

| Off | Role |
|----:|------|
| hash `+0x14` | walk head |
| hash `+0x1d` | TraversalLock flag |
| node `+0x20` | next |
| node `+0x0c` | object* payload |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (shared dual-list step) |
| External callers | **13** functions / **28** UNCONDITIONAL_CALL |
| Site role | world/pick object enumeration |
| Callees | `00402c40` (dualed lock set); `004bc530` (TraverseToNext residual) |
| SelectBestPick binding | ECX = `Client+0xBC` (**High** — call-site sealed; closes parent gap) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Dual hash select by flag (asm) | **Yes** |
| TraversalLock + TraverseToNext string family | **Yes** (via callees) |
| Object payload return used as pick candidates | **Yes** (SelectBestPick) |
| Product host class RTTI English | **No** → `_Inferred` |
| LoadMapFile parent chain | **No** — scaffold retired |

**Preferred name:** `Host_DualCNDHash_TraverseNextObject_Inferred`

---

## 7. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** |
| ABI thiscall + RET 8 | **Confirmed** |
| Dual list offsets + flag polarity | **High** |
| Lock/walk/unlock sandwich | **High** |
| SelectBestPick host = Client+0xBC | **High** |
| Product host English / list A vs B product names | **Tentative** |
| `004bc530` full dual | **Open** (MEGA-029) |
| Runtime Confirmed | **Open** |
| Overall | **accept-with-gaps** |

## 8. Gaps

1. Product RTTI / English for dual-list host class.
2. Semantic product labels for list A vs B (flag 0/1).
3. Dual seal of `FUN_004bc530` (MEGA-029 OWN).
4. Runtime / bit-exact / differential.

**Verdict:** accept-with-gaps. ABI, dual-list CF, lock sandwich, and SelectBestPick host binding sealed; product host English open.
