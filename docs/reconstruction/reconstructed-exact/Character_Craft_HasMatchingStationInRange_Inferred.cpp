// =============================================================================
// Character_Craft_HasMatchingStationInRange_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0052eb90
// Address:   0x0052eb90  (autoassault.exe, image base 0x400000)
// Body:      0x0052eb90–0x0052ed73 exclusive (483 B / 0x1E3)
// System:    inventory-transfer — craft station proximity gate
// Generated: 2026-08-05 R12-021 dual seal (from raw + live disasm)
// Exactness: Behavior-preserving rewrite of decompiler/asm control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NEVER claimed.
// =============================================================================
//
// PURPOSE:
//   Character thiscall bool gate: does the local character have a matching
//   craft/discipline station object within 50.0 surface distance for the
//   selected craft object's DisciplineDef requirements?
//
//   Used by craft host UI as host+0x7e2 and by item tooltip greyscale.
//
// ABI (machine):
//   ECX = Character* (call sites load DAT_00d1b6d8)
//   stack+4 = Object* craftObject (host+0x7cc or tooltip item)
//   AL = 0/1
//   RET 0x4
//
// Bypass:
//   character+0x6b4 > 0  → true
//   DisciplineDef map miss for clonebase+0x4ac → true
//
// Match:
//   Scan TFID vector at MI char-object+0xe7f8; resolve via +0xe4e8;
//   surface distance <= DAT_00a0f524 (50.0f);
//   nearby clonebase short +0x3f4 in {0xD,0xE,0xF} with matching
//   DisciplineDef payload flag at +0x1F0/+0x1F4/+0x1F8 non-zero.
//
// Callees:
//   DisciplineDefMap_TryCopyPayloadById_Inferred (0x0052b040)  [dualed R12-020]
//   FUN_004e5810  (TFID vector materialize @ +0xe7f8)
//   CVOGReaction_ResolveObjectTarget (0x004bae70)
//   Object_SurfaceDistance3D_Inferred (0x0053e510)  [dualed W25-H]
//   operator_delete
// =============================================================================

#include <cstdint>

// External dualed helpers (declarations only; not redefined here)
extern "C" uint8_t __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(int disciplineId, void* outPayload0x1FC);
extern "C" void* __thiscall FUN_004e5810(void* objectWithE7f8, void* outVec); // returns outVec
extern "C" void* __stdcall CVOGReaction_ResolveObjectTarget(void* ctx, uint32_t tfidLo, uint32_t tfidHi);
extern "C" long double __thiscall Object_SurfaceDistance3D_Inferred(void* objA, void* objB);
extern "C" void __cdecl operator_delete(void* p);
extern float DAT_00a0f524; // 50.0f @ 0x00a0f524

// Ghidra twin symbol kept for xref stability
uint8_t __thiscall FUN_0052eb90(int self, int craftObject);

