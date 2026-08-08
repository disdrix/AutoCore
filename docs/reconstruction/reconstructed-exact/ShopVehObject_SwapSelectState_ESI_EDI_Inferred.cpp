// =============================================================================
// ShopVehObject_SwapSelectState_ESI_EDI_Inferred  (FUN_00833160)
// -----------------------------------------------------------------------------
// Stable ID: aa_00833160
// Address:   0x00833160–0x00833383 exclusive (547 B / 0x223)
// Module:    autoassault.exe @ 0x400000
// Dual:      WQ9J-D 2026-08-05 — accept-with-gaps
// Exactness: Behavior-preserving from live decompile + assembly context.
// Runtime Confirmed: not claimed (no Launcher).
// =============================================================================
//
// PURPOSE: Swap select fields + nested XformState@+0x510 between two objects
// (ESI/EDI). Sole caller shopveh list reindex FUN_0083ac90.
//
// ABI: ESI=objA*, EDI=objB*; AL return 0/1; RET.

#include <cstdint>

void* __thiscall FUN_00416240(void* dest, const void* src); // FieldBlock_CopyFrom_ClearFlags0xBC
void  __thiscall FUN_00416160(void* dest, const void* src); // XformState_AssignSelectiveByFlags
void  __thiscall FUN_0040cf90(void* self, const float* pos3);

// Modeled with explicit args; retail uses ESI/EDI register pair.
unsigned char ShopVehObject_SwapSelectState_ESI_EDI_Inferred(int* esi_obj, int* edi_obj)
{
  if (edi_obj == nullptr) {
    return 0;
  }

  auto swap4 = [](int* a, int* b, int idx) {
    int t = a[idx];
    a[idx] = b[idx];
    b[idx] = t;
  };

  // Dword indices: 0x142→+0x508, 0x143→+0x50C, 0x175→+0x5D4, 0xA6→+0x298
  swap4(esi_obj, edi_obj, 0x142);
  swap4(esi_obj, edi_obj, 0x143);
  swap4(esi_obj, edi_obj, 0x175);
  swap4(esi_obj, edi_obj, 0x0A6);

  // Byte offsets (assembly authority): +0x4FC, +0x5D0, +0x5DC, +0xBC
  auto* a = reinterpret_cast<unsigned char*>(esi_obj);
  auto* b = reinterpret_cast<unsigned char*>(edi_obj);
  auto swap1 = [](unsigned char* x, unsigned char* y, size_t off) {
    unsigned char t = x[off];
    x[off] = y[off];
    y[off] = t;
  };
  swap1(a, b, 0x4FC);
  swap1(a, b, 0x5D0);
  swap1(a, b, 0x5DC);
  swap1(a, b, 0x0BC);

  // Three-way nested block swap at +0x510 (0x144*4)
  alignas(16) unsigned char local_d0[0xD0];
  FUN_00416240(local_d0, a + 0x510);          // temp ← ESI+0x510 (clear flags)
  FUN_00416160(a + 0x510, b + 0x510);         // ESI  ← EDI
  FUN_00416160(b + 0x510, local_d0);          // EDI  ← temp

  // 16 B @ +0x5E0 (indices 0x178..0x17B)
  swap4(esi_obj, edi_obj, 0x178);
  swap4(esi_obj, edi_obj, 0x179);
  swap4(esi_obj, edi_obj, 0x17A);
  swap4(esi_obj, edi_obj, 0x17B);

  // Pair @ +0x500 / +0x504 (indices 0x140 / 0x141)
  swap4(esi_obj, edi_obj, 0x140);
  swap4(esi_obj, edi_obj, 0x141);

  // Optional nested pos cross via vtbl+0x1a0
  using VCall = int (__thiscall*)(void*);
  VCall getA = *reinterpret_cast<VCall*>(*esi_obj + 0x1A0);
  int subA = getA(esi_obj);
  if (subA != 0) {
    VCall getB = *reinterpret_cast<VCall*>(*edi_obj + 0x1A0);
    int subB = getB(edi_obj);
    if (subB != 0) {
      int pB = *(int*)(getB(edi_obj) + 8);
      int pA = *(int*)(getA(esi_obj) + 8);
      getB(edi_obj);
      FUN_0040cf90(reinterpret_cast<void*>(/*this = last EDI vtbl return*/ getB(edi_obj)),
                   reinterpret_cast<float*>(pA + 0x90));
      getA(esi_obj);
      FUN_0040cf90(reinterpret_cast<void*>(getA(esi_obj)),
                   reinterpret_cast<float*>(pB + 0x90));
    }
  }

  using VCall0 = void (__thiscall*)(void*);
  (*reinterpret_cast<VCall0*>(*edi_obj + 0x3BC))(edi_obj);
  (*reinterpret_cast<VCall0*>(*esi_obj + 0x3BC))(esi_obj);
  return 1;
}

// Ghidra export: no formal params; ESI/EDI live
unsigned FUN_00833160(void)
{
  // Not callable as written without register setup — retail entry uses ESI/EDI.
  return 0;
}
