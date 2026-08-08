# Dual A/B report — MEGA-117 OWN-ONLY (`0x0052e640`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-117**  
**Scope:** VA `0x0052e640` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `disassemble_function` + `analyze_function_complete` + `get_function_callers` / `callees` + `get_xrefs_to` / `get_function_xrefs` + `read_memory` + `batch_decompile` helpers. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — nested callee of dualed **Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred** (`0x0085ce20`).  
**Partition hint:** `UI_ItemHover_ApplyTooltipText` → **parent role**, not this VA.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052e640` Character_ComputeReverseEngineerSuccessFraction_Inferred | **accept-with-gaps** — CF/ABI/RET4/ST0/constants/callers sealed; product field English + sibling duals + orphan site open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tooltip-self / tinkering-scaffold / cdecl / ECX=item / float-CBID / merge-with-0052e1d0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052e640` — sealed facts

1. **Body:** `0x0052e640`–`0x0052eb76` inclusive (**1335 B** / `0x537`); pad `90`; jump-table @ `0x0052eb78`.
2. **ABI:** **ECX** = character*; stack item*; **ST0** float; **`RET 4`** on all exits (`C2 04 00`).
3. **Semantics:** Reverse Engineer **success fraction**:
   - Gates: item, lootgen (`004ce940`), configured slots (`00599dd0`) > 0.
   - Free: `character+0x6b4 >= 1` → **1.0**.
   - Eligibility: `FUN_00522950` else **0**.
   - Primary material cost from def CBIDs `@+0x498` (type **0x1a**, rank `@+0x4c8` − 1).
   - Budget: `floor(skill_byte(+0x598) × 3.5)`; over → **0**.
   - Secondary recipe-row walk (vtbl+0x60 / +0x5c → `005097b0`); over capacity → **0**.
   - Zero primary cost → **100.0** (UI ×100 clamps to 100%).
   - Else tier bases `{50,50,40,30,20,10}` + skill weights `{2.5,2.5,2.0,1.5,1.0,0.5}` × **0.01**, cap **0.95**.
4. **Constants (`read_memory`):** 3.5 / 1.0 / 0 / 100 / 2.5 / 2.0@`a10e74` / 1.5 / 0.5 / 0.01 / 0.95.
5. **Callees:** `00404d70`, `004ce940`, `004f1e20`, `005097b0`, `00520520`, `00522950`, `00599dd0`, `floor`.
6. **Callers / xrefs:** `FUN_0085ce20` @ `0085ce6c`; `FUN_0084b890` @ `0084ba78` (`%.01f%%`); orphan `0085d7df`.
7. **Name:** `Character_ComputeReverseEngineerSuccessFraction_Inferred` (Ghidra `FUN_0052e640`). Product method open → `_Inferred`. Retire Named_CalleeOf tinkering scaffold.
8. **Decompile ≡ raw CF**; ABI/int-CBID sealed via `disassemble_function` + `read_memory` + call sites.

### Gaps

- Product English for `+0x598` / `+0x6b4` / material `+0x4c8`.  
- Dual siblings `0052e1d0`, `00522950`, `00520520`, `005097b0` (unowned).  
- Orphan call `0085d7df` function boundary.  
- Server RNG vs display-only.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052e640_FUN_0052e640.md` |
| Annotated | `docs/reconstruction/raw/aa_0052e640_FUN_0052e640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_ComputeReverseEngineerSuccessFraction_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052e640.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640.cpp` |
| Function | `docs/reconstruction/functions/aa_0052e640_FUN_0052e640.md` |
| Function named | `docs/reconstruction/functions/aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20  Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed WQ8R-H]
  mode 0 Reverse Engineer:
    ├─ FUN_0052e640  Character_ComputeReverseEngineerSuccessFraction_Inferred  [OWN MEGA-117]
    ├─ FUN_0052e1d0  required RE level (int)  [residual]
    ├─ FUN_00522950  RE eligibility  [residual]
    └─ FUN_00599dd0  ItemDef_CountConfiguredModSlots_Inferred  [dualed]

FUN_0084b890  item UI overlay
  └─ FUN_0052e640 → score*100 clamp → sprintf("%.01f%% %s")  [OWN MEGA-117]

FUN_0052e640 callees (evidence):
  ├─ 004ce940  CVOGLootGenerator_GetOrCreate  [dualed]
  ├─ 00599dd0  slot count  [dualed]
  ├─ 00404d70  GameData_LookupCloneBaseByCbid  [dualed]
  ├─ 00520520  skill capacity by tier  [residual]
  ├─ 005097b0  recipe-by-prefix ("GetTypelessRecipe")  [residual]
  └─ 00522950  eligibility  [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052e640-mega-117-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052e640` | Port as **character thiscall** returning **float success fraction** for Reverse Engineer. **ECX=character**, stack=item, **RET 4**, ST0 out. |
| Display | UI multiplies by **100** and clamps to **100** for `%.01f%%`. Formula path capped at **0.95** (95%). Free flag `+0x6b4≥1` → 1.0. Zero material cost → 100.0 sentinel. |
| Do **not** | Merge with required-level twin `0052e1d0`; treat CBIDs as floats; name as ItemHover tooltip presenter. |
| Pair with | dualed parent tooltip `0085ce20`; residual `0052e1d0` / `00522950` / `00520520`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when batching MEGA residuals  
- Inventory-transfer system map note: RE fraction helper under ItemHover mode 0  
- Retire any inventory rows still pointing at Named_CalleeOf tinkering scaffold for `aa_0052e640`
