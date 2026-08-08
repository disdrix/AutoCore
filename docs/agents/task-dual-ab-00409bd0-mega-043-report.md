# Dual A/B report — MEGA-043 OWN-ONLY (`0x00409bd0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-043**  
**Scope:** VA `0x00409bd0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `batch_decompile` callees + caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-043 (hint PollBoundActions nested; **live parent** sort-target-list).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409bd0` StdSort_RanItStride16_Inferred | **accept-with-gaps** — CF/ABI/cdecl/RET/stride-16/MSVC `_Sort` shape/caller sealed; product English + nested helpers + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): PollBoundActions / thiscall / wrong stride / stdcall-RET4 / pure-quicksort claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409bd0` — sealed facts

1. **Body:** `0x00409bd0`–`0x00409cb9` inclusive (**234 B** / `0xEA`).
2. **ABI:** **`__cdecl`**; stack `first, last, ideal, pred`; void; plain **`RET`** (`C3` @ `0x00409c82` / `0x00409cb9`); caller cleans **`ADD ESP,0x10`**.
3. **Semantics:** MSVC-style **introsort** (`std::_Sort`) for **stride-16** random-access elements:
   - `count = (last - first) >> 4`
   - if `count ≤ 32`: insertion via `FUN_0040a410` when `count > 1`
   - if `ideal ≤ 0`: make_heap `FUN_0040a820` (when span > 16) + sort_heap `FUN_0040a380`
   - else: partition `FUN_00409f90` → pair cuts; `ideal = ideal/2 + (ideal/2)/2` (¾); recurse smaller; iterate larger
4. **Callees:** `FUN_00409f90`, `FUN_0040a410`, `FUN_0040a820`, `FUN_0040a380`, self.
5. **Callers / xrefs:** External **`FUN_00930360`** @ `0x009305fc` (1); self @ `0x00409c3e` / `0x00409c4f`. Total 3 UNCONDITIONAL_CALL.
6. **Call-site args:** `FUN_00409bd0(begin, end, count, &LAB_0092cdd0)`; pred is float less-than on record `+4`.
7. **Name:** `StdSort_RanItStride16_Inferred` (Ghidra `FUN_00409bd0`). Retire `Named_CalleeOf_*PollBoundActions*` scaffold. `_Inferred` — no RTTI demangle.
8. **Decompile ≡ raw CF**; ABI/stride sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Partition hint correction:** MEGA map listed PollBoundActions nested under `0x00925d60`; live graph parent is sort-target-list `FUN_00930360` (interaction/skills consumer of this STL sort, not this body itself).

### Gaps

- Nested partition/insertion/heap helpers undualed here.  
- Element field English beyond pred float@+4.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409bd0_StdSort_RanItStride16_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409bd0_StdSort_RanItStride16_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409bd0_FUN_00409bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00409bd0_FUN_00409bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdSort_RanItStride16_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00409bd0_FUN_00409bd0.md` |
| Function named | `docs/reconstruction/functions/aa_00409bd0_StdSort_RanItStride16_Inferred.md` |
| Scaffold retired (path kept) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409bd0.cpp` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00930360  Client_SortTargetListByViewAngle (partition plate / residual)
  ├─ build vector of 16-byte {object*, score…} entries
  ├─ FUN_00409bd0  StdSort_RanItStride16_Inferred  [OWN MEGA-043]
  │     pred LAB_0092cdd0  float less @+4
  │     ├─ FUN_00409f90  partition (residual)
  │     ├─ FUN_0040a410  insertion (residual)
  │     ├─ FUN_0040a820  make_heap (residual)
  │     └─ FUN_0040a380  sort_heap (residual)
  └─ rewrite TFID list from sorted object pointers

PollBoundActions 0x00925d60  — partition lineage only; NOT a live xref to 00409bd0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409bd0-mega-043-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409bd0` | Port as **MSVC `std::_Sort`-style introsort** for **16-byte** elements. **`__cdecl`**, plain **`RET`**, args `(first, last, ideal, pred)`. Seed `ideal` with element count. Threshold **32**; depth **¾** per level; heap finishers when depth exhausted. |
| Do **not** | Treat as PollBoundActions / input poll; do not invent thiscall; do not assume stride 8/32. |
| Pair with | caller `FUN_00930360` (sort target list); residual helpers `00409f90` / `0040a410` / `0040a820` / `0040a380`; pred `0092cdd0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`StdSort_RanItStride16_Inferred`; retire PollBoundActions Named_CalleeOf)  
- `systems/*` residual tables (STL sort helper under interaction/skills consumer)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00409bd0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (cdecl plain RET; stride 16).  
- Odd behavior preserved: tail-loop on larger half after recurse; heap path gated on count>32; partition out-pair locals.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
