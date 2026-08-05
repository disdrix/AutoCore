// =============================================================================
// FUN_0055c310  — twin of StdVector_InsertOne_RebindIt_Elem28 (aa_0055c310)
// -----------------------------------------------------------------------------
// Address:   0x0055c310–0x0055c383 exclusive (115 B)
// Wave:      W37-AF 2026-08-04
// Notes:     Ghidra scaffold name preserved; prefer structural name in ports.
// =============================================================================

#include <cstdint>

struct Elem28 { uint32_t w[7]; };
struct VectorElem28 {
    void* unknown0;
    Elem28* begin;
    Elem28* end;
    Elem28* cap_end;
};

extern "C" void __thiscall FUN_0055be00(
    VectorElem28* vec, Elem28* where, uint32_t count, const Elem28* value);

// Ghidra: void __thiscall FUN_0055c310(int,int*,int,undefined4)
void __thiscall FUN_0055c310(
    VectorElem28* param_1,
    Elem28** param_2,
    Elem28* param_3,
    const Elem28* param_4)
{
    Elem28* begin = param_1->begin;
    int index = 0;

    if (begin != nullptr) {
        if ((reinterpret_cast<char*>(param_1->end) -
             reinterpret_cast<char*>(begin)) / 0x1c != 0) {
            index = static_cast<int>(
                (reinterpret_cast<char*>(param_3) -
                 reinterpret_cast<char*>(begin)) / 0x1c);
        }
    }

    FUN_0055be00(param_1, param_3, 1, param_4);
    *param_2 = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(param_1->begin) + index * 0x1c);
}
