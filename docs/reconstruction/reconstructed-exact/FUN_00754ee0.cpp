// =============================================================================
// FUN_00754ee0  (scaffold twin of GlyphCache_PlacementCtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00754ee0
// Address:   0x00754ee0
// Wave:      W35-H — prefer GlyphCache_PlacementCtor.cpp
// =============================================================================

#include <cstdint>

extern uint32_t DAT_00d1f01c;
extern uint32_t DAT_00d1f020;
extern void* PTR_FUN_00a9f584[];
void basic_string_default_ctor(void* self);
uint32_t* FUN_004438c0(uint32_t* self /*stack*/);

// stack(this*); RET 4
uint32_t* FUN_00754ee0(uint32_t* param_1 /*stack*/)
{
  param_1[1] = 0;
  param_1[0] = reinterpret_cast<uint32_t>(PTR_FUN_00a9f584);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  basic_string_default_ctor(param_1 + 6);
  param_1[0xe] = DAT_00d1f01c;
  param_1[0xf] = DAT_00d1f020;
  param_1[0x10] = 0;
  FUN_004438c0(param_1 + 0x11);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = DAT_00d1f01c;
  param_1[0x2d] = DAT_00d1f020;
  return param_1;
}
