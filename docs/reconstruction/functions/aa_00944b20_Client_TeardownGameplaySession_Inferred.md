# Function record: Client_TeardownGameplaySession_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944b20` |
| **Canonical name** | `Client_TeardownGameplaySession_Inferred` |
| **Ghidra name** | `FUN_00944b20` |
| **Address** | `0x00944b20`–`0x00944d03` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-session / login / return-to-login |
| **Classification** | worker (session teardown orchestrator) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; ABI + full/partial branches sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Tear down gameplay / UI session state on the global client object. Invoked from login-fail (`RecvPlayFail`), account-kicked, auth return-to-login, and missing-region-content abort. `fullTeardown!=0` releases five UI COM widgets and runs audio/mission/map cleanup; both modes clear `+0xf44` buffer and common leave flags.

## Signature (sealed)

```c
// this in EAX (not ECX); stack char; RET 4
void Client_TeardownGameplaySession_Inferred(void *self /*EAX*/, char fullTeardown);
```

| Param | Location | Meaning |
|---|---|---|
| `self` | `EAX` on entry → `ESI` | client main object (typically `0x00d1a840`) |
| `fullTeardown` | `[esp+4]` | non-zero → deep UI/session wipe |
| return | — | void |

## Key offsets (this)

| Offset | Role |
|---|---|
| `+0x309c / +0x30a4 / +0x30a8 / +0x30ac / +0x30b0` | UI COM* slots (Release via vtbl+4) |
| `+0x30b4..+0x30bf` | paired ready/clear flags for those slots |
| `+0x31ec` | gate for `FUN_005742a0` |
| `+0x31f0` | buffer* zeroed `0x82` dwords then `*buf = -1` |
| `+0xde8` | arg to `FUN_0079e7d0` |
| `+0xf44` | heap block `delete[]` always |
| `+0x113` / `+0x134` | cleared always |
| `+0xf40` / `+0xf38` | equality gate for leave helpers |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.md`
- Annotated: `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_TeardownGameplaySession_Inferred.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_00944b20.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00944b20_Client_TeardownGameplaySession_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00944b20_Client_TeardownGameplaySession_Inferred.md`
- Report: `docs/agents/task-dual-ab-004bb010-00944b20-w17t-report.md`

## Callers / callees

**Callees (17):** `FUN_007fc970`, `FUN_007fc360`, `Client_GetMissionCompleteAudioTable`, `FUN_007246d0`, `FUN_005742a0`, `FUN_00943db0`, `FUN_0079e7d0`, `FUN_00943b80`, `FUN_00442fa0`, `FUN_00410420`, `operator_delete[]`, `FUN_008076c0`, `FUN_00801c50`, `FUN_009302b0`, `FUN_00937560`, `FUN_0048f370`, `FUN_009133a0`.

**Callers:**

- `Client_RecvLoginCallback_3` `0x008227f0`
- `Client_RecvLoginCallback_7` `0x008226f0` (`RecvPlayFail`)
- `Client_RecvLoginCallback_9` `0x008226b0` (`RecvAccountKicked`, tail-JMP)
- `FUN_00812de0` (Auth return-to-login / connection terminated path)
- `FUN_009463b0` (reinitPhysics missing-content → message + teardown)

**Xrefs:** 7.

**Globals:** `DAT_00d1b77c` (session singleton gate); call-site `this` often `0x00d1a840`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| EAX-this + stack char + `RET 4` | **High** |
| Full vs partial branch split | **High** |
| Five COM slot offsets / flag pairs | **High** |
| `0x82`-dword wipe + `-1` head | **High** |
| Product names of nested callees / widgets | **Tentative** |
| Unit English name | **Probable** (`_Inferred`) |
