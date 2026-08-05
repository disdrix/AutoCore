# Function record: ListTrackedObj_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004be2a0` |
| **Canonical name** | `ListTrackedObj_CompleteDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_004be2a0` |
| **Address** | `0x004be2a0` |
| **Body** | `0x004be2a0`–`0x004be43c` (**412 B** / `0x19C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | large owned object complete dtor (list-tracked) |
| **Completion status** | **Dual-reviewed** W30-P — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for a large object: optional flag-gated list cleanup, decrement global trackers, unlink from intrusive DLL (`+0/+4`), free two buffer triples, run six member dtors, install base vtbl `PTR_LAB_009cb5cc` at `+0x10` and `+0x20`. Does **not** free `this`.

## Signature

```c
// ECX = this. SEH. Bare RET after ADD ESP,0x10. void.
void __fastcall ListTrackedObj_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00494700`, `FUN_00494530`, `FUN_00497a30`, `FUN_005b8000`, self |
| Callees | `operator_delete`, `FUN_004bf740`, self, `FUN_0074b580`×3, `FUN_00763f60`×3 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.md`
- Annotated: `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ListTrackedObj_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004be2a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004be2a0_ListTrackedObj_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004be2a0_ListTrackedObj_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004be2a0_FUN_004be2a0.md`

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| DLL unlink + global counts | **High** |
| Buffer offsets + member dtor offsets | **High** |
| Base vtbl install `009cb5cc` | **High** |
| Product class English | **Low** |
| Nested member type English | **Low** |
