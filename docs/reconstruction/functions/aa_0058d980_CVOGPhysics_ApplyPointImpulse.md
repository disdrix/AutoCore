# Function record: CVOGPhysics_ApplyPointImpulse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d980` |
| **Canonical name** | `CVOGPhysics_ApplyPointImpulse` (inferred) |
| **Ghidra / prior** | `FUN_0058d980` / `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0058d980` |
| **Address** | `0x0058d980` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` / `CVOGPhysics` |
| **Body size** | `0x37` bytes (instruction-sealed through `ret 8`) |
| **Completion status** | **Dual reviewed** — accept-with-gaps (2026-07-29, W16-B) |
| **Bit-for-bit / runtime / diff** | Static CF High; runtime open |

## Purpose

Optional readiness prepare on a `CVOGPhysics` object, then call bound rigid-body **vtable +0x60** with **two** caller-supplied pointers — **apply point impulse** (impulse vector + point/contact object). Sibling of one-arg body write helpers (`ApplyImpulseVector` +0x50, `SetAngularVelocity` +0x54, `ApplyVector_Vtbl5c` +0x5c) with the same `ProbeReadyFlag` / `PrepareReady` gate.

## Signature (decompiler + asm)

```c
void __thiscall CVOGPhysics_ApplyPointImpulse(
    void *phys /* ECX */,
    void *impulseVec /* stack */,
    void *pointObj /* stack */);
// ret 8
```

## Control flow

1. `FUN_005070b0(phys, &outByte)` — if `phys+0x44==0` → out=0; else out=`*(*(phys+0x44)+0x29)`.
2. If `out==0` **and** `*(phys+0x44)!=0` → `FUN_005070d0(phys)`.
3. `body = *(phys+0x3c)`; `(*body->vtbl)[+0x60](impulseVec, pointObj)`.
4. Return. No null check on body.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0058d980_FUN_0058d980.md`
- Annotated: `docs/reconstruction/raw/aa_0058d980_FUN_0058d980.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysics_ApplyPointImpulse.cpp`
- Ghidra twin: `docs/reconstruction/reconstructed-exact/FUN_0058d980.cpp`
- Prior scaffold alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0058d980.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md`
- Review B: `docs/reconstruction/reviews/B_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_0058d980_FUN_0058d980.md`

## Callers / callees

**Callees:** `FUN_005070b0`, `FUN_005070d0`, indirect body vtbl+0x60.

**Callers:** OWN-ONLY pass did not run xref tools. Scaffold seed: nested callee of VOG_DEBUG path. Prior art: postTick / suspension paths also invoke body vtbl+0x60 **inline** (not necessarily via this wrapper).

## Confidence

| Claim | Level |
|---|---|
| Control flow / vtbl imm 0x60 / ret 8 | **High** |
| Sibling parity (ready gate) | **High** |
| applyPointImpulse English (prior art) | **High** (usage docs) / product string **Open** |
| Arg layouts (f3/f4 impulse; point type) | **Probable** / **Open** |
| Runtime / bit-exact image | Open |

## Prior art

- `physics/0.4-suspension.md` — chassis RB `applyPointImpulse` at vtbl `+0x60`
- Sibling duals: `A/B_aa_0040d040_*`, `A/B_aa_0040d260_*`, `A/B_aa_00404cb0_*`
- Ready helpers: `A/B_aa_005070b0_*`, `A/B_aa_005070d0_*`
