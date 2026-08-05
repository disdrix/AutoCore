// =============================================================================
// CVOGObject_SetGfxBodyLink_Mode1AndTarget  (FUN_0058e370)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e370
// Address:   0x0058e370  (autoassault.exe, image base 0x400000)
// System:    client CVOG object / gfxBody link packet
// Generated: 2026-07-29 W20-M dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: If this->gfxBody (+0x914) and gfxBody->linkPacket (+0x78) are non-null,
// set packet mode byte to 1 and packet+4 to the target pointer argument.
//
// ABI: __thiscall (this in ECX); one stack arg; ret 4.
// Body range: 0x0058e370 .. 0x0058e398 (40 B). Hex seal:
//   8b8114090000 85c0 741c 83787800 7416 8b5078 c60201
//   8b8114090000 8b4878 8b542404 895104 c20400
//
// RELATED (context, not this unit):
//   - FUN_0058f780 creates gfxBody and packet (mode 9, +4 = self)
//   - FUN_00590f00 / FUN_00593e10 reset packet to mode 9 / self on teardown
//   - Sole caller FUN_004b73c0 walks list +0x204 and arms each entry's object
//   - Prior auto alias Named_CalleeOf_…_Cli_0058e370 (parent-seed noise)
//

#include <cstdint>

void CVOGObject_SetGfxBodyLink_Mode1AndTarget(int self, uint32_t target)
{
  int gfxBody = *(int *)(self + 0x914);
  if ((gfxBody != 0) && (*(int *)(gfxBody + 0x78) != 0)) {
    **(uint8_t **)(gfxBody + 0x78) = 1;
    *(uint32_t *)(*(int *)(*(int *)(self + 0x914) + 0x78) + 4) = target;
  }
  return;
}

// Ghidra alias
void __thiscall FUN_0058e370(int param_1, uint32_t param_2)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x914);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x78) != 0)) {
    **(uint8_t **)(iVar1 + 0x78) = 1;
    *(uint32_t *)(*(int *)(*(int *)(param_1 + 0x914) + 0x78) + 4) = param_2;
  }
  return;
}
