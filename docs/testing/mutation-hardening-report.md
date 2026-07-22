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
**Commit:** `d30b217c`

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

## Slice: combat tac-arc — baseline ≥80% (full residual catalog)

**Config:** `stryker-tacarc-config.json`  
**Status:** **Acceptance-complete for ≥80% bar** (not further hardened this session).  
**Baseline:** **81.75%** (K=112 S=25 N=0), `StrykerOutput/2026-07-21.22-49-51`  
**Evidence:** `{SCRATCH}/mutation-campaign-final/slice-tacarc-stryker-baseline.json`  
**Tests green:** filter `TacArcGeometry|WeaponFireTarget|VehicleMapPropRam|VehicleWeaponCombatant`

| File | Killed | Survived | Score |
| ---- | ------ | -------- | ----- |
| TacArcGeometry.cs | 48 | 20 | 70.6% |
| WeaponFireTargetAcquisition.cs | 58 | 4 | 93.5% |
| WeaponFireTargetLimits.cs | 6 | 1 | 85.7% |

### Every residual mutant (25) — disposition

#### TacArcGeometry.cs (20)

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L31:26 | arithmetic on `(w*y)-(x*z)` | missing numeric/sign | **Next:** oracle with known yaw/quat → expected side vector; kill + vs − |
| L32:32 | arithmetic on `(y*y)-(x*x)` | missing numeric/sign | **Next:** same oracle; kill * vs / and − vs + |
| L46:18 | `target.X + shooter.X` (should be −) | missing delta sign | **High priority:** AimDelta must use subtraction; test target east of shooter → positive dx |
| L47:18 | `target.Z + shooter.Z` | missing delta sign | same as L46 |
| L49:13 | `lenSq <= 1e-8f` | float epsilon | Near-eq for continuous noise; **next:** exact (0,0) vs (1e-9) degenerate aim |
| L53:20 | `dx / inv` (normalize) | missing numeric | **Next:** unit-length assert after normalize |
| L59:22/32 | `ax/ax`, `az/az` self-div | missing numeric | **Next:** non-unit facing vector requires *inv*, not identity |
| L60:13 | `aLenSq <= 1e-8f` | float epsilon | degenerate facing; exact zero facing vs tiny |
| L62:13 | eps normalize gate (`Abs(aLenSq-1)` / negate / `</>` ) | float epsilon | near-eq for unit vectors already near 1; **next:** aLenSq=1.1 forces renormalize |
| L62:23 | `aLenSq + 1f` | missing numeric | **Next:** renormalize path with aLenSq≠1 |
| L64:24 | `1f * Sqrt` | missing numeric | **Next:** assert invA = 1/sqrt |
| L65–66 | `ax *= invA` → `/=` | missing numeric | **Next:** non-unit ax,az after scale |
| L76:13 | `rangeMin > 0` / `\|\|` rewrite | missing boundary | **Next:** rangeMin=0 must not reject; rangeMin=10 rejects dist=5 |
| L76:30 | `dist < rangeMin` → `<=` | missing boundary | **Next:** dist exactly rangeMin (in vs out) |
| L79:30 | `dist > rangeMax` → `>=` | missing boundary | **Next:** dist exactly rangeMax |

#### WeaponFireTargetAcquisition.cs (4) — combat-critical

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L101:13 | `result.Count >= maxTargets` → `>` | missing equality | **High priority:** when hard targets already fill maxTargets, soft fill must not run; test Count==max after hard |
| L127:13 | `taken.Add(c.Coid)` removed | missing side-effect | **High priority:** duplicate COID must not appear twice in result when soft re-sees candidate |
| L147:13 | `explosionRadius <= 0` → `<` | missing boundary | **Next:** explosionRadius==0 returns empty (not process candidates) |
| L159:17 | `distSq > r2` → `>=` | missing boundary | **Next:** candidate exactly on radius shell included vs excluded |

