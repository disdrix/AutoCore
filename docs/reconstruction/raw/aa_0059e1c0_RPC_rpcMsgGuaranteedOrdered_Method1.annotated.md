# Annotated low-level: RPC_rpcMsgGuaranteedOrdered_Method1

| Field | Value |
|---|---|
| Stable ID | `aa_0059e1c0` |
| VA | `0x0059e1c0` |
| System | `networking` (TNL RPC / NetClassRep) |
| Date | 2026-07-23 (scaffold); **2026-07-29 dual A/B seal** |

## Machine-level notes

- Source: raw capture for `aa_0059e1c0`.
- Prefer assembly when decompiler conflicts — here decompile ≡ asm ≡ memory.
- Body is a **getClassRep** stub: `mov eax, 0x00b04f40; ret`.
- `DAT_00b04f40` = static `TNL::NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>`.
- Product class name string @ `0x009d80cc`: `RPC_TNLConnection_rpcMsgGuaranteedOrdered`.
- Vtbl slot 0 of `PTR_RPC_rpcMsgGuaranteedOrdered_Method1_009d7c8c` (`0x009d7c8c`).
- Dual A/B: `reviews/A_aa_0059e1c0_*`, `reviews/B_aa_0059e1c0_*` → **accept**.

## Pseudocode (annotated copy of raw)

```c
/* VA 0x0059e1c0 — virtual getClassRep for RPC_TNLConnection_rpcMsgGuaranteedOrdered.
 * this (ECX) unused. Returns static NetClassRepInstance @ DAT_00b04f40. */
undefined * /* NetClassRep* */ RPC_rpcMsgGuaranteedOrdered_Method1(void)
{
  return &DAT_00b04f40; /* 0x00b04f40 — ClassRep storage, size 0x38 */
}
```

## Asm

```text
0059e1c0  B8 40 4F B0 00    mov eax, 0x00b04f40
0059e1c5  C3                ret
```

## Open questions

- Runtime-assigned net class id / group index after ClassRep registration (live process).
- Full post-construction field dump of `DAT_00b04f40` beyond ctor write map (optional).
