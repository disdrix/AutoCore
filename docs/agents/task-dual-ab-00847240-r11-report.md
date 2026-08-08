# Dual A/B report — R11-029 OWN-ONLY (`0x00847240`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-029**  
**Scope:** VA `0x00847240` (`aa_00847240`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_function_labels` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-029**.  
**Work item:** Residual dual seal — inventory-transfer item tooltip type/meta line builder; partition score parent `0x00513fc0`.  
**Hint retired:** `Mission_Mission_Object_00847240` (string-weak).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00847240` UI_ItemTooltip_AppendTypeMetaLines_Inferred | **accept-with-gaps** — CF/ABI/cdecl/EDI host/type map/rarity/meta/patentee/RE lines/2 callers sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-only name / thiscall-ECX / equip-packet / setter / merge-with-detail-panel / bool-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00847240` — sealed facts

1. **Body:** `0x00847240`–`0x008479f0` exclusive (**1968 B** / `0x7B0`); two plain **`C3`** exits (`ADD EAX,1` / `ADD EAX,2`).
2. **ABI:** **cdecl** stack `(Item* item, char showMeta)`; callers **`ADD ESP,8`**. **EDI** = UI text host (caller-live; vfuncs `+0x250` / `+0x224` / `+0x22c`). **Not** pure thiscall.
3. **Semantics:** item tooltip **type + meta line builder**:
   - Type-class switch `holder+0x38` → English (Mission Object, Junk…Accessory, UNKNOWN…).
   - Type-6 subtype `blob+0x3f4` (Junk / Repair Kit / Paint Can / Ornament / Hazard Kit / Trick Material / Useable Item / Item).
   - Type-0xc weapon path: mount flags `blob+0x536`, spray `+0x537`, explosion radius float `+0x508`, melee subtype 9.
   - Rarity: `", "` + table `DAT_00b04214` stride `0x48` index `blob+0x4b8` + color `FUN_005140d0` (skip type 4).
   - Meta (`showMeta`): customize via dualed `FUN_00513fc0`; not-tradable `blob+0x4be`; charges `item+0x180` / unlimited `blob+0x4bc==-1`.
   - Patentee C-string `item+0x101` → `"Patented By: "` color `0xffaedeff`.
   - Session-gated RE/memorize forbid via dualed `FUN_00522950` color `0xffff2020`.
   - Return ≈ line-count delta.
4. **Callers (2 UNCONDITIONAL_CALL):**
   - `FUN_00843a60` @ `0x00843dc1` — equipped compare (`push 1; push item`).
   - `FUN_0084b890` `UI_ItemDetailPanel_Refresh_Inferred` @ `0x0084be00` — detail refresh (`push 1; push object`).
5. **Xrefs:** 2 UNCONDITIONAL_CALL (no DATA/vtbl-only).
6. **Callees (notable):** `00513fc0`, `00522950`, `005129b0`, `005140d0`, `007a6de0`, `007a69d0`, `0040da70`, `00599dd0`, `00844fa0`, `sprintf`.
7. **Family:** dualed detail panel `0084b890`, dualed tooltip stats `UI_BuildItemTooltipStats`, dualed bind probe `00513fc0`, dualed patentee match `00522950`. **Do not merge** with panel refresh or stats builder.
8. **Name:** `UI_ItemTooltip_AppendTypeMetaLines_Inferred` (Ghidra `FUN_00847240`). Retires `Mission_Mission_Object_00847240`.
9. **Decompile ≡ raw CF**; re-verify append-only on raw.
10. **Partition parent** `0x00513fc0` is wave score parent and **live customize-line callee**, not structural sole owner.

### Gaps

- Product / PDB demangle for text-host class and panel RTTI.  
- Weapon mount-flag product English beyond UI strings.  
- Exact layout consumer of return line-count.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00847240_UI_ItemTooltip_AppendTypeMetaLines_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00847240_UI_ItemTooltip_AppendTypeMetaLines_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00847240_FUN_00847240.md` |
| Annotated | `docs/reconstruction/raw/aa_00847240_FUN_00847240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ItemTooltip_AppendTypeMetaLines_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00847240.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Mission_Mission_Object_00847240.cpp` |
| Function | `docs/reconstruction/functions/aa_00847240_FUN_00847240.md` |
| Function named | `docs/reconstruction/functions/aa_00847240_UI_ItemTooltip_AppendTypeMetaLines_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_ItemDetailPanel_Refresh_Inferred  0x0084b890  [dualed]
  ├─ layout / broken overlay / name lines
  ├─ FUN_00847240  UI_ItemTooltip_AppendTypeMetaLines_Inferred  [OWN R11-029]
  │     ├─ Item_RequiresBindOrTradeLock  0x00513fc0  [dualed MEGA-050]
  │     ├─ Item_PatenteeMatchesCharacterOrEmpty_*  0x00522950  [dualed]
  │     └─ EnsureLootRarityTableLoaded_*  0x005129b0  [dualed]
  └─ UI_BuildItemTooltipStats  [dualed]  — do not merge

FUN_00843a60  equipped-compare panel  [residual]
  └─ FUN_00847240  (showMeta=1)
```

Partition host `inventory-transfer` names the **system bucket**; leaf role is **client tooltip text**.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00847240-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00847240` | Port as **tooltip type/meta line appender**: type-class table + rarity + optional bind/trade/charges + patentee + RE forbid. cdecl `(item, showMeta)`; EDI text host; return line delta. |
| Distinct from | Detail panel refresh `0084b890`; stats builder; bind probe `00513fc0` (callee only). |
| Pair with | dualed `00513fc0`, `00522950`, `005129b0`, `0084b890`; residual equipped-compare `00843a60`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `UI_ItemTooltip_AppendTypeMetaLines_Inferred` @ `0x00847240` / `aa_00847240`.
- Retire: `Mission_Mission_Object_00847240`.
- Verdict: **accept-with-gaps**; Terminal **false**.
