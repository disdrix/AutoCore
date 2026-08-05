# Function record: Client_Interact_SelectBestPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00490070` |
| **Canonical name** | `Client_Interact_SelectBestPickTarget` |
| **Prior names** | `FUN_00490070`, `Named_CalleeOf_Client_InteractClickPickTarget_00490070` |
| **Address** | `0x00490070` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Calling convention** | MSVC `__thiscall` — `this` = Client*; stack screenXY*, unused, char filterSelfOwned |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (score table + two-pass enum + FLT_MAX) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Purpose

**Primary** world-object pick for `Client_InteractClickPickTarget` (`0x009247b0`).

1. Early-out if client gfx views `+0xC0` or `+0xBC` are null.
2. Unproject screen coords (`FUN_0075c340` / `GfxView_UnprojectScreenToWorldRay_Inferred`) into local ray buffers.
3. **Two** passes of object enumerator `FUN_004bae00` with flag byte **0 then 1**.
4. For each candidate: visibility/interact gate → distance sample → priority from def flags + **clone type switch** → keep **max priority**, ties → **min distance**.
5. Return best `object*` or `NULL`.

Does **not** send UseObject; parent click hub does that after selection.

## Signature (sealed CF)

```c
// this = Client*
Object* __thiscall Client_Interact_SelectBestPickTarget(
    void* this,
    void* screenXY,      // param_2 → unproject
    void* unused,        // param_3 — unused in body
    char filterSelfOwned // param_4 — 0: skip objects owned by local player char
);
```

## Priority table (SEALED)

| Pri | When |
|----:|------|
| `0x50` | def flags `@+0x3F2` bit 14 |
| `0x46` | bit 7 (if pri `< 0x47`); type 10-family null parent |
| `0x5A` | type 10/0xC/0x10/0x1C with `obj[0x2B]` parent (retarget); type `0xE` |
| `0x3C` | types 1/3 mission interact\|pick hit; type `0x12` creature `vtbl+0x198` |
| `0x32` | type `0x12` + `FUN_0040b1b0` |
| `0x28` | default / type `0x14` |
| `0x14` | types 1/3 owner slots or flag `0x2000` |
| `0x64` | type `0x16`; type `0x12` when `0040b1b0` false |
| skip | types `0x1E`, `0x36`, `0x38` |

Init distance / best = **`DAT_00aaa630` = FLT_MAX** (`FF FF 7F 7F`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00490070_FUN_00490070.md`
- Annotated: `docs/reconstruction/raw/aa_00490070_FUN_00490070.annotated.md`
- Clean refined: `docs/reconstruction/reconstructed-exact/Client_Interact_SelectBestPickTarget.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00490070.cpp`
- Named seed: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InteractClickPickTarget_00490070.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00490070_Client_Interact_SelectBestPickTarget.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00490070_Client_Interact_SelectBestPickTarget.md`
- Residual: `docs/reconstruction/reviews/a_00490070.md`

## Callers / callees

| Kind | Name / VA |
|------|-----------|
| Caller | `Client_InteractClickPickTarget` `0x009247b0` |
| Callee | `FUN_0075c340` unproject `0x0075c340` |
| Callee | `FUN_004bae00` enumerate `0x004bae00` |
| Callee | `FUN_00524520` ForInteract objective id |
| Callee | `FUN_005245d0` ForPick objective id |
| Callee | `FUN_0040b1b0` def subint check |
| Callee | `__RTDynamicCast` → `CVOGCreature` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / early-out views | **High** (entry bytes) |
| Score selection rule | **High / Sealed** |
| Priority constants | **High / Sealed** |
| Two-pass flag toggle | **High** |
| `DAT_00aaa630` = FLT_MAX | **Confirmed** (`read_memory`) |
| Clone-type switch cases | **High** (raw ≡ live) |
| `param_3` unused | **High** |
| FUN_004bae00 host ECX | **Tentative** (elided) |
| Unproject this (which view) | **Probable** (`+0xC0` family) |
| Product English for every type | **Tentative** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## Dual reviews

- A: `reviews/A_aa_00490070_Client_Interact_SelectBestPickTarget.md`
- B: `reviews/B_aa_00490070_Client_Interact_SelectBestPickTarget.md`
