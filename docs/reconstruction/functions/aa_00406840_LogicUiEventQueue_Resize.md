# Function record: LogicUiEventQueue_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406840` |
| **Canonical name** | `LogicUiEventQueue_Resize` |
| **Ghidra name** | `FUN_00406840` |
| **Address** | `0x00406840`–`0x004068e7` (168 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-logic-ui / event queue |
| **Completion status** | **dual-sealed** W24-E 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Resize Logic-UI event queue to `newCount` with fill-value (stride 0x138).

## Signature

```c
void __fastcall LogicUiEventQueue_Resize(void* queue, uint32_t newCount /*EAX*/, /* Event[0x138] on stack */);
// RET 0x138
```

## Artifacts

See `aa_00406840_FUN_00406840.md` for full table + A/B paths.
