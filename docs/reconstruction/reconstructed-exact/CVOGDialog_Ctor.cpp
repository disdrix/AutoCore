// =============================================================================
// CVOGDialog_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_0087b890
// Address:   0x0087b890 – 0x0087b905 inclusive (118 B / 0x76)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression (partition); shared CVOGDialog base
// Wave:      R11-030 OWN-ONLY dual 2026-08-05
// Ghidra:    FUN_0087b890
// RTTI:      .?AVCVOGDialog@@  (type_info @ 0x00af8e50; COL @ 0x00ab4984)
// Vtbl:      PTR_FUN_00a58c6c @ 0x00a58c6c
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime).
// Terminal:  false
// =============================================================================
//
// PURPOSE:
//   CVOGDialog constructor. Calls CNDUIDialog base ctor FUN_00792d20 (vtbl
//   0x00a98f44 temporarily), zeros a small dialog field pack, installs the
//   CVOGDialog primary vtbl, and stores the second ctor argument at +0x2A4.
//   Shared base for dozens of client dialog subclasses (mission NPC host,
//   CDlgFirstTime, CreateNDUIDialogs installers, etc.). Callers typically
//   overwrite *this with a more-derived vtbl after return.
//
// ABI:
//   __stdcall-style stack: (this*, param_2); RET 8; returns this in EAX.
//   SEH LAB_009b531d.
//
// NOT:
//   - Not a mission-state mutator / C2S sender.
//   - Not subclass-specific (mission host / first-time / …) — those overwrite vtbl.
//   - Scaffold Named_CalleeOf_Mission_i_d_npc_xml_0087b890 is NOT product.
// =============================================================================

#include <cstdint>

// CNDUIDialog ctor peer of CNDUIDialog_CompleteDtor (0x00792c20).
// Dual plate also used NDUIContainerPanel_Ctor_Inferred for same VA.
extern "C" std::uint32_t* FUN_00792d20(std::uint32_t* self);

// Retail CVOGDialog primary vtbl (Ghidra PTR_FUN_00a58c6c).
extern "C" void* PTR_FUN_00a58c6c;

// MSVC SEH ExceptionList (thread FS:[0]) — plate only.
extern "C" void* ExceptionList;
extern "C" void* LAB_009b531d;

/// CVOGDialog constructor.
/// @param self    CVOGDialog* (stack arg 0)
/// @param param_2 Stored at self+0x2A4 (callers commonly pass 0; English open)
/// @return self in EAX
extern "C" std::uint32_t* __stdcall CVOGDialog_Ctor(
    std::uint32_t* self,
    std::uint32_t param_2)
{
  // SEH frame: push -1; push LAB_009b531d; link ExceptionList (runtime)
  void* local_c;
  void* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = &LAB_009b531d;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  // Base CNDUIDialog / container construction
  FUN_00792d20(self);

  // Zero dialog mode / pack fields (absolute offsets sealed by read_memory)
  self[0x141] = 0;                                              // +0x504
  self[0x142] = 0;                                              // +0x508
  self[0x13f] = 0;                                              // +0x4FC
  self[0x140] = 0;                                              // +0x500
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(self) + 0xBF) = 0;
  *reinterpret_cast<std::uint8_t*>(self + 0x124) = 0;           // +0x490; clears base=1

  // Install CVOGDialog vtbl (RTTI .?AVCVOGDialog@@)
  *self = reinterpret_cast<std::uint32_t>(static_cast<void*>(&PTR_FUN_00a58c6c));

  // Retain ctor argument
  self[0xa9] = param_2;                                         // +0x2A4

  ExceptionList = local_c;
  return self;  // RET 8
}

// Ghidra symbol alias
extern "C" std::uint32_t* __stdcall FUN_0087b890(
    std::uint32_t* self,
    std::uint32_t param_2)
{
  return CVOGDialog_Ctor(self, param_2);
}
