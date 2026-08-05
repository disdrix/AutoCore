# Function record: Dword_FillN_ReturnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2f70` |
| **Canonical name** | `Dword_FillN_ReturnEnd_Inferred` |
| **Ghidra / prior** | `FUN_004e2f70` / `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e2f70` |
| **Address** | `0x004e2f70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic dword fill-n) |
| **Body size** | `0x2C` bytes (instruction-sealed through `ret 0x0C`) |
| **Completion status** | **Dual reviewed** — accept-with-gaps (2026-07-29, W16-B) |
| **Bit-for-bit / runtime / diff** | Static CF High; runtime open |

## Purpose

Leaf **fill-n** for 4-byte POD: write `*pValue` into `count` consecutive dwords at `dst`; return **end** pointer `dst + count` (byte end `dst + count*4`). Shared by MSVC-style `vector` insert/grow holes. **Not** memcpy (source pointer not advanced).

## Signature (decompiler + asm)

```c
uint32_t *Dword_FillN_ReturnEnd_Inferred(
    uint32_t *dst,
    int count,
    uint32_t *pValue);
// free function; ret 0x0C; ECX unused
```

## Control flow

1. If `count == 0` → return `dst`.
2. Else loop `count` times: `*dst++ = *pValue` (pValue fixed).
3. Return original `dst + count`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e2f70_FUN_004e2f70.md`
- Annotated: `docs/reconstruction/raw/aa_004e2f70_FUN_004e2f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Dword_FillN_ReturnEnd_Inferred.cpp`
- Ghidra twin: `docs/reconstruction/reconstructed-exact/FUN_004e2f70.cpp`
- Prior scaffold alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e2f70.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_004e2f70_FUN_004e2f70.md`

## Callers / callees

**Callees:** none.

**Callers:** multi-caller generic (vector insert paths; scaffold seed `CVOGSectorMap_AddCharacter` chain). OWN-ONLY: no live xref dump.

## Confidence

| Claim | Level |
|---|---|
| Fill-n CF / ret 0x0C / lea end | **High** |
| Not memcpy (src fixed) | **High** |
| Element stride 4 | **High** |
| Product demangled name | **Open** |
| Domain exclusivity | **Falsified** (shared util) |
