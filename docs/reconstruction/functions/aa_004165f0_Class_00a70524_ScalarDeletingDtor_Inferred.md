# Function record: Class_00a70524_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004165f0` |
| **Canonical name** | `Class_00a70524_ScalarDeletingDtor_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004165f0` |
| **Address** | `0x004165f0` |
| **Body** | `0x004165f0`–`0x0041660E` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9I-J — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a70524`. Always runs the complete dtor (`FUN_008327f0` — install `00a70524`, chain base `FUN_0082d540`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX. Peer ctor `FUN_00832830` (not owned) installs the same vtbl and loads `"i_m_chatlog.xml"`.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall Class_00a70524_ScalarDeletingDtor_Inferred(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a70524[0]` @ `0x00a70524` |
| Callees | `FUN_008327f0` (complete), `operator_delete` |

## Artifacts

- Raw (+ WQ9I-J append): `docs/reconstruction/raw/aa_004165f0_FUN_004165f0.md`
- Annotated: `docs/reconstruction/raw/aa_004165f0_FUN_004165f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a70524_ScalarDeletingDtor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004165f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004165f0_FUN_004165f0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Complete callee identity | **High** (live decompile of `008327f0`) |
| Product MSVC demangle / chatlog English class name | **Low** / inferred from peer ctor string |
| Vtbl slots [1+] | **Open** |
