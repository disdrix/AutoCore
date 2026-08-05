// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00448180
// -----------------------------------------------------------------------------
// Stable ID: aa_00448180
// Callee of Named_effDeviceEffect
// Address:   0x00448180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00448180×3, FUN_004484e0, FUN_004486f0, FUN_00448740, FUN_00448c70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

void Named_CalleeOf_Named_effDeviceEffect_00448180(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int local_8;

  int local_4;

  

  iVar1 = param_2 - param_1;

  do {

    iVar1 = iVar1 >> 3;

    if (iVar1 < 0x21) {

LAB_00448217:

      if (1 < iVar1) {

        FUN_00448740(param_1,param_2,param_4);

      }

      return;

    }

    if (param_3 < 1) {

      if (0x20 < iVar1) {

        if (8 < (int)(param_2 - param_1 & 0xfffffff8U)) {

          FUN_00448c70(param_1,param_2,param_4);

        }

        FUN_004486f0(param_1,param_2);

        return;

      }

      goto LAB_00448217;

    }

    FUN_004484e0(&local_8,param_1,param_2,param_4);

    iVar1 = local_4;

    param_3 = param_3 / 2 + (param_3 / 2) / 2;

    if ((int)(local_8 - param_1 & 0xfffffff8U) < (int)(param_2 - local_4 & 0xfffffff8U)) {

      Named_CalleeOf_Named_effDeviceEffect_00448180(param_1,local_8,param_3,param_4);

      param_1 = iVar1;

    }

    else {

      Named_CalleeOf_Named_effDeviceEffect_00448180(local_4,param_2,param_3,param_4);

      param_2 = local_8;

    }

    iVar1 = param_2 - param_1;

  } while( true );

}
