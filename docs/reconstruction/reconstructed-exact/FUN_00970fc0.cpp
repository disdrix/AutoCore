// =============================================================================
// FUN_00970fc0  (twin of AssPreloader_DrainAcRingToTree_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00970fc0
// Address:   0x00970fc0–0x00971024 inclusive (101 B / 0x65)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W37-AD 2026-08-04
// Exactness: Behavior-preserving; register ABI from body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct PodU32U8 {
  std::uint32_t key;
  std::uint8_t  flag;
};

extern "C" void FUN_0043d6f0(void /*EAX=PodU32U8**/);
extern "C" std::uint8_t FUN_0043e850(void /*ESI=ring, EDI=out*/);
extern "C" std::uint32_t* __fastcall FUN_0043d700(const std::uint32_t* key /*ECX*/
                                                   /*EDI=tree*/);
extern "C" void FUN_0043d770(void /*EAX=tree, ECX=key**/);

// Retail entry: host pointer in EAX.
extern "C" void FUN_00970fc0(void /*EAX = AssPreloader* host*/)
{
  // --- byte-faithful control flow (host modeled as in_EAX) ---
  // PUSH EBP; MOV EBP,ESP; AND ESP,-8; SUB ESP,0xC
  // PUSH EBX; PUSH ESI; MOV EBX,EAX; PUSH EDI
  PodU32U8 local{};
  // LEA EAX,[local]; CALL FUN_0043d6f0
  FUN_0043d6f0(); // EAX=&local in retail

  // LEA ESI,[EBX+0xAC]; LEA EDI,[local]; CALL FUN_0043e850
  std::uint8_t have = FUN_0043e850(); // ESI=host+0xAC, EDI=&local
  if (have == 0) {
    return;
  }

  // ADD EBX,0xDC  — tree base for all subsequent iterations
  // void* tree = host + 0xDC;  (EBX)

  for (;;) {
    // CMP byte [local.flag], 0; LEA ECX,[local.key]
    if (local.flag == 0) {
      // MOV EAX,EBX; CALL FUN_0043d770
      FUN_0043d770(); // EAX=tree, ECX=&local.key
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
  // POP EDI; POP ESI; POP EBX; MOV ESP,EBP; POP EBP; RET
}
