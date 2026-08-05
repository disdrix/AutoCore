# Function record: TNL_NetClassRepInstance_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2410` |
| **Canonical name** | `TNL_NetClassRepInstance_Ctor` |
| **Ghidra name** | `FUN_005a2410` |
| **Address** | `0x005a2410` |
| **Body span** | `005a2410`–`005a2466` (87 B through `ret 0x10`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `tnl` / NetClassRep |
| **Completion status** | **Dual A/B sealed** (W21-K 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `FUN_005a2410`
- Prior: partial scaffold only (2026-07-23)

## Purpose

In-place constructor for a TNL **NetClassRepInstance**-style ClassRep:

1. Base ClassRep init (`FUN_0042aea0`).
2. Install NetClassRepInstance vtbl `PTR_FUN_009d7bf4`.
3. `_strdup` class name → `+0x20`.
4. Store group mask (`+0x04`), type (`+0x0C`), version (`+0x08`).
5. Zero `classId[4]` at `+0x10..+0x1C`.
6. Prepend to global ClassList head `DAT_00d179a4` via link at `+0x34`.

Aligns with in-repo `TNL.NET` `NetClassRepInstance(string, uint groupMask, NetClassType, int classVersion)` + `ClassList.Add(this)`.

Object span **0x38** (sibling dual on GuaranteedOrdered RPC ClassRep @ `DAT_00b04f40`).

## Signature

```c
NetClassRepInstance* __thiscall TNL_NetClassRepInstance_Ctor(
    NetClassRepInstance* self,
    char* className,
    uint32_t classGroupMask,
    uint32_t classType,
    uint32_t classVersion);
// ret 0x10
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a2410_FUN_005a2410.md`
- Annotated: `docs/reconstruction/raw/aa_005a2410_FUN_005a2410.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TNL_NetClassRepInstance_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_005a2410.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005a2410_TNL_NetClassRepInstance_Ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_005a2410_TNL_NetClassRepInstance_Ctor.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_005a2410_FUN_005a2410.md` (superseded by this)

## Callers / callees

**Callees:** `FUN_0042aea0` (base ClassRep), `_strdup` (IAT `0x009c6474`).

**Callers:** CRT static init @ `0x009c0ec0` (constructs GuaranteedOrdered RPC ClassRep at `DAT_00b04f40`). Sibling dtor `FUN_005a2470` registered via atexit.

**Globals:** vtbl `0x009d7bf4`, ClassList head `DAT_00d179a4`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / field stores / list splice | **Confirmed** (bytes + decompile) |
| `__thiscall` `ret 0x10`, 4 stack args | **Confirmed** |
| Role = NetClassRepInstance ctor | **High** (RTTI + CRT name + TNL.NET ctor shape) |
| Product template parameter identity (which `T`) | **Per-instance** (caller supplies storage + name) |
| Full base ClassRep layout beyond written slots | **Probable** (base init owned elsewhere) |

## Dual verdict

**accept**
