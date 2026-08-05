# OWN-ONLY dual A/B batch report - Skill_DbLoadSkillsCharacters nested

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Scope:** Dual EACH if no prior `A_aa_*` for eight VAs under parent ensure `0x007e34b0` Skill_DbLoadSkillsCharacters.

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x0041aef0` | `aa_0041aef0` | `SkillRowVec_EmplaceBack_Stride934_Inferred` | **accept-with-gaps** |
| `0x0041bf70` | `aa_0041bf70` | `AdoRowsetHolder_Teardown_Inferred` | **accept-with-gaps** |
| `0x0041c000` | `aa_0041c000` | `OleDb_RebindAccessor_Inferred` | **accept-with-gaps** |
| `0x00422de0` | `aa_00422de0` | `OleDb_ReleaseAccessorHandleArray_Inferred` | **accept-with-gaps** |
| `0x00423170` | `aa_00423170` | `OleDb_ReleaseAccessorHandle_Inferred` | **accept-with-gaps** |
| `0x004231d0` | `aa_004231d0` | `OleDb_CreateAccessorFromBindings_Inferred` | **accept-with-gaps** |
| `0x00423f40` | `aa_00423f40` | `CsSinglyLinkedList_TryNext_Inferred` | **accept-with-gaps** |
| `0x007b8910` | `aa_007b8910` | `Com_BstrPropertyEquals_Inferred` | **accept-with-gaps** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** HTTP `127.0.0.1:8089` -> `batch_decompile`, `read_memory`, callers/xrefs/callees. No `disassemble_bytes`. Program: `autoassault.exe`.

**Parent chain:** `Skill_DbLoadSkillsCharacters` (`aa_007e34b0`) ADO bulk-load `//vSkillsCharacters/row`  
uses nested vector emplace (`0041aef0`), list cursor (`00423f40`), BSTR compare (`007b8910`), and shared OLE DB accessor plumbing (`0041bf70` / `0041c000` / `00422de0` / `00423170` / `004231d0`).

**IID seal:** `DAT_00a860ac` -> `{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}` = **IID_IAccessor**.

---

## Written

### Dual A/B (16 files)

- `docs/reconstruction/reviews/A_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0041c000_OleDb_RebindAccessor_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041c000_OleDb_RebindAccessor_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md`
- `docs/reconstruction/reviews/A_aa_007b8910_Com_BstrPropertyEquals_Inferred.md`
- `docs/reconstruction/reviews/B_aa_007b8910_Com_BstrPropertyEquals_Inferred.md`

### Named function records (8)

- `docs/reconstruction/functions/aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md`
- `docs/reconstruction/functions/aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md`
- `docs/reconstruction/functions/aa_0041c000_OleDb_RebindAccessor_Inferred.md`
- `docs/reconstruction/functions/aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md`
- `docs/reconstruction/functions/aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md`
- `docs/reconstruction/functions/aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md`
- `docs/reconstruction/functions/aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md`
- `docs/reconstruction/functions/aa_007b8910_Com_BstrPropertyEquals_Inferred.md`

### Other

- Legacy `functions/aa_*_FUN_*.md` pointer notes
- Raw live dual appends on each `raw/aa_*_FUN_*.md`
- Scratch `tmp/a_0041aef0.md` … `a_007b8910.md`
- Live capture `tmp/batch_007e34b0_nested_live.json`
- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Prior `A_aa_*` for any of 8 VAs | **None existed** - all dualled |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Dual of parent `007e34b0` | Already has A_aa; referenced only |
| Nested callees `004220c0` / `0041c920` / `004232c0` / `004205e0` full dual | Out of batch VA list |
| Ghidra rename/plate apply | Docs-only dual |
| Bit-exact / image diff | Deferred |

---

## Sealed one-liners

1. **`0041aef0`**: `SkillRowVec_EmplaceBack_Stride934` - vector +4/+8/+0xc; stride **0x934**; sole parent 007e34b0.
2. **`0041bf70`**: `AdoRowsetHolder_Teardown` - unbind accessors, delete slab, Release ifaces; shared DbLoad cleanup.
3. **`0041c000`**: `OleDb_RebindAccessor` - ReleaseAccessor(+0x18) then rebind(+0x14) with flag->±1; rollback via 004205e0.
4. **`00422de0`**: `OleDb_ReleaseAccessorHandleArray` - QI **IID_IAccessor** `{0C733A8C-…4773D}`; ReleaseAccessor each; delete[].
5. **`00423170`**: `OleDb_ReleaseAccessorHandle` - single-handle ReleaseAccessor + owner Release; same IID.
6. **`004231d0`**: `OleDb_CreateAccessorFromBindings` - QI IAccessor; CreateAccessor vtbl+0x10; mark binding active.
7. **`00423f40`**: `CsSinglyLinkedList_TryNext` - TryEnter CS; 0/1/0x80070005; node+8 next, +4 payload; parent row walk.
8. **`007b8910`**: `Com_BstrPropertyEquals` - VarBstrCmp(…,0x400,0)==1; free rhs BSTR; E_POINTER on null obj.

---

## AutoCore impact

- Closes dual gap on **skill character table load** nested helpers + shared **OLE DB IAccessor** release/create plumbing used by many DbLoad paths.
- Port note: server does not need client ADO/XML vector machinery; use sealed row fields from parent `Skill_DbLoadSkillsCharacters` when porting skill defs.
- Pair with existing: `aa_007e34b0` Skill_DbLoadSkillsCharacters; child `aa_007d9440` Skill_DbLoadSkillElements.
