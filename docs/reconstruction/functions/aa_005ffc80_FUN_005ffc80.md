# Function record: FUN_005ffc80

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc80` |
| **Canonical name** | `EmptyStub_Ret4` (Ghidra `FUN_005ffc80`) |
| **Address** | `0x005ffc80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared / multi-domain nop leaf |
| **Completion status** | **partial** — dual A/B **accept** (R11-009); prefer named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | **false** |

## Purpose

Shared empty leaf — `ret 4`. See named record for full seal.

## Signature (machine-corrected)

```c
void EmptyStub_Ret4(void *ignored_stack_arg); // ret 4
// Decompiler: void FUN_005ffc80(void) — CF empty, ABI incomplete
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.md`
- Annotated: `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/EmptyStub_Ret4.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005ffc80.cpp`
- Named record: `docs/reconstruction/functions/aa_005ffc80_EmptyStub_Ret4.md`
- Review A: `docs/reconstruction/reviews/A_aa_005ffc80_EmptyStub_Ret4.md`
- Review B: `docs/reconstruction/reviews/B_aa_005ffc80_EmptyStub_Ret4.md`
- Report: `docs/agents/task-dual-ab-005ffc80-r11-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Code callers** | `FUN_0064d9f0` |
| **DATA** | 100+ vtbl / pointer-table xrefs |

## Confidence

| Claim | Level |
|---|---|
| Control flow empty return | **High** |
| Machine ABI `ret 4` | **High** |
| Parameter semantic names | N/A (ignored) |
| Types | Tentative (ignored stack dword) |
