# Review A (reconstruction fidelity): `aa_00578ac0` Skill_HB_ClearPtrVectorAt6b0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ac0` |
| **VA** | `0x00578ac0`–`0x00578b28` inclusive (**0x69 B** / 105) |
| **Canonical name** | `Skill_HB_ClearPtrVectorAt6b0_Inferred` |
| **Ghidra name** | `FUN_00578ac0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | MEGA-014 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/vector layout/sole caller sealed; product field English open |

---

## 1. Purpose

Destroy the skill-HB-owned **pointer vector** at `this+0x6b0..+0x6b8` during shared OnEnd teardown:

1. For each non-null element: dualed `NDSpecialFX_TeardownCore_Inferred` then `operator_delete`.
2. Free the array buffer if non-null.
3. Zero begin / end / capacity **always**.

Sole retail caller is dualed `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` (`0x00578ce0`) @ `0x00578d18`.

```c
// __thiscall; no stack args; plain RET
void Skill_HB_ClearPtrVectorAt6b0_Inferred(void *hb /* ECX */);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify APPEND) | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Skill_HB_ClearPtrVectorAt6b0_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00578ac0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00578ac0_FUN_00578ac0.md` |
| Function named | `docs/reconstruction/functions/aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |
| Live Ghidra | `decompile_function` / `analyze_function_complete` / `disassemble_function` / `read_memory` / `get_function_callers` / `get_function_xrefs` / `get_assembly_context` / `get_function_by_address` |
| Parent OnEnd dual | `A_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` |
| Element teardown dual | `A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred` |

**No** `disassemble_bytes`. Constants/CF from `read_memory` + `disassemble_function`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00578ac0`–`0x00578b28` incl. (**0x69 B**) | **Confirmed** | `get_function_by_address`; pad `CC` after RET |
| ECX=this; no stack args; plain RET | **Confirmed** | `MOV EDI,ECX`; epilogue `POP EDI/ESI; RET` |
| Vector `+0x6b0/+0x6b4/+0x6b8` begin/end/cap | **Confirmed** | loads + three `MOV dword,0` |
| Element stride 4 | **Confirmed** | `ADD ESI,4` |
| Per-elem `FUN_004b99c0` then `operator_delete` | **Confirmed** | `MOV ECX,EBX; CALL 004b99c0; PUSH EBX; CALL delete; ADD ESP,4` |
| `operator_delete` returns | **Confirmed** | `ADD ESP,4`; continue loop / zeros |
| Always zero three fields | **Confirmed** | fall-through after both buffer paths |
| Sole caller OnEnd `0x00578ce0` | **Confirmed** | 1 UNCONDITIONAL_CALL @ `0x00578d18` |
| Call-site ECX = HB this | **Confirmed** | `get_assembly_context`; ESI held as this |
| Element role = NDSpecialFX teardown | **High** | dualed callee `004b99c0` |
| Live decompile skeleton ≡ scaffold raw | **Confirmed** | 2026-08-05 re-decompile |
| Decompiler zero-store omission after free | **Confirmed defect** | corrected via bytes |
| Product C++ name / field English | **Inferred** | no string/RTTI on this VA |
| Runtime / bit-exact / differential | **Open** | Terminal false |

---

## 4. Control flow (sealed)

```text
it = [this+0x6b0]; end = [this+0x6b4]
if it != end:
  loop:
    p = *it
    if p:
      FUN_004b99c0(p)          // ECX=p
      operator_delete(p)       // cdecl; returns
    it += 1
    while it != [this+0x6b4]
buf = [this+0x6b0]
if buf: operator_delete(buf)
[this+0x6b0] = 0
[this+0x6b4] = 0
[this+0x6b8] = 0
RET
```

### Decompile ≡ raw CF (with known defects)

| Stage | Scaffold raw | Live decompile | Assembly |
|---|---|---|---|
| Iterate begin≠end | yes | yes | yes |
| Null-skip element | yes | yes | yes |
| Teardown + delete elem | yes | yes (noreturn warn) | yes + continue |
| Free buffer | yes | yes (noreturn warn) | yes + continue |
| Zero three fields | only if buf null | same defect | **always** |

Clean source uses **assembly-corrected** CF (always zero).

---

## 5. ABI

| Item | Evidence |
|---|---|
| thiscall ECX | entry `8B F9` (`MOV EDI,ECX`); caller keeps ESI as this |
| No `RET n` | `C3` plain RET |
| Callee `004b99c0` thiscall | `8B CB` before CALL |
| `operator_delete` cdecl | `PUSH`; `ADD ESP,4`; IAT `FF 25 94 66 9C 00` @ `0x00489822` |

---

## 6. Gaps (acceptable)

1. Product / PDB symbol for method and HB field at `+0x6b0`.
2. Allocation / push site that fills the vector (FireTail-adjacent residual; not this VA).
3. Whether every element is always NDSpecialFX (High via teardown callee; no RTTI in this body).
4. Runtime / bit-exact / differential (Terminal false; no Launcher).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw skeleton | **Pass** |
| Assembly corrections applied in clean | **Pass** |
| ABI / epilogue sealed | **Pass** |
| Sole OnEnd caller sealed | **Pass** |
| Clean uses meaningful name | **Pass** |
| No parent ledger edits / no Launcher | **Pass** |
| Verdict | **accept-with-gaps** |
