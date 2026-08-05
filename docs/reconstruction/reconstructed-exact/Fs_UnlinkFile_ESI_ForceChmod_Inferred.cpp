// =============================================================================
// Fs_UnlinkFile_ESI_ForceChmod_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b080
// Address:   0x0076b080–0x0076b0f1 (114 B / 0x72)
// Module:    autoassault.exe (image base 0x400000)
// System:    filesystem — force-writable unlink of one path
// Wave:      W37-S OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite; bytes sealed in raw W37-S append.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// =============================================================================

#include <cstdint>
#include <sys/stat.h>
#include <io.h> // MSVC _chmod / _unlink (conceptual; retail uses CRT imports)

// cdecl; force on stack; path in ESI (register formal — callers LEA/MOV ESI)
// MSVC: _S_IFREG = 0x8000 (bit 15), _S_IWRITE = 0x80 (bit 7),
//       _S_IREAD|_S_IWRITE = 0x180
bool __cdecl Fs_UnlinkFile_ESI_ForceChmod_Inferred(char force /* , ESI = path */)
{
    // Register formal: const char* path = ESI;
    const char* path = nullptr; // filled by register at call

    if (force != 0) {
        struct _stat sb {};
        if (_stat(path, &sb) == 0 && ((static_cast<unsigned>(sb.st_mode) >> 15) & 1) != 0) {
            if (_stat(path, &sb) == 0 &&
                ((~static_cast<unsigned>(static_cast<uint8_t>(sb.st_mode) >> 7)) & 1) != 0) {
                _chmod(path, 0x180);
            }
        }
    }
    return _unlink(path) == 0;
}

// Full 114 B hex:
// 83ec24807c2428007456578b3d04659c008d4424045056ffd783c40885c0753f
// 8b4c240ac1e90f80e101884c242c742f8d5424045256ffd783c40885c07520
// 8a44240ac0e807f6d024018844242c740f688001000056ff1568659c00
// 83c4085f56ff15a0649c00f7d81bc083c00183c428c3