#### WeaponFireTargetLimits.cs (1)

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L20:19 | `sprayTargets==0 ? 1 : sprayTargets` always false branch | missing boundary | **Next:** flags=SprayModeBit, sprayTargets=0 → max=1 (not 0) |

**Priority order for next kill pass:** Acquisition L101/L127 (overcap / dupe hits) → Geometry delta sign L46–47 → Limits sprayTargets=0 → remaining FP/eps.

---

## Slice: NPC drive — baseline ≥80% (full residual catalog)

**Config:** `stryker-npc-drive-config.json`  
**Status:** **Acceptance-complete for ≥80% bar** (not further hardened this session).  
**Baseline:** **84.62%** (K=368 S=68+timeouts in report; 442 tested), `StrykerOutput/2026-07-21.22-51-05`  
**Evidence:** `{SCRATCH}/mutation-campaign-final/slice-npc-drive-stryker-baseline.json`  
**Files mutated:** PathCurvature, TerrainContactPlane, NpcVehicleDriveController, **VehicleGroundMetricsCache**

| File | Killed | Residuals (S+Timeout) | Score (K/(K+S+T) approx) |
| ---- | ------ | --------------------- | ------------------------ |
| NpcVehicleDriveController.cs | 129 | 29 | ~81.6% |
| PathCurvature.cs | 36 | 3 | 92.3% |
| TerrainContactPlane.cs | 148 | 35 | 80.9% |
| **VehicleGroundMetricsCache.cs** | 55 | **7** | 88.7% |

### Every residual mutant — disposition

#### NpcVehicleDriveController.cs (29)

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L86:43 | `desiredSpeed * 0.85` → `/` | missing numeric | **Next:** assert capped cruise = 0.85×desired (not /) |
| L112:9 | block removal | missing side-effect | **Next:** assert path state / speed update body runs |
| L123:54 | `fwd.Y * newSpeed` → `/` | missing numeric | vertical velocity component sign/magnitude oracle |
| L166:13 | `cbid <= 0` → `== 0` | missing boundary | **Next:** negative cbid rejected same as 0 |
| L171:13 | statement removal | missing side-effect | assert metrics cache lookup side effect |
| L184:13 | `n >= 3` → `>` | missing boundary | **Next:** path with exactly 3 points accepted |
| L202:19 | `aim.Z - position.Z` → `+` | missing sign | **High priority:** aim vector Z delta |
| L204:13–14 | lenSq arithmetic | missing numeric | aim length-squared oracle |
| L236:13 | `drift >= MaxPathDrift` → `<` | missing boundary | **Next:** drift exactly MaxPathDrift triggers repath |
| L236:38 | `drift > 1e-4` → `<=` | float epsilon | exact zero drift vs 1e-4 |
| L246:29 | `dz * pull` → `/` | missing numeric | lateral pull magnitude |
| L262:29 | `guard < n+2` → `<=` | missing boundary | loop bound: **Timeout** on OR rewrite / `guard--` already times out |
| L262:46 | `remaining > 0` → `>=` | missing boundary | remaining==0 must exit advance loop |
| L262:62 | `guard++` → `--` | loop direction | **Timeout** (treated as killed by timeout) |
| L266:22 | `pt.Z - cursor.Z` → `+` | missing sign | segment vector along path |
| L268:17 | `seg < 1e-3` → `<=` | float epsilon | zero-length segment skip |
| L274:17 | `seg <= remaining` → `>` | missing boundary | partial segment consume |
| L293:13 | laneOffset eps | float epsilon | exact zero lane offset |
| L293:46 | `path.Points.Count < 2` → `<=` | missing boundary | **Next:** exactly 2 points still builds lane |
| L299:20 | `idx > 0` → `< 0` / false ternary | missing boundary | first point has no prev; idx==0 uses point not Points[-1] |
| L300–301 | `next - prev` → `+` | missing sign | path tangent direction |
| L336–339 | angle wrap ±π | loop/normalize | **Timeout** on wrap invert; next: angle=π+ε wraps to −π range |

