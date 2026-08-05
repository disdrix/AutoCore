// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×2, while×2.
//  - Notable callees: FUN_004ab300, FUN_00788280, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_004ab300
// -----------------------------------------------------------------------------
// Stable ID: aa_004ab300
// Address:   0x004ab300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004ab300(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_20;

  int local_1c;

  int local_18;

  uint8_t local_10 [12];

  

  if (*(int *)(param_3 + 4) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_3 + 8) - *(int *)(param_3 + 4) >> 3;

  }

  if (iVar2 % 3 == 0) {

    local_1c = 0;

    if (0 < iVar2 / 3) {

      local_20 = 0;

      local_18 = 0;

      do {

        iVar3 = 0;

        iVar4 = local_18;

        do {

          iVar3 = iVar3 + 1;

          cVar1 = FUN_00788280(local_10,param_1,param_2,*(int *)(param_3 + 4) + iVar4,

                               *(int *)(param_3 + 4) + (iVar3 % 3 + local_20) * 8);

          if (cVar1 != '\0') {

            return 1;

          }

          iVar4 = iVar4 + 8;

        } while (iVar3 < 3);

        local_20 = local_20 + 3;

        local_1c = local_1c + 1;

        local_18 = local_18 + 0x18;

      } while (local_1c < iVar2 / 3);

    }

    return 0;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 1;

}
