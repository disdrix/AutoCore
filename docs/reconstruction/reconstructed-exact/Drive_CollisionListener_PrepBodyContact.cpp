// =============================================================================
// Drive_CollisionListener_PrepBodyContact
// -----------------------------------------------------------------------------
// Stable ID: aa_005d9ea0
// Address:   0x005d9ea0  (autoassault.exe, image base 0x400000)
// System:    drive / collision / client FX+SFX
// Generated: 2026-07-29 W25-K dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Per-body contact prep invoked twice from CollisionListener::contact
//   (body A then body B). Walks body parent chain, resolves host pair-list
//   materials (types 1/3/4), optionally plays collision sound and type-3 GO
//   collision effect when |impact| > 1.0 and enable gate is set.
//
// ABI (bytes):
//   __thiscall RET 0x14
//   ECX = CollisionListener* this  (last-body cache @ +0xc)
//   stack: ctx, body*, impact*, enable, outPlayed*
//
// STRING SIBLINGS (not on this VA):
//   "CollisionListener::contact" / PlayCollisionSound / PlayCollisionEffect
//
// CALLER: Drive_CollisionListener_Contact (FUN_005da0a0) ×2
// CALLEES: FUN_005d90a0, FUN_0040afb0×2, FUN_005d9af0 (allowCreate=0)
// SIZE: 500 bytes (0x005d9ea0–0x005da093)
// GATE: _DAT_00af4364 = 1.0f
// =============================================================================

#include <cstdint>
#include <cmath>

extern float _DAT_00af4364; // 1.0f @ 0x00af4364

extern void FUN_005d90a0(void* ctx, float* absImpact, uint32_t matA, uint32_t matB);
extern uint32_t* FUN_0040afb0(void* scratch, int key);
extern void FUN_005d9af0(void* ctx, uint32_t a1, float a2, void* gameObject, int8_t allowCreate);
// Note: PlayCollisionEffect is __thiscall on listener; decompiler may show
// ctx as first stack after implicit this — call site in this unit passes
// allowCreate=0.

void __thiscall Drive_CollisionListener_PrepBodyContact(
    int self,
    void* ctx,
    int* body,
    float* impact,
    /* decomp: float */ uint32_t enable_slot,
    uint8_t* outPlayed)
{
  int local_go = 0;
  int* piVar5 = (int*)body[3];
  int* piVar9 = body;
  int* piVar3;
  while ((piVar3 = piVar5) != nullptr) {
    piVar9 = piVar3;
    piVar5 = (int*)piVar3[3];
  }
  int host = piVar9[8];
  int i = 0;
  if (*(int*)(host + 0x34) > 0) {
    int* pair = *(int**)(host + 0x30);
    do {
      if (*pair == 1) {
        int* obj = (int*)(*(int**)(host + 0x30))[i * 2 + 1];
        if (obj != nullptr && (((uint32_t)obj[0x5f] >> 5) & 1) != 0) {
          local_go = (*(int(**)())(*obj + 0x1c8))();
        }
        break;
      }
      i++;
      pair += 2;
    } while (i < *(int*)(host + 0x34));
  }

  int count = *(int*)(host + 0x34);
  int mat3 = 0;
  if (count > 0) {
    int* pair = *(int**)(host + 0x30);
    int j = 0;
    do {
      if (*pair == 3) {
        mat3 = (*(int**)(host + 0x30))[j * 2 + 1];
        goto found3;
      }
      j++;
      pair += 2;
    } while (j < count);
  }
  mat3 = 0;
found3:
  int mat4 = 0;
  if (count > 0) {
    int* pair = *(int**)(host + 0x30);
    int k = 0;
    do {
      if (*pair == 4) {
        mat4 = (*(int**)(host + 0x30))[k * 2 + 1];
        goto found4;
      }
      k++;
      pair += 2;
    } while (k < count);
  }
  mat4 = 0;
found4:

  uint8_t enable = (uint8_t)enable_slot;
  bool soundDone = false;
  float scratch = 0.0f;

  if (*(int*)(self + 0xc) != *body) {
    if (enable != 0) {
      scratch = fabsf(*impact);
      if (_DAT_00af4364 < scratch) {
        FUN_005d90a0(ctx, &scratch, mat3, mat4);
      }
      soundDone = true;
    }
    *(int*)(self + 0xc) = *body;
  }

  if (local_go != 0 &&
      *(int*)(*(int*)(*(int*)(*(int*)(local_go + 4) + 4) + 0xac + local_go) + 0x38) == 3) {
    uint32_t* p3 = FUN_0040afb0(&scratch, 3);
    uint32_t u3 = *p3;
    uint32_t* p4 = FUN_0040afb0(&scratch, 4);
    if (enable != 0) {
      scratch = fabsf(*impact);
      if (_DAT_00af4364 < scratch) {
        if (!soundDone) {
          FUN_005d90a0(ctx, &scratch, u3, *p4);
        }
        // allowCreate = 0 — no lazy FxMaster from prep
        FUN_005d9af0(ctx, u3, *impact,
                     (void*)(*(int*)(*(int*)(local_go + 4) + 4) + 4 + local_go),
                     0);
        *outPlayed = 1;
      }
      *(int*)(self + 0xc) = *body;
    }
  }
}

void __thiscall FUN_005d9ea0(
    int param_1, void* param_2, int* param_3, float* param_4,
    uint32_t param_5, uint8_t* param_6)
{
  Drive_CollisionListener_PrepBodyContact(
      param_1, param_2, param_3, param_4, param_5, param_6);
}
