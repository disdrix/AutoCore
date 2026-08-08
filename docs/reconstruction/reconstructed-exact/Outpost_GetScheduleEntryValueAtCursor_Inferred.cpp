// =============================================================================
// Outpost_GetScheduleEntryValueAtCursor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00607550
// Address:   0x00607550–0x006075a8 exclusive (88 B / 0x58, autoassault.exe base 0x400000)
// System:    outpost / capture schedule table lookup
// Generated: 2026-08-04 WQ8R-E dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00607550
// =============================================================================
//
// PURPOSE:
//   Select schedule bank via outpost+0x220 (DAT_00d029e0 vs DAT_00d029f0),
//   index by outpost+0x23c (cursor), return the dword at entry+4 of the
//   16-byte schedule vector element. Soft-return 0 on negative / OOB index.
//   Pathological operator[] recheck throws via FUN_00608620
//   ("invalid vector<T> subscript").
//
// ABI:
//   __thiscall (ECX=outpost); no stack formals; plain RET; returns EAX dword.
//   Entry: 8B C1 …
//   Exit:  5E C3  (success and zero paths)
//
// CALLER:
//   Outpost_CaptureOutpost (0x006082e0) @ 0x006085cc — after +0x23c=0,
//   result stored to timerBlob(+0x248)[+8]; GetTickCount → timer[+0x14].
//
// TWIN (not owned):
//   Outpost_GetPulseXpPercent @ 0x006075b0 — same bank/cursor/stride;
//   returns float at entry+8.
//
// REJECT:
//   Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00607550 — wrong chain.
// =============================================================================

#include <cstdint>

// BSS vector headers (image zeros; runtime-filled). Layout: unused@0, begin@+4, end@+8.
extern "C" uint8_t DAT_00d029e0[];
extern "C" uint8_t DAT_00d029f0[];

// noreturn throw "invalid vector<T> subscript"
extern "C" void FUN_00608620(void);

extern "C" uint32_t __thiscall Outpost_GetScheduleEntryValueAtCursor_Inferred(void* self)
{
  // Bytes: MOV EAX,ECX; CMP byte [EAX+0x220],0; MOV ECX, tableA/B
  uint8_t* table = (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x220) != 0)
      ? DAT_00d029e0
      : DAT_00d029f0;

  int32_t index = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x23c);
  if (index < 0) {
    return 0;
  }

  uint8_t* begin = *reinterpret_cast<uint8_t**>(table + 4);
  uint32_t size = 0;
  if (begin != nullptr) {
    uint8_t* end = *reinterpret_cast<uint8_t**>(table + 8);
    size = static_cast<uint32_t>((end - begin) >> 4);  // stride 0x10
  }

  if (static_cast<uint32_t>(index) >= size) {
    return 0;
  }

  // In-range gate already passed; recheck matches MSVC vector::operator[] shape.
  if (begin == nullptr || size <= static_cast<uint32_t>(index)) {
    FUN_00608620();  // noreturn
  }

  return *reinterpret_cast<uint32_t*>(begin + static_cast<uint32_t>(index) * 0x10u + 4u);
}
