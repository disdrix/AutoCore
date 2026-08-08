// =============================================================================
// UI_ItemRarity_WriteBgraFromIndex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005140d0
// Address:   0x005140d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R12-016 dual seal (from raw + live re-decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Leaf fixed palette: map signed rarity index (blob+0x4b8 / loot-rarity row)
//   to a 4-byte BGRA color used by item tooltip / detail UI text hosts.
//
// ABI (MSVC cdecl):
//   arg0 = uint8_t* outBgra
//   arg1 = int16_t rarityIndex  (MOVSX at entry)
//   bare RET; EAX = out on exit (callers may load *(uint32_t*)EAX)
//
// Related:
//   Parent: UI_ItemTooltip_AppendTypeMetaLines_Inferred @ 0x00847240
//   Table:  EnsureLootRarityTableLoaded @ 0x005129b0 + DAT_00b04214
//   Sibling palette (do not merge): Ui_NameColorPalette_WriteArgb @ 0x00930f40
//
// Retires scaffold alias Named_CalleeOf_Mission_Mission_Object_005140d0.
// =============================================================================

#include <cstdint>

// Returns out (EAX). Memory order: B, G, R, A. Little-endian DWORD = AARRGGBB.
uint8_t* UI_ItemRarity_WriteBgraFromIndex_Inferred(uint8_t* out, int16_t rarityIndex)
{
  switch (rarityIndex) {
  case 0: // 0xFF919191 gray
    out[2] = 0x91;
    out[1] = 0x91;
    out[0] = 0x91;
    out[3] = 0xFF;
    return out;
  case 1: // 0xFFFFFFFF white
    out[2] = 0xFF;
    out[1] = 0xFF;
    out[0] = 0xFF;
    out[3] = 0xFF;
    return out;
  case 2: // 0xFF2828FF blue
    out[2] = 0x28;
    out[1] = 0x28;
    out[0] = 0xFF;
    out[3] = 0xFF;
    return out;
  case 3: // 0xFFF014F0 purple
    out[1] = 0x14;
    out[0] = 0xF0;
    out[2] = 0xF0;
    out[3] = 0xFF;
    return out;
  case 4: // 0xFFFF0A23 orange-red
    out[2] = 0xFF;
    out[1] = 0x0A;
    out[0] = 0x23;
    out[3] = 0xFF;
    return out;
  case 5: // 0xFFFF8A0A gold
    out[2] = 0xFF;
    out[1] = 0x8A;
    out[0] = 0x0A;
    out[3] = 0xFF;
    return out;
  default: // 0xFFF0E43C cyan fallback (index < 0 or > 5)
    out[1] = 0xE4;
    out[0] = 0x3C;
    out[2] = 0xF0;
    out[3] = 0xFF;
    return out;
  }
}
