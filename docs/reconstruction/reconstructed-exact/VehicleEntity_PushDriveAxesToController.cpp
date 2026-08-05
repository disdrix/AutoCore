// =============================================================================
// VehicleEntity_PushDriveAxesToController
// -----------------------------------------------------------------------------
// Purpose:  Copy entity thr/HB into the *input controller* block (layout-distinct
//           from Havok VehicleAction) and apply hard-stop / positive thr ceiling /
//           overspeed travel-polarity thr-zero gates.
//
// Address:  0x004fbc10  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fbc10
// System:   input-drive-control
// Dual:     residual strengthen 2026-07-29 (accept-with-gaps)
//
// Convention: MSVC __fastcall (entity in ECX)
//
// Gates:
//   entity+0x101 == 0  (not driving-suppressed)
//   entity+0x1a0 != 0  (controller host present)
//   ctrl = *(entity+0x1a0) + 8
//
// Controller writes:
//   ctrl+0x25 = 0
//   if entity+0x109:  ctrl+0x20 = 0, ctrl+0x24 = 1, return   (forced stop; no +0x61c)
//   else:
//     ctrl+0x20 = entity+0x614  (longitudinal; Accel=-1, Reverse=+1 from producers)
//     if ctrl+0x19: positive ceiling ctrl+0x20 = min(thr, DAT_00a0f734)  // 0.9 only
//     if derivedMax (local_3c) < entity+0x10c: may zero thr that continues travel
//     ctrl+0x24 = entity+0x61c  (handbrake byte)
//
// entity+0x618 (steer) is NOT written here — consumed later as steer ramp target
// in VehicleAction_applyAction. entity+0x61c is also read in calcWheelTorque.
// ctrl+0x24 is u8 HB — NOT VehicleAction+0x24 (f32 steer stage-1).
//
// Callers: DriveControlTick, PollBoundActions, SetDriveAxes, Vehicle_setDrivingInputs,
//          MoveToTarget3DPoint, TryActivatePhysics, ...
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Uninitialized fStack_40 is preserved as decompiler shows (x87/stack);
//            ports should treat initial bonus as 0 unless live-stack proves otherwise.
// =============================================================================

#include <cmath>
#include <cstdint>

// Entity offsets
static constexpr std::uintptr_t kOffLink0            = 0x04;
static constexpr std::uintptr_t kOffPhysicsBody      = 0x08;
static constexpr std::uintptr_t kOffDriveSuppressed  = 0x101; // char; must be 0
static constexpr std::uintptr_t kOffForcedStop       = 0x109; // char
static constexpr std::uintptr_t kOffSpeedCapRef      = 0x10c; // f32 requested/target speed vs derived max
static constexpr std::uintptr_t kOffControllerHost   = 0x1a0; // ptr; ctrl = *host + 8
static constexpr std::uintptr_t kOffLongitudinal     = 0x614; // f32
static constexpr std::uintptr_t kOffHandbrake        = 0x61c; // u8
// Related (not written here): kOffSteer = 0x618

// Input-controller offsets (relative to ctrl = *(host)+8) — not Havok VehicleAction
static constexpr std::uintptr_t kOffCtrlThrottle     = 0x20; // f32
static constexpr std::uintptr_t kOffCtrlHandbrake    = 0x24; // u8
static constexpr std::uintptr_t kOffCtrlClearFlag    = 0x25; // u8
static constexpr std::uintptr_t kOffCtrlReverseMode  = 0x19; // char — enable positive thr ceiling 0.9

// Globals
extern float DAT_00a0f734;       // thr positive ceiling (0.9) when ctrl+0x19
extern float DAT_00b041b0[];     // fallback velocity vec when body null
extern float g_flOne;
extern float g_flOverheatCoolFrac;
extern float DAT_009cd0d8;       // bonus add 0.5 (boost-style flag 0x4000 / obj+0xb5&0x40)
extern float DAT_00aaa668;       // AbsoluteTopSpeed sentinel -1.0
extern char  DAT_00af1854;       // feature gate for +0xd48 bonus

// Helpers (unresolved names kept as FUN_*)
float* FUN_00404a20(void);                              // forward basis / facing
void   FUN_004e8a40(float* in4, float* out3);           // derive facing axes
/*float10*/ FUN_004c4e20(void);                         // max-speed from driver/vehicle

struct VehicleEntity;

