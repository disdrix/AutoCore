# Function record: Com_BstrHolder_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419e20` |
| **Canonical name** | `Com_BstrHolder_Release` |
| **Ghidra name** | `FUN_00419e20` |
| **Address** | `0x00419e20` |
| **Body range** | `0x00419e20`–`0x00419e60` (64 bytes through `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `crt-com` / MSVC BSTR smart-holder |
| **Completion status** | **partial** — dual A/B **accept**; CF + ESI ABI + 0xC layout sealed; product class name + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00419e20_Com_BstrHolder_Release.md`, `reviews/B_aa_00419e20_Com_BstrHolder_Release.md` (2026-07-29 W22-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00419e20`
- `Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_00419e20` (legacy parent-seed)
- Role: interlocked release of create-side holder `FUN_00419ca0`

## Purpose

**Release** a 12-byte BSTR holder:

1. `InterlockedDecrement` on `holder+8`.
2. If non-zero: return current refcount at `+8`.
3. If zero: `SysFreeString(+0)` if set; `operator_delete[](+4)` if set; `operator_delete(self)`; return **0**.

## Signature

```c
// ESI-this; no stack formals; ret (C3)
LONG Com_BstrHolder_Release(ComBstrHolder *self /* ESI */);
```

## Layout

| Offset | Field |
|---|---|
| `+0` | `BSTR` |
| `+4` | secondary buffer* (`operator_delete[]`) |
| `+8` | `LONG` refcount |

## Algorithm

See clean `Com_BstrHolder_Release.cpp` and raw re-verify byte section.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00419e20_FUN_00419e20.md`
- Annotated: `docs/reconstruction/raw/aa_00419e20_FUN_00419e20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Com_BstrHolder_Release.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00419e20.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00419e20_FUN_00419e20.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0099a8e0-00419e20-w22l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `InterlockedDecrement`, `SysFreeString`, `operator_delete[]` @ `0x0048981c`, `operator_delete` @ `0x00489822` |
| **Callers** | `FUN_00419db0`, `FUN_00419ed0`, `FUN_00419f60`, `FUN_007b87c0`…`FUN_007b8de0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| ESI-this / no stack args | **High** |
| Layout +0/+4/+8 size 0xC | **High** (create sibling + bytes) |
| Array-delete of +4 | **High** |
| Decompiler “no return” on delete | **Confirmed residual** (false) |
| Product English class name | **Inferred** |
| Runtime / differential | Open |

## Related

- `aa_00419ca0` Com_BstrHolder_CreateFromOleStr_Inferred — create sibling
- `FUN_00419db0` — release-if-nonnull slot helper
