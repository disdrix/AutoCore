// =============================================================================
// PalVisibleBoundingShape_EffectMaterialInit_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Post-ctor init for HostPtrTable12 slot-0 mesh host: load
//           PalVisibleBoundingShape.fx, bind solid/wire diffuse+emissive
//           material params, refcount-swap resource at self+0x20, return OR
//           of stage statuses.
//
// Address:  0x0099e6c0  (autoassault.exe, image base 0x400000)
// Body:     0x0099e6c0–0x0099e894 (469 B / 0x1D5)
// Stable:   aa_0099e6c0
// System:   mesh host FX / material init
// Ghidra:   FUN_0099e6c0
//
// ABI:      ECX = self (0xC4 mesh host); return status OR in EAX.
// Callers:  sole — HostPtrTable12_Bootstrap_EDI (FUN_0073c810) @ 0x0073c869.
//
// Exactness: CF mirrors raw + read_memory; product FX/material strings sealed.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W36-H seal).
// =============================================================================

#include <stdint.h>

extern void *ExceptionList;
extern void *LAB_009b2d4b;
extern float g_flOne;                 /* 0x00a0f2a0 */
extern uint32_t DAT_00d1a6c0;
extern uint32_t DAT_00d1a6c4;
extern uint32_t DAT_00d1a6c8;

extern void FUN_00989e00(void *out, const char *path);
extern uint32_t FUN_009701d0(void *fx_name_obj);
extern void FUN_0098ef00(void *tmp);
extern void FUN_0098f2b0(int n /* 200 */);
extern uint32_t FUN_00749d10(void *tmp);
extern int *FUN_00752370(void *out, const char *param_name);
extern uint32_t FUN_0096fff0(int *res_slot, int param_index);
extern int *FUN_0073d940(int handle);
extern void FUN_00457a00(void *tmp);

uint32_t __fastcall PalVisibleBoundingShape_EffectMaterialInit_Inferred(
    void *self /* ECX */)
{
  void *frame[4];
  int local_name;
  int idx_buf[4];
  uint8_t tmp[48 + 16]; /* local_54..local_18 material/desc stack blob */
  uint32_t *color = (uint32_t *)(tmp + 48); /* local_24..local_18 */
  int *res = (int *)((uint8_t *)self + 0x20);
  uint32_t s_fx, s_mat, s0, s1, s2, s3;
  int *idx;
  int *rc;

  frame[3] = (void *)(uintptr_t)0xFFFFFFFFu;
  frame[2] = &LAB_009b2d4b;
  frame[1] = ExceptionList;
  ExceptionList = &frame[1];

  FUN_00989e00(&local_name, "PalVisibleBoundingShape.fx");
  s_fx = FUN_009701d0(&local_name);

  FUN_0098ef00(tmp);
  frame[3] = 0;
  color[0] = DAT_00d1a6c0;
  color[1] = DAT_00d1a6c4;
  color[2] = DAT_00d1a6c8;
  *(float *)&color[3] = g_flOne;
  FUN_0098f2b0(200);
  s_mat = FUN_00749d10(tmp);

#define BIND_PARAM(out_status, name, slot)                                    \
  do {                                                                        \
    if (*res == 0) {                                                          \
      local_name = -1;                                                        \
      idx = &local_name;                                                      \
    } else {                                                                  \
      idx = FUN_00752370((void *)(slot), (name));                             \
    }                                                                         \
    if (*idx < 0)                                                             \
      (out_status) = 0xFFFFFFFFu;                                             \
    else                                                                      \
      (out_status) = FUN_0096fff0(res, *idx);                                 \
  } while (0)

  BIND_PARAM(s0, "SolidMatDiffuse", &idx_buf[0]);
  BIND_PARAM(s1, "SolidMatEmissive", &idx_buf[1]);
  BIND_PARAM(s2, "WireMatDiffuse", &idx_buf[2]);
  BIND_PARAM(s3, "WireMatEmissive", &idx_buf[3]);

#undef BIND_PARAM

  rc = FUN_0073d940(*res);
  if (rc != 0) {
    rc[1] = rc[1] + 1;
    if (rc[1] == 1) {
      ((void (*)(void))(*(void **)*rc)[1])(); /* vfunc +4 first-use */
    }
    {
      int *old = (int *)*res;
      if (old != 0) {
        old[1] = old[1] - 1;
        if (old[1] == 0) {
          ((void (*)(void))(*(void **)*old)[2])(); /* vfunc +8 release */
        }
      }
    }
    *res = (int)(uintptr_t)rc;
  }

  frame[3] = (void *)(uintptr_t)0xFFFFFFFFu;
  FUN_00457a00(tmp);
  ExceptionList = frame[0]; /* decomp restores via stack slot; SEH unwind */
  return s_fx | s_mat | s0 | s1 | s2 | s3;
}
