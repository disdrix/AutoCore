// =============================================================================
// PhysSim_MergeHosts_Inferred  (FUN_00560a30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560a30
// Address:   0x00560a30  (autoassault.exe, image base 0x400000)
// Body:      0x00560a30 – 0x00560c8b
// System:    physics / island host glue
// Generated: 2026-07-29 W20-B dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Merge physics host/island `src` into `dest` under world/sim ECX:
//   activate both if needed, splice owned vectors/lists, rebind back-pointers,
//   swap-remove src from world host table, destroy src, return dest.
//
// ABI
//   __thiscall; ECX = World*; two stack Host*; RET 0x8; returns dest*
//
// CALLER
//   PhysSim_FlushPendingBodyPairs_Inferred (0x00561320) when body+0x44 hosts differ
// =============================================================================

#include <cstdint>

struct World;
struct Host;

// External callees
extern "C" void FUN_0055eb80(Host *host);                 // PhysSim_ActivateHost
extern "C" void FUN_00560750(void *destList, void *srcList); // merge @ host+0x68
extern "C" void FUN_005b3300(void *vec, int newCap, int elemSize);

struct Host {
  void **vtbl; // +0x00; (*vtbl)(this, 1) scalar delete
  // +0x08 max scalar; +0x0c..+0x18 additive scalars
  // +0x24 world table index
  // +0x28 dirty u8; +0x29 activated u8
  // vectors at +0x3c / +0x4c / +0x58 / +0x74; list at +0x68
};

// Capacity mask used throughout retail vector grow
static inline int Cap(uint32_t raw) { return (int)(raw & 0x7fffffffu); }

static void GrowIfNeeded(uint32_t *vecBase /* data,count,cap */, int need,
                         int elemSize) {
  // vecBase[0]=data, [1]=count, [2]=cap (with high bit)
  if (Cap(vecBase[2]) < need) {
    int c = Cap(vecBase[2]) * 2;
    if (c <= need)
      c = need;
    FUN_005b3300(vecBase, c, elemSize);
  }
}

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile / raw
// ---------------------------------------------------------------------------

Host *__thiscall PhysSim_MergeHosts_Inferred(World *world, // ECX
                                             Host *dest,   // survivor
                                             Host *src)    // absorbed
{
  if (dest == src)
    return dest;

  // Activated flag at +0x29; 0 → ensure active in sim
  if (*((uint8_t *)dest + 0x29) == 0)
    FUN_0055eb80(dest);
  if (*((uint8_t *)src + 0x29) == 0)
    FUN_0055eb80(src);

  // Merge list objects at host+0x68 (dword index 0x1a)
  FUN_00560750((char *)dest + 0x68, (char *)src + 0x68);

  // ---- vector A: +0x3c data / +0x40 count / +0x44 capacity (elem size 4) ----
  {
    uint32_t *d = (uint32_t *)((char *)dest + 0x3c);
    uint32_t *s = (uint32_t *)((char *)src + 0x3c);
    int base = (int)d[1];
    int need = (int)s[1] + base;
    GrowIfNeeded(d, need, 4);
    d[1] = (uint32_t)need;
    for (int i = 0; i < (int)s[1]; i++) {
      uint32_t item = ((uint32_t *)s[0])[i];
      ((uint32_t *)d[0])[base + i] = item;
      *(Host **)((char *)(uintptr_t)item + 0x44) = dest; // body→host
      *(int *)((char *)(uintptr_t)item + 0x58) = base + i;
    }
  }

  // ---- vector B: +0x4c / +0x50 / +0x54 (elem 4); item+0x10 = host ----
  {
    uint32_t *d = (uint32_t *)((char *)dest + 0x4c);
    uint32_t *s = (uint32_t *)((char *)src + 0x4c);
    int base = (int)d[1];
    int need = (int)s[1] + base;
    GrowIfNeeded(d, need, 4);
    d[1] = (uint32_t)need;
    for (int i = 0; i < (int)s[1]; i++) {
      uint32_t item = ((uint32_t *)s[0])[i];
      ((uint32_t *)d[0])[base + i] = item;
      *(Host **)((char *)(uintptr_t)item + 0x10) = dest;
    }
  }

  // ---- vector C: +0x58 / +0x5c / +0x60 (elem 4); item+0x14 = host ----
  {
    uint32_t *d = (uint32_t *)((char *)dest + 0x58);
    uint32_t *s = (uint32_t *)((char *)src + 0x58);
    int base = (int)d[1];
    int need = (int)s[1] + base;
    GrowIfNeeded(d, need, 4);
    d[1] = (uint32_t)need;
    for (int i = 0; i < (int)s[1]; i++) {
      uint32_t item = ((uint32_t *)s[0])[i];
      ((uint32_t *)d[0])[base + i] = item;
      *(Host **)((char *)(uintptr_t)item + 0x14) = dest;
    }
  }

  // Scalars: max at +0x08; add +0x0c, +0x10, +0x18, +0x14
  {
    int *di = (int *)dest;
    int *si = (int *)src;
    int m = si[2];
    if (m < di[2])
      m = di[2];
    di[2] = m;
    di[3] += si[3];
    di[4] += si[4];
    di[6] += si[6];
    di[5] += si[5];
  }

  // ---- vector D: +0x74 / +0x78 / +0x7c (elem size 8) ----
  {
    uint32_t *d = (uint32_t *)((char *)dest + 0x74);
    uint32_t *s = (uint32_t *)((char *)src + 0x74);
    int base = (int)d[1];
    int need = (int)s[1] + base;
    GrowIfNeeded(d, need, 8);
    d[1] = (uint32_t)need;
    for (int i = 0; i < (int)s[1]; i++) {
      uint32_t *from = (uint32_t *)(s[0] + (uint32_t)(i * 8));
      uint32_t *to = (uint32_t *)(d[0] + (uint32_t)((base + i) * 8));
      to[0] = from[0];
      to[1] = from[1];
    }
  }

  // World host table swap-remove src (index at src+0x24)
  {
    int srcIndex = *(int *)((char *)src + 0x24);
    Host **table = *(Host ***)((char *)world + 0x08);
    int count = *(int *)((char *)world + 0x0c);
    Host *moved = table[count - 1];
    table[srcIndex] = moved;
    *(int *)((char *)moved + 0x24) = srcIndex;
    *(int *)((char *)world + 0x0c) = count - 1;
  }

  // Dirty flag +0x28: 0 only if both were 0; else 1. Then destroy src.
  uint8_t dDirty = *((uint8_t *)dest + 0x28);
  uint8_t sDirty = *((uint8_t *)src + 0x28);
  if (dDirty == 0 && sDirty == 0)
    *((uint8_t *)dest + 0x28) = 0;
  else
    *((uint8_t *)dest + 0x28) = 1;

  // (*src->vtbl)(src, 1) — scalar deleting destructor
  ((void(__thiscall *)(Host *, int)) * (void **)src)(src, 1);
  return dest;
}

// Ghidra symbol alias
Host *__thiscall FUN_00560a30(World *world, Host *dest, Host *src) {
  return PhysSim_MergeHosts_Inferred(world, dest, src);
}
