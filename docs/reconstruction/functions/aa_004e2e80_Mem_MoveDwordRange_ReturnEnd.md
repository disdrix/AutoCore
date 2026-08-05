# Function record: Mem_MoveDwordRange_ReturnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2e80` |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004e2e80` |
| **Address** | `0x004e2e80` |
| **Body span** | `004e2e80`–`004e2eaa` (42 B through `ret 0xC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `stl-helpers` |
| **Completion status** | **Dual A/B sealed** (W19-C 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `FUN_004e2e80`
- Prior auto alias: `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e2e80` (one caller family; not exclusive)

## Purpose

Move a **dword-aligned** half-open range `[srcBegin, srcEnd)` into `dest` via `memmove`, then return `dest + byteCount`. Size is `((srcEnd-srcBegin)>>2)*4`. Generic STL/vector relocate helper for POD 4-byte elements.

## Signature

```c
void * __stdcall Mem_MoveDwordRange_ReturnEnd(void *srcBegin, int srcEnd, void *dest);
// ret 0xC
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.md`
- Annotated: `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ReturnEnd.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004e2e80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_004e2e80_FUN_004e2e80.md` (superseded by this)

## Callers / callees

**Callees:** `memmove` (IAT).

**Callers (sample; 30+):** `FUN_004e39d0`, `FUN_004073a0`, `FUN_0040f5b0`, `FUN_00429970`, `FUN_004442c0`, `FUN_004490a0`, `FUN_004507a0`, `FUN_0049c8a0`, `FUN_004a6f70`, `FUN_004bf830`, `FUN_004c2bb0`, `FUN_00539810`, `FUN_005438c0`, `FUN_00548210`, `FUN_00596770`, `FUN_005969f0`, `FUN_00596b40`, `FUN_00596c90`, `FUN_00602920`, `FUN_00604500`, `FUN_0068c060`, …

## Confidence

| Claim | Level |
|---|---|
| Control flow / size math / memmove / return end | **Confirmed** (bytes + decompile) |
| `__stdcall` `ret 0xC` | **Confirmed** |
| Role = dword-range relocate helper | **High** |
| Product STL English name | **Open** |

## Dual verdict

**accept**
