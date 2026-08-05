# Function record: Mem_FillDwordN_ReturnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004651d0` |
| **Canonical name** | `Mem_FillDwordN_ReturnEnd` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004651d0` |
| **Address** | `0x004651d0` |
| **Body span** | `004651d0`–`004651f0` (**33 B** through bare `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `stl-helpers` / POD fill |
| **Completion status** | **Dual A/B sealed** (W22-T 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `FUN_004651d0`
- Role: count-based dword fill returning write end (vector insert-N helper)

## Purpose

Fill **N** consecutive **dwords** at `dest` with the value at `*value` (re-read each loop iteration). Return **write end** (`dest + N`) so callers can chain a suffix `memmove` after an insert hole is filled during vector realloc.

## Signature

```c
// Custom register ABI at call sites:
//   EDI = dest, ESI = count, EDX = value*, bare ret, EAX = dest+count
uint32_t *Mem_FillDwordN_ReturnEnd(uint32_t *dest, int count, uint32_t const *value);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004651d0_FUN_004651d0.md`
- Annotated: `docs/reconstruction/raw/aa_004651d0_FUN_004651d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_FillDwordN_ReturnEnd.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004651d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004651d0_Mem_FillDwordN_ReturnEnd.md`
- Review B: `docs/reconstruction/reviews/B_aa_004651d0_Mem_FillDwordN_ReturnEnd.md`
- Scaffold record: `docs/reconstruction/functions/aa_004651d0_FUN_004651d0.md`

## Callers / callees

**Callees:** none (leaf).

**Callers:** `FUN_00456960` (×2), `FUN_00429970` (×2), `FUN_00419880` (×2) — dword vector insert-N family.

## Confidence

| Claim | Level |
|---|---|
| Fill-N from `*EDX`, count ESI, dest EDI | **Confirmed** (bytes + decompile) |
| Return `dest+count` via `lea eax,[edi+esi*4]` | **Confirmed** |
| Leaf / bare `ret` / no stack args | **Confirmed** |
| Product MSVC English name | **Open** |

## Dual verdict

**accept**
