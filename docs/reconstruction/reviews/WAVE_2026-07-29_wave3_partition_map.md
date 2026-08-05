# Multi-agent partition map — wave 3 (2026-07-29)

| Field | Value |
|-------|-------|
| Wave | wave 3 — high-priority callees missing dual A/B + UF-011 flush residual |
| Rule | **One write owner per VA**. Parent merges ledgers only. |
| Scratch | `{SCRATCH}/wave3_partition.md` mirror optional |

## Flush / modal chain (UF-010/011)

| VA | Stable ID | Focus |
|----|-----------|-------|
| `0x007fca10` | `aa_007fca10` | Flush invoker host (vtbl+0x440 call) |
| `0x008aec40` | `aa_008aec40` | Dialog list/response → close → flush path |
| `0x008af020` | `aa_008af020` | Sibling close path if present |
| `0x008ab8f0` | `aa_008ab8f0` | UF-011 residual only: cancel-close +0x650 clear? |

## Missions helpers

| VA | Focus |
|----|-------|
| `0x0052b420` | Turn-in ready predicate |
| `0x0052dac0` | Reward region helper |
| `0x0052a020` | Objective readiness |
| `0x0052c700` | Mission staging map store |
| `0x0053fff0` | Mission table lazy getter |
| `0x0059d880` | CompleteCount load |
| `0x00637de0` | Progress toast shared Action |
| `0x0092ce90` | Mission UI refresh |
| `0x00613b50` | Kill_Precheck residual deepen |

## Skills helpers

| VA | Focus |
|----|-------|
| `0x0093b7f0` | Cast-block feedback |
| `0x0093bac0` | PromptSkillTargetSelect |
| `0x00514e00` | DecActiveCast residual |
| `0x00514e20` | Sibling cast clear |
| `0x00553240` | Accuracy helper |
| `0x0058ab60` | Seed/table clone |
| `0x0051c150` | Map find for cast binding |
| `0x004bae70` | ResolveObjectTarget residual if dual thin |

## Inventory helpers

| VA | Focus |
|----|-------|
| `0x005714e0` | Inventory space / FindFree wrapper |
| `0x00570840` | CanPlace footprint |
| `0x00571b60` | Occupancy check before place |
| `0x005710c0` | Cargo find-by-COID |
| `0x0085f220` | Drop hit-test |
| `0x0085f1d0` | pageH helper |

## Input / vehicle helpers

| VA | Focus |
|----|-------|
| `0x004c4e20` | Max-speed base for PushDriveAxes |
| `0x004fbec0` | SetDriveAxes residual deepen |
| `0x00922270` | TryFirePrimaryWeapons_Inferred |

## QuickBar / chat

| VA | Focus |
|----|-------|
| `0x008a0ed0` | QuickBar SelectPage |
| `0x00941d50` | UseInventoryItem C2S 0x2045 |
| `0x00941fb0` | SendChatOrMacro 0x2021 |

## Meta

| Role | Focus |
|------|-------|
| Experiments | recon suite → scratch |
| Naming scan | conflict check wave3 |
| Coverage ledger note | deep dual count honesty |
