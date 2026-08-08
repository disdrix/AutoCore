# Dual A/B report — MEGA-050 OWN-ONLY (`0x00513fc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-050**  
**Scope:** VA `0x00513fc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `disassemble_function` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes` primary.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer residual of dualed **`Client_ConfirmEquipOrCustomizeItem`** (`0x00941b20`): bind / trade-lock need probe.  
**Hint:** `Item_RequiresBindOrTradeLock`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513fc0` Item_RequiresBindOrTradeLock | **accept-with-gaps** — CF/ABI/RET8/type-gate/`0x4b8`/vtbl+0x60/4 callers sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Named_CalleeOf-only / decompiler-no-this / setter-or-packet / capacity-`0x4b8` / fail-open-null claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00513fc0` — sealed facts

1. **Body:** `0x00513fc0`–`0x0051404f` inclusive (**144 B** / `0x90`); three **`RET 8`** exits.
2. **ABI:** **ECX** = `Item*`; stack `coid_lo` (`item+0x160`), `coid_hi` (`item+0x164`); **AL** bool; **`RET 8`**. Decompiler omits this — sealed via disassembly + four call sites.
3. **Semantics:** bind / permanent-customize / trade-lock **need** predicate:
   - `reaction = *(*(item+0xa4)+0xe4e8)`
   - `obj = CVOGReaction_ResolveObjectTarget(reaction, 1, coid…)` → null ⇒ false
   - Type gate: `holder+0x38` ∈ `{0xc,0x1c,0xa,0x10,0xe}` **or** (`==6` && `blob+0x3f4` ∈ `{10,11}`)
   - Inside gate: `need = (int16)(blob+0x4b8) >= 2`; if `obj->vtbl[+0x60]() != 0` return true; else return `need`
4. **Callees:** `CVOGReaction_ResolveObjectTarget` `0x004bae70`; indirect vtbl+0x60.
5. **Callers (4 UNCONDITIONAL_CALL):**
   - `0x00941cdc` in `Client_ConfirmEquipOrCustomizeItem` (`0x00941b20`) — permanent-customize modal
   - `0x008638bd` in `Client_UI_InventoryItemClickDispatch` (`0x008635b0`) — same modal
   - `0x008104cc` in `Client_OnVehicleSwitchFailure` (`0x00810360`) — auto `Item_SetCustomized(1)`
   - `0x0084778b` in `FUN_00847240` — `"\nCustomizes On Equip"` / owner UI
6. **Live decompile ≡ 2026-07-23 raw CF**; re-verify append-only on raw.
7. **Name:** `Item_RequiresBindOrTradeLock` (Ghidra `FUN_00513fc0`). Retires `Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0`.

### Gaps

- Product type-class / subtype English.  
- Product names for `blob+0x4b8` and `vtbl+0x60`.  
- Original PDB symbol.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00513fc0_Item_RequiresBindOrTradeLock.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00513fc0_Item_RequiresBindOrTradeLock.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_RequiresBindOrTradeLock.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513fc0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00513fc0_FUN_00513fc0.md` |
| Function named | `docs/reconstruction/functions/aa_00513fc0_Item_RequiresBindOrTradeLock.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ConfirmEquipOrCustomizeItem  0x00941b20  [dualed]
  ├─ gates: town / type4 / equip precheck / space
  ├─ if confirmFlag && !bit20(Customized) && Item_RequiresBindOrTradeLock(...):
  │     modal 0x4e58/0x4e59 permanent-customize trade-lock warn
  │     return 0 (defer)
  └─ else emit equip C2S via 0x00931440

Client_UI_InventoryItemClickDispatch  0x008635b0
  └─ same modal when probe true && !bit20

Client_OnVehicleSwitchFailure  0x00810360
  └─ if Item_RequiresBindOrTradeLock: Item_SetCustomized(1)  [0x00513e30 dualed]

FUN_00847240  (item UI / tooltip)
  └─ if probe: "Customizes On Equip" or owner branch

Item_RequiresBindOrTradeLock  0x00513fc0  [OWN MEGA-050]
  └─ CVOGReaction_ResolveObjectTarget  0x004bae70
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00513fc0-mega-050-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00513fc0` | Port as **read-only** `Item_RequiresBindOrTradeLock(item, coid_lo, coid_hi)`. **thiscall RET 8**. Do **not** write Customized bit here. |
| Pair with | dualed equip gate `00941b20`; dualed `Item_SetCustomized` `00513e30`; resolve `004bae70`. |
| Gate | Type set + subtype 10/11; threshold `blob+0x4b8 >= 2`; vtbl+0x60 force-true. |
| UI | Modal / tooltip copy owned by callers, not this leaf. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY` / coverage ledgers as applicable  
- Do **not** claim runtime Confirmed without Launcher evidence
