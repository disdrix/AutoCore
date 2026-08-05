# Function record: CDlgTrade2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008847f0` |
| **Canonical name** | `CDlgTrade2d_CreateChildWidgets` |
| **Address** | `0x008847f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Asm-structural sealed** — decompiler blocked (overlapping varnodes); dual A/B accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Client trade dialog **CreateChildWidgets**: rebuild child tree, allocate/skin/attach dual inventory grids, credit digits, offer/balance chrome, ready/accept/cancel/close buttons. Vtable DATA `@ 0x00a56ad8`. No network.

## Signature

```c
void __fastcall CDlgTrade2d_CreateChildWidgets(void *this)
```

## Key facts

| Item | Value |
|---|---|
| Size | ~1213 insn, 123 BB, CC 46, 68 calls, 41 strings |
| Local inv | `*(DAT_00d1b6d8+0xce0)` → grid `@ host+0x588`, id `40002` |
| Them inv | `*(host+0x510+0xce0)` → grid `@ host+0x58c`, id `40003`, owner flag **6** |
| Widget ids | 40000 close … 40005 cancel |
| XML prefix | `i_d_t_2d_*` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008847f0_CDlgTrade2d_CreateChildWidgets.md`
- Annotated: `docs/reconstruction/raw/aa_008847f0_CDlgTrade2d_CreateChildWidgets.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CDlgTrade2d_CreateChildWidgets.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md`
