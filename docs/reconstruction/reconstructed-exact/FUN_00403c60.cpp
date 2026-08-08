// =============================================================================
// FUN_00403c60  (clean twin → StdTree_LowerBound_StringKey_Isnil131_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403c60
// Address:   0x00403c60–0x00403ca6  (71 B / 0x47)  autoassault.exe base 0x400000
// Canonical: StdTree_LowerBound_StringKey_Isnil131_Inferred
// Generated: 2026-08-05 MEGA-041 — Ghidra-symbol twin of named clean.
// Exactness: Decompiler CF preserved. ABI: map in EAX (in_EAX), key on stack, RET 4.
// =============================================================================

// See StdTree_LowerBound_StringKey_Isnil131_Inferred.cpp for plate + family notes.

#include <stdint.h>
#include <string>

// Ghidra decompile twin — in_EAX is the real map register (not a phantom).
uint32_t *FUN_00403c60(std::string *param_1)
{
  char cVar1;
  uint32_t *puVar2;
  bool bVar3;
  int in_EAX; /* map* — live ABI loads from EAX at entry */
  uint32_t *puVar4;
  uint32_t *puVar5;

  puVar5 = (uint32_t *)(*(uint32_t **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x131);
  puVar2 = *(uint32_t **)(in_EAX + 4);
  while (cVar1 == '\0') {
    bVar3 = *reinterpret_cast<std::string *>(puVar5 + 3) < *param_1;
    if (bVar3) {
      puVar4 = (uint32_t *)puVar5[2];
      puVar5 = puVar2;
    } else {
      puVar4 = (uint32_t *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x131);
  }
  return puVar2;
}
