// =============================================================================
// FUN_008577c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008577c0
// Address:   0x008577c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008577c0 @ 0x008577c0
// Stable ID: aa_008577c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_007889b0×4, FUN_008577c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ FUN_008577c0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  if ((in_EAX != (uint32_t /* width from decompiler */ *)0x0) && (param_1 != (uint32_t /* width from decompiler */ *)0x0)) {

    local_20 = *in_EAX;

    local_1c = in_EAX[1];

    local_18 = *param_1;

    local_14 = param_1[1];

    cVar1 = FUN_007889b0(&local_10,&local_20,param_2);

    if (cVar1 == '\0') {

      cVar1 = FUN_007889b0(&local_10,&local_20,param_2);

      if (cVar1 == '\0') {

        cVar1 = FUN_007889b0(&local_10,&local_20,param_2);

        if (cVar1 == '\0') {

          cVar1 = FUN_007889b0(&local_10,&local_20,param_2);

          if (cVar1 == '\0') {

            return 0xffffffff;

          }

          local_34 = 3;

        }

        else {

          local_34 = 2;

        }

      }

      else {

        local_34 = 1;

      }

    }

    else {

      local_34 = 0;

    }

    *param_1 = local_10;

    param_1[1] = local_c;

    return local_34;

  }

  return 0xffffffff;

}
