# Function record: WorldObj_AttachRegisterHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e760` |
| **Canonical name** | `WorldObj_AttachRegisterHost_Inferred` |
| **Ghidra name** | `FUN_0055e760` |
| **Address** | `0x0055e760`–`0x0055e850` (**240 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / phys host attach |
| **Completion status** | **Dual-sealed** (W29-T 2026-07-29) — A **accept**, B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Manager **thiscall** attach/register of a world object onto a host island:

1. Always `obj+8 = manager`.
2. Sticky `obj+0x40`: attach via existing `*(manager+0x2c)` host.
3. Manager flag `+0x23c`: allocate new 0xa8 host (tag `0x2d`), init, attach object, push host on `manager+8` list.
4. Else if no hosts yet: create first host, then attach to `list[0]`.
5. Else: attach to existing first host.

Used by enroll / reattach-guarded / rehome (mode-7 family) before `WorldObj_BindLinks_Inferred`.

## Signature

```c
// RET 4
void __thiscall WorldObj_AttachRegisterHost_Inferred(int manager, uint32_t obj);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.md` |
| Annotated | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_AttachRegisterHost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e760.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0055e760_FUN_0055e760.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_00560ec0` | enroll activate |
| Caller | `FUN_00560f30` | reattach guarded (enter mode 7) |
| Caller | `FUN_00560f70` | rehome phase 0 |
| Callee | `FUN_006291e0` | host attach (this = host) |
| Callee | `FUN_006295f0` | 0xa8 host init |
| Callee | `FUN_005b3370` | grow manager host list |
| Callee | `DAT_00b05060` | tagged alloc vtbl+0x10 |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **Confirmed** |
| Machine host this-pointer | **Confirmed** |
| Product names | Open / `_Inferred` |
