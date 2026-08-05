# Function record: Client_InitDefaultKeybinds

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f8720` |
| **Canonical name** | `Client_InitDefaultKeybinds` |
| **Address** | `0x007f8720` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Human-refined partial** — sectioned DIK defaults + dual A/B reviews; helper bodies + drive DIK seed open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Last refined** | 2026-07-23 (human-refine: sections 0–8; pActionMap rename; dual reviews) |

## Purpose

Write default DIK/VK codes into ActionMap action slots when per-slot customized flags are clear. Slot stride `0x34`. Called from `Client_ActionMap_Init` after display-name fill.

## Signature (decompiler-derived)

```c
void Client_InitDefaultKeybinds(void)
// ActionMap* arrives in EDI (decomp unaff_EDI → pActionMap)
```

## Artifacts

| Layer | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f8720_Client_InitDefaultKeybinds.md` |
| Annotated | `docs/reconstruction/raw/aa_007f8720_Client_InitDefaultKeybinds.annotated.md` |
| Clean (sectioned) | `docs/reconstruction/reconstructed-exact/Client_InitDefaultKeybinds.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_007f8720_Client_InitDefaultKeybinds.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007f8720_Client_InitDefaultKeybinds.md` |
| Parent | `Client_ActionMap_Init` `0x007f9110` |
| Sibling | `Client_InitActionDisplayNames` `0x007f7570` |

## Notable defaults (body immediates)

| Slot family | Primary DIK | Notes |
|---|---|---|
| Inventory | `0x17` @ `+0x5ea` | Plate: I |
| Mission inventory | `0x17` + mod `0x2a` | Shift+I |
| QuickBar 1–10 | `2..0x0B` @ `+0xc9e` family | Primary row |
| Shift QB / pages | `2..9` + mod `0x2a` | Higher offsets |
| Drive thr/steer/HB | **open** | Not named in this body; may be helpers |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Inventory / QB immediates | High |
| Human DIK labels (I, 1–0) | Probable |
| `pActionMap` object type | High (context) |
| Drive DIK seeding in this body | Open / likely false for named stores |
| `FUN_007f74a0` / `FUN_007f72e0` | Open |

## Open questions

1. What does `FUN_007f74a0` write (drive defaults?)?
2. What does `FUN_007f72e0(map, 2|3)` do?
3. Map slot offsets → global held `DAT_00d1bc*` for DriveControlTick.
