# Function record: LogicUiEventQueue_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_004076a0` |
| **Canonical name** | `LogicUiEventQueue_InsertN` |
| **Ghidra name** | `FUN_004076a0` |
| **Address** | `0x004076a0`–`0x00407991` (754 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-logic-ui / event queue |
| **Completion status** | **dual-sealed** W23-B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Insert `count` copies of a 0x138-byte Logic-UI event into the queue vector at `insertAt`, growing capacity when needed (MSVC 1.5× policy) or shifting in place.

## Signature

```c
void __thiscall LogicUiEventQueue_InsertN(void* queue, void* insertAt, uint32_t count, const void* valueSrc);
// RET 0xC
```

## Artifacts

See `aa_004076a0_FUN_004076a0.md` for full table + A/B paths.
