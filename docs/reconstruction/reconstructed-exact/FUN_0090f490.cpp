// =============================================================================
// FUN_0090f490
// -----------------------------------------------------------------------------
// Stable ID: aa_0090f490
// Address:   0x0090f490 – 0x0090f8d3  (1092 B / 0x444; autoassault.exe base 0x400000)
// System:    client / object pose track
// Dual:      W27-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Track related-object pose relative to a host. When far from a global
//   sample position, gate on Math_Vec3NearlyEqual_AbsRel(live @ +0x90 vs
//   cached @ host+0x4fc, eps≈1e-6). On miss, refresh cache and rebuild
//   orthonormal basis / matrix / quat / pos. Optional param_1 callback.
//
// ABI (machine):
//   EBX = host object (custom register this)
//   stack: int *param_1 (optional); callee cleans with RET 4
//   void return
//
// SEALED CALLEE:
//   Math_Vec3NearlyEqual_AbsRel (FUN_0040d3f0, W26-A)
// =============================================================================

#include <cstdint>
#include <cmath>

// Sealed W26-A — ESI/EDI register ABI in machine form.
extern "C" std::uint32_t FUN_0040d3f0(float relTol, float absTol);
extern "C" float *FUN_0076f5f0(float *out, float *in); // normalize3
extern "C" void FUN_00972580(float *a, float *b);
extern "C" void __fastcall FUN_0076e970(float *mat); // matrix→quat via EAX
extern "C" void __thiscall FUN_0040d1a0(void *self, float *quat);
extern "C" void __thiscall FUN_0040cf90(void *self, float *pos);

// Globals (Ghidra names)
extern float g_flZero;
extern float g_flOne;
extern float g_flMultiKillCountBlend; // 0.1f @ 0x00a0f730
extern float g_nInferredThreatDefault; // plate; 20.0f class constant elsewhere
extern float DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;
extern float DAT_00aaa668; // -1.0f
extern std::uint32_t DAT_00afdf70[];
extern int *DAT_00d09a5c;

