// =============================================================================
// LocalWorklist_Release_Inferred  (Ghidra: FUN_0055f4c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f4c0
// Address:   0x0055f4c0 – 0x0055f51b  (autoassault.exe, image base 0x400000)
// Size:      92 bytes (0x5C); epilogue ret (0 stack)
// System:    allocator / local worklist teardown
// Dual:      W27-N 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; tag-free includes machine AND 0x7fffffff.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Release a stack/local worklist descriptor against DAT_00b05060 allocator:
//   (1) return or free the aligned slab described by desc[+0xc]/[+0x10];
//   (2) if desc[+0x8] >= 0, tagged free of *desc with tag 0x12.
//   Always called at end of WorldObj bind/unbind (and sibling) paths.
//
// ABI (machine):
//   __fastcall/thiscall; ECX = desc; ret 0; void
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

// Ghidra name: FUN_0055f4c0
void __fastcall LocalWorklist_Release_Inferred(std::uint32_t *param_1 /*ECX*/)
{
  int *piVar1;
  std::uint32_t uVar2;

  piVar1 = DAT_00b05060;
  uVar2 = (param_1[4] * 8 + 0xfU) & 0xfffffff0;
  if ((uVar2 == 0) ||
      ((param_1[3] != static_cast<std::uint32_t>(DAT_00b05060[5]) &&
        (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - static_cast<int>(uVar2);
    piVar1[3] = piVar1[3] + static_cast<int>(uVar2);
  } else {
    (**(void (***)(std::uint32_t, std::uint32_t))(*DAT_00b05060 + 0x28))(
        param_1[3], uVar2);
  }
  if (-1 < static_cast<int>(param_1[2])) {
    // Machine: AND EAX,0x7fffffff then *8 (decompiler omits mask)
    std::uint32_t nbytes = (param_1[2] & 0x7fffffffU) * 8;
    (**(void (***)(std::uint32_t, std::uint32_t, int))(*DAT_00b05060 + 0x14))(
        *param_1, nbytes, 0x12);
  }
}

// Scaffold twin entry (Ghidra name)
extern "C" void __fastcall FUN_0055f4c0(std::uint32_t *param_1)
{
  LocalWorklist_Release_Inferred(param_1);
}
