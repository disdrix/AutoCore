// =============================================================================
// HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Get-or-create next 0x14c host from EDI-owned pointer vector
//           (cursor +0x44, begin +0x4c, end +0x50). On miss: allocate
//           0x14c + 0xC4 material, load PalDiffMap.fx / DiffuseMap, wire via
//           FUN_007647c0, grow vector, store, return new host.
//
// Address:  0x0073cb70  (autoassault.exe, image base 0x400000)
// Body:     0x0073cb70–0x0073cd69 (506 B / 0x1FA)
// Stable:   aa_0073cb70
// System:   EDI host vector / PalDiffMap material
// Ghidra:   FUN_0073cb70
//
// Callers:  FUN_0073d020 @ 0x0073d025, FUN_0073d0a0 @ 0x0073d0a5
// Family:   related construction pair to W35-E HostPtrTable12 slot 0x14c/0xC4
//
// Exactness: CF mirrors raw + read_memory; names structural _Inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W36-G seal).
// =============================================================================

#include <cstdint>

extern void *operator_new(unsigned size);
extern void *FUN_00764030(void *self /* ECX */);
extern void *FUN_00748960(void *self /* ECX */);
extern void FUN_00989e00(void *out, const char *name);
extern void FUN_009701d0(void *fx_ref);
extern void *FUN_00752310(void *io, const char *param_name);
extern void FUN_0096f0e0(int fmt, void *dims, int a, int b, int c, int d);
extern void FUN_00970060(int param_idx, int stage);
extern void FUN_0096efd0(void);
extern void FUN_0098ef00(void *local_mat);
extern void FUN_0098f2b0(int value);
extern void FUN_00749d10(void *local_mat);
extern void FUN_007647c0(void *host14c /* ECX */, void *material);
extern void FUN_004367f0(void *vec_hdr /* ECX */, uint32_t new_count, uint32_t fill);
extern void FUN_00457a00(void *local_mat);
extern uint32_t DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;
extern float g_flMultiKillCountBlend;

/* EDI host layout (sealed offsets):
     +0x44  uint32_t cursor
     +0x48  vector header (grow thiscall target)
     +0x4c  void **begin
     +0x50  void **end
*/

struct HostEDI_VecCursor44 {
  uint8_t pad0[0x44];
  uint32_t cursor;       /* +0x44 */
  uint8_t vec_hdr[4];    /* +0x48 — grow header base for FUN_004367f0 */
  void **begin;          /* +0x4c */
  void **end;            /* +0x50 */
};

void *HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred(HostEDI_VecCursor44 *host /* EDI */)
{
  uint32_t count;
  uint32_t cur;
  void *host14c;
  void *material;
  void *fx_name_holder;
  void **param_io;
  int param_idx;
  uint32_t dims[2];
  uint8_t local_mat[0x30];
  uint32_t *mat_tail;

  if (host->begin == 0) {
    count = 0;
  } else {
    count = (uint32_t)((uintptr_t)host->end - (uintptr_t)host->begin) >> 2;
  }

  cur = host->cursor;
  if (cur < count) {
    host14c = host->begin[cur];
    host->cursor = cur + 1;
    return host14c;
  }

  /* Slow path: construct 0x14c host + 0xC4 material with PalDiffMap.fx */
  host14c = operator_new(0x14c);
  if (host14c == 0) {
    host14c = 0;
  } else {
    host14c = FUN_00764030(host14c);
  }

  material = operator_new(0xc4);
  if (material != 0) {
    material = FUN_00748960(material);
  } else {
    material = 0;
  }

  FUN_00989e00(&fx_name_holder, "PalDiffMap.fx");
  FUN_009701d0(&fx_name_holder);
  param_io = &fx_name_holder;
  if (material == 0 || *((uint32_t *)material + 8) == 0) {
    fx_name_holder = (void *)(uintptr_t)-1;
  } else {
    param_io = (void **)FUN_00752310(param_io, "DiffuseMap");
  }
  fx_name_holder = *param_io;
  param_idx = (int)(intptr_t)fx_name_holder;
  if (param_idx >= 0) {
    dims[0] = 0x10;
    dims[1] = 0x10;
    FUN_0096f0e0(0x16, dims, 1, 1, 1, 0);
    FUN_00970060(param_idx, 0);
    FUN_0096efd0();
  }

  FUN_0098ef00(local_mat);
  mat_tail = (uint32_t *)(local_mat + 0x30 - 0x18);
  /* local_24..local_18 at end of 0x30 block: colors + blend float */
  mat_tail[0] = DAT_00d1a6c0; /* layout mirrors raw local_24/20/1c/18 */
  mat_tail[1] = DAT_00d1a6c4;
  mat_tail[2] = DAT_00d1a6c8;
  *(float *)(mat_tail + 3) = g_flMultiKillCountBlend;
  FUN_0098f2b0(200);
  FUN_00749d10(local_mat);
  if (material != 0) {
    (*(void (__thiscall **)(void *))(*(uint32_t *)material + 0x5c))(material);
  }
  FUN_007647c0(host14c, material);

  FUN_004367f0(&host->vec_hdr, host->cursor + 1, 0);
  host->begin[host->cursor] = host14c;
  host->cursor = host->cursor + 1;

  FUN_00457a00(local_mat);
  return host14c;
}
