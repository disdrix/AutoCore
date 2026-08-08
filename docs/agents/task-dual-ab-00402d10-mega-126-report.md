# Dual A/B report — MEGA-126 OWN-ONLY (`0x00402d10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-126**  
**Scope:** VA `0x00402d10` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — nested callee of **Client_DebugListMissionsStatus** (`0x009572e0`); partition missions-progression.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402d10` StdList_PushBack_Dword_Inferred | **accept-with-gaps** — CF/ABI/RET4/push_back/0xC node/Incsize throw/7 xrefs sealed; product `T` English + null-new safety open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-only / vector / push-front / EAX-payload / cdecl / plain-RET / leaf / no-throw / full-object-embed / merge-with-`00480350` claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402d10` — sealed facts

1. **Body:** `0x00402d10`–`0x00402d41` inclusive (**50 B** / `0x32`); pad `CC` from `0x00402d42`.
2. **ABI:** **ECX** = list*; stack `const dword* pValue`; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** MSVC-shaped **`std::list` push_back** (insert before sentinel):
   - `head = *(list+4)`
   - `node = FUN_00418700(head, head->_Prev, pValue)` — `operator_new(0xC)`; Next/Prev/Myval
   - `FUN_00404840(list, 1)` — `_Incsize`; may throw `"list<T> too long"` @ `0x00a1581c` / ThrowInfo `DAT_00acc388`
   - `head->_Prev = node`; `old_prev->_Next = node`
4. **Layout:** list Myhead@+4 Mysize@+8; node Next@0 Prev@4 Myval@8.
5. **Callees:** `FUN_00418700` (BuyNode, `RET 0xC`); `FUN_00404840` (Incsize thiscall `RET 4`).
6. **Callers / xrefs:** **7** UNCONDITIONAL_CALL / **3** parents:
   - `FUN_00509010` @ `0x00509280`
   - `FUN_0057ade0` @ `0x0057aeee` / `0x0057af49` / `0x0057af92` / `0x0057b080` / `0x0057b0c0`
   - `FUN_009572e0` Client_DebugListMissionsStatus @ `0x00957467`
7. **Name:** `StdList_PushBack_Dword_Inferred` (Ghidra `FUN_00402d10`). Product `T` open → `_Inferred`. Retires `Named_CalleeOf_Client_DebugListMissionsStatus_00402d10`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` (50 B hex seal).
9. **Hex seal:** `8b4424045356578bf18b7e048b4f045051578bcee8d75901006a018bce8bd8e80c1b0000895f048b53045f5e891a5bc20400`

### Gaps

- Product element-type English (shared helper; not one `T`).  
- Dual residual of BuyNode `00418700` and Incsize `00404840` (twins exist elsewhere).  
- Null-`operator_new` link safety.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402d10_StdList_PushBack_Dword_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402d10_StdList_PushBack_Dword_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00402d10_FUN_00402d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_Dword_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402d10.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_DebugListMissionsStatus_00402d10.cpp` |
| Function | `docs/reconstruction/functions/aa_00402d10_FUN_00402d10.md` |
| Function named | `docs/reconstruction/functions/aa_00402d10_StdList_PushBack_Dword_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_009572e0  Client_DebugListMissionsStatus  [parent seed / missions-progression]
  ├─ FUN_0040fb90  AllocEmptySentinel  [dualed elsewhere]
  ├─ FUN_00402dd0  list resize helper  [residual]
  └─ FUN_00402d10  StdList_PushBack_Dword_Inferred  [OWN MEGA-126]
        ├─ FUN_00418700  BuyNode 0xC  [residual; twin dualed 006759b0]
        └─ FUN_00404840  Incsize + "list<T> too long"  [residual; twin dualed 0043fe60]

FUN_00509010  reaction/item give path
  └─ FUN_00402d10(&item*)  [shared]

FUN_0057ade0
  └─ FUN_00402d10 ×5  [shared]

Peer (not this unit): FUN_00480350 StdList_PushPayloadNode_Inferred
  — same splice pattern; payload via EAX; different BuyNode/Incsize VAs
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402d10-mega-126-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402d10` | Port as **`std::list`-shaped push_back** of a **pointer/dword** via `const T*`. **thiscall RET 4**. Pair with BuyNode `00418700` (0xC node) and Incsize `00404840` (overflow throw). Do **not** model as vector growth or mission-only API. Keep distinct from EAX-payload peer `00480350`. |
| Pair with | dualed `StdList_BuyNode_Dword` `006759b0`; dualed `StdList_Incsize` `0043fe60`; dualed `StdList_PushPayloadNode` `00480350`; parent DebugListMissionsStatus `009572e0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / inventory as applicable
- System map `missions-progression` note: nested helper is **shared list push_back**, not mission-specific logic
