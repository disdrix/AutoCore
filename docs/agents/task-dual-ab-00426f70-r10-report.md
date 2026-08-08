# Dual A/B report — R10-026 OWN-ONLY (`0x00426f70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-026**  
**Scope:** VA `0x00426f70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs + `analyze_data_region` (IAT) + parent/caller decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — **RunElem_WStringDtor_Plus0C_Trampoline** (callee of dualed `StdVector_DestroyRuns_0x80_Inferred` `0x004271c0`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00426f70` RunElem_WStringDtor_Plus0C_Trampoline_Inferred | **accept** — CF/ABI/ECX-this/+0x0C/IAT~wstring sealed; product element English residual only |

Path A (fidelity): **accept**.  
Path B (adversarial): full-element-dtor / narrow-string / local-RET / EBX-this / free-shell / VOG_DEBUG-product / skill-logic claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00426f70` — sealed facts

1. **Body:** `0x00426f70`–`0x00426f78` inclusive (**9 B** / `0x9`); pad `CC` after.
2. **ABI:** **ECX** = element base\*; no stack formals; void; **tail-JMP** IAT (no local `RET`).
3. **Semantics:** member dtor trampoline:
   - `ADD ECX, 0x0C`
   - `JMP DWORD PTR [0x009C62AC]` → `~basic_string<wchar_t>`
4. **Classification:** stub (Ghidra); structural trampoline.
5. **Callers / xrefs (7):** `FUN_004271c0` @ `0x004271d2`; `FUN_00427590` @ `0x00427599`; `FUN_005ac510` @ `0x005ac530`; 4× `Unwind@*`.
6. **Callees:** none as CALL — IAT tail only.
7. **Name:** `RunElem_WStringDtor_Plus0C_Trampoline_Inferred` (Ghidra `FUN_00426f70`). Scaffold `Named_CalleeOf_*` **retired**.
8. **Decompile ≡ intent**; **bytes win** on call-vs-JMP and false jumptable warning.  
   Full hex: `83c10cff25ac629c00`

### Gaps

- Product 0x80 element English beyond dualed "run" (hence `_Inferred`).  
- Other element fields unowned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RunElem_WStringDtor_Plus0C_Trampoline_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00426f70.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00426f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00426f70_FUN_00426f70.md` |
| Function named | `docs/reconstruction/functions/aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed WQ9K-F]
  └─ owned text layout @ +0x28C:
        FUN_00797d70  UiTextLayout_CompleteDtor_Inferred  [dualed WQ9L-F]
          ├─ FUN_00797530(1) finalize
          ├─ free buffer vector @ +0x94
          ├─ LEA EBX,[layout+0x80]; CALL FUN_004271c0  [MEGA-128 dualed]
          └─ ~wstring @ +0x0C (layout member)

FUN_004271c0  StdVector_DestroyRuns_0x80_Inferred  [MEGA-128]
  ├─ FUN_00426f70  RunElem_WStringDtor_Plus0C_Trampoline_Inferred  [OWN R10-026]
  └─ operator_delete

thunk 00427040  JMP 004271c0
also: FUN_00427590 destroy-range stride 0x80 → same trampoline
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00426f70-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00426f70` | Port as **thiscall trampoline**: `~wstring` at `elem+0x0C` via MSVC IAT. **Not** full element dtor. Do **not** free vector buffer. Pair with dualed `StdVector_DestroyRuns_0x80_Inferred` `004271c0`. |
| Pair with | dualed parent tidy `004271c0` (MEGA-128); grandparent layout complete `00797d70` (WQ9L-F). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (skills-abilities / UI text-layout run elem wstring trampoline)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN-ONLY dual **R10-026**: exclusive VA `0x00426f70`; no parent ledger edits; no Launcher.  
- Live tools: decompile + analyze_function_complete + get_function_by_address + read_memory + callers/xrefs + IAT analyze_data_region. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed — verdicts **accept** both paths.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; scaffold `Named_CalleeOf_*` retired.  
- Odd behavior preserved: decompiler call-shape + jumptable warning vs actual IAT tail JMP.  
- Product demangle open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
