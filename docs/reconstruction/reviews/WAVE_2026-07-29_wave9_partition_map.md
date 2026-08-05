# Multi-agent partition map — wave 9 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **745** unique A |
| Rule | **One write owner per VA** |

## Physics / pose helpers (DriveControlTick chain)

| VA | Focus |
|----|-------|
| `0x005070b0` | Physics ready probe |
| `0x005070d0` | Physics prepare |
| `0x004cb3e0` | Local pos float4 store leaf |
| `0x005a58c0` | Heightfield sample Y |
| `0x00404a20` | World quat/orientation twin of pos ptr |
| `0x0040d0a0` | Physics vector helper |
| `0x00404dc0` | Physics/object helper |
| `0x004e8a40` | PushDriveAxes related |
| `0x004e8ad0` | related |
| `0x004e8bf0` | related |
| `0x0053d970` | Vehicle type-6 cleanup |
| `0x004c4e20` | Base speed getter |

## Skills / targeting / HB

| VA | Focus |
|----|-------|
| `0x00512090` | Targeting link HB self |
| `0x00604d40` | Targeting link HB target |
| `0x007fb640` | Progress bar dismiss |
| `0x0040ce50` | Mod chip lookup |
| `0x00564700` | SpawnPoint SetObjectActiveState |
| `0x00567ce0` | related active state |

## UI / inventory / string helpers

| VA | Focus |
|----|-------|
| `0x008f6800` | Chat log file write |
| `0x0085fcc0` | Inventory sheet remove helper |
| `0x008605b0` | Inventory sheet add helper |
| `0x007a69d0` | string helper |
| `0x007a6de0` | string helper |
| `0x004962b0` | Equip gfx refresh callee |
| `0x0075b7f0` | gfxView near extents |
| `0x00972fa0` | world transform helper |
| `0x00513770` | Drop/item helper |
| `0x007fdfb0` | Drop UI helper |
| `0x0085f1d0` | Drop path |
| `0x0085f220` | Drop path |

## Missions / profiler / map

| VA | Focus |
|----|-------|
| `0x004111f0` | GiveMission path |
| `0x0040c5c0` | GiveMission path |
| `0x00538b20` | mission map helper |
| `0x0053c360` | mission map |
| `0x0053c660` | mission map |
| `0x00547920` | mission helper |
| `0x007866e0` | Profiler thread slot |
| `0x00786470` | Profiler find/create zone |
| `0x00785e00` | Profiler start timer |
| `0x00780690` | QPC accumulate |

## Meta

| Role | Focus |
|------|-------|
| Parent | restamp after land |
| Honesty | Terminal false; dual 745≪25666 |

## Honesty

Terminal **false**. Dual 745 / 25666. Stamp ≠ dual depth.
