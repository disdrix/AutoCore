// =============================================================================
// FUN_00476db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00476db0
// Address:   0x00476db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476db0 @ 0x00476db0
// Stable ID: aa_00476db0
// Embedded strings (evidence for future rename):
//   - "0123456789ABCDEF deflate 1.2.1 Copyright 1995-2003 Jean-loup Gailly "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00476db0, strncpy.
//  - Return sites: 2.

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

void __fastcall FUN_00476db0(uint32_t /* width from decompiler */ param_1,char *param_2,int param_3)



{

  byte bVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint uVar4;

  char *_Dest;

  int iVar5;

  

  iVar2 = 0;

  iVar5 = 0;

  do {

    bVar1 = *(byte *)(iVar5 + 0x11c + param_3);

    uVar4 = (uint)bVar1;

    iVar5 = iVar5 + 1;

    if (((uVar4 < 0x41) || (0x7a < uVar4)) || ((0x5a < uVar4 && (uVar4 < 0x61)))) {

      *(uint8_t *)(iVar2 + in_EAX) = 0x5b;

      *(char *)(iVar2 + 1 + in_EAX) =

           "0123456789ABCDEF deflate 1.2.1 Copyright 1995-2003 Jean-loup Gailly "[(int)uVar4 >> 4];

      *(char *)(iVar2 + 2 + in_EAX) =

           "0123456789ABCDEF deflate 1.2.1 Copyright 1995-2003 Jean-loup Gailly "[uVar4 & 0xf];

      iVar3 = iVar2 + 3;

      *(uint8_t *)(iVar3 + in_EAX) = 0x5d;

    }

    else {

      *(byte *)(iVar2 + in_EAX) = bVar1;

      iVar3 = iVar2;

    }

    iVar2 = iVar3 + 1;

  } while (iVar5 < 4);

  if (param_2 == (char *)0x0) {

    *(uint8_t *)(iVar2 + in_EAX) = 0;

    return;

  }

  *(uint8_t *)(iVar2 + in_EAX) = 0x3a;

  *(uint8_t *)(iVar3 + 2 + in_EAX) = 0x20;

  _Dest = (char *)(in_EAX + iVar3 + 3);

  strncpy(_Dest,param_2,0x3f);

  _Dest[0x3f] = '\0';

  return;

}
