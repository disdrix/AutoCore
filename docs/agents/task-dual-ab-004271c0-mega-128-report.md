# Dual A/B report — MEGA-128 OWN-ONLY (`0x004271c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-128**  
**Scope:** VA `0x004271c0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + callee decompile `FUN_00426f70` + call-site disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — **StdVector_DestroyRuns_0x80** (callee of dualed `UiTextLayout_CompleteDtor_Inferred` `0x00797d70`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004271c0` StdVector_DestroyRuns_0x80_Inferred | **accept** — CF/ABI/EBX-this/RET/stride0x80/elem~wstring/delete+zero sealed; product element English residual only |

Path A (fidelity): **accept**.  
Path B (adversarial): thiscall / false-noreturn / dword-stride / free-host / VOG_DEBUG_STOP-product / skill-logic claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004271c0` — sealed facts

1. **Body:** `0x004271c0`–`0x00427204` inclusive (**69 B** / `0x45`); pad `CC` after.
2. **ABI:** **EBX** = vector shell\*; no stack formals; void; bare **`RET`** (`C3` @ `0x00427204`).
3. **Semantics:** MSVC-style **vector tidy** stride **0x80**:
   - begin@**+4** end@**+8** cap@**+0xC**.
   - Null begin → zero triple.
   - Else: for each elem `ECX=elem; FUN_00426f70` (`ADD ECX,0xC; JMP IAT ~basic_string<wchar_t>`), then `operator_delete(begin)`, zero triple.
4. **Classification:** worker (`analyze_function_complete`).
5. **Callers / xrefs:** `FUN_00797d70` @ `0x00797df0` (CALL; `LEA EBX,[ESI+0x80]`); thunk `0x00427040` (JMP `E9 7B 01 00 00`).
6. **Callees:** `FUN_00426f70`; `operator_delete` @ `0x00489822`.
7. **Name:** `StdVector_DestroyRuns_0x80_Inferred` (Ghidra `FUN_004271c0`). Scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004271c0` **retired**.
8. **Decompile ≡ raw CF**; **bytes win** on post-delete zero (decompiler false-noreturn).  
   Full hex: raw MEGA-128 append (69 B).

### Gaps

- Product 0x80 element English beyond `wstring@+0x0C` (hence `_Inferred` / "runs").  
- Unowned trampoline `FUN_00426f70` dual depth (body sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRuns_0x80_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004271c0.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004271c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004271c0_FUN_004271c0.md` |
| Function named | `docs/reconstruction/functions/aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed WQ9K-F]
  └─ owned text layout @ +0x28C:
        FUN_00797d70  UiTextLayout_CompleteDtor_Inferred  [dualed WQ9L-F]
          ├─ FUN_00797530(1) finalize
          ├─ free buffer vector @ +0x94
          ├─ LEA EBX,[layout+0x80]; CALL FUN_004271c0  [OWN MEGA-128]
          └─ ~wstring @ +0x0C

FUN_004271c0  StdVector_DestroyRuns_0x80_Inferred  [OWN MEGA-128]
  ├─ FUN_00426f70  (~wstring trampoline elem+0xC)  [unowned]
  └─ operator_delete

thunk 00427040  JMP 004271c0
twin pattern: StdVector_Tidy_Stride24_EbxThis_Inferred 00465d70  [dualed W38-R]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004271c0-mega-128-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004271c0` | Port as **EBX-this vector tidy** stride **0x80**: per-elem `~wstring` @+0x0C via trampoline, delete buffer, zero +4/+8/+0xC. **Not** thiscall. Do **not** free host layout. Pair with dualed `UiTextLayout_CompleteDtor_Inferred` `00797d70` (`layout+0x80`). |
| Pair with | dualed layout complete `00797d70` (WQ9L-F); residual trampoline `00426f70`; twin tidy `00465d70` (W38-R). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (skills-abilities / UI text-layout run vector tidy)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN-ONLY dual **MEGA-128**: exclusive VA `0x004271c0`; no parent ledger edits; no Launcher.  
- Live tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + callee/call-site. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed — verdicts **accept** both paths.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; scaffold `Named_CalleeOf_*` retired.  
- Odd behavior preserved: Ghidra false-noreturn truncates after `operator_delete` (full CF via disasm + hex).  
- Product demangle open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
