// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_006ba750
// -----------------------------------------------------------------------------
// Stable ID: aa_006ba750
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x006ba750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_006bfed0×2, FUN_005b3300, FUN_006ba750.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_006ba750(uint *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint *puVar1;

  int iVar2;

  uint uVar3;

  uint *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int local_c;

  int local_8;

  uint local_4;

  

  puVar4 = param_1;

  uVar3 = param_1[2];

  if ((uVar3 == 0x10) && ((*param_1 & 0xf) == 0)) {

    FUN_006bfed0(*param_1,param_1[1],param_2,param_3);

    return;

  }

  puVar1 = param_1 + 1;

  local_c = 0;

  local_8 = 0;

  local_4 = 0x80000000;

  param_1 = (uint *)0x0;

  if (0 < (int)*puVar1) {

    iVar6 = 0;

    do {

      iVar7 = local_8;

      iVar2 = local_8 + 1;

      if ((int)(local_4 & 0x7fffffff) < iVar2) {

        iVar5 = (local_4 & 0x7fffffff) * 2;

        if (iVar5 <= iVar2) {

          iVar5 = iVar2;

        }

        FUN_005b3300(&local_c,iVar5,0x10);

      }

      *(uint32_t /* width from decompiler */ *)(iVar7 * 0x10 + local_c) = *(uint32_t /* width from decompiler */ *)(iVar6 + *puVar4);

      iVar7 = iVar7 * 0x10 + local_c;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 4) = *(uint32_t /* width from decompiler */ *)(*puVar4 + 4 + iVar6);

      *(uint32_t /* width from decompiler */ *)(iVar7 + 8) = *(uint32_t /* width from decompiler */ *)(*puVar4 + 8 + iVar6);

      param_1 = (uint *)((int)param_1 + 1);

      iVar6 = iVar6 + ((int)(uVar3 + ((int)uVar3 >> 0x1f & 3U)) >> 2) * 4;

      local_8 = iVar2;

    } while ((int)param_1 < (int)puVar4[1]);

  }

  FUN_006bfed0(local_c,puVar4[1],param_2,param_3);

  if (-1 < (int)local_4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 << 4,0x12);

  }

  return;

}
