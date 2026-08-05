// =============================================================================
// Named_addhazardcount_d
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e640
// Address:   0x0094e640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_addhazardcount_d @ 0x0094e640
// Stable ID: aa_0094e640
// Embedded strings (evidence for future rename):
//   - "//addhazardcount %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: Named_addhazardcount_d, sscanf.
//  - Strings: "//addhazardcount %d".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//addhazardcount %d"
 * Domain alias of FUN_0094e640 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */



uint32_t /* width from decompiler */ __thiscall Named_addhazardcount_d(int param_1,int param_2)



{

  int iVar1;

  int local_c [2];

  float local_4;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    local_c[0] = 100;

    if ((param_2 != 0) && ((char *)(param_2 + 0x2e) != (char *)0x0)) {

      sscanf((char *)(param_2 + 0x2e),"//addhazardcount %d",local_c);

    }

    iVar1 = *(int *)(param_1 + 0xe98);

    *(float *)(iVar1 + 0x600) =

         (float)*(int *)(iVar1 + 0x608) + *(float *)(iVar1 + 0x600) + (float)local_c[0];

    local_4 = (float)local_c[0];

    local_c[1] = 0x202e;

    if (*(int *)(param_1 + 0xc78) != 0) {

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_c + 1,8,0);

    }

  }

  return 1;

}
