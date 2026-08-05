# Function record (named): Class_009c7a1c_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00496f70` |
| **Semantic name** | `Class_009c7a1c_Ctor` |
| **Ghidra name** | `FUN_00496f70` |
| **Address** | `0x00496f70`–`0x004970a8` exclusive (**312 B** / `0x138`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | class / complete-object constructor |
| **Naming basis** | Ctor body for primary vtbl `PTR_FUN_009c7a1c`; product demangle open — vtbl suffix matches W28-M complete dtor |
| **Status** | Dual sealed W29-G (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **complete-object constructor** for class family `PTR_FUN_009c7a1c`. Installs vtbl, seeds `+4/+8=0x40`, allocates StdList sentinel via `FUN_00457c60` into list object at `+0x0C` (head@`+0x10`, size@`+0x14`), zeros six buffer triples + cookie-vector ptr, sets flags/floats (300.f/25.f), copies one byte from parent context `+0x7d`. Returns `this`.

## Signature

```c
// __thiscall; ECX=this; stack: context*; returns this; ret 4
void *__thiscall Class_009c7a1c_Ctor(void *self, void *ctx);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.md`
- Annotated: `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_009c7a1c_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00496f70.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00496f70_FUN_00496f70.md`
- Reviews: `A_aa_00496f70_Class_009c7a1c_Ctor.md`, `B_aa_00496f70_Class_009c7a1c_Ctor.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_004cda90` | sole; `operator_new(0xC8)` then ctor(parent); store @ `parent+0xE898` |
| Callee | `FUN_00457c60` | list sentinel factory (`operator_new(0x18)`, self-link) |
| Twin | `Class_009c7a1c_CompleteDtor` `0x004970b0` | W28-M |
| Related | `FUN_004975e0` | scalar deleting (vtbl[0]) |

## Confidence

| Claim | Level |
|---|---|
| ABI + ret 4 + return this | **High** |
| Role = complete ctor for PTR_FUN_009c7a1c | **High** |
| Object size 0xC8 from factory | **High** |
| Product English name | **Open** |
