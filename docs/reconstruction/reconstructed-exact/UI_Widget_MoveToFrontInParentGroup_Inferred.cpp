// =============================================================================
// UI_Widget_MoveToFrontInParentGroup_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Move a UI widget to the front of its parent group's child-pointer
//           vector (erase-if-present + InsertN at begin). Early-out when the
//           group vector already has exactly one element, or return -1 when
//           the widget has no parent group (widget+0x88 == 0).
//
// Address:  0x00756c90  (autoassault.exe, image base 0x400000)
// Stable:   aa_00756c90
// System:   inventory-transfer (UI tab/group chrome helper — no inventory wire)
// Ghidra:   FUN_00756c90
//
// Convention (custom register ABI — not portable C):
//   EDI          = widget*
//   (no stack args)
//   EAX          = 0 on success; 0xFFFFFFFF if no parent group
//   RET          (not RET n)
//
// Layout:
//   widget+0x88          parent group*
//   group+0x90           vector object base passed to InsertN helper
//   group+0x94 / +0x98   vector begin / end (T**; elem size 4)
//   group+0x9c           capacity end (via InsertN param_2+0xc)
//
// Callees:
//   memmove            — erase shift (IAT 0x009c652c)
//   FUN_00456960       — StdVector InsertN
//                        ECX=count(1), EDX=vec(group+0x90),
//                        stack=insert_pos(begin), EAX=&value (widget)
//
// Callers (evidence): FUN_00888b00, FUN_00889410, FUN_00889fb0, FUN_00887780,
//   + other tab/dialog hosts (28 UNCONDITIONAL_CALL xrefs). Typically after
//   FUN_00822cb0 with BL=0 (collapse) on the same tab chrome control.
//
// Contrast:
//   FUN_00756be0 — true detach (erase + clear widget+0x88)
//   FUN_00756d40 — rebind/restore group link path
//
// Exactness: Behavior-preserving CF from live disasm + decompile.
// Dual R12-003 2026-08-05.
// Dual reviews:
//   reviews/A_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md
//   reviews/B_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md
// Scaffold twin: reconstructed-exact/FUN_00756c90.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

// StdVector InsertN — residual dual. Live custom multi-register ABI.
// count@ECX, vec@EDX, insert_pos@stack, value_src@EAX (*EAX written N times).
extern "C" void FUN_00456960(std::uint32_t count_ecx,
                             void* vec_edx,
                             void* insert_pos_stack);

// Register-accurate entry: widget in EDI. Clean form takes widget* for ports.
extern "C" std::uint32_t UI_Widget_MoveToFrontInParentGroup_Inferred(void* widget_edi)
{
    auto* widget = reinterpret_cast<std::uint8_t*>(widget_edi);

    auto* group = *reinterpret_cast<std::uint8_t**>(widget + 0x88);
    if (group == nullptr) {
        return 0xFFFFFFFFu;
    }

    auto** begin = *reinterpret_cast<void***>(group + 0x94);
    auto** end   = *reinterpret_cast<void***>(group + 0x98);

    if (begin != nullptr) {
        const std::ptrdiff_t size = end - begin; // elem size pointer
        if (size == 1) {
            return 0;
        }
    }

    // Erase self if present (memmove tail left by one pointer).
    for (auto** p = begin; p != end; ++p) {
        if (*p == widget_edi) {
            const std::size_t tail_bytes =
                static_cast<std::size_t>(reinterpret_cast<char*>(end) -
                                         reinterpret_cast<char*>(p + 1));
            std::memmove(p, p + 1, tail_bytes);
            end = *reinterpret_cast<void***>(group + 0x98);
            *reinterpret_cast<void***>(group + 0x98) = end - 1;
            break;
        }
    }

    // Reload begin after possible erase; InsertN(1) of widget at front.
    begin = *reinterpret_cast<void***>(group + 0x94);
    void* vec_base = group + 0x90;
    void* value = widget_edi;
    // Live: MOV ECX,1 / LEA EDX,[group+0x90] / PUSH begin / EAX=&local / CALL
    FUN_00456960(/*ECX*/ 1u, /*EDX*/ vec_base, /*stack pos*/ begin);
    (void)value; // value delivered via *EAX in retail image

    return 0;
}

// Ghidra default symbol — same VA / body.
extern "C" std::uint32_t FUN_00756c90(void* widget_edi)
{
    return UI_Widget_MoveToFrontInParentGroup_Inferred(widget_edi);
}
