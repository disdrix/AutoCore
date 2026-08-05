# Function record: FUN_004be2a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004be2a0` |
| **Canonical name** | `FUN_004be2a0` (scaffold) |
| **Structural name** | `ListTrackedObj_CompleteDtor` |
| **Address** | `0x004be2a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | large owned object complete dtor |
| **Completion status** | **Dual-reviewed** W30-P — see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

Scaffold plate `Named_CalleeOf_Named_VOG_DEBUG_STOP_004be2a0` — **rejected** as product identity (W30-P). Role is complete dtor of list-tracked owned objects (Elem0x28 owned@+0x24, etc.).

## Purpose

See `aa_004be2a0_ListTrackedObj_CompleteDtor.md`.

## Signature (decompiler-derived)

```c
void __fastcall FUN_004be2a0(int *param_1)
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004be2a0_ListTrackedObj_CompleteDtor.md`
- Raw / annotated / clean / dual A/B under `docs/reconstruction/`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile + bytes | High |
| Complete-dtor pairing with operator_delete | High (callers) |
| Product types | Tentative / open |
