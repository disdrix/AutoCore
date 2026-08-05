// =============================================================================
// FUN_0058e370  — alias plate for CVOGObject_SetGfxBodyLink_Mode1AndTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e370
// Address:   0x0058e370  (autoassault.exe, image base 0x400000)
// System:    client CVOG object / gfxBody link packet
// Generated: 2026-07-29 W20-M dual seal (updates 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/CVOGObject_SetGfxBodyLink_Mode1AndTarget.cpp
// =============================================================================

#include <cstdint>

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
