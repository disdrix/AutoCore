# Dual A/B report — MEGA-104 OWN-ONLY (`0x00513bc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-104**  
**Scope:** VA `0x00513bc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` / `get_xrefs_from` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer **Item_TinkerPrerequisiteGate** (sole callee of residual `Item_ValidateTinkerKitUse` `0x00513c10`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513bc0` Item_TinkerPrerequisiteGate_Inferred | **accept-with-gaps** — CF/ABI/RET4/AL-bool/type specials 0x44↔10 / 0x46↔11 / sole caller sealed; product type English + parent dual open |

Path A (fidelity): `00513bc0` **accept-with-gaps**.  
Path B (adversarial): full-validator / skill-check / fastcall-plain-RET / multi-status-return / unconditional-0x44 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00513bc0` — sealed facts

1. **Body:** `0x00513bc0`–`0x00513c06` inclusive (**71 B** / `0x47`); pad `CC` @ `0x00513c07`–`0x00513c0f` before sibling `FUN_00513c10`.
2. **ABI:** **ECX** = kit/item; stack `candidate*`; **AL** bool; **`RET 4`** (`C2 04 00` ×2).
3. **Semantics:** leaf **type-compatibility prerequisite gate**:
   - null candidate → false
   - `*(candidate+0xb4) == *(*(kit+0xa8)+0x38)` → true
   - candidate type **0x44** → true iff kit def short `@(*(host+0x3c)+0x3f4) == 10`
   - candidate type **0x46** → true iff same short **== 11**
   - else false
4. **Callees:** none (leaf).
5. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — `FUN_00513c10` @ `0x00513c36` (`TEST AL,AL`; fail → parent status `3`).
6. **Cross-link (context):** `FUN_00509b10` remaps type-6 subtype **10→0x44**, **11→0x46** (inverse of special arms).
7. **Name:** `Item_TinkerPrerequisiteGate_Inferred` (Ghidra `FUN_00513bc0`). Product English open → `_Inferred`. Retire Named_CalleeOf scaffold.
8. **Decompile ≡ raw CF**; ABI/immediates sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product type / field English (`0x44`, `0x46`, `+0xb4` vs `host+0x38`).  
- Parent residual `FUN_00513c10` dual (partition MEGA-036 family).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_TinkerPrerequisiteGate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513bc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00513bc0_FUN_00513bc0.md` |
| Function named | `docs/reconstruction/functions/aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20 / FUN_0085f660  Skill_You_do_not_possess_the_Tinkering… UI/apply  [residual]
  └─ FUN_00513c10  Item_ValidateTinkerKitUse residual  [MEGA partition; not OWN]
       ├─ FUN_00513bc0  Item_TinkerPrerequisiteGate_Inferred  [OWN MEGA-104]
       └─ FUN_00521eb0  Character_GetTinkerSkillOrCap residual  [MEGA-106]

FUN_00509b10  Item_ApplyModPack residual  [evidence]
  └─ type-6 subtype 10→0x44 / 11→0x46  (inverse of OWN specials)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00513bc0-mega-104-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00513bc0` | Port as **leaf bool type gate** for tinker prereq. **thiscall RET 4**, AL bool. Keep specials **0x44↔subtype 10** and **0x46↔subtype 11**. Do **not** fold skill/level/charge logic from parent `00513c10`. |
| Pair with | residual parent `00513c10`; residual skill cap `00521eb0`; dualed peer `Item_IsAffixableType` `00513d10` (same subtype window); remap peer `00509b10`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
**Not edited by this agent.**
