// =============================================================================
// FUN_005e0480 / LootCatalog_TypeCodeToRowIndex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0480
// Address:   0x005e0480  (autoassault.exe, image base 0x400000)
// System:    inventory / loot catalog
// Generated: 2026-07-23 scaffold; refined 2026-07-29 OWN-ONLY W16-C dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Map sparse gear/item type codes to compact loot-catalog table row indices
//   0..11, or return 0xffffffff (-1) when unmapped. Pure switch; no side effects.
//
// CALLERS:
//   FUN_005e07d0, FUN_005e0cd0, FUN_005e0610, FUN_005e0c50
//
// ABI: stack formal typeCode; ret 4 (stdcall-ish). Return in EAX.
//

#include <cstdint>

// Proposed name: LootCatalog_TypeCodeToRowIndex_Inferred
// Ghidra: FUN_005e0480
uint32_t FUN_005e0480(uint32_t typeCode)
{
  switch (typeCode) {
  case 6:
    return 0;
  default:
    return 0xffffffff;
  case 8:
    return 1;
  case 10:
    return 2;
  case 0xc:
    return 3;
  case 0xe:
    return 4;
  case 0x10:
    return 5;
  case 0x1a:
    return 6;
  case 0x1c:
    return 7;
  case 0x32:
    return 9;
  case 0x34:
    return 8;
  case 0x44:
    return 0xb;
  case 0x46:
    return 10;
  }
}
