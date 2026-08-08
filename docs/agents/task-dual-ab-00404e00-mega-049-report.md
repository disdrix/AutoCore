# Dual A/B report — MEGA-049 OWN-ONLY (`0x00404e00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-049**  
**Scope:** VA `0x00404e00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-049 residual dual seal — RecvSkillStatusEffect nested leaf (partition skills-abilities).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404e00` CVOGPhysics_WriteNotFullyReadyOut_Inferred | **accept-with-gaps** — CF/ABI/RET4/leaf/polarity/2 call sites sealed; product field English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-decoder / ready-probe-merge / polarity-flip / entity-this / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404e00` — sealed facts

1. **Body:** `0x00404e00`–`0x00404e22` inclusive (**35 B** / `0x23`); pad `CC` after.
2. **Hex:** `8A414084C0741183790800740B8B44240432C98808C204008B442404B1018808C20400`.
3. **ABI:** **ECX** = CVOGPhysics this; stack `uint8_t* out`; **EAX** = out; **`RET 4`** ×2 exits.
4. **Semantics:** write-not-fully-ready out-byte:
   - fully ready (`byte(+0x40)!=0` **AND** `dword(+0x08)!=0`) → `*out = 0`
   - else → `*out = 1`
5. **Callees:** none (leaf).
6. **Callers (2):**
   - `FUN_005d0d60` `Skill_ApplyBoundStatusMotionTable_Inferred` @ `0x005d0fb6` — soft heading when `*out`
   - `FUN_005d7f70` `CVOGHBAICreatureBase_DoLogic` @ `0x005d80a5` — AI state branch when `*out`
7. **Call-site this:** both load **ECX = `*(entity+0x08)`** (phys).
8. **Family:** same fully-ready fields as dualed `CVOGPhysics_SetRotation` (`0x00404dc0`) skip gate (inverted consumer polarity). Distinct from ready-probe `FUN_005070b0` (`+0x44`/`+0x29`).
9. **Name:** `CVOGPhysics_WriteNotFullyReadyOut_Inferred` (Ghidra `FUN_00404e00`). Product English open → `_Inferred`. Retire Named_CalleeOf scaffold.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
11. **Partition note:** skills-abilities / RecvSkillStatusEffect is **nested-caller seed only** — body role is physics readiness.

### Gaps

- Product English for `phys+0x40` / `phys+0x08` beyond behavioral fully-ready.  
- Runtime / bit-exact / differential.  
- Parent ledger lockstep (OWN-ONLY excluded).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.md` |
| Annotated | `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_WriteNotFullyReadyOut_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404e00.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00404e00_FUN_00404e00.md` |
| Function named | `docs/reconstruction/functions/aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RecvSkillStatusEffect  [dualed elsewhere]
  └─ … nested …
       └─ FUN_005d0d60  Skill_ApplyBoundStatusMotionTable_Inferred  [dualed W22-A]
            └─ FUN_00404e00  CVOGPhysics_WriteNotFullyReadyOut_Inferred  [OWN MEGA-049]
                 (ECX = *(entity+8); soft heading iff *out)

FUN_005d7f70  CVOGHBAICreatureBase_DoLogic  [dualed W25-J]
  └─ FUN_00404e00  [OWN MEGA-049]
       (ECX = *(entity+8); AI state branch iff *out)

CVOGPhysics_SetRotation  0x00404dc0  [dualed]
  └─ same +0x40/+0x08 fully-ready skip (dispatch when NOT ready)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00404e00-mega-049-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404e00` | Port as **CVOGPhysics not-fully-ready out-byte writer**. **thiscall RET 4**. `*out=0` when ready (`+0x40 && +0x08`); else `*out=1`. Return out* in EAX. |
| Pair with | dualed SetRotation `00404dc0` / setPosition `0040d2a0` fully-ready skip; do **not** merge with ready-probe `005070b0`. |
| Callers | skill motion `005d0d60` soft heading; AI DoLogic `005d7f70` state branch — both need `*(entity+8)` phys this. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (physics readiness — not skill-packet)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00404e00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; Named_CalleeOf scaffold retired.  
- Odd behavior preserved: decompiler void vs EAX=out; polarity fully-ready→0.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
