# Dual A/B report — MEGA-044 OWN-ONLY (`0x00409e20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-044**  
**Scope:** VA `0x00409e20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `analyze_control_flow` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — PollBoundActions nested ConstructN 0x10 (partition interaction-activation; util container role).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409e20` StdVector_ConstructN_Elem0x10_Inferred | **accept-with-gaps** — CF/ABI/RET-cdecl/stride0x10/SEH/2 callers/PodCopy leaf sealed; product POD English + helper duals open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): PollBound-role / insert-N / range-copy / ret4-thiscall / end-pointer-here / non-POD-ctor claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409e20` — sealed facts

1. **Body:** `0x00409e20`–`0x00409e82` inclusive (**99 B** / `0x63`); next fn @ `0x00409e83`.
2. **ABI:** **ECX** = template `const Elem0x10*`; stack `void* dest`, `int count`; void; plain **`RET` (`C3`)** cdecl. Callers push 4 dwords + `ADD ESP,0x10` (2 phantoms unused by body).
3. **Semantics:** ConstructN / uninitialized_fill_n for **0x10** POD:
   - SEH frame (`LAB_009bc610` / FS:[0]); state 0 in loop, `-1` on exit.
   - Loop: while count ≠ 0 → `FUN_00409f70` (EAX=dest, ECX=template) PodCopy 4 dwords if dest≠null; count--; dest += `0x10`.
   - Template **fixed** (not advanced) — fill-from-one, not range-copy.
   - Does **not** return end pointer (wrapper `FUN_00407000` does `dest+count*0x10`).
4. **Callees:** `FUN_00409f70` only.
5. **Callers (2):** UNCONDITIONAL_CALL
   - `FUN_00407000` @ `0x0040700c` (construct-N wrapper; parent insert-N `FUN_00408640`)
   - `FUN_00930360` @ `0x009305a5` (SortTargetListByViewAngle; count=1 capacity path)
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `StdVector_ConstructN_Elem0x10_Inferred` (Ghidra `FUN_00409e20`). Product POD English open → `_Inferred`. Scaffold `Named_CalleeOf_*PollB*` **retired**.
8. **Decompile ≡ raw CF**; ABI/stride sealed via `disassemble_function` + `read_memory` + call-site context (decompiler signature incomplete — asm authoritative).

### Gaps

- Product English type of 0x10 element.  
- Dual seal of PodCopy `00409f70` and wrapper `00407000` residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409e20_FUN_00409e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00409e20_FUN_00409e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409e20.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409e20.cpp` |
| Function | `docs/reconstruction/functions/aa_00409e20_FUN_00409e20.md` |
| Function named | `docs/reconstruction/functions/aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408640  StdVector_InsertN_Elem0x10_Inferred  [dualed prior WQ9H-H]
  └─ FUN_00407000  construct-N wrapper → end = dest+count*0x10  [residual]
       └─ FUN_00409e20  StdVector_ConstructN_Elem0x10_Inferred  [OWN MEGA-044]
            └─ FUN_00409f70  PodCopy 4 dwords / 0x10  [residual]

FUN_00930360  Client_SortTargetListByViewAngle  [partition MEGA-023 peer]
  ├─ FUN_00409e20  capacity-hit push count=1  [OWN MEGA-044]
  └─ FUN_00408640  grow path  [dualed prior]
```

Partition map row: MEGA-044 | `0x00409e20` | P90 | interaction-activation | PollBoundActions nested.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409e20-mega-044-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409e20` | Port as **vector ConstructN / uninitialized_fill_n** for **0x10-byte POD**. **ECX=template**, stack dest+count, **cdecl RET**. Source fixed; dest += 0x10/iter. Keep SEH if matching MSVC layout. |
| Pair with | dualed InsertN `00408640`; residual wrapper `00407000`; residual PodCopy `00409f70`; twin ConstructN 0x28 `00409d40` / elem12 `00409db0`. |
| Do **not** | treat as PollBound input leaf; merge with range-copy; assume `ret 4` / end-pointer return at this VA. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable
- progress inventory entry for MEGA-044 **accept-with-gaps**
