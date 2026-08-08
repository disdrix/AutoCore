# Dual A/B report — MEGA-016 OWN-ONLY (`0x0061b960`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-016**  
**Scope:** VA `0x0061b960` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — skills-abilities nested under dualed parent pulse `0x0061b6f0`.  
**Hint:** `Skill_HB_CopyTfid16At668`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0061b960` Skill_HB_CopyTfid16At668_Inferred | **accept** — CF/ABI/RET4/offset+0x668/16B/leaf/sole-caller sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): getter-merge / float4 / cdecl / mutator / +0x228-merge / multi-caller / Apply*-sibling claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0061b960` — sealed facts

1. **Body:** `0x0061b960`–`0x0061b986` inclusive (**39 B** / `0x27`); pad `CC` at `0x0061b987`.
2. **ABI:** **ECX** = skill-HB this; stack `TFID_16* out`; **EAX** = out; **`RET 4`**.
3. **Semantics:** leaf **16-byte TFID out-copy** from **`this+0x668..+0x677`**:
   - `mov eax, [esp+4]` → out  
   - `add ecx, 0x668`  
   - four dword pairs `out[i] ← src[i]`  
   - no branches; no callees; no stores to this.
4. **Callees:** none (leaf).
5. **Callers:** **1** UNCONDITIONAL_CALL — `FUN_0061b6f0` @ `0x0061b760`.
6. **Call-site:** `lea out / push / mov ecx,esi / call`; post-call uses `[eax]` then expands 4 dwords into target `vtbl+0x88` after `vtbl+0x214` resolve.
7. **Twin shape:** dualed `Object_CopyTfid16At228_Inferred` `0x0040aff0` (same prologue/body; offset `+0x228`).
8. **Name:** `Skill_HB_CopyTfid16At668_Inferred` (Ghidra `FUN_0061b960`). Product English open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB symbol.  
- Exact RTTI of skill-HB `this` without parent cast.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0061b960_FUN_0061b960.md` |
| Annotated | `docs/reconstruction/raw/aa_0061b960_FUN_0061b960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_CopyTfid16At668_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0061b960.cpp` |
| Function | `docs/reconstruction/functions/aa_0061b960_FUN_0061b960.md` |
| Function named | `docs/reconstruction/functions/aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  skill-HB shared pulse / status apply  [parent residual; not OWN]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus          [MEGA-004]
  ├─ FUN_0061b960  Skill_HB_CopyTfid16At668_Inferred  [OWN MEGA-016]
  │     → target vtbl+0x88(scaledShort, tfid0..3) after vtbl+0x214 resolve
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta            [MEGA-005]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta              [MEGA-006]
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool           [MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater      [MEGA-008]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect       [MEGA-009]

Twin (other system / dualed):
  FUN_0040aff0  Object_CopyTfid16At228_Inferred       [WQ9R-B]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0061b960-mega-016-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0061b960` | Port as **skill-HB TFID_16 out-copy** from **`this+0x668`**. **thiscall RET 4**; **EAX=out**. Leaf only — do not invent mutation. Keep distinct from object TFID copy `0040aff0` (+0x228). |
| Pair with | parent pulse `0061b6f0`; dualed twin `0040aff0`; sibling Apply* leaves under same parent (other MEGA owners). |

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

- OWN VA only (`0x0061b960`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine twin retained; ABI corrections (thiscall RET 4; EAX=out).  
- Odd behavior preserved: decompiler `void` vs EAX=out return.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
