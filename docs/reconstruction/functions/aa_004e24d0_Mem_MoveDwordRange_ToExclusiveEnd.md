# Function record: Mem_MoveDwordRange_ToExclusiveEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e24d0` |
| **Canonical name** | `Mem_MoveDwordRange_ToExclusiveEnd` |
| **Ghidra name** | `FUN_004e24d0` |
| **Address** | `0x004e24d0` |
| **Body range** | `0x004e24d0`–`0x004e24f3` (exclusive end; **35** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | stl-helpers / vector relocate |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + memmove sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md`, `reviews/B_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| **Last reviewed** | `2026-07-29` (W20-H) |

## Alias

- `FUN_004e24d0` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e24d0` (auto parent-seed — **misleading product claim**)
- Residual: MSVC internal vector relocate helper spelling unknown

## Purpose

**Dword-range relocate to exclusive end:** move half-open `[srcBegin, srcEnd)` via `memmove` so the moved block **ends at** `destEndExcl`:

```
size = ((srcEnd - srcBegin) >> 2) * 4;
memmove(destEndExcl - size, srcBegin, size);
```

Used by many `std::vector`-style in-place insert paths to open a hole (right-shift tail).

## Signature

```c
// cdecl; bare ret; void
void Mem_MoveDwordRange_ToExclusiveEnd(void *srcBegin, int srcEnd, int destEndExcl);
```

## Algorithm

See annotated + clean. Sole callee: CRT `memmove`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.md`
- Annotated: `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ToExclusiveEnd.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e24d0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e24d0-0056c0a0-w20h-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `memmove` only (IAT `0x009c652c`) |
| **Callers** | 25 code xrefs — vector insert/grow (`FUN_004073a0`, `FUN_004507a0`, `FUN_004e39d0`, `FUN_005064e0`, `FUN_00539810`, `FUN_004bf830`, …) |

## Confidence

| Claim | Level |
|---|---|
| Size = `((end-begin)>>2)*4` | **High** |
| dest = exclusiveEnd − size | **High** |
| Bare `ret` cdecl (not stdcall) | **High** |
| Sole memmove | **High** |
| Distinct from `aa_004e2e80` / `aa_00506430` | **High** |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_004e2e80` `Mem_MoveDwordRange_ReturnEnd` — forward dest, return end, `ret 0xC`
- `aa_00506430` — same forward pattern as 004e2e80 (near-clone)
- Vector insert duals that call this for in-place tail shift
