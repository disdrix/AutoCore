# Review A (reconstruction fidelity): `aa_00578a60` CVOGHBSkillBase_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578a60` |
| **VA** | `0x00578a60`–`0x00578ab2` inclusive (**83 B** / `0x53`) |
| **Canonical name** | `CVOGHBSkillBase_dtor` |
| **Ghidra symbol** | `FUN_00578a60` |
| **Prior scaffold** | `FUN_00578a60` (2026-07-23 generic plate) |
| **Review date** | `2026-08-05` (R12-026 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00578a60_CVOGHBSkillBase_dtor.md` |
| **System** | `skills-abilities` / CVOGHBSkillBase lifecycle |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + parent/base/ctor/thunk decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **complete destructor body** for **`CVOGHBSkillBase`** (non-scalar; no free of `this`):

```text
CVOGHBSkillBase_dtor(this)
  *this = &PTR_FUN_009d3fdc
  if [this+0x6a0]: operator_delete[]([this+0x6a0]); [this+0x6a0]=0
  if [this+0x6b0]: operator_delete([this+0x6b0])
  [this+0x6b0]=[this+0x6b4]=[this+0x6b8]=0
  JMP CVOGHBBase_dtor(this)     // 0x00508390
```

Primary retail caller is dualed scalar deleting dtor `CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0` (vtbl[0]).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-026 re-verify) | `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_dtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00578a60.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00578a60_FUN_00578a60.md` |
| Function named | `docs/reconstruction/functions/aa_00578a60_CVOGHBSkillBase_dtor.md` |
| Live body | `disassemble_function` + `read_memory` 83 B @ `0x00578a60` |
| Vtbl | `read_memory` @ `0x009d3fdc` → LE `E08D5700` = scalar dtor; this unit **restores** same vtbl |
| Scalar parent dual | `A_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor` |
| Base dtor dual | `CVOGHBBase_dtor` @ `0x00508390` |
| Ctor dual | `CVOGHBSkillBase_ctor` @ `0x005788d0` |
| OnEnd vector clear (not merge) | `Skill_HB_ClearPtrVectorAt6b0_Inferred` @ `0x00578ac0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 83 B / ends JMP base | **Confirmed** | `get_function_by_address` `00578a60–00578ab2`; hex ends `E9 DD F8 F8 FF` |
| `__thiscall` ECX=this; no stack args | **Confirmed** | `MOV ESI,ECX`; no `RET n` |
| Vtbl restore `0x009d3fdc` | **Confirmed** | `C7 06 DC 3F 9D 00` |
| `+0x6a0` delete[] then zero | **Confirmed** | CALL `0048981c` + `ADD ESP,4` |
| `+0x6b0` delete buffer; always zero triad | **Confirmed** | free path + fall-through; three `MOV [ESI+off],EDI` |
| No element walk | **Confirmed** | no loop / no `004b99c0` |
| Tail to `CVOGHBBase_dtor` | **Confirmed** | JMP `0x00508390` |
| Class `CVOGHBSkillBase` | **Confirmed** | RTTI on same vtbl; ctor/scalar duals |
| Scalar parent always calls this | **Confirmed** | dualed `00578de0` |
| Live decompile skeleton ≡ scaffold raw | **Confirmed** | force_decompile 2026-08-05 |
| Decompiler noreturn delete / CALL base | **Noise** | bytes: return + JMP |
| Product mangled / field English | **Open** | |
| Runtime / bit-exact / differential | **Open** | Terminal false |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| vtbl restore | **Yes** |
| conditional delete[] `+0x6a0` + zero | **Yes** |
| conditional delete `+0x6b0` + always zero triad | **Yes** (decompile omits “always” only if misread noreturn) |
| tail base dtor | **Yes** (JMP; decompile shows call+return) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Role = complete dtor body (no free of this) | **Yes** |
| Class = `CVOGHBSkillBase` | **Yes** — RTTI / ctor / scalar family |
| Distinct from scalar `00578de0` | **Yes** |
| Distinct from OnEnd vector clear `00578ac0` | **Yes** |
| Product mangled on this VA | **No** |
| Family name twin of `CVOGHBBase_dtor` | **Yes** |

**Decision:** promote **`CVOGHBSkillBase_dtor`** (no `_Inferred` — class + role sealed by RTTI family + MSVC complete-body pattern; same gate as R11-006 scalar dual).

---

## 6. Gaps (non-blocking)

1. Product/PDB mangled complete-body symbol.  
2. Product English for `+0x6a0` table / `+0x6b0` vector.  
3. Whether destroy-without-OnEnd can leave live element objects (buffer free only).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
