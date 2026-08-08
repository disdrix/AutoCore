# Dual A/B report — R10-033 OWN-ONLY (`0x00520520`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-033**  
**Scope:** VA `0x00520520` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + parent call-site bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual partition — inventory-transfer worker under parent `0x0052e640` (RE success fraction).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00520520` Character_GetReverseEngineerSkillCapacityByTier_Inferred | **accept-with-gaps** — CF/ABI/RET4/field+0x598/mult table/2 call sites/character-ECX sealed; product field English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): item-this / tinker Named_CalleeOf / plain RET / leaf / ST0 return / wrong mult set **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00520520` — sealed facts

1. **Body:** `0x00520520`–`0x005206aa` inclusive (**395 B** / `0x18b`); NOP pad `0x005206ab`; jump table data `0x005206ac`–`0x005206c3` (6 dwords).
2. **ABI:** **ECX** = character; stack **tier**; **EAX** = int capacity; **`RET 4`** all exits.
3. **Semantics:** `capacity = floor(skill_byte(+0x598) * mult[tier])` for tier 0..5; else 0.
4. **Mults (read_memory):** 3.5 / 3.5 / 2.8 / 2.1 / 1.4 / 0.7 (`0x009da8a4`, `0x00aaaa3c`, `0x009cefc0`, `0x009cefbc`, `0x00a0f710`).
5. **Callees:** CRT `floor` only (worker).
6. **Callers (2):** `FUN_0052e640` @ `0x0052ea2b` (`PUSH row+1`); @ `0x0052ea96` (`PUSH tier 0..5`) — both ECX=character.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `Character_GetReverseEngineerSkillCapacityByTier_Inferred` (Ghidra `FUN_00520520`). Product field English open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/table sealed via `disassemble_function` + `read_memory` + call-site bytes.
10. **Retired scaffold:** `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520`.

### Gaps

- Product English for `character+0x598`.  
- Designer meaning of tier vs recipe-row ordinal (`row+1` at site A).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00520520_FUN_00520520.md` |
| Annotated | `docs/reconstruction/raw/aa_00520520_FUN_00520520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetReverseEngineerSkillCapacityByTier_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00520520.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520.cpp` |
| Function | `docs/reconstruction/functions/aa_00520520_FUN_00520520.md` |
| Function named | `docs/reconstruction/functions/aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0052e640  Character_ComputeReverseEngineerSuccessFraction_Inferred  [parent MEGA-117]
  ├─ primary: floor(skill×3.5) inline vs material cost_sum
  ├─ FUN_00520520  Character_GetReverseEngineerSkillCapacityByTier_Inferred  [OWN R10-033]
  │    ├─ @0052ea2b capacity(row+1) vs secondary cost
  │    └─ @0052ea96 capacity(tier) in score (capacity−need)
  └─ UI: %.01f%% / "Requires At Least %d Reverse Engineering"
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00520520-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00520520` | Port as **character** `+0x598` × tier mult → **int** capacity. **thiscall**, **one stack tier**, **`RET 4`**. Mults 3.5/2.8/2.1/1.4/0.7. |
| Pair with | parent RE fraction `0052e640`; primary skill×3.5 gate is **inline in parent**, not this VA. |
| Do not merge | item tier mappers (`00521eb0`); tinker Named_CalleeOf plates; parent score weights `{2.5,2.0,…}`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- **not** touched by R10-033
