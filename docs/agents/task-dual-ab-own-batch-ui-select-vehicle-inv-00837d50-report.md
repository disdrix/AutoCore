# OWN-ONLY dual A/B batch report

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Scope:** Dual EACH if no prior `A_aa_*` for five VAs.

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x00837d50` | `aa_00837d50` | `UiSelectWidget_ApplySelectChrome_Inferred` | **accept-with-gaps** |
| `0x008e9290` | `aa_008e9290` | `UiTargetPanel_PaintSlotChrome_Inferred` | **accept-with-gaps** |
| `0x00862b70` | `aa_00862b70` | `UI_VehicleInvHardpoint_RecomputeMode_Inferred` | **accept-with-gaps** |
| `0x0087d810` | `aa_0087d810` | `UI_VehicleInvSheet_RebuildStatsLabels_Inferred` | **accept-with-gaps** |
| `0x0085fd20` | `aa_0085fd20` | `Client_UI_InventorySheet_RemoveByItem` | **accept** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** HTTP `127.0.0.1:8089` — `decompile_function`, `disassemble_function`, `read_memory`, callers/xrefs/callees. No `disassemble_bytes`. Program: `autoassault.exe`.

---

## Written

### Dual A/B (10 files)

- `docs/reconstruction/reviews/A_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md`
- `docs/reconstruction/reviews/A_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md`
- `docs/reconstruction/reviews/B_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md`
- `docs/reconstruction/reviews/B_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md`

### Named function records (5)

- `docs/reconstruction/functions/aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md`
- `docs/reconstruction/functions/aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md`
- `docs/reconstruction/functions/aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md`
- `docs/reconstruction/functions/aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md`
- `docs/reconstruction/functions/aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md`

### Other

- Raw live dual appends on each `raw/aa_*_FUN_*.md`
- Legacy `functions/aa_*_FUN_*.md` pointer notes
- Scratch `tmp/a_00837d50.md` … `a_0085fd20.md`
- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Prior `A_aa_*` for any of 5 VAs | **None existed** — all dualled |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Full bit-exact clean of `FUN_0087d810` (~0x28be body) | Structural dual only; formulas residual |
| Ghidra rename/plate apply | Docs-only dual |

---

## Sealed one-liners

1. **`00837d50`**: ESI=widget, EAX→`+0x518`; vtbl chrome `+0xd0/+0xcc/+0x444/+0xcc`; optional child float; tail `+0x34c`.
2. **`008e9290`**: EAX=panel, EBX=slot; paint `0xFF32FF32` vs `0xFFAFAFAF` on 4 slots @ `+0x5d8`.
3. **`00862b70`**: EAX=widget, EDI=vehicle; mode 0/1/2 @ `+0x520`; redraw on change via `+0x3b4/+0x34c`.
4. **`0087d810`**: stack sheet*; empty vs full label rebuild for vehicle inv stats (`+0x55c..+0x580`).
5. **`0085fd20`**: EAX=item → COID push → `0085fcc0`; ESI=sheet from caller.

---

## AutoCore impact

- All five are **client UI** helpers (select chrome / target slots / vehicle inv / sheet remove).
- No server packet ownership in these units.
- Pair with existing parent duals: `00893580`, `008e9690`, `008800e0`, `0085fcc0`.
