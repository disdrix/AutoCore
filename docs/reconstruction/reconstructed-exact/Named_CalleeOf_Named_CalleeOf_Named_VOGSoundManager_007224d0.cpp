// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGSoundManager_007224d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007224d0
// Callee of Named_CalleeOf_Named_VOGSoundManager
// Address:   0x007224d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGSoundManager: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007224d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGSoundManager
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool Named_CalleeOf_Named_CalleeOf_Named_VOGSoundManager_007224d0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ *local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_40 = 0;

  local_38 = 0;

  local_34 = 0;

  local_30 = 0;

  local_2c = 0;

  local_10 = DAT_00aa9100;

  local_50 = 0;

  local_c = DAT_00aa9104;

  local_8 = DAT_00aa9108;

  local_4 = DAT_00aa910c;

  local_3c = &local_28;

  local_4c = 0x24;

  local_48 = 0x10004;

  local_44 = 150000;

  local_28 = 0x6fffe;

  local_24 = 0xac44;

  local_1c = 0x10000c;

  local_20 = 0x81330;

  local_18 = 0x16;

  local_14 = 0x3f;

  iVar1 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1,&local_4c,&local_50,0);

  return -1 < iVar1;

}
