# Dual A/B report — MEGA-077 OWN-ONLY (`0x0082fc40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-077**  
**Scope:** VA `0x0082fc40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs/callees + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-077**.  
**Hint:** `UI_InteractionMenu_AddTrade`.  
**System:** skills-abilities / interaction menu.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082fc40` UI_InteractionMenu_AddTrade_Inferred | **accept-with-gaps** — CF/ABI/RET0/strings/IDs/slot/range/call sites sealed; product host class + `+0x6B4` English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / skill-cast / linear-1600 / EDX-target / destroy-on-disable claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082fc40` — sealed facts

1. **Body:** `0x0082fc40`–`0x0082fd4a` exclusive (**266 B** / `0x10A`); pad `CC`. Epilogue **`ret`** (`C3`) after `POP EDI; MOV ESP,EBP; POP EBP`.

2. **ABI:** parent-preserved registers (not formal ECX-thiscall entry):
   - **ESI** = interaction **menu host***
   - **EBX** = **target object*** (parent `MOV EBX,EBP` at both sites)
   - **No** stack cleanup (`ret 0`)
   - Frame: `AND ESP,0xFFFFFFF0; SUB ESP,0x1C` for SSE dist temps

3. **Semantics — add Trade button pack:**
   - Gate: `*(target+0x6B4) < 1` **OR** `*(local+0x6B4) > 0` (local = `DAT_00d1b6d8`).
   - Create via host **`vtbl+0x444`**: plate `"i_m_int_2d_btn_generic.xml"`, flags `0`, id **`0x11175`**, `-1`.
   - Label via btn **`vtbl+0x1D8`**: **`"Trade"`**, `1`, `1`.
   - Store button at host **`+0x550`** (`ESI[0x154]`).
   - Fetch target + local XYZ via SharedBase chain **`vtbl+0x1A0`**.
   - If button non-null and dist² **>** `DAT_00aaa674` (**1600.0f** → range **40**): disable via **`vtbl+0xD4(0)`**.

4. **Callers (1 fn, 2 sites):** `FUN_0082fe20` (`UI_InteractionMenu_PopulateTargetButtons_Inferred`)
   - `0x0082fed7` — order-0 pack (after Tell; before Clan)
   - `0x0082ff0b` — order-≠0 pack (after Clan; before Tell)

5. **Xrefs:** 2 UNCONDITIONAL_CALL (same sites).

6. **Callees:** none direct (all vtbl indirect).

7. **Name:** `UI_InteractionMenu_AddTrade_Inferred` (Ghidra `FUN_0082fc40`). Prior plate scaffold `UI_int_btn_generic_0082fc40` **retired** as primary. Product menu class open → `_Inferred`.

8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / MSVC demangle for menu host class.  
- English for `+0x6B4` and SharedBase position getter.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082fc40_FUN_0082fc40.md` |
| Annotated | `docs/reconstruction/raw/aa_0082fc40_FUN_0082fc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddTrade_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082fc40.cpp` |
| Prior plate scaffold (superseded) | `docs/reconstruction/reconstructed-exact/UI_int_btn_generic_0082fc40.cpp` |
| Function | `docs/reconstruction/functions/aa_0082fc40_FUN_0082fc40.md` |
| Function named | `docs/reconstruction/functions/aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed WQ9E-D]
  ├─ resolve target TFID @ host+0x578
  ├─ skip if self / local affinity
  ├─ pack order via host vtbl+0x478
  │     order-0: Ignore → Friends → Tell → Trade → Clan → Convoy → Name
  │     order-≠0: reverse
  ├─ FUN_0082fc40  UI_InteractionMenu_AddTrade_Inferred  [OWN MEGA-077]
  │     id 0x11175 "Trade" → host+0x550; disable if dist² > 1600
  ├─ FUN_0082fb30  UI_InteractionMenu_AddConvoyInviteOrKick_Inferred  [dualed WQ9D-I]
  └─ sibling packs (Tell/Ignore/Friends/Clan/Name) residual
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082fc40-mega-077-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082fc40` | Port as **interaction-menu Trade button creator**. **ESI=menu host**, **EBX=target**, **ret 0**. Button id **`0x11175`**, plate `i_m_int_2d_btn_generic.xml`, label `"Trade"`, slot **`+0x550`**. Disable when **dist² > 1600.0f** (40 units) via `vtbl+0xD4(0)`. Do **not** model as skill-cast or ECX-thiscall leaf. |
| Pair with | dualed parent `0082fe20` PopulateTargetButtons; dualed convoy sibling `0082fb30`; residual Tell/Ignore/Friends/Clan/Name packs. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming / system map entries for `UI_InteractionMenu_AddTrade_Inferred`
- retire primary alias `UI_int_btn_generic_0082fc40` in any inventory that still points at the plate scaffold
