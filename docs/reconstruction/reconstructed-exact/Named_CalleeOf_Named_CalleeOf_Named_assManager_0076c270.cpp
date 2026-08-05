// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assManager_0076c270
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c270
// Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
// Address:   0x0076c270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: QueryPerformanceCounter×2, rdtsc×2, CARRY4, FUN_0076c270, QueryPerformanceFrequency, __allmul, __aulldiv.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_assManager_0076c270(void)



{

  uint uVar1;

  uint uVar2;

  uint64_t uVar3;

  LARGE_INTEGER local_28;

  LARGE_INTEGER local_20;

  LARGE_INTEGER local_18;

  uint local_10;

  int local_c;

  uint local_8;

  int local_4;

  

  QueryPerformanceFrequency(&local_28);

  QueryPerformanceCounter(&local_20);

  uVar3 = rdtsc();

  local_4 = (int)((ulonglong)uVar3 >> 0x20);

  local_8 = (uint)uVar3;

  uVar1 = local_28.s.LowPart >> 4 | local_28.s.HighPart << 0x1c;

  uVar2 = uVar1 + local_20.s.LowPart;

  uVar1 = ((uint)local_28.s.HighPart >> 4) + local_20.s.HighPart +

          (uint)CARRY4(uVar1,local_20.s.LowPart);

  do {

    do {

      QueryPerformanceCounter(&local_18);

      uVar3 = rdtsc();

      local_c = (int)((ulonglong)uVar3 >> 0x20);

      local_10 = (uint)uVar3;

    } while ((uint)local_18.s.HighPart < uVar1);

  } while ((local_18.s.HighPart == uVar1) && (local_18.s.LowPart < uVar2));

  uVar3 = __allmul(local_10 - local_8,(local_c - local_4) - (uint)(local_10 < local_8),

                   local_28.s.LowPart,local_28.s.HighPart);

  uVar3 = __aulldiv(uVar3,local_18.s.LowPart - local_20._0_4_,

                    (local_18.s.HighPart - local_20._4_4_) -

                    (uint)(local_18.s.LowPart < local_20.s.LowPart));

  DAT_00d1a538 = (int)uVar3;

  DAT_00d1a53c = (int)((ulonglong)uVar3 >> 0x20);

  DAT_00d1a530 = 1;

  return;

}
