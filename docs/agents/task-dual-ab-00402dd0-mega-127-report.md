# Dual A/B report — MEGA-127 OWN-ONLY (`0x00402dd0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-127**  
**Scope:** VA `0x00402dd0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-127 residual dual seal — nested callee of **Client_DebugListMissionsStatus** (shared list resize).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402dd0` StdList_Resize_EsiList_EaxCount_Inferred | **accept-with-gaps** — CF/ABI/RET4/ESI-list/EAX-count/5 callers sealed; element type open |

Path A (fidelity): `00402dd0` **accept-with-gaps**.  
Path B (adversarial): mission-body / clear-only-merge / thiscall-ECX / vector-resize / false-noreturn / front-pop claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402dd0` — sealed facts

1. **Body:** `0x00402dd0`–`0x00402e1f` inclusive (**80 B** / `0x50`).
2. **ABI:** **ESI** = list shell\*; **EAX** = `new_size`; stack = **fill**; void; **`RET 4`** ×2 exits.
3. **Semantics:** MSVC-style circular list **resize**:
   - **Grow** (`new > size`): `FUN_004034c0(list, head, n)` with `ECX=&fill` inserts n nodes.
   - **Equal:** return.
   - **Shrink** (`new < size`): loop unlink **`head->_Prev`** (back), `operator_delete`, **`size--`**.
4. **Layout:** list `+4` head, `+8` size; node `+0` next, `+4` prev.
5. **Callees:** `FUN_004034c0`; `operator_delete` @ `0x00489822`.
6. **Callers:** **5** UNCONDITIONAL_CALL:
   - `Client_DebugListMissionsStatus` `FUN_009572e0` @ `0x00957447`
   - `FUN_008eca80` @ `0x008ecb86`
   - `FUN_00801c50` @ `0x00801d84`
   - `FUN_0080b7f0` @ `0x0080b87f`
   - `FUN_008a5c90` @ `0x008a5d7c`
   - All observed sites use **EAX=0** (clear/resize-to-empty).
7. **Decompiler traps:** `void()` + false-noreturn on delete (misses size-- loop) — assembly authoritative.
8. **Name:** `StdList_Resize_EsiList_EaxCount_Inferred` (Ghidra `FUN_00402dd0`). Product element type open → `_Inferred`.
9. **Retired scaffold:** `Named_CalleeOf_Client_DebugListMissionsStatus_00402dd0`.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for element type T / sizeof(T) on fill.  
- Dual of grow `004034c0` / insert `004040f0` (related residuals).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Resize_EsiList_EaxCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402dd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00402dd0_FUN_00402dd0.md` |
| Function named | `docs/reconstruction/functions/aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` |
| Scaffold (retired content) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_DebugListMissionsStatus_00402dd0.cpp` |

---

## Chain context (not dualled; evidence only)

```text
Client_DebugListMissionsStatus  FUN_009572e0  [string dualed elsewhere]
  ├─ FUN_00402dd0  StdList_Resize_EsiList_EaxCount_Inferred  [OWN MEGA-127]  // clear local list
  ├─ FUN_008ec750  filter/match helper
  └─ FUN_00402d10  list insert (push)  [MEGA-126 residual]

FUN_00402dd0
  ├─ FUN_004034c0  insert-N grow  [MEGA-134 residual]
  │     └─ FUN_004040f0  single insert
  │           ├─ FUN_00418700  buynode
  │           └─ FUN_00404840  incsize
  └─ operator_delete

Peers (do not merge):
  StdList_Clear_ESI  0x00415e90  — clear-only, bare RET
  StdList_Clear ECX  0x00404060
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402dd0-mega-127-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402dd0` | Port as **list resize(n, fill)** with **ESI=list**, **EAX=n**, stack fill, **RET 4**. Prefer `List<T>.Resize` / clear-via-resize(0). |
| Shrink | **Pop back** (head→prev), not front. Decrement size after each free. |
| Grow | Delegate to insert-N `004034c0` with fill. |
| Distinct from | `StdList_Clear_ESI` `00415e90` (no grow/fill); do **not** name from mission parent alone. |
| Pair with | parent `Client_DebugListMissionsStatus` `009572e0`; insert `00402d10`; grow `004034c0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers when batch-merging MEGA residuals
