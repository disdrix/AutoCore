// =============================================================================
// FUN_004ba310
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba310
// Alias of: NDSpecialFX_Ctor
// Address:   0x004ba310–0x004ba545  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX
// Generated: 2026-07-29 W18-F OWN dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (not run).
// =============================================================================

// PURPOSE:
//   Default-construct a 0x240-byte NDSpecialFX host: clear flags, install default
//   16-byte blocks from DAT_009cb2a0, construct nested subobject at +0xa0, create
//   six empty vector heads and one tree sentinel, stamp client tick, strncpy name
//   into +0xd5 (0x104). Returns this.

// ABI (sealed):
//   __thiscall: ECX = this, stack name*, RET 4, EAX = this

#include <cstdint>
#include <cstring>

extern float g_flOne;
extern uint32_t g_dwClientTickMs;
extern uint32_t DAT_009cb2a0, DAT_009cb2a4, DAT_009cb2a8, DAT_009cb2ac;
extern void FUN_0074ba00(void);
extern uint32_t FUN_004933f0(void);
extern uint32_t FUN_00439770(void);

uint32_t * __thiscall FUN_004ba310(uint32_t *self, char *name)
{
  float one = g_flOne;

  *self = *self & 0xfffffffc;
  *(uint8_t *)(self + 1) = 0;
  *(uint8_t *)((int)self + 5) = 0;
  *(uint8_t *)((int)self + 6) = 0;
  *(uint8_t *)((int)self + 7) = 0;
  *(uint8_t *)(self + 2) = 0;
  *(uint8_t *)((int)self + 9) = 0;
  *(uint8_t *)((int)self + 10) = 0;
  *(uint8_t *)((int)self + 0xb) = 1;
  *(uint8_t *)(self + 3) = 0;
  self[4] = 0;

  self[6] = DAT_009cb2a0;
  self[7] = DAT_009cb2a4;
  self[8] = DAT_009cb2a8;
  self[9] = DAT_009cb2ac;

  self[0xc] = (uint32_t)one;
  self[0xd] = (uint32_t)one;
  self[0xe] = (uint32_t)one;
  self[10] = 0;
  self[0xb] = 0;
  self[0xf] = 0;
  self[0x10] = 0;

  self[0x12] = DAT_009cb2a0;
  self[0x13] = DAT_009cb2a4;
  self[0x14] = DAT_009cb2a8;
  self[0x15] = DAT_009cb2ac;
  self[0x16] = 0xffffffff;
  self[0x17] = 0;
  self[0x18] = 0;

  self[0x1a] = DAT_009cb2a0;
  self[0x1b] = DAT_009cb2a4;
  self[0x1c] = DAT_009cb2a8;
  self[0x1d] = DAT_009cb2ac;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;

  FUN_0074ba00(); // ECX = self+0xa0 at call site

  *(uint8_t *)(self + 0x35) = 0;

  uint32_t u;
  u = FUN_004933f0(); self[0x78] = u; self[0x79] = 0;
  u = FUN_004933f0(); self[0x7b] = u; self[0x7c] = 0;
  u = FUN_004933f0(); self[0x7e] = u; self[0x7f] = 0;
  u = FUN_004933f0(); self[0x81] = u; self[0x82] = 0;
  u = FUN_004933f0(); self[0x84] = u; self[0x85] = 0;
  u = FUN_004933f0(); self[0x87] = u; self[0x88] = 0;

  u = FUN_00439770();
  self[0x8a] = u;
  *(uint8_t *)(u + 0x15) = 1;
  *(uint32_t *)(self[0x8a] + 4) = self[0x8a];
  *(uint32_t *)self[0x8a] = self[0x8a];
  *(uint32_t *)(self[0x8a] + 8) = self[0x8a];
  self[0x8b] = 0;
  self[0x8c] = 2;

  self[0x23] = 0;
  self[0x22] = 0;
  self[0x21] = 0;
  self[0x20] = 0;
  self[0x34] = g_dwClientTickMs;
  strncpy((char *)((int)self + 0xd5), name, 0x104);
  return self;
}
