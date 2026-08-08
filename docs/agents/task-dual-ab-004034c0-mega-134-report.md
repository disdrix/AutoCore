# Dual A/B report — MEGA-134 OWN-ONLY (`0x004034c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-134**  
**Scope:** VA `0x004034c0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` + `analyze_function_completeness` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-134 residual dual seal — Debug mission list nested → shared list insert-N.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004034c0` StdList_InsertN_BeforeNode_Dword_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/sole caller/list insert-N dword sealed; demangle + callee duals + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-Named_CalleeOf / ECX=list entry / cdecl / vector-or-tree / multi-xref claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004034c0` — sealed facts

1. **Body:** `0x004034c0`–`0x00403522` inclusive (**99 B** / `0x63`); SEH catch `@0x00403523`.
2. **ABI:** **ECX** = `const uint32_t* val`; stack `list*`, `where*`, `count`; void; **`RET 0xC`**.
3. **Semantics:** loop `count` times calling insert-one-before (`FUN_004040f0`):
   - BuyNode `0xC` (`FUN_00418700`) — Next/Prev/dword `*val`
   - Incsize +1 (`FUN_00404840`) — max `0x3fffffff`, `"list<T> too long"`
   - rewire `where->prev` / `new->prev->next`
4. **Callees:** `FUN_004040f0` only (direct).
5. **Callers:** **1** UNCONDITIONAL_CALL — `FUN_00402dd0` @ `0x00402de6` (resize grow: where=head, count=`target-size`, ECX=`&stack T`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL (same site).
7. **Name:** `StdList_InsertN_BeforeNode_Dword_Inferred` (Ghidra `FUN_004034c0`). Retire `Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_004034c0`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + caller site (decompiler elides list this on insert call — asm corrects).

### Gaps

- Exact CRT / demangle spelling for list `_Insert` specialization.  
- Dual seal of insert-one `004040f0` / BuyNode `00418700` (evidence only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004034c0_FUN_004034c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004034c0_FUN_004034c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_InsertN_BeforeNode_Dword_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004034c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004034c0_FUN_004034c0.md` |
| Function named | `docs/reconstruction/functions/aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_DebugListMissionsStatus  0x009572e0   [string missions debug]
  └─ FUN_00402dd0  list resize (ESI=list, EAX=target, stack T)
       ├─ grow: FUN_004034c0  StdList_InsertN_BeforeNode_Dword_Inferred  [OWN MEGA-134]
       │         └─ FUN_004040f0  insert one before
       │              ├─ FUN_00418700  BuyNode 0xC
       │              └─ FUN_00404840  Incsize max 0x3fffffff
       └─ shrink: unlink head->prev + operator_delete  [same parent; not this VA]

Peer insert-range (shares 004040f0, not this VA): FUN_00404560
List destroy family (nearby): StdList_Destroy_FreeHead 00403430 [prior dual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004034c0-mega-134-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004034c0` | Port as **list insert-N before node** for **dword** elements. **ECX=val***, stack `(list, where, count)`, **`RET 0xC`**. Do **not** treat entry ECX as list this. |
| Pair with | resize `00402dd0`; insert-one `004040f0`; BuyNode `00418700`; Incsize `00404840`; sentinel/destroy duals. |
| Avoid | Mission-named primary symbol; vector InsertN; assuming multi-word element copy in this body. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` (retire Named_CalleeOf scaffold → `StdList_InsertN_BeforeNode_Dword_Inferred`)
- coverage / progress ledgers if used

**Terminal:** false.
