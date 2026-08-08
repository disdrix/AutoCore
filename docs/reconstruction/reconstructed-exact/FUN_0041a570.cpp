// =============================================================================
// FUN_0041a570  (scaffold twin of StdMap_InsertOrFind_CharKey_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a570
// Address:   0x0041a570–0x0041a628 exclusive (184 B / 0xB8)
// System:    skills-abilities / STL map-set (char-key isnil@+0x21)
// Generated: 2026-07-23 scaffold; refined 2026-08-05 R13-021 dual
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Named clean: StdMap_InsertOrFind_CharKey_Isnil21_Inferred.cpp
// =============================================================================
// PURPOSE: MSVC unique insert-or-find for char-key isnil@+0x21 maps.
// ABI: __thiscall ECX=map; stack (out*, value*); RET 0x8.
// Insert: FUN_0041ba30 (dualed R12-011). Pred: FUN_005adff0 (residual).
// Dual: reviews/A|B_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

// Dualed always-insert (thiscall; ret 0x10) — plate shows decomp call shape
extern "C" uint32_t* FUN_0041ba30(uint32_t* out, char addLeft, uint32_t* where,
                                  const void* value);
// Residual predecessor isnil21
extern "C" void FUN_005adff0();

void __thiscall FUN_0041a570(int param_1, uint32_t* param_2, char* param_3)
{
  uint32_t uVar1;
  bool bVar2;
  char* pcVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;

  pcVar3 = param_3;
  puVar5 = *(uint32_t**)(param_1 + 4);
  bVar2 = true;
  if (*(char*)((int)puVar5[1] + 0x21) == '\0') {
    puVar4 = (uint32_t*)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *param_3 < *(char*)(puVar5 + 3); // node+0x0C char key
      if (bVar2) {
        puVar4 = (uint32_t*)*puVar5;
      } else {
        puVar4 = (uint32_t*)puVar5[2];
      }
    } while (*(char*)((int)puVar4 + 0x21) == '\0');
  }
  param_3 = (char*)puVar5;
  if (bVar2) {
    if (puVar5 == (uint32_t*)**(int**)(param_1 + 4)) {
      puVar5 = (uint32_t*)FUN_0041ba30((uint32_t*)&param_3, 1, puVar5, pcVar3);
      uVar1 = *puVar5;
      *(uint8_t*)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_005adff0();
  }
  if (*(char*)((int)param_3 + 0xc) < *pcVar3) {
    puVar5 = (uint32_t*)FUN_0041ba30((uint32_t*)&param_3, (char)bVar2, puVar5,
                                     pcVar3);
    *param_2 = *puVar5;
    *(uint8_t*)(param_2 + 1) = 1;
    return;
  }
  *(uint8_t*)(param_2 + 1) = 0;
  *param_2 = (uint32_t)param_3;
  return;
}
