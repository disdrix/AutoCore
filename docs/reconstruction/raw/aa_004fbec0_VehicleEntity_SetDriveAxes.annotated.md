# Annotated low-level: VehicleEntity_SetDriveAxes

| Field | Value |
|---|---|
| Stable ID | `aa_004fbec0` |
| VA | `0x004fbec0` |
| Body span | `0x004fbec0` – `0x004fbeed` (46 bytes) |
| System | input-drive-control |
| Date | 2026-07-23 (capture); **2026-07-29 strengthen** (machine + xrefs) |

---

## Machine-level notes

- Source: raw capture for `aa_004fbec0` + live `read_memory` 2026-07-29.
- Prefer assembly when decompiler conflicts (decompiler types thr/steer as `undefined4`; machine is **`movss` f32**).
- Call at `0x004fbee6`: rel32 `e8 25 fd ff ff` → **`0x004fbc10`** `VehicleEntity_PushDriveAxesToController`.
- Stack: thr `@+4`, steer `@+8`, hb `@+0xc`; **`ret 0xc`**.
- **No** 0xC7 gate loads. Straight-line stores then push.
- Sole static xref: `VehicleAction_airStabilization` `0x0059858a` with thr=0, steer=0, **hb=1**.

### Instruction table

| VA | Bytes | Op |
|---|---|---|
| `004fbec0` | `f30f10442404` | `movss xmm0, [esp+4]` thr |
| `004fbec6` | `8a44240c` | `mov al, [esp+0xc]` hb |
| `004fbeca` | `f30f118114060000` | `movss [ecx+0x614], xmm0` |
| `004fbed2` | `f30f10442408` | `movss xmm0, [esp+8]` steer |
| `004fbed8` | `f30f118118060000` | `movss [ecx+0x618], xmm0` |
| `004fbee0` | `88811c060000` | `mov [ecx+0x61c], al` |
| `004fbee6` | `e825fdffff` | `call PushDriveAxesToController` |
| `004fbeeb` | `c20c00` | `ret 0xc` |
| `004fbeee` | `cccc` | padding |

---

## Pseudocode (annotated copy of raw)

```c
/* WI-MOV-002: thiscall SetDriveAxes(throttle@+0x614, steer@+0x618, handbrake@+0x61c) then
   PushDriveAxesToController. Ungated. Always push. */

void __thiscall
VehicleEntity_SetDriveAxes(VehicleEntity *this, float thr, float steer, uint8_t hb)
{
  *(float *)(this + 0x614) = thr;
  *(float *)(this + 0x618) = steer;
  *(uint8_t *)(this + 0x61c) = hb;
  VehicleEntity_PushDriveAxesToController(this);
  return;
}
```

---

## Open questions

- Indirect callers beyond the single static airStab site.
- Runtime differential under recovery.
- External airStab plates still say “SetDriveAxes(0)” for HB clear — site is **(0,0,1)**.
