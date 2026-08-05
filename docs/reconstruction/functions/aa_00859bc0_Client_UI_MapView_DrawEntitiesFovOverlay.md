# Function record: Client_UI_MapView_DrawEntitiesFovOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00859bc0` |
| **Canonical name** | `Client_UI_MapView_DrawEntitiesFovOverlay` |
| **Ghidra name** | `FUN_00859bc0` |
| **Address** | `0x00859bc0` |
| **Body range** | `0x00859bc0`–`0x0085a9ef` (3631 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / map-view overlay |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + phases + constants sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md`, `reviews/B_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` (2026-07-29 W23-N) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00859bc0`
- Scaffold / twin of `Client_UI_MapView_DrawMarkersFovOverlay` @ `0x00851630`

## Purpose

Client map-view **entity-rich composite overlay** draw:

1. World entity vector A (host+`0x28`) with filter + lazy path → `FUN_00859260`.
2. World entity vector B (host+`0x48`) with owner/faction filters + ally tint → `FUN_00859260`.
3. Marker list (`DAT_00d1d964`) type textures `config+0x624+type*4`.
4. Auto-patrol / mission tree (`0x65`) / special (`100`) / squad (`1`) via `FUN_00859a90`.
5. Player FOV textured quad: radius from `config+0x514` with optional scale and final `* 0.5`.

## Signature

```c
void __thiscall Client_UI_MapView_DrawEntitiesFovOverlay(void* self);
// ECX = self; no stack args; plain ret (C3)
```

## Algorithm

1. Gate: config*, local*, world*, world+0xe4e8*, list heads A/B.
2. Snapshot local pose (vfunc +0x1a0).
3. Walk world list A → filtered entity icons.
4. Bump layer; walk world list B → filtered entity icons (+ally tint).
5. Markers → patrol → mission → special → squad (each with layer bumps).
6. If camera pair live: FOV quad → `FUN_00757890`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.md`
- Annotated: `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawEntitiesFovOverlay.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00859bc0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00859bc0_FUN_00859bc0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00851630-00859bc0-w23n-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| DATA xref | `0x00a65a54` | vtable method slot |
| Callee | `0x00859260` | entity/marker draw |
| Callee | `0x00859a90` | icon-type dispatch |
| Callee | `0x00757890` | FOV draw |
| Callee | `0x005134e0` | filter |
| Callee | `Client_EvalAutoPatrolWaypoint` | patrol |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| thiscall plain ret | **High** |
| Entity-rich map overlay role | **High** |
| World list A/B structure | **High** |
| FOV scale chain + 0.5 | **High** |
| Product C++ name | **Open** |
| List A/B semantic labels | **Medium** (structure sealed, English open) |
| Runtime / differential | Open |
