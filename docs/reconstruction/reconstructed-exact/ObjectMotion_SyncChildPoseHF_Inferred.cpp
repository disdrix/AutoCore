// =============================================================================
// ObjectMotion_SyncChildPoseHF_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b18f0
// Address:   0x004b18f0 – 0x004b1a56  (autoassault.exe, image base 0x400000)
// Size:      358 B / 0x166  (pad CC after RET 4)
// System:    client object motion / reaction slot child pose
// Generated: 2026-07-29 W27-F dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b18f0.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   When stack flag != 0, sync orientation-ish fields from the motion slot to the
//   child object at slot+8, then place the child's world XYZ using a heightfield
//   sample at the slot XZ and a scaled basis triple, finally lifting Y by ≈0.04.
//
// ABI:
//   __thiscall (ECX = motion slot); one stack formal (flag:int); void;
//   epilogue ret 4 (C2 04 00). Entry: push esi/edi; flag in EDI; this in ESI.
//
// CONSTANTS (read_memory Confirmed):
//   imm 0x3f400000 = 0.75f
//   DAT_00aaa8f4   ≈ 0.04f  (0AD7233D)
//   DAT_00afdef0   = 0xFF000000 (bytes 00 00 00 FF)
//   DAT_00b03530/34/38 image static 0.0 (runtime fill OPEN)
//
// RELATED (sealed peers):
//   FUN_004cd220 = CVOGMap_SampleHeightfieldY
//   FUN_004b4620 = ObjectMotion_SlotTick_Inferred (caller; after IntegrateStep)
// =============================================================================

#include <cstdint>

extern float DAT_00aaa8f4;     // ≈0.04f
extern uint32_t DAT_00afdef0;  // 0xFF000000
extern uint32_t DAT_00b03530;  // basis X (image 0)
extern uint32_t DAT_00b03534;  // basis Y (image 0)
extern uint32_t DAT_00b03538;  // basis Z (image 0)
extern uint8_t DAT_00aef980[]; // matrix/scratch fed to FUN_00973820

void FUN_00973820(void *pMat);
void FUN_00973690(uint32_t fl075, uint32_t a, uint32_t b);
uint8_t FUN_006a3db0(void);
long double FUN_004cd220(uint32_t x, uint32_t z); // CVOGMap_SampleHeightfieldY

// param_1 = motion slot (this); param_2 = flag from SlotTick / emitter path
void __thiscall ObjectMotion_SyncChildPoseHF_Inferred(int param_1, int param_2)
{
  int iVar1;
  uint8_t uVar2;
  long double fVar3;
  float fVar4;

  if (param_2 != 0) {
    FUN_00973820(&DAT_00aef980);
    FUN_00973690(0x3f400000u,
                 *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 8) + 0x34),
                 DAT_00afdef0);
    uVar2 = FUN_006a3db0();
    *reinterpret_cast<uint8_t *>(*reinterpret_cast<int *>(param_1 + 8) + 0x37) = uVar2;
    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 8) + 0x10) =
        *reinterpret_cast<uint32_t *>(param_1 + 0x10);
    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 8) + 0x18) =
        *reinterpret_cast<uint32_t *>(param_1 + 0x18);
    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(param_1 + 8) + 0x2c) =
        *reinterpret_cast<uint32_t *>(param_1 + 0x2c);
    fVar3 = FUN_004cd220(*reinterpret_cast<uint32_t *>(param_1 + 0x178),
                         *reinterpret_cast<uint32_t *>(param_1 + 0x180));
    fVar4 = *reinterpret_cast<float *>(param_1 + 0x17c);
    iVar1 = *reinterpret_cast<int *>(param_1 + 8);
    *reinterpret_cast<uint32_t *>(iVar1 + 0x178) = DAT_00b03530;
    *reinterpret_cast<uint32_t *>(iVar1 + 0x17c) = DAT_00b03534;
    *reinterpret_cast<uint32_t *>(iVar1 + 0x180) = DAT_00b03538;
    iVar1 = *reinterpret_cast<int *>(param_1 + 8);
    fVar4 = 0.0f - static_cast<float>(static_cast<long double>(fVar4) - fVar3) /
                       *reinterpret_cast<float *>(iVar1 + 0x17c);
    *reinterpret_cast<float *>(iVar1 + 0x178) =
        *reinterpret_cast<float *>(iVar1 + 0x178) * fVar4;
    *reinterpret_cast<float *>(iVar1 + 0x17c) =
        *reinterpret_cast<float *>(iVar1 + 0x17c) * fVar4;
    *reinterpret_cast<float *>(iVar1 + 0x180) =
        *reinterpret_cast<float *>(iVar1 + 0x180) * fVar4;
    iVar1 = *reinterpret_cast<int *>(param_1 + 8);
    *reinterpret_cast<float *>(iVar1 + 0x178) =
        *reinterpret_cast<float *>(param_1 + 0x178) +
        *reinterpret_cast<float *>(iVar1 + 0x178);
    *reinterpret_cast<float *>(iVar1 + 0x17c) =
        *reinterpret_cast<float *>(param_1 + 0x17c) +
        *reinterpret_cast<float *>(iVar1 + 0x17c);
    *reinterpret_cast<float *>(iVar1 + 0x180) =
        *reinterpret_cast<float *>(param_1 + 0x180) +
        *reinterpret_cast<float *>(iVar1 + 0x180);
    *reinterpret_cast<float *>(*reinterpret_cast<int *>(param_1 + 8) + 0x17c) =
        *reinterpret_cast<float *>(*reinterpret_cast<int *>(param_1 + 8) + 0x17c) +
        DAT_00aaa8f4;
  }
  return;
}
