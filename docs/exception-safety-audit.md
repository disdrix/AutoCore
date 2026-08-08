# Exception-Safety & Crash-Resistance Audit

**Status:** Phase 1â€“2 complete (CRITICAL + HIGH remediated); Phase 3 pre-alpha pass complete (SS-20â€¦SS-24); SS-25 Discord module boundaries; SS-26 auth dispatch boundary; SS-27 kill-loot credit persistence; SS-28 GM command authz; SS-29 transfer-key log-only; SS-30 instance-disposal containment; remaining MEDIUM/LOW catalogued below
**Date:** 2026-08-08
**Scope:** all production code under `src/` â€” `AutoCore.{Auth,Communicator,Database,Discord,Game,Global,Launcher,Sector,Utils}`
**Gate:** `dotnet build src/AutoCore.sln` + `dotnet test src/AutoCore.sln`

Repository-wide audit of unhandled exceptions, unsafe failure paths, and conditions that could
terminate a server process, a worker, a thread, or a request handler. The objective is not "zero
possible crashes" â€” it is that a single failure is **isolated, observable, and survivable**,
without using `try`/`catch` to hide defects.

No live server was started at any point (`AGENTS.md`: shared ports/DBs require explicit approval).

---

## Methodology

1. Inventory every entry point, detached execution path, loop, and external boundary.
2. Trace call chains to find where an escaping exception actually lands.
3. For each finding: write a failing tripwire test first, fix, then prove the test fails again
   when the fix is reverted (TDD per `AGENTS.md`).
4. Isolate at architectural boundaries only. Do not wrap ordinary logic in `try`/`catch`.
5. Catalogue what was not fixed, with severity and rationale.

### Reproducible commands

```powershell
# Build (analyzers on, warnings only â€” the build cannot break on analysis)
dotnet build src/AutoCore.sln

# Full suite
dotnet test src/AutoCore.sln

# The reliability primitives specifically
dotnet test src/AutoCore.Utils.Tests/AutoCore.Utils.Tests.csproj `
  --filter "FullyQualifiedName~Reliability|FullyQualifiedName~LoggerTests|FullyQualifiedName~TimerTests"

# Analyzer warning census by rule
dotnet build src/AutoCore.sln -v minimal --no-incremental 2>&1 `
  | Select-String "warning CA" `
  | ForEach-Object { if ($_ -match "warning (CA\d+)") { $matches[1] } } `
  | Group-Object | Sort-Object Count -Descending
```

### Results

| Metric | Baseline (33b114e2e) | After |
|---|---:|---:|
| Build errors | 0 | 0 |
| Tests passed | 4139 | **4207** |
| Tests failed | 1 (flaky, see below) | **0** |
| Tests skipped | 4 | 4 |
| Process-global exception handlers | **0** | 4 (`AppDomain`) + 4 (`TaskScheduler`) |
| Entry points with a failure boundary | 0 of 4 | **4 of 4** |
| `throw ex;` (stack-trace resets) | 0 | 0 |
| Error-level logs discarding the stack trace | 36 | **0** |
| `Logger.WriteException` call sites | 0 | 76 |
| No-op (empty / comment-only) catch bodies | 17 | **10** (4 documented-intentional, 6 low-risk) |
| Built-in default credentials | 1 (`admin`/`admin`, Level 255) | **0** |

The baseline failure was `LauncherShutdownTests.Shutdown_DoesNotBindPorts`. It is **pre-existing,
flaky, and unrelated**: it compares the machine-wide `GetActiveTcpListeners()` count before and
after, so any parallel test assembly binding a socket fails it. It passes in isolation and passed
in the final full run.

---

## Severity levels

* **CRITICAL** â€” can terminate the application or corrupt important state
* **HIGH** â€” can permanently kill an important subsystem or worker
* **MEDIUM** â€” can cause an operation to fail incorrectly or leak resources
* **LOW** â€” defensive hardening opportunity

---

## Prior work: SS-01 â€¦ SS-05

An earlier hardening pass existed only as code comments, documented nowhere. Recorded here so
the series is traceable.

