# Function record: CVOGHBBase_StampLastFireTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508270` |
| **Canonical name** | `CVOGHBBase_StampLastFireTime` |
| **Address** | `0x00508270` |
| **Body range** | `0x00508270`–`0x00508278` (9 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **Sealed** (body High; dual A/B accept 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write **`HB+0x14` (`dwLastFireTickMs`) = `g_dwClientTickMs`**. Resets the heartbeat elapsed clock to the current client tick. Manual stamp outside TryFire’s inlined success-path store; also referenced from many HB vtables.

## Signature (machine + decompiler)

```c
void __fastcall CVOGHBBase_StampLastFireTime(CVOGHBBase *this /* ECX */);
```

- Convention: MSVC `__thiscall` / `__fastcall` — **ECX = this**, no stack formals, void, bare `ret`.
- Callees: **none**.

## Body (authoritative)

```
A1 CC41B000    mov  eax, [0x00b041cc]   ; g_dwClientTickMs
89 41 14       mov  [ecx+0x14], eax     ; dwLastFireTickMs
C3             ret
```

Decompile:

```c
void __fastcall CVOGHBBase_StampLastFireTime(CVOGHBBase *this)
{
  this->dwLastFireTickMs = g_dwClientTickMs;
  return;
}
```

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x14` | `dwLastFireTickMs` | Last fire / stamp tick (ms); **written here** |

Global: `g_dwClientTickMs` @ `0x00b041cc` (uint).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00508270_CVOGHBBase_StampLastFireTime.md`
- Annotated: `docs/reconstruction/raw/aa_00508270_CVOGHBBase_StampLastFireTime.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_StampLastFireTime.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00508270_CVOGHBBase_StampLastFireTime.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00508270_CVOGHBBase_StampLastFireTime.md`

## Callers / xrefs

### Code

| Address | Kind | Owner |
|---|---|---|
| `0x0051e3a6` | tail JMP | `CVOGHBOKToCastAgain_OnStart` |
| `0x00578c96` | CALL | `FUN_00578b30` |
| `0x00578cd0` | CALL | `FUN_00578b30` |
| `0x005cc54a` | tail JMP | **undefined function** (gap pre-`FUN_005cc560`) |
| `0x005cc55b` | tail JMP | **undefined function** |

### DATA (28 vtable/method-table slots)

`0x009cda14`, `0x009cdab4`, `0x009cdfb4`, `0x009cdfd8`, `0x009d2680`, `0x009d5594`, `0x009d81bc`, `0x009d9580`, `0x009daeec`, `0x009db1ac`, `0x009db570`, `0x009dd2d4`, `0x009dd2f4`, `0x009dd440`, `0x009dde30`, `0x009de7b8`, `0x009df66c`, `0x009e316c`, `0x009e318c`, `0x009e3518`, `0x009e35b8`, `0x009e3b74`, `0x009e3c28`, `0x009e43c4`, `0x009e43e4`, `0x009e5260`, `0x009e52c8`, `0x009e52e8`

### Not a call site (semantic peer)

`CVOGHBBase_TryFire` inlines `dwLastFireTickMs = g_dwClientTickMs` after successful OnHeartBeat.

## Confidence

| Claim | Level |
|---|---|
| Control flow / body bytes | **High** (sealed) |
| `+0x14` last-fire field | **High** |
| `g_dwClientTickMs` @ `0x00b041cc` | **High** |
| Named code callers | **High** |
| Orphan `0x005cc5xx` owner name | **Open** |
| Vtbl slot indices per class | **Open** |
| Runtime / bit-exact | **Deferred** |
