# Function record: FUN_004bcbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcbf0` |
| **Canonical name** | `ThreadSafeObjectList_Dtor` (see named record) |
| **Ghidra name** | `FUN_004bcbf0` |
| **Address** | `0x004bcbf0`–`0x004bcc31` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::util / lock-protected object list |
| **Completion status** | **Sealed** — dual A/B W25-C 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Structural: `ThreadSafeObjectList_Dtor`
- Full record: `functions/aa_004bcbf0_ThreadSafeObjectList_Dtor.md`

## Purpose

List destructor: vtbl install, PopFront-drain with payload delete, zero count, DeleteCriticalSection ×2.

## Signature

```c
void __fastcall FUN_004bcbf0(ThreadSafeObjectList *list);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.md`
- Annotated: `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bcbf0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_Dtor.cpp`
- Reviews: `A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`, `B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`

## Callers / callees

**Callees:** `FUN_0040b020`, `DeleteCriticalSection`  
**Callers:** `FUN_004bcc40`, `FUN_004d64d0`, `FUN_004bbc70`, `FUN_0058c850`, `Unwind@009a5750`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Layout / role | **High** |
| Product English | Inferred |
