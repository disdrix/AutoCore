// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00798590
// -----------------------------------------------------------------------------
// Stable ID: aa_00798590
// Callee of Named_CalleeOf_Client_RecvBroadcast
// Address:   0x00798590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2, for×1.
//  - Notable callees: FUN_00797e20×2, wcslen×2, FUN_004270d0, FUN_00798590.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00798590(int param_1,wchar_t *param_2,uint32_t /* width from decompiler */ param_3,int param_4,char param_5)



{

  size_t sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  uint32_t /* width from decompiler */ local_4c [19];

  

  if (param_2 != (wchar_t *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = in_XMM0_Da;

    if ((((param_4 != *(int *)(param_1 + 0xc0)) ||

         (*(char *)(param_1 + 0xc6) != (char)((uint)param_3 >> 0x10))) ||

        (*(char *)(param_1 + 0xc5) != (char)((uint)param_3 >> 8))) ||

       (((*(char *)(param_1 + 0xc4) != (char)param_3 ||

         (*(char *)(param_1 + 199) != (char)((uint)param_3 >> 0x18))) ||

        (*(char *)(param_1 + 0xbc) == '\x01')))) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = param_3;

      *(int *)(param_1 + 0xc0) = param_4;

      puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x60);

      puVar4 = local_4c;

      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      FUN_004270d0();

      *(uint8_t *)(param_1 + 0xbc) = 0;

    }

    if (param_5 == '\0') {

      iVar2 = 0;

      sVar1 = wcslen(param_2);

      if (0 < (int)sVar1) {

        do {

          FUN_00797e20(param_2[iVar2]);

          iVar2 = iVar2 + 1;

        } while (iVar2 < (int)sVar1);

      }

    }

    else {

      sVar1 = wcslen(param_2);

      if (0 < (int)sVar1) {

        do {

          FUN_00797e20(0x2a);

          sVar1 = sVar1 - 1;

        } while (sVar1 != 0);

        return;

      }

    }

  }

  return;

}
