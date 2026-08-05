// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00643a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00643a50
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00643a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×8, do×5, while×5, return×2.
//  - Notable callees: FUN_00643a50, FUN_006a3db0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00643a50(int param_1,int param_2,int param_3,int param_4)



{

  uint16_t uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint16_t *local_2160;

  int local_2158;

  int local_2154;

  uint16_t *local_213c;

  int local_2138;

  uint16_t local_2104 [4224];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x643a5a;

  iVar5 = *(int *)(param_1 + 4);

  local_2154 = 0;

  if (0 < iVar5) {

    iVar4 = *(int *)(param_4 + 0x10);

    local_2160 = local_2104;

    iVar3 = param_2;

    do {

      if (iVar4 <= iVar3) break;

      local_2158 = 0;

      if (0 < iVar5) {

        iVar2 = *(int *)(param_4 + 0x14);

        local_213c = local_2160;

        do {

          if (iVar2 <= param_3 + local_2158) break;

          local_2138 = 3;

          do {

            local_2138 = local_2138 + -1;

          } while (local_2138 != 0);

          uVar1 = FUN_006a3db0();

          *local_213c = uVar1;

          local_213c = local_213c + iVar5;

          local_2158 = local_2158 + 1;

        } while (local_2158 < iVar5);

      }

      local_2160 = local_2160 + 1;

      local_2154 = local_2154 + 1;

      iVar3 = iVar3 + 1;

    } while (local_2154 < iVar5);

  }

  iVar4 = 0;

  if (0 < iVar5) {

    do {

      if (*(int *)(param_4 + 0x10) <= param_2) {

        return;

      }

      iVar2 = 0;

      iVar3 = param_3;

      if (0 < iVar5) {

        do {

          if (*(int *)(param_4 + 0x14) <= iVar3) break;

          *(uint16_t *)

           (*(int *)(param_4 + 0x3e0) + (*(int *)(param_4 + 0x10) * iVar3 + param_2) * 2) =

               local_2104[iVar5 * iVar2 + iVar4];

          iVar5 = *(int *)(param_1 + 4);

          iVar2 = iVar2 + 1;

          iVar3 = iVar3 + 1;

        } while (iVar2 < iVar5);

      }

      iVar5 = *(int *)(param_1 + 4);

      iVar4 = iVar4 + 1;

      param_2 = param_2 + 1;

    } while (iVar4 < iVar5);

  }

  return;

}
