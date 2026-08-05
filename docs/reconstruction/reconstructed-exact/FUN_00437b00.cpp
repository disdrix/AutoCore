// =============================================================================
// FUN_00437b00  (twin of Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00437b00
// Address:   0x00437b00–0x00437b57  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map A) + stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W36-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Preferred name: Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred
// See: reconstructed-exact/Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.cpp
// NOTE: raw decompile claims creator(tag); bytes show 0-arg creator + PUSH EDI to vfunc.
// =============================================================================

#include <cstdint>

extern "C" uint32_t FUN_0076a900(void); // PeekChunkTag; this in ESI
extern "C" void* FUN_00438c40(void);    // MapA GetInstance
extern "C" void FUN_0046c1b0(void);     // NestedHash lookup

// cdecl; param_1 = out*; EDI = stoChunkReader*
extern "C" uint32_t FUN_00437b00(int* param_1)
{
  uint32_t uVar1;
  int iVar2;
  uint32_t local_node; // decompiler local_4 — actually found node after lookup
  // retail also keeps tag in a sibling stack slot

  // mov esi, edi  (chunk reader)
  uVar1 = FUN_0076a900(); // tag (not passed to creator)
  FUN_00438c40();
  FUN_0046c1b0(); // fills found-node local from tag
  iVar2 = (int)FUN_00438c40();
  if (local_node == (uint32_t)*(int*)(iVar2 + 8)) {
    iVar2 = 0;
  } else {
    // bytes: CALL [node+0xC] — no stack arg (decompiler (uVar1) is wrong)
    iVar2 = (int)((void* (*)(void))*(void**)(local_node + 0xc))();
  }
  *param_1 = iVar2;
  if (iVar2 != 0) {
    // bytes: MOV EDX,[EAX+4]; LEA ECX,[EAX+4]; PUSH EDI; CALL [EDX+4]
    uVar1 = ((uint32_t(__thiscall*)(void*, void*))
                 * (void**)(*(int*)(iVar2 + 4) + 4))(
        (void*)(iVar2 + 4),
        /* EDI chunk reader */ nullptr);
    return uVar1;
  }
  return 0xffffffffu;
}
