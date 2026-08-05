# Annotated low-level: VehicleEntity_SetHandbrake

| Field | Value |
|---|---|
| Stable ID | `aa_004f3620` |
| VA | `0x004f3620` |
| System | input-drive-control |
| Date | 2026-07-23; residual 2026-07-29; strengthen 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_004f3620`.
- **2026-07-29 residual + strengthen:** live Ghidra re-decompile **≡ raw**. Prefer assembly only if decompiler conflicts — none observed.
- **`read_memory` body (authoritative length):**

```text
004f3620  8a 44 24 04          mov al, [esp+4]          ; handbrakeOn
004f3624  88 81 1c 06 00 00    mov [ecx+0x61c], al      ; this+0x61c
004f362a  c2 04 00             ret 4                    ; thiscall + 1 stack arg
004f362d  cc cc cc             int3 padding             ; not body
```

- Body span: **13** bytes (`0x004f3620`–`0x004f362c` inclusive). Prior “~`0x004f3626`” corrected.
- Integer widths: single `undefined1` / `uint8_t` store; consumers use ≠0 tests.
- Side-effect order: sole store; no calls.
- **No** `0xC7` suppress chain (contrast `SetSteerInput` / `SetLongitudinalInput`).
- **Bypass writers** (same byte, not this function): `MoveToTarget3DPoint` `0x004fc650` direct stores; `SetDriveAxes` `0x004fbec0` bundled store.
- **Consumers:** PushDriveAxes → `ctrl+0x24`; calcWheelTorque rear × `DAT_00a0f298` (0.5f, `00 00 00 3f`).
- **Call graph:** 10 functions / 18 unconditional call sites (see function record).

## Pseudocode (annotated copy of raw)

```c
/* WI-MOV-001: thiscall. this+0x61c = handbrake/bool. DriveControlTick sets 1 while Brake action
   held (DAT_00d1bd5e) or bounce path; clears to 0 on release. */

void __thiscall VehicleEntity_SetHandbrake(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x61c) = param_2;
  return;
}
```

## Open questions

- Runtime / differential (policy open).
- English names for non-input callers (AI/UI).
- Exhaustive direct-store inventory beyond known bypasses.
