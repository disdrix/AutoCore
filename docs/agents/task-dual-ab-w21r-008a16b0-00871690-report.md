# Dual A/B report — W21-R OWN-ONLY (`0x008a16b0`, `0x00871690`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W21-R  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x008a16b0`, `0x00871690` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ `analyze_function_complete` / xrefs). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x008a16b0` | `CDlgQuickBar_CreateChildWidgets_Inferred` | **accept-with-gaps** |
| `0x00871690` | `UiHost_FindTrackedPairNode_Inferred` | **accept** |

---

## VA `0x008a16b0` — CDlgQuickBar_CreateChildWidgets_Inferred

### Sealed facts

1. **ABI:** `__thiscall`/`__fastcall` ECX = QuickBar host; void; MSVC SEH `LAB_009b98c0`. Entry `mov edi,ecx`.
2. **Role:** CreateChildWidgets-style builder — allocate/parent chrome, two page buttons, hazard skins, Y-reposition, page rebind, selection restore. **Not** cast/network.
3. **Vtable:** data slot `0x00a4d320` → this VA; adjacent strings `Show Quick Menu` / `Hide Quick Menu` @ `0x00a4d338`.
4. **Key children:**
   - `+0x664` `new(0x580)` + `FUN_0082f4a0`
   - `+0x624`/`+0x628` `new(0x488)` + `FUN_007b5dd0` (z-order)
   - `+0x62c`/`+0x630` `new(0x4cc)` + `FUN_0079c860`
   - `+0x668` `new(0x520)` + `FUN_008c4f10`
   - `+0x634` inc btn `i_d_qb_2d_btn_inc.xml` (scale 0.5f)
   - `+0x66c`/`+0x670` **two** `UI_QuickBar_CreateSlotButton` (`0x00825bf0`) — `+0x500=0/1`, labels `"1"`/`"2"`
   - Hazard bar/inc/gauge/label XML set; gauge `new(0x4f8)` + `FUN_0097ffa0`
   - `+0x684` `new(0x58c)` + `FUN_008b0ce0`
5. **Tail:** `FUN_008a0370` → read `DAT_00d1da38[page]` → `FUN_008a04b0` / `FUN_008a1110` / `FUN_008a0e10` → clear `DAT_00d1a9fc` → if col `+0x548` null/6 then `FUN_008a0210(1)` else `FUN_00826780(1)` → optional `FUN_008a0770` → `vtbl+0x34c`.
6. **Live decompile ≡** 2026-07-23 raw (no CF delta). Body `0x008a16b0`–`0x008a1e58`.
7. **Prior seed name** `UI_qb_hazard_gauge` **superseded** (too narrow).

### Gaps

1. Product C++ method name (`_Inferred`).
2. English roles for early 0x488/0x4cc children.
3. SetSelected ECX residual on restore arm.
4. Sibling duals for `FUN_008a1110` / `FUN_008a04b0` (not OWN).
5. Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_008a16b0_FUN_008a16b0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CDlgQuickBar_CreateChildWidgets_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_008a16b0.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_008a16b0_FUN_008a16b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008a16b0_FUN_008a16b0.annotated.md` |

**Sibling context (not owned):** `UI_QuickBar_CreateSlotButton` `0x00825bf0`; `QuickBar_SelectPage` `0x008a0ed0`; `UI_QuickBarSlotButton_SetSelected` `0x00826780`; `FUN_008a0e10` / `FUN_008a1110` / `FUN_008a0210`; `UI_HostRepositionAnchoredChild_Y` `0x008a0370`.

---

## VA `0x00871690` — UiHost_FindTrackedPairNode_Inferred

### Sealed facts

1. **ABI:** `__thiscall` ECX = host; stack keyA, keyB; **`RET 8`**. Returns **node\*** or **0**.
2. **Bytes:** entry `mov esi,ecx` + `add esi,0x628`; exit `c2 08 00`. Body `0x00871690`–`0x00871738`.
3. **Semantics:**
   - `List_TraversalLock` (`FUN_004294f0`) on `this+0x628`
   - iterate `FUN_004113b0` until end or match
   - match: `node+8 == keyA && node+0xc == keyB`
   - unlock if `this+0x650` → `LeaveCriticalSection(this+0x62c)` on both exit paths
4. **Callers (only 3):** `FUN_008718a0` (ClearTrackedPairAndRefresh), `FUN_008718d0`, `FUN_008719d0`.
5. **Callees:** lock, iterate, LeaveCS only — pure find.
6. **Live decompile ≡** 2026-07-23 raw. Full CF sealed.
7. **Legacy VOGClient seed alias** superseded for role naming.

### Gaps

1. Product host/node C++ names.
2. Semantic type of keyA/keyB (Tentative).
3. Runtime golden.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00871690_FUN_00871690.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/UiHost_FindTrackedPairNode_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00871690.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871690.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_00871690_FUN_00871690.md` |
| Annotated | `docs/reconstruction/raw/aa_00871690_FUN_00871690.annotated.md` |

**Sibling context (not owned):** `UiHost_ClearTrackedPairAndRefresh` `0x008718a0`; list helpers `0x004294f0` / `0x004113b0`; refresh `0x00871150`.

---

## AutoCore impact

- **QuickBar host:** on dialog create/show, build chrome via this virtual (vtable `0x00a4d320` family); only **two** special page buttons use `CreateSlotButton` size `0x554` with indices 0/1; full 10-column rebind is `FUN_008a0e10` after `FUN_008a1110`, not this unit alone. First-show selection restores `DAT_00d1da38[page]` with gate on column `+0x548` (differs from SelectPage empty-mask).
- **UiHost list:** pair lookup is find-only under CS at `+0x628`; consumers clear `*node` then refresh — implement find as pure scan, never mutate keys here.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`008a16b0`, `00871690`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
