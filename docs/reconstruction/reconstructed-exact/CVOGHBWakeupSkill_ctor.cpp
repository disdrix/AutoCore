// =============================================================================
// CVOGHBWakeupSkill_ctor  (was FUN_006061e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006061e0
// Address:   0x006061e0 – 0x00606353  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / heartbeat
// Generated: 2026-07-29 W19-G OWN dual A/B seal
//            three-rep: raw 2026-07-23 ≡ live decompile ≡ read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Class:     CVOGHBWakeupSkill (RTTI Confirmed ".?AVCVOGHBWakeupSkill@@" @ 0x00af48f0)
// Vtbl:      PTR_FUN_009de7b4 (install at +0x00)
// Size:      0x674 (operator_new at callers)
// =============================================================================

// PURPOSE
// Construct delayed-skill apply heartbeat after CVOGHBBase_ctor:
//   - install CVOGHBWakeupSkill vtbl
//   - embed skill runtime blob at +0x24 (0x630 bytes / 0x18c dwords)
//   - seed world (+0x654), skipBusy byte (+0x658), pos (+0x66c), seed (+0x670)
//   - zero TFID vector at +0x65c (+0x660 begin / +0x664 end / +0x668 cap)
//   - period seeds +0x0C/+0x10 = 1; +0x08 = type/period arg
//   - AttachOwnerObject(host)
//   - append TFID list until invalid; always append DAT_009de7a0 sentinel
// Returns this. Callers: Skill_ApplyStatusEffectLocal (delay>=1), ApplyLocalById.

#include <cstdint>

extern "C" void* PTR_FUN_009de7b4[];
extern "C" uint32_t DAT_009de7a0[4]; // invalid TFID: {-1,-1,0,0}

extern void __thiscall CVOGHBBase_ctor(void* thisHb);
extern void __thiscall CVOGHBBase_AttachOwnerObject(void* thisHb, void* owner);

// Vector grow/insert at end (thiscall ECX = vector base @ thisHb+0x65c).
// Decompiler often surfaces end pointer as first formal; ECX is container.
extern void __thiscall FUN_004cbfc0(void* vec, void* insertAt, unsigned count,
                                    const void* value16);

// Copy count × 16-byte TFID elements from src to dest (fill helper).
extern void FUN_00608720(void* dest, int count, const void* src);

static inline int TfidList_IsValid(const int* p)
{
  // while ((*p != -1 || p[1] != -1) || ((char)p[2] != 0))
  return !(*p == -1 && p[1] == -1 && (char)p[2] == 0);
}

void* /*CVOGHBWakeupSkill**/ __thiscall CVOGHBWakeupSkill_ctor(
    void* thisHb /* ECX */,
    uint32_t skillTypeOrPeriodSeed, // stack+0x04 → +0x08
    void* hostObject,               // stack+0x08 → AttachOwner
    uint32_t* skillBlobSrc,         // stack+0x0C → +0x24 (0x18c dwords)
    void* world,                    // stack+0x10 → +0x654
    int* tfidList,                  // stack+0x14 → vector of 16 B elems
    void* pos,                      // stack+0x18 → +0x66c
    uint32_t seed,                  // stack+0x1C → +0x670
    uint32_t flagWord)              // stack+0x20 low byte → +0x658
{
  // SEH frame omitted (LAB_009a8106); state -1 then 1 after seed.

  CVOGHBBase_ctor(thisHb);

  *reinterpret_cast<void***>(thisHb) = PTR_FUN_009de7b4;

  // rep movsd: 0x18c dwords from skillBlobSrc → this+0x24
  uint32_t* dst = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(thisHb) + 0x24);
  uint32_t* src = skillBlobSrc;
  for (int i = 0x18c; i != 0; --i) {
    *dst++ = *src++;
  }

  *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x654) = world;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(thisHb) + 0x658) =
      static_cast<uint8_t>(flagWord);

  // TFID vector: begin/end/cap at +0x660/+0x664/+0x668 (container base +0x65c)
  *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x660) = nullptr;
  *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x664) = nullptr;
  *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x668) = nullptr;

  *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x66c) = pos;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(thisHb) + 0x0C) = 1;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(thisHb) + 0x10) = 1;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(thisHb) + 0x670) = seed;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(thisHb) + 0x08) = skillTypeOrPeriodSeed;

  CVOGHBBase_AttachOwnerObject(thisHb, hostObject);

  void* vecBase = reinterpret_cast<char*>(thisHb) + 0x65c;
  int* cursor = tfidList;

  while (TfidList_IsValid(cursor)) {
    void* begin = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x660);
    void* end   = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x664);
    void* cap   = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x668);

    const bool needGrow =
        (begin == nullptr) ||
        ((((uintptr_t)cap - (uintptr_t)begin) >> 4) <=
         (((uintptr_t)end - (uintptr_t)begin) >> 4));

    if (needGrow) {
      // Decomp surface: FUN_004cbfc0(end, 1, cursor) with ECX = vecBase
      FUN_004cbfc0(vecBase, end, 1, cursor);
    } else {
      FUN_00608720(end, 1, cursor);
      *reinterpret_cast<char**>(reinterpret_cast<char*>(thisHb) + 0x664) =
          reinterpret_cast<char*>(end) + 0x10;
    }
    cursor += 4; // next 16-byte TFID
  }

  // Always append invalid sentinel DAT_009de7a0
  {
    void* begin = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x660);
    void* end   = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x664);
    void* cap   = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x668);
    const bool needGrow =
        (begin == nullptr) ||
        ((((uintptr_t)cap - (uintptr_t)begin) >> 4) <=
         (((uintptr_t)end - (uintptr_t)begin) >> 4));
    if (needGrow) {
      FUN_004cbfc0(vecBase, end, 1, DAT_009de7a0);
    } else {
      FUN_00608720(end, 1, DAT_009de7a0);
      *reinterpret_cast<char**>(reinterpret_cast<char*>(thisHb) + 0x664) =
          reinterpret_cast<char*>(end) + 0x10;
    }
  }

  return thisHb;
}

// Ghidra alias
extern "C" void* __thiscall FUN_006061e0(
    void* thisHb,
    uint32_t a2, void* a3, uint32_t* a4, void* a5,
    int* a6, void* a7, uint32_t a8, uint32_t a9)
{
  return CVOGHBWakeupSkill_ctor(thisHb, a2, a3, a4, a5, a6, a7, a8, a9);
}
