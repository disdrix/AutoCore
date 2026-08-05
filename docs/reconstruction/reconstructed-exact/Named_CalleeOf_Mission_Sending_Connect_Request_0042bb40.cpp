// =============================================================================
// Named_CalleeOf_Mission_Sending_Connect_Request_0042bb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0042bb40
// Callee of Mission_Sending_Connect_Request (+1 other named callers)
// Address:   0x0042bb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Sending_Connect_Request: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Sending_Connect_Request (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1, goto×1.
//  - Notable callees: FUN_0077d960×2, BitStream_writeBits, CONCAT31, FUN_0042bb40, realloc, strncpy.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Sending_Connect_Request (+1 other named callers)
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

void __thiscall Named_CalleeOf_Mission_Sending_Connect_Request_0042bb40(int param_1,uint8_t *param_2,uint param_3)



{

  void *pvVar1;

  byte *pbVar2;

  char cVar3;

  byte bVar4;

  uint _NewSize;

  uint uVar5;

  uint uVar6;

  

  if (param_2 == (uint8_t *)0x0) {

    param_2 = &DAT_00a1419b;

  }

  bVar4 = 0;

  if ((byte)param_3 != 0) {

    do {

      if ((*(char *)(bVar4 + 0x38 + param_1) != param_2[bVar4]) || (param_2[bVar4] == '\0')) break;

      bVar4 = bVar4 + 1;

    } while (bVar4 < (byte)param_3);

  }

  uVar5 = param_3 & 0xff;

  uVar6 = (uint)bVar4;

  strncpy((char *)(uVar6 + 0x38 + param_1),param_2 + uVar6,uVar5 - uVar6);

  *(uint8_t *)(uVar5 + 0x38 + param_1) = 0;

  param_3 = CONCAT31(param_3._1_3_,2 < bVar4);

  cVar3 = 2 < bVar4;

  if (*(uint *)(param_1 + 0x30) < *(int *)(param_1 + 0x18) + 1U) {

    _NewSize = (*(uint *)(param_1 + 0x30) + 8 >> 3) + 0x5dc;

    if (*(uint *)(param_1 + 0x10) < _NewSize) {

      if (*(char *)(param_1 + 0x14) != '\0') {

        *(uint *)(param_1 + 0x10) = _NewSize;

        pvVar1 = realloc(*(void **)(param_1 + 0xc),_NewSize);

        *(void **)(param_1 + 0xc) = pvVar1;

        *(uint *)(param_1 + 0x2c) = _NewSize * 8;

        *(uint *)(param_1 + 0x30) = _NewSize * 8;

        cVar3 = (byte)param_3;

        goto LAB_0042bc22;

      }

    }

    else {

      *(uint *)(param_1 + 0x10) = _NewSize;

    }

    *(uint8_t *)(param_1 + 0x1c) = 1;

  }

  else {

LAB_0042bc22:

    pbVar2 = (byte *)((*(uint *)(param_1 + 0x18) >> 3) + *(int *)(param_1 + 0xc));

    bVar4 = '\x01' << ((byte)*(uint *)(param_1 + 0x18) & 7);

    if (cVar3 == '\0') {

      *pbVar2 = *pbVar2 & ~bVar4;

    }

    else {

      *pbVar2 = *pbVar2 | bVar4;

    }

    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

    if (cVar3 != '\0') {

      param_3 = uVar6;

      BitStream_writeBits(8,&param_3);

      FUN_0077d960(uVar5 - uVar6);

      return;

    }

  }

  FUN_0077d960(uVar5);

  return;

}
