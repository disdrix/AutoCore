// =============================================================================
// SoftCastHitList_QuickSortRange_KeyFloat14_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00489f20
// Address:   0x00489f20 – 0x0048a05d inclusive (318 B / 0x13E)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-115 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00489f20
// =============================================================================
//
// PURPOSE
//   Hoare-partition quicksort over a soft-cast hit array:
//     - element stride 0x30
//     - ascending sort key = float at element +0x14
//     - mid-index pivot ((lo+hi)>>1)
//     - partial element swap (7 dwords; see layout)
//   Sole external caller: SoftCastHitList_SortIfCountGt1_Inferred (0x0048a060)
//   which gates on count>1 and passes [0, count-1].
//
// ABI (sealed)
//   cdecl: (void *base, int lo, int hi, uint32_t cookie)
//   void return; bare RET (C3)
//   Caller cleans 0x10 (ADD ESP,0x10) at both external and recursive sites.
//   cookie is unused in compare/swap; recursive path re-pushes it only.
//
// HIT ELEMENT (stride 0x30) — fields touched by swap
//   +0x00  dword / float  (swapped; FPU load as float at head)
//   +0x04  dword / float  (swapped)
//   +0x08  dword          (swapped)
//   +0x0C  dword          (swapped)
//   +0x10  dword          (swapped)
//   +0x14  float          (swapped)  **sort key**
//   +0x18  dword          (NOT swapped)
//   +0x1C  dword          (NOT swapped)
//   +0x20  dword          (swapped)  hub walk uses as object-related slot
//   +0x24  dword          (NOT swapped)
//   +0x28  dword          (NOT swapped)
//   +0x2C  dword          (NOT swapped)
//
// ODD BEHAVIOR PRESERVED
//   - Partial swap: +0x18..+0x1C and +0x24..+0x2C stay put across exchange.
//   - cookie 4th arg is dead weight (parent seeds this&0xFFFFFF00).
//   - Equal keys do not advance left/right scans (strict < only).
//   - Right partition is iterative (tail); left is recursive.
//
// READABILITY
//   - Decompiler void/undefined return: assembly bare RET, no EAX contract.
//   - FPU TEST AH,0x5 / JP reconstructed as float < comparisons.
// =============================================================================

#include <cstdint>

struct SoftCastHitElem0x30 {
  uint32_t f00;     // +0x00
  uint32_t f04;     // +0x04
  uint32_t f08;     // +0x08
  uint32_t f0c;     // +0x0C
  uint32_t f10;     // +0x10
  float    key14;   // +0x14  sort key
  uint32_t f18;     // +0x18  NOT swapped
  uint32_t f1c;     // +0x1C  NOT swapped
  uint32_t f20;     // +0x20  swapped (object-related slot in hub walk)
  uint32_t f24;     // +0x24  NOT swapped
  uint32_t f28;     // +0x28  NOT swapped
  uint32_t f2c;     // +0x2C  NOT swapped
};

static_assert(sizeof(SoftCastHitElem0x30) == 0x30, "hit elem stride");

// Partial swap matching assembly at 0x00489fa1..0x0048a028.
static void SoftCastHit_SwapPartial(SoftCastHitElem0x30 *a,
                                    SoftCastHitElem0x30 *b)
{
  uint32_t t00 = a->f00;
  uint32_t t04 = a->f04;
  uint32_t t08 = a->f08;
  uint32_t t0c = a->f0c;
  uint32_t t10 = a->f10;
  float    t14 = a->key14;
  uint32_t t20 = a->f20;

  a->f00   = b->f00;
  a->f04   = b->f04;
  a->f08   = b->f08;
  a->f0c   = b->f0c;
  a->f10   = b->f10;
  a->key14 = b->key14;
  a->f20   = b->f20;

  b->f00   = t00;
  b->f04   = t04;
  b->f08   = t08;
  b->f0c   = t0c;
  b->f10   = t10;
  b->key14 = t14;
  b->f20   = t20;
  // f18, f1c, f24, f28, f2c intentionally untouched
}

// cdecl; void; bare RET
extern "C" void __cdecl SoftCastHitList_QuickSortRange_KeyFloat14_Inferred(
    SoftCastHitElem0x30 *base,
    int lo,
    int hi,
    uint32_t cookie /* unused */)
{
  // AND ESP,0xFFFFFFF0; SUB ESP,0x64 — aligned pivot temp (not modeled)
  do {
    // pivot = base[(lo+hi)>>1].key14
    float pivot = base[(lo + hi) >> 1].key14;
    int j = hi; // EDX
    int i = lo; // ESI

    do {
      // while base[i].key14 < pivot: i++
      while (base[i].key14 < pivot) {
        i++;
      }
      // while pivot < base[j].key14: j--
      while (pivot < base[j].key14) {
        j--;
      }
      if (j < i) {
        break;
      }
      if (j != i) {
        SoftCastHit_SwapPartial(&base[j], &base[i]);
      }
      j--;
      i++;
    } while (i <= j);

    // recurse left partition
    if (lo < j) {
      SoftCastHitList_QuickSortRange_KeyFloat14_Inferred(base, lo, j, cookie);
    }

    // tail right: lo = i; continue if lo < hi
    lo = i;
    if (hi <= i) {
      return;
    }
  } while (true);
}

// Scaffold twin: docs/reconstruction/reconstructed-exact/FUN_00489f20.cpp
