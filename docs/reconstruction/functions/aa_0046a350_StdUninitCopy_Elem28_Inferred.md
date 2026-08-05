# Function record: StdUninitCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a350` |
| **Canonical name** | `StdUninitCopy_Elem28_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_0046a350` |
| **Address** | `0x0046a350`–`0x0046a372` exclusive (**34 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC-style trivial `uninitialized_copy`, T POD **0x1c** |
| **Calling convention** | **EAX=dst**; **EDX=src_begin**; **EBX=src_end**; bare **`ret`**; **EAX=dst_end** out |
| **Completion status** | **Dual sealed** W36-P — **accept** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A** | `reviews/A_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| **Dual B** | `reviews/B_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W36-P) |

## Purpose

Forward range copy for 28-byte POD elements under the ValueEdx InsertN chain (`FUN_00469f50`). Closes the unowned `FUN_0046a350` residual listed by W34-Q.

## Signature

```c
// EAX=dst, EDX=src_begin, EBX=src_end; bare RET; EAX=dst_end
Elem28* StdUninitCopy_Elem28_Inferred(
    Elem28* dst,
    const Elem28* src_begin,
    const Elem28* src_end);
```

## Behavioral summary

| Stage | Effect |
|---|---|
| Empty | `src_begin == src_end` → return dst unchanged |
| Store | if dst non-null, copy 7 dwords via `REP MOVSD` |
| Advance | always `src += 0x1c`, `dst += 0x1c` |
| Return | EAX = dst after last element |

## Related

| VA | Role |
|---|---|
| `0x00469f50` | sole parent InsertN ValueEdx (W34-Q) |
| `0x0046a260` | sibling fill-n next symbol (unowned here) |
| `0x0046a240` | `StdCopyBackward_Elem28_Inferred` (W35-L) |
| `0x004673b0` | `StdVector_UninitializedCopy_Elem28_Inferred` — stack-last ABI peer (W35-T) |
| `0x0045f360` | `StdUninitCopy_Pod28` — Pod28 family peer (W35-K) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_Elem28_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a350.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_0046a350_StdUninitCopy_Elem28_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00466df0-0046a350-w36p-report.md` |
