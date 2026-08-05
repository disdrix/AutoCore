# Function record: Client_MissionDialog_ControlDispatch_Inferred (`FUN_008aec40`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aec40` |
| **Canonical name** | `Client_MissionDialog_ControlDispatch_Inferred` |
| **Ghidra name** | `FUN_008aec40` |
| **Address** | `0x008aec40` |
| **Body span** | `008aec40` – `008aefbb` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / client mission dialog UI |
| **Completion status** | **Partial** — raw/annotated/clean + dual A/B sealed 2026-07-29; product name / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_008aec40`
- Structural: `Client_MissionDialog_ControlDispatch_Inferred`
- Vtable DATA install: `0x00a4a854` → `0x008aec40`

## Purpose

Mission dialog UI **control-message dispatch**: routes toolkit messages (`msgType`) for control IDs in the `0x9c40` band (close, scale widget, four reward slots, eight dialog buttons, NPC multi-select table). Invokes named mission helpers (`Client_MissionDialogHandleButton`, `Client_ShowNpcMissionDialogUI`) and the close/flush chain (`FUN_007fca10` → FlushPreparedResponse / C2S `0x206E` per UF-010).

## Signature (decompiler + asm)

```c
// __thiscall: this = dialog UI object; ret 8 (2 stack args)
undefined4 __thiscall Client_MissionDialog_ControlDispatch_Inferred(
    int thisDialog, int msgType, int controlId);
```

### Control IDs (this body)

| ID | Role |
|---|---|
| `0x9c40` | Close |
| `0x9c41` | Scale/slider (`msg 0x1a`) |
| `0x9c42`–`0x9c45` | Reward slots 0..3 |
| `0x9c46`–`0x9c4d` | Dialog action buttons → HandleButton |
| `≥0x9c4f` | NPC multi-select indices |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aec40_FUN_008aec40.md`
- Annotated: `docs/reconstruction/raw/aa_008aec40_FUN_008aec40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_008aec40.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md`

## Callers / callees

**Callers:** no code CALL xrefs — **DATA** vtable @ `0x00a4a854` only.

**Callees (from live decompile):**

| Callee | VA / notes |
|---|---|
| `Client_MissionDialogHandleButton` | `0x008ae7c0` |
| `Client_ShowNpcMissionDialogUI` | `0x009438f0` |
| `FUN_007fca10` | close/flush invoker |
| `FUN_007fef20` | abandon-state chrome |
| `CVOGReaction_ResolveObjectTarget` | reward resolve |
| `FUN_007fd420` | UI geometry helper |
| `FUN_008aa3f0` | reward slot click |
| `FUN_0087b500` | residual forwarder |
| widget vtbls | `+0xf8,+0x120,+0x140,+0x158,+0x214,+0x218,+0x34c,+0x458` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| thiscall / `ret 8` / vtable install | **High** (`read_memory`) |
| Control-id bands and close path | **High** |
| Constants `~1e-4` / `255.0f` | **High** (`read_memory`) |
| HandleButton `unaff_EDI` is artifact | **High** (entry bytes) |
| Product English method name | **Probable** (`_Inferred`) |
| Toolkit msg 5/6/8/0x1a English | **Tentative** |
| Runtime 0x206E on close | Open (UF-011 residual) |