void __fastcall VehicleEntity_PushDriveAxesToController(VehicleEntity* thisEntity)
{
    auto* const entity = reinterpret_cast<std::uint8_t*>(thisEntity);

    float  flSpeedMag;           // local_34
    float  flMaxSpeed;           // local_3c
    float  flThrottle;           // fVar9 / ctrl throttle working copy
    float  flCapAdjust;          // fStack_40 — decompiler leaves often unset
    float  flCloneMax;           // fVar1 from clonebase +0x634
    float* pVel;
    int*   pWobj;
    int    iCtrl;
    int    iTmp;
    unsigned uFlags;
    bool   bThrottleOpposes;
    float  faceX, faceY, faceZ, faceW; // local_34..fStack_28 from FUN_00404a20
    float  axX, axY, axZ;              // fStack_24..fStack_1c from FUN_004e8a40

    // -------------------------------------------------------------------------
    // Entry gate: not suppressed + controller host present
    // -------------------------------------------------------------------------
    if (*(char*)(entity + kOffDriveSuppressed) == '\0' &&
        *(int*)(entity + kOffControllerHost) != 0) {

        iCtrl = *(int*)(*(int*)(entity + kOffControllerHost) + 8);
        *(std::uint8_t*)(iCtrl + kOffCtrlClearFlag) = 0;

        // Forced stop: zero throttle, handbrake=1, leave
        if (*(char*)(entity + kOffForcedStop) != '\0') {
            *reinterpret_cast<std::uint32_t*>(iCtrl + kOffCtrlThrottle) = 0;
            *(std::uint8_t*)(iCtrl + kOffCtrlHandbrake) = 1;
            return;
        }

        // ---------------------------------------------------------------------
        // Copy longitudinal; optional positive thr ceiling DAT_00a0f734 (0.9)
        // ---------------------------------------------------------------------
        flThrottle = *reinterpret_cast<float*>(entity + kOffLongitudinal);
        *reinterpret_cast<float*>(iCtrl + kOffCtrlThrottle) = flThrottle;

        if (*(char*)(*(int*)(*(int*)(entity + kOffControllerHost) + 8) + kOffCtrlReverseMode)
            != '\0') {
            if (DAT_00a0f734 <= flThrottle) {
                flThrottle = DAT_00a0f734;
            }
            *reinterpret_cast<float*>(iCtrl + kOffCtrlThrottle) = flThrottle;
        }

        // ---------------------------------------------------------------------
        // Velocity vector: physics body +0x40 or fallback DAT_00b041b0
        // ---------------------------------------------------------------------
        if (*(int*)(entity + kOffPhysicsBody) == 0) {
            pVel = DAT_00b041b0;
        } else {
            pVel = reinterpret_cast<float*>(
                *(int*)(*(int*)(entity + kOffPhysicsBody) + 0x3c) + 0x40);
        }

        flThrottle = *reinterpret_cast<float*>(entity + kOffSpeedCapRef); // reuse fVar9
        pWobj = *reinterpret_cast<int**>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(entity + kOffLink0) + 4)
            + 0xb0 + reinterpret_cast<std::uintptr_t>(entity));

        flSpeedMag = std::sqrt(pVel[2] * pVel[2] + pVel[1] * pVel[1] + pVel[0] * pVel[0]);
        (void)flSpeedMag; // SSA-dead |v|; local_34 slot reused as basis storage in overspeed gate

        // Max speed from wobj vtable +0x1d8 → FUN_004c4e20, else 0
        if (pWobj == nullptr) {
            flMaxSpeed = 0.0f;
        } else {
            iTmp = (*reinterpret_cast<int(__thiscall**)(int*)>(*pWobj + 0x1d8))(pWobj);
            if (iTmp == 0) {
                flMaxSpeed = 0.0f;
            } else {
                (*reinterpret_cast<int(__thiscall**)(int*)>(
                    **reinterpret_cast<int**>(
                        *reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(entity + kOffLink0) + 4)
                        + 0xb0 + reinterpret_cast<std::uintptr_t>(entity))
                    + 0x1d8))(
                    *reinterpret_cast<int**>(
                        *reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(entity + kOffLink0) + 4)
                        + 0xb0 + reinterpret_cast<std::uintptr_t>(entity)));
                flMaxSpeed = (float)FUN_004c4e20();
            }
        }

        // Optional character +0xd48 bonus onto flCapAdjust when flag set
        {
            int* pIface = reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(entity + kOffLink0) + 4)
                + 4 + reinterpret_cast<std::uintptr_t>(entity));
            iTmp = (*reinterpret_cast<int(__thiscall**)(int*, int)>(*pIface + 0x210))(pIface, 0);
            if (iTmp != 0 && DAT_00af1854 != '\0') {
                iTmp = (*reinterpret_cast<int(__thiscall**)(int*, int)>(*pIface + 0x210))(pIface, 0);
                flCapAdjust = *reinterpret_cast<float*>(iTmp + 0xd48) + flCapAdjust;
            }
        }

        // Flag bits on entity+0xb8 (via link) and wobj+0xb5 adjust flCapAdjust
        {
            int link1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(entity + kOffLink0) + 4);
            uFlags = *reinterpret_cast<unsigned*>(link1 + 0xb8 + reinterpret_cast<std::uintptr_t>(entity));
            int base = link1 + static_cast<int>(reinterpret_cast<std::uintptr_t>(entity));

            if ((uFlags & 0x1000) != 0 ||
                (*(int*)(base + 0xb0) != 0 &&
                 (*(std::uint8_t*)(*(int*)(base + 0xb0) + 0xb5) & 0x10) != 0)) {
                flCapAdjust = flCapAdjust - g_flOverheatCoolFrac;
            }
            if ((uFlags & 0x4000) != 0 ||
                (*(int*)(base + 0xb0) != 0 &&
                 (*(std::uint8_t*)(*(int*)(base + 0xb0) + 0xb5) & 0x40) != 0)) {
                flCapAdjust = flCapAdjust + DAT_009cd0d8;
            }

            flCloneMax = *reinterpret_cast<float*>(
                *(int*)(*(int*)(base + 0xac) + 0x3c) + 0x634);
            flMaxSpeed = (flCapAdjust + g_flOne) * flMaxSpeed;
            if (flCloneMax != DAT_00aaa668 && flCloneMax < flMaxSpeed) {
                flMaxSpeed = flCloneMax;
            }

            // -----------------------------------------------------------------
            // Overspeed: if derived max (flMaxSpeed) < entity+0x10c (flThrottle
            // reuses fVar9 as requested-speed field), zero thr that continues
            // travel polarity (Accel=-1 / Reverse=+1); leave opposing thr.
            // -----------------------------------------------------------------
            if (flMaxSpeed < flThrottle) {
                float* pFace = FUN_00404a20();
                faceX = pFace[0];
                faceY = pFace[1];
                faceZ = pFace[2];
                faceW = pFace[3];
                (void)faceW;
                float in4[4] = { faceX, faceY, faceZ, faceW };
                float out3[3];
                FUN_004e8a40(in4, out3);
                axX = out3[0];
                axY = out3[1];
                axZ = out3[2];
                // Decompiler names fStack_24/20/1c — same as out3 after call.

                if (*(int*)(entity + kOffPhysicsBody) == 0) {
                    pVel = DAT_00b041b0;
                } else {
                    pVel = reinterpret_cast<float*>(
                        *(int*)(*(int*)(entity + kOffPhysicsBody) + 0x3c) + 0x40);
                }

                // Dot(vel, facingAxis): bVar7 true when thr sign continues travel
                if (pVel[2] * axZ + pVel[1] * axY + pVel[0] * axX <= 0.0f) {
                    flThrottle = *reinterpret_cast<float*>(iCtrl + kOffCtrlThrottle);
                    bThrottleOpposes = flThrottle < 0.0f; // Accel polarity "toward travel"
                } else {
                    flThrottle = *reinterpret_cast<float*>(iCtrl + kOffCtrlThrottle);
                    bThrottleOpposes = 0.0f < *reinterpret_cast<float*>(iCtrl + kOffCtrlThrottle);
                    // Reverse polarity "toward travel" when going forward
                }
                if (!bThrottleOpposes && flThrottle != 0.0f) {
                    *reinterpret_cast<std::uint32_t*>(iCtrl + kOffCtrlThrottle) = 0;
                }
            }
        }

        // Handbrake byte from entity → controller
        *(std::uint8_t*)(iCtrl + kOffCtrlHandbrake) =
            *(std::uint8_t*)(entity + kOffHandbrake);
    }
}