uint8_t __thiscall Character_Craft_HasMatchingStationInRange_Inferred(int self, int craftObject)
{
  // MI-adjusted object* at self+0xa8
  int vb = *reinterpret_cast<int*>(*reinterpret_cast<int*>(self + 4) + 4);
  int charObj = *reinterpret_cast<int*>(vb + self + 0xa8);

  if (charObj == 0 || craftObject == 0) {
    return 0;
  }

  // Free / RE-open bypass
  if (*reinterpret_cast<int*>(self + 0x6b4) > 0) {
    return 1;
  }

  // DisciplineDef payload (0x1FC). Tail three dwords = station-type flags.
  alignas(4) uint8_t discBuf[0x1FC];
  int itemGame = *reinterpret_cast<int*>(craftObject + 0xa8);
  int cloneDef = *reinterpret_cast<int*>(itemGame + 0x3c);
  int disciplineId = *reinterpret_cast<int*>(cloneDef + 0x4ac);

  if (DisciplineDefMap_TryCopyPayloadById_Inferred(disciplineId, discBuf) == 0) {
    return 1; // no discipline row → gate open
  }

  const int flagD = *reinterpret_cast<int*>(discBuf + 0x1F0);
  const int flagE = *reinterpret_cast<int*>(discBuf + 0x1F4);
  const int flagF = *reinterpret_cast<int*>(discBuf + 0x1F8);

  // Loop index is a byte in the original (local_21d); wrap is live oddity preserved.
  uint8_t idx = 0;
  for (;;) {
    // --- first materialize for count ---
    uint8_t tmpVecA[0x10]; // begin/end/capacity-shaped; exact std layout open
    // Live: ECX=charObj; out on stack; FUN_004e5810 copies vector @ charObj+0xe7f8
    void* vecA = FUN_004e5810(reinterpret_cast<void*>(charObj), tmpVecA);
    int* beginA = *reinterpret_cast<int**>(reinterpret_cast<char*>(vecA) + 4);
    int* endA   = *reinterpret_cast<int**>(reinterpret_cast<char*>(vecA) + 8);
    uint32_t count = 0;
    if (beginA != nullptr) {
      count = static_cast<uint32_t>(
          (reinterpret_cast<char*>(endA) - reinterpret_cast<char*>(beginA)) >> 3);
    }
    // Live always zero-clears the temp vector after measuring (delete if owned).
    void* ownedA = *reinterpret_cast<void**>(tmpVecA + 4); // decompiler local_218
    // NOTE: exact std::vector member offsets follow live stack layout; CF only.
    (void)ownedA;

    if (static_cast<uint32_t>(idx) >= count) {
      return 0;
    }

    // --- second materialize for element load (matches dual CALL pattern) ---
    uint8_t tmpVecB[0x10];
    void* vecB = FUN_004e5810(reinterpret_cast<void*>(charObj), tmpVecB);
    int* beginB = *reinterpret_cast<int**>(reinterpret_cast<char*>(vecB) + 4);

    uint32_t lo = static_cast<uint32_t>(beginB[static_cast<int>(idx) * 2 + 0]);
    uint32_t hi = static_cast<uint32_t>(beginB[static_cast<int>(idx) * 2 + 1]);

    void* ctx = *reinterpret_cast<void**>(charObj + 0xe4e8);
    int* nearObj = reinterpret_cast<int*>(
        CVOGReaction_ResolveObjectTarget(ctx, lo, hi));

    if (nearObj != nullptr) {
      auto** vtbl = reinterpret_cast<void**>(*nearObj);
      using Fn0 = int(__thiscall*)(void*);
      using Fn1 = void*(__thiscall*)(void*);
      using FnPush = void*(__thiscall*)(void*, void*);

      int hasPose = reinterpret_cast<Fn0>(vtbl[0x1c8 / 4])(nearObj);
      if (hasPose != 0) {
        void* poseB = reinterpret_cast<Fn1>(vtbl[0x1c8 / 4])(nearObj);

        // Player MI subobject used as this for vtbl+0x19c
        int* charSub = reinterpret_cast<int*>(vb + self + 4);
        auto** subVtbl = reinterpret_cast<void**>(*charSub);
        void* poseA = reinterpret_cast<FnPush>(subVtbl[0x19c / 4])(charSub, poseB);

        long double dist = Object_SurfaceDistance3D_Inferred(poseA, poseB);
        if (dist <= static_cast<long double>(DAT_00a0f524)) {
          int nearGame = nearObj[0x2a]; // +0xa8
          int nearDef = *reinterpret_cast<int*>(nearGame + 0x3c);
          short subtype = *reinterpret_cast<short*>(nearDef + 0x3f4);

          if (subtype == 0x0D) {
            if (flagD != 0) return 1;
          } else if (subtype == 0x0E) {
            if (flagE != 0) return 1;
          } else if (subtype == 0x0F) {
            if (flagF != 0) return 1;
          }
        }
      }
    }

    idx = static_cast<uint8_t>(idx + 1);
  }
}

// Keep Ghidra symbol as alias entry for coverage tools.
uint8_t __thiscall FUN_0052eb90(int self, int craftObject)
{
  return Character_Craft_HasMatchingStationInRange_Inferred(self, craftObject);
}