| ID | Invariant | Production | Test |
|---|---|---|---|
| SS-01 | A tick exception must not kill the main loop thread | `AutoCore.Utils/Threading/MainLoop.cs:68` | `MainLoopTests.MainLoop_ContinuesAfterUnhandledExceptionInTick` |
| SS-02 | One throwing connection must not skip others in the sector tick | `AutoCore.Sector/Network/SectorCombatTick.cs`, `SectorPlayerPoseTick.cs` | `SectorCombatTickTests`, `SectorPlayerPoseTickTests` |
| SS-03 | Objects unregistered on disconnect; no stale living instance | `AutoCore.Game/Managers/ObjectManager.cs`, `TNL/TNLConnection.cs:1215` | `ObjectManagerTests` |
| SS-04 | Stale `OwningConnection` must not NRE private chat | `AutoCore.Game/Managers/ChatManager.cs`, `TNL/TNLConnection.cs:1263` | `ChatPrivateMessageOwnershipTests` |
| SS-05 | DB writes must not block the vehicle-move / tick hot path | `AutoCore.Game/Managers/ExplorationManager.cs` | `ExplorationPersistenceTests` |

---

## Shared reliability utilities (new)

Three small, debuggable primitives in `src/AutoCore.Utils/Reliability/`. Each generalizes a
pattern that already existed in duplicate; none was introduced speculatively.

| Type | Purpose |
|---|---|
| `Guard` | `Run` / `ForEach` â€” isolate a unit of work at a boundary, report it, continue. Generalizes the SS-02 `ProcessAll` helpers, which now delegate to it. |
| `SafeTask` | `FireAndForget` â€” the sanctioned way to detach work. Observes the fault, unwraps `AggregateException`, distinguishes cancellation from failure. |
| `CrashHandler` | `Install` â€” registers the two process-global hooks and formats a full diagnostic report. Idempotent. |
| `BackoffPolicy` | Bounded exponential backoff with jitter and a consecutive-failure cap, for loops that must survive transient errors without spinning. |

`Guard` deliberately **does not** contain `OperationCanceledException` (cancellation is control
flow; the surrounding loop must be allowed to stop) or `OutOfMemoryException` (continuing is
unsafe). See *Deliberately unhandled* below.

---

## Findings

### CRITICAL

| ID | Subsystem | File:line | Risk / failure scenario | Handled before | Remediation | Tests |
|---|---|---|---|---|---|---|
| SS-06 | Logging | `AutoCore.Utils/Logger.cs` | **The last-resort diagnostic layer could itself throw, from inside the 160 `catch` blocks that call it** â€” converting a contained failure into a crash. `LogType.ExportData` had no `switch` case and fell to `default: throw new ArgumentOutOfRangeException` *before* reaching its own formatting branch (dead code proving intent). The static `StreamWriter` and `Console` colour state were mutated from the tick thread and every socket task with **no lock** (interleaving + `ObjectDisposedException` race with `UpdateConfig`). `UpdateConfig` opened a `FileStream` unguarded, so an unwritable path aborted startup. | No | Every public entry point is now total: unknown enum degrades, all emission is serialised, file/console I/O failures are contained, a hostile `ToString()` cannot escape. Added `LogType.Warning`/`Fatal` and `Logger.WriteException`. | 17 in `LoggerTests`, incl. concurrency and unwritable-path |
| SS-07 | All entry points | `{Launcher,Auth,Global,Sector}/Program.cs` | **Zero process-global exception handling existed repo-wide.** No `Main` had a `try`/`catch`; `AppDomain.CurrentDomain.UnhandledException` and `TaskScheduler.UnobservedTaskException` had **0 occurrences**. Any escaped exception killed the process with only a default stack dump â€” and Launcher hosts Auth+Global+Sector in one process, so all three died together. Separately, Global and Sector declared `LoggerConfig` but never called `Logger.UpdateConfig`, so their configured file logging was inert and diagnostics went to console only. | No | `CrashHandler.Install(...)` first in every `Main`; body wrapped with a `Fatal` boundary returning exit code 1. `Logger.UpdateConfig` wired in Global and Sector. Console-ctrl exit handlers isolated per server. | `CrashHandlerTests` (9) |
| SS-19 | Persistence | `Game/Managers/ExplorationManager.cs:275`, `MissionPersistence.cs:153` | **An exception escaping a `ThreadPool.QueueUserWorkItem` callback is an unhandled exception on a pool thread, which terminates the process.** Both had `try`/`finally` (clearing the scheduling flag) but **no `catch`**, so any throw from the flush was fatal. | No | Both bodies wrapped in `Guard.Run`; the `finally` bookkeeping is unchanged. | Covered by `GuardTests`; failure path exercised via `MissionFaultInjectionTests` |

