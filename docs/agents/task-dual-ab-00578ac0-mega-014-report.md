# Dual A/B report — MEGA-014 OWN-ONLY (`0x00578ac0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-014**  
**Scope:** VA `0x00578ac0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `disassemble_function` + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — callee of dualed **Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred** (`0x00578ce0`): **clear ptr vector @ +0x6b0**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00578ac0` Skill_HB_ClearPtrVectorAt6b0_Inferred | **accept-with-gaps** — CF/ABI/RET0/vector triad/sole OnEnd caller/element teardown sealed; product field English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): noreturn / decompile-truncated-zeros / multi-caller / FireTail-merge / stack-arg / list-layout claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00578ac0` — sealed facts

1. **Body:** `0x00578ac0`–`0x00578b28` inclusive (**105 B** / `0x69`); pad `CC` ×5 before next unit.
2. **ABI:** **ECX** = skill HB this; no stack args; void; plain **`RET`**.
3. **Semantics:** clear owned pointer vector at `this+0x6b0..+0x6b8`:
   - Walk `[begin, end)` stride 4.
   - Non-null elem → `FUN_004b99c0` (`NDSpecialFX_TeardownCore_Inferred`, ECX=elem) + `operator_delete(elem)`.
   - Non-null buffer → `operator_delete(begin)`.
   - **Always** zero `+0x6b0`, `+0x6b4`, `+0x6b8`.
4. **Decompiler defects corrected via bytes:** false noreturn on `operator_delete`; missing zero-stores after non-null buffer free; elided ECX arg to `004b99c0`.
5. **Callees:** `FUN_004b99c0` (dualed); `operator_delete` @ `0x00489822` (IAT jmp `[0x009c6694]`; cdecl returns).
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — `FUN_00578ce0` @ `0x00578d18` (ECX=HB this / ESI).
7. **Name:** `Skill_HB_ClearPtrVectorAt6b0_Inferred` (Ghidra `FUN_00578ac0`). Product field English open → `_Inferred`. No `Named_CalleeOf_*` scaffold for this VA (FUN twin retained as machine-name alias).
8. **Live decompile skeleton ≡ scaffold raw**; clean uses assembly-corrected CF.

### Gaps

- Product / PDB symbol for method and HB vector field.  
- Allocation / push site for `+0x6b0` (FireTail-adjacent residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify APPEND) | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ClearPtrVectorAt6b0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578ac0.cpp` |
| Function | `docs/reconstruction/functions/aa_00578ac0_FUN_00578ac0.md` |
| Function named | `docs/reconstruction/functions/aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00578ce0  Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred  [dualed WQ9D-F]
  ├─ PTR_FUN_00af31e0(this, 0)          // client end hook
  ├─ CVOGReaction_ResolveObjectTarget   // target from TFID pack
  ├─ FUN_00578ac0  Skill_HB_ClearPtrVectorAt6b0_Inferred  [OWN MEGA-014]
  │     ├─ FUN_004b99c0  NDSpecialFX_TeardownCore_Inferred  [dualed]  ×N
  │     └─ operator_delete  ×(elems + buffer)
  ├─ owner vtbl+0x238 mode 1 …
  ├─ optional ClearCastBinding / FUN_0051f880(0) …
  └─ tail CVOGHBBase_EmptyVFunc (0x005081f0)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00578ac0-mega-014-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00578ac0` | Port as **clear owned `T*` vector** at skill HB `+0x6b0/+0x6b4/+0x6b8`. **thiscall**, plain RET. Per non-null element: **teardown core then delete** (do not skip `004b99c0`). Always null the triad after free. |
| Pair with | dualed OnEnd parent `00578ce0`; dualed element teardown `004b99c0`; residual vector fill / FireTail sibling. |
| Do not | Trust Ghidra noreturn; port decompiler path that skips zeros after buffer free; invent product field name as Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00578ac0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine ABI corrections (always-zero triad; teardown thiscall ECX).  
- Odd behavior preserved: null elements skipped; buffer free separate from element free; Ghidra noreturn ignored.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
