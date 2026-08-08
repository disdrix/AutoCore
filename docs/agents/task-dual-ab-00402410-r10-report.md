# Dual A/B report — R10-019 OWN-ONLY (`0x00402410`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-019**  
**Scope:** VA `0x00402410` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — callee sibling of dualed **StdList_DefaultCtor_Inferred** (parent `0x004023f0`); unit is shared MSVC list copy-construct helper.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` row R10-019.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402410` StdList_CopyCtor_Inferred | **accept-with-gaps** — CF/ABI/RET8/head@+4/size@+8/empty-init+range-insert sealed; `T` + insert-chain dual + runtime residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): domain-only / empty-only / wrong-offset / thiscall-RET4 / assign-in-place / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402410` — sealed facts

1. **Body:** `0x00402410`–`0x00402495` inclusive (**134 B** / `0x86`); SEH `LAB_009bd220`.
2. **ABI:** **stack** dest @ `[EBP+8]`, src @ `[EBP+0xC]`; **EAX** = dest; **`RET 0x8`** (stdcall). **Not** ECX thiscall.
3. **Semantics:** list copy-construct helper:
   - `CALL FUN_0040fb90` → dualed **StdList_AllocEmptySentinel_Inferred**.
   - `dest+4 = EAX` (`_Myhead`).
   - `dest+8 = 0` (`_Mysize`).
   - `CALL FUN_00404490(dest, *dest._Myhead, *src._Myhead, src._Myhead)` → insert `[src.begin(), src.end())` before dest end.
   - return `dest`.
4. **Object layout:** same **0xC** list object as default-ctor sibling (head@+4, size@+8; +0 unwritten).
5. **Callees:** `FUN_0040fb90`, `FUN_00404490` (→ residual `00404560` / `004040f0`).
6. **Callers:** **8** UNCONDITIONAL_CALL, all `FUN_00955010` (`00955111` … `00955de8`). No DATA xrefs.
7. **Pair / sibling:** dualed default **StdList_DefaultCtor_Inferred** `0x004023f0`; dualed destroy **StdList_Destroy_FreeHead_Inferred** `0x00403430`; dualed sentinel **StdList_AllocEmptySentinel_Inferred** `0x0040fb90`.
8. **Name:** `StdList_CopyCtor_Inferred` (Ghidra `FUN_00402410`). Product map open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory`.

### Gaps

- Element type `T` (site-specific; residual insert chain).  
- Unwritten `list+0` (allocator / `_Container_base`).  
- Insert chain duals `00404490` / `00404560` / `004040f0`.  
- Runtime / bit-exact / differential.  
- Stdcall 2-arg vs textbook thiscall copy-ctor decoration.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402410_StdList_CopyCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402410_StdList_CopyCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402410_FUN_00402410.md` |
| Annotated | `docs/reconstruction/raw/aa_00402410_FUN_00402410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_CopyCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402410.cpp` |
| Function | `docs/reconstruction/functions/aa_00402410_FUN_00402410.md` |
| Function named | `docs/reconstruction/functions/aa_00402410_StdList_CopyCtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Parent dual (MEGA-052 / partition parent):
  FUN_004023f0  StdList_DefaultCtor_Inferred  [dualed]
    └─ FUN_0040fb90  StdList_AllocEmptySentinel_Inferred  [dualed]

This unit (R10-019):
  FUN_00402410  StdList_CopyCtor_Inferred  [OWN]
    ├─ FUN_0040fb90  StdList_AllocEmptySentinel_Inferred  [dualed]
    └─ FUN_00404490  range-insert wrapper  [residual]
         └─ FUN_00404560  walk [first,last)
              └─ FUN_004040f0  insert value before where  [residual]
                   └─ FUN_00418700 BuyNode / FUN_00404840 Incsize  [residual]

Sole caller:
  FUN_00955010  [not dualled]
    └─ FUN_00402410 ×8

Paired teardown (sibling family):
  FUN_00403430  StdList_Destroy_FreeHead_Inferred  [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402410-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402410` | Port as **`std::list` copy-construct into dest**. **Stdcall** dest+src stack args, **EAX=dest**, **`RET 8`**. Head@**+4**, size@**+8** empty then insert. Object **0xC**. |
| Do **not** | Treat as ECX thiscall like default ctor; treat as empty-only default; invent mission domain; place head at +0. |
| Pair with | dualed `StdList_AllocEmptySentinel_Inferred` `0040fb90`; dualed `StdList_DefaultCtor_Inferred` `004023f0`; dualed `StdList_Destroy_FreeHead_Inferred` `00403430`; residual insert `00404490`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
