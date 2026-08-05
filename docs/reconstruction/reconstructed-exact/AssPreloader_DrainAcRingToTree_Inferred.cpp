// =============================================================================
// AssPreloader_DrainAcRingToTree_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970fc0
// Address:   0x00970fc0–0x00971024 inclusive (101 B / 0x65)
// Module:    autoassault.exe (image base 0x400000)
// System:    assPreloader / asset preload pipeline
// Wave:      W37-AD 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
//            Decompiler void/no-arg display corrected: host in EAX.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Drain the AssPreloader locked ring at host+0xAC ({u32 key, u8 flag}).
//   For each popped entry:
//     flag != 0 → find-or-insert key in membership tree host+0xDC, set value=1
//     flag == 0 → fail-path helper FUN_0043d770 on the same tree
//   Called before preload child-asset attempts and inside the preload worker loop.
//
// RELATED:
//   Callers: AssPreloader_TryPreloadChildAssetsForAbsentKeys (0x00971280, W32-J)
//            AssPreloader_PreloadWorkerLoop (0x00972140, W32-K)
//   Ring pop: FUN_0043e850 (ESI=ring, EDI=out entry, AL success)
//   Tree find-or-insert: FUN_0043d700 (ECX=key*, EDI=tree) → value*
//   Entry zero: FUN_0043d6f0 (EAX=entry*)
//
// ABI: host in EAX; no stack args; bare RET; void.
// =============================================================================

#include <cstdint>

struct PodU32U8 {
  std::uint32_t key;   // +0x00
  std::uint8_t  flag;  // +0x04
};

// Nested helpers (owned elsewhere; ABI as used at this site).
extern "C" void FUN_0043d6f0(void /*EAX=PodU32U8**/);
extern "C" std::uint8_t FUN_0043e850(void /*ESI=ring, EDI=out entry*/);
extern "C" std::uint32_t* __fastcall FUN_0043d700(const std::uint32_t* key /*ECX*/
                                                   /*EDI=tree*/);
extern "C" void FUN_0043d770(void /*EAX=tree, ECX=key**/);

// Ghidra: FUN_00970fc0
// Retail entry: AssPreloader* host in EAX (not ECX thiscall).
extern "C" void AssPreloader_DrainAcRingToTree_Inferred(void /*EAX = AssPreloader* host*/)
{
  // PUSH EBP; MOV EBP,ESP; AND ESP,-8; SUB ESP,0xC
  // PUSH EBX; PUSH ESI; MOV EBX,EAX; PUSH EDI
  PodU32U8 local{};
  // LEA EAX,[local]; CALL FUN_0043d6f0  — *key=0, flag=0
  FUN_0043d6f0();

  // LEA ESI,[EBX+0xAC]; LEA EDI,[local]; CALL FUN_0043e850
  std::uint8_t have = FUN_0043e850();
  if (have == 0) {
    return;
  }

  // ADD EBX,0xDC once — tree = host+0xDC for remainder of drain
  for (;;) {
    // CMP [local.flag],0; LEA ECX,[local.key]
    if (local.flag == 0) {
      // MOV EAX,EBX; CALL FUN_0043d770
      FUN_0043d770();
    } else {
      // MOV EDI,EBX; CALL FUN_0043d700; MOV dword [EAX],1
      std::uint32_t* val = FUN_0043d700(&local.key);
      *val = 1;
    }
    // LEA EDI,[local]; CALL FUN_0043e850; TEST AL; JNZ body
    have = FUN_0043e850();
    if (have == 0) {
      break;
    }
  }
  // POP EDI; POP ESI; POP EBX; leave; RET
}

// Ghidra twin name
extern "C" void FUN_00970fc0(void /*EAX=host*/)
{
  AssPreloader_DrainAcRingToTree_Inferred();
}
