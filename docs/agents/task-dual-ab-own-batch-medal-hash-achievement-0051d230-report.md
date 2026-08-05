# OWN-ONLY dual A/B batch report

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Scope:** Dual EACH if no prior `A_aa_*` for five VAs.

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x0051d230` | `aa_0051d230` | `CNDHash_Recreate` | **accept-with-gaps** |
| `0x0051e4d0` | `aa_0051e4d0` | `CNDHash_Insert_009ce0a8` | **accept-with-gaps** |
| `0x00604e10` | `aa_00604e10` | `MedalDef_ZeroOwnedStrings_Inferred` | **accept-with-gaps** |
| `0x00605090` | `aa_00605090` | `MedalDef_InitFromAchievementRow_Inferred` | **accept-with-gaps** |
| `0x007cea40` | `aa_007cea40` | `DbReader_LoadTAchievementRows_Inferred` | **accept-with-gaps** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `batch_decompile`, `disassemble_function`, `read_memory`, callers/xrefs/callees. No `disassemble_bytes`. Program: `autoassault.exe`.

**Parent chain (all five owned by one ensure path):** `FUN_00519660` medal-table lazy loader  
`Recreate(DAT_00b042e0,4)` → `LoadTAchievementRows` → loop `new(0x1c)` / ZeroStrings / InitFromRow / Insert.

---

## Written

### Dual A/B (10 files)

- `docs/reconstruction/reviews/A_aa_0051d230_CNDHash_Recreate.md`
- `docs/reconstruction/reviews/B_aa_0051d230_CNDHash_Recreate.md`
- `docs/reconstruction/reviews/A_aa_0051e4d0_CNDHash_Insert_009ce0a8.md`
- `docs/reconstruction/reviews/B_aa_0051e4d0_CNDHash_Insert_009ce0a8.md`
- `docs/reconstruction/reviews/A_aa_00604e10_MedalDef_ZeroOwnedStrings_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00604e10_MedalDef_ZeroOwnedStrings_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00605090_MedalDef_InitFromAchievementRow_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00605090_MedalDef_InitFromAchievementRow_Inferred.md`
- `docs/reconstruction/reviews/A_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md`
- `docs/reconstruction/reviews/B_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md`

### Named function records (5)

- `docs/reconstruction/functions/aa_0051d230_CNDHash_Recreate.md`
- `docs/reconstruction/functions/aa_0051e4d0_CNDHash_Insert_009ce0a8.md`
- `docs/reconstruction/functions/aa_00604e10_MedalDef_ZeroOwnedStrings_Inferred.md`
- `docs/reconstruction/functions/aa_00605090_MedalDef_InitFromAchievementRow_Inferred.md`
- `docs/reconstruction/functions/aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md`

### Other

- Legacy `functions/aa_*_FUN_*.md` pointer notes
- Raw live dual appends on each `raw/aa_*_FUN_*.md`
- Scratch `tmp/a_0051d230.md` … `a_007cea40.md`
- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Prior `A_aa_*` for any of 5 VAs | **None existed** — all dualled |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Full bit-exact clean of `FUN_007cea40` (SEH/COM) | Structural dual only |
| Dual of parent `FUN_00519660` | Out of batch VA list (referenced only) |
| Ghidra rename/plate apply | Docs-only dual |

---

## Sealed one-liners

1. **`0051d230`**: `CNDHash_Recreate(this, log2)` — clear + AllocBuckets; parent bits=4 on `DAT_00b042e0`; lock warn-only.
2. **`0051e4d0`**: Insert twin vtbl **`009ce0a8`**; freelist `this+0x20`; ret `0x0C`; medal table soft=0.
3. **`00604e10`**: Zero MedalDef string slots `+4..+0x10`; returns this (11 bytes).
4. **`00605090`**: Init def from row 0x3d4 — id + 4 ACP strings + 2 dwords; `ret 0x20`; stack arg4 unused.
5. **`007cea40`**: DbReader load `//tAchievement/row` → vector 0x3d4; ECX=`*[00b0469c]`; dual path `DAT_00d1793c`.

---

## AutoCore impact

- Closes dual gap on **medal definition table load** callees used by `MedalDef_LookupById` / CompleteObjective medal toast.
- No server packet ownership in these units (client DB/table + hash container).
- Pair with existing: `aa_0051a0e0` MedalDef_LookupById; CNDHash insert twins `0051e6d0` / `0053c560`.
