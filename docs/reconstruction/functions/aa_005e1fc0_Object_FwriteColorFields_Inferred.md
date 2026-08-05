# Function record: Object_FwriteColorFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1fc0` |
| **Canonical name** | `Object_FwriteColorFields_Inferred` |
| **Ghidra name** | `FUN_005e1fc0` |
| **Address** | `0x005e1fc0`–`0x005e203c` (124 B / `0x7C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object stream serialize (color extension) |
| **Wave** | W29-J OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Virtual **FILE stream serialize** extension for an object that already has a base writer at `thunk_FUN_005a61d0` / `FUN_005a61d0`:

1. Call base writer `(this, FILE*)` — id / pose / name / child-id list.
2. `fwrite(this+0x170, 4, 1, file)` — raw dword field.
3. Pack float4 at `this+0x174` → 4-byte color via `Color_PackFloat4_Scale255` (`FUN_00973820`).
4. Pack float4 at `this+0x184` → second 4-byte color.
5. `fwrite` both packed colors (4 bytes each).

Deserialize twin (not OWN): `FUN_005e2040` reads `+0x170` and unpacks two colors into `+0x174` / `+0x184` via `FUN_009733d0`.

## ABI

| Item | Value |
|---|---|
| Convention | **`__thiscall`** |
| ECX | `object* this` |
| Stack | `FILE *stream` (1 arg) |
| Epilogue | **`ret 4`** (`C2 04 00`) |
| Return | void |

## Field map (this)

| Offset | Role |
|---|---|
| `+0x170` | raw u32 written as-is |
| `+0x174` | float4 color A (src for pack) |
| `+0x184` | float4 color B (src for pack) |

Base writer (callee, not OWN) also touches `+0x134`, `+0x140` (12 B), `+0x30` (0x104 name), child ptr range `+0x14`/`+0x18`.

## Call graph

| | |
|---|---|
| Callees | `thunk_FUN_005a61d0` (`0x005e6b50` → `FUN_005a61d0`), `fwrite` (IAT `0x009c64bc`), `FUN_00973820` ×2 |
| Code callers | **none** (Ghidra) |
| Data xref | vtable slot `@ 0x009dc8e8` → `0x005e1fc0` |

## Decompiler defects (bytes supersede)

- Locals after pack are **packed u32 colors**, not `FILE*` copies of `param_2`.
- `FUN_00973820` surface omits **ECX dest** (stack float* src only); call sites set ECX to stack color slot, push `this+0x174` / `this+0x184` as src.

## Gaps

1. Product/PDB class + method name; owning class for vtable `0x009dc8e8`.
2. Semantic English for `+0x170` dword (flags vs packed color vs id).
3. Channel meaning of the two float4s (primary/secondary, etc.).
4. Runtime / bit-exact stream golden.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_FwriteColorFields_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005e1fc0.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_005e1fc0_FUN_005e1fc0.md` |
| A | `docs/reconstruction/reviews/A_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005e1fc0-008e4430-w29j-report.md` |
