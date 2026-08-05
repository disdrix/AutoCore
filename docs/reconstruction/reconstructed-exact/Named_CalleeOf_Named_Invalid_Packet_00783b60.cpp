// =============================================================================
// Named_CalleeOf_Named_Invalid_Packet_00783b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00783b60
// Callee of Named_Invalid_Packet (+12 other named callers)
// Address:   0x00783b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Invalid_Packet: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Invalid_Packet (+12 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, return×2, goto×2, while×2.
//  - Notable callees: FUN_0042ae30, FUN_0077fe70, FUN_00783b60, _atexit.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Invalid_Packet (+12 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * Named_CalleeOf_Named_Invalid_Packet_00783b60(byte *param_1)



{

  byte bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  byte *pbVar3;

  int iVar4;

  byte *pbVar5;

  bool bVar6;

  

  puVar2 = DAT_00d1799c;

  if ((_DAT_00d1fcbc & 1) == 0) {

    _DAT_00d1fcbc = _DAT_00d1fcbc | 1;

    FUN_0042ae30();

    _atexit((_func_4879 *)&LAB_009c3140);

    puVar2 = DAT_00d1799c;

  }

  do {

    if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

      _DAT_00d1fcb0 = _DAT_00d1fcb0 + 1;

      if (DAT_00d1fcb8 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_0077fe70();

      }

      else {

        puVar2 = DAT_00d1fcb8;

        DAT_00d1fcb8 = (uint32_t /* width from decompiler */ *)*DAT_00d1fcb8;

      }

      puVar2[2] = param_1;

      *puVar2 = DAT_00d1799c;

      DAT_00d1799c = puVar2;

      *(uint8_t *)(puVar2 + 1) = 0;

      return puVar2;

    }

    pbVar3 = (byte *)puVar2[2];

    pbVar5 = param_1;

    do {

      bVar1 = *pbVar3;

      bVar6 = bVar1 < *pbVar5;

      if (bVar1 != *pbVar5) {

LAB_00783bd4:

        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

        goto LAB_00783bd9;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar3[1];

      bVar6 = bVar1 < pbVar5[1];

      if (bVar1 != pbVar5[1]) goto LAB_00783bd4;

      pbVar3 = pbVar3 + 2;

      pbVar5 = pbVar5 + 2;

    } while (bVar1 != 0);

    iVar4 = 0;

LAB_00783bd9:

    if (iVar4 == 0) {

      return puVar2;

    }

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

  } while( true );

}