### HIGH

| ID | Subsystem | File:line | Risk / failure scenario | Handled before | Remediation | Tests |
|---|---|---|---|---|---|---|
| SS-08 | Server host | `Utils/Server/BaseServer.cs:14` | `while (IsRunning) { ProcessCommand(); }` is the **foreground loop of all four executables** and was unguarded. A throwing console command ended it; the process stayed alive but accepted no further commands and never reached its shutdown path. | No | Per-iteration `Guard.Run`, plus an inner guard on handler dispatch in `CommandProcessor.Execute`. | `BaseServerTests.ProcessCommands_WhenACommandThrows_LoopSurvivesAndKeepsProcessing`, 2 in `CommandProcessorTests` |
| SS-09 | Timers | `Utils/Timer/Timer.cs:29` | Callbacks were invoked **inside `lock (_timedItems)` and inside the `foreach`**. One throwing callback (a) aborted every remaining due timer, (b) skipped the one-shot cleanup so **a failing one-shot re-fired forever**, and (c) made it illegal for a callback to schedule follow-up work (`InvalidOperationException`, collection modified) â€” which is exactly what the exit and communicator-reconnect timers do. | No | Collect due items under the lock, unregister one-shots, then invoke outside the lock via `Guard.Run`. Added `TimedItem.Cancelled` so a timer removed earlier in the same pass still does not fire (preserves original semantics). | 5 tripwires in `TimerTests` |
| SS-10 | Networking | `Utils/Networking/AsyncLengthedSocket.cs` | The accept, receive and send loops each had an outer `catch (Exception)` that **exited the loop permanently** â€” no re-listen. The process stayed up while silently serving nobody. Five catches were empty; one (`catch (TaskCanceledException) {}` inside `while(true)`) was an unbounded hot spin. All reporting used `Console.WriteLine`, bypassing `Logger`. `Close()` disposed the `CancellationTokenSource` while the loops were still awaiting its token. | Partially (loop died "cleanly") | Terminal vs transient classification; bounded backoff + jitter with a failure cap escalating to `Fatal`; all reporting through `Logger`; CTS no longer disposed under in-flight awaits. | `Loopback_WhenAcceptCallbackThrows_...`, `Close_IsIdempotent`, 8 in `BackoffPolicyTests` |
| SS-11 | Protocol | `Communicator.cs:209/215`, `Auth/Network/AuthClient.Socketing.cs`, `Game/TNL/TNLConnection.cs:725` | **Peer-controlled bytes threw from the socket receive task**, killing that connection's receive loop for good. An unknown opcode or an over/under-read threw bare `Exception`; TNL's dispatch prologue (`ReadUInt32`) sat *outside* the `try` guarding the handler switch, so a frame shorter than 4 bytes threw past it. The length prefix was never range-checked, so a negative or oversized declared size corrupted stream bookkeeping. | No | Malformed input is validated and the **message** rejected (Warning + peer identity), not the connection. TNL prologue moved inside its guard. Declared packet size range-checked against `0..MaxDataSize`; framing cannot be resynchronised after a bad length, so the connection is dropped deliberately. Packets are always consumed in a `finally` so a malformed one cannot be re-parsed in a hot loop. | `Loopback_WhenReceiveCallbackThrows_...`, 6 rewritten/new in `CommunicatorHandlerTests` |
| SS-12 | NPC AI | `Game/Npc/NpcTicker.cs:31`, `Managers/MapManager.cs`, `Sector/Network/SectorServer.cs` | The per-NPC `foreach` was unguarded, so one bad NPC aborted **every later NPC on that map**, and because `MapManager.TickNpcs` looped maps unguarded too, **every later map** â€” freezing AI server-wide while the tick kept running. `RebucketAllGrids`, `ForcePathVehiclePoseDirty` and `Interface.Pulse()` were likewise unguarded; a throw before `Pulse` meant that tick shipped **no network output at all**. | No | `Guard.ForEach` per NPC and per map; each tick stage individually guarded. | `NpcTicker_WhenOneNpcPathIsCorrupt_OtherNpcsStillTick` (verified to fail with a real `NullReferenceException` when the guard is reverted) |
| SS-13 | World logic | `Game/Map/SectorMap.cs:1865` | Reactions are the data-driven "scripting" surface â€” map content reaches an ~80-case switch â€” so malformed content lands there. One throwing reaction aborted the whole batch **and** its queued child batch, silently dropping unrelated world logic. | No | `Guard.ForEach` per reaction and per child batch. | 2 in `SectorMapReactionIsolationTests` (both verified to fail when reverted) |
| SS-14 | Persistence | `Game/Managers/MissionPersistenceQueue.cs:86` | Bare `catch { _pending.TryAdd(key, op); }` â€” a permanently failing write re-queued itself on **every flush forever**, with no logging. The queue never drained and nothing reported the problem. | No | Bounded attempts (`MaxPersistAttempts = 5`) with Warning per retry, Error + dead-letter on exhaustion, and a `DeadLetteredCount` so loss is observable. A success resets the budget. | 2 in `MissionFaultInjectionTests` |
| SS-15 | Auth / DB | `Auth/Network/AuthServer.Commands.cs:59`, `Database/Char/CharContext.cs:282`, `Game/Managers/CharacterSelectionManager.cs:312` | A bare `catch` reported **every** account-creation failure (connection refused, schema mismatch, permission denied) as *"Username or email is already taken!"*. A bare `catch` on raw DDL migration, commented "already exists", made a permissions error indistinguishable from the benign case â€” **startup continued on a silently incomplete schema**. One truly empty `catch {}` hid failure to restore `FOREIGN_KEY_CHECKS`. **The create-account success path also logged the plaintext password.** | No | Duplicate checked up-front (Â§10) with `DbUpdateException` handling the race; other failures logged and reported honestly. DDL narrowed to genuine duplicate-object MySQL error numbers, everything else logged at Error. Password removed from the log. | Covered by existing Auth/Database suites |
| SS-16 | Resources | `AuthClient.Socketing.cs`, `Communicator.cs:263`, `AuthServer.cs:46`, `GlobalServer.cs:36` | `ArrayPool` buffers were returned only on the success path, so any throw leaked them out of the pool permanently. Two finalizers called `Shutdown()` â€” which takes locks and closes sockets â€” on the GC finalizer thread, where **an escaping exception is uncatchable and terminates the process**. | No | `try`/`finally` around all pooled rentals; both finalizers isolated with `Guard.Run`. | Covered by existing Auth/Communicator suites |
| SS-17 | Detached work | `AsyncLengthedSocket.cs` Ã—4, `Sector/Dev/DevControlServer.cs` Ã—2, `MissionClientSoftPedal.cs`, `NpcInteractHandler.cs` | Six bare `_ = Taskâ€¦` sites: nothing observed them, so a fault was invisible until GC. `DevControlServer` had two empty bare catches (one hiding a faulted accept loop on shutdown), an unconditional `continue` on accept failure (100% CPU spin on a persistent error such as handle exhaustion), and reported request failures **only in the HTTP response** â€” so if no client read it, the error vanished. | Partially | All detached work routed through `SafeTask.FireAndForget`. Accept loop uses `BackoffPolicy`. Failures logged server-side. `Stop()` made exception-safe so it cannot wedge `IsRunning`. | 7 in `SafeTaskTests` |
| SS-18 | Observability | 30 files | **105 sites logged `ex.Message` only** against 8 logging the full exception â€” discarding the type, stack trace and inner-exception chain, which is what makes production failures undiagnosable. | No | 27 Error-level sites mechanically converted to `Logger.WriteException`. 12 Error-level sites remain (non-uniform shapes) â€” see *Remaining risk*. | Assertion on chain preservation in `LoggerTests.WriteException_PreservesTypeMessageStackAndInnerChain` |

