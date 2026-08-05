# Function record: Mem_CopyBytes

| Field | Value |
|---|---|
| **Stable ID** | `aa_006380a0` |
| **Canonical name** | `Mem_CopyBytes` (structural; product/PDB open) |
| **Ghidra name** | `FUN_006380a0` |
| **Address** | `0x006380a0` |
| **Body span** | `006380a0`–`006380be` (31 B through bare `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `util` / memory |
| **Completion status** | **Dual A/B sealed** (W21-K 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `FUN_006380a0`
- Prior auto alias: `Named_CalleeOf_Named_CalleeOf_CVOGHBList_Tick_006380a0` (one caller family; not exclusive)
- Parent duals cite as **MemCopy** / payload copy after grow

## Purpose

Forward-only **byte-count POD copy** (memcpy semantics):

```c
// n dwords then residual bytes; dst, src, n
memcpy(dst, src, n);  // not memmove
```

Retail body is `rep movsd` + `rep movsb`. Used after heap realloc/grow to relocate old payload (e.g. `FUN_005b3370` GrowableArray_DoubleGrow, `FUN_005b3300` HB grow).

## Signature

```c
void __cdecl Mem_CopyBytes(void* dst, const void* src, unsigned n);
// bare ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006380a0_FUN_006380a0.md`
- Annotated: `docs/reconstruction/raw/aa_006380a0_FUN_006380a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_CopyBytes.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_006380a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006380a0_Mem_CopyBytes.md`
- Review B: `docs/reconstruction/reviews/B_aa_006380a0_Mem_CopyBytes.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_006380a0_FUN_006380a0.md` (superseded by this)

## Callers / callees

**Callees:** none (leaf).

**Callers (sample; 40+ xrefs):** `FUN_005b3300`, `FUN_005b3370`, `FUN_005d8960`, `FUN_005f31e0`, `FUN_00632180`, `FUN_0063f710`, `FUN_00640010`, `FUN_00640580`, `FUN_006416d0`, `FUN_00642d20`, `FUN_006430a0`, `FUN_006462a0`, `FUN_00647990`, `FUN_00659d90`, `FUN_0065a140`, `FUN_0065a230`, `FUN_00664230`, `FUN_00664300`, `FUN_006644e0`, `FUN_006f3900`, `FUN_006f3950`, …

## Confidence

| Claim | Level |
|---|---|
| Control flow dword-then-byte copy | **Confirmed** (bytes + decompile) |
| `__cdecl` dst/src/n order | **Confirmed** |
| Role = generic memcpy helper | **High** |
| Product English name | **Open** |
| Overlap safety = memcpy not memmove | **High** (forward `rep movs*`) |

## Dual verdict

**accept**
