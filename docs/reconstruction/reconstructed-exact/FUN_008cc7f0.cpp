// =============================================================================
// FUN_008cc7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc7f0
// Address:   0x008cc7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc7f0 @ 0x008cc7f0
// Stable ID: aa_008cc7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_00541a80×2, FUN_00403450, FUN_007a69d0, FUN_007a6de0, FUN_008cc7f0, block.
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

/* WARNING: Removing unreachable block (ram,0x008cc905) */



void __fastcall FUN_008cc7f0(int param_1)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  char *unaff_EBX;

  uint8_t *puVar5;

  uint uVar6;

  uint8_t local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ac5be;

  local_c = ExceptionList;

  if (unaff_EBX != (char *)0x0) {

    if (param_1 == 0) {

      *unaff_EBX = '\0';

      return;

    }

    uVar6 = *(uint *)(param_1 + 0x740);

    ExceptionList = &local_c;

    pvVar2 = (void *)FUN_00541a80();

    pvVar2 = CNDHash_LookupByKey(pvVar2,uVar6);

    if (pvVar2 == (void *)0x0) {

      uVar6 = *(uint *)(param_1 + 0x73c);

      pvVar2 = (void *)FUN_00541a80();

      pvVar2 = CNDHash_LookupByKey(pvVar2,uVar6);

      if (pvVar2 == (void *)0x0) {

        *(uint32_t /* width from decompiler */ *)unaff_EBX = DAT_00a41270;

        *(uint16_t *)(unaff_EBX + 4) = DAT_00a41274;

        ExceptionList = local_c;

        return;

      }

    }

    puVar5 = local_8c;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450((int)pvVar2 + 0xb4,uVar3);

    uStack_4 = 0;

    uVar3 = 0xffffffff;

    FUN_007a69d0(puVar5,0xffffffff);

    pcVar4 = (char *)FUN_007a6de0(puVar5,uVar3);

    do {

      cVar1 = *pcVar4;

      *unaff_EBX = cVar1;

      pcVar4 = pcVar4 + 1;

      unaff_EBX = unaff_EBX + 1;

    } while (cVar1 != '\0');

  }

  ExceptionList = local_c;

  return;

}
