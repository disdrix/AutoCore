# Function record: Phys_ActionBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636370` |
| **Canonical name** | `Phys_ActionBase_ctor` |
| **Ghidra name** | `FUN_00636370` |
| **Address** | `0x00636370` |
| **Body range** | `0x00636370`–`0x006363b2` (`ret 4` at end; ~67 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / Havok-like action base |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + host-link sealed; product name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00636370_Phys_ActionBase_ctor.md`, `reviews/B_aa_00636370_Phys_ActionBase_ctor.md` |
| **Last reviewed** | `2026-07-29` (W17-P) |

## Alias

- `FUN_00636370` (Ghidra)
- `Named_CalleeOf_…_CVO_00636370` (auto parent-seed — **misleading**)
- Physics plates: “base / hkAction-like ctor”

## Purpose

Base constructor for dual-vtable action-like objects:

1. Seed refcount `this+6 = 1`
2. Install base primary + secondary vtables (MI intermediate then final secondary)
3. Clear `+0xc` and `+0x14`
4. Store optional host at `+0x18`; if set, push `this` onto host's action vector and addref host

Derived ctors (`VehicleAction_ctor`, flipper, `FUN_00658bf0`) call this then stamp class-specific vtables/fields.

## Signature

```c
void * __thiscall Phys_ActionBase_ctor(void *self, void *host);
// ECX=self; stack host; ret 4; returns self
```

## Layout (this unit)

| Offset | Field | Init |
|---|---|---|
| +0x00 | primary vtbl | `PTR_FUN_009e39f4` |
| +0x06 | refcount u16 | `1` |
| +0x08 | secondary vtbl | final `PTR_LAB_009e5e78` |
| +0x0c | u32 | `0` |
| +0x14 | u32 | `0` |
| +0x18 | host ptr | ctor arg |

## Algorithm

1. `*(u16*)(this+6) = 1`
2. Intermediate secondary @ `+8` = `0x009e3a68`
3. `*(u32*)(this+0xc) = 0`; `*(u32*)(this+0x14) = 0`
4. `*this = 0x009e39f4`; `*(this+8) = 0x009e5e78`
5. `*(this+0x18) = host`
6. If host: `FUN_00507290(host, this)` then `*(u16*)(host+6)++`
7. Return this

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00636370_FUN_00636370.md`
- Annotated: `docs/reconstruction/raw/aa_00636370_FUN_00636370.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Phys_ActionBase_ctor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00636370.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00636370-phys-actionbase-ctor-report.md`

## Callers / callees

| Direction | Target |
|---|---|
| **Callees** | `FUN_00507290` (host vector append) — only when host ≠ 0 |
| **Callers** | `VehicleAction_ctor` `0x00597f90`; `FUN_00600140`; `FUN_00658bf0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Refcount @ +6 = 1 | **High** |
| Dual base vtables | **High** |
| Host @ +0x18 + addref | **High** |
| FUN_00507290 ABI (ECX=host) | **High** (bytes; decomp incomplete) |
| Product name hkAction | **Inferred** / Probable |
| Host concrete type per caller | Open / peer duals |

## Related

- `aa_00597f90` VehicleAction_ctor
- `aa_00600140` Phys_FlipperConstraint_ctor
- `FUN_00636290` base dtor chain (sibling, not owned)
- Physics verified: `fn_00597e90_vehicleActionCtor.md`
