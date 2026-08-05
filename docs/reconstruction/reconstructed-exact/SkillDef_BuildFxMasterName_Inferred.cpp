// =============================================================================
// SkillDef_BuildFxMasterName_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Build FX master basename into caller buffer:
//             "skill_" + classTag(+0x180) + categoryTag(+0x17c) + name(+0x5a6)
//           Class: 0=h_ 1=m_ 2=c_ else=n_
//           Category: 0=c_ 1=e_ 2=o_ 3=r_ else=fixme_
//
// Address:  0x00540090  (autoassault.exe, image base 0x400000)
// Body:     0x00540090–0x00540282 (498 bytes; plain ret / cdecl)
// Stable:   aa_00540090
// System:   skills-abilities / client-fx
// Ghidra:   FUN_00540090
//
// ABI:      __cdecl
//             skillPayload*  (callers pass SkillDef RB-node + 0x10)
//             char* out
//             size_t cap     (typically 0x400)
//
// Callers:  FxCache_EnsureMasterAndResolve (0x005408f0),
//           FxCache_ApplyWithNfxEnsure (0x00542790),
//           FUN_005c74e0 SpecialFX path
//
// Exactness: CF mirrors raw + live decompile + read_memory string/ABI seal.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-N).
// =============================================================================

#include <cstdint>
#include <cstring>

// String literals sealed via read_memory @ 0x009d01bc / 0x009cf9e0 family.
// Retail places them in .rdata; reconstruct as C strings for readability.

void SkillDef_BuildFxMasterName_Inferred(
    const char *skillPayload /* param_1 */,
    char *out,
    size_t cap)
{
    char buf[0x400];

    // Seed "skill_" (DAT_009d01bc..c2 → local_400 / local_3fc / local_3fa[0])
    buf[0] = 's';
    buf[1] = 'k';
    buf[2] = 'i';
    buf[3] = 'l';
    buf[4] = 'l';
    buf[5] = '_';
    buf[6] = '\0';

    const int classTag = *reinterpret_cast<const int *>(skillPayload + 0x180);
    // Append class fragment at end of buf (strlen + write 2–3 bytes)
    char *p = buf;
    while (*p != '\0') {
        ++p;
    }
    if (classTag == 0) {
        p[0] = 'h';
        p[1] = '_';
        p[2] = '\0';
    } else if (classTag == 1) {
        p[0] = 'm';
        p[1] = '_';
        p[2] = '\0';
    } else if (classTag == 2) {
        p[0] = 'c';
        p[1] = '_';
        p[2] = '\0';
    } else {
        p[0] = 'n';
        p[1] = '_';
        p[2] = '\0';
    }

    const int category = *reinterpret_cast<const int *>(skillPayload + 0x17c);
    p = buf;
    while (*p != '\0') {
        ++p;
    }
    switch (category) {
    case 0:
        p[0] = 'c';
        p[1] = '_';
        p[2] = '\0';
        break;
    case 1:
        p[0] = 'e';
        p[1] = '_';
        p[2] = '\0';
        break;
    case 2:
        p[0] = 'o';
        p[1] = '_';
        p[2] = '\0';
        break;
    case 3:
        p[0] = 'r';
        p[1] = '_';
        p[2] = '\0';
        break;
    default:
        // "fixme_"
        p[0] = 'f';
        p[1] = 'i';
        p[2] = 'x';
        p[3] = 'm';
        p[4] = 'e';
        p[5] = '_';
        p[6] = '\0';
        break;
    }

    // Append C-string at skillPayload+0x5a6 (dword bulk + byte tail in retail)
    const char *name = skillPayload + 0x5a6;
    const char *nameEnd = name;
    while (*nameEnd != '\0') {
        ++nameEnd;
    }
    p = buf;
    while (*p != '\0') {
        ++p;
    }
    while (name < nameEnd) {
        *p++ = *name++;
    }
    *p = '\0';

    std::strncpy(out, buf, cap);
}
