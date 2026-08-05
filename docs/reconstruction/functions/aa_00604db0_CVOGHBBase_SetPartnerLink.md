# Function record: CVOGHBBase_SetPartnerLink

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604db0` |
| **Canonical name** | `CVOGHBBase_SetPartnerLink` |
| **Ghidra name** | `FUN_00604db0` |
| **Address** | `0x00604db0`–`0x00604dc4` (`ret 4`; int3 pad) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `object / combat-target / HB` |
| **Completion status** | **Dual A/B complete** (2026-07-29 W20-S) — **accept** |
| **Bit-for-bit / runtime / diff** | Body byte-sealed; runtime golden open |

## Alias

- `FUN_00604db0`
- `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0` (**superseded** — seed misname)

## Purpose

Set `this+0x24` partner heartbeat pointer when clearing (`partner == null`) or when the candidate partner’s owner at `+0x18` differs from this owner; no-op when both non-null and owners match.

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack partner*, ret 4, void
void CVOGHBBase_SetPartnerLink(void *thisHb, void *partnerHb);
```

## Artifacts

| Role | Path |
|---|---|
| Raw scaffold + re-verify | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBBase_SetPartnerLink.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00604db0.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00604db0_FUN_00604db0.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller (only) | `0x005172d0` sites `0x005173b6`, `0x005173be` | `Object_SetSelectedTarget` — both-ways partner cross-link |
| Callees | — | **none** (leaf) |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Partner field | `this+0x24` | High (bytes) |
| Owner field | `this+0x18` / `partner+0x18` | High (bytes + AttachOwner seals) |
| Same-owner skip | non-null && equal owners | High |
| Null partner | always writes 0 | High |

## Confidence

| Claim | Level |
|---|---|
| Control flow byte-exact | High |
| Owner / partner field roles | High |
| Product C++ name | Tentative (`CVOGHBBase_` family inferred) |
| Runtime golden | Open |
