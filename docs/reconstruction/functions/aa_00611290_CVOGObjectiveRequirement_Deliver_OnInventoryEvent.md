# Function record: Deliver OnInventoryEvent (INFERRED)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611290` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` |
| **Address** | `0x00611290` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Status** | Human-refined partial; dual residual A/B sealed 2026-07-29 |
| **Name confidence** | **Probable** (Deliver family / OnInventoryEvent role); suffix `_Inferred` — original PDB unknown |
| **Bit-for-bit / runtime / diff** | Open (policy / not run) |

## Purpose

Deliver-family virtual **OnInventoryEvent** (vtable `PTR_FUN_009e0f24` **+0x04**). When the inventory event type is **4**, cargo holds the required CBID quantity (or qty check is bypassed), and the event id matches the deliver target id, mark the objective progress slot complete (**float 1.0**) and optionally build a toast.

**Not Collect.** Collect type-2 Eval is `0x00611940`. Do not label this “Collect type-4” (UF-014): **req type 3** / **event type 4**.

## Signature (decompiler-derived)

```c
// __thiscall  this = CVOGObjectiveRequirement_Deliver*
uint32_t __thiscall Deliver_OnInventoryEvent(
    int req,              // this
    int character,        // param_2
    int *progressSlots,   // param_3  (slot base; index uses req+8)
    int eventType,        // param_4  — must be 4
    float eventItemId,    // param_5  — compared as int to req+0x18
    undefined4 unused6,
    undefined4 unused7,
    int toastObject);     // param_8  — TFID source when toast enabled
```

## Control flow (sealed)

1. If `eventType != 4` → return **0**.
2. If `*(char*)(*(character+0x250)+0x2b0) == 0` (no cargo grid) → return **0** (null check on grid pointer).
3. `count = InventoryGrid_CountItemsByCbid(cargoGrid, *(req+0x10) /*CBID*/, 0 /*exclude Broken*/)`.
4. If `(int)eventItemId != *(req+0x18)` → return **0**.
5. If **not** (`*(req+0x14) <= count` **OR** `*(char*)(req+0x23) == 0`) → return **0**.
6. `progressSlots[*(uint8_t*)(req+8) + 1] = bitcast_i32(g_flOne)` // 1.0f
7. If `*(char*)(req+0x22) != 0`: pack char COID + object TFID → `CVOGReaction_BuildTextParams`.
8. Return **1**.

## `+0x23` polarity (dual residual sealed)

| Value | Effect |
|------:|--------|
| **0** | **Bypass quantity gate** — still need event type 4, cargo grid, and id match |
| **≠0** (ctor default **1**) | Enforce `NumToDeliver/need (req+0x14) ≤ count` |

Raw form: `(*(req+0x14) <= count) || (*(char*)(req+0x23) == '\0')`.

Evidence:

- Body at `0x00611290` (raw + re-decompile)
- Identical OR in CargoReady `0x00610f20`
- Deliver ctor `0x00610bc0` stores `*(req+0x23) = 1`

**Not** “skip when flag set.” Behavioral name: **require-count / enforce-qty**. XML/asset field name open.

## Layout (this requirement)

| Offset | Role | Confidence |
|-------:|------|------------|
| +0x00 | vptr → `PTR_FUN_009e0f24` | High |
| +0x0c | requirement type code (**3** Deliver) | High (ctor) |
| +0x08 | progress slot index (byte) | High |
| +0x10 | item CBID for Count | High |
| +0x14 | needed quantity | High |
| +0x18 | matched event / deliver target id | High |
| +0x22 | toast enable (char) | High |
| +0x23 | require-count (char; 1=enforce, 0=bypass qty) | High |

## Vtable (Deliver `PTR_FUN_009e0f24`)

| Slot | VA | Role (this dual) |
|-----:|----|------------------|
| +0x04 | `0x00611290` | **this** OnInventoryEvent |
| +0x38 | `0x00610f20` | CargoReady (sibling qty/`+0x23`) |

Only DATA xref to `0x00611290`: `0x009e0f28` (vtable slot).

## Callees

| Addr | Name / role |
|------|-------------|
| `0x005711c0` | `InventoryGrid_CountItemsByCbid` (includeBroken=0) |
| (toast) | `CVOGReaction_BuildTextParams` |
| const | `g_flOne` @ `0x00a0f2a0` = `1.0f` |

## Related

| Stable ID | Addr | Relation |
|-----------|------|----------|
| `aa_00610bc0` | `0x00610bc0` | Deliver ctor (type 3, defaults `+0x22/+0x23=1`) |
| `aa_00610f20` | `0x00610f20` | Deliver CargoReady — same qty/`+0x23` |
| `aa_005711c0` | `0x005711c0` | CountItemsByCbid |
| `aa_00611940` | `0x00611940` | Collect_Eval — **different class** (do not merge) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00611290_CVOGObjectiveRequirement_Deliver_OnInventoryEvent.md` / `aa_00611290_FUN_00611290.md`
- Annotated: `docs/reconstruction/raw/aa_00611290_CVOGObjectiveRequirement_Deliver_OnInventoryEvent.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Deliver_OnInventoryEvent.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00611290_CVOGObjectiveRequirement_Deliver_OnInventoryEvent.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00611290_CVOGObjectiveRequirement_Deliver_OnInventoryEvent.md`

## Confidence summary

| Claim | Level |
|---|---|
| CF / gates / returns from decompiler | **High** |
| Deliver type 3 / not Collect (UF-014) | **High** |
| `+0x23==0` qty bypass polarity | **High** |
| eventType 4 enum name | **Open** |
| Parameter semantic names | **Probable** |
| Original C++ name | **Tentative** (`_Inferred`) |

## Gaps

- event type 4 enum map
- original symbol
- XML name for `+0x23`
- runtime / bit-exact / image diff
