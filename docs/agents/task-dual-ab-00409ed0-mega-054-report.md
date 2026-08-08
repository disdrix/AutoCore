# Dual A/B report — MEGA-054 OWN-ONLY (`0x00409ed0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-054**  
**Scope:** VA `0x00409ed0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-054 residual dual seal — Named_CalleeOf scaffold under SkillSet_GetEntryCount chain → **copy_backward 0x18**.  
**Hint matched:** Named_CalleeOf SkillSet_GetEntryCount → role refined to reverse range copy, not count.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409ed0` SkillSet_CopyBackward_0x18 | **accept** — CF/ABI/RET0/stride0x18/5 callers/leaf sealed; Named_CalleeOf retired |

Path A (fidelity): **accept**.  
Path B (adversarial): GetEntryCount-identity / thiscall / RET4 / forward-merge / ctor-loop / void-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409ed0` — sealed facts

1. **Body:** `0x00409ed0`–`0x00409f0a` inclusive (**59 B** / `0x3B`); pad `CC` after `RET`.
2. **ABI:** **EAX** = dest_end (in) / dest_begin (out); **ECX** = src_end; **EDX** = src_begin; **`RET`** (no stack args).
3. **Semantics:** MSVC-style **copy_backward** of **0x18-byte POD** SkillSet entries (6 dwords):
   - Empty: `CMP EDX,ECX` / early `RET` (EAX unchanged).
   - Loop: `SUB ECX,0x18`; `SUB EAX,0x18`; copy 6 dwords; until `ECX == EDX`.
   - No null-dest skip (unlike forward twin).
   - No callees; saves EBX/ESI/EDI.
4. **Callees:** none (leaf).
5. **Callers (5 UNCONDITIONAL_CALL):**
   - `FUN_00412730` @ `0x004129c0`
   - `FUN_00440f80` @ `0x004411fc`
   - `FUN_00442760` @ `0x004429df`
   - `FUN_00454f30` @ `0x004551ba`
   - `FUN_0046bba0` @ `0x0046be30`
6. **Xrefs:** 5 UNCONDITIONAL_CALL (same sites).
7. **Forward twin:** dualed `SkillSet_UninitializedCopy_0x18` `0x00442b00` (ADD +0x18; null-dest skip).
8. **Stride peer:** dualed `SkillSet_GetEntryCount` `0x00402d80` (`(end-begin)/0x18`).
9. **Name:** `SkillSet_CopyBackward_0x18` (Ghidra `FUN_00409ed0`). Retired: `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00409ed0`.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product field English for 0x18 entry.  
- Exact MSVC demangle.  
- Runtime / bit-exact / differential.  
- Parent insert bodies residual (not OWN).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409ed0_SkillSet_CopyBackward_0x18.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00409ed0_SkillSet_CopyBackward_0x18.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00409ed0_FUN_00409ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00409ed0_FUN_00409ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_CopyBackward_0x18.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409ed0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00409ed0.cpp` |
| Function | `docs/reconstruction/functions/aa_00409ed0_FUN_00409ed0.md` |
| Function named | `docs/reconstruction/functions/aa_00409ed0_SkillSet_CopyBackward_0x18.md` |

---

## Chain context (not dualled; evidence only)

```text
SkillSet vector insert / reallocate parents
  FUN_00412730 / FUN_00440f80 / FUN_00442760 / FUN_00454f30 / FUN_0046bba0
  ├─ FUN_00442b00  SkillSet_UninitializedCopy_0x18        [dualed — forward]
  ├─ FUN_00409ed0  SkillSet_CopyBackward_0x18             [OWN MEGA-054]
  ├─ FUN_00402d80  SkillSet_GetEntryCount                 [dualed — count]
  └─ FUN_00406f00  SkillSet_Vector_UninitializedFillN…    [dualed — fill]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409ed0-mega-054-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409ed0` | Port as **copy_backward** of **0x18 POD** entries. **EAX=dest_end→dest_begin**, **ECX=src_end**, **EDX=src_begin**, **RET 0**. No null check. No ctors. Keep distinct from forward `00442b00` and from GetEntryCount `00402d80`. |
| Pair with | dualed forward copy `00442b00`; dualed GetEntryCount `00402d80`; dualed fill-n `00406f00`; residual insert parents. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`Named_CalleeOf_*` → `SkillSet_CopyBackward_0x18`)  
- `systems/*` skills residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00409ed0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: no null-dest skip (unlike forward twin); decompiler void/phantom corrected via assembly.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
