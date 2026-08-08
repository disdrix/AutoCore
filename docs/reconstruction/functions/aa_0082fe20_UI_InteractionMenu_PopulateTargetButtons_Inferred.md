# Function record: UI_InteractionMenu_PopulateTargetButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fe20` |
| **Canonical name** | `UI_InteractionMenu_PopulateTargetButtons_Inferred` |
| **Ghidra name** | `FUN_0082fe20` |
| **Address** | `0x0082fe20`–`0x0082ff3f` exclusive |
| **Body size** | **287 B** (`0x11F`); `ret` (`C3`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction menu / social UI |
| **Completion status** | **Dual sealed** (WQ9E-D 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `UI_InteractionMenu_PopulateTargetButtons_Inferred`
- Prior: `FUN_0082fe20`

## Purpose

Populate the interaction-menu social action buttons for a resolved target TFID when the menu host is active. Rebuilds popup shell, gates local/self/affinity, then runs seven button packs (Ignore, Friends, Tell, Trade, Clan, Convoy, name) in forward or reverse order.

## Signature

```c
// __thiscall; ECX = menu host*; ret 0
void UI_InteractionMenu_PopulateTargetButtons_Inferred(MenuHost* menu);
```

## Layout / contracts

| Offset / slot | Role |
|---|---|
| `this+0x4C0` | active/valid menu gate |
| `this+0x578` | target TFID_16 |
| `this+0x2B0` | widget used by close path |
| `vtbl+0x478` | pack order flag |
| `vtbl+0x210` (target) | owner/parent probe |
| `vtbl+0x298` (local) | affinity / blocked probe |
| DATA xref `0x00a720e0` | vtbl method pointer |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082fe20_FUN_0082fe20.md`
- Annotated: `docs/reconstruction/raw/aa_0082fe20_FUN_0082fe20.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_PopulateTargetButtons_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082fe20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082fe20_FUN_0082fe20.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | none as CALL; **DATA** vtbl @ `0x00a720e0` |
| Callees | `FUN_0082d2b0`, `Object_ResolveFromTFID`, `FUN_0090d400`, packs `0082f8d0`/`f9a0`/`f810`/`fc40`/`fa60`/`fb30`/`fd50` |
| Dualed child | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`0x0082fb30`) ×2 |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile / raw | **Confirmed** |
| Pack orders + convoy child sites | **Confirmed** |
| Product English name | **Inferred** |
