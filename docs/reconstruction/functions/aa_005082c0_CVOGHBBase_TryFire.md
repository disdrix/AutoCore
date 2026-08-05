# Function record: CVOGHBBase_TryFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_005082c0` |
| **Canonical name** | `CVOGHBBase_TryFire` |
| **Address** | `0x005082c0` |
| **Body range** | `0x005082c0`–`0x00508347` (`ret 4`); `CC` pad after |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **Sealed CF/offsets** (dual A/B 2026-07-29); OnHeartBeat return ABI residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Per-tick decision for one heartbeat action: write **EHBStatus** and optionally run virtual **OnHeartBeat** (`vtable+0x0C`), stamping **`dwLastFireTickMs` (`+0x14`)**. Invoked from **`CVOGHBList_Tick`** via **vtable+0x08** (DATA slots only; no direct CALL xrefs).

## Signature (machine + decompiler)

```c
uint* /* pOutStatus */ __thiscall CVOGHBBase_TryFire(
    CVOGHBBase* this /* ECX */,
    uint*       pOutStatus /* stack */);
// ret 4
```

- Decompiler may show `__fastcall` / `unaff_retaddr` — **ignore**; machine is thiscall + one stack out-param.

## Body contract (authoritative)

```
if cStopped(+0x20): *out = g_dwTimedActionDefaultPeriodMs (16 = Remove); return out
if nPeriodMs(+0x08) == -1000: *out = Continue(0); return out   // no OnHeartBeat
if (tick - lastFire) > nPeriodMs OR lastFire > tick:
  if fDormant(+0x21): *out = Inactive(2); return out
  status = *OnHeartBeat(vtbl+0x0C)
  dwLastFireTickMs(+0x14) = g_dwClientTickMs
  *out = status; return out
*out = Continue(0); return out
```

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x00` | `pVTable` | OnHeartBeat @ `+0x0C` |
| `+0x08` | `nPeriodMs` | pulse period ms; gate vs elapsed; `-1000` suppresses fire |
| `+0x14` | `dwLastFireTickMs` | last fire tick; stamp on fire |
| `+0x20` | `cStopped` | → Remove |
| `+0x21` | `fDormant` | → Inactive |

Not read: `+0x0C` nPeriodSentinel, `+0x10` nPeriodCounter (siblings).

## Globals

| VA | Name | Sealed value |
|---|---|---|
| `0x00b041cc` | `g_dwClientTickMs` | runtime tick (BSS 0 in image) |
| `0x00af19e8` | `g_dwTimedActionDefaultPeriodMs` | **16** (Remove / delay token) |
| `0x00af19e4` | `g_dwHBStatusInactive` | **2** |
| `0x00b041d0` | `g_dwHBStatusContinue` | **0** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005082c0_CVOGHBBase_TryFire.md`
- Annotated: `docs/reconstruction/raw/aa_005082c0_CVOGHBBase_TryFire.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_TryFire.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005082c0_CVOGHBBase_TryFire.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005082c0_CVOGHBBase_TryFire.md`

## Callers / xrefs

- **Code callers:** none (indirect via list Tick).
- **DATA:** 76 vtable slots (e.g. `0x009cdab8`, `0x009ce1cc`, …).
- **Semantic caller:** `CVOGHBList_Tick` (`0x00507950`) `call [vtable+8]`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets / constants | **High** (sealed) |
| 16 = Remove ≠ regen period | **High** |
| `+0x08==-1000` = no-fire Continue | **High** |
| OnHeartBeat pointer-return details | **Probable** |
| Runtime / bit-exact | **Deferred** |
