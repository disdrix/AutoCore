# Function record: NDResource_AcquireInnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ee0` |
| **Canonical name** | `NDResource_AcquireInnerObject` |
| **Address** | `0x00745ee0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body range** | `0x00745ee0` – `0x00745f70` (~0x90 B; `int3` pad after) |
| **System** | client NDResource shell (XML / gfx / effect / anim consumers) |
| **Completion status** | **Partial** — dual A/B **accept-with-gaps** 2026-07-29; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00745ee0_NDResource_AcquireInnerObject.md` + `reviews/B_aa_00745ee0_NDResource_AcquireInnerObject.md` |

## Purpose

Pin an `NDResource` shell for consumers: bump refcount at `+0x10`, stamp float last-touch at `+0x1c` via `FUN_0076c330`, optionally nest-lock CS at `+0x20` when flag `+0x38`, Release shell via vtbl+8 if inner `+0x8` is null, return inner pointer.

## Signature

```c
// MSVC __thiscall — ECX = NDResource* shell; no stack args; plain ret
// Ghidra may show __fastcall(int *this) — same ECX ABI
void* NDResource_AcquireInnerObject(NDResource* self);
```

## Behavioral contract (sealed static)

```
if (self->lockFlag) EnterCS(&self->cs);          // +0x38 / +0x20
self->refcount += 1;                             // +0x10
self->lastTouch = NowFloat();                    // +0x1c ← FUN_0076c330 / fstp
if (self->lockFlag) EnterCS(&self->cs);          // nested (recursive CS)
inner = self->inner;                             // +0x08
if (self->lockFlag) LeaveCS(&self->cs);
if (inner == NULL) self->Release();              // vtbl +0x08
inner = self->inner;                             // re-sample
if (self->lockFlag) LeaveCS(&self->cs);
return inner;
```

## Offsets

| Offset | Type | Role |
|--------|------|------|
| `+0x00` | vtbl* | includes Release @ +0x08 |
| `+0x08` | void* | inner object (return) |
| `+0x10` | int32 | refcount |
| `+0x1c` | float | last-acquire time |
| `+0x20` | CRITICAL_SECTION | optional lock |
| `+0x38` | uint8 | lock-enabled flag |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00745ee0_NDResource_AcquireInnerObject.md`
- Annotated: `docs/reconstruction/raw/aa_00745ee0_NDResource_AcquireInnerObject.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDResource_AcquireInnerObject.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00745ee0_NDResource_AcquireInnerObject.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00745ee0_NDResource_AcquireInnerObject.md`

## Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `FUN_0076c330` (`0x0076c330`), virtual `vtbl+0x08`.

**Callers (18 UNCONDITIONAL_CALL):**  
`NDXml_LoadDocumentFromPath` (`0x007b6c70`), `FUN_007b70e0`, `FUN_007b72b0`, `FUN_007b7250`, `FUN_007b7420`, `FUN_007533e0`, `FUN_0074fd90`, `FUN_0074fe70`, `FUN_0074ee40`, `FUN_00764830`, `FUN_007641c0`, `FUN_0096a440`, `FUN_0096bcf0`, `FUN_0096c2c0`, `FUN_0096ea60`, `FUN_00981f50`, `FUN_00448f50`, plus site `0x004453de`.

**Sibling (not this unit):** `FUN_00745ea0` — shell decref under same CS/flag layout.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Offsets / nested CS / refcount / float time | **High / Sealed** |
| Canonical name role | **High** |
| Product English for timer + Release | **Open** |
| Runtime / bit-exact | **Open** |
