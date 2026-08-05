# Function record: EmptyRet

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056f570` |
| **Canonical name** | `EmptyRet` |
| **Ghidra name** | `FUN_0056f570` |
| **Address** | `0x0056f570` |
| **Body range** | `0x0056f570`–`0x0056f570` (1 byte `c3`; exclusive end `0x0056f571`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared / multi-domain nop leaf |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0056f570_EmptyRet.md`, `reviews/B_aa_0056f570_EmptyRet.md` |
| **Last reviewed** | `2026-07-29` (W17-P) |

## Alias

- `FUN_0056f570` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0056f570` (auto parent-seed — **misleading**; prefer `EmptyRet`)

## Purpose

Shared **empty leaf**: single-byte `RET`. Body performs no work. Observed roles via xrefs only:

1. Default empty **vtable** methods (hundreds of DATA slots with LE `70 f5 56 00`).
2. MSVC **EH Unwind** / vector ctor-dtor iterators for trivial types.
3. Call sites that look like **debug prints** (format strings) — args discarded.

## Signature

```c
void EmptyRet(void);   // bare ret; ignores any this / stack args callers may pass
```

## Algorithm

1. `return;`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.md`
- Annotated: `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EmptyRet.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0056f570.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0056f570-emptyret-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | 100+ listed by Ghidra (mostly Unwind_*); also LED helpers, EH vector paths, vtbl DATA |
| **DATA sample** | Base HB vtbl `0x009cdfb0` slot 7 (`0x009cdfcc`) = this |

## Confidence

| Claim | Level |
|---|---|
| Body is pure `ret` (`c3`) | **High** |
| No side effects | **High** |
| Shared multi-role nop (not domain-specific) | **High** |
| Product/PDB symbol | Open |
| Exhaustive DATA-slot census | Open (not needed for CF) |

## Related

- `aa_0051b850` CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget — **overrides** base slot 7
- `aa_004f3700` VehicleEntity_DrivePathNoOp_Inferred — **different** empty-ret VA
