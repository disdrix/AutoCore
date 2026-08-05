// =============================================================================
// FUN_0077d960
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d960
// Address:   0x0077d960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077d960 @ 0x0077d960
// Stable ID: aa_0077d960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×3, while×3.
//  - Notable callees: BitStream_writeBits×5, FUN_0042b450×3, FUN_0077d520, FUN_0077d960.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0077d960(uint param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  byte *pbVar3;

  uint uVar4;

  uint uVar5;

  char *unaff_EBX;

  char *pcVar6;

  uint uVar7;

  uint local_4;

  

  if (unaff_EBX == (char *)0x0) {

    if ((*(int *)(in_EAX + 0x18) + 1U <= *(uint *)(in_EAX + 0x30)) ||

       (cVar2 = FUN_0042b450(), cVar2 != '\0')) {

      pbVar3 = (byte *)(*(int *)(in_EAX + 0xc) + (*(uint *)(in_EAX + 0x18) >> 3));

      *pbVar3 = *pbVar3 & ~('\x01' << ((byte)*(uint *)(in_EAX + 0x18) & 7));

      *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;

    }

    local_4 = 0;

    BitStream_writeBits(8,&local_4);

    return 1;

  }

  if (DAT_00d17a28 == '\0') {

    FUN_0077d520();

  }

  pcVar6 = unaff_EBX;

  do {

    cVar2 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar2 != '\0');

  uVar7 = (int)pcVar6 - (int)(unaff_EBX + 1);

  if (param_1 < (uint)((int)pcVar6 - (int)(unaff_EBX + 1))) {

    uVar7 = param_1;

  }

  uVar5 = 0;

  uVar4 = 0;

  if (uVar7 != 0) {

    do {

      pbVar3 = (byte *)(unaff_EBX + uVar4);

      uVar4 = uVar4 + 1;

      uVar5 = uVar5 + *(byte *)(DAT_00d1eabc + 4 + (uint)*pbVar3 * 0xc);

    } while (uVar4 < uVar7);

  }

  local_4 = uVar7;

  if (uVar7 * 8 <= uVar5) {

    if ((*(int *)(in_EAX + 0x18) + 1U <= *(uint *)(in_EAX + 0x30)) ||

       (cVar2 = FUN_0042b450(), cVar2 != '\0')) {

      pbVar3 = (byte *)((*(uint *)(in_EAX + 0x18) >> 3) + *(int *)(in_EAX + 0xc));

      *pbVar3 = *pbVar3 & ~('\x01' << ((byte)*(uint *)(in_EAX + 0x18) & 7));

      *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;

    }

    BitStream_writeBits(8,&local_4);

    BitStream_writeBits(uVar7 * 8,unaff_EBX);

    return 1;

  }

  if ((*(int *)(in_EAX + 0x18) + 1U <= *(uint *)(in_EAX + 0x30)) ||

     (cVar2 = FUN_0042b450(), cVar2 != '\0')) {

    pbVar3 = (byte *)((*(uint *)(in_EAX + 0x18) >> 3) + *(int *)(in_EAX + 0xc));

    *pbVar3 = *pbVar3 | '\x01' << ((byte)*(uint *)(in_EAX + 0x18) & 7);

    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;

  }

  BitStream_writeBits(8,&local_4);

  uVar4 = 0;

  if (uVar7 != 0) {

    do {

      iVar1 = DAT_00d1eabc + (uint)(byte)unaff_EBX[uVar4] * 0xc;

      BitStream_writeBits(*(uint8_t *)(iVar1 + 4),iVar1 + 8);

      uVar4 = uVar4 + 1;

    } while (uVar4 < uVar7);

  }

  return 1;

}
