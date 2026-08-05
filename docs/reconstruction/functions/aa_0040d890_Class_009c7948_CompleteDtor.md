# Function record: Class_009c7948_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d890` |
| **Canonical name** | `Class_009c7948_CompleteDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d890` |
| **Address** | `0x0040d890` |
| **Body** | `0x0040d890`–`0x0040d8ca` (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC derived complete dtor — `PTR_FUN_009c7948` |
| **Completion status** | **Dual-reviewed** W32-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Derived complete destructor: install `PTR_FUN_009c7948`, then chain base `StdTreeHost_PtrVal_CompleteDtor` (`0x0040d820`) which installs base vtbl, clears the tree, and tears down `this+4`. Does **not** free `this`.

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall Class_009c7948_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0040d870` @ `0x0040d873` (scalar-deleting for this vtbl) |
| Callees | `StdTreeHost_PtrVal_CompleteDtor` / `FUN_0040d820` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.md`
- Annotated: `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_009c7948_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d890.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d890_Class_009c7948_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d890_Class_009c7948_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d890_FUN_0040d890.md`
- Base complete: `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor (W31-A)
- Base scalar: `aa_0040d590` Class_009c7938_ScalarDeletingDtor (W31-E)

## Confidence

| Claim | Level |
|---|---|
| Derived vtbl install + base complete chain | **High** |
| ABI SEH + ADD ESP,0x10; RET | **High** |
| Complete vs scalar | **High** (scalar is `0040d870`) |
| Product class English | **Low** |
| Vtbl slots [1]/[2] | **Open** |
