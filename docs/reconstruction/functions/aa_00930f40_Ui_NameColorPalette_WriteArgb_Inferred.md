# Function record: Ui_NameColorPalette_WriteArgb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930f40` |
| **Canonical name** | `Ui_NameColorPalette_WriteArgb_Inferred` |
| **Ghidra name** | `FUN_00930f40` |
| **Address** | `0x00930f40`–`0x00930f9c` (+ jump table `@0x00930fa0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / entity name-label color (skills residual consumer of dualed name-color) |
| **Name confidence** | **High** role (fixed palette ARGB writer); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9E-C** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: write one of five fixed **AARRGGBB** name-color palette entries into a 4-byte out buffer selected by integer **mode**. Sole caller is dualed `Ui_ResolveEntityNameColor_Inferred` (`0x00930fc0`).

## Signature

```c
uint32_t* Ui_NameColorPalette_WriteArgb_Inferred(int mode /*ECX*/, uint8_t* out /*EAX*/);
// bare ret; EAX = out
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Modes → red/beige/cyan/green/white | **High** |
| ECX mode, EAX out, bare ret | **High** |
| Leaf | **High** |
| BGRA memory / AARRGGBB dword | **High** |
| Product symbol | **Open** |

### Palette

| mode | AARRGGBB |
|---|---|
| 0 | `0xFFC41616` |
| 1 / default | `0xFFDCE0C8` |
| 2 | `0xFF66D3EA` |
| 3 | `0xFF14D314` |
| −1 | `0xFFFFFFFF` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00930f40_FUN_00930f40.md`
- Annotated: `docs/reconstruction/raw/aa_00930f40_FUN_00930f40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Ui_NameColorPalette_WriteArgb_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00930f40.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md`, `B_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00930f40_FUN_00930f40.md`
