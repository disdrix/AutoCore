# Function record: StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c310` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0055c310` |
| **Address** | `0x0055c310`–`0x0055c383` exclusive (**115 B** / `0x73`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector` insert-one + rebind, POD T stride **0x1c** |
| **Completion status** | **Dual sealed** W37-AF — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Insert **exactly one** POD Elem28 at pointer iterator `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive realloc. Thin wrapper over `StdVector_InsertN_Elem28` (`0x0055be00`, W34-R).

Primary known caller: **`FUN_0055c710`** push_back (fast path: spare cap → `FUN_0055b7a0` fill-one at end; slow path: this insert-one at `end`).

## Signature

```c
// ECX = vector*; stack outIt*, where, value*; void; RET 0x0C
void __thiscall StdVector_InsertOne_RebindIt_Elem28(
    VectorElem28* vec,
    Elem28** outIt,
    Elem28* where,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F9`) | **High** |
| outIt | stack0 | **High** |
| where | stack1 → EBX | **High** |
| value | stack2 | **High** |
| cleanup | `C2 0C 00` | **High** |
| stride | `/ 0x1c` magic `0x92492493` | **High** |
| POD path | routes to InsertN_Elem28 (no string IAT) | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0055c710` @ `0x0055c78d` only (direct) |
| Callees | `StdVector_InsertN_Elem28` (`0x0055be00`, W34-R) |

## Related

| VA | Role |
|---|---|
| `0x0055be00` | `StdVector_InsertN_Elem28` (W34-R) |
| `0x0055c250` | resize sibling (other agent exclusive) |
| `0x0055c710` | push_back parent (unowned) |
| `0x0040dbf0` | dword thiscall insert-one twin (stride 4) |
| `0x004612d0` | RC Elem28 insert-one (EDI=vec) |
| `0x00469e20` | Elem28 insert-one ValueEdx/EDI ABI twin |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ W37-AF append) | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.md` |
| Annotated | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0055c310.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0055c310_FUN_0055c310.md` |
| Dual report | `docs/agents/task-dual-ab-0055c310-w37af-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Insert-one + rebind CF | **High** |
| ABI thiscall + RET 0x0C | **High** |
| Stride 0x1c + magic | **High** |
| Sole callee InsertN_Elem28 | **High** |
| Product type of Elem28 | **Low** (domain open) |
| Parent push_back plate | **Med** (decompile only) |
