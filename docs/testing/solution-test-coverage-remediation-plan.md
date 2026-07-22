# Solution-Wide Test Coverage Remediation Plan

**Status:** handoff-ready backlog (documentation only)  
**Date:** 2026-07-21  
**Owner:** next implementers following work streams below  
**Gate:** ≥80% line coverage **per** first-party `AutoCore.*` production assembly; ≥90% executed-test pass rate (target: zero failures)

This document is the single backlog for bringing first-party AutoCore production assemblies to the coverage gate. It is grounded in Cobertura artifacts collected 2026-07-21 under `TestResults/coverage-audit-*` and the solution test run recorded the same day. **No production code, test code, or coverage scripts are modified by this document** — implementers execute the work streams as separate commits.

---

## 1. Summary

| Assembly | Baseline line % | Test project today | Gap to 80% |
|----------|----------------:|--------------------|------------|
| AutoCore.Game | **75.57%** | `AutoCore.Game.Tests` | ~4.4 pp; 134 files <80% (74 at 0%) |
| AutoCore.Utils | **19.93%** | `AutoCore.Utils.Tests` (thin) | ~60 pp; almost all production files under-tested |
| AutoCore.Database | **47.32%** | covered only via Game.Tests | ~33 pp; contexts + many models cold |
| AutoCore.Sector | **10.62%** | `AutoCore.Sector.Tests` (ticks only) | ~69 pp; server/dev/host cold |
| AutoCore.Communicator | **0%** | **none** | full assembly |
| AutoCore.Auth | **n/a (0%)** | **none** | full assembly |
| AutoCore.Global | **n/a (0%)** | **none** | full assembly |
| AutoCore.Launcher | **n/a (0%)** | **none** | full assembly |
| TNL.NET (`lib/`) | **29.57%** (observed) | incidental via Game | **tracked dependency risk only** — not in first-party 80% gate |

**Suite health (2026-07-21):** 3,122 passed / 1 failed / 4 skipped / 3,127 total. Pass rate of executed tests = `3122/(3122+1) ≈ 99.97%` (≥90%), but the suite is **not green**.

**Non-negotiables for every work stream**

1. **TDD:** write/adjust a failing test first; confirm failure reason; minimal production or fixture change; re-run until green.
2. **One coherent subsystem per commit** (failing tests → seams → pass → coverage snapshot update in this file).
3. **No live Launcher / Auth / Global / Sector process** for this effort; use injected seams and test doubles.
4. After each stream: full `dotnet test src/AutoCore.sln` + refresh coverage summary + update §11 Progress log.

---

## 2. Baseline (2026-07-21)

### 2.1 Suite run

Command:

```text
dotnet test src/AutoCore.sln --no-restore
```

| Metric | Value |
|--------|------:|
| Passed | 3,122 |
| Failed | 1 |
| Skipped | 4 |
| Total | 3,127 |
| Executed pass rate `Passed/(Passed+Failed)` | ≈99.97% (≥90%) |
| Suite green? | **No** |

**Failed test**

| Item | Detail |
|------|--------|
| Fully qualified name | `DeathLootDeliveryTests.AutoLootItem_AddsCargoWithCreateAddResponseCargoSendAll` |
| Location | `src/AutoCore.Game.Tests/Managers/DeathLootDeliveryTests.cs` |
| Root cause (baseline) | Fixture lacks **nonzero inventory footprint** data for the registered clone base / item, so auto-loot cargo path does not complete the Create + AddResponse + CargoSendAll assertions as written. |

**Skipped tests:** 4 skipped at baseline. Catalog and justify before adding any new skips (see Work stream 1 health gate).

### 2.2 Coverage evidence sources

| Artifact | Role |
|----------|------|
| `TestResults/coverage-audit-game/.../coverage.cobertura.xml` | Game **75.57%**, Database **47.32%**, Communicator **0%**, TNL.NET **29.57%** (package rates) |
| `TestResults/coverage-audit-utils/.../coverage.cobertura.xml` | Utils **19.93%** package rate |
| `TestResults/coverage-audit-sector/.../coverage.cobertura.xml` | Sector package rate in this artifact (~6–7% de-duped file aggregation); **objective baseline for Sector is 10.62%** (use that as the recorded gate baseline; file inventory still from this audit) |
| Source trees for Auth / Global / Launcher | No Cobertura packages; inventory is **0% by absence of test projects** |

Per-file executable line counts below are **de-duplicated by source file** (partial classes merged by line number, max hits). Package `line-rate` attributes are the official assembly baseline numbers above.

### 2.3 Solution test projects (current)

| Production | Test project |
|------------|--------------|
| AutoCore.Game | AutoCore.Game.Tests |
| AutoCore.Utils | AutoCore.Utils.Tests |
| AutoCore.Sector | AutoCore.Sector.Tests |
| AutoCore.Database | *(none — covered incidentally)* |
| AutoCore.Communicator | *(none)* |
| AutoCore.Auth | *(none)* |
| AutoCore.Global | *(none)* |
| AutoCore.Launcher | *(none)* |
| TNL.NET | *(none dedicated)* |

---

## 3. Coverage scope and gates

### 3.1 In scope (first-party 80% gate)

All production code under:

- `src/AutoCore.Game`
- `src/AutoCore.Utils`
- `src/AutoCore.Database`
- `src/AutoCore.Sector`
- `src/AutoCore.Communicator`
- `src/AutoCore.Auth`
- `src/AutoCore.Global`
- `src/AutoCore.Launcher`

**Exclude from the first-party gate (still track where noted):**

