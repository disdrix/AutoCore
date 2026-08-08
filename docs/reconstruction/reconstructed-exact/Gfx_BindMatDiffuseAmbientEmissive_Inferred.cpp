// =============================================================================
// Gfx_BindMatDiffuseAmbientEmissive_Inferred  (named alias of FUN_005194f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005194f0
// Address:   0x005194f0 – 0x00519657  (autoassault.exe, image base 0x400000)
// Body:      359 bytes (0x167)
// System:    graphics / material FX
// Generated: 2026-08-04 (WQ9R-F dual seal)
// Exactness: Behavior-preserving rewrite of raw decompile + Capstone/bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Contract:
//   void Gfx_BindMatDiffuseAmbientEmissive_Inferred(void* shaderHost, void* colorVec);
//   // cdecl, 2 stack args, void
//
//   shaderHost+0xc0 / +0xc4 : dword vector of effect entry pointers
//   colorVec+4 / +8         : float4 vector (stride 0x10)
//   require shaderN * 3 == colorN (else VOG_DEBUG_STOP log)
//   for each shader i:
//     this = entry[i] + 0x20
//     SetParam(this, "MatDiffuse",  &colors[i*3 + 0])
//     SetParam(this, "MatAmbient",  &colors[i*3 + 1])
//     SetParam(this, "MatEmissive", &colors[i*3 + 2])
//   colorVec.resize(0) via FUN_0051def0
//
// Strings: MatDiffuse@0x00a2f8cc, MatAmbient@0x00a2f8c0, MatEmissive@0x00a2f8b4
// =============================================================================

#include <cstdint>

struct ShaderHost_Inferred {
    uint8_t  pad_000[0xc0];
    uint32_t* entryBegin; // +0xc0
    uint32_t* entryEnd;   // +0xc4
};

struct ColorVec_Inferred {
    uint32_t unk0;     // +0
    float*   begin;    // +4  float4*
    float*   end;      // +8
};

// FUN_009700f0 — thiscall ECX=effect+0x20; stack: float4*, name (order per push: color then name)
int __thiscall Effect_SetNamedFloat4_Inferred(void* effectPlus20, const char* name, float* rgba);
// FUN_0051def0 — thiscall resize float4 vector to newCount; stack fill if growing
void __thiscall ColorVec_Resize_Inferred(ColorVec_Inferred* self, uint32_t newCount, float fillX, float fillY, float fillZ, float fillW);
void FUN_007a4480(int level, const char* fmt, ...);

extern float g_flOne; // 0x00a0f2a0

static inline int CountDword(uint32_t* b, uint32_t* e)
{
    if (b == nullptr) return 0;
    return (int)((e - b)); // ptr diff already element count; bytes: (end-begin)>>2
}

static inline int CountFloat4(float* b, float* e)
{
    if (b == nullptr) return 0;
    return (int)(((uint8_t*)e - (uint8_t*)b) >> 4);
}

void Gfx_BindMatDiffuseAmbientEmissive_Inferred(void* shaderHost, void* colorVec)
{
    auto* host = (ShaderHost_Inferred*)shaderHost;
    auto* colors = (ColorVec_Inferred*)colorVec;

    int shaderN = 0;
    if (host->entryBegin != nullptr)
        shaderN = (int)(((uint8_t*)host->entryEnd - (uint8_t*)host->entryBegin) >> 2);

    int colorN = 0;
    if (colors->begin != nullptr)
        colorN = (int)(((uint8_t*)colors->end - (uint8_t*)colors->begin) >> 4);

    if (shaderN * 3 != colorN)
        FUN_007a4480(0, "VOG_DEBUG_STOP");

    int i = 0;
    int slotNeed = 2; // exclusive index that must exist: 2,5,8,...
    int byteOff = 0;
    for (;;) {
        int sn = 0;
        if (host->entryBegin != nullptr)
            sn = (int)(((uint8_t*)host->entryEnd - (uint8_t*)host->entryBegin) >> 2);
        if (i >= sn)
            break;

        int cn = 0;
        if (colors->begin != nullptr)
            cn = (int)(((uint8_t*)colors->end - (uint8_t*)colors->begin) >> 4);
        if (slotNeed >= cn)
            break;

        uint8_t* base = (uint8_t*)colors->begin;
        uint32_t entry = host->entryBegin[i];
        void* effectThis = (void*)(entry + 0x20);

        Effect_SetNamedFloat4_Inferred(effectThis, "MatDiffuse",  (float*)(base + byteOff + 0x00));
        Effect_SetNamedFloat4_Inferred(effectThis, "MatAmbient",  (float*)(base + byteOff + 0x10));
        Effect_SetNamedFloat4_Inferred(effectThis, "MatEmissive", (float*)(base + byteOff + 0x20));

        i += 1;
        slotNeed += 3;
        byteOff += 0x30;
    }

    // resize(0); fill (0,0,0,1) only used if growing
    ColorVec_Resize_Inferred(colors, 0, 0.0f, 0.0f, 0.0f, g_flOne);
}

// Scaffold twin entry (same VA):
void FUN_005194f0(void* shaderHost, void* colorVec)
{
    Gfx_BindMatDiffuseAmbientEmissive_Inferred(shaderHost, colorVec);
}
