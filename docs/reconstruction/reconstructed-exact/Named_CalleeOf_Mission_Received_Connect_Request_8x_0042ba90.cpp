// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_0042ba90
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ba90
// Callee of Mission_Received_Connect_Request_8x
// Address:   0x0042ba90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×2.
//  - Notable callees: FUN_0077daf0×2, BitStream_readBits, FUN_0042ba90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x
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

void __thiscall Named_CalleeOf_Mission_Received_Connect_Request_8x_0042ba90(uint param_1,char *param_2)



{

  char cVar1;

  byte bVar2;

  uint uVar3;

  char *pcVar4;

  int iVar5;

  uint local_4;

  

  uVar3 = *(uint *)(param_1 + 0x18);

  if (*(uint *)(param_1 + 0x2c) < uVar3) {

    *(uint8_t *)(param_1 + 0x1c) = 1;

  }

  else {

    bVar2 = *(byte *)((uVar3 >> 3) + *(int *)(param_1 + 0xc));

    *(uint *)(param_1 + 0x18) = uVar3 + 1;

    if ((bVar2 & (byte)(1 << ((byte)uVar3 & 7))) != 0) {

      local_4 = 0;

      BitStream_readBits(8,&local_4);

      FUN_0077daf0((local_4 & 0xff) + 0x38 + param_1);

      pcVar4 = (char *)(param_1 + 0x38);

      iVar5 = (int)param_2 - (int)pcVar4;

      do {

        cVar1 = *pcVar4;

        pcVar4[iVar5] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      return;

    }

  }

  local_4 = param_1;

  FUN_0077daf0(param_2);

  iVar5 = (param_1 + 0x38) - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar5] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  return;

}
