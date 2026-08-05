# Function record: StdVector_Tidy_Stride24_EbxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00465d70` |
| **Canonical name** | `StdVector_Tidy_Stride24_EbxThis_Inferred` |
| **Confidence** | **Inferred** |
| **Address** | `0x00465d70` |
| **Ghidra** | `FUN_00465d70` |
| **Wave** | W38-R |
| **Verdict** | **accept** |

## Sealed contract

1. **EBX = vector***; fields begin/end/cap at **+4/+8/+0xC**.
2. Null begin → zero triple + return.
3. Else destroy each **0x24** elem via `FUN_00481d80` (ESI=elem).
4. `operator_delete(begin)`; zero triple; RET.
5. Thunk JMP from `0x00465c30`.
6. Called from Palantir elem complete dtor with `EBX = elem+0x70C`.

## Reject

- Decompiler “does not return” after `operator_delete`.
- Thiscall/ECX ABI (bytes use EBX).
- Product element type names without evidence.

## Gaps

- Element product English.
- Runtime / bit-exact.
