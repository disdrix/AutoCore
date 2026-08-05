# Wave 3 sample trio+A/B artifact check — 2026-07-29

| Field | Value |
|-------|-------|
| Purpose | Verify trio (functions + raw + clean) + dual A/B for sample wave-3 units |
| Method | `pathlib.Path` existence + `is_file()` under `docs/reconstruction/` |
| Date | 2026-07-29 |
| Units | 8 VAs from verification panel sample |
| Overall | **PASS** (8/8 units) |
| Scratch twin | `C:/Users/josh/AppData/Local/Temp/grok-goal-09ea1b2de129/implementer/wave3_sample_trio_check.md` |
| WORK_QUEUE | **Not touched** |

## 1. Criteria

| Artifact | Path pattern | Required? |
|----------|--------------|:---------:|
| Function record | `functions/aa_{va}_*.md` | **Yes** |
| Raw (non-annotated) | `raw/aa_{va}_*.md` excluding `*.annotated.md` | **Yes** |
| Annotated raw | `raw/aa_{va}_*.annotated.md` | Optional |
| Clean C++ | `reconstructed-exact/*{va}*.cpp` | **Yes** |
| Dual A | `reviews/A_aa_{va}_*.md` or `reviews/a_{va}.md` | **Yes** |
| Dual B | `reviews/B_aa_{va}_*.md` or `reviews/b_{va}.md` | **Yes** |

Unit **PASS** iff every required class has ≥1 existing file. Annotated present/absent does not change unit PASS/FAIL.

## 2. Summary table

| VA | Name | functions | raw | annotated | clean cpp | A dual | B dual | Unit |
|----|------|:---------:|:---:|:---------:|:---------:|:------:|:------:|:----:|
| `0x007fca10` | FUN_007fca10 (Flush invoker host) | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x00570840` | InventoryGrid_CanPlace | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x005714e0` | InventoryGrid_FindFreeForItem | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x0052b420` | CVOGCharacter_IsMissionTurnInReady | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x00941d50` | Client_UseInventoryItem_Inferred | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x00941fb0` | Client_SendChatOrMacro_Inferred | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x008ab8f0` | Client_MissionDialog_FlushPreparedResponse | Y | Y | Y | Y | Y | Y | **PASS** |
| `0x0093b7f0` | Client_CastBlockFeedback | Y | Y | Y | Y | Y | Y | **PASS** |

**Aggregate:** 8 PASS / 0 FAIL / 8 total → **PASS**

## 3. Per-unit detail (pathlib)

### `0x007fca10` — **PASS** — FUN_007fca10 (Flush invoker host)

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_007fca10_FUN_007fca10.md` | 4996 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.md` | 3969 |
| annotated | OK | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.annotated.md` | 5782 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_007fca10.cpp` | 3469 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_PollBoundActions_007fca10.cpp` | 3615 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_007fca10_FUN_007fca10.md` | 5068 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_007fca10_FUN_007fca10.md` | 4794 |

### `0x00570840` — **PASS** — InventoryGrid_CanPlace

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_00570840_FUN_00570840.md` | 1881 |
|  | OK | `docs/reconstruction/functions/aa_00570840_InventoryGrid_CanPlace.md` | 2832 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_00570840_FUN_00570840.md` | 3106 |
| annotated | OK | `docs/reconstruction/raw/aa_00570840_FUN_00570840.annotated.md` | 3897 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_00570840.cpp` | 3624 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryDropToGrid_00570840.cpp` | 3980 |
| A dual | OK | `docs/reconstruction/reviews/a_00570840.md` | 5957 |
|  | OK | `docs/reconstruction/reviews/A_aa_00570840_InventoryGrid_CanPlace.md` | 7528 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_00570840_InventoryGrid_CanPlace.md` | 7664 |

