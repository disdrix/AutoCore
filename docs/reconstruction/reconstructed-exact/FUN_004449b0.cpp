// =============================================================================
// FUN_004449b0  (twin of Sto_AbstractUnserializationFactory_InsertCreator_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004449b0
// Address:   0x004449b0–0x00444a35  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map A)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W36-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Preferred name: Sto_AbstractUnserializationFactory_InsertCreator_Inferred
// See: reconstructed-exact/Sto_AbstractUnserializationFactory_InsertCreator_Inferred.cpp
// =============================================================================

#include <cstdint>

// MapA GetInstance (W35-D)
extern "C" void* FUN_00438c40(void);
// NestedHash lookup / insert (unowned W36-B)
extern "C" void FUN_0046c1b0(void);
extern "C" int* FUN_0046bf90(uint8_t* out_pair, int* key_pair);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

// cdecl; tag = param_1; creator = EBX (register)
extern "C" void FUN_004449b0(int param_1)
{
  int iVar1;
  int* piVar2;
  uint32_t creator_ebx; // retail: EBX register input (unaff_EBX)
  int local_10[2];
  uint8_t local_8[8];

  iVar1 = (int)FUN_00438c40();
  iVar1 = *(int*)(iVar1 + 8); // sentinel
  FUN_00438c40();
  FUN_0046c1b0(); // ESI=map, ECX=&param_1, EAX=&local_10[0]
  if (local_10[0] != iVar1) {
    vog_LogMessage("..\\arda2/storage/stoAbstractUnserializationFactory.h", 0x24, 2,
                   "Inserting duplicate creator tag to factory");
  }
  iVar1 = (int)FUN_00438c40();
  FUN_0046c1b0();
  if (local_10[0] == *(int*)(iVar1 + 8)) {
    local_10[0] = param_1;
    local_10[1] = 0;
    piVar2 = FUN_0046bf90(local_8, local_10); // EDI=map
    local_10[0] = *piVar2;
  }
  *(uint32_t*)(local_10[0] + 0xc) = creator_ebx;
  return;
}
