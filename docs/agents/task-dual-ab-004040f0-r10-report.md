# Dual A/B report — R10-005 OWN-ONLY (`0x004040f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-005**  
**Scope:** VA `0x004040f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — undualed callee of dualed BuyNode parent `0x00418700`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004040f0` StdList_InsertOne_BeforeNode_Dword_Inferred | **accept-with-gaps** — CF/ABI/RET0x8/list insert-one dword sealed; demangle + null-new + Incsize dual formal + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-Named_CalleeOf / cdecl / after-insert / vector-or-tree / sole-caller / ECX≠list claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004040f0` — sealed facts

1. **Body:** `0x004040f0`–`0x00404122` inclusive (**51 B** / `0x33`).
2. **ABI:** **ECX** = `list*`; stack `where*`, `val*`; void; **`RET 0x8`**.
3. **Semantics:** insert one dword before `where`:
   - BuyNode `0xC` (`FUN_00418700` / dualed `StdList_BuyNode_Dword_Seh`) — Next=`where`, Prev=`where->prev`, value=`*val`
   - Incsize +1 (`FUN_00404840`) — max `0x3fffffff`, `"list<T> too long"`
   - rewire `where->prev = node`; `node->prev->next = node`
4. **Callees:** `FUN_00418700`, `FUN_00404840`.
5. **Callers / xrefs:** **3** UNCONDITIONAL_CALL — `FUN_004034c0` @ `0x004034fc`, `FUN_00404560` @ `0x004045a0`, orphan @ `0x004cd020`.
6. **Name:** `StdList_InsertOne_BeforeNode_Dword_Inferred` (Ghidra `FUN_004040f0`). Retire `Named_CalleeOf_*DebugListMi_004040f0`.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + caller sites (decompiler elides list this / Incsize this).
8. **Twin relation:** push_back `0x00402d10` is same splice with `where = head` fixed; InsertN `0x004034c0` loops this unit.

### Gaps

- Exact CRT / demangle spelling for list `_Insert` specialization.  
- Null BuyNode return still rewires (OOM residual; same as push_back dual).  
- Formal dual of Incsize `00404840` (string path already High).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004040f0_FUN_004040f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004040f0_FUN_004040f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_InsertOne_BeforeNode_Dword_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004040f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004040f0_FUN_004040f0.md` |
| Function named | `docs/reconstruction/functions/aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_DebugListMissionsStatus  0x009572e0   [string missions debug]
  └─ FUN_00402dd0  list resize
       └─ FUN_004034c0  StdList_InsertN_BeforeNode_Dword_Inferred  [dualed MEGA-134]
            └─ FUN_004040f0  StdList_InsertOne_BeforeNode_Dword_Inferred  [OWN R10-005]
                 ├─ FUN_00418700  StdList_BuyNode_Dword_Seh  [dualed MEGA-081]
                 └─ FUN_00404840  Incsize max 0x3fffffff / "list<T> too long"

Peer insert-range (shares this VA): FUN_00404560
Push-back twin (where=head): StdList_PushBack_Dword_Inferred 0x00402d10 [dualed MEGA-126]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004040f0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004040f0` | Port as **list insert-one before node** for **dword** elements. **ECX=list**, stack `(where, val*)`, **`RET 0x8`**. |
| Pair with | InsertN `004034c0`; PushBack `00402d10`; BuyNode `00418700`; Incsize `00404840`; insert-range `00404560`. |
| Avoid | Mission-named primary symbol; vector Insert; treating ECX as where/val; assuming multi-word element copy in this body. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` (retire Named_CalleeOf scaffold → `StdList_InsertOne_BeforeNode_Dword_Inferred`)
- coverage / progress ledgers if used

**Terminal:** false.
