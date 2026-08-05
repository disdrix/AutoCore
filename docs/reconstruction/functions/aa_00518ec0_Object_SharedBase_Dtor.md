# Function record (named): Object_SharedBase_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ec0` |
| **Semantic name** | `Object_SharedBase_Dtor` |
| **Ghidra name** | `FUN_00518ec0` |
| **Address** | `0x00518ec0`–`0x005190b1` exclusive (**497 B** / `0x1F1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / dual-base shared fields |
| **Naming basis** | Field-dtor twin of sealed `Object_SharedBase_Ctor` (`aa_00518940`); product log string confirms object destructor |
| **Status** | Dual sealed W29-G (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **shared dual-base / virtual-base field destructor** for the client object core. Tears down CO-list membership safety, interface@`+0x14`, double-list registration, CS helper@`+0xb0`, owned FX lists (`FUN_005179e0`), typed owned pointers, and residual buffer triples.

## Signature

```c
// __thiscall/__fastcall; ECX=this; void; bare RET
void __fastcall Object_SharedBase_Dtor(void *self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.md`
- Annotated: `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SharedBase_Dtor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00518ec0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00518ec0_FUN_00518ec0.md`
- Reviews: `A_aa_00518ec0_Object_SharedBase_Dtor.md`, `B_aa_00518ec0_Object_SharedBase_Dtor.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00575350` Object_009d33c4_CompleteDtor | tail-jmp (W28-M) |
| Caller | many complete dtors / Unwind@* | 53 xrefs total |
| Callee | `Object_TeardownOwnedFxLists_Inferred` `0x005179e0` | W28-H |
| Twin | `Object_SharedBase_Ctor` `0x00518940` | W22-B |

## Confidence

| Claim | Level |
|---|---|
| Shared-base field dtor role | **High** |
| ABI + bare RET + body size | **High** |
| Not scalar-deleting | **High** |
| Product C++ class English | **Open** |
