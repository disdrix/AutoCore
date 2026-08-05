// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_008704f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008704f0
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x008704f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00870430, FUN_008704f0, block.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

/* WARNING: Removing unreachable block (ram,0x0087058d) */



void Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_008704f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = param_1;

  *(uint16_t *)(param_1 + 0x510) = 0;

  param_1 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x51c);

  do {

    if (*in_EAX == 0) {

      puVar2[-1] = 0xffffffff;

      if ((void *)*puVar2 != (void *)0x0) {

        operator_delete__((void *)*puVar2);

      }

      *puVar2 = 0;

      puVar2[1] = 0;

    }

    else {

      *(short *)(iVar1 + 0x510) = *(short *)(iVar1 + 0x510) + 1;

      FUN_00870430();

    }

    param_1 = param_1 + 1;

    in_EAX = in_EAX + 3;

    puVar2 = puVar2 + 3;

  } while (param_1 < 4);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x514) = param_2;

  *(uint8_t *)(iVar1 + 0x548) = 1;

  return;

}
