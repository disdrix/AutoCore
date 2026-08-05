# Function record: NpcMissionDialog_TeardownChildWidgetLists

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa320` |
| **Canonical name** | `NpcMissionDialog_TeardownChildWidgetLists` |
| **Ghidra name** | `FUN_008aa320` |
| **Address** | `0x008aa320` |
| **Body range** | `0x008aa320`–`0x008aa3ef` (exclusive end; **207** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client UI |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + vector offsets sealed; product list English / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md`, `reviews/B_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| **Last reviewed** | `2026-07-29` (W21-T) |

## Alias

- `FUN_008aa320` (Ghidra)

## Purpose

**Tear down two dynamic child-widget lists** on the NPC mission dialog:

For each non-null pointer in `dialog+0x72c..+0x730` and `dialog+0x73c..+0x740` vectors:

1. `child->vtbl+0x440()`
2. `dialog->vtbl+0xb0(child)`

Does **not** clear prepared response `+0x650`, free vector storage, or run dialog `vtbl+0x3ac` (caller does that next).

## Signature

```c
// ESI = NpcMissionDialog*; bare ret; void
void NpcMissionDialog_TeardownChildWidgetLists(void);
```

## Algorithm

See annotated + clean. Callees: pure virtuals only.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.md`
- Annotated: `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NpcMissionDialog_TeardownChildWidgetLists.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008aa320.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-008a0210-008aa320-w21t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | child `vtbl+0x440`; dialog `vtbl+0xb0` |
| **Callers (1)** | `Client_MissionDialog_FlushPreparedResponse` (`0x008ab8f0`) @ `0x008ab998` |

## Confidence

| Claim | Level |
|---|---|
| ESI dialog; bare ret | **High** |
| Two begin/end vectors + count formula | **High** |
| Virtual pair order | **High** |
| Role = child-list teardown on flush path | **High** |
| Product list English / vtbl method names | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_008ab8f0` Client_MissionDialog_FlushPreparedResponse
- Dialog vtbl base `PTR_FUN_00a4a51c` (Flush plate)
- Follow-on: dialog `vtbl+0x3ac`, `FUN_00792490`
