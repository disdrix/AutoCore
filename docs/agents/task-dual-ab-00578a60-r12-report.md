# Dual A/B report — R12-026 OWN-ONLY (`0x00578a60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-026**  
**Scope:** VA `0x00578a60` (`aa_00578a60`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + parent/base/ctor/thunk samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-026**.  
**Work item:** Residual dual seal — skills-abilities; complete dtor body for `CVOGHBSkillBase`.  
**Partition parent dual:** `0x00578de0` (`CVOGHBSkillBase_ScalarDeletingDtor`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00578a60` CVOGHBSkillBase_dtor | **accept-with-gaps** — CF/ABI/offsets/vtbl restore/delete-split/base-tail/class sealed via assembly; product mangled + field English + destroy-order + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): scalar-collapse / free-this / OnEnd-element-walk-merge / noreturn-delete / CALL-not-JMP-base / wrong delete[]-vs-delete claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00578a60` — sealed facts

1. **Body:** `0x00578a60`–`0x00578ab2` inclusive (**83 B** / `0x53`); pad `CC` then sibling `FUN_00578ac0` @ `0x00578ac0`.
2. **ABI:** MSVC **`__thiscall`** — **ECX=this**, no stack formals; epilogue **`JMP 0x00508390`** (`CVOGHBBase_dtor`), not bare `RET` / not `ret 4`.
3. **Semantics:** MSVC **complete destructor body** (non-scalar):
   - Restore `*this = &PTR_FUN_009d3fdc` (skill-base vtbl; same as ctor install).
   - If `[this+0x6a0]`: **`operator_delete[]`** @ `0x0048981c` (`ADD ESP,4`); zero field.
   - If `[this+0x6b0]`: **`operator_delete`** @ `0x00489822` (`ADD ESP,4`).
   - Always zero vector triad `+0x6b0 / +0x6b4 / +0x6b8`.
   - Tail to dualed `CVOGHBBase_dtor` (base vtbl `0x009cdab0` + optional owner detach).
   - **Does not** free `this` (scalar deleting dtor owns that).
   - **Does not** walk/teardown vector elements (OnEnd clear @ `0x00578ac0` owns that).
4. **Ctor link:** dualed `CVOGHBSkillBase_ctor` @ `0x005788d0` sets vtbl, zeros vector, stores `FUN_0058ab60(arg7)` at `+0x6a0` (`operator_new__(0x4b0)` + 300-dword seed).
5. **Callers / xrefs (CODE):**
   - `FUN_00578de0` @ `0x00578de3` — scalar deleting dtor (partition parent dual)
   - `thunk_FUN_00578a60` @ `0x00548f90` — 5-byte JMP thunk
   - Unwind@`009a4650`, `009a4670`, `009a8640`, `009a8700`, `009a8ae0`, `009a8b60` — EH cleanup
6. **Callees:** `operator_delete[]`, `operator_delete`, `FUN_00508390` / `CVOGHBBase_dtor`.
7. **Name:** `CVOGHBSkillBase_dtor` (Ghidra `FUN_00578a60`). No `_Inferred` — class RTTI Confirmed + complete-body role sealed (family twin of dualed `CVOGHBBase_dtor`; same gate as R11-006 scalar dual).
8. **Decompile skeleton ≡ scaffold raw**; assembly corrections: noreturn-delete noise, CALL→JMP base, thiscall label.

### Byte seal

```
00578a60  56                 push esi
00578a61  8B F1              mov  esi, ecx
00578a63  8B 86 A0 06 00 00  mov  eax, [esi+0x6a0]
00578a69  57                 push edi
00578a6a  33 FF              xor  edi, edi
00578a6c  3B C7              cmp  eax, edi
00578a6e  C7 06 DC 3F 9D 00  mov  dword [esi], 0x009d3fdc
00578a74  74 09              jz   skip_arr
00578a76  50                 push eax
00578a77  E8 A0 0D F1 FF     call operator_delete[]   ; 0x0048981c
00578a7c  83 C4 04           add  esp, 4
00578a7f  89 BE A0 06 00 00  mov  [esi+0x6a0], edi
00578a85  8B 86 B0 06 00 00  mov  eax, [esi+0x6b0]
00578a8b  3B C7              cmp  eax, edi
00578a8d  74 09              jz   skip_buf
00578a8f  50                 push eax
00578a90  E8 8D 0D F1 FF     call operator_delete     ; 0x00489822
00578a95  83 C4 04           add  esp, 4
00578a98  89 BE B0 06 00 00  mov  [esi+0x6b0], edi
00578a9e  89 BE B4 06 00 00  mov  [esi+0x6b4], edi
00578aa4  89 BE B8 06 00 00  mov  [esi+0x6b8], edi
00578aaa  5F                 pop  edi
00578aab  8B CE              mov  ecx, esi
00578aad  5E                 pop  esi
00578aae  E9 DD F8 F8 FF     jmp  0x00508390          ; CVOGHBBase_dtor
```

Hex: `568bf18b86a00600005733ff3bc7c706dc3f9d00740950e8a00df1ff83c40489bea00600008b86b00600003bc7740950e88d0df1ff83c40489beb006000089beb406000089beb80600005f8bce5ee9ddf8f8ff`

### Gaps

- Product / PDB mangled complete-body symbol.  
- Product English for `+0x6a0` seeded table and `+0x6b0` vector.  
- Guarantee that OnEnd (or equivalent) clears vector **elements** before this free-buffer path.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00578a60_CVOGHBSkillBase_dtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00578a60_CVOGHBSkillBase_dtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_dtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578a60.cpp` |
| Function | `docs/reconstruction/functions/aa_00578a60_FUN_00578a60.md` |
| Function named | `docs/reconstruction/functions/aa_00578a60_CVOGHBSkillBase_dtor.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d3fdc  [CVOGHBSkillBase vtbl]
  [0]  FUN_00578de0  CVOGHBSkillBase_ScalarDeletingDtor  [parent dual R11-006]
         └─ FUN_00578a60  CVOGHBSkillBase_dtor  [OWN R12-026]
              ├─ operator_delete[]  (+0x6a0 array)
              ├─ operator_delete    (+0x6b0 buffer only)
              └─ JMP FUN_00508390  CVOGHBBase_dtor  [dualed]

CVOGHBSkillBase_ctor (0x005788d0)  [dualed]
  └─ installs PTR_FUN_009d3fdc; FUN_0058ab60 → +0x6a0; zeros +0x6b0 triad

Skill_HB_ClearPtrVectorAt6b0_Inferred (0x00578ac0)  [dualed sibling]
  └─ OnEnd element walk + free — do NOT merge with complete dtor

thunk_FUN_00578a60 (0x00548f90)
  └─ JMP complete dtor

EH Unwind frames (009a4650 … 009a8b60)
  └─ CALL complete dtor on unwind
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00578a60-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00578a60` | Port as **CVOGHBSkillBase complete dtor body**. **`__thiscall`** ECX=this. Restore skill vtbl, **delete[]** `+0x6a0`, **delete** vector buffer `+0x6b0` and zero triad, **tail** `CVOGHBBase_dtor`. Do **not** free `this`. Do **not** walk/teardown vector elements (OnEnd owns that). Do **not** merge with scalar `00578de0` or clear-vector `00578ac0`. |
| Pair with | scalar `00578de0`; ctor `005788d0`; base dtor `00508390`; OnEnd clear `00578ac0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` skills-abilities residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00578a60`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + parent/base/ctor/thunk samples. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use assembly-corrected CF under sealed family name; twin keeps `FUN_00578a60`.  
- Odd behavior preserved: buffer free without element teardown; tail JMP (not CALL+RET).  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
