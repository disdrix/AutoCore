# Raw capture: RPC_rpcMsgGuaranteedOrdered_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2a50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a2a50` |
| **Canonical name** | `RPC_rpcMsgGuaranteedOrdered_Execute` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool RPC_rpcMsgGuaranteedOrdered_Execute(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,&TNL::Object::RTTI_Type_Descriptor,
                          &TNLConnection::RTTI_Type_Descriptor,0);
  return iVar1 != 0;
}
```
---

## Live re-verify (2026-07-29 dual A/B) — append only

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_xrefs_to` |
| **Decompile match** | Identical body to 2026-07-23 raw |
| **Body bytes** `0x005a2a50` len 36 | `8b442404 6a00 68483aaf00 68a40bb000 6a00 50 e83c6eeeff 83c414 f7d8 1bc0 f7d8 c20400` |
| **RTTI Object** | `0x00b00ba4` → string `.?AVObject@TNL@@` @ `0x00b00bac` |
| **RTTI TNLConnection** | `0x00af3a48` → string `.?AVTNLConnection@@` @ `0x00af3a50` |
| **DATA xrefs (6)** | `009d7c84 009d7cb4 009d7ce4 009d7d14 009d7d44 009d7d74` |
| **Code xrefs** | none |
| **ABI** | stdcall `ret 4`; bool via neg/sbb/neg |
