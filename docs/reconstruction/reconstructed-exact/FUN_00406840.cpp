// =============================================================================
// FUN_00406840  (canonical: LogicUiEventQueue_Resize)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406840
// Address:   0x00406840 – 0x004068e7  (168 B; autoassault.exe, image base 0x400000)
// System:    client-logic-ui / event queue
// Generated: 2026-07-29 W24-E dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/LogicUiEventQueue_Resize.cpp
// =============================================================================

#include <cstdint>

static constexpr std::uint32_t kStride = 0x138u;

extern "C" void* FUN_00407640(void* q, void* outIt, void* first, void* last);
extern "C" void __thiscall FUN_004076a0(void* q, void* insertAt, std::uint32_t count, const void* valueSrc);

// Ghidra: FUN_00406840
// ABI: ECX=queue; EAX=newCount; stack value[0x138] by-value; RET 0x138
void __fastcall FUN_00406840(int param_1 /*ECX queue*/)
{
  std::uint32_t in_EAX; // newCount — live in EAX on entry (caller-supplied)
  std::uint32_t uVar1;
  int iVar2;

  // NOTE: value POD is at &stack0x00000004 for 0x138 bytes (not modeled as C param).

  iVar2 = *reinterpret_cast<int*>(param_1 + 4); // begin
  if (iVar2 == 0) {
    uVar1 = 0;
  } else {
    uVar1 = static_cast<std::uint32_t>(
        (*reinterpret_cast<int*>(param_1 + 8) - iVar2) / static_cast<int>(kStride));
  }

  if (in_EAX <= uVar1) {
    if ((iVar2 != 0) &&
        (in_EAX < static_cast<std::uint32_t>(
             (*reinterpret_cast<int*>(param_1 + 8) - iVar2) / static_cast<int>(kStride)))) {
      // erase [begin + newCount*0x138, end)
      FUN_00407640(
          reinterpret_cast<void*>(param_1),
          /* &stack value as out-it storage */ nullptr,
          reinterpret_cast<void*>(iVar2 + static_cast<int>(in_EAX * kStride)),
          *reinterpret_cast<void**>(param_1 + 8));
    }
    return; // ret 0x138
  }

  if (iVar2 == 0) {
    iVar2 = 0;
  } else {
    iVar2 = (*reinterpret_cast<int*>(param_1 + 8) - iVar2) / static_cast<int>(kStride);
  }
  // InsertN(queue=ECX, insertAt=end, count=new-size, value=&stack)
  FUN_004076a0(
      reinterpret_cast<void*>(param_1),
      *reinterpret_cast<void**>(param_1 + 8),
      in_EAX - static_cast<std::uint32_t>(iVar2),
      /* &stack value */ nullptr);
  return; // ret 0x138
}
