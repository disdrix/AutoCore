# Dual A/B report — R10-003 OWN-ONLY (`0x00427040`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-003**  
**Scope:** VA `0x00427040` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/callee decompiles (evidence only). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-003**.  
**Work item:** Residual dual seal — SEH JMP thunk of dualed `StdVector_DestroyRuns_0x80_Inferred`.  
**Inventory name retired as final:** `thunk_FUN_004271c0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00427040` StdVector_DestroyRuns_0x80_Thunk_Inferred | **accept** — pure 5 B JMP to dualed parent; EBX SEH alias @ +0x80 sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): expanded-decompile-as-local / second-tidy / thiscall / CALL-only / skill-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00427040` — sealed facts

1. **Body:** `0x00427040`–`0x00427044` inclusive (**5 B** / `0x5`); pad `CC` after.
2. **Insn:** sole **`JMP 0x004271c0`** (`E9 7B 01 00 00`); rel32 `0x17B`.
3. **Classification:** **thunk** (`analyze_function_complete` `is_thunk: true`).
4. **ABI (inherited):** **EBX** = vector shell*; no stack formals; void; parent bare **`RET`**.
5. **Semantics:** SEH alias of MSVC-style **vector tidy** stride **0x80** (parent MEGA-128):
   - begin@**+4** end@**+8** cap@**+0xC**.
   - Null begin → zero triple.
   - Else: for each elem `ECX=elem; FUN_00426f70` (~wstring @+0x0C), then `operator_delete(begin)`, zero triple.
6. **Callers / xrefs:** **2** Unwind JMP only — `009ac305` (`Unwind@009ac2fc`), `009add47` (`Unwind@009add3e`); both `MOV EBX,[EBP+4]; ADD EBX,0x80` then JMP here.
7. **Callees:** JMP → `FUN_004271c0` only (parent callees: `FUN_00426f70`, `operator_delete` @ `0x00489822`).
8. **Name:** `StdVector_DestroyRuns_0x80_Thunk_Inferred` (Ghidra `thunk_FUN_004271c0`).
9. **Decompile caveat:** Ghidra follows thunk and prints parent body (false noreturn on delete); **bytes win**.

### Gaps

- Product 0x80 element English beyond `wstring@+0x0C` (inherited `_Inferred` / "runs").  
- Unowned residual trampoline `FUN_00426f70` (R10-026).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00427040_thunk_FUN_004271c0.md` |
| Annotated | `docs/reconstruction/raw/aa_00427040_thunk_FUN_004271c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRuns_0x80_Thunk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00427040.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/thunk_FUN_004271c0.cpp` |
| Function | `docs/reconstruction/functions/aa_00427040_FUN_00427040.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00427040_thunk_FUN_004271c0.md` |
| Function named | `docs/reconstruction/functions/aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed]
  └─ owned text layout @ +0x28C:
        FUN_00797d70  UiTextLayout_CompleteDtor_Inferred  [dualed WQ9L-F]
          ├─ FUN_00797530(1) finalize
          ├─ free buffer vector @ +0x94
          ├─ LEA EBX,[layout+0x80]; CALL FUN_004271c0  [dualed MEGA-128]
          └─ ~wstring @ +0x0C

FUN_004271c0  StdVector_DestroyRuns_0x80_Inferred  [dualed MEGA-128]
  ├─ FUN_00426f70  ~wstring@elem+0x0C trampoline  [R10-026 residual]
  └─ operator_delete  free begin

thunk @ 0x00427040  StdVector_DestroyRuns_0x80_Thunk_Inferred  [OWN R10-003]
  └─ JMP → FUN_004271c0
       ↑ SEH Unwind@009ac2fc / Unwind@009add3e
         (MOV EBX,[EBP+4]; ADD EBX,0x80)
```

Partition system tag **skills-abilities** is ownership domain; body is pure container SEH alias (parent B dual falsified skill-logic claim).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00427040-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00427040` | Port as **pure alias** of `DestroyRuns0x80` — **no second body**. EBX-this; SEH JMP density only. |
| Parent | dualed `StdVector_DestroyRuns_0x80_Inferred` @ `0x004271c0` — real tidy. |
| Pair with | dualed `UiTextLayout_CompleteDtor_Inferred` (vector @ `layout+0x80`); residual elem dtor `FUN_00426f70`. |
| Distinct from | dword / other-stride vector tidies; host layout free (parent of parent). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdVector_DestroyRuns_0x80_Thunk_Inferred` @ `0x00427040` / `aa_00427040`.
- Verdict: **accept**; Terminal **false**.

---

## Process

- OWN VA only (`0x00427040`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + assembly context + parent/callee decompiles (evidence). **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine twin + retired scaffold path kept.
- Odd behavior preserved: decompiler expands parent; retail is JMP-only.
- `_Inferred` inherited where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
