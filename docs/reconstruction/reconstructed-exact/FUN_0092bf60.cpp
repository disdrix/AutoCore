// =============================================================================
// FUN_0092bf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0092bf60
// Address:   0x0092bf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092bf60 @ 0x0092bf60
// Stable ID: aa_0092bf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: block×6, FUN_0092a3d0, FUN_0092af80, FUN_0092b2a0, FUN_0092bf60.
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

/* WARNING: Removing unreachable block (ram,0x0092c006) */

/* WARNING: Removing unreachable block (ram,0x0092c00b) */

/* WARNING: Removing unreachable block (ram,0x0092c019) */

/* WARNING: Removing unreachable block (ram,0x0092c01e) */

/* WARNING: Removing unreachable block (ram,0x0092c021) */

/* WARNING: Removing unreachable block (ram,0x0092c02d) */



uint32_t /* width from decompiler */ FUN_0092bf60(void)



{

  int iVar1;

  char cVar2;

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar1 = *in_EAX;

  if (((iVar1 != 0) && (*(int *)(iVar1 + 0xe98) != 0)) && (*(int *)(iVar1 + 0xe04) != 0)) {

    FUN_0092a3d0();

    in_EAX[5] = DAT_00aaa690;

    iVar1 = *(int *)(*in_EAX + 0xe98);

    if ((*(char *)(iVar1 + 0x4f1) == '\0') && (*(int *)(*in_EAX + 0xd34) != 0)) {

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1a0))();

      uStack_4 = DAT_00aaaaf8;

      cVar2 = FUN_0092af80(uVar3,&uStack_4);

      if ((cVar2 != '\0') && (cVar2 = FUN_0092b2a0(in_EAX,uVar3), cVar2 != '\0')) {

        return 1;

      }

      *(uint8_t *)(in_EAX + 2) = 0;

      return 0;

    }

  }

  return 0;

}
