# Function record: CVOGHBBase_AttachOwnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083b0` |
| **Canonical name** | `CVOGHBBase_AttachOwnerObject` |
| **Address** | `0x005083b0` |
| **Body** | `0x005083b0`–`0x005083ec` (60 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-action infrastructure |
| **Completion status** | **Sealed** — dual A/B accept 2026-07-29; machine call-shape High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Set `CVOGHBBase.pOwnerObject` at `+0x18`. When prior/new owner has non-null **list manager pointer** at `owner+0xB0`, detach from prior via `FUN_005085b0` and attach to new via `FUN_00508490`. Helper **this** is the list manager, not the HB.

## Signature (machine-derived)

```c
void __thiscall CVOGHBBase_AttachOwnerObject(void* thisHb, void* pOwnerObject);
// ECX = thisHb; stack = pOwnerObject; ret 4
```

## Layout binds

| Offset | Field | Conf |
|---|---|---|
| `HB+0x18` | `pOwnerObject` | **High** |
| `Owner+0xB0` | `pListManager` (pointer to list mgr object) | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005083b0_CVOGHBBase_AttachOwnerObject.md`
- Annotated: `docs/reconstruction/raw/aa_005083b0_CVOGHBBase_AttachOwnerObject.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_AttachOwnerObject.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005083b0_CVOGHBBase_AttachOwnerObject.md`
- Review B: `docs/reconstruction/reviews/B_aa_005083b0_CVOGHBBase_AttachOwnerObject.md`

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_005085b0` @ `0x005085b0` | Remove HB from listMgr (`this=listMgr`, arg=HB) |
| Callee | `FUN_00508490` @ `0x00508490` | Insert HB into listMgr (`this=listMgr`, arg=HB) |
| Callers | ~36 sites | regen / skill / mission / weapon track / token flag HB ctors |

## Confidence

| Claim | Level |
|---|---|
| Control flow from machine | **High** |
| pOwner at +0x18; list **manager ptr** at owner+0xB0 | **High** |
| Callee this = listMgr (decompiler wrong) | **High** |
| Helper internal names / full node schema | **Probable / residual** |
