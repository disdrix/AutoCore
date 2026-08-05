// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CVOGObject_SetInteractSpecialFX×2, FUN_00517250.
//  - Return sites: 1.

// =============================================================================
// CVOGObject_SetInteractSpecialFX
// -----------------------------------------------------------------------------
// Purpose:  Replace the interact special-FX attachment on a world object
//           (mission/NPC icon FX path).
//
// Address:  0x005179a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005179a0
// System:   missions-progression / interact chrome
//
// Convention: MSVC __thiscall
//   this        CVOGObject*
//   pSpecialFx  new FX object or null
//
// Algorithm:
//   if this+0x130 != null: FUN_00517250(old) tear down
//   if pSpecialFx != null: vtable+0xF8(pSpecialFx, 1, 0) attach
//   this+0x130 = pSpecialFx
//
// Related: NDSpecialFX_LoadFromScriptName builds interact_* mission icons.
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

void FUN_00517250(int pOldFx);

static constexpr int kOffInteractSpecialFx = 0x130;

void __thiscall CVOGObject_SetInteractSpecialFX(void* thisObject, void* pSpecialFx)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(thisObject);
    int pOld = *reinterpret_cast<int*>(base + kOffInteractSpecialFx);
    if (pOld != 0) {
        FUN_00517250(pOld);
    }

    if (pSpecialFx != nullptr) {
        using VAttach = void (__thiscall*)(void*, void*, int, int);
        auto* const pVTable = *reinterpret_cast<void***>(thisObject);
        auto  const pAttach = reinterpret_cast<VAttach>(pVTable[0xF8 / sizeof(void*)]);
        pAttach(thisObject, pSpecialFx, 1, 0);
    }

    *reinterpret_cast<void**>(base + kOffInteractSpecialFx) = pSpecialFx;
}