| Exclusion | Reason |
|-----------|--------|
| `src/**/bin/**`, `src/**/obj/**` | Build outputs |
| `*.Tests` projects | Test code is not production coverage subject |
| Designer/generated-only stubs with zero executable lines | No behavior to cover |
| Pure JSON/YAML/config **content** files (not C# loaders) | Configuration-only; loaders **are** in scope |

### 3.2 Per-assembly gate (not aggregate)

The **80% line coverage requirement applies to each first-party assembly independently**. High Game coverage must not mask 0% Communicator or missing host tests.

**Branch coverage** is reported for diagnostics but is **not** the hard gate in this plan (line coverage is).

### 3.3 Dependency: TNL.NET

| Item | Policy |
|------|--------|
| Path | `lib/TNL.NET` (solution project `TNL.NET`) |
| Observed line coverage | **29.57%** (via Game.Tests audit) |
| Gate | **Outside** first-party 80% threshold |
| Reporting | Separate optional Work stream 5; do **not** hide risk with silent exclusions |
| Enforcement change | Only if ownership of the submodule is explicitly expanded |

### 3.4 Test health gate

| Rule | Threshold |
|------|-----------|
| Executed pass rate | `Passed / (Passed + Failed) >= 0.90` |
| Target end state | **Zero failures** |
| Skipped tests | Reported **separately**; new skips require an explicit tracked rationale in this document (or linked issue) |
| Full suite | Run `dotnet test src/AutoCore.sln` after every work stream |

---

## 4. Deliberate infrastructure exclusions

These seams are **hard to unit-test without flakiness or shared ports**. They are **not** free passes to ignore behavior: each has a required alternative. Mark excluded lines in coverlet runsettings only when the alternative suite exists.

| Area | Files / APIs (examples) | Reason for exclusion from unit gate | Required alternative |
|------|-------------------------|-------------------------------------|----------------------|
| Process host entry | `AutoCore.Launcher/Program.cs` live `Main` process start; `ExitableProgram` process-exit paths | Starts multi-server host; binds shared ports; kills process | Extract config validation + ordered init into pure methods; contract tests on extracted methods; optional one-shot smoke **outside** default CI with explicit approval |
| Shared live servers | Auth TCP 2106/2107, Global UDP 26880, Sector UDP 27001 | Port/DB conflicts across worktrees | Never start Launcher for coverage work; use fakes |
| Raw TCP accept/bind | `AuthServer.Socketing`, `AuthClient.Socketing`, `AsyncLengthedSocket` OS socket I/O | Non-deterministic, needs free ports | Length-prefix framing contract tests via `MemoryStream` / test double implementing the same read/write protocol |
| UDP / TNL bind | `TNLInterface` real bind, `TNLSocket`, `NetInterface` listen | OS UDP + game traffic | Constructor/config unit tests without bind; BitStream pack tests; loopback integration only if isolated ephemeral ports and not default CI |
| EF provider to shared MySQL | `AuthContext`/`CharContext`/`WorldContext` against real shared DBs | Mutates shared state | EF InMemory or isolated local DB; `OnModelCreating` snapshot tests; repository-style tests with substitutes where behavior is equivalent |
| HttpListener production bind (Dev) | `DevControlServer` default port | Port conflicts | Extract request handlers; test with ephemeral port **or** pure handler methods |
| Crypto OS RNG pure entropy | any `RandomNumberGenerator` fill | Non-deterministic | Inject RNG or test with fixed seed wrappers where security allows |

**Rule:** If a file is listed in §5 inventory as needing coverage **and** appears here, implementers cover the **non-I/O logic** and document the residual I/O exclusion in the Progress log with the alternative test name.

---

## 5. File-level inventory (below 80% / uncovered)

**How to read columns**

| Column | Meaning |
|--------|---------|
| Exec lines | De-duplicated executable lines from Cobertura (or approx source lines for hosts without coverage) |
| % | Line coverage for that file |
| Priority | P0 = high impact cold path; P1 = important; P2 = medium; P3 = residual to 80% |
| Proposed test seam | How to test without live servers |
| Acceptance scenarios | Minimum behavior matrix for that file/group |

### 5.1 AutoCore.Game — 75.57% overall; 134 files below 80%

Evidence: `coverage-audit-game` (24,846 / 32,877 lines covered at package level).  
249 files already ≥80%; **74 fully uncovered (0%)**; 60 partial (<80%).

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| Managers/LoginManager.cs | 105 | 0 | P0 | ExpectLoginToGlobal/LoginToGlobal with fake TNLConnection + timer advance | expect login; successful global login; auth key mismatch; expire timeout; sector login success/fail |
| EntityTemplates/OutpostTemplate.cs | 68 | 0 | P0 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/TNLConnection.Global.cs | 63 | 0 | P0 | Extract handler methods; TNLConnection.TestPacketSink + fake client | global login packet handlers; disconnect; mail/clan stubs if present |
| Packets/Login/LoginNewCharacterPacket.cs | 52 | 0 | P0 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| TNL/TNLInterface.cs | 47 | 0 | P0 | Constructor/config seams; avoid real UDP bind in unit tests | version fields; allow mismatch flag; construct without bind when possible |
| Structures/RoadNode.cs | 39 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/TNLConnection.Login.cs | 34 | 0 | P1 | Extract handler methods; TNLConnection.TestPacketSink + fake client | login request/response paths; new/delete character handlers |
| Structures/Music.cs | 31 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Mail/AuctionListResponsePacket.cs | 26 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/ChatPacket.cs | 25 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/BroadcastPacket.cs | 25 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/MissionDialogPacket.cs | 25 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/ClanUpdatePacket.cs | 25 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionListRequestPacket.cs | 21 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/GetEnemiesResponsePacket.cs | 21 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailListResponsePacket.cs | 21 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/VisualWaypoint.cs | 21 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Global/NewsPacket.cs | 20 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/GetFriendsResponsePacket.cs | 18 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/TransferFromGlobalStage3Packet.cs | 18 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/VehicleMovedPacket.cs | 17 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/MapTransferRequestPacket.cs | 15 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailCreateRequestPacket.cs | 14 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/Auction/AuctionItemCriteria.cs | 14 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Mail/MailNotificationPacket.cs | 14 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionCreateRequestPacket.cs | 13 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Login/LoginRequestPacket.cs | 12 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Skills/CharacterSkillPersistence.cs | 12 | 0 | P1 | Persistence boundary fakes + skill apply unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/ClanManager.cs | 12 | 0 | P1 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/ChangeCombatModeResponsePacket.cs | 11 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/TransferToSectorPacket.cs | 11 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/TransferFromGlobalPacket.cs | 11 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/Social/Enemy.cs | 10 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Global/RequestClanNameResponsePacket.cs | 10 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/MailPacket.cs | 10 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/MailPacket.cs | 10 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionCancelResponsePacket.cs | 9 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/ChangeCombatModeRequestPacket.cs | 9 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionBidResponsePacket.cs | 9 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Weather/WeatherInfo.cs | 9 | 0 | P3 | WeatherInfo value/container unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Login/LoginNewCharacterResponsePacket.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/Auction/AuctionListItem.cs | 8 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Structures/Mail/MailListItem.cs | 8 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Global/LoginPacket.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailDeleteRequestPacket.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionBidRequestPacket.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailContentCollectRequestPacket.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailDeleteResponsePacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/ItemPickupPacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/Social/Friend.cs | 7 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Mail/MailContentCollectResponsePacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/AuctionCreateResponsePacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Inventory/PendingCargoDrag.cs | 7 | 0 | P3 | Character inventory fixtures + TestPacketSink | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Global/EventStatusPacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/DisconnectPacket.cs | 6 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/RequestClanNamePacket.cs | 6 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/LoginAckPacket.cs | 6 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Login/LoginDeleteCharacterPacket.cs | 6 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailCreateResponsePacket.cs | 5 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Inventory/InventoryGrabDebugLog.cs | 5 | 0 | P3 | Character inventory fixtures + TestPacketSink | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Mail/AuctionCancelRequestPacket.cs | 5 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Login/LoginResponsePacket.cs | 4 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Global/ClanUpdateResponsePacket.cs | 4 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Sector/OutpostTokenChancePacket.cs | 3 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/Reward.cs | 3 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Weather/WeatherContainer.cs | 3 | 0 | P3 | WeatherInfo value/container unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Global/DisconnectAckPacket.cs | 3 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/Mail/MailListRequestPacket.cs | 3 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| EntityTemplates/QuestObjectTemplate.cs | 3 | 0 | P3 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/ConvoyManager.cs | 2 | 0 | P3 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/BasePacket.cs | 2 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/SeaPlane.cs | 2 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Mail/BaseMailPacket.cs | 2 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/TimeCurve.cs | 2 | 0 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/ChatManager.cs | 583 | 1.03 | P0 | Command dispatch table tests with fake connection | known command succeeds; unknown command rejected; permission/guard paths; null connection safe |
| Managers/CharacterSelectionManager.cs | 266 | 1.88 | P0 | DB-isolated CharContext + packet sink | list characters; create/delete guards; invalid account; packet emissions |
| Managers/Asset/MapDataLoader.cs | 45 | 2.22 | P1 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| Managers/Asset/GLMLoader.cs | 144 | 4.17 | P0 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| Managers/Asset/WorldDBLoader.cs | 120 | 8.33 | P0 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| Entities/WheelSet.cs | 31 | 9.68 | P1 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/Ghost/GhostCharacter.cs | 95 | 11.58 | P0 | Ghost pack/unpack with BitStream fixture; no live connection | pack mask bits; unpack into entity; null/zero ghost id; max object count edge |
| Map/MapData.cs | 225 | 12 | P0 | In-memory SectorMap / MapData builders | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/TNLConnection.Sector.cs | 594 | 12.63 | P0 | Extract handler methods; TNLConnection.TestPacketSink + fake client | sector transfer stages; inventory/combat handlers already partially covered—fill gaps |
| Inventory/InventoryPersistence.cs | 182 | 13.74 | P0 | Character inventory fixtures + TestPacketSink | save/load round-trip; empty inventory; capacity edges |
| EntityTemplates/ReactionTemplate.cs | 128 | 14.06 | P0 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/CreatureMovedPacket.cs | 6 | 16.67 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| EntityTemplates/ObjectTemplate.cs | 45 | 17.78 | P1 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| EntityTemplates/StoreTemplate.cs | 43 | 20.93 | P1 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/CreateVehicleExtendedPacket.cs | 14 | 21.43 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| EntityTemplates/MapPathTemplate.cs | 27 | 22.22 | P2 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/CreateArmorPacket.cs | 17 | 23.53 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| TNL/Ghost/GhostCreature.cs | 84 | 26.19 | P1 | Ghost pack/unpack with BitStream fixture; no live connection | pack mask bits; unpack into entity; null/zero ghost id; max object count edge |
| Packets/Sector/LogicStateChangePacket.cs | 37 | 27.03 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| EntityTemplates/SpawnPointTemplate.cs | 94 | 34.04 | P1 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/Ghost/GhostObject.cs | 189 | 34.39 | P1 | Ghost pack/unpack with BitStream fixture; no live connection | pack mask bits; unpack into entity; null/zero ghost id; max object count edge |
| Entities/Armor.cs | 23 | 34.78 | P2 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/ObjectMovedPacket.cs | 20 | 35 | P2 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Managers/AssetManager.cs | 532 | 35.15 | P1 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| EntityTemplates/TriggerTemplate.cs | 58 | 36.21 | P1 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/MapManager.cs | 177 | 37.85 | P1 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| EntityTemplates/GraphicsObjectTemplate.cs | 47 | 38.3 | P1 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| EntityTemplates/EnterPointTemplate.cs | 13 | 38.46 | P3 | Template property load from fixture XML/object graph | happy path; invalid input; boundary sizes; error/cancel path |
| CloneBases/Specifics/ArmorSpecific.cs | 21 | 42.86 | P2 | Specifics deserialize / property matrix | happy path; invalid input; boundary sizes; error/cancel path |
| TNL/TNLConnection.cs | 743 | 46.3 | P2 | Extract handler methods; TNLConnection.TestPacketSink + fake client | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/CreateWeaponPacket.cs | 41 | 46.34 | P2 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Diagnostics/LootTuning.cs | 112 | 49.11 | P2 | Config ApplyFrom* with temp JSON/YAML files | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/Asset/WadXmlWorldDataLoader.cs | 389 | 51.16 | P2 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| Structures/Vector4.cs | 25 | 52 | P2 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/StoreTransactionRequestPacket.cs | 49 | 53.06 | P2 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Entities/Character.Missions.cs | 49 | 53.06 | P2 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Diagnostics/LogFilters.cs | 274 | 53.28 | P2 | Config ApplyFrom* with temp JSON/YAML files | happy path; invalid input; boundary sizes; error/cancel path |
| Structures/DamageSpecific.cs | 13 | 53.85 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/InteractTriggerService.cs | 149 | 59.73 | P2 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/CreateCharacterPacket.cs | 93 | 60.22 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Entities/Character.cs | 388 | 61.34 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/MapInfoPacket.cs | 82 | 62.2 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Structures/TFID.cs | 44 | 63.64 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Managers/LootManager.cs | 761 | 63.86 | P3 | Singleton reset + collaborator fakes (existing test helpers) | existing loot tests; fill remaining roll branches and empty table paths |
| Managers/Asset/TgaAreaMaskReader.cs | 75 | 65.33 | P3 | Inject test game path / SetTest* helpers; skip full WAD disk when possible | missing path fails soft; minimal fixture loads; AllowMissingCBID; corrupt header rejected |
| Managers/ObjectManager.cs | 63 | 68.25 | P3 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/Sector/AttributeIncrementPacket.cs | 10 | 70 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Combat/CombatDebugLog.cs | 49 | 71.43 | P3 | Pure calculator unit tests (existing pattern) | happy path; invalid input; boundary sizes; error/cancel path |
| Npc/NpcTicker.cs | 167 | 72.46 | P3 | NpcTicker with fake map/entity set + clock | happy path; invalid input; boundary sizes; error/cancel path |
| Diagnostics/SectorLoopControl.cs | 11 | 72.73 | P3 | Config ApplyFrom* with temp JSON/YAML files | happy path; invalid input; boundary sizes; error/cancel path |
| Structures/RGB.cs | 11 | 72.73 | P3 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Physics/Vehicle/CompositeVehicleCollisionQuery.cs | 215 | 73.49 | P3 | Deterministic step fixtures | happy path; invalid input; boundary sizes; error/cancel path |
| Diagnostics/ServerConfig.cs | 168 | 75 | P3 | Config ApplyFrom* with temp JSON/YAML files | happy path; invalid input; boundary sizes; error/cancel path |
| Entities/Character.Exploration.cs | 88 | 75 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Extensions/BinaryReaderExtensions.cs | 12 | 75 | P3 | BinaryReader/Writer MemoryStream extension matrix | lengthed string; edge lengths; EOF; multi-byte values |
| Entities/Reaction.cs | 913 | 77.55 | P3 | Entity constructors + attribute/pool unit tests | mission reaction types matrix; unknown type no-op; null target safe |
| Managers/MissionCollectProgress.cs | 238 | 78.57 | P3 | Singleton reset + collaborator fakes (existing test helpers) | happy path; invalid input; boundary sizes; error/cancel path |
| Entities/Weapon.cs | 43 | 79.07 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| Map/MapTerrainHeightfield.cs | 96 | 79.17 | P3 | In-memory SectorMap / MapData builders | happy path; invalid input; boundary sizes; error/cancel path |
| Map/SectorMap.cs | 1213 | 79.88 | P3 | In-memory SectorMap / MapData builders | add/remove entity; interest; teardown; tick spawn; concurrent map ops if applicable |

### 5.2 AutoCore.Database — 47.32% overall; 18 files below 80%

Evidence: `coverage-audit-game` package `AutoCore.Database` (291 / 615 lines).

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| World/WorldContext.cs | 25 | 0 | P1 | EF InMemory or SQLite substitute; OnModelCreating assertions | model config; EnsureCreated on isolated DB; connection string init once |
| World/Models/ConfigNewCharacter.cs | 14 | 0 | P1 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/Clan.cs | 14 | 0 | P1 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/CharacterSocial.cs | 11 | 0 | P1 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/CharacterInventoryData.cs | 11 | 0 | P1 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/ClanMember.cs | 8 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/CharacterQuickBarSlotData.cs | 4 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/CharacterLearnedSkillData.cs | 3 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Auth/Models/GlobalServer.cs | 3 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| World/Models/CreatureExperienceLevel.cs | 2 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| World/Models/QuestXpLookup.cs | 2 | 0 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Auth/AuthContext.cs | 48 | 25 | P1 | EF InMemory or SQLite substitute; OnModelCreating assertions | model config; EnsureCreated on isolated DB; connection string init once |
| Char/CharContext.cs | 239 | 45.61 | P2 | EF InMemory or SQLite substitute; OnModelCreating assertions | model config; EnsureCreated on isolated DB; connection string init once |
| World/Models/ContinentObject.cs | 23 | 52.17 | P2 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/SimpleObjectData.cs | 5 | 60 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| World/Models/LootTable.cs | 69 | 65.22 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| Char/Models/CharacterData.cs | 48 | 70.83 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |
| World/Models/ContinentArea.cs | 4 | 75 | P3 | Model property + key/relationship mapping tests | required keys; default values; navigation properties |

### 5.3 AutoCore.Communicator — 0% overall; 7/7 files uncovered

Evidence: `coverage-audit-game` package `AutoCore.Communicator` (0 / 379 lines). **No test project.**

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| Communicator.cs | 274 | 0 | P0 | Inject socket factory; test packet handlers with MemoryStream peers | login accept/reject; redirect; server-info; malformed length; disconnect mid-read |
| Packets/LoginRequestPacket.cs | 31 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/RedirectRequestPacket.cs | 24 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/ServerInfoResponsePacket.cs | 20 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/RedirectResponsePacket.cs | 13 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/LoginResponsePacket.cs | 10 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Packets/ServerInfoRequestPacket.cs | 7 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |

### 5.4 AutoCore.Utils — 19.93% overall; 17 files below 80%

Evidence: `coverage-audit-utils` package rate **19.93%**. De-duplicated file aggregation on the same artifact ≈22.85% (partial-class accounting differs); use **19.93%** as the gate baseline. `Threading/MainLoop.cs` is already 100% via existing tests.

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| Networking/AsyncLengthedSocket.cs | 116 | 0 | P0 | EXCLUDE socket I/O; contract-test length framing with MemoryStream substitute | contract: length prefix framing; max length reject (via substitute) |
| Extensions/BinaryWriterExtensions.cs | 89 | 0 | P0 | BinaryReader/Writer MemoryStream extension matrix | lengthed string; edge lengths; EOF; multi-byte values |
| Commands/CommandProcessor.cs | 60 | 0 | P0 | Register commands; invoke Process with string inputs | register; dispatch; scoped commands; unknown command; empty input |
| Timer/Timer.cs | 43 | 0 | P0 | Fake ILoopable + manual clock advance | schedule; fire on advance; cancel; multi-item order |
| Packets/PacketRouter.cs | 41 | 0 | P0 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Extensions/BinaryReaderExtensions.cs | 40 | 0 | P0 | BinaryReader/Writer MemoryStream extension matrix | lengthed string; edge lengths; EOF; multi-byte values |
| Timer/TimedItem.cs | 22 | 0 | P1 | Fake ILoopable + manual clock advance | schedule; fire on advance; cancel; multi-item order |
| Packets/PacketQueue.cs | 21 | 0 | P1 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Server/BaseServer.cs | 20 | 0 | P1 | Subclass test double; command registration only | happy path; invalid input; boundary sizes; error/cancel path |
| Packets/PacketHandlerAttribute.cs | 8 | 0 | P3 | Read/Write round-trip via BinaryReader/Writer MemoryStream; no network | round-trip pack/unpack; truncated buffer throws/rejects; max-field sizes; opcode preserved |
| Extensions/StringExtensions.cs | 7 | 0 | P3 | BinaryReader/Writer MemoryStream extension matrix | happy path; invalid input; boundary sizes; error/cancel path |
| ExitableProgram.cs | 5 | 0 | P3 | EXCLUDE process exit; extract config validation seams | missing config fails; invalid connection string fails early; cancellation/shutdown path |
| Extensions/RandomExtensions.cs | 3 | 0 | P3 | BinaryReader/Writer MemoryStream extension matrix | happy path; invalid input; boundary sizes; error/cancel path |
| Extensions/SocketAsyncEventArgsExtensions.cs | 3 | 0 | P3 | BinaryReader/Writer MemoryStream extension matrix | optional: bind ephemeral; send/recv loopback OR exclude with framing contract |
| Memory/Singleton.cs | 2 | 0 | P3 | Instance reset lifecycle | happy path; invalid input; boundary sizes; error/cancel path |
| Logger.cs | 80 | 23.75 | P1 | WriteLog filter/type matrix with capture sink if available | each LogType; filter suppress; format args |
| Memory/NonContiguousMemoryStream.cs | 141 | 69.5 | P3 | Existing Memory tests; expand boundary/error paths | read/write spans; seek; grow; empty; large multi-segment |

### 5.5 AutoCore.Sector — 10.62% baseline; majority of files cold

Evidence: `coverage-audit-sector`. Existing tests cover `SectorCombatTick` and `SectorPlayerPoseTick` at 100%; host/server/dev remain 0%.

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| Dev/DevControlServer.cs | 185 | 0 | P0 | HttpListener test host on ephemeral port OR extract request handlers | list players; select player; invalid path 404; method not allowed |
| Network/SectorServer.cs | 139 | 0 | P0 | Setup with fake config; command dispatch without Start/UDP | Setup applies config; command exit/status; loop registration without Start |
| Program.cs | 49 | 0 | P0 | Extract config load + validation; do not start live servers | missing config fails; invalid connection string fails early; cancellation/shutdown path |
| Network/SectorServer.Commands.cs | 41 | 0 | P0 | Setup with fake config; command dispatch without Start/UDP | Setup applies config; command exit/status; loop registration without Start |
| Dev/DevPlayerSelector.cs | 19 | 0 | P1 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| Dev/DevConnectedCharacter.cs | 13 | 0 | P1 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| Config/SectorConfig.cs | 6 | 0 | P3 | Bind from temp JSON; required-field validation | happy path; invalid input; boundary sizes; error/cancel path |
| Config/GameConfig.cs | 6 | 0 | P3 | Bind from temp JSON; required-field validation | happy path; invalid input; boundary sizes; error/cancel path |

| File | Exec lines | % | Notes |
|------|-----------:|--:|-------|
| `Network/SectorCombatTick.cs` | 16 | 100 | Already covered — regression only |
| `Network/SectorPlayerPoseTick.cs` | 21 | 100 | Already covered — regression only |

### 5.6 AutoCore.Auth — no test project (0%)

Source inventory (approx physical lines; treat as fully uncovered until a coverage package exists):

| File | Source lines (approx) | % | Priority | Proposed test seam | Acceptance scenarios |
|------|----------------------:|--:|----------|--------------------|----------------------|
| `Program.cs` | 43 | 0 (no test project) | P0 | Extract config load + validation; do not start live servers | missing config fails; invalid connection string fails early; cancellation/shutdown path |
| `Config/AuthConfig.cs` | 9 | 0 (no test project) | P1 | Bind from temp JSON; required-field validation | required fields; defaults; invalid values rejected |
| `Crypto/Blowfish.cs` | 222 | 0 (no test project) | P0 | Known-vector encrypt/decrypt unit tests | encrypt/decrypt known vector; bad padding; empty buffer |
| `Crypto/CryptoManager.cs` | 43 | 0 (no test project) | P0 | Known-vector encrypt/decrypt unit tests | encrypt/decrypt known vector; key lifecycle; null key rejected |
| `Data/ClientOpcode.cs` | 9 | 0 (no test project) | P3 | Enum completeness / cast matrix | all opcode values distinct |
| `Data/ClientState.cs` | 11 | 0 (no test project) | P3 | Enum completeness / cast matrix | state transitions documented values |
| `Data/FailReason.cs` | 15 | 0 (no test project) | P3 | Enum completeness / cast matrix | all fail reasons distinct |
| `Data/ServerOpcode.cs` | 18 | 0 (no test project) | P3 | Enum completeness / cast matrix | all opcode values distinct |
| `Network/AuthClient.cs` | 105 | 0 (no test project) | P0 | Extract handlers; fake socket; no shared ports | login success/fail; protocol version; server list; kick; logout; no live bind |
| `Network/AuthClient.Handlers.cs` | 89 | 0 (no test project) | P0 | Extract handlers; fake socket; no shared ports | login success/fail; protocol version; server list; kick; logout; no live bind |
| `Network/AuthClient.Socketing.cs` | 47 | 0 (no test project) | P1 | EXCLUDE raw socket bind; contract framing via substitute | framing contract; disconnect path via fake |
| `Network/AuthServer.cs` | 135 | 0 (no test project) | P0 | Extract handlers; fake socket; no shared ports | setup; start refused without config; command registration; shutdown cancel |
| `Network/AuthServer.Commands.cs` | 63 | 0 (no test project) | P1 | CommandProcessor registration + string invoke | register; dispatch; unknown command |
| `Network/AuthServer.Communicator.cs` | 71 | 0 (no test project) | P1 | Fake communicator peer MemoryStream | login/redirect with fake peer |
| `Network/AuthServer.Socketing.cs` | 20 | 0 (no test project) | P2 | EXCLUDE shared-port bind; extract accept-handler | accept path via fake socket factory |
| `Packets/Client/AboutToPlayPacket.cs` | 24 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Client/LoginPacket.cs` | 43 | 0 (no test project) | P0 | Read/Write MemoryStream round-trip + DES fixture | round-trip credentials; bad ciphertext; opcode preserved |
| `Packets/Client/LogoutPacket.cs` | 21 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Client/SCCheckPacket.cs` | 21 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Client/ServerListExtPacket.cs` | 24 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/AccountKickedPacket.cs` | 22 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/BlockedAccountPacket.cs` | 18 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/BlockedAccountWithMsgPacket.cs` | 24 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/HandoffToQueuePacket.cs` | 24 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/LoginFailPacket.cs` | 22 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/LoginOkPacket.cs` | 42 | 0 (no test project) | P0 | Read/Write MemoryStream round-trip | round-trip session fields; truncated buffer |
| `Packets/Server/PlayFailPacket.cs` | 22 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/PlayOkPacket.cs` | 24 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/ProtocolVersionPacket.cs` | 26 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/SCCheckReqPacket.cs` | 21 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/SendServerFailPacket.cs` | 22 | 0 (no test project) | P1 | Read/Write MemoryStream round-trip | round-trip; truncated buffer; opcode preserved |
| `Packets/Server/SendServerListExtPacket.cs` | 67 | 0 (no test project) | P0 | Read/Write MemoryStream round-trip | empty list; multi-server list; truncated buffer |

### 5.7 AutoCore.Global — no test project (0%)

| File | Source lines (approx) | % | Priority | Proposed test seam | Acceptance scenarios |
|------|----------------------:|--:|----------|--------------------|----------------------|
| `Program.cs` | 60 | 0 (no test project) | P0 | Extract config load + validation; do not start live servers | missing config fails; invalid connection string fails early; cancellation/shutdown path |
| `Config/GameConfig.cs` | 18 | 0 (no test project) | P1 | Bind from temp JSON; required-field validation | required fields; defaults; invalid values rejected |
| `Config/GlobalConfig.cs` | 13 | 0 (no test project) | P1 | Bind from temp JSON; required-field validation | required fields; defaults; invalid values rejected |
| `Config/ServerInfoConfig.cs` | 9 | 0 (no test project) | P1 | Bind from temp JSON; required-field validation | required fields; defaults; invalid values rejected |
| `Network/GlobalServer.cs` | 88 | 0 (no test project) | P0 | Extract handlers; fake socket; no shared ports | setup; communicator login; command registration; shutdown cancel |
| `Network/GlobalServer.Commands.cs` | 28 | 0 (no test project) | P1 | CommandProcessor registration + string invoke | register; dispatch; unknown command |
| `Network/GlobalServer.Communicator.cs` | 67 | 0 (no test project) | P1 | Fake communicator peer MemoryStream | login/redirect with fake peer |

### 5.8 AutoCore.Launcher — no test project (0%)

| File | Source lines (approx) | % | Priority | Proposed test seam | Acceptance scenarios |
|------|----------------------:|--:|----------|--------------------|----------------------|
| `Program.cs` | 123 | 0 (no test project) | P0 | Extract config load, DB init, AssetManager init, host handoff into testable methods; never start live Launcher process | missing config fails; bad GamePath fails; DB connection string validation; ordered startup of Auth/Global/Sector seams with fakes; cancellation/shutdown |

### 5.9 TNL.NET — dependency risk (29.57%); **not** first-party 80% gate

Evidence: `coverage-audit-game` package `TNL.NET` (1,323 / 4,474 lines). Paths relative to repo root.

| File | Exec lines | % | Priority | Proposed test seam | Acceptance scenarios |
|------|-----------:|--:|----------|--------------------|----------------------|
| lib/TNL.NET/TNL.NET/Entities/NetInterface.cs | 765 | 0 | P0 | Entity constructors + attribute/pool unit tests | optional: bind ephemeral; send/recv loopback OR exclude with framing contract |
| lib/TNL.NET/TNL.NET/Structures/ReflectedSerializer.cs | 94 | 0 | P0 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/ClientPuzzleManager.cs | 68 | 0 | P0 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Network/TNLSocket.cs | 65 | 0 | P0 | OPTIONAL TNL stream; network bind exclusion + contract tests | optional: bind ephemeral; send/recv loopback OR exclude with framing contract |
| lib/TNL.NET/TNL.NET/Entities/Certificate.cs | 59 | 0 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/AsymmetricKey.cs | 58 | 0 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/StringTableEntry.cs | 49 | 0 | P0 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/SymmetricCipher.cs | 47 | 0 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/NetObjectRPCEvent.cs | 42 | 0 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/StringTable.cs | 26 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Utils/PacketStream.cs | 26 | 0 | P1 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/ConnectionStringTable.cs | 26 | 0 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Notify/PacketNotify.cs | 9 | 0 | P3 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Notify/EventPacketNotify.cs | 5 | 0 | P3 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Notify/GhostPacketNotify.cs | 5 | 0 | P3 | Unit tests against public API; extract pure logic if needed | pack mask bits; unpack into entity; null/zero ghost id; max object count edge |
| lib/TNL.NET/TNL.NET/Entities/EventConnection.cs | 351 | 14.25 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/Nonce.cs | 35 | 14.29 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/BaseObject.cs | 18 | 16.67 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/NetConnection.cs | 646 | 18.58 | P0 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/RPCEvent.cs | 14 | 28.57 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/BitSet.cs | 48 | 29.17 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Structures/FunctorDecl.cs | 36 | 33.33 | P1 | Value equality/serialization unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Utils/ByteBuffer.cs | 45 | 35.56 | P1 | Round-trip bit packing unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/GhostConnection.cs | 588 | 36.56 | P1 | Entity constructors + attribute/pool unit tests | pack mask bits; unpack into entity; null/zero ghost id; max object count edge |
| lib/TNL.NET/TNL.NET/Utils/RandomUtil.cs | 20 | 45 | P2 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Utils/BitStream.cs | 618 | 49.03 | P2 | Round-trip bit packing unit tests | write/read bits; string; aligned bytes; overflow guard |
| lib/TNL.NET/TNL.NET/Entities/NetObject.cs | 175 | 53.71 | P2 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Types/NetClassRep.cs | 105 | 60.95 | P3 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Entities/NetEvent.cs | 19 | 63.16 | P3 | Entity constructors + attribute/pool unit tests | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Types/NetConnectionRep.cs | 12 | 75 | P3 | State-machine unit tests with fake socket buffers | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Types/NetClassRepInstance.cs | 13 | 76.92 | P3 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |
| lib/TNL.NET/TNL.NET/Utils/Utils.cs | 14 | 78.57 | P3 | Unit tests against public API; extract pure logic if needed | happy path; invalid input; boundary sizes; error/cancel path |

---

## 6. Commit-ready work streams

**Commit shape (every stream):**

1. Failing tests (TDD red).
2. Minimal production seams / fixture fixes only as needed.
3. Tests green (TDD green).
4. Coverage snapshot + update §11 Progress log in this file.
5. Single coherent subsystem; narrowly scoped commit title (suggested below).

**Verification command (every stream):**

```powershell
dotnet test src/AutoCore.sln --no-restore
# then solution coverage script from stream 1, once it exists:
# powershell -File scripts/measure-solution-coverage.ps1
```

---

### Work stream 1 — Quality baseline

| Field | Value |
|-------|-------|
| **Goal** | Green suite foundation + reusable coverage/health gates before expanding coverage |
| **Coverage target** | N/A for new assemblies; unlock honest measurement; suite **0 failures** |
| **Suggested commit title** | `test: fix death-loot fixture and add solution coverage health gates` |

#### 1.1 Repair failing loot fixture (first)

| Item | Detail |
|------|--------|
| Test class | `DeathLootDeliveryTests` |
| Method | `AutoLootItem_AddsCargoWithCreateAddResponseCargoSendAll` |
| Fix approach (TDD) | Reproduce failure → supply **nonzero inventory footprint** on the registered clone base / item fixture (same pattern as other inventory tests that set grid size) → confirm Create + `InventoryAddItemResponsePacket` + `InventoryCargoSendAllPacket` assertions pass |
| Do **not** | Weaken assertions or `[Ignore]` the test |

#### 1.2 Solution coverage command/script

Add reusable script (proposed path: `scripts/measure-solution-coverage.ps1`), patterned after `scripts/measure-scoped-coverage.ps1` / `measure-mission-coverage.ps1`:

| Requirement | Detail |
|-------------|--------|
| Collect | Each test project’s Cobertura (`dotnet test ... --collect:"XPlat Code Coverage"` per test project or solution with results directory) |
| De-dupe | Merge executable lines by assembly + source file + line number (max hits) |
| Emit | Console + Markdown summary: per-assembly line % and branch % |
| Fail | Exit non-zero if any **first-party** assembly `AutoCore.{Game,Utils,Database,Sector,Communicator,Auth,Global,Launcher}` is below **80%** line coverage **when that assembly is present in reports** |
| Hosts without tests | Report as **0% / no coverage package** and fail the gate once test projects exist; until then script may list them as `MISSING_TESTS` hard-fail after stream 2 |
| TNL.NET | Print separately; **do not** fail first-party gate on TNL % |
| Health | Parse trx/console: enforce `Passed/(Passed+Failed) >= 90%`; list skipped counts; fail if new untracked skips (optional allow-list file) |

#### 1.3 Test-health gate policy

| Rule | Enforcement |
|------|-------------|
| `Passed / (Passed + Failed) >= 90%` | Script + CI later |
| Skipped | Report separately; prohibit newly skipped tests without rationale entry in §11 or `docs/testing/skipped-tests.md` |
| Full suite | `dotnet test src/AutoCore.sln` before merge of this stream |

#### 1.4 Behavior matrix (stream 1)

| Scenario | Expected |
|----------|----------|
| Death loot auto-loot with footprint fixture | Cargo add + three packet types |
| Death loot cargo full | Returns false; no add response |
| Coverage script missing report | Non-zero exit with clear error |
| Coverage script with Game <80% | Non-zero exit listing Game |
| Health with 1 failure / 3122 pass | Pass rate ≥90% still true; but stream 1 must eliminate the failure |

#### 1.5 Verification

```powershell
dotnet test src/AutoCore.Game.Tests/AutoCore.Game.Tests.csproj --filter "FullyQualifiedName~DeathLootDeliveryTests"
dotnet test src/AutoCore.sln --no-restore
powershell -File scripts/measure-solution-coverage.ps1
```

---

### Work stream 2 — Untested application hosts (Auth, Global, Launcher)

| Field | Value |
|-------|-------|
| **Goal** | Create test projects + deterministic seams; cover startup/config, wiring, auth/session failures, shutdown, handoff **without** live servers |
| **Coverage target** | Each of Auth / Global / Launcher ≥80% of **testable** surface; excluded I/O per §4 with contract alternatives |
| **Suggested commit titles** | `test: add AutoCore.Auth.Tests with packet and crypto coverage` → `test: add AutoCore.Global.Tests host seams` → `test: add AutoCore.Launcher.Tests config and init seams` (one commit per host preferred) |

#### 2.1 New test projects

| Project | References | Notes |
|---------|------------|-------|
| `src/AutoCore.Auth.Tests` | Auth, Utils, Database as needed | MSTest to match solution |
| `src/AutoCore.Global.Tests` | Global, Utils, Game as needed | |
| `src/AutoCore.Launcher.Tests` | Launcher (or extracted library surface) | Prefer testing extracted pure methods over `Main` |

Add projects to `src/AutoCore.sln` under the existing `test` solution folder.

#### 2.2 Test classes (planned)

| Assembly | Test classes |
|----------|--------------|
| Auth | `AuthConfigTests`, `BlowfishTests`, `CryptoManagerTests`, `LoginPacketTests`, `AuthServerPacketRoundTripTests`, `AuthClientHandlerTests`, `AuthServerCommandTests`, `AuthServerSetupTests` |
| Global | `GlobalConfigTests`, `GlobalServerSetupTests`, `GlobalServerCommandTests`, `GlobalServerCommunicatorTests` |
| Launcher | `LauncherConfigValidationTests`, `LauncherInitOrderTests`, `LauncherShutdownTests` |

#### 2.3 Behavior matrix

| Area | Scenarios |
|------|-----------|
| Config | Missing file; invalid JSON; missing connection string; defaults applied |
| Auth packets | Round-trip all client/server packets; truncated buffer; LoginPacket DES fixture |
| Auth crypto | Blowfish/CryptoManager known vectors |
| Auth handlers | Login ok/fail; blocked account; protocol version mismatch; logout; about-to-play |
| Global | Setup with fake config; communicator login/redirect; commands |
| Launcher | Config validation fails fast; AssetManager init failure path (fake); ordered handoff to Auth/Global/Sector **fakes**; cancellation |
| Shutdown | Cancellation token / exit handler does not hang; no port bind |

#### 2.4 Verification

```powershell
dotnet test src/AutoCore.Auth.Tests/AutoCore.Auth.Tests.csproj
dotnet test src/AutoCore.Global.Tests/AutoCore.Global.Tests.csproj
dotnet test src/AutoCore.Launcher.Tests/AutoCore.Launcher.Tests.csproj
dotnet test src/AutoCore.sln --no-restore
powershell -File scripts/measure-solution-coverage.ps1
```

---

### Work stream 3 — Communicator, Sector, and Utils

| Field | Value |
|-------|-------|
| **Goal** | Lift Communicator from 0%, Sector from ~10%, Utils from ~20% toward ≥80% each |
| **Coverage target** | Communicator ≥80%; Sector ≥80%; Utils ≥80% |
| **Suggested commit titles** | `test: cover Communicator packets and login flows` → `test: expand Sector server and Dev control coverage` → `test: raise Utils sockets framing, timers, and packet router coverage` |

#### 3.1 Communicator

| Item | Detail |
|------|--------|
| New project | `src/AutoCore.Communicator.Tests` (if not folded into Utils/Auth tests) |
| Test classes | `LoginRequestPacketTests`, `LoginResponsePacketTests`, `RedirectRequestPacketTests`, `RedirectResponsePacketTests`, `ServerInfoRequestPacketTests`, `ServerInfoResponsePacketTests`, `CommunicatorHandlerTests` |
| Seams | Packet Read/Write MemoryStream; inject socket factory for `Communicator.cs`; no shared live ports |
| Matrix | Valid login; bad password; redirect; server-info; malformed length; partial read; disconnect mid-packet; opcode mismatch |

#### 3.2 Sector

| Item | Detail |
|------|--------|
| Existing | `SectorCombatTickTests`, `SectorPlayerPoseTickTests` (keep green) |
| New classes | `SectorServerSetupTests`, `SectorServerCommandTests`, `SectorConfigTests`, `DevControlServerTests`, `DevPlayerSelectorTests`, `ProgramConfigValidationTests` |
| Seams | `SectorServer.Setup` without `Start`/UDP; command processor; Dev handlers on ephemeral port or extracted methods |
| Matrix | Setup applies config; commands; Dev list/select/404; combat/pose ticks regression; cancellation |

#### 3.3 Utils

| Item | Detail |
|------|--------|
| Existing | `MainLoopTests`, `NonContiguousMemoryStreamTests` |
| New classes | `CommandProcessorTests`, `PacketRouterTests`, `PacketQueueTests`, `TimerTests`, `TimedItemTests`, `BinaryReaderExtensionsTests`, `BinaryWriterExtensionsTests`, `StringExtensionsTests`, `LoggerTests`, `BaseServerTests`, `LengthPrefixFramingTests` (contract for AsyncLengthedSocket), `SingletonTests` |
| Exclusions | OS socket I/O in `AsyncLengthedSocket` per §4; framing contract required |
| Matrix | Command register/dispatch/scopes; router known/unknown opcode; queue order; timer fire/cancel; lengthed string edges; logger types; memory stream multi-segment |

#### 3.4 Verification

```powershell
dotnet test src/AutoCore.Communicator.Tests/AutoCore.Communicator.Tests.csproj
dotnet test src/AutoCore.Sector.Tests/AutoCore.Sector.Tests.csproj
dotnet test src/AutoCore.Utils.Tests/AutoCore.Utils.Tests.csproj
dotnet test src/AutoCore.sln --no-restore
powershell -File scripts/measure-solution-coverage.ps1
```

---

### Work stream 4 — Database and Game gaps

| Field | Value |
|-------|-------|
| **Goal** | Database ≥80%; Game ≥80% by closing 0% Login/TNL/mail/global packets and templates, then partial managers |
| **Coverage target** | Database ≥80%; Game ≥80% (assembly line rate) |
| **Suggested commit titles** | `test: add Database context and model coverage` → `test: cover Game login TNL and mail/global packet contracts` → `test: close Game manager and template coverage gaps to 80%` |

#### 4.1 Database

| Item | Detail |
|------|--------|
| Project | Prefer `src/AutoCore.Database.Tests` (clean) or expand Game.Tests with clear namespace `Database` |
| Test classes | `AuthContextModelTests`, `CharContextModelTests`, `WorldContextModelTests`, `CharacterDataMappingTests`, `LootTableModelTests`, `ConnectionStringInitTests` |
| Seams | EF InMemory / SQLite; `OnModelCreating`; isolated DB; **no shared MySQL** |
| Matrix | EnsureCreated; keys/relationships; invalid concurrent update if applicable; connection string init idempotence |

#### 4.2 Game — priority order

1. **Fully uncovered Login / TNL connection flows** — `LoginManager`, `TNLConnection.Login`, `TNLConnection.Global`, `TNLInterface`, login packets.
2. **Mail / Global / Sector packet contracts at 0%** — all §5.1 packet rows at 0% — bulk round-trip tests.
3. **Entity templates & structures at 0%** — `OutpostTemplate`, `RoadNode`, `Music`, auction/mail structures, weather.
4. **Partial high-impact managers** — `ChatManager`, `CharacterSelectionManager`, asset loaders, `TNLConnection.Sector`, `InventoryPersistence`, ghosts, `AssetManager`, `MapData`, `LootManager` residual, `SectorMap` to push assembly over 80%.

| Test classes (examples) | Focus |
|-------------------------|-------|
| `LoginManagerTests` | expect/login/timeout/mismatch |
| `LoginPacketContractTests` | all Login/* packets |
| `MailPacketContractTests` | all Mail/* packets |
| `GlobalPacketContractTests` | all Global/* packets at 0% |
| `TNLConnectionLoginTests` / `TNLConnectionGlobalTests` | handlers + TestPacketSink |
| `TNLInterfaceTests` | config/version without bind |
| `OutpostTemplateTests` + template suite | property load |
| `ChatManagerCommandTests` | dispatch matrix |
| `CharacterSelectionManagerTests` | list/create/delete guards |
| `GhostCharacterPackTests` etc. | BitStream pack |
| `InventoryPersistenceTests` | save/load |

#### 4.3 Behavior matrix (Game highlights)

| Scenario | Expected |
|----------|----------|
| ExpectLoginToGlobal then LoginToGlobal valid | Success path; entry consumed |
| Auth key mismatch | Fail; no session |
| Login timeout after advance | Entry expired |
| Packet round-trip | Field equality after Write/Read |
| Truncated packet | Controlled failure (throw or false) — document actual API |
| Chat unknown command | Safe reject |
| Character selection invalid account | No crash; fail packet |

#### 4.4 Verification

```powershell
dotnet test src/AutoCore.Database.Tests/AutoCore.Database.Tests.csproj  # if created
dotnet test src/AutoCore.Game.Tests/AutoCore.Game.Tests.csproj
dotnet test src/AutoCore.sln --no-restore
powershell -File scripts/measure-solution-coverage.ps1
```

---

### Work stream 5 — TNL.NET dependency-risk follow-up (optional)

| Field | Value |
|-------|-------|
| **Goal** | Track and optionally raise coverage on high-risk untested networking/serialization/crypto in `lib/TNL.NET` |
| **Coverage target** | **Not** part of first-party 80% gate unless ownership is confirmed |
| **Suggested commit title** | `test: optional TNL.NET BitStream and connection state coverage` |

#### 5.1 High-risk cold areas (from inventory)

| File | Lines | % | Risk |
|------|------:|--:|------|
| `Entities/NetInterface.cs` | 765 | 0 | Listen/connect core |
| `Entities/NetConnection.cs` | 646 | 18.58 | Connection state machine |
| `Entities/GhostConnection.cs` | 588 | 36.56 | Ghosting |
| `Entities/EventConnection.cs` | 351 | 14.25 | Events |
| `Utils/BitStream.cs` | 618 | 49.03 | Serialization backbone |
| `Structures/ReflectedSerializer.cs` | 94 | 0 | Reflection serdes |
| `Network/TNLSocket.cs` | 65 | 0 | Socket |
| `Entities/SymmetricCipher.cs` / `AsymmetricKey` / `Certificate` | 47–59 | 0 | Crypto |
| `Structures/ClientPuzzleManager.cs` | 68 | 0 | Anti-DoS puzzle |

#### 5.2 Policy

- Do **not** use coverlet exclusions to hide these files from reports.
- Prefer pure `BitStream` / buffer tests first (high ROI, no bind).
- Network bind tests only with ephemeral ports and explicit opt-in.
- Promote into enforced gate **only** if AutoCore owns TNL.NET maintenance.

#### 5.3 Verification

```powershell
dotnet test src/AutoCore.Game.Tests/AutoCore.Game.Tests.csproj --collect:"XPlat Code Coverage"
# report TNL.NET package separately in measure-solution-coverage.ps1
dotnet test src/AutoCore.sln --no-restore
```

---

## 7. TDD protocol (mandatory)

For **every** production change or fixture fix in streams 1–5:

1. Write or update a test that expresses the desired behavior.
2. Run it; **confirm it fails for the correct reason** (not compile noise from unrelated breaks).
3. Implement the **smallest** production or test-fixture change to pass.
4. Re-run the new test and the relevant suite.
5. Run full solution tests before declaring the stream done.
6. Update coverage snapshot in §11.

Agents must follow `Agents.md` engineering standards (coverage expectations for touched modules, no empty catches, no live Launcher without approval).

---

## 8. Verification and acceptance (plan completion criteria)

When **all** work streams are done, the solution is accepted if:

| # | Criterion |
|---|-----------|
| 1 | `dotnet test src/AutoCore.sln` → **0 failed**; skipped cataloged and justified |
| 2 | `Passed/(Passed+Failed) >= 90%` (and effectively 100% with zero failures) |
| 3 | Each first-party assembly line coverage ≥ **80%** per solution coverage script |
| 4 | TNL.NET reported separately; not used to pass/fail first-party gate unless ownership expanded |
| 5 | This document’s §11 Progress log lists each stream’s commit, coverage after, remaining hotspots |
| 6 | No live Launcher was required for the default test path |

**This documentation deliverable only** is accepted when:

| # | Criterion |
|---|-----------|
| 1 | This file exists at `docs/testing/solution-test-coverage-remediation-plan.md` |
| 2 | Baseline numbers match §2 (3122/1/4/3127, named failing test, assembly %) |
| 3 | Scope, exclusions, inventory, five work streams, TDD, verification are present |
| 4 | Inventory rows reference real paths under `src/AutoCore.*` / `lib/TNL.NET` |

---

## 9. Suggested implementation order

```text
Stream 1 (green suite + measurement)
    → Stream 2 (hosts Auth/Global/Launcher)
        → Stream 3 (Communicator / Sector / Utils)
            → Stream 4 (Database + Game to 80%)
                → Stream 5 (optional TNL.NET)
```

Parallelism: after stream 1, streams 2 and 3 can proceed in parallel on separate branches/worktrees if merge discipline is kept. Stream 4 depends on stable Game.Tests fixtures from stream 1.

---

## 10. Assumptions

1. **80% is per first-party assembly**, not a weighted solution average.
2. **TNL.NET** is a vendored/submodule dependency tracked separately.
3. **No live Launcher/server** for this remediation effort; hosts tested via seams and doubles.
4. Baseline suite counts and assembly percentages are **frozen as of 2026-07-21**; later Progress log rows supersede “current” coverage as streams land.
5. File-level executable line counts come from Cobertura de-duplication on audit artifacts; hosts without packages use source-line approximations until first coverage run.

---

## 11. Progress log (update after each committed stream)

| Date | Stream | Commit | Suite (P/F/S/T) | Assembly coverage notes | Remaining focus |
|------|--------|--------|-----------------|-------------------------|-----------------|
| 2026-07-21 | — (baseline) | *(this document only)* | 3122 / 1 / 4 / 3127 | Game 75.57%; Utils 19.93%; Database 47.32%; Sector 10.62%; Communicator 0%; Auth/Global/Launcher no tests; TNL.NET 29.57% | Stream 1: fix DeathLoot fixture + coverage script |
| 2026-07-21 | 1 Quality baseline | uncommitted | 3123 / 0 / 4 / 3127 | DeathLoot fixture fixed (`RegisterCloneBase` InvSize 1×1); `scripts/measure-solution-coverage.ps1` + SCRIPTS.md; test projects scaffolded | Streams 2–4 |
| 2026-07-21 | 2 Hosts | uncommitted | Auth 84; Global 46; Launcher 37 | Auth 87.88%; Global 98.45% (Program host excluded §4); Launcher 90.62% (Program + live bootstrap methods excluded §4) | Residual socket bind I/O |
| 2026-07-21 | 3 Comm/Sector/Utils | uncommitted | Comm 66; Sector 79; Utils 170 | Communicator 98.49%; Sector 90.24%; Utils 93.51% | AsyncLengthedSocket OS residual |
| 2026-07-21 | 4 Database/Game | uncommitted | DB 58; Game 3266 / 0 / 4 | Database 94.23%; Game 80.79% | Optional deeper Chat/TNLConnection.Sector; Stream 5 optional |
| 2026-07-21 | **Acceptance** | uncommitted | **~3806 / 0 / 4 / ~3810** | **All first-party ≥80%** via `measure-solution-coverage.ps1` (gate exit 0). TNL.NET 32.59% (not gated) | Stream 5 optional only |
| 2026-07-21 | **≥90% gate** | uncommitted | **4103 / 0 / 4 / 4107** | Game 90.34%; Utils 93.51%; Database 94.23%; Sector 90.24%; Communicator 98.49%; Auth 97.53%; Global 98.45%; Launcher 90.62%. TNL.NET 33.95% ignored | Optional deeper residual only |
| | 5 TNL.NET optional | _pending_ | | TNL.NET 33.95% | Optional BitStream/crypto follow-up |

**Skipped tests catalog (baseline + later):**

| Test | Reason | Tracked? |
|------|--------|----------|
| `RetailParityTests.RampExit_GenuineLiftoffAtLip_FollowsBallisticArc` | C-mass residual (m=1500): no genuine free-flight at lip | Yes — physics parity debt |
| `RetailParityTests.Downhill_ContinuousGrade_AtSpeed_StaysGrounded_NoBounce` | C-mass residual: contactRatio≈96% (&lt;99% contract) from r×F micro-hop | Yes — physics parity debt |
| `FrictionSolverOracleTests.PortSolve_ReproducesRetailImpulses_BitExact` | C4 residual: Solve coupling / CircleProjection not bit-exact vs retail | Yes — physics parity debt |
| `SteeringOracleTests.KnownDeviation_ZeroFullSpeedLimitZeroForwardSpeed_PortDiffersFromRetail` | Documented port deviation (retail NaN case); unblocked note on Ignore | Yes — known deviation |

---

## 12. Evidence index

| Evidence | Location |
|----------|----------|
| Game/Database/Communicator/TNL Cobertura | `TestResults/coverage-audit-game/` |
| Utils Cobertura | `TestResults/coverage-audit-utils/` |
| Sector Cobertura | `TestResults/coverage-audit-sector/` |
| Failing test source | `src/AutoCore.Game.Tests/Managers/DeathLootDeliveryTests.cs` |
| Existing coverage script patterns | `scripts/measure-*-coverage.ps1` |
| Style peer docs | `docs/testing/mission-test-plan.md`, `mission-coverage-report.md` |

---

*End of remediation plan. Implementers: execute streams in order, keep TDD, update §11, do not start shared live servers without explicit approval.*

