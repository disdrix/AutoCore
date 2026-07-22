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
**Commit:** *(see git log: test: harden mission-critical mutation resistance)*

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

### Remaining risks / next slice

1. **Next:** broader mission handlers — `stryker-mission-config.json` (NpcInteract, MissionKillProgress; expect Safe Mode CompileError on some methods).
2. Then inventory footprint (`stryker-inventory-footprint-config.json`) for economy/placement critical bar.
3. Residual near-equivalents above are cataloged; none silently ignored.
