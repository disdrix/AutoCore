# Function record: Mem_MoveDwordRange_ReturnEnd_EcxEax

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c7c0` |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd_EcxEax` (structural; product/PDB open) |
| **Ghidra name** | `FUN_0040c7c0` |
| **Address** | `0x0040c7c0` |
| **Body span** | `0040c7c0`–`0040c7e2` (**35 B** through `ret 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `stl-helpers` / POD relocate |
| **Completion status** | **Dual A/B sealed** (W22-T 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `FUN_0040c7c0`
- Prior auto aliases: `Named_CalleeOf_Named_CalleeOf_Named_assManager_0040c7c0`, `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0040c7c0` (caller-family provenance only; not exclusive role names)
- Algorithm twin: `Mem_MoveDwordRange_ReturnEnd` (`aa_004e2e80`)

## Purpose

Move a **dword-aligned** half-open range `[srcBegin, srcEnd)` into `dest` via `memmove`, return `dest + byteCount`. Size is `((srcEnd-srcBegin)>>2)*4`. Used by vector insert-N / grow paths that prefer **ECX/EAX/stack** ABI over full stdcall.

## Signature

```c
// Retail: ECX=srcBegin, EAX=srcEnd, push dest; ret 4; EAX=dest+size
void *Mem_MoveDwordRange_ReturnEnd_EcxEax(void *srcBegin, int srcEnd, void *dest);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040c7c0_FUN_0040c7c0.md` (scaffold + W22-T append)
- Annotated: `docs/reconstruction/raw/aa_0040c7c0_FUN_0040c7c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ReturnEnd_EcxEax.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0040c7c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040c7c0_FUN_0040c7c0.md`

## Callers / callees

**Callees:** `memmove` (IAT `0x009c652c`).

**Callers:** `FUN_00456960` (×2), `FUN_00419880` (×4), `FUN_0043a090` (×2), `FUN_0043a1d0` (×2).

## Confidence

| Claim | Level |
|---|---|
| Size math / memmove / return end | **Confirmed** (bytes + decompile) |
| ECX begin / EAX end / stack dest / `ret 4` | **Confirmed** |
| Role = dword-range relocate helper | **High** |
| Product STL English name | **Open** |

## Dual verdict

**accept**
