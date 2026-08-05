# Function record: UI_MissionJournal_SelectMission_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829b20` |
| **Canonical name** | `UI_MissionJournal_SelectMission_Inferred` |
| **Address** | `0x00829b20` |
| **Body range** | `0x00829b20` – `0x00829ca5` (0x185 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / missions-progression / mission journal |
| **Calling convention** | context in **EAX**; mission* in **EDI**; plain **`ret`**; void |
| **Completion status** | **Dual A/B sealed** — CF + ABI + string + ready-check framing; color residuals open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` |
| **Dual B** | `reviews/B_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W24-J) |

## Alias

- Ghidra: `FUN_00829b20`
- Prior auto: `Named_CalleeOf_Client_UpdateMissionJournal_00829b20`

## Purpose

Apply a **mission selection** to the mission-journal UI:

1. Gate on context virtual `vtbl+0x3d8` and non-null mission.
2. Format title `"[%d] %s"` from mission level (@+0x11c) + name (@+0x14c path).
3. When local character present: call `CVOGCharacter_IsMissionJournalReady` then `FUN_00829ac0` (list/objective refresh).
4. Sync secondary chrome color from title.
5. Store `selectedMissionId = *mission` at context `+0x500`.

## Signature

```c
void UI_MissionJournal_SelectMission_Inferred(
    /*EAX*/ UI_MissionJournalContext* ctx,
    /*EDI*/ MissionObject* mission);
/* plain ret */
```

## Layout

### Journal context

| Offset | Role |
|---:|---|
| `+0x500` | selectedMissionId (written) |
| `+0x508` | title label widget* |
| `+0x50C` | secondary chrome widget* |

### Mission object

| Offset | Role |
|---:|---|
| `+0x000` | mission id |
| `+0x11C` | level (int16) |
| `+0x14C` | name source |

## Machine seal (`read_memory` 2026-07-29)

| Item | Evidence |
|---|---|
| Body | `00829b20`–`00829ca5` |
| Entry | `mov esi,eax`; `call [vtbl+0x3d8]`; `test edi,edi` |
| String | `"[%d] %s"` @ `0x00a4abb4` |
| Ready call | `00829c5c` → `0052b3b0` (`CVOGCharacter_IsMissionJournalReady`) |
| List helper | `00829c61` → `00829ac0` |
| Store id | `mov [esi+0x500], [edi]` before epilog |

## Callers

| Caller | Site | Role |
|---|---:|---|
| `Client_UpdateMissionJournal` | `0x008ae4b9` | active missions entries |
| `Client_UpdateMissionJournal` | `0x008ae6b8` | new missions entries |

## Callees

| VA | Name |
|---:|---|
| `0x0052b3b0` | `CVOGCharacter_IsMissionJournalReady` |
| `0x00829ac0` | journal list refresh helper |
| `0x007a69d0` / `0x007a6de0` | name string helpers |
| `0x0092d580` | color prep residual |
| `0x006a3db0` | float→byte residual (×3) |
| IAT | `sprintf` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829b20_FUN_00829b20.md` (+ W24-J append)
- Annotated: `docs/reconstruction/raw/aa_00829b20_FUN_00829b20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionJournal_SelectMission_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00829b20.cpp`

## Confidence

| Claim | Level |
|---|---|
| Function boundary + body size | **High** |
| ABI EAX-ctx + EDI-mission + plain ret | **High** |
| Title format string | **High** |
| IsMissionJournalReady framing | **High** (rel32 + sibling dual) |
| selectedMissionId @ +0x500 | **High** |
| Product English method name | **Inferred** |
| Mission field English (+0x11c/+0x14c) | **Inferred** |
| Color channel formulas | **Open** (residual) |
| Runtime / bit-exact | **Open** |

## Open questions

1. Product method name on journal panel class.
2. Product field names for mission level/name offsets.
3. Whether `FUN_00829ac0` uses ready AL (out of ownership).
4. Full color dual for `FUN_0092d580` / `FUN_006a3db0`.
5. Runtime / differential.
