# Dual A/B report — MEGA-055 OWN-ONLY (`0x0040a600`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-055**  
**Scope:** VA `0x0040a600` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory` + callee/caller decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — sibling SkillSet consumer of dualed `SkillSet_GetEntryCount`.  
**Hint (partition):** Sibling SkillSet consumer.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040a600` SkillSet_Vector_UninitializedCopy_0x18_Inferred | **accept-with-gaps** — CF/ABI/RET-cdecl/stride-0x18/SEH/call-family sealed; product demangle + parent insert open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-Uses / Named_CalleeOf / thiscall / leaf-`00442b00`-merge / Ufill-merge / tree-helper / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040a600` — sealed facts

1. **Body:** `0x0040a600`–`0x0040a664` inclusive (**101 B** / `0x65`); pad/next `6A 00 6A 00…`.
2. **ABI:** **ECX** = `src_end`; stack `src_first`, `dest` (+2 unused caller pushes); **EAX** = `dest_end`; **`RET` (`C3`)** cdecl — callers **`ADD ESP, 0x10`**.
3. **Semantics:** MSVC-style **vector uninitialized_copy** for **0x18-byte** SkillSet entries:
   - SEH frame (`LAB_009bd090` / FS:[0]); EH state 0 in loop, −1 on exit.
   - Loop: while `first != end`: `FUN_00412b10(dest=EAX, src=ECX)` then both cursors `+0x18`.
   - Return destination end pointer (parent stores to `vector.end` @ `+0x8`).
4. **Callees:** `FUN_00412b10` only (6-dword / 0x18 element copy; null-dest guard).
5. **Callers (2 fns / 3 sites):** insert `FUN_00412730` @ `0x00412946`, `0x004129ad`; trampoline `FUN_00412a80` @ `0x00412a90`.
6. **Xrefs:** 3 UNCONDITIONAL_CALL.
7. **Family:** same insert parent as dualed Ufill `SkillSet_Vector_UninitializedFillN_0x18_Inferred` (`0x00406f00`) and dualed count `SkillSet_GetEntryCount` (`0x00402d80`); **distinct** from leaf `SkillSet_UninitializedCopy_0x18` (`0x00442b00`).
8. **Name:** `SkillSet_Vector_UninitializedCopy_0x18_Inferred` (Ghidra `FUN_0040a600`). Product demangle open → `_Inferred`. **Retired** `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context (Ghidra `__thiscall` mislabel corrected).

### Gaps

- Product / MSVC `_Ucopy` demangle English.  
- Full `NPCSkillSetEntry` field plate.  
- Parent insert `FUN_00412730` + trampoline `FUN_00412a80` undualed.  
- Exact meaning of 2 extra unused stack pushes.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedCopy_0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040a600.cpp` |
| Retired Named_CalleeOf | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600.cpp` |
| Function | `docs/reconstruction/functions/aa_0040a600_FUN_0040a600.md` |
| Function named | `docs/reconstruction/functions/aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00412730  SkillSet vector insert/reallocate  [undualed]
  ├─ SkillSet_GetEntryCount (0x00402d80)                              [dualed]
  ├─ SkillSet_Vector_UninitializedFillN_0x18_Inferred (0x00406f00)  [dualed]
  ├─ FUN_0040a600  SkillSet_Vector_UninitializedCopy_0x18_Inferred  [OWN MEGA-055]
  │     └─ FUN_00412b10  6-dword element copy
  ├─ FUN_00412a80  Ucopy trampoline → FUN_0040a600                  [undualed]
  └─ FUN_00409ed0 / FUN_00406f00 / operator_new|delete …

SkillSet_UninitializedCopy_0x18 (0x00442b00)  leaf register-ABI twin  [dualed W22-S]
  — different ABI (EAX/ECX/EDX); no SEH; do not merge
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040a600-mega-055-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040a600` | Port as **vector uninitialized_copy** of **0x18-byte** SkillSet entries. **ECX=end**, stack first/dest, **cdecl RET**, return dest end. Element assign = 6-dword copy (`FUN_00412b10` null-guard). Keep SEH-aware if exceptions matter; body element copy is non-throwing POD-ish. |
| Do **not** | Merge with leaf Ucopy `00442b00` (register ABI) or Ufill `00406f00` without adapters. Do not name as skill-cast product logic. |
| Pair with | dualed count `00402d80`; dualed fill `00406f00`; undualed parent insert `00412730`; trampoline `00412a80`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- promote `SkillSet_Vector_UninitializedCopy_0x18_Inferred`; retire Named_CalleeOf alias  
- Terminal remains **false** until runtime Confirmed
