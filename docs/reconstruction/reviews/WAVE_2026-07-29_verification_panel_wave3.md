# Verification panel package — wave 3 (2026-07-29)

| Field | Value |
|-------|-------|
| Purpose | Adversarial verification inputs for multi-agent reconstruction goal |
| Scratch twin | `{SCRATCH}/wave3_verification_panel.md` |

## 1. Multi-agent concurrency evidence

| Artifact | Path |
|----------|------|
| Wave 2 partition | `reviews/WAVE_2026-07-29_multiagent_partition_map.md` (~82 stable IDs) |
| Wave 3 partition | `reviews/WAVE_2026-07-29_wave3_partition_map.md` (~40 OWN-ONLY VAs) |
| CHANGE_LOG | Wave 2 merge + wave 3 launch/merge entries |
| ACTIVE_WORK | Wave 3 idle after merge |
| Naming scans | `WAVE_2026-07-29_naming_scan_wave2.md`, `…_wave3.md` (0 conflicts) |

**Observation:** Substantial waves used concurrent subagents with isolated VA ownership; parent merges ledgers only.

## 2. Sample wave-3 units — trio + dual A/B

| VA | Stable / name | raw | ann | clean | fn | A | B |
|----|---------------|:---:|:---:|:-----:|:--:|:-:|:-:|
| `0x007fca10` | `FUN_007fca10` Flush invoker | Y | Y | Y | Y | Y | Y |
| `0x00570840` | `InventoryGrid_CanPlace` | Y | Y | Y | Y | Y | Y |
| `0x005714e0` | `InventoryGrid_FindFreeForItem` | Y | Y | Y | Y | Y | Y |
| `0x0052b420` | `CVOGCharacter_IsMissionTurnInReady` | Y | Y | Y | Y | Y | Y |
| `0x00941d50` | `Client_UseInventoryItem_Inferred` | Y | Y | Y | Y | Y | Y |
| `0x00941fb0` | `Client_SendChatOrMacro_Inferred` | Y | Y | Y | Y | Y | Y |
| `0x008ab8f0` | FlushPreparedResponse (UF-011 residual) | Y | Y | Y | Y | Y | Y |
| `0x0093b7f0` | `Client_CastBlockFeedback` | Y | Y | Y | Y | Y | Y |

**Ghidra spot-check (parent):** decompile `0x007fca10` shows gates + `vtbl+0x3d8` then `vtbl+0x440` — matches dual A/B Flush invoker claim (UF-010).

## 3. Ledger honesty (do not equate stamps)

| Metric | Value | Meaning |
|--------|------:|---------|
| Ghidra functions | **26256** | Terminal universe |
| Inventory listed | **25664** | Export snapshot; gap **592** vs Ghidra |
| Inventory status | full+trivial-batch accounted on listed rows | `progress.json` `full_coverage` = **inventory accounted**, not dual-depth |
| Function records `aa_*.md` | **~17280+** | Industrial three-rep / stamp depth |
| Dual A/B unique | **586** (shell-verified) | Deep dual-reviewed (≪ 26256 ≈ **2.2%**) |
| Function records | **17291** | Industrial full-ish stamp depth ≠ dual |
| Clean cpp approx | **26167** | Many industrial emits |
| COVERAGE_LEDGER Full coverage | **false** | Criterion: every of 26256 is full/reviewed/trivial-batch with artifacts |
| Sample wave3 trio+A/B | **8/8 PASS** | `007fca10,00570840,005714e0,0052b420,00941d50,00941fb0,008ab8f0,0093b7f0` |

**Hard rule:** `progress.json` inventory stamp and function-record count are **not** objective-complete for “all functions decompiled to project standard.” Dual `reviewed` depth and full inventory of all 26256 are still open.

## 4. Experiment log

| Suite | Result | Capture |
|-------|--------|---------|
| Key unittest modules | **76 OK** | `{SCRATCH}/recon_experiments.txt` |
| Inventory collect bridge + wave3 structural | prior **22 OK** (CanPlace dual skip then land) | inventory scratch logs |

## 5. Terminal bar (restored)

Continue multi-agent waves until **every** Ghidra VA is one of:

- `reviewed` (full + dual A/B) for important units  
- `full` (three-rep + record)  
- `trivial-batch` (thunk/import/Unwind template with ledger entry)  
- `deferred-low` with **explicit reason**

Finite passes must leave durable advance + honest remaining gap; they must **not** re-narrow the terminal OBJECTIVE.