### Pre-alpha pass (SS-20 â€¦ SS-24)

Added when scoping a closed alpha with many concurrent players. That context re-ranks the
remaining work: **silent data corruption outranks crashes** (a crash gets reported; wrong XP
quietly poisons the very data an alpha exists to collect), and **concurrency bugs only appear at
player count**. Two of these are not exception-safety findings at all â€” they surfaced while
reviewing the same code for alpha readiness.

| ID | Subsystem | File:line | Risk / failure scenario | Severity | Remediation | Tests |
|---|---|---|---|---|---|---|
| SS-20 | Auth / security | `Database/Auth/AuthContext.cs:54` | **Built-in default administrator credential.** Any empty auth database was seeded with username `admin`, password `admin`, `Level = 255`, `Validated = true`, `Locked = false` â€” on a network-reachable auth server. Not an exception-safety issue; found while reviewing alpha readiness. | **CRITICAL (alpha-blocking)** | No built-in default remains. The bootstrap password must come from `AuthConfig.DefaultAdminPassword`; if unset or blank, **nothing is seeded** and the operator is told to run `auth.create`. Wired in both `Auth/Program.cs` and the Launcher bootstrap. Password is never logged. | 4 in `AuthContextModelTests` |
| SS-21 | Sector / security | `Sector/Config/GameConfig.cs:7` | The dev-control HTTP API defaulted to **enabled**, exposing unauthenticated endpoints including `/chat-command`, which executes commands as a selected character. Bound to loopback only, so not remotely reachable â€” but an unauthenticated admin channel should be opt-in, not on by default. | MEDIUM | Default flipped to `false`. Neither tracked `appsettings.sector.json` sets the key, so real deployments now get the safe default. **Local debugging must opt in** with `"EnableDevControl": true`. | `SectorConfigTests.GameConfig_Defaults_MatchHostExpectations` |
| SS-22 | Experience | `Game/Experience/ExperienceService.cs` (7 sites), `KillXpAward.cs:36,88` | Every XP/credit lookup swallowed asset failures with a bare `catch` commented *"Asset manager not initialized in unit tests"*, then returned a built-in approximation from `docs/XP.md`. In production that converts an asset problem into **silently wrong XP, credits and quest rewards** â€” undetectable until someone audits the numbers, by which point the character database is already wrong. A test convenience had become a production correctness bug. | **HIGH for alpha** | The fallback is kept (the server stays playable) but is no longer silent: `ExperienceService.FallbackCount` counts degraded lookups and each kind warns once with the underlying exception. Kill-XP drops and clonebase multiplier failures now log at Warning with the victim/CBID. Catches narrowed to exclude cancellation/OOM. | 6 in `ExperienceFallbackVisibilityTests` |
| SS-23 | Login | `Game/Managers/LoginManager.cs:27` | The session-expiry sweep enumerated the pending-login dictionary **outside** the lock and only took it to remove. A concurrent login threw "Collection was modified" mid-enumeration. Post-SS-09 this no longer kills the tick â€” `Guard.Run` catches it â€” but **the sweep aborts, so expired sessions accumulate** and reconnecting players are told they are already logged in. The window scales with live session count: invisible at 2 players, routine at 50. | **HIGH for alpha** | Selection and removal now happen under one lock. | 2 in `LoginManagerConcurrencyTests`; the concurrency test was verified to fail on the old code with **50 of 50 expired sessions surviving** |
| SS-24 | Combat / observability | `Game/Entities/Vehicle.cs:571`, 12 sites across `Game` | The weapon-fire path swallowed **every** send failure with a bare `catch` and no logging, so "my shots don't register" reports arrive with zero server-side evidence; one bad connection also aborted the send for every other player in scope. Separately, 12 Error-level sites still logged `ex.Message` only. | MEDIUM | Per-connection isolation via `Guard.ForEach`; failures recorded through a throttled reporter (`Vehicle.CombatSendFailureCount`, warning at most every 5s with the running total) so a hot path cannot flood the log. All 12 remaining sites converted to `Logger.WriteException`; packet-parse failures also moved Error â†’ **Warning**, since malformed client input is expected at a boundary and recoverable (same principle as SS-11). | Covered by existing combat/TNL suites |
| SS-25 | Discord module | `Discord/Commands/DiscordAccountCommands.cs`, `Discord/Abstractions/DiscordNetGateway.cs`, `Discord/DiscordBotService.cs`, `Launcher/Bootstrap/DiscordLauncherServerHost.cs` | Optional Discord gateway + slash-command path is an external boundary: a throwing handler, faulted Ready registration, presence timer, or stop/dispose path could otherwise tear down the shared Launcher process (Auth/Global/Sector). Detached gateway work must be observed (SS-17). Passwords and bot tokens must never appear in logs. | MEDIUM (when enabled) | Interaction dispatch wrapped in `Guard.Run`; Ready/slash/presence/stop use `SafeTask.FireAndForget` or contained catches with `Logger.WriteException`; host shutdown isolated with `Guard.Run`. Domain replies never echo passwords. Module off by default. | `PresenceAndCommandTests`, `DiscordBotServiceTests`, `AccountLinkServiceTests` |
| SS-26 | Auth / dispatch | `Auth/Network/AuthClient.Handlers.cs:14` | `AuthClient.HandlePacket` â€” the auth server's dispatch switch for client-controlled TCP packets â€” had **no try/catch**. A malformed packet whose handler throws (e.g. a Logout/ServerListExt with invalid session data while no account is bound dereferences `Account!` â†’ `NullReferenceException`) propagated out of the dispatch into the socket receive/update path, able to tear down the auth pump for every connected client. Same class of hole as SS-11 on the game side. | **HIGH for alpha** | Dispatch wrapped in `Guard.Run($"auth packet dispatch ({opcode})", â€¦)` so one bad packet fails that packet only and is reported via `Logger.WriteException`. Auth lifecycle is now structured-logged (`AuthLoginSucceeded`/`AuthLoginFailed` with reason, `AuthRedirectRequested`) under a per-client server-generated `SessionId` LogContext scope; passwords are never logged. | `AuthClientLoggingTests.HandlePacket_ThrowingHandler_IsContainedAtDispatchBoundary` â€” verified to fail with `NullReferenceException` escaping when the guard is reverted |
| SS-27 | Economy / persistence | `Game/Managers/LootManager.cs` `TryGiveCredits` | Kill-loot credit grants called `CurrencySync.AddCredits(persistence: null, â€¦)`, hitting the "no inventory persistence bound; balance not saved" branch: credits earned from kills applied in memory and were sent to the client, but **were never written to the character DB and vanished on restart** (silent data loss, invisible until a relog). | MEDIUM (silent data loss) | Grant now routes through `killer.Inventory.AddCredits(â€¦, CurrencyChangeReason.KillLoot)`, which binds the same `IInventoryPersistence` every other money mutation uses; the persistence-less `CurrencySync` call remains only as a fallback when no inventory is attached. Mutation is also visible in the audit trail as `CurrencyChanged` with `Reason=KillLoot`. | `LootManagerKillLootPersistenceTests.TryGiveCredits_PersistsBalanceThroughBoundInventoryPersistence` â€” verified to fail (`CreditsSaves` count 0) when the fix is reverted to `persistence: null` |
| SS-28 | Chat / admin authz | `Game/Chat/ChatCommandService.cs`, `Game/Managers/ChatManager.cs` | Mutating chat/GM commands (`/credits`, `/addItem`, `/warp`, `/kill`, `/level`, `/completeMission`, â€¦) had **zero permission checks**. Any connected player could run them. `Character.GMLevel` is populated from `Account.Level` but was never read. | **HIGH for alpha** | Flat gate `GMLevel >= 1` in both dispatch stages via `ChatAdminGate`. Denied â†’ `AdminCommandDenied` (SEC-001) + no state change; allowed â†’ `AdminCommandExecuted` (Audit). Null character (console/dev path) is treated as allowed for tooling. | `AdminCommandAuthzTests` â€” GMLevel 0 denied with no mutation; verified red when gate is bypassed |
| SS-29 | Sector / transfer security | `Game/TNL/TNLConnection.Sector.cs` `HandleTransferFromGlobalPacket` | Sector transfer key from Global is **not enforced** (historical TODO). A crafted transfer could in principle join a sector without a valid handoff. Full enforcement needs Global/Sector key agreement that is not ready for the playtest. | MEDIUM (accepted risk) | **Log-only:** emit `SecurityKeyMismatch` WARN (SEC-002) when the key â‰  expected; do **not** disconnect. Documented accepted risk until a shared key path lands. | Covered by sector handshake logging paths; no enforcement tripwire by design |
| SS-30 | World / instancing | `Game/Map/SectorMap.cs` `LeaveMap` disposal branch, `Game/Managers/MapManager.cs` `DisposeInstance` | Per-player instance disposal (starting areas 698/707/708) runs synchronously inside the owner's `LeaveMap`, i.e. on the logout/transfer teardown path (`SetMap` â†’ `EndCharacterSession` â†’ MainLoop). An unguarded throw during entity teardown would abort the leaving player's disconnect and could leak the dead map into the tick loops. | No | Registry unregistered **before** teardown; `Guard.Run` at both the LeaveMap call site and around `TearDownLocalEntities`; per-entity `try/catch` inside the sweep (same containment as the shared-map reset). Instance disposal never runs the shared-template `IsActive` restore â€” that write is cross-instance-visible (`MapData` is process-global). | `MapInstanceDisposalTests.SS30_Tripwire_EntityTeardownFaultDoesNotAbortDisposal` â€” verified red (registry leak + collections not cleared) before the fix; `InstanceDisposal_MustNotRestoreSharedTemplateState` pins the template-write exclusion |

