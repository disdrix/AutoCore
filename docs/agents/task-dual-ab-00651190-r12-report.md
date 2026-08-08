# Dual A/B report — R12-001 OWN-ONLY (`0x00651190`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-001**  
**Scope:** VA `0x00651190` (`aa_00651190`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-001**.  
**Work item:** Residual dual seal — skills-abilities; shared MSVC scalar deleting dtor for `CVOGHBSkill_*` subclasses.  
**Partition parent dual:** `0x00614c80` (`CVOGHBSkill_Master_Execute`) — context only; already dualed.  
**Dual start baseline:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00651190` CVOGHBSkill_SharedScalarDeletingDtor_Inferred | **accept-with-gaps** — CF/ABI/shared-vtbl[0]/complete-body path sealed; product mangled + full class inventory + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): complete-dtor-collapse / base-scalar-merge / always-free / array-delete / singular-Master-or-XPAdder ownership / bare-ret claims **falsified**; product mangled **open**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00651190` — sealed facts

1. **Body:** `0x00651190`–`0x006511ae` exclusive (**30 B** / `0x1E`); terminal **`C2 04 00`**; pad `CC CC`.
2. **ABI:** MSVC **`__thiscall`** — **ECX=this**, stack **`uint8_t flags`**, **`ret 4`**, **EAX=this**.
3. **Semantics:** MSVC **scalar deleting destructor**:
   - Always `CALL 0x00548f90` — JMP thunk → `FUN_00578a60` (CVOGHBSkillBase complete dtor).
   - If `(flags & 1)` → `operator_delete(this)` @ `0x00489822` (+ `add esp,4`).
   - Return `this`.
4. **Xrefs:** **~39 DATA** from skill subclass vtbl[0] slots (`0x009d0e14` … `0x009e5304` incl. Master `0x009d0e6c`, XPAdder `0x009e5304`). **0** direct UNCONDITIONAL_CALL. CODE uses are **COMPUTED_CALL** virtual deletes (`push 1; call [vtbl+0]`).
5. **Callees:** `thunk_FUN_00578a60` (`0x00548f90` → `0x00578a60`); `operator_delete`.
6. **Family:** dualed base scalar `CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0` (same pattern, **different VA**, base vtbl `0x009d3fdc` only). Complete body `FUN_00578a60` residual (not OWN). Base twin pattern `CVOGHBBase_ScalarDeletingDtor` @ `0x00508630` (do **not** merge).
7. **Name:** `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` (Ghidra `FUN_00651190`). **`_Inferred`** — multi-class share, no product demangle; do not steal base-class name.
8. **Decompile ≡ raw CF ≡ bytes**; decompiler "delete does not return" is noise.
9. **Parent dual context:** Master Execute `0x00614c80` owner-null path → `vtbl[0](1)` lands here.

### Byte seal

```
00651190  56                 push esi
00651191  8B F1              mov  esi, ecx
00651193  E8 F8 7D EF FF     call 0x00548f90   ; → FUN_00578a60
00651198  F6 44 24 08 01     test byte [esp+8], 1
0065119d  74 09              jz   no_free
0065119f  56                 push esi
006511a0  E8 7D 86 E3 FF     call operator_delete
006511a5  83 C4 04           add  esp, 4
006511a8  8B C6              mov  eax, esi
006511aa  5E                 pop  esi
006511ab  C2 04 00           ret  4
```

Hex: `568bf1e8f87deffff644240801740956e87d86e3ff83c4048bc65ec20400`

### Gaps

- Product / PDB mangled symbol(s) for the COMDAT-merged scalar dtor.  
- Complete dtor `FUN_00578a60` undualed (not OWN).  
- Exhaustive subclass vtbl DATA inventory (samples sealed: Master, XPAdder + peer reports).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00651190_FUN_00651190.md` |
| Annotated | `docs/reconstruction/raw/aa_00651190_FUN_00651190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SharedScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00651190.cpp` |
| Function | `docs/reconstruction/functions/aa_00651190_FUN_00651190.md` |
| Function named | `docs/reconstruction/functions/aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase vtbl PTR_FUN_009d3fdc
  [0]  FUN_00578de0  CVOGHBSkillBase_ScalarDeletingDtor  [dualed R11-006]
         └─ FUN_00578a60  complete dtor  [residual]

Many CVOGHBSkill_* subclass vtbls (Master 009d0e6c, XPAdder 009e5304, …)
  [0]  FUN_00651190  CVOGHBSkill_SharedScalarDeletingDtor_Inferred  [OWN R12-001]
         └─ thunk 0x00548f90 → FUN_00578a60  complete dtor
              └─ FUN_00508390  CVOGHBBase_dtor  [dualed family]

Owner-null factory/execute paths (e.g. Master Execute 0x00614c80):
  push 1; call [vtbl+0]  → this VA → free heap HB

Do not merge with:
  CVOGHBBase_ScalarDeletingDtor  0x00508630
  CVOGHBSkillBase_ScalarDeletingDtor  0x00578de0
```

Partition host `skills-abilities` matches class role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00651190-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00651190` | Port as **shared skill-subclass scalar deleting dtor**: complete `CVOGHBSkillBase` teardown then optional free. **`__thiscall` + `ret 4`**. Virtual delete with **flags=1** frees; stack/member destroy with flags=0 must **not** free. Do **not** invent per-subclass dtor bodies when their vtbl[0] points here. Keep separate from base scalar `0x00578de0` and complete-only `0x00578a60`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
