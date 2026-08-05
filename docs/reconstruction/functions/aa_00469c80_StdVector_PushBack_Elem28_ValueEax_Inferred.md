# Function record: StdVector_PushBack_Elem28_ValueEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c80` |
| **Canonical name** | `StdVector_PushBack_Elem28_ValueEax_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00469c80` |
| **Address** | `0x00469c80`–`0x00469d04` exclusive (**132 B** / `0x84`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector::push_back`, POD T size **0x1c** |
| **Completion status** | **Dual sealed** W37-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **push_back** for the POD-elem28 vector family used by the 00469* cluster. Thin router:

1. If `begin != 0` and `size < capacity`: uninit-fill **one** element at `end` via `StdUninitFillN_Elem28_CountEcx` (`ECX=1`, `EAX=end`, `EBX=value*`), then `end += 0x1c`.
2. Else: `StdVector_InsertOne_RebindIt_Elem28_ValueEdx` at `where=end` (capacity growth / insert-n engine), out-iterator discarded.

## Signature

```c
// ECX=vec*, EAX=value*; bare RET (C3)
void StdVector_PushBack_Elem28_ValueEax_Inferred(
    StdVectorElem28* vec,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | **ECX** → EDI | **High** |
| value* | **EAX** → EBX | **High** |
| cleanup | bare `C3` | **High** |

## Related

| VA | Role |
|---|---|
| `0x0046a260` | fill-n engine (W36-M) — fast path |
| `0x00469e20` | insert-one rebind (W36-Q) — slow path |
| `0x00469f50` | insert-n ValueEdx (W34-Q) — under insert-one |
| `0x00460f90` | `StdVector_PushBack_RcElem28` (W36-O) — **different** register ABI + RC T |
| `0x0071a4a0` / `0x00983350` / `0x009847c0` | live callers |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem28_ValueEax_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00469c80.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00469c80-004a04f0-w37c-report.md` |

## Gaps

- Product/PDB T English.
- Caller container product names.
- Runtime / bit-exact.
