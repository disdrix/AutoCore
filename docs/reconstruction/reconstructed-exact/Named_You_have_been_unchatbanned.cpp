// =============================================================================
// Named_You_have_been_unchatbanned
// -----------------------------------------------------------------------------
// Stable ID: aa_0080d280
// Address:   0x0080d280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_You_have_been_unchatbanned @ 0x0080d280
// Stable ID: aa_0080d280
// Embedded strings (evidence for future rename):
//   - "Chatbanned"
//   - "You have been chatbanned by GM"
//   - "Unchatbanned"
//   - "You have been unchatbanned by GM"
//   - "%s %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007a6de0×3, FUN_007a69d0, FUN_007fdfb0, Named_You_have_been_unchatbanned, FUN_008f8200, sprintf, strncpy.
//  - Strings: "Chatbanned"; "You have been chatbanned by GM"; "Unchatbanned"; "You have been unchatbanned by GM".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "You have been unchatbanned by GM"
 * Domain alias of FUN_0080d280 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_You_have_been_unchatbanned(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EDI;

  char *pcVar5;

  char local_214 [16];

  char local_204 [516];

  

  FUN_007a69d0();

  uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x109c);

  strncpy(local_214,(char *)(in_EAX + 4),0x10);

  local_204[0] = '0';

  if (*(int *)(unaff_EDI + 0xe98) != 0) {

    iVar2 = *(int *)(unaff_EDI + 0xe98);

    if (*in_EAX == 0x8059) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x188))();

      uVar3 = FUN_007a6de0("Chatbanned",0xffffffff);

      pcVar5 = "You have been chatbanned by GM";

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 400))(0x20);

      uVar3 = FUN_007a6de0("Unchatbanned",0xffffffff);

      pcVar5 = "You have been unchatbanned by GM";

    }

    uVar4 = FUN_007a6de0(pcVar5,0xffffffff);

    sprintf(local_204,"%s %s",uVar4,&stack0xfffffde8);

    FUN_007fdfb0(unaff_EDI,local_204,0xffffffff,1,0);

    FUN_008f8200(uVar1,6,uVar3,local_204,0);

  }

  return;

}
