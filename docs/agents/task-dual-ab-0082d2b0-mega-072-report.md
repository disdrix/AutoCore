# Dual A/B report — MEGA-072 OWN-ONLY (`0x0082d2b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-072**  
**Scope:** VA `0x0082d2b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `analyze_control_flow` + callers/xrefs + `get_assembly_context` + `read_memory` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-072**.  
**Work item:** Mega residual dual seal — popup-shell rebuild callee of dualed `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0x0082fe20`).  
**Hint retired into name:** `UI_InteractionMenu_RebuildPopupShell` → `_Inferred`.  
**Scaffold retired:** `Named_CalleeOf_Skill_i_m_qb_2d_btn_menu_skills_xml_0082d2b0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082d2b0` UI_InteractionMenu_RebuildPopupShell_Inferred | **accept-with-gaps** — CF/ABI/offsets/string/call graph/DATA vtbl sealed; product host class + vtbl English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-cast / skill-only Named_CalleeOf / button-factory / stdcall / no-gate / wrong layer / free-list claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082d2b0` — sealed facts

1. **Body:** `0x0082d2b0`–`0x0082d3ce` exclusive (**286 B** / `0x11E`); terminal **`C3`** @ `0x0082d3cd`; pad **`CC`**.
2. **ABI:** **`__thiscall`**; **ECX** = menu host (`MOV ESI,ECX`); void; **`RET`** (no stack cleanup). SEH `LAB_009b3381`.
3. **Semantics:** **popup-shell rebuild** when `host+0x4C0 ≠ 0`:
   - `host.vtbl+0x450()` pre-clear.
   - `operator_new(0x34)` + `FUN_00416920` with **CL=2** → store CNDHash* @ **`+0x534`**.
   - Reset depth `+0x68` / float `+0x74` / clamp `+0x70` / flag `+0x4A4`.
   - If dialog @ **`+0x538`**: `host.vtbl+0xbc(old)`.
   - `operator_new(0x488)` + `FUN_007b5dd0(p,0)` → attach `host.vtbl+0xa8`.
   - Load **`i_d_pop_2d_wnd_blocker.xml`** (`dialog.vtbl+0x28`); layer **70000** (`0x11170`, `dialog.vtbl+0x74`).
   - Bump count; store dialog; float `-(float)count` @ `+0x74`; update max; `host.vtbl+0x3f4(1)`.
4. **Callers (7 CALL + 1 DATA):** dualed populate `0082fe20` @ `0082fe31`; skill `0082f1d0`; equip `0082de30`; `00830960`; `00830b90`; `00831894`; `008323c9`; DATA vtbl **`0x00a733b8`**.
5. **Xrefs:** 7 UNCONDITIONAL_CALL + 1 DATA.
6. **Callees:** `operator_new` @ `0x00489892`; `FUN_00416920`; `FUN_007b5dd0`; host/dialog vtbls.
7. **String:** `0x00a4c5ec` `"i_d_pop_2d_wnd_blocker.xml"`.
8. **Name:** `UI_InteractionMenu_RebuildPopupShell_Inferred` (Ghidra `FUN_0082d2b0`). Product class open → `_Inferred`.
9. **Decompile ≡ raw CF**; float store sealed via asm (`NEG; CVTSI2SS; MOVSS`) — decompiler `(int)(float)` presentation gap only.
10. **Peer dual:** `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` (`0x0082ce20`) complementary teardown of `+0x534`.

### Gaps

- Product MSVC class English for menu host.  
- Host/dialog vtbl method English (`+0x450` / `+0xa8` / `+0xbc` / `+0x3f4` / dialog `+0x28` / `+0x74`).  
- Dual of `FUN_007b5dd0` / full product type of `FUN_00416920` (size/flag sealed; English open).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082d2b0_FUN_0082d2b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0082d2b0_FUN_0082d2b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_RebuildPopupShell_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082d2b0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_i_m_qb_2d_btn_menu_skills_xml_0082d2b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0082d2b0_FUN_0082d2b0.md` |
| Function named | `docs/reconstruction/functions/aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed WQ9E-D]
  ├─ FUN_0082d2b0  UI_InteractionMenu_RebuildPopupShell_Inferred  [OWN MEGA-072]
  │     ├─ operator_new(0x34) → FUN_00416920(CL=2)  → +0x534 CNDHash
  │     ├─ host.vtbl+0xbc(old +0x538)
  │     ├─ operator_new(0x488) → FUN_007b5dd0        [residual]
  │     ├─ load i_d_pop_2d_wnd_blocker.xml @ layer 70000
  │     └─ host.vtbl+0x3f4(1)
  ├─ Object_ResolveFromTFID / affinity gates
  └─ packs (Ignore/Friends/Tell/Trade/Clan/Convoy/name)
        └─ UI_InteractionMenu_AddConvoyInviteOrKick_Inferred  [dualed]

CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred  [dualed]
  └─ complementary lifecycle for +0x534 (teardown, not rebuild)

Other CALL parents (skill/equip/misc +0x4C0 hosts) — shared shell, not OWN
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082d2b0-mega-072-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082d2b0` | Port as **popup-shell rebuild** for active menu host (`+0x4C0`). **thiscall RET 0**. Replace CNDHash @ `+0x534`, blocker dialog @ `+0x538` from `i_d_pop_2d_wnd_blocker.xml` layer **70000**. Preserve depth float as `-(float)count` @ `+0x74`. |
| Do **not** | Merge with button packs (`0082f8d0`…`0082fd50`); do not treat as skill-cast; do not keep skill-only Named_CalleeOf name. |
| Pair with | dualed populate `0082fe20`; dualed convoy pack `0082fb30`; dualed CNDHash teardown `0082ce20`; residual NDUI ctor `007b5dd0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming ledgers (parent-owned only)
- Retire any residual Named_CalleeOf skill-only index rows pointing at `0x0082d2b0`