---

## Deliberately unhandled

These must escape normal recovery. Documented per Â§9 of the audit brief.

| Condition | Behaviour | Rationale |
|---|---|---|
| `StackOverflowException` | Terminates the process | Cannot be caught in .NET at all. |
| `OutOfMemoryException` | Propagates through `Guard` and `BackoffPolicy` | Continuing after memory exhaustion is not safe; state is untrustworthy. |
| `OperationCanceledException` | Propagates through `Guard`; treated as non-failure by `SafeTask` | Cancellation is control flow, not failure. Swallowing it makes shutdown hang and loops spin through cancelled work. |
| Startup failures (invalid config, DB unreachable, missing assets) | Logged at `Fatal`, process exits 1 | Genuinely unrecoverable. SS-07 changed *how* they terminate (diagnosably), not *whether*. |
| Corrupted length framing on a socket | Connection dropped | A length-prefixed stream cannot be resynchronised after a bad prefix; guessing would desynchronise every later packet. |
| `Logger` internal failure | Swallowed in `Logger.EmergencyReport` | The single documented exception-swallowing site in the codebase: there is no remaining sink to report to, and rethrowing would defeat SS-06 entirely. |

---

## Remaining risk

### No-op catch bodies (10 in production, down from 17)

Verified by scanning 70 single-block catches. None is now an unexplained swallow:

