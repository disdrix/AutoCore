# Function record: Client_UI_MapView_DrawMarkersFovOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00851630` |
| **Canonical name** | `Client_UI_MapView_DrawMarkersFovOverlay` |
| **Ghidra name** | `FUN_00851630` |
| **Address** | `0x00851630` |
| **Body range** | `0x00851630`–`0x00852428` (3576 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / map-view overlay |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + phases + constants sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md`, `reviews/B_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` (2026-07-29 W23-N) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00851630`
- Scaffold / twin of `Client_UI_MapView_DrawEntitiesFovOverlay` @ `0x00859bc0`

## Purpose

Client map-view **composite overlay** draw:

1. Marker circular list (`DAT_00d1d964`) → screen project → textured or default icon rect.
2. Auto-patrol waypoints (`Client_EvalAutoPatrolWaypoint` → `FUN_008513d0`).
3. Mission tree (`DAT_00d1b938`) icons type `0x65`.
4. Optional special world point (`DAT_00d1ad1c`).
5. Squad slots 0..3 when local party flag `+0xcb0`.
6. Player FOV/range textured quad (scale **300 / viewport**) + optional radar cone (`sin(angle * 2.5)`).

Requires map config `this+0x488` and enable flag `config+0x4fc`.

## Signature

```c
void __thiscall Client_UI_MapView_DrawMarkersFovOverlay(void* self);
// ECX = self; no stack args; plain ret (C3)
```

## Algorithm

1. Gate: config*, world*, world+0xe4e8*, local*, config+0x4fc.
2. Snapshot local pose (vfunc +0x1a0).
3. Walk markers → project → draw.
4. Between major phases: bump layer counters `this+0x68/+0x70/+0x74`.
5. Patrol / mission / special / squad icon phases via `FUN_008513d0`.
6. If camera pair live: build FOV quad (+ optional cone) → `FUN_00757890`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00851630_FUN_00851630.md`
- Annotated: `docs/reconstruction/raw/aa_00851630_FUN_00851630.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawMarkersFovOverlay.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00851630.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00851630_FUN_00851630.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00851630-00859bc0-w23n-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| DATA xref | `0x00a68204` | vtable method slot |
| Callee | `0x008513d0` | icon helper |
| Callee | `0x0084f610` / `0x0084f4f0` | project |
| Callee | `0x00758460` / `0x00757890` | draw |
| Callee | `Client_EvalAutoPatrolWaypoint` | patrol |
| Callee | `0x00574760` | squad slot |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| thiscall plain ret | **High** |
| Map overlay role | **High** (icon helpers + FOV draw + marker list) |
| Enable `+0x4fc` | **High** |
| Constants 300 / 2.5 / 30 | **High** |
| Product C++ name | **Open** |
| Runtime / differential | Open |
