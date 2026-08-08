# Dual A/B report — R11-002 OWN-ONLY (`0x0052e1d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-002**  
**Scope:** VA `0x0052e1d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** inventory-transfer residual — Reverse Engineer **required level** integer (parent twin success fraction `0x0052e640`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory` + parent call-site bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` (R11-002).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052e1d0` Character_ComputeReverseEngineerRequiredLevel_Inferred | **accept-with-gaps** — CF/ABI/RET4/EAX/int/constants/sole caller sealed; product field English + helper duals open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tooltip-self / tinkering-scaffold / cdecl / ECX=item / float-return / merge-with-0052e640 / percent claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Shared context (parent, not owned)

| Link | Notes |
|------|-------|
| Twin dual | `0x0052e640` `Character_ComputeReverseEngineerSuccessFraction_Inferred` — float success fraction |
| Parent tooltip | `0x0085ce20` mode 0: fraction ≤ 0 → `"Requires At Least %d Reverse Engineering"` via **this** VA |
| Capacity helper | `FUN_00520520` mults 3.5/3.5/2.8/2.1/1.4/0.7 (dualed R10-033) |
| Level helper | `FUN_005206d0` = `ceil(cost * 1/mult[tier])` (residual; table sealed here) |
| Domain | inventory-transfer Reverse Engineer client skill math |

---

## VA `0x0052e1d0` — sealed facts

1. **Body:** `0x0052e1d0`–`0x0052e636` inclusive (**1127 B** / `0x467`); pad `0xCC` to twin `@0x0052e640`.
2. **ABI:** **ECX** = character*; stack item*; **EAX** int; **`RET 4`** on both exits (`C2 04 00`).
3. **Semantics:** Reverse Engineer **required level**:
   - Gates: null item, slots (`00599dd0`) &lt; 1, free `character+0x6b4 > 0` → **0**.
   - Primary material cost from def CBIDs `@+0x498` (type **0x1a**, rank `@+0x4c8` − 1).
   - Base: `ceil(primary_cost * (1/3.5))` via `DAT_009cdff4`.
   - Secondary recipe-row walk (vtbl+0x60 / +0x5c → `005097b0`); accumulate total + per-row.
   - If primary_cost == 0 → **0**.
   - Else `required = max(base, FUN_005206d0(row_count, total), FUN_005206d0(tier, row_cost[tier]) for tier 1..5)`.
4. **Constants (`read_memory`):**

   | VA | Float | = 1/mult |
   |---|---:|---:|
   | `0x009cdff4` | 0.2857143 | 3.5 |
   | `0x009cefcc` | 0.3571429 | 2.8 |
   | `0x009cefc8` | 0.4761904 | 2.1 |
   | `0x00aaa7c4` | 0.7142857 | 1.4 |
   | `0x009cefc4` | 1.4285715 | 0.7 |

5. **Callees:** `00404d70`, `004ce940`, `004f1e20`, `005097b0`, `005206d0`, `00599dd0`, `ceil`.
6. **Callers / xrefs:** sole `FUN_0085ce20` @ `0085cfe9`.
7. **Name:** `Character_ComputeReverseEngineerRequiredLevel_Inferred` (Ghidra `FUN_0052e1d0`). Product method open → `_Inferred`. Retire Named_CalleeOf tinkering scaffold.
8. **Decompile ≡ raw CF**; ABI/int sealed via prologue/epilogue `read_memory` + call site.

### Gaps

- Product English for `+0x6b4` / material `+0x4c8`.  
- Dual helpers `005206d0`, `005097b0` (unowned).  
- Secondary-loop FPU CW / EBX decompiler noise.  
- Server vs display-only.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052e1d0_FUN_0052e1d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052e1d0_FUN_0052e1d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_ComputeReverseEngineerRequiredLevel_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052e1d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0052e1d0_FUN_0052e1d0.md` |
| Function named | `docs/reconstruction/functions/aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0052e1d0-r11-report.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20  Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed]
  mode 0 Reverse Engineer:
    ├─ FUN_0052e640  success fraction  [dualed MEGA-117]
    ├─ FUN_0052e1d0  required RE level (int)  [OWN R11-002]
    ├─ FUN_00522950  RE eligibility  [residual]
    └─ FUN_00599dd0  slot count  [dualed]

FUN_0052e1d0 callees (evidence):
  ├─ 004ce940  CVOGLootGenerator_GetOrCreate  [dualed]
  ├─ 00599dd0  slot count  [dualed]
  ├─ 00404d70  GameData_LookupCloneBaseByCbid  [dualed]
  ├─ 005206d0  cost→level by tier  [residual; table sealed]
  └─ 005097b0  recipe-by-prefix  [residual]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052e1d0` | Port as **character thiscall** returning **int required RE level**. **ECX=character**, stack=item, **RET 4**, EAX out. |
| Display | Parent formats `"Requires At Least %d Reverse Engineering"` when twin fraction ≤ 0. |
| Formula | `required = max(ceil(primary_cost/3.5), ceil(total/mult[rows]), ceil(row_cost[t]/mult[t]) for t=1..5)`. Free flag → 0. Zero primary → 0. |
| Do **not** | Merge with fraction twin `0052e640`; name as ItemHover tooltip; treat as float/ST0. |
| Pair with | dualed parent tooltip `0085ce20`; dualed twin `0052e640`; dualed capacity `00520520`. |

---

## Residual for parent merge (not edited here)

- Count **+1** dual unique when parent merges R11-002 (`0052e1d0`).
- NAMING_REGISTRY: `Character_ComputeReverseEngineerRequiredLevel_Inferred`.
- VERIFICATION_MATRIX row + `systems/inventory-transfer.md` entry point.
- Optional follow-up: dual `FUN_005206d0` / `FUN_005097b0`.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ analyze/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Name uses inventory-domain + `_Inferred` (no invented product plates).  
- Terminal false.
