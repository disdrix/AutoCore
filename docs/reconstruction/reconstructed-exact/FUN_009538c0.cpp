// =============================================================================
// FUN_009538c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009538c0
// Address:   0x009538c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009538c0 @ 0x009538c0
// Stable ID: aa_009538c0
// Embedded strings (evidence for future rename):
//   - "System "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008f8200, FUN_009538c0, __RTDynamicCast, _ctime64, _time64.
//  - Strings: "System ".
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __fastcall FUN_009538c0(int param_1)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  __time64_t local_8;

  

  _time64(&local_8);

  uVar5 = 0;

  pcVar1 = _ctime64(&local_8);

  pcVar4 = "System ";

  uVar3 = 6;

  uVar2 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                          &CDlgChatLog::RTTI_Type_Descriptor,0,6,"System ",pcVar1,uVar5);

  FUN_008f8200(uVar2,uVar3,pcVar4,pcVar1,uVar5);

  return 1;

}
