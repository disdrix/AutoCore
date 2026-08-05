// =============================================================================
// Vehicle_BuildSteeringDescriptor
// -----------------------------------------------------------------------------
// Purpose:  Fill a steering descriptor blob used by the vehicle physics/setup
//           path: wheel count, max steer angles (clonebase × entity scalars),
//           and per-wheel steer-enable bits.
//
// Address:  0x005fc710  (autoassault.exe, image base 0x400000)
// Stable:   aa_005fc710
// System:   input-drive-control
//
// Convention: MSVC __cdecl (decompiler surface)
//   pVehicle   vehicle entity (param_1)
//   param_2    unused in body (present in signature)
//   pOut       descriptor output:
//                +0x00  u8   wheel count (from FUN_004f5560)
//                +0x04  f32  maxSteerA = clonebase+0x594 * entity+0x208
//                +0x08  f32  maxSteerB = clonebase+0x598 * entity+0x20c
//                +0x0c  ptr  byte array of per-wheel flags (grown via FUN_005b3300)
//                +0x10  int  array length (= wheel count)
//                +0x14  int  capacity (signed magnitude in low 31 bits)
//
// Per-wheel flag byte:
//   for wheel i in [0, wheelCount):
//     if i < tankSteerCount@chassis+0x4cc:
//       bit = (clonebase+0x5f0 >> 2) & 1
//     else:
//       bit = (clonebase+0x5f0 >> 3) & 1
//
// Clonebase path:
//   *( *( *( *(vehicle+4)+4 ) + 0xac + vehicle ) + 0x3c )
// Chassis secondary object at vehicle+600 (0x258) used only for +0x4cc count.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Growable byte buffer helper (vector-like reserve)
void FUN_005b3300(int* pVecHdr, int newCap, int elemSize);
// Wheel count query (returns char count of drive/steer wheels)
char FUN_004f5560(void /* vehicle context in regs */);

void Vehicle_BuildSteeringDescriptor(
    int            pVehicle,
    std::uint32_t  /* param_2 unused */,
    std::uint8_t*  pOut)
{
    int*  pFlagVec;   // piVar1 → pOut+0x0c header for FUN_005b3300
    char  cWheelCount;
    char  cTankSplit; // chassis clonebase+0x4cc
    char  cIter;
    char  cLimit;
    int   nNeed;
    int   nGrow;

    // -------------------------------------------------------------------------
    // Ensure flag array capacity >= wheel count
    // -------------------------------------------------------------------------
    cWheelCount = FUN_004f5560();
    nNeed       = (int)cWheelCount;
    pFlagVec    = reinterpret_cast<int*>(pOut + 0x0c);

    if ((int)(*(unsigned*)(pOut + 0x14) & 0x7fffffffu) < nNeed) {
        nGrow = (int)(*(unsigned*)(pOut + 0x14) & 0x7fffffffu) * 2;
        if (nGrow <= nNeed) {
            nGrow = nNeed;
        }
        FUN_005b3300(pFlagVec, nGrow, 1);
    }

    *(int*)(pOut + 0x10) = nNeed;

    // -------------------------------------------------------------------------
    // Header: wheel count + scaled max-steer floats from clonebase
    // -------------------------------------------------------------------------
    *pOut = (std::uint8_t)FUN_004f5560();

    {
        // clonebase = *(*(*(vehicle+4)+4) + 0xac + vehicle)->+0x3c
        int link1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pVehicle + 4) + 4);
        int pCloneObj = *reinterpret_cast<int*>(link1 + 0xac + pVehicle);
        int pCloneBase = *reinterpret_cast<int*>(pCloneObj + 0x3c);

        *reinterpret_cast<float*>(pOut + 4) =
            *reinterpret_cast<float*>(pCloneBase + 0x594) *
            *reinterpret_cast<float*>(pVehicle + 0x208);

        *reinterpret_cast<float*>(pOut + 8) =
            *reinterpret_cast<float*>(pCloneBase + 0x598) *
            *reinterpret_cast<float*>(pVehicle + 0x20c);
    }

    // -------------------------------------------------------------------------
    // Tank/split steer threshold from secondary object at vehicle+0x258 (600)
    // -------------------------------------------------------------------------
    {
        int pSec = *reinterpret_cast<int*>(pVehicle + 600);
        int link1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pSec + 4) + 4);
        int pCloneObj = *reinterpret_cast<int*>(link1 + 0xac + pSec);
        int pCloneBase = *reinterpret_cast<int*>(pCloneObj + 0x3c);
        cTankSplit = *reinterpret_cast<char*>(pCloneBase + 0x4cc);
    }

    // -------------------------------------------------------------------------
    // Per-wheel enable bits from clonebase+0x5f0 bit 2 (front) / bit 3 (rear)
    // -------------------------------------------------------------------------
    cIter  = 0;
    cLimit = FUN_004f5560();
    if ('\0' < cLimit) {
        do {
            int link1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pVehicle + 4) + 4);
            int pCloneObj = *reinterpret_cast<int*>(link1 + 0xac + pVehicle);
            int pCloneBase = *reinterpret_cast<int*>(pCloneObj + 0x3c);
            std::uint8_t flags = *reinterpret_cast<std::uint8_t*>(pCloneBase + 0x5f0);

            if (cIter < cTankSplit) {
                *(std::uint8_t*)((int)cIter + *pFlagVec) = (flags >> 2) & 1;
            } else {
                *(std::uint8_t*)((int)cIter + *pFlagVec) = (flags >> 3) & 1;
            }

            cIter  = cIter + 1;
            cLimit = FUN_004f5560();
        } while (cIter < cLimit);
    }
}
