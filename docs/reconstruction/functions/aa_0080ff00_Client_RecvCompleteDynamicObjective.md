# Function record: Client_RecvCompleteDynamicObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **Canonical name** | `Client_RecvCompleteDynamicObjective` |
| **Address** | `0x0080ff00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (cross-link: interaction-activation UseObject) |
| **Opcode** | **S2C `0x2070`** CompleteDynamicObjective |
| **Calling convention** | Packet pointer stack arg (`param_2` from PacketDispatch); **client in EDI** |
| **Sole caller** | `Client_PacketDispatch` @ `0x00815710` — `case 0x2070` |
| **Completion status** | **Human-refined clean** + dual A/B (2026-07-23) + **dual residual sealed 2026-07-29** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Server-driven **force-complete** handler. Always calls

```text
CVOGReaction_CompleteObjective(localChar, objectiveId @ packet+0x10, -1, -1, force=1)
```

then refreshes mission UI/dialog chrome, optionally `Client_SendUseObject` when a type-`3` requirement captured a world target id that matches a nearby/listed object, then bulk-refreshes open mission windows.

**Not** progress-only — that is `Client_RecvObjectiveState` @ `0x00809460` (opcode **0x2071**).

Historical misname: was labeled `Client_RecvObjectiveState`; corrected.

## Signature

```c
// Packet handler. Client/game object in EDI (handler register residual).
// Dispatch: case 0x2070 → Client_RecvCompleteDynamicObjective(param_2)
void Client_RecvCompleteDynamicObjective(void* pPacket /* stack */);
// Effective character:
//   CVOGCharacter* localChar = *(CVOGCharacter**)(client_EDI + 0xe98);
```

## Packet map

| Offset | Field | Width | Notes |
|---|---|---|---|
| `+0x10` | objective id | u32 | Active-objectives hash key **and** CompleteObjective arg0 |

Body does not read other packet fields.

## Behavioral summary

1. **`FUN_0052d8b0(localChar, 0, -1)`** — thiscall; with missionId=`-1` clears character tree at **`+0x50c`**; flag `0` skips ResolveObjectTarget side path.
2. Lookup active objective `CNDHash_LookupByKey(char+0x548, id@+0x10)`.
3. If found: scan requirement array `obj+0x158..+0x15c`; first req with **`vtbl+0x50() == 3`** → capture **`req[6]`** as `worldTarget` (else `-1`).
4. **Always** `CVOGReaction_CompleteObjective(localChar, id, 0xFFFFFFFF, 0xFFFFFFFF, force=1)` — call site loads **ECX = [EDI+0xe98]** (sealed 2026-07-29).
5. Refresh mission UI controller `client+0x107c` (vcalls `+0x3d8` / `+0x448` / `+0x34c` when visible).
6. If dialog chrome `client+0x10b0` open (`+0x684 != 0`): `FUN_008af180(0)`, `FUN_008a0370()`, optional child `+0x664` vcall `+0x480`.
7. If `worldTarget != -1`:
   - Prefer **`FUN_009197a0(15.0f)`** (`0x41700000` bits) — nearest world object / AutoPatrol waypoint within **radius 15**;
   - Match `*( *(obj+0xa8) + 0x34 ) == worldTarget` → **`Client_SendUseObject`** (C2S **0x2072**);
   - Else list-iterate `FUN_004294f0` / `FUN_004022a0` for same id match; CS release path on char interaction lock.
8. **`Client_RefreshOpenMissionUiWindows(client)`**; optional secondary UI `client+0x1034` → `FUN_0090cbc0`.

## Sealed call-site bytes (residual 2026-07-29)

| Site | Bytes / meaning |
|---|---|
| Entry clear | `mov ecx,[edi+0xe98]; push -1; push 0; call FUN_0052d8b0` |
| CompleteObjective `@0x0080ff80+` | `mov edx,[pkt+0x10]; mov ecx,[edi+0xe98]; push 1; push -1; push -1; push edx; call 0x00533f90` |
| Near pick | `push 0x41700000; call FUN_009197a0` then compare `*(obj+0xa8)+0x34` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Opcode / sole dispatch binding | **High** | PacketDispatch case `0x2070`; sole caller (residual) |
| Force CompleteObjective args + this=char | **High** | Literals + ECX load at call site |
| Active hash `char+0x548` | **High** | Consistent mission layout + CompleteObjective |
| Always-call even on hash miss | **High** | CF order; no miss-gate |
| `FUN_009197a0` = 15.0f nearest-object | **High** | Decompile radius² + immediate (residual) |
| `FUN_0052d8b0` = clear `char+0x50c` tree | **High** | thiscall + body when id=-1 (residual) |
| World id `*(obj+0xa8)+0x34` | **High** | Shared with SendUseObject |
| Req type `3` enum identity | **Tentative / Probable** | Scan sealed; full enum open |
| UI object formal names | **Tentative** | vtable offsets only |
| Overall static | **High** | Dual + residual |

## Open questions

- Full requirement-type enum for `vtbl+0x50` value `3` (Collect ctor is type **2**; type **3** not fully named here).
- Exact field name/role of `req[6]` beyond world-id compare key.
- Formal names for `FUN_008af180` / `FUN_008a0370` / `FUN_0090cbc0` and dialog chrome object.
- Runtime force-complete + optional UseObject capture; differential / bit-exact.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| Annotated | `raw/aa_0080ff00_Client_RecvCompleteDynamicObjective.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvCompleteDynamicObjective.cpp` |
| Dual A (2026-07-23) | `reviews/A_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| Dual B (2026-07-23) | `reviews/B_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| Dual A residual (2026-07-29) | `reviews/A_aa_0080ff00_Client_RecvCompleteDynamicObjective_residual.md` |
| Dual B residual (2026-07-29) | `reviews/B_aa_0080ff00_Client_RecvCompleteDynamicObjective_residual.md` |
| Callee | `functions/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| UseObject | `functions/aa_00916740_Client_SendUseObject.md` |
| Dispatch | `functions/aa_00815710_Client_PacketDispatch.md` |
| Sibling progress | `functions/aa_00809460_Client_RecvObjectiveState.md` |
| Prior art | `docs/missionState.md`, `docs/missionHandler.md` |
