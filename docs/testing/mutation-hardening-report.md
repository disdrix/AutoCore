# Mutation Hardening Report

Campaign to raise **mutation resistance** (not merely line coverage) across AutoCore critical paths. Follows `AGENTS.md` TDD, existing Stryker configs, and per-subsystem commits.

## Methodology

For each subsystem slice:

1. Confirm focused unit tests are green.
2. Baseline with the matching `stryker-*-config.json` at repo root.
3. Triage every Survived / NoCoverage mutant (missing assertion, boundary, state, error path, equivalent, tooling).
4. Add observable-behavior tests that kill survivors; change production only when a real gap is proven.
5. Re-run focused tests + Stryker; record metrics; commit the slice.

### Reproducible commands

```powershell
dotnet tool restore

# Focused unit suites
dotnet test src/AutoCore.Game.Tests/AutoCore.Game.Tests.csproj --filter "FullyQualifiedName~Mission"
dotnet test src/AutoCore.Game.Tests/AutoCore.Game.Tests.csproj --filter "FullyQualifiedName~InventoryFootprint|FullyQualifiedName~InventoryGridPlacement|FullyQualifiedName~InventoryManager"

# Mutation
dotnet tool run dotnet-stryker -- --config-file stryker-mission-critical-config.json
dotnet tool run dotnet-stryker -- --config-file stryker-mission-config.json
dotnet tool run dotnet-stryker -- --config-file stryker-inventory-footprint-config.json
dotnet tool run dotnet-stryker -- --config-file stryker-tacarc-config.json
dotnet tool run dotnet-stryker -- --config-file stryker-npc-drive-config.json
```

Reports land under `StrykerOutput/<timestamp>/reports/`.

### Config map

| Config | Production mutate globs | Score bar |
| ------ | ----------------------- | --------- |
| `stryker-mission-critical-config.json` | `MissionPersistence*`, `CharacterQuest` | ≥90% critical |
| `stryker-mission-config.json` | + kill progress, NpcInteract | ≥80% |
| `stryker-inventory-footprint-config.json` | footprint / grid placement | ≥90% if ownership/dupe risk |
| `stryker-tacarc-config.json` | combat tac-arc | ≥80% |
| `stryker-npc-drive-config.json` | NPC drive | ≥80% |

**Forbidden:** lowering `thresholds.break` / `low` / `high` to game the score; blanket mutate exclusions; ignore comments without equivalent-mutant proof in this report.

---

## Slice: mission-critical — **DONE**

**Subsystem:** `MissionPersistence`, `MissionPersistenceQueue`, `CharacterQuest`  
**Config:** `stryker-mission-critical-config.json`  
**Commit:** `d69259c2`

### Baseline → Final

| Metric | Baseline | Final |
| ------ | -------- | ----- |
| Mutation score | **69.33%** | **94.48%** |
| Killed / Survived / NoCoverage | ~113 / 35 / 15 | **154 / 8 / 1** |
| Focused Mission tests | 671 pass | **698 pass** |
| Report dir | `StrykerOutput/2026-07-21.22-29-36` | `StrykerOutput/2026-07-21.22-37-53` |

| File (final) | Killed | Survived | NoCoverage |
| ---- | ------ | -------- | ---------- |
| CharacterQuest.cs | 93 | 5 | 0 |
| MissionPersistence.cs | 48 | 3 | 0 |
| MissionPersistenceQueue.cs | 13 | 0 | 1 |

**Acceptance:** ≥90% critical ✅; no unproven survivors in auth/data-loss/duplication/ownership/packet-validation/state-transition paths ✅.

### Survivor triage (baseline → disposition)

#### CharacterQuest

| Mutant class | Disposition |
| ------------ | ----------- |
| Write OOB sequence / slot bounds / multi-pad / multi-lap / collect | **Killed** by new tests |
| Normalized slot filter / capacity non-wipe / max init loop | **Killed** |
| `maxSeq` `>` → `>=` | **Equivalent:** when equal, reassigns same value; capacity `Max(8, maxSeq+1)` unchanged |
| ResolveObjectiveMax `>` → `>=` on derived (use/kill/agg/collect) | **Equivalent:** max-fold from `derived=0` with non-negative counts; equal reassignment is a no-op |

#### MissionPersistence

| Mutant class | Disposition |
| ------------ | ----------- |
| AutoFlush default, constructor seams, MaybeFlush paths | **Killed** (fresh instance + ThreadPool wait tests) |
| DeleteActive upsert purge, re-chain under concurrent enqueue, fail no-spin | **Killed** |
| `Reset` Interlocked.Exchange (L116) | **Residual:** test-only flag clear; production lifecycle does not use Reset. Next: optional CAS assert after forced flag stuck state |
| `return` after failed CAS in ScheduleBackgroundFlush (L151) | **Near-equivalent / race:** removing return only double-schedules work items; flush remains correct. Next: count ThreadPool entries if score pressure returns |
| re-chain `PendingCount > 0` → `>= 0` (L167) | **Near-equivalent:** after success PendingCount is 0; triggers one empty extra flush then stops (`persisted==0`). Not data-loss. Next: instrument schedule count |
| Queue TryRemove fail `continue` | **NoCoverage / concurrency race** — only hit if key vanishes mid-flush; next: concurrent stress harness |

