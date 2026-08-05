# Function record: WorldObj_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560020` |
| **Canonical name** | `WorldObj_UnregisterAndRelease_Inferred` |
| **Ghidra name** | `FUN_00560020` |
| **Address** | `0x00560020`–`0x0056010c` (**237 B** / `0xED`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world / phys-link object unenroll + release |
| **Completion status** | **Dual sealed** (W29-S 2026-07-29) — A/B accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00560020`
- Prior scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_00560020` (misleading; superseded)

## Purpose

Unregister an enrolled world/link object from the manager: unbind-extract pairs, sorted-diff remove, notify, drop short refcount, clear owner dword, destroy if zero, swap-remove from `manager+0x120`. Twin of enroll `FUN_0055ff20`.

## Signature (machine)

```c
// thiscall; ECX = manager; stack = object*; void; ret 4
void __thiscall WorldObj_UnregisterAndRelease_Inferred(void* manager, void* object);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00560020_FUN_00560020.md` (+ W29-S append)
- Annotated: `docs/reconstruction/raw/aa_00560020_FUN_00560020.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/WorldObj_UnregisterAndRelease_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00560020.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00560020_WorldObj_UnregisterAndRelease_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00560020_WorldObj_UnregisterAndRelease_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (8) | `FUN_004e9720`, `FUN_004ea350`, `FUN_004c4660`, `FUN_009302b0`, `FUN_00562680`, `FUN_005db1b0`, `FUN_00609f00`, `FUN_0064ce20` |
| Callees | `0062d960`, extract vcall `+0xc`, `006cad30`, `006caaa0`, `0062a510`, vtbl0 destroy, `0055f4c0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow decompile ≡ live | **High** |
| thiscall + ret 4 | **High** |
| List swap-remove / refcount | **High** |
| unaff_* = extract out-buffer | **High** (machine) |
| Product class English | **Tentative** |
| Runtime / bit-exact | **Open** |
