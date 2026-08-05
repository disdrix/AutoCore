// =============================================================================
// FUN_00809c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00809c70
// Address:   0x00809c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00809c70 @ 0x00809c70
// Stable ID: aa_00809c70
// Embedded strings (evidence for future rename):
//   - "Tried to modify an object that isn\'t in inventory."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00571010×2, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_00809c70.
//  - Strings: "Tried to modify an object that isn\'t in inventory.".
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

void __fastcall FUN_00809c70(uint32_t /* width from decompiler */ param_1)



{

  int *in_EAX;

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  FUN_007a69d0();

  piVar1 = (int *)FUN_00571010(in_EAX[6],in_EAX[7]);

  if (piVar1 == (int *)0x0) {

    piVar1 = (int *)FUN_00571010(in_EAX[6],in_EAX[7]);

    if (piVar1 == (int *)0x0) {

      uVar5 = 1;

      uVar4 = 0xffffffff;

      uVar2 = FUN_007a6de0("Tried to modify an object that isn\'t in inventory.",0xffffffff);

      FUN_007fdfb0(param_1,uVar2,uVar4,uVar5,piVar1);

      return;

    }

  }

  iVar3 = 5;

  do {

    in_EAX = in_EAX + 1;

    if (*in_EAX != -1) {

      (**(code **)(*piVar1 + 0x58))();

      (**(code **)(*piVar1 + 0x6c))(*in_EAX,1);

    }

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
