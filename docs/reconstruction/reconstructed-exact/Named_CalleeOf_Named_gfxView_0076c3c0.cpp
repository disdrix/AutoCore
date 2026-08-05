// =============================================================================
// Named_CalleeOf_Named_gfxView_0076c3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c3c0
// Callee of Named_gfxView (+7 other named callers)
// Address:   0x0076c3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxView (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT44×2, ROUND×2, FUN_0076c3c0, rdtsc.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxView (+7 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_gfxView_0076c3c0(int param_1)



{

  uint64_t uVar1;

  double dVar2;

  uint uVar3;

  uint64_t local_8;

  

  if (*(char *)(param_1 + 0x18) != '\0') {

    uVar1 = rdtsc();

    uVar3 = ((int)((ulonglong)uVar1 >> 0x20) - *(int *)(param_1 + 0xc)) -

            (uint)((uint)uVar1 < *(uint *)(param_1 + 8));

    local_8 = CONCAT44(uVar3,(uint)uVar1 - *(uint *)(param_1 + 8)) & 0x7fffffffffffffff;

    dVar2 = (double)local_8;

    local_8 = ((ulonglong)uVar3 & 0x80000000) << 0x20;

    local_8._0_4_ =

         (uint32_t /* width from decompiler */)

         (longlong)ROUND((-(double)(longlong)local_8 + dVar2) * *(double *)(param_1 + 0x28));

    return (uint32_t /* width from decompiler */)local_8;

  }

  uVar3 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) -

          (uint)(*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 8));

  local_8 = CONCAT44(uVar3,*(uint *)(param_1 + 0x10) - *(uint *)(param_1 + 8)) & 0x7fffffffffffffff;

  dVar2 = (double)local_8;

  local_8 = ((ulonglong)uVar3 & 0x80000000) << 0x20;

  local_8._0_4_ =

       (uint32_t /* width from decompiler */)

       (longlong)ROUND((-(double)(longlong)local_8 + dVar2) * *(double *)(param_1 + 0x28));

  return (uint32_t /* width from decompiler */)local_8;

}
