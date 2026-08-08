# Function record: UI_InteractionMenu_AddTrade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fc40` |
| **Canonical name** | `UI_InteractionMenu_AddTrade_Inferred` |
| **Ghidra name** | `FUN_0082fc40` |
| **Address** | `0x0082fc40`–`0x0082fd4a` exclusive |
| **Body size** | **266 B** (`0x10A`); `ret` (`C3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction menu / Trade UI |
| **Completion status** | **Dual sealed** (MEGA-077 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `UI_InteractionMenu_AddTrade_Inferred`
- Prior: `UI_int_btn_generic_0082fc40` / `FUN_0082fc40`

## Purpose

Create Trade (`0x11175`) generic interaction button for a target, store on menu host (`+0x550`), disable when squared world-distance to local player exceeds 1600.0f (linear range 40).

## Signature

```c
// ESI = menu host; EBX = target object; ret 0
void UI_InteractionMenu_AddTrade_Inferred(void* menuHost, void* targetObject);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082fc40_FUN_0082fc40.md`
- Annotated: `docs/reconstruction/raw/aa_0082fc40_FUN_0082fc40.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddTrade_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082fc40.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082fc40_FUN_0082fc40.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0082fe20` (`UI_InteractionMenu_PopulateTargetButtons_Inferred`) ×2 (`0x0082fed7`, `0x0082ff0b`) |
| Direct callees | none |
| Indirect | host `vtbl+0x444`, btn `vtbl+0x1D8`, pos `vtbl+0x1A0` ×2, btn `vtbl+0xD4` |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile | **Confirmed** |
| Trade string + id `0x11175` | **Confirmed** |
| Slot `+0x550` | **Confirmed** |
| Dist² > 1600.0f disable | **Confirmed** |
| ESI host / EBX target ABI | **Confirmed** |
| Product English name | **Inferred** |
