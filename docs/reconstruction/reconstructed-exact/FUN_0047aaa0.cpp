// =============================================================================
// FUN_0047aaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047aaa0
// Address:   0x0047aaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047aaa0 @ 0x0047aaa0
// Stable ID: aa_0047aaa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, switch×1.
//  - Notable callees: FUN_00476cc0×2, FUN_0047a3c0×2, FUN_00470090, FUN_0047a420, FUN_0047a480, FUN_0047aaa0.
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

void FUN_0047aaa0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  byte bVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  char local_8;

  uint8_t local_7;

  uint8_t local_6;

  uint8_t local_5;

  uint8_t local_4;

  

  if ((*(uint *)(in_EAX + 0x68) & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  if (param_2 != 0xd) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 1;

  FUN_0047a420();

  FUN_0047a480();

  iVar2 = FUN_0047a3c0();

  uVar3 = FUN_0047a3c0();

  *(uint8_t *)(in_EAX + 0x123) = local_4;

  *(uint8_t *)(in_EAX + 0x238) = local_5;

  *(int *)(in_EAX + 200) = iVar2;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcc) = uVar3;

  *(char *)(in_EAX + 0x127) = local_8;

  *(uint8_t *)(in_EAX + 0x126) = local_7;

  *(uint8_t *)(in_EAX + 0x260) = local_6;

  switch(local_7) {

  case 0:

  case 3:

    *(uint8_t *)(in_EAX + 0x12a) = 1;

    break;

  case 2:

    *(uint8_t *)(in_EAX + 0x12a) = 3;

    break;

  case 4:

    *(uint8_t *)(in_EAX + 0x12a) = 2;

    break;

  case 6:

    *(uint8_t *)(in_EAX + 0x12a) = 4;

  }

  bVar1 = *(char *)(in_EAX + 0x12a) * local_8;

  *(byte *)(in_EAX + 0x129) = bVar1;

  if (bVar1 < 8) {

    uVar4 = (uint)bVar1 * iVar2 + 7 >> 3;

  }

  else {

    uVar4 = (uint)(bVar1 >> 3) * iVar2;

  }

  *(uint *)(in_EAX + 0xd8) = uVar4;

  FUN_00470090(iVar2,uVar3,local_8,local_4,local_6,local_5);

  return;

}