### `0x005714e0` — **PASS** — InventoryGrid_FindFreeForItem

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_005714e0_FUN_005714e0.md` | 475 |
|  | OK | `docs/reconstruction/functions/aa_005714e0_InventoryGrid_FindFreeForItem.md` | 4030 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_005714e0_FUN_005714e0.md` | 2668 |
| annotated | OK | `docs/reconstruction/raw/aa_005714e0_FUN_005714e0.annotated.md` | 2406 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_005714e0.cpp` | 2791 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendInventoryUnequip_005714e0.cpp` | 3347 |
| A dual | OK | `docs/reconstruction/reviews/a_005714e0.md` | 6880 |
|  | OK | `docs/reconstruction/reviews/A_aa_005714e0_InventoryGrid_FindFreeForItem.md` | 4607 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_005714e0_InventoryGrid_FindFreeForItem.md` | 4427 |

### `0x0052b420` — **PASS** — CVOGCharacter_IsMissionTurnInReady

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` | 3239 |
|  | OK | `docs/reconstruction/functions/aa_0052b420_FUN_0052b420.md` | 1089 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_0052b420_FUN_0052b420.md` | 2251 |
| annotated | OK | `docs/reconstruction/raw/aa_0052b420_FUN_0052b420.annotated.md` | 3431 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_0052b420.cpp` | 2941 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052b420.cpp` | 3181 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` | 6059 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` | 5381 |

### `0x00941d50` — **PASS** — Client_UseInventoryItem_Inferred

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_00941d50_Client_UseInventoryItem_Inferred.md` | 2635 |
|  | OK | `docs/reconstruction/functions/aa_00941d50_FUN_00941d50.md` | 1303 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.md` | 3295 |
| annotated | OK | `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.annotated.md` | 3800 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_00941d50.cpp` | 4937 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_QuickBar_ActivateSlot_00941d50.cpp` | 5197 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_00941d50_Client_UseInventoryItem_Inferred.md` | 7735 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_00941d50_Client_UseInventoryItem_Inferred.md` | 5240 |

### `0x00941fb0` — **PASS** — Client_SendChatOrMacro_Inferred

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_00941fb0_Client_SendChatOrMacro_Inferred.md` | 3655 |
|  | OK | `docs/reconstruction/functions/aa_00941fb0_FUN_00941fb0.md` | 961 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.md` | 7629 |
| annotated | OK | `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.annotated.md` | 8009 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_00941fb0.cpp` | 8589 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_QuickBar_ActivateSlot_00941fb0.cpp` | 8954 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` | 8460 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` | 5637 |

### `0x008ab8f0` — **PASS** — Client_MissionDialog_FlushPreparedResponse

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` | 4748 |
|  | OK | `docs/reconstruction/functions/aa_008ab8f0_FUN_008ab8f0.md` | 1178 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` | 3217 |
|  | OK | `docs/reconstruction/raw/aa_008ab8f0_FUN_008ab8f0.md` | 2592 |
| annotated | OK | `docs/reconstruction/raw/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.annotated.md` | 1786 |
|  | OK | `docs/reconstruction/raw/aa_008ab8f0_FUN_008ab8f0.annotated.md` | 1981 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_008ab8f0.cpp` | 990 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` | 9167 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` | 7292 |

### `0x0093b7f0` — **PASS** — Client_CastBlockFeedback

| Class | Status | Paths (repo-relative) | size |
|-------|:------:|-----------------------|-----:|
| functions | OK | `docs/reconstruction/functions/aa_0093b7f0_Client_CastBlockFeedback.md` | 3021 |
|  | OK | `docs/reconstruction/functions/aa_0093b7f0_FUN_0093b7f0.md` | 1647 |
| raw (non-annotated) | OK | `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.md` | 7160 |
| annotated | OK | `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.annotated.md` | 8585 |
| clean cpp | OK | `docs/reconstruction/reconstructed-exact/FUN_0093b7f0.cpp` | 7980 |
|  | OK | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_CastSkillFromQuickBarSlot_0093b7f0.cpp` | 8217 |
| A dual | OK | `docs/reconstruction/reviews/A_aa_0093b7f0_Client_CastBlockFeedback.md` | 5544 |
| B dual | OK | `docs/reconstruction/reviews/B_aa_0093b7f0_Client_CastBlockFeedback.md` | 3798 |

## 4. Notes

- Multiple hits per class (e.g. FUN_ + Named_ clean, dual shell `a_{va}.md` + full `A_aa_*`) still count as present.
- Raw exclusion: any name containing `.annotated.` is counted under annotated only.
- This check is **artifact presence only** (not semantic dual quality).
- No WORK_QUEUE edits.

## 5. Verdict

All **8** sample wave-3 units have functions + raw + clean cpp + dual A + dual B. Annotated present on all 8 (optional). **PASS.**
