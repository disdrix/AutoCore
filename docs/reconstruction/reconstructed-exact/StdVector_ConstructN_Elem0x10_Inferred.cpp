// =============================================================================
// StdVector_ConstructN_Elem0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409e20
// Address:   0x00409e20  (autoassault.exe, image base 0x400000)
// Body:      0x00409e20–0x00409e82 inclusive (99 B / 0x63); RET (C3) cdecl
// System:    util / container (std::vector elem stride 0x10)
// Generated: 2026-08-05 MEGA-044 dual seal (raw + live decompile + disasm + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-05).
// Ghidra:    FUN_00409e20
// Prior:     Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409e20
//            (scaffold RETIRED — role is ConstructN 0x10, not PollBound leaf)
// =============================================================================
//
// PURPOSE:
//   Uninitialized ConstructN / fill-N for 0x10-byte POD elements from a single
//   fixed template (source not advanced):
//     for (i = 0; i < count; ++i)
//       PodCopy0x10(dest + i*0x10, value);
//
// ABI (cdecl — sealed from disassembly + call sites):
//   ECX        = const void* value   (template; held in EBX across loop)
//   stack arg0 = void* dest          ([EBP+8]; advanced +0x10 per iter)
//   stack arg1 = int count           ([EBP+0xc])
//   callers push 4 dwords + ADD ESP,0x10 (2 phantom slots unused by body)
//   return     = void; RET (C3) — no callee stack pop
//
// CALLEE:
//   FUN_00409f70 — PodCopy 0x10: if (EAX!=0) copy 4 dwords *ECX → *EAX
//
// PARENTS:
//   FUN_00407000 — thin wrapper: call this, return dest+count*0x10 (residual)
//     used by dualed InsertN FUN_00408640 (StdVector_InsertN_Elem0x10_Inferred)
//   FUN_00930360 — SortTargetListByViewAngle capacity-hit push (count=1)
//
// TWINS (CF shape):
//   StdVector_ConstructN_Elem0x28_Inferred @ 0x00409d40
//   StdVector_ConstructN_Elem12_Inferred   @ 0x00409db0
// =============================================================================

#include <cstdint>

// PodCopy 0x10 — undualed residual leaf (EAX=dest, ECX=src).
extern "C" void FUN_00409f70(
    /*ECX*/ const void* src
    /*EAX dest implicit*/);

extern "C" void StdVector_ConstructN_Elem0x10_Inferred(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count)
{
  // Bytes: SEH frame (LAB_009bc610), state=0 for loop body.
  // EBX = value (fixed); ESI = dest; EDI = count.
  for (; count != 0; --count) {
    // MOV ECX,EBX; MOV EAX,ESI; CALL FUN_00409f70
    // FUN_00409f70: if (dest) { copy 4x uint32 from *value to *dest }
    if (dest != nullptr) {
      const auto* src = static_cast<const uint32_t*>(value);
      auto* dst = static_cast<uint32_t*>(dest);
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
    }
    dest = static_cast<uint8_t*>(dest) + 0x10u;
  }
  // SEH state=-1; unlink FS:[0]; RET (C3)
}

// Scaffold alias (Ghidra name) — same body.
extern "C" void FUN_00409e20(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count)
{
  StdVector_ConstructN_Elem0x10_Inferred(value, dest, count);
}