// Ghidra: void FUN_0090f490(int *param_1) with unaff_EBX host
void FUN_0090f490_portable(std::uint8_t *host, int *param_1)
{
  char near_flag;
  int live;
  int other;
  float fVar6, fVar7, fVar8;
  float fStack_a4, fStack_a0, fStack_9c;
  float fStack_98, fStack_94, fStack_90;
  float fStack_8c, fStack_88, fStack_84;
  float fStack_80, fStack_7c, fStack_78;
  float fStack_74, fStack_70, fStack_6c;
  std::uint32_t uStack_68, uStack_64, uStack_60;
  float fStack_5c;
  std::uint32_t auStack_58[21];
  std::uint32_t *puVar4;
  std::uint32_t *puVar5;
  int iVar2;

  if (*reinterpret_cast<float *>(host + 0x544) == g_flZero) {
    *reinterpret_cast<float *>(host + 0x544) = g_flMultiKillCountBlend;
  }
  (**(void (**)(std::uint32_t, int))(*DAT_00d09a5c + 8))(
      *reinterpret_cast<std::uint32_t *>(host + 0x544), 1);

  fStack_80 = DAT_00d1a6c0;
  fStack_7c = DAT_00d1a6c4;
  fStack_78 = DAT_00d1a6c8;

  if (*reinterpret_cast<int **>(host + 0xa20) == nullptr) {
    return;
  }

  live = (**(int (**)())(**reinterpret_cast<int **>(host + 0xa20) + 0xc))();
  fVar6 = fStack_80 - *reinterpret_cast<float *>(live + 0x90);
  fVar8 = fStack_7c - *reinterpret_cast<float *>(live + 0x94);
  fVar7 = fStack_78 - *reinterpret_cast<float *>(live + 0x98);

  if (g_flMultiKillCountBlend <=
      std::sqrt(fVar6 * fVar6 + fVar8 * fVar8 + fVar7 * fVar7)) {
    (**(int (**)())(**reinterpret_cast<int **>(host + 0xa20) + 0xc))();
    // Machine: LEA ESI,[EAX+0x90]; LEA EDI,[EBX+0x4fc]; push 0x358637BD ×2
    near_flag = static_cast<char>(FUN_0040d3f0(0x358637bd, 0x358637bd));

    if (near_flag == 0) {
      live = (**(int (**)())(**reinterpret_cast<int **>(host + 0xa20) + 0xc))();
      *reinterpret_cast<std::uint32_t *>(host + 0x4fc) =
          *reinterpret_cast<std::uint32_t *>(live + 0x90);
      *reinterpret_cast<std::uint32_t *>(host + 0x500) =
          *reinterpret_cast<std::uint32_t *>(live + 0x94);
      *reinterpret_cast<std::uint32_t *>(host + 0x504) =
          *reinterpret_cast<std::uint32_t *>(live + 0x98);

      live = (**(int (**)())(**reinterpret_cast<int **>(host + 0xa20) + 0xc))();
      fStack_80 = *reinterpret_cast<float *>(live + 0x90);
      fStack_7c = *reinterpret_cast<float *>(live + 0x94);
      fStack_78 = *reinterpret_cast<float *>(live + 0x98);

      live = (**(int (**)())(**reinterpret_cast<int **>(host + 0xa20) + 0xc))();
      other = (**(int (**)())(**reinterpret_cast<int **>(host + 0xa24) + 0xc))();
      fStack_a4 = *reinterpret_cast<float *>(other + 0x90) -
                  *reinterpret_cast<float *>(live + 0x90);
      fStack_a0 = *reinterpret_cast<float *>(other + 0x94) -
                  *reinterpret_cast<float *>(live + 0x94);
      fStack_9c = *reinterpret_cast<float *>(other + 0x98) -
                  *reinterpret_cast<float *>(live + 0x98);
      fStack_74 = fStack_a4;
      fStack_70 = fStack_a0;
      fStack_6c = fStack_9c;
      FUN_0076f5f0(&fStack_74, &fStack_74);

      // Cross with DAT_00aaa668 (-1.0f); zeros preserved from decompile
      fStack_a4 = fStack_70 * 0.0f - fStack_6c * DAT_00aaa668;
      fStack_a0 = fStack_6c * 0.0f - fStack_74 * 0.0f;
      fStack_9c = fStack_74 * DAT_00aaa668 - fStack_70 * 0.0f;
      fVar6 = fStack_6c;
      fVar7 = fStack_70;
      fVar8 = fStack_74;
      fStack_98 = fStack_a4;
      fStack_94 = fStack_a0;
      fStack_90 = fStack_9c;
      fStack_8c = fStack_a4;
      fStack_88 = fStack_a0;
      fStack_84 = fStack_9c;
      FUN_0076f5f0(&fStack_a4, &fStack_a4);

      fStack_98 = fStack_9c * fVar7 - fStack_a0 * fVar6;
      fStack_94 = fVar6 * fStack_a4 - fStack_9c * fVar8;
      fStack_90 = fStack_a0 * fVar8 - fVar7 * fStack_a4;
      fStack_8c = fStack_98;
      fStack_88 = fStack_94;
      fStack_84 = fStack_90;
      FUN_0076f5f0(&fStack_98, &fStack_98);

      puVar4 = &DAT_00afdf70[0];
      puVar5 = auStack_58;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_00972580(&fStack_74, &fStack_98);
      FUN_0076e970(reinterpret_cast<float *>(auStack_58));
      FUN_0040d1a0(/* ECX set by machine path */ nullptr,
                   reinterpret_cast<float *>(&uStack_68));
      FUN_0040cf90(/* ECX set by machine path */ nullptr, &fStack_80);
    }

    if (param_1 != nullptr) {
      (**(void (**)(int))(*param_1 + 0x10))(3);
    }
  } else {
    iVar2 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(host + 0x2a4) + 8);
    if (static_cast<float>(g_nInferredThreatDefault) <
        std::sqrt(*reinterpret_cast<float *>(iVar2 + 0x98) *
                      *reinterpret_cast<float *>(iVar2 + 0x98) +
                  *reinterpret_cast<float *>(iVar2 + 0x94) *
                      *reinterpret_cast<float *>(iVar2 + 0x94) +
                  *reinterpret_cast<float *>(iVar2 + 0x90) *
                      *reinterpret_cast<float *>(iVar2 + 0x90))) {
      uStack_68 = 0;
      uStack_64 = 0;
      uStack_60 = 0;
      fStack_7c = DAT_00d1a6c4;
      fStack_80 = DAT_00d1a6c0;
      fStack_5c = g_flOne;
      fStack_78 = DAT_00d1a6c8;
      FUN_0040d1a0(nullptr, reinterpret_cast<float *>(&uStack_68));
      FUN_0040cf90(nullptr, &fStack_80);
      return;
    }
  }
}

// Scaffold entry matching Ghidra signature — EBX must be live.
extern "C" void FUN_0090f490(int *param_1)
{
  (void)param_1;
  // Intentionally incomplete for portable C: EBX host is register-passed.
  // Prefer FUN_0090f490_portable for ports.
}
