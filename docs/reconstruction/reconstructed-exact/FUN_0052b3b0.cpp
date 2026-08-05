// =============================================================================
// FUN_0052b3b0 — legacy scaffold path
// Prefer: CVOGCharacter_IsMissionJournalReady.cpp
// Stable ID: aa_0052b3b0  VA: 0x0052b3b0
// Sealed dual A/B 2026-07-29.
// =============================================================================

// Redirect note: authoritative clean reconstruction lives at:
//   docs/reconstruction/reconstructed-exact/CVOGCharacter_IsMissionJournalReady.cpp
//
// Behavioral CF (authoritative raw pseudocode preserved for scaffold tools):

#include <cstdint>

extern "C" char FUN_0052a020(void* character, void* objective, char modeFlag);

// Ghidra-shaped entry; production name: CVOGCharacter_IsMissionJournalReady
std::uint32_t __thiscall FUN_0052b3b0(int param_1 /* Character* */, int param_2 /* MissionDef* */)
{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  char cVar4;

  iVar1 = *(int *)(*(int *)(param_2 + 0x13c) + -4 + (uint32_t)*(uint8_t *)(param_2 + 0x130) * 4);
  uVar2 = *(uint32_t *)(iVar1 + 0x10);
  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 0x10) +
                           (*(uint32_t *)(*(int *)(param_1 + 0x548) + 8) & uVar2) * 4) + 4);
  while (true) {
    if (iVar3 == 0) {
      return 0;
    }
    if (uVar2 == *(uint32_t *)(iVar3 + 0x10)) break;
    iVar3 = *(int *)(iVar3 + 0xc);
  }
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(iVar3 + 8) == 0) {
    return 0;
  }
  // Mode 0 (journal). Decompiler shows FUN_0052a020(iVar1,0); thiscall ECX=param_1.
  cVar4 = FUN_0052a020(reinterpret_cast<void*>(param_1), reinterpret_cast<void*>(iVar1), 0);
  if (cVar4 == '\0') {
    return 0;
  }
  return 1;
}
