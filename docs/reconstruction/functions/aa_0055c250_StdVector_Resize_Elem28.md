# Function record: StdVector_Resize_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c250` |
| **Canonical name** | `StdVector_Resize_Elem28` |
| **Ghidra name** | `FUN_0055c250` |
| **Address** | `0x0055c250`–`0x0055c306` exclusive (**182 B** / `0xB6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector` resize, POD elem stride **0x1c** |
| **Completion status** | **Dual-reviewed** (W37-AA) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Terminal coverage** | false |

## Alias

- Ghidra: `FUN_0055c250`
- **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055c250`
- Family peer: `StdVector_InsertN_Elem28` (`0x0055be00`, W34-R); ABI peer (different regs): `StdVector_Resize_Pod28` (`0x0045c4b0`, W35-M, RET 0x1C / EBX+ECX)

## Purpose

`vector<Elem28>::resize(new_size, value)`: if growing, insert `(new_size - size)` copies of `value` at `end` via InsertN; if shrinking, publish `end = begin + new_size * 0x1c` (empty POD move via `FUN_0055b470` returning dest).

## Signature (sealed)

```c
// __thiscall; RET 0x20 (new_size + 0x1c value blob)
void __thiscall StdVector_Resize_Elem28(
    VectorElem28* vec,   /* ECX */
    uint32_t new_size,   /* stack */
    Elem28 value);       /* stack by value */
```

## Artifacts

- Raw (+ W37-AA append): `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.md`
- Annotated: `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0055c250.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0055c250_FUN_0055c250.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0055c250_StdVector_Resize_Elem28.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0055c250_StdVector_Resize_Elem28.md`

## Callers / callees

| Dir | Symbol | Role |
|---|---|---|
| Caller | `FUN_0055a5f0` @ `0x0055a684` | clone/copy: resize dest vector to source size |
| Callee | `FUN_0055be00` / `StdVector_InsertN_Elem28` | grow path (W34-R) |
| Callee | `FUN_0055b470` | shrink path POD range helper (unowned) |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + RET 0x20 + value by value 0x1c | **High** (bytes) |
| Stride 0x1c / size magic | **High** |
| Grow → InsertN at end | **High** |
| Shrink → end = begin + n*0x1c via helper return | **High** |
| Product Elem28 English | **Low** / open |
| Runtime / bit-exact | **Open** |
