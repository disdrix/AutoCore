// =============================================================================
// FUN_00983b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00983b60
// Address:   0x00983b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983b60 @ 0x00983b60
// Stable ID: aa_00983b60
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"
//   - "Opening compressed from memory from pack file."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0071abd0, FUN_0076c0b0, FUN_00983b60, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"; "Opening compressed from memory from pack file.".
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

uint32_t /* width from decompiler */ * __fastcall FUN_00983b60(int *param_1)



{

  int in_EAX;

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_ESI;

  

  if (param_1 == (int *)0x0) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  pvVar1 = operator_new__(in_EAX + 1);

  iVar2 = (**(code **)(*param_1 + 0x14))(pvVar1);

  (**(code **)*param_1)(1);

  if (-1 < iVar2) {

    pvVar3 = operator_new(0x18);

    if (pvVar3 == (void *)0x0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0076c0b0(unaff_ESI + 1);

    }

    iVar2 = FUN_0071abd0(puVar4[1],&stack0xfffffff8);

    operator_delete__(pvVar1);

    if (-1 < iVar2) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0xfc,1,

                     "Opening compressed from memory from pack file.");

      puVar4[3] = unaff_ESI;

      return puVar4;

    }

    (**(code **)*puVar4)(1);

  }

  return (uint32_t /* width from decompiler */ *)0x0;

}
