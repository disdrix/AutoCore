# Multi-agent partition map — wave 6 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start (wave5 end) | ~613 unique A |
| Rule | **One write owner per VA** — do not touch other agents' addresses |
| Parent | merges WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / UNRESOLVED / matrix only |

## Wave5 residual (must dual if still missing)

| VA | Focus | Owner |
|----|-------|-------|
| `0x00504c70` | throttle / setDrivingInputs | dual-w6-throttle |
| `0x00512870` | EnsureQuestBaseCreditsLoaded | dual-w5 (still running) — do not steal |
| `0x00571b80` | inventory occupancy sibling | dual-w6-occ |

## Domain duals (named / user-visible)

| VA | Focus | Owner |
|----|-------|-------|
| `0x00402210` | Map_LowerBoundFindByCharKey | dual-w6-maplb |
| `0x00423ac0` | NDResource_LoadByKey | dual-w6-ndres |
| `0x004a61b0` | NDSpecialFX_LoadFromScriptName | dual-w6-sfx |
| `0x005ffbd0` | TimedAction_CreateTokenFlagAction | dual-w6-timed |
| `0x00931870` | Inventory_WriteSwapDebugLog | dual-w6-swaplog |
| `0x00979730` | ClientSpecialEvent_Respawn_Update | dual-w6-respawn |
| `0x008f92e0` | UI_OnAttributePointClick_Inferred | dual-w6-attrpt |
| `0x008747e0` | CDlgArenaPrefs_CreateChildWidgets | dual-w6-arena |
| `0x008847f0` | CDlgTrade2d_CreateChildWidgets | dual-w6-trade |
| `0x008faaf0` | CDlgCharSheet2d_CreateChildWidgets | dual-w6-charsheet |
| `0x00792980` | NDUIWindow_ReloadInterface | dual-w6-uireload |
| `0x007b0ef0` | NDUIWindow_LoadInterfaceFile | dual-w6-uiload |
| `0x007b1ec0` | NDUIWindow_ApplyXmlNodeAttributes | dual-w6-uixml |
| `0x007b3710` | NDUIWindow_InitFromInterfaceXml | dual-w6-uiinit |
| `0x007999c0` | NDXml_OpenTaggedDocument | dual-w6-xmlopen |
| `0x007b6c70` | NDXml_LoadDocumentFromPath | dual-w6-xmlpath |
| `0x00436090` | stoChunkReader_readF32Array | dual-w6-f32 |
| `0x007673a0` | stoChunkWriter_EndChunk | dual-w6-endchk |
| `0x00767460` | stoChunkWriter_BeginChunk | dual-w6-begchk |
| `0x0076a2c0` | stoChunkReader_OpenChunk | dual-w6-openchk |
| `0x004332e0` | NDAssetImage_FlipVertical | dual-w6-flip |
| `0x004347d0` | NDAssetImage_LoadTGA | dual-w6-tga |
| `0x00745ee0` | NDResource_AcquireInnerObject | dual-w6-acquire |
| `0x0074ac40` | gfxGeometryPiece_Serialize | dual-w6-gfxser |
| `0x0074af60` | gfxGeometryPiece_Unserialize | dual-w6-gfxunser |
| `0x00996dc0` | vog_LogMessage | dual-w6-voglog |
| `0x0044af00` | Phy_CPConnection_AssertConnectionPoint | dual-w6-cpconn |
| `0x00467690` | Phy_BoundingVolumeFactory_InvalidTag | dual-w6-bvtag |
| `0x0096e280` | phyBone_unserialize | dual-w6-bone |
| `0x00970260` | effEffect_Unserialize | dual-w6-eff |

## High-priority callees / residual managers (decompile-first if unnamed)

| VA | Focus | Owner |
|----|-------|-------|
| `0x009223b0` | DriveControlTick residual deepen (dual exists — refresh only if gaps) | skip if dual present |
| `0x00571830` | Stack qty merge residual | dual-w6-stack if no dual |
| `0x0052d8b0` | Clear staging tree residual | dual-w6-stage if no dual |
| `0x008aa3f0` | Auto-select reward residual | dual-w6-reward if no dual |

## Meta / trivial-batch

| Role | Focus |
|------|-------|
| CRT/import trivial-batch | Body-prove remaining IAT pure JMPs (0x006a3dxx, 0x00717exx, etc.) → append `trivial_batch_imports.jsonl` only |
| thunk pure E9 | Body-prove additional pure JMP thunks → `trivial_batch_thunks.jsonl` |
| Ledger restamp | Parent only after duals land |

## Honesty

Terminal **false**. Dual ~613 / 25666. Inventory stamp ≠ dual depth. Do not claim complete.
