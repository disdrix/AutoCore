# Function record: CDlgCharSheet2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008faaf0` |
| **Canonical name** | `CDlgCharSheet2d_CreateChildWidgets` |
| **Address** | `0x008faaf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-ui / character sheet |
| **Completion status** | **Partial structural** — decompiler blocked (overlapping varnodes); image prolog + full string/callee set sealed; dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md`, `reviews/B_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md` — **accept-with-gaps** |

## Purpose

Virtual CreateChildWidgets for the 2D character sheet dialog. Builds NDUI child tree from `i_d_c_2d_*` / `i_d_tabs_c_2d_*` XML (identity, XP, credits, four attributes + add + tooltips, close). Optional `Client_MaybeShowFirstTimeTip`. UI construct only — no packet send, no attribute-spend logic.

## Signature

```c
void __fastcall CDlgCharSheet2d_CreateChildWidgets(void *this)
```

## Sealed facts (High)

| Fact | Evidence |
|---|---|
| DATA-only xref `0x00a35b30` | `get_function_xrefs` / `read_memory` |
| Entry: `FUN_00792600` → `operator_new(0x488)` → `FUN_0040ddd0` | image |
| Host `this+0x1478`, attach `vtbl+0xA8`, XML `vtbl+0x28` | image |
| Host `this+0x1464` mid-body | image |
| 30 XML string refs (char-sheet family) | signature |
| Callees include `Client_MaybeShowFirstTimeTip` | signature |

## Residuals

- Full 69-block CF / complete host-offset map
- Exact first-time tip id
- Vtable base + slot English index
- Runtime / bit-exact

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md`
- Annotated: `docs/reconstruction/raw/aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CDlgCharSheet2d_CreateChildWidgets.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md`
