# Raw capture: RPC_rpcMsgGuaranteedOrdered_Method1

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059e1c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0059e1c0` |
| **Canonical name** | `RPC_rpcMsgGuaranteedOrdered_Method1` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined * RPC_rpcMsgGuaranteedOrdered_Method1(void)



{

  return &DAT_00b04f40;

}
```

---

## Re-verify append (2026-07-29) — dual A/B seal

**Integrity:** Original raw body block left as capture; this section is append-only re-verify.

| Check | Result |
|---|---|
| Live `decompile_function` `0x0059e1c0` | **≡** raw body (`return &DAT_00b04f40`) |
| Live `read_memory` body | `b8 40 4f b0 00 c3` + `cc` pad |
| Live `analyze_function_complete` | stub; 1 DATA xref @ `0x009d7c8c`; 0 callers/callees |
| ClassRep region | `analyze_data_region` `00b04f40`–`00b04f77` (0x38) |
| CRT init | `0x009c0eb0`: `FUN_005a2410(ecx=&DAT_00b04f40, name=0x009d80cc, 1, 2, 0)` |
| Name string | `RPC_TNLConnection_rpcMsgGuaranteedOrdered` @ `0x009d80cc` |
| RTTI | `NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>` |
| Dual A/B | **accept** — getClassRep stub; runtime open |

**Product role:** virtual ClassRep getter (Ghidra `Method1`). Dual A/B → **accept**.
