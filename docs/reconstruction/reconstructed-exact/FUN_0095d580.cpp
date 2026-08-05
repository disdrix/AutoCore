// =============================================================================
// FUN_0095d580
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d580
// Address:   0x0095d580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d580 @ 0x0095d580
// Stable ID: aa_0095d580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×2, do×1, while×1.
//  - Notable callees: FUN_0095d580.
//  - Return sites: 4.

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

void FUN_0095d580(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,char param_3)



{

  int in_EAX;

  float *pfVar1;

  int iVar2;

  int *piVar3;

  float unaff_EBP;

  uint32_t /* width from decompiler */ *puVar4;

  float unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ unaff_retaddr;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ *local_54;

  uint32_t /* width from decompiler */ auStack_50 [10];

  uint32_t /* width from decompiler */ local_28 [10];

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  puVar5 = param_2;

  puVar6 = local_28;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    return;

  }

  local_54 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

  local_58 = (float)((int)local_54 - (int)puVar4 >> 2);

  if (local_58 == 0.0) {

    return;

  }

  piVar3 = (int *)0x0;

  local_5c = 0.0;

  if (puVar4 != local_54) {

    do {

      piVar3 = (int *)*puVar4;

      pfVar1 = (float *)(**(code **)(*piVar3 + 0x2c))();

      local_58 = *pfVar1;

      puVar5 = param_2;

      puVar6 = auStack_50;

      for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      local_5c = local_58 + local_5c;

      (**(code **)(*piVar3 + 0x14))(param_1,auStack_50);

      (**(code **)(*piVar3 + 0x1c))(unaff_retaddr,unaff_retaddr,&local_58,unaff_EBP / unaff_ESI);

      puVar4 = puVar4 + 1;

    } while (puVar4 != local_54);

    if (g_flOne < local_5c) {

      return;

    }

  }

  if ((param_3 != '\0') && (piVar3 != (int *)0x0)) {

    (**(code **)(*piVar3 + 0x1c))(param_2,local_28,param_2,local_5c);

  }

  return;

}
