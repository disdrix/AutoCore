# Dual A/B report — MEGA-089 OWN-ONLY (`0x004027f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-089**  
**Scope:** VA `0x004027f0` (`aa_004027f0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `read_memory` + `get_assembly_context` + callee decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Named_CalleeOf **RecvCreateCharacter** residual → sealed **std::list push_front**.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` (MEGA-089).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004027f0` StdList_PushFront_DwordFromEax_Inferred | **accept-with-gaps** — CF/ABI/RET4/node0xC/push_front/8 xrefs sealed; product element English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): RecvCreateCharacter-only / thiscall / push_back / CsSList-merge / two-stack-arg claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004027f0` — sealed facts

1. **Body:** `0x004027f0`–`0x0040281e` inclusive (**47 B** / `0x2F`); pad `CC` before `FUN_00402830`; Ghidra body end `00402820`.
2. **ABI:** stack **`list*`**; **EAX** = `const uint32_t*` value; void-like; **`RET 4`**. **Not** thiscall.
3. **Semantics:** MSVC **`std::list` push_front** (4-byte `T`):
   - `head = *(list+4)`
   - `node = FUN_00418700(head, head->_Next, eax_val)` — `operator_new(0xC)`; `{_Prev,_Next,_Myval}`
   - `FUN_00418790(ecx=1, edx=list)` — `_Mysize += 1`; may throw `"list<T> too long"`
   - `head->_Next = node`; `node->_Next->_Prev = node`
4. **Callees:** `FUN_00418700`, `FUN_00418790` only.
5. **Callers:** **7** functions / **8** UNCONDITIONAL_CALL:
   - `Client_RecvCreateCharacter` @ `00814823` (list +`0xf08`)
   - `Client_CreateVehicleObjectApply` @ `008128c2` (list +`0xefc`)
   - `FUN_0080af70` @ `0080b03f` (list +`0xf08`)
   - `FUN_0093ffb0` @ `00940cff` / `00940e2c` (list +`0xaa8`)
   - `FUN_008c7700` @ `008c7b5b`
   - `FUN_00919dc0` @ `00919ebb`
   - `FUN_00946c00` @ `009477f1`
6. **Name:** `StdList_PushFront_DwordFromEax_Inferred` (Ghidra `FUN_004027f0`). Product list/element open → `_Inferred`.
7. **Retired scaffold:** `Named_CalleeOf_Client_RecvCreateCharacter_004027f0`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product `list<T>` / element English per host offset.  
- list+0 base/allocator unused by body.  
- Null-`operator_new` crash retained (no guard in unit).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushFront_DwordFromEax_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004027f0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_RecvCreateCharacter_004027f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004027f0_FUN_004027f0.md` |
| Function named | `docs/reconstruction/functions/aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_PacketDispatch / FUN_008078b0
  ├─ Client_RecvCreateCharacter  [named]
  │     └─ FUN_004027f0  StdList_PushFront_DwordFromEax_Inferred  [OWN MEGA-089]
  │           list @ character+0xf08 ; val = created object*
  ├─ Client_CreateVehicleObjectApply  [named]
  │     └─ FUN_004027f0  (list @ +0xefc)
  └─ FUN_0080af70  (give-item / reaction)
        └─ FUN_004027f0  (list @ +0xf08)

FUN_004027f0
  ├─ FUN_00418700  _Buynode(0xC)  [residual]
  └─ FUN_00418790  _Incsize + "list<T> too long"
        ├─ FUN_00401a40  Std_LengthError_CtorFromString  [dualed]
        └─ _CxxThrowException(..., DAT_00acc388)

Siblings (not OWN):
  FUN_00402d10  push_front thiscall + FUN_00404840 size
  FUN_00403120  insert-before-node RET 8
  FUN_00405e20  related splice with ECX val
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004027f0-mega-089-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004027f0` | Port as **`std::list` push_front** of a **dword** (typically object*). **Stack list***, **EAX = const T***, **`RET 4`**. Do **not** model as thiscall. Pair with buynode `00418700` + incsize `00418790` / length_error throw. Keep distinct from CsSList (`004024d0`) and LockedList families. |
| Call sites | Character list often at **`this+0xf08`** (RecvCreateCharacter / give-item); vehicle host **`+0xefc`**; UI host **`+0xaa8`**. |
| Pair with | residual buynode/incsize; dualed length_error `00401a40`; sibling push_front variants `00402d10` / `00403120`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming registry entries for `StdList_PushFront_DwordFromEax_Inferred`
- retire `Named_CalleeOf_Client_RecvCreateCharacter_004027f0` aliases in parent indexes

---

## Terminal

**false** — dual documentation complete; no runtime Confirmed; no Launcher.