**Intentional and documented (4)** â€” `Logger.cs:291` (emergency fallback, the one sanctioned
swallow), `CharContext.cs:311` (non-relational provider in tests), `AsyncLengthedSocket.cs:459`
and `DevControlServer.cs:65` (already-disposed on teardown).

**Low-risk, comment-explained (5)** â€” `AuthClient.cs:63`/`:118` (`ObjectDisposedException` on
timeout/close), `TossDebugLogger.cs:27` (best-effort debug output), `NpcInteractHandler.cs:105`
(cancellation), `ExplorationManager.cs:126` (XP award on discovery).

**MEDIUM, deferred (1)** â€” `AssetManager.cs:524`, boot-time; see below.

### MEDIUM â€” catalogued, not fixed

All remaining MEDIUM items are **asset/boot-time**: they occur once at startup on the operator's
own machine, are visible in the startup log, and are not player-facing at runtime. That is why
they were left out of the pre-alpha pass.

| Subsystem | File:line | Risk |
|---|---|---|
| Assets | `Game/Managers/Asset/TgaAreaMaskReader.cs:79` | `catch { remaining = long.MaxValue; }` â€” the failure path makes a subsequent bounds check **pass**. The most defective of the remaining items. |
| Assets | `Game/Managers/Asset/WADLoader.cs:35` | Whole-file `try`/`catch`: one bad clonebase row discards the entire WAD (contrast `GLMLoader`, which isolates per file). |
| Assets | `Game/Managers/Asset/GLMLoader.cs:53` | `FileStream.Read` return value ignored; a short read yields silently truncated asset data. |
| Assets | `Game/Managers/AssetManager.cs:524` | `catch { /* Ignore errors */ }` around continent-object loading; partial world data loads with no signal. |

