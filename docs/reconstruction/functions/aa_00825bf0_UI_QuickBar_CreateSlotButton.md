# Function record: UI_QuickBar_CreateSlotButton

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825bf0` |
| **Canonical name** | `UI_QuickBar_CreateSlotButton` |
| **Address** | `0x00825bf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B accept-with-gaps** (2026-07-29) — ctor / size / XML / key fields sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00825bf0`
- Prior auto-slug names (if any): leave on disk; canonical is `UI_QuickBar_CreateSlotButton`
- Legacy: `Skill_i_d_qb_2d_btn_quickbar_xml_00825bf0`

## Purpose

In-place constructor for a QuickBar slot-button NDUI widget: base ctor → derived vtable `PTR_FUN_00a75004` → field defaults → load `i_d_qb_2d_btn_quickbar.xml`. Returns `this`. Client UI only (no wire).

## String evidence

`"i_d_qb_2d_btn_quickbar.xml"`

## Signature (sealed)

```c
// this = operator_new(0x554) buffer; returns this
void * UI_QuickBar_CreateSlotButton(void *this_);
```

## Object size

`0x554` (sole caller `FUN_008a16b0`, both sites)

## Key field defaults (this unit)

| Off | Init |
|----:|------|
| `+0x00` | `PTR_FUN_00a75004` |
| `+0x4fc` | `0` (selected/active) |
| `+0x500` | `0xFFFFFFFF` (index sentinel) |
| `+0x508` | `0.88f` (`DAT_00aaabc4`, default DOWN_SIZE_RATIO) |
| `+0x514` | `0.1f` (shared pool `@0x00a0f730`) |
| `+0x540..+0x550` | `0` (5 dwords; `+0x548` → label child* after XML) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.md`
- Annotated: `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/UI_QuickBar_CreateSlotButton.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00825bf0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00825bf0_UI_QuickBar_CreateSlotButton.md`
- Review B: `docs/reconstruction/reviews/B_aa_00825bf0_UI_QuickBar_CreateSlotButton.md`
- Dual report: `docs/agents/task-dual-ab-00825bf0-ui-quickbar-create-slot-button-report.md`

## Callers / callees

**Callers (2 xrefs):** `FUN_008a16b0` @ `0x008a19d2`, `0x008a1b1c`  
**Callees:** `FUN_00792d20` (base ctor), `NDUIWindow_ReloadInterface`  
**Related:** dtor `FUN_00825bb0`; XML attr `FUN_00825cd0`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Naming from string literals | **High** |
| Size `0x554` / sole dual callers | **High** |
| `+0x500` / `+0x508` / `+0x4fc` roles | **High** |
| Residual field English / RTTI | **Open** |
| Parameter semantic product names | **Inferred** |
