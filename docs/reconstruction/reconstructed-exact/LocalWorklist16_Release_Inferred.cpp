// =============================================================================
// LocalWorklist16_Release_Inferred  (Ghidra: FUN_0055f590)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f590
// Address:   0x0055f590 – 0x0055f5e7  (autoassault.exe, image base 0x400000)
// Size:      88 bytes (0x58); epilogue ret (0 stack)
// System:    allocator / local worklist teardown (element stride 0x10)
// Dual:      W28-R 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; slab size align16 + tag-free AND 0x7fffffff.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Release a stack/local worklist descriptor (stride 0x10) against DAT_00b05060:
//   (1) return or free the aligned slab described by desc[+0xc]/[+0x10];
//   (2) if desc[+0x8] >= 0, tagged free of *desc with tag 0x12 and nbytes
//       (count & 0x7fffffff) << 4.
//   Twin of LocalWorklist16_Init_Inferred; called from Phys_CommitPairListStorage.
//   Sibling of LocalWorklist_Release_Inferred (0x0055f4c0, stride *8).
//
// ABI (machine):
//   __fastcall/thiscall; ECX = desc; ret 0; void
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

// Ghidra name: FUN_0055f590
void __fastcall LocalWorklist16_Release_Inferred(std::uint32_t *param_1 /*ECX*/)
{
  int *piVar1;
  std::uint32_t uVar2;

  piVar1 = DAT_00b05060;
  // Machine: SHL 4; ADD 0xF; AND 0xFFFFFFF0
  uVar2 = (param_1[4] * 0x10u + 0xfu) & 0xfffffff0u;
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
    // Machine: AND EAX,0x7fffffff then SHL 4 (decompiler omits mask)
    std::uint32_t nbytes = (param_1[2] & 0x7fffffffu) << 4;
    (**(void (***)(std::uint32_t, std::uint32_t, int))(*DAT_00b05060 + 0x14))(
        *param_1, nbytes, 0x12);
  }
}

// Scaffold twin entry (Ghidra name)
extern "C" void __fastcall FUN_0055f590(std::uint32_t *param_1)
{
  LocalWorklist16_Release_Inferred(param_1);
}
