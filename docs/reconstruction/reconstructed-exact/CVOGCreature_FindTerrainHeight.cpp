// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, goto×1, return×1.
//  - Notable callees: FUN_0076cef0×2, FUN_0076cf00×2, CVOGCreature_FindTerrainHeight, FUN_004cd220, FUN_00580ed0, Y.
//  - Strings: "CVOGCreature::FindTerrainHeight::findZposition"; "CVOGCreature::FindTerrainHeight::castRay".
//  - Return sites: 1.

// =============================================================================
// CVOGCreature_FindTerrainHeight
// -----------------------------------------------------------------------------
// Purpose:  AI / movement ground snap. Sample terrain height under world XZ
//           (plus optional vertical bias), then add creature foot offset
//           at this+0x120 (dword index this[0x48]).
//
// Address:  0x004c6100  (autoassault.exe, image base 0x400000)
// Stable:   aa_004c6100
// System:   world / creature movement
//
// Convention: MSVC __thiscall  (this = CVOGCreature*)
// Returns:    float10  final Y = terrainSample + footOffset(+0x120)
//
// Algorithm:
//   1. bLocal = (object at sectorMap+0xe8a0, vfunc+0x1d8) == this
//   2. flTerrainY = FUN_004cd220(worldX, worldZ) + flBias
//   3. if (worldY - flTerrainY) - foot > DAT_00a0f298 (~0.5):
//        if physics body (this+0x254) is null:
//          flTerrainY = CVOGMap_CastTerrainHeight(x, z, y+bias, bLocal) + bias
//        else:
//          vfunc+0x54 prep; vertical FUN_00580ed0 castRay from y+foot down
//          by DAT_00aaa7ac; on hit, lerp Y by hit fraction + bias + DAT_00aaa8f0
//   4. return flTerrainY + foot
//
// Plate: Combat NPCs re-snap; static IsNPC may never call this - server must
// send elevated Y (AutoCore applies physics foot offset for IsNPC).
//
// Exactness: Control flow mirrors raw Ghidra decompile. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined: 2026-07-23 (priority_011)
// =============================================================================

#include <cstdint>

extern "C" void* ExceptionList;
extern "C" void FUN_0076cf00(const char* scopeName);
extern "C" void FUN_0076cef0();
extern "C" long double FUN_004cd220(std::uint32_t worldXBits, std::uint32_t worldZBits);
extern "C" long double CVOGMap_CastTerrainHeight(std::uint32_t worldXBits,
                                                 std::uint32_t worldZBits,
                                                 float startY,
                                                 char bLocalFilter);
// Physics castRay - fills hit flag / fraction in sibling stack slots (see aa_00580ed0).
extern "C" void FUN_00580ed0(void* pRayDesc, void* pHitOut);

extern float DAT_00a0f298; // ~0.5
extern float g_flOne;
extern float DAT_00aaa7ac; // ray down length
extern float DAT_00aaa8f0; // hit Y bias

long double __thiscall CVOGCreature_FindTerrainHeight(int* thisCreature,
                                                      std::uint32_t* pWorldPos,
                                                      float flBias)
{
    int nSectorMap;
    int* pFocused;
    char bLocal;
    long double flTmp;
    float flTerrainY;

    // castRay path locals (names from decompiler)
    std::uint32_t uStack_80; // ray start X
    float fStack_7c;         // ray start Y
    std::uint32_t uStack_78; // ray start Z
    std::uint32_t uStack_74;
    std::uint32_t uStack_70; // ray end X
    float fStack_6c;         // ray end Y
    std::uint32_t uStack_68; // ray end Z
    std::uint32_t uStack_64;
    std::uint8_t uStack_60;
    int iStack_5c;           // filter flags
    std::uint8_t auStack_50[20];
    float fStack_3c;         // hit fraction (init g_flOne; written by castRay)
    int iStack_30;           // hit flag (written by castRay)
    void* pvStack_1c;
    std::uint8_t* puStack_18;
    std::uint32_t uStack_14;

    uStack_14 = 0xffffffffu;
    puStack_18 = nullptr; // SEH handler cookie in original
    pvStack_1c = ExceptionList;

    nSectorMap = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(thisCreature[1] + 4) + 0xa8 +
        reinterpret_cast<int>(thisCreature));
    ExceptionList = &pvStack_1c;

    if (nSectorMap != 0 && *reinterpret_cast<int*>(nSectorMap + 0xe8a0) != 0) {
        int* pObj = *reinterpret_cast<int**>(nSectorMap + 0xe8a0);
        pFocused = reinterpret_cast<int*>((**(int*(**)())(*pObj + 0x1d8))());
        if (pFocused == thisCreature) {
            bLocal = 1;
            goto LAB_004c6157;
        }
    }
    bLocal = 0;

LAB_004c6157:
    FUN_0076cf00("CVOGCreature::FindTerrainHeight::findZposition");
    uStack_14 = 0;
    flTmp = FUN_004cd220(pWorldPos[0], pWorldPos[2]);
    uStack_14 = 0xffffffffu;
    flTerrainY = static_cast<float>(flTmp + static_cast<long double>(flBias));
    FUN_0076cef0();

    // Refine when creature is well above heightfield sample + foot offset.
    if (DAT_00a0f298 <
        (*reinterpret_cast<float*>(&pWorldPos[1]) - flTerrainY) -
            static_cast<float>(thisCreature[0x48])) {
        FUN_0076cf00("CVOGCreature::FindTerrainHeight::castRay");
        uStack_14 = 1;

        if (thisCreature[0x95] == 0) {
            // No physics body at +0x254
            flTmp = CVOGMap_CastTerrainHeight(
                pWorldPos[0],
                pWorldPos[2],
                *reinterpret_cast<float*>(&pWorldPos[1]) + flBias,
                bLocal);
            flTerrainY = static_cast<float>(flTmp + static_cast<long double>(flBias));
        } else {
            (**(void(**)())(*thisCreature + 0x54))();

            uStack_80 = pWorldPos[0];
            uStack_70 = pWorldPos[0];
            fStack_7c = *reinterpret_cast<float*>(&pWorldPos[1]) +
                        static_cast<float>(thisCreature[0x48]);
            fStack_3c = g_flOne;
            uStack_78 = pWorldPos[2];
            uStack_68 = pWorldPos[2];
            fStack_6c = fStack_7c - DAT_00aaa7ac;
            iStack_5c = (-static_cast<unsigned>(bLocal != 0) & 0xd) + 5;
            iStack_30 = 0;
            uStack_74 = 0;
            uStack_60 = 0;
            uStack_64 = 0;

            // Ray desc starts at &uStack_80 (packed with filter/hit siblings).
            FUN_00580ed0(&uStack_80, auStack_50);

            if (iStack_30 != 0) {
                // Lerp start/end Y by hit fraction; add bias + DAT_00aaa8f0.
                flTerrainY = fStack_7c * (g_flOne - fStack_3c) + fStack_6c * fStack_3c +
                             flBias + DAT_00aaa8f0;
            }
        }

        uStack_14 = 0xffffffffu;
        FUN_0076cef0();
    }

    ExceptionList = pvStack_1c;
    (void)puStack_18;
    return static_cast<long double>(flTerrainY) +
           static_cast<long double>(static_cast<float>(thisCreature[0x48]));
}
