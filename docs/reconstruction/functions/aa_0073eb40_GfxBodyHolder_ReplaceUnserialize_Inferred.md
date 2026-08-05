# Function record: GfxBodyHolder_ReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073eb40` |
| **Canonical name** | `GfxBodyHolder_ReplaceUnserialize_Inferred` |
| **Confidence** | **Inferred** |
| **Address** | `0x0073eb40` |
| **Ghidra** | `FUN_0073eb40` |
| **Wave** | W38-R |
| **Verdict** | **accept-with-gaps** |

## Sealed contract

1. **thiscall** `holder` / stack `reader` / **`RET 4`**.
2. Dtor prior `holder->body` via vtbl scalar-deleting (`arg=1`).
3. `operator_new(0x14C)` + `FUN_00764030` ctor → store at `+4`.
4. Peek tag (`FUN_0076a900`, ESI=reader).
5. **SAMB** `0x424D4153` → `FUN_009615c0(body,reader)` cdecl.
6. Else → `GfxBody_UnserializeGBOD_Inferred(body,reader)` stdcall RET 8.
7. **EAX** = callee status.

## Reject

- `Named_CalleeOf_Named_*` scaffold aliases.
- Claiming product method English without PDB.
- Trusting decompiler `void` return.

## Gaps

- Inbound static callers not recovered.
- Holder/body product class names.
- Runtime / bit-exact.
