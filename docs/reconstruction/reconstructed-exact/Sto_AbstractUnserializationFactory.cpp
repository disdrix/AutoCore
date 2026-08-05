// =============================================================================
// Sto_AbstractUnserializationFactory
// -----------------------------------------------------------------------------
// Stable ID: aa_004449b0
// Address:   0x004449b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Sto_AbstractUnserializationFactory for FUN_004449b0 @ 0x004449b0
// Stable ID: aa_004449b0
// Embedded strings (evidence for future rename):
//   - "..\\arda2/storage/stoAbstractUnserializationFactory.h"
//   - "Inserting duplicate creator tag to factory"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00438c40×3, FUN_0046c1b0×2, Sto_AbstractUnserializationFactory, FUN_0046bf90, vog_LogMessage.
//  - Strings: "..\\arda2/storage/stoAbstractUnserializationFactory.h"; "Inserting duplicate creator tag to factory".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "..\arda2/storage/stoAbstractUnserializationFactory.h"
 * Domain alias of FUN_004449b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Sto_AbstractUnserializationFactory(int param_1)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ unaff_EBX;

  int local_10 [2];

  uint8_t local_8 [8];

  

  iVar1 = FUN_00438c40();

  iVar1 = *(int *)(iVar1 + 8);

  FUN_00438c40();

  FUN_0046c1b0();

  if (local_10[0] != iVar1) {

    vog_LogMessage("..\\arda2/storage/stoAbstractUnserializationFactory.h",0x24,2,

                   "Inserting duplicate creator tag to factory");

  }

  iVar1 = FUN_00438c40();

  FUN_0046c1b0();

  if (local_10[0] == *(int *)(iVar1 + 8)) {

    local_10[0] = param_1;

    local_10[1] = 0;

    piVar2 = (int *)FUN_0046bf90(local_8,local_10);

    local_10[0] = *piVar2;

  }

  *(uint32_t /* width from decompiler */ *)(local_10[0] + 0xc) = unaff_EBX;

  return;

}
