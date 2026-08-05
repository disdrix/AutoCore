# OWN-ONLY dual A/B batch report — Skill_DbLoadSkillsCharacters nested residual

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Seed:** `Skill_DbLoadSkillsCharacters` `0x007e34b0`  
**Rule:** Dual EACH listed nested residual with **no prior `A_aa_*`** (cap 6). MUST A+B.

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x004048e0` | `aa_004048e0` | `Cxx_ThrowException_Param_Inferred` | **accept-with-gaps** |
| `0x00419ca0` | `aa_00419ca0` | `Com_BstrHolder_CreateFromOleStr_Inferred` | **accept-with-gaps** |
| `0x00419ed0` | `aa_00419ed0` | `Com_CallVtbl90_OutIface_OptionalRelease_Inferred` | **accept-with-gaps** |
| `0x0041a3e0` | `aa_0041a3e0` | `Com_LoaderCtx_Teardown_Inferred` | **accept-with-gaps** |
| `0x0041a9b0` | `aa_0041a9b0` | `Com_Cursor_ClearSlotAndFetch_Inferred` | **accept-with-gaps** |
| `0x0041ac60` | `aa_0041ac60` | `Hash_CollectKeyMatchesToLockedList_Inferred` | **accept-with-gaps** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `batch_decompile`, `get_function_callees` / `callers`, `read_memory`. No `disassemble_bytes`. Program: `autoassault.exe`.

---

## Written

### Dual A/B (12 files)

- `docs/reconstruction/reviews/A_aa_004048e0_Cxx_ThrowException_Param_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004048e0_Cxx_ThrowException_Param_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00419ca0_Com_BstrHolder_CreateFromOleStr_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00419ca0_Com_BstrHolder_CreateFromOleStr_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00419ed0_Com_CallVtbl90_OutIface_OptionalRelease_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00419ed0_Com_CallVtbl90_OutIface_OptionalRelease_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0041a3e0_Com_LoaderCtx_Teardown_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041a3e0_Com_LoaderCtx_Teardown_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0041a9b0_Com_Cursor_ClearSlotAndFetch_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041a9b0_Com_Cursor_ClearSlotAndFetch_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0041ac60_Hash_CollectKeyMatchesToLockedList_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0041ac60_Hash_CollectKeyMatchesToLockedList_Inferred.md`

### Function records updated (6)

- `docs/reconstruction/functions/aa_004048e0_FUN_004048e0.md`
- `docs/reconstruction/functions/aa_00419ca0_FUN_00419ca0.md`
- `docs/reconstruction/functions/aa_00419ed0_FUN_00419ed0.md`
- `docs/reconstruction/functions/aa_0041a3e0_FUN_0041a3e0.md`
- `docs/reconstruction/functions/aa_0041a9b0_FUN_0041a9b0.md`
- `docs/reconstruction/functions/aa_0041ac60_FUN_0041ac60.md`

### Other

- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Seed `0x007e34b0` Skill_DbLoadSkillsCharacters | Already had `A_aa_*` + `B_aa_*` |
| Nested already dualled | `0041a810`, `004294f0`, `007d9440`, `007a4480`, … |
| Other missing nested under seed | Cap 6; priority was the six tasked VAs (all direct callees of seed) |
| `0041c000` / `0041c7e0` / `0041a8e0` / `00423170` / `00419e20` | Nested residuals still without A; beyond this 6-cap batch |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Ghidra rename/plate apply | Docs-only dual |

---

## Sealed one-liners

1. **`004048e0`**: non-return `_CxxThrowException(&param, &DAT_00acc3fc)` — BSTR/COM hard-fail funnel.
2. **`00419ca0`**: `new(0xC)` holder `{SysAllocString(EDI), 0, ref=1}` → `*out`; OOM `0x8007000E`.
3. **`00419ed0`**: `vtbl[+0x90](this=EDI, *arg?, &out)` + optional holder Release; not QI.
4. **`0041a3e0`**: ctx teardown — `00423170` → Release `*(ctx+0x24)` → `0041a8e0`.
5. **`0041a9b0`**: clear slot `EDI+0xC` (vtbl+0x18) → fetch (vtbl+0x1C) → bind `0041c000(0,1)`.
6. **`0041ac60`**: new CS list `0x2C` / vtbl `00a86168`; hash-bucket collect matches → `0041c7e0`.

---

## Nesting provenance

```
Skill_DbLoadSkillsCharacters 0x007e34b0   [already dualled]
  ├─ FUN_007d9440 Skill_DbLoadSkillElements   [already dualled]
  ├─ (DAT_00d1793c==0 DB branch)
  │    ├─ FUN_0041a810 …                     [already dualled]
  │    ├─ FUN_0041a9b0  ClearSlotAndFetch     ← dualled
  │    ├─ FUN_0041ac60  CollectKeyMatches     ← dualled
  │    ├─ FUN_0041c000  (field bind / next)   [still missing A]
  │    └─ FUN_0041a3e0  Teardown              ← dualled
  └─ (DAT_00d1793c!=0 WAD/XML branch)
       ├─ SysAllocString("//vSkillsCharacters/row")
       ├─ FUN_004048e0  throw on BSTR null    ← dualled
       ├─ FUN_00419ca0  BstrHolder create     ← dualled
       ├─ FUN_00419ed0  vtbl+0x90 open        ← dualled
       └─ FUN_0041a3e0  Teardown              ← dualled
```

---

## AutoCore impact

- Client skill **definition ingest** is COM/ADO/XML — server ports should load skill tables natively (no vtbl+0x90 / BSTR holders).
- Element attach path: hash collect → locked list → 0x14-byte element copy loop (parent-owned).
- Do not treat these six as mission/gameplay CF; they are shared COM infrastructure used by skill load.
