# Dual A/B report — R13-006 OWN-ONLY (`0x00548f90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-006**  
**Scope:** VA `0x00548f90` (`aa_00548f90`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + parent dual evidence only. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-006**.  
**Work item:** Residual dual seal — skills-abilities; pure JMP thunk of dualed `CVOGHBSkillBase_dtor`.  
**Partition parent dual:** `0x00578a60` (`CVOGHBSkillBase_dtor`).  
**Inventory name retired as final:** `thunk_FUN_00578a60`.  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00548f90` CVOGHBSkillBase_dtor_Thunk_Inferred | **accept** — pure 5 B JMP to dualed parent; CALL-site alias for shared scalar + EH sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): expanded-decompile-as-local / second-complete-dtor / free-this / OnEnd-merge / base-dtor-alias / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00548f90` — sealed facts

1. **Body:** `0x00548f90`–`0x00548f94` inclusive (**5 B** / `0x5`); pad `CC` after.
2. **Insn:** sole **`JMP 0x00578a60`** (`E9 CB FA 02 00`); rel32 `0x0002FACB`.
3. **Classification:** **thunk** (`analyze_function_complete` `is_thunk: true`).
4. **ABI (inherited):** MSVC **`__thiscall`** — **ECX=this**; no stack formals; parent tails base dtor via JMP.
5. **Semantics:** pure alias of dualed MSVC **complete destructor body** for `CVOGHBSkillBase` (parent R12-026):
   - Restore `*this = &PTR_FUN_009d3fdc`.
   - Conditional `delete[]` at `+0x6a0`; conditional `delete` buffer at `+0x6b0`; always zero triad `+0x6b0/+0x6b4/+0x6b8`.
   - Tail JMP `CVOGHBBase_dtor` @ `0x00508390`.
   - **Does not** free `this`; **does not** walk vector elements.
6. **Callers / xrefs (CODE):**
   - `FUN_00651190` @ `0x00651193` — shared skill-subclass scalar deleting dtor (dualed R12-001)
   - `Unwind@009a89d0` @ `0x009a89d3` — EH cleanup CALL
   - `Unwind@009a8a00` @ `0x009a8a03` — EH cleanup CALL
   - `Unwind@009a8a30` @ `0x009a8a33` — EH cleanup CALL
7. **Callees:** JMP → `FUN_00578a60` only (parent callees: `operator_delete[]`, `operator_delete`, `CVOGHBBase_dtor`).
8. **Name:** `CVOGHBSkillBase_dtor_Thunk_Inferred` (Ghidra `thunk_FUN_00578a60`). `_Inferred` for thunk demangle; parent class RTTI sealed without it.
9. **Decompile caveat:** Ghidra follows thunk and prints parent body (false noreturn on delete); **bytes win**.

### Byte seal

```
00548f90  E9 CB FA 02 00     jmp  0x00578a60
; pad CC…
```

Hex: `e9cbfa0200`  
Target check: `0x00548f90 + 5 + 0x0002FACB = 0x00578A60`.

### Gaps

- Product / PDB demangle of the thunk symbol itself.  
- Parent field English residuals (`+0x6a0` / `+0x6b0`) — inherited.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00548f90_thunk_FUN_00578a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00548f90_thunk_FUN_00578a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_dtor_Thunk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00548f90.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/thunk_FUN_00578a60.cpp` |
| Function | `docs/reconstruction/functions/aa_00548f90_FUN_00548f90.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00548f90_thunk_FUN_00578a60.md` |
| Function named | `docs/reconstruction/functions/aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d3fdc  [CVOGHBSkillBase vtbl]
  [0]  FUN_00578de0  CVOGHBSkillBase_ScalarDeletingDtor  [dualed R11-006]
         └─ CALL FUN_00578a60  CVOGHBSkillBase_dtor  [dualed R12-026 parent]
              ├─ operator_delete[]  (+0x6a0 array)
              ├─ operator_delete    (+0x6b0 buffer only)
              └─ JMP FUN_00508390  CVOGHBBase_dtor  [dualed]

CVOGHBSkill_SharedScalarDeletingDtor_Inferred (0x00651190)  [dualed R12-001]
  └─ CALL thunk 0x00548f90 → FUN_00578a60
       then optional operator_delete(this) on flags&1

thunk @ 0x00548f90  CVOGHBSkillBase_dtor_Thunk_Inferred  [OWN R13-006]
  └─ JMP → FUN_00578a60
       ↑ CALL from FUN_00651190 + Unwind@009a89d0 / 009a8a00 / 009a8a30

CVOGHBSkillBase_ctor (0x005788d0)  [dualed]
  └─ installs PTR_FUN_009d3fdc

Skill_HB_ClearPtrVectorAt6b0_Inferred (0x00578ac0)  [dualed sibling]
  └─ OnEnd element walk — do NOT merge with complete dtor / this thunk
```

Partition host **skills-abilities** matches product class role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00548f90-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00548f90` | Port as **pure alias** of `CVOGHBSkillBase_dtor` — **no second body**. `__thiscall` ECX=this. CALL density / EH only. |
| Parent | dualed `CVOGHBSkillBase_dtor` @ `0x00578a60` — real complete body. |
| Pair with | shared scalar `00651190`; base scalar `00578de0`; ctor `005788d0`; base dtor `00508390`; OnEnd clear `00578ac0`. |
| Distinct from | free-this scalars; OnEnd vector walk; inventing local teardown at this VA. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` skills-abilities residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

Name to register: `CVOGHBSkillBase_dtor_Thunk_Inferred` @ `0x00548f90` / `aa_00548f90`.  
Verdict: **accept**; Terminal **false**.

---

## Process

- OWN VA only (`0x00548f90`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + get_function_by_address. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use assembly-corrected JMP-only CF under sealed family name; twin keeps `FUN_00548f90`; scaffold path retained.  
- Odd behavior preserved: decompiler expands parent; retail is JMP-only.  
- `_Inferred` on thunk demangle; never Runtime Confirmed. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