#### PathCurvature.cs (3)

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L31:13/27/41 | `ab/bc/ca < 1e-4` → `<=` | float epsilon | **Next:** collinear points with length exactly 1e-4 vs 0; return 0 curvature |

#### TerrainContactPlane.cs (35)

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L67:60 | `groundClearance >= 0` → `>` | missing boundary | clearance==0 accepted |
| L73:22 | `-Sin(yaw)` → `+Sin` | **sign (high)** | **Next:** yaw=π/2 right vector sign vs world +X |
| L92:18 | `halfWidth > 0` / `>=` flips | missing boundary | halfWidth==0 sample collapse |
| L97–101 | corner offsets `± fwd*hl ± right*hw` | missing numeric/sign | **Next:** known rectangle corners for yaw=0 |
| L197:* | hardpoint near-zero eps | float epsilon | zero HP skip vs tiny HP |
| L198/207 | statement removal | missing side-effect | HP accumulation / sample add |
| L205 | lateral offset arithmetic | missing numeric | hardpoint world XZ |
| L212/223 | `hp.Z/X > 0` | missing boundary | left/right bucket of hardpoints |
| L239–242 | `nF/nR/nL > 0` → `>=` + always-true avg | missing boundary | **Next:** empty side sample falls back to yC (n==0) |
| L244/246 | maxAbsZ/X thresholds | missing boundary | track width/length estimate gates |
| L272 | boolean flip | missing branch | plane validity flag |
| L278–279 | near-zero OR + statement | float / side-effect | skip invalid HP |
| L288 | statement | side-effect | normal normalize or store |
| L306 | `x * w` → `/` | missing numeric | scale |
| L344 | `fwdZ * fwdZ` → `/` | missing numeric | length-squared |

#### VehicleGroundMetricsCache.cs (7) — **was omitted earlier; now cataloged**

| Loc | Mutant | Class | Disposition / next action |
| --- | ------ | ----- | ------------------------- |
| L35:9 | `ByCbid.Clear()` removed in `Clear()` | **state / data integrity** | **High priority:** after `Build` then `Clear()`, `Count==0` and `TryGet` fails |
| L70:9 | `Logger.WriteLog(...)` removed | logging-only | **Equivalent for game behavior** if no log sink assert; next: optional log TestSink if required |
| L71–72 | log string `$""` emptied | string cosmetic | **Equivalent** for gameplay; log message only |
| L118:21/48/75 | `Abs(hp.*) < 1e-4` → `<=` | float epsilon | hardpoint all-near-zero skip; **next:** HP exactly (1e-4,0,0) counted vs skipped |

**Priority order for next kill pass:** VehicleGroundMetricsCache `Clear()` L35 → NpcVehicleDrive aim/path sign L202/L300 → TerrainContactPlane yaw sign L73 → empty-side nF==0 fallback L239 → PathCurvature eps.

---

## Campaign status / next uncompleted subsystem

| Slice | Status | Score | Notes |
| ----- | ------ | ----- | ----- |
| Mission-critical | **Done** | 94.48% (`d69259c2`) | Full triage; residuals equivalent/near-eq cataloged |
| Inventory footprint | **Done** | 90.91% (`d30b217c`) | Full triage |
| Tac-arc combat | **Done (≥80% bar)** | 81.75% | All 25 residuals cataloged above |
| NPC drive | **Done (≥80% bar)** | 84.62% | All residuals cataloged incl. **VehicleGroundMetricsCache** |
| Broader mission | **Incomplete** | 60.64% | **Primary next** — NpcInteract mass |
| Networking / auth / communicator / utils | **Not started** | — | No Stryker config run this session |

**Immediate next for another agent:** broader mission (`stryker-mission-config.json`) — NpcInteractHandler multipath + finish MissionKillProgress helpers. Then optionally raise tac-arc Acquisition L101/L127 and VehicleGroundMetricsCache Clear. Do not lower Stryker thresholds.
