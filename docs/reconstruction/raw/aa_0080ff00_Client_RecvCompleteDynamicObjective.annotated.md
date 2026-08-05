# Annotated low-level: Client_RecvCompleteDynamicObjective (`aa_0080ff00`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **VA** | `0x0080ff00` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_0080ff00_Client_RecvCompleteDynamicObjective.md` (capture 2026-07-23) |
| **Opcode** | **S2C `0x2070`** CompleteDynamicObjective (force complete) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// Packet handler; client object often in EDI (decompiler unaff_EDI)
void Client_RecvCompleteDynamicObjective(CompleteDynamicObjectivePacket* pkt /* param_1 */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `param_1` / pkt | 32-bit pointer | unsigned | stack/arg | Packet buffer |
| `unaff_EDI` | 32-bit pointer | unsigned | EDI | Client / game context |
| return | void | — | — | — |

### Packet layout (byte offsets on `param_1`)

| Offset | Width | Role |
|---|---|---|
| `+0x10` | **u32** | Objective id → active hash key and CompleteObjective arg0 |

(Other header fields before `+0x10` not used by this body.)

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| Historical name `Client_RecvObjectiveState` | **Wrong** — that name is `0x00809460` / opcode `0x2071` | **High** |
| `unaff_EDI + 0xe98` | Local character pointer | **High** |
| `character + 0x548` | Active objectives hash | **High** |
| Requirement `vtable+0x50` returns `3` | World/use-object requirement class (inferred) | **Probable** |
| `piVar1[6]` | Captured world target id for optional UseObject | **Probable** |
| `CompleteObjective(id, -1, -1, 1)` | Force complete; accept-all reward COID filter | **High** |
| UI `+0x107c` vcalls `+0x3d8/+0x448/+0x34c` | Same pair as RecvObjectiveState | **High** |
| `+0x10b0` dialog chrome | Hide/refresh when `+0x684 != 0` | **Probable** |
| `FUN_009197a0(0x41700000)` | `0x41700000` = float 15.0f bits; pick/mode helper | **Probable** |
| `Client_RefreshOpenMissionUiWindows` | Bulk journal/UI refresh | **High** (named) |
| Critical-section release chain | Interaction lock cleanup after world scan | **Tentative** naming |

**Always** calls CompleteObjective even if active-objective lookup misses (force path still runs).

---

## 3. Control flow

```text
FUN_0052d8b0(0, -1)

obj = Lookup(char+0x548, pkt.objectiveId)
worldTarget = -1
if obj:
  for each requirement:
    if req.vtable[+0x50]() == 3:
      worldTarget = req[6]; break

CompleteObjective(pkt.objectiveId, -1, -1, force=1)

refresh UI +0x107c
if dialog +0x10b0 open: hide/refresh helpers
if worldTarget != -1: find world object → Client_SendUseObject (+ CS cleanup)
Client_RefreshOpenMissionUiWindows
optional UI +0x1034 → FUN_0090cbc0
```

| Branch | Effect |
|---|---|
| Active obj miss | worldTarget stays -1; CompleteObjective still called |
| No type-3 requirement | worldTarget -1; skip UseObject |
| World object match | SendUseObject |
| Dialog not open | Skip chrome hide path |

---

## 4. Side-effect order

1. Mission UI clear helper.
2. Read-only active-hash + requirement scan.
3. **CompleteObjective** (full advance/final side effects).
4. UI refresh / dialog chrome.
5. Optional UseObject + CS release.
6. Bulk mission UI windows + secondary UI.

---

## 5. Protocol note (external to body)

Dialog turn-in runs **local** CompleteObjective in `Client_MissionDialogHandleButton`. Server must **not** also send `0x2070` for the same completion (missionState.md / missionHandler.md). Body alone does not send packets proving that policy — architectural.

---

## 6. Open questions

- Exact requirement type enum for vtable+0x50 value `3`.
- Identity of `FUN_008af180` / `FUN_008a0370` / `FUN_0090cbc0`.
- Whether CompleteObjective thiscall character is implicit global vs client+0xe98 (decompiler elides this).
- Full 0x2070 header layout beyond `+0x10`.