### Tests added (this slice)

**`CharacterQuestMutationHardeningTests`:** OOB active sequence; FirstStateSlot=4 (kill/use/multi-pad/collect); multi-pad absolute vs single-pad normalized; multi-lap absolute; zero-target multi-lap not multi-pad; collect absolute; normalized slot-1 only; capacity non-wipe; max default loop; ResolveObjectiveMax aggregate/collect/multi; negative progress clamp.

**`MissionPersistenceTests`:** fresh manager defaults AutoFlush=true + constructor seams; AutoFlush background change/complete/fail/remove; DeleteActive upsert purge keeps Complete; concurrent re-chain; failed persist does not spin; Reset clears background flag; pack edge ints.

### Remaining residuals (cataloged)

| Survivor | Proof / next action |
| -------- | ------------------- |
| maxSeq `>`→`>=`, ResolveObjectiveMax `>`→`>=` | Equivalent max-fold / equal reassignment |
| Reset Interlocked / CAS return / PendingCount `>=0` | Near-equivalent / test-only; optional schedule-count instrumentation |
| Queue TryRemove continue | Concurrency race NoCoverage |

---

## Slice: inventory footprint — **DONE**

**Subsystem:** `InventoryFootprintPolicy`, `InventoryGridPlacement`  
**Config:** `stryker-inventory-footprint-config.json`  
**Commit:** *(filled on commit)*

### Baseline → Final

| Metric | Baseline | Final |
| ------ | -------- | ----- |
| Mutation score | **89.90%** | **90.91%** |
| Killed / Survived / Timeout | 87 / 10 / 2 | **88 / 9 / 2** |
| Focused inventory filter tests | 57 pass | 57+ new placement tests pass |
| Report | `StrykerOutput/2026-07-21.22-44-49` | `StrykerOutput/2026-07-21.22-47-41` |

**Acceptance:** ≥90% for placement/ownership-adjacent critical path ✅. Footprint policy **100%** killed (15/15). No high-risk placement false-accept survivors uncataloged.

### Survivor triage (final)

| Mutant | Classification | Disposition |
| ------ | -------------- | ----------- |
| EnumerateCells `sizeX<1 \|\| sizeY<1` → `&&`; yield break removal | **Equivalent** | When either dim is 0, nested loops yield zero cells either way |
| CanPlace grid dim `\|\|` → `&&` (width/height) | **Equivalent** for observable place | Zero width still fails later bounds (`x+sizeX > 0`) for size≥1 |
| TryFindFirstFree compound `\|\|`→`&&` on size/grid | residual | Partial rewrites; invalid size still fails other clauses or CanPlace. Next: property over random invalid tuples if score pressure |
| maxY/maxX `height-size` → `height+size` | **Near-equivalent** | CanPlace rejects OOB y/x; wrong max only extends scan. Timeouts on `ty--`/`tx--` already kill infinite-loop direction |
| origin-occupied `continue` removal | **Equivalent** | Full CanPlace also fails when origin cell occupied |
| height bound `y+sizeY` (killed by new test) | missing assertion | **Killed** |

### Tests added

`InventoryGridPlacementTests`: height bound with lax pageHeight; width bound edges; zero width/height/page alone; TryFindFirstFree zero/oversized independent fails; Y-then-X scan after origin occupied; 3×3 subtraction max bounds.

---

## Slice: broader mission handlers — **IN PROGRESS / HANDOFF**

**Config:** `stryker-mission-config.json`  
**Baseline (2026-07-21.22-41-34):** score **60.64%**, 1314 mutants tested, K≈877 S≈436 N≈134.

| File | Score (approx) | Survived | Notes |
| ---- | -------------- | -------- | ----- |
| NpcInteractHandler.cs | ~56% | ~388 + 114 NC | Dominant mass; dialog delay, grant/complete multipaths |
| MissionKillProgress.cs | ~56% | ~40 + 19 NC | Safe Mode CompileError on `NotifyObjectKilled` body drops many mutants; unit helpers still mutable |
| CharacterQuest / MissionPersistence | ~94% | residual as critical slice | Already hardened |

### Next actions for another agent (broader mission)

1. Expand `MissionKillProgressUnitTests` for `IsKillOnlyObjective` / `HasNonKillRequirement` / `ResolveKillerCharacter` player-vehicle map walk (L138–210 survivors).
2. Targeted NpcInteract: soft-pedal delayMs bounds, null conn/character short-circuit, objectiveId≥0, dialog follow-up cancel/remove.
3. Do **not** lower break thresholds; prefer new focused mutate globs only if splitting NpcInteract into a dedicated config without ignoring survivors.
4. Re-run `stryker-mission-config.json` until ≥80% or catalog every residual with proof.

---

## Campaign status / next uncompleted subsystem

| Slice | Status | Score |
| ----- | ------ | ----- |
| Mission-critical | **Done** | 94.48% |
| Inventory footprint | **Done** | 90.91% |
| Broader mission | Handoff @ 60.64% | need ≥80% |
| Tac-arc / NPC drive / networking / auth / utils | Not started | use existing configs |

**Immediate next:** broader mission handlers (NpcInteract + KillProgress unit paths), then `stryker-tacarc-config.json` / `stryker-npc-drive-config.json`.
