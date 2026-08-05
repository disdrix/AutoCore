# Function record: Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3f60` |
| **Canonical name** | `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20` (Inferred) |
| **Ghidra name** | `FUN_005b3f60` |
| **Address** | `0x005b3f60` |
| **Body range** | `0x005b3f60`–`0x005b3f9a` exclusive (**58** B / `0x3A`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host object / MSVC default ctor |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI + callers sealed; product class open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md`, `reviews/B_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` (2026-07-29 W30-O) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b3f60`
- Role: MSVC **default constructor** — install vtbl `PTR_FUN_009d95b4`, empty list at `this+0x10`, zero four floats at `+0x20`

## Purpose

Default-construct a **0x30**-byte host object: set construction/final vtbl, allocate self-linked list sentinel into embedded list shell at `+0x10`, clear size, zero float quartet at `+0x20..+0x2c`. Returns `this`.

## Signature

```c
void * __fastcall Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(void *self);
// ECX = this; returns this in EAX; bare RET
```

## Algorithm

1. `*self = PTR_FUN_009d95b4`.
2. `list = self + 0x10`; buy sentinel via `FUN_005b43b0`; `list+4 = sentinel`; `list+8 = 0`.
3. Zero `float` at `self+0x20`, `+0x24`, `+0x28`, `+0x2c` (`xorps`/`movss`).
4. Return `self`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.md`
- Annotated: `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005b3f60.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005b3f60-005b4260-w30o-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005b43b0` (sentinel buy `operator_new(0x30)` self-link) |
| **Callers** | `FUN_004cd8f0` @ `0x004cd93f`; `FUN_004cd9a0` @ `0x004cd9f8` — both `new(0x30)` then this, store at host `+0xe4fc` |

## Confidence

| Claim | Level |
|---|---|
| Bytes: vtbl + list@+0x10 + F4 zero | **High** |
| Object size 0x30 from callers | **High** |
| ABI ECX this / EAX return | **High** |
| Product class English | **Open** |
| Fields +0x04..+0x0C / +0x1C | **Open** (unwritten here) |
| Runtime / differential | Open |

## Related

- Body dtor: `aa_005b3b20` `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` (W28-N)
- Scalar dtor shell: `FUN_005b44d0` (vtbl[0])
- Param ctor twin: `aa_005b4260` `Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate`
- Populate: `FUN_005b3fa0` (not owned this wave)