Fixed since the first pass: `ExperienceService` and `KillXpAward` (SS-22), `Vehicle.cs:571` and
the last 12 `ex.Message` sites (SS-24), `LoginManager` (SS-23).

### Not an exception-safety finding, but open

**There is no connection cap or rate limit anywhere.** `MaxPlayers` exists only as a value
reported to the server list â€” it is never enforced â€” and the Communicator listens with
`backlog: int.MaxValue`. Acceptable for a *closed* alpha with invited players; must be addressed
before anything open.

### LOW â€” analyzer census

Analyzers are enabled as **warnings only** (`src/Directory.Build.props`, `src/.editorconfig`);
`TreatWarningsAsErrors` is off and `<Nullable>` is unchanged, so analysis cannot break the build.
Current census (warnings are catalogued, not suppressed):

| Rule | Count | Disposition |
|---|---:|---|
| CA2201 â€” do not throw reserved types (`Exception`) | 82 | Deferred. Forces callers into catch-all handling. Concentrated in `AutoCore.Game` (44). |
| CA1816 â€” `GC.SuppressFinalize` usage | 28 | Deferred; relates to the two finalizers hardened under SS-16. |
| CA2022 â€” inexact `Stream.Read` | 30 â†’ 2 fixed in production | Both production sites in `AsyncLengthedSocket` now check the returned count; remainder are in tests. |
| CA2008 â€” task without `TaskScheduler` | 2 | `AssetManager.cs:143` startup `ContinueWith`; low risk, startup-only. |
| CA1031 â€” broad catch | suggestion | **Deliberately not a warning.** A broad catch is correct at a boundary whose job is to prevent process termination. Promoting it would flag every deliberate boundary and train people to suppress it. Boundaries are reviewed by hand against this register. |

### Structural

* `AutoCore.Database` now references `AutoCore.Utils` so schema-migration failures can be logged.
  `AutoCore.Utils` has no project references, so the dependency is acyclic.
* `LauncherShutdownTests.Shutdown_DoesNotBindPorts` is flaky by construction (machine-wide
  listener count). It should be rewritten to assert on the coordinator rather than the machine.
* `AutoCore.Utils` line coverage was 19.93% at the last measurement; this work added 51 tests
  there, but a full coverage pass on that assembly is still outstanding.

---

## Conventions established

New exception-safety work continues the **`SS-nn`** series. When adding one:

1. Allocate the next id and record it in the table above.
2. Reference the id in the production comment explaining *why* the boundary exists.
3. Add a tripwire test whose XML doc names the id, and **verify it fails when the fix is
   reverted** â€” a guard with no failing test is not evidence of anything.

See `AGENTS.md` â†’ *Exception safety and crash resistance* for the working rules.
