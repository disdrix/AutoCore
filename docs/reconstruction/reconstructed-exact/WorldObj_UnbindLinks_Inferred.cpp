// =============================================================================
// WorldObj_UnbindLinks_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fbf0
// Address:   0x0055fbf0 – 0x0055fd72  (autoassault.exe, image base 0x400000)
// System:    world-object / manager unbind
// Dual:      W26-D 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Manager-side unbind / remove spatial-query links for a world object.
//   First step of WorldObj_RebindActivate_Inferred (unbind → bind → flag)
//   and of remove/defer unbind chains.
//
// ABI (machine):
//   thiscall; ECX = manager; stack Object* obj; ret 4; void
// =============================================================================

#include <cstdint>

// Nested callees — contracts not sealed in this dual (not OWN)
void FUN_0062d960(std::uint32_t arg);
void FUN_006297e0(int a, int b, std::uint32_t c, int d);
void FUN_006caaa0(int a, int b, std::uint32_t c, int d, int e);
void FUN_0055f4c0(void); // machine: thiscall/fastcall on stack alloc desc (ECX)

extern void* PTR_FUN_009d2820;
extern int*  DAT_00b05060;

// Ghidra name: FUN_0055fbf0
void __thiscall WorldObj_UnbindLinks_Inferred(int manager /*ECX*/, int obj /*stack*/)
{
  int iVar1;
  int iVar2;
  std::uint32_t local_38;
  int iStack_34;
  void** ppuStack_24;
  int iStack_20;
  std::uint8_t* puStack_1c;
  int iStack_18;
  int iStack_14;
  std::uint8_t auStack_10[16];

  FUN_0062d960(*reinterpret_cast<std::uint32_t*>(manager + 0x234));

  if ((*reinterpret_cast<int*>(obj + 0xc) != 0) &&
      ((**(void (***)(int, std::uint32_t*))(
            **reinterpret_cast<int**>(manager + 0xc4) + 0xc))(obj + 0x1c, &local_38),
       0 < iStack_34)) {
    if (*reinterpret_cast<char*>(obj + 0x40) == '\0') {
      FUN_006297e0(0, 0, local_38, iStack_34);
    } else {
      puStack_1c = auStack_10;
      ppuStack_24 = &PTR_FUN_009d2820;
      iStack_18 = 0;
      iStack_14 = -0x7ffffffc;
      *reinterpret_cast<void****>(*reinterpret_cast<int*>(manager + 0x138) + 0x24) =
          reinterpret_cast<void***>(&ppuStack_24);
      if (*reinterpret_cast<int*>(manager + 0xd0) == 0) {
        iVar2 = 0;
      } else {
        iVar2 = *reinterpret_cast<int*>(manager + 0xd0) + 8;
      }
      iStack_20 = obj + 0xc;
      FUN_006caaa0(0, 0, local_38, iStack_34, iVar2);
      iVar2 = 0;
      *reinterpret_cast<int*>(*reinterpret_cast<int*>(manager + 0x138) + 0x24) =
          *reinterpret_cast<int*>(manager + 0x138) + 0x100;
      if (0 < iStack_18) {
        do {
          iVar1 = *reinterpret_cast<int*>(puStack_1c + iVar2 * 4);
          FUN_006297e0(
              0, 0,
              *reinterpret_cast<std::uint32_t*>(iVar1 + 0x8c),
              *reinterpret_cast<std::uint32_t*>(iVar1 + 0x90));
          iVar2 = iVar2 + 1;
          *reinterpret_cast<std::uint32_t*>(iVar1 + 0x90) = 0;
        } while (iVar2 < iStack_18);
      }
      if (-1 < iStack_14) {
        (**(void (***)(std::uint8_t*, int, int))(*DAT_00b05060 + 0x14))(
            puStack_1c, iStack_14 * 4, 0x12);
        FUN_0055f4c0();
        return;
      }
    }
  }
  FUN_0055f4c0();
}

// Scaffold twin entry (Ghidra name)
extern "C" void __thiscall FUN_0055fbf0(int manager, int obj)
{
  WorldObj_UnbindLinks_Inferred(manager, obj);
}
