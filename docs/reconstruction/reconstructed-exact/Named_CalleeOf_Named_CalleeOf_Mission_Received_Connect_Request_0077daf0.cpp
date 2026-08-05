// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_0077daf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077daf0
// Callee of Named_CalleeOf_Mission_Received_Connect_Request_8x
// Address:   0x0077daf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×2, goto×1.
//  - Notable callees: BitStream_readBits×3, FUN_0077d520, FUN_0077daf0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Received_Connect_Request_8x
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_0077daf0(int param_1)



{

  byte bVar1;

  short sVar2;

  uint uVar3;

  int unaff_ESI;

  uint uVar4;

  int iVar5;

  uint local_4;

  

  if (DAT_00d17a28 == '\0') {

    FUN_0077d520();

  }

  uVar4 = *(uint *)(unaff_ESI + 0x18);

  if (*(uint *)(unaff_ESI + 0x2c) < uVar4) {

    *(uint8_t *)(unaff_ESI + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar4 >> 3) + *(int *)(unaff_ESI + 0xc));

    *(uint *)(unaff_ESI + 0x18) = uVar4 + 1;

    if ((bVar1 & (byte)(1 << ((byte)uVar4 & 7))) != 0) {

      uVar4 = 0;

      local_4 = 0;

      BitStream_readBits(8,&local_4);

      local_4 = local_4 & 0xff;

      if (local_4 != 0) {

        do {

          iVar5 = 0;

          do {

            uVar3 = *(uint *)(unaff_ESI + 0x18);

            if (*(uint *)(unaff_ESI + 0x2c) < uVar3) {

              *(uint8_t *)(unaff_ESI + 0x1c) = 1;

LAB_0077dba3:

              sVar2 = *(short *)(DAT_00d1eab0 + 4 + iVar5 * 8);

            }

            else {

              bVar1 = *(byte *)((uVar3 >> 3) + *(int *)(unaff_ESI + 0xc));

              *(uint *)(unaff_ESI + 0x18) = uVar3 + 1;

              if ((bVar1 & (byte)(1 << ((byte)uVar3 & 7))) == 0) goto LAB_0077dba3;

              sVar2 = *(short *)(DAT_00d1eab0 + 6 + iVar5 * 8);

            }

            iVar5 = (int)sVar2;

          } while (-1 < iVar5);

          *(uint8_t *)(param_1 + uVar4) = *(uint8_t *)(DAT_00d1eabc + iVar5 * -0xc + -7);

          uVar4 = uVar4 + 1;

        } while (uVar4 < local_4);

      }

      *(uint8_t *)(local_4 + param_1) = 0;

      return 1;

    }

  }

  local_4 = 0;

  BitStream_readBits(8,&local_4);

  uVar4 = local_4 & 0xff;

  BitStream_readBits(uVar4 * 8,param_1);

  *(uint8_t *)(uVar4 + param_1) = 0;

  return 1;

}
