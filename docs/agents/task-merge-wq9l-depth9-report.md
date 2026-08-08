# MERGE-WQ9L — WQ-009 depth-9 residual dual seal (parent)

| Field | Value |
|-------|-------|
| Agent | MERGE-WQ9L |
| Date | 2026-08-05 |
| Wave | WQ-009 depth-9 residual |
| Partition | `docs/reconstruction/reviews/WAVE_2026-08-05_wq009_depth9_partition_map.md` |
| Dual unique A∩B | **2408 → 2428** (+20) |
| Terminal | **false** |
| Runtime Confirmed | **none** |

## Scope

Parent lockstep only. All 20 VAs dual-sealed by OWN agents (WQ9L-A…J + D2/H2/F-RPT finish). No re-dual. No Launcher.

## Sealed units (20)

| VA | Canonical name | A verdict |
|----|----------------|-----------|
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | accept |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | accept-with-gaps |
| `0x00401bc0` | `Std_OutOfRange_CtorFromString` | accept |
| `0x00403e90` | `StdTree_Lrotate_Isnil31_Inferred` | accept-with-gaps |
| `0x00403ee0` | `StdTree_Rrotate_Isnil31_Inferred` | accept |
| `0x004043e0` | `StdTree_Max_Isnil31` | accept |
| `0x0076c4d0` | `RdtscTimer_StampAndArm_Inferred` | accept-with-gaps |
| `0x0078c3d0` | `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` | accept-with-gaps |
| `0x007a8580` | `CNDUIWindow_ClearOwnedObject_Inferred` | accept-with-gaps |
| `0x00424060` | `ObjectCsList_DestroyAll_Inferred` | accept |
| `0x00759de0` | `gfxUIWindow_CompleteDtor` | accept-with-gaps |
| `0x00797d70` | `UiTextLayout_CompleteDtor_Inferred` | accept-with-gaps |
| `0x007aec70` | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` | accept-with-gaps |
| `0x007aff00` | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` | accept-with-gaps |
| `0x0082ce20` | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | accept-with-gaps |
| `0x00415e90` | `StdList_Clear_ESI` | accept-with-gaps |
| `0x007917c0` | `CNDUIDialog_TeardownChildHash_Inferred` | accept-with-gaps |
| `0x0083a860` | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | accept-with-gaps |
| `0x0083a880` | `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` | accept-with-gaps |
| `0x0083abf0` | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` | accept-with-gaps |

Names verified from live `A_aa_*` / `B_aa_*` review filenames (20/20 pairs present).

## Ledger updates (parent)

1. `docs/reconstruction/VERIFICATION_MATRIX.md` — +20 function rows; skills status → depth-9; summary **324**
2. `docs/reconstruction/NAMING_REGISTRY.md` — depth-9 rename table + 20 rename-history lines
3. `docs/reconstruction/systems/skills-abilities.md` — depth-9 residual section (STL/UI helpers noted)
4. `docs/reconstruction/WORK_QUEUE.md` — dual count 2428; WQ-009 status through depth-9
5. `docs/reconstruction/RESUME.md` — dual 2428; next mega residual / runtime
6. `docs/reconstruction/CHANGE_LOG.md` — prepend depth-9 parent entry
7. `docs/reconstruction/COVERAGE_LEDGER.md` — dual **2428**
8. `docs/reconstruction/coverage/progress.json` — dual_ab_pairs / dual_depth 2428; date 2026-08-05
9. `docs/reconstruction/PROJECT_STATE.md` — last updated / active wave depth-9
10. `docs/reconstruction/ACTIVE_WORK.md` — depth-9 complete; ready for mega residual claim

## Notes

- Batch is residual-depth **STL / UI teardown / shop list helpers**, not product skill-cast English.
- Residual gaps remain product demangle / runtime / bit-exact on most accept-with-gaps units.
- Next: parent mega residual claim beyond depth-9, or runtime when Launcher approved.
