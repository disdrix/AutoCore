# Annotated low-level: RPC_rpcMsgGuaranteedOrdered_Execute

| Field | Value |
|---|---|
| Stable ID | `aa_005a2a50` |
| VA | `0x005a2a50` |
| System | network-tnl-rpc |
| Date | 2026-07-29 (dual A/B seal) |

## Machine-level notes

- Source: raw capture for `aa_005a2a50` + live `decompile_function` / `read_memory` 2026-07-29.
- Full body is 36 bytes; ends `ret 4` (stdcall).
- RTTI targets verified by string bytes at TypeDescriptor+8.
- Six DATA xrefs are NetEvent vtable Execute slots (stride 0x30) — not code CALL sites.
- Ghidra name includes `GuaranteedOrdered`; body is reliability-agnostic type gate shared by all six TNLConnection rpcMsg* event classes.

## Pseudocode (annotated)

```c
/* TNL RPCEvent::Execute / CheckClassType equivalent.
 * param_1: EventConnection / Object* under test (TNL::Object*).
 * return: true if dynamic_cast to TNLConnection succeeds.
 */
bool __stdcall RPC_rpcMsgGuaranteedOrdered_Execute(void *param_1 /* TNL::Object* */)
{
  /* __RTDynamicCast(inObj, VfDelta=0, SrcRTTI=TNL::Object, TargetRTTI=TNLConnection, isRef=0) */
  void *casted = __RTDynamicCast(
      param_1,
      0,
      &TNL::Object::RTTI_Type_Descriptor,      /* 0x00b00ba4 */
      &TNLConnection::RTTI_Type_Descriptor,    /* 0x00af3a48 */
      0);
  return casted != 0;  /* MSVC: neg / sbb / neg → EAX 0 or 1 */
}
```

## Body bytes

```
005a2a50  8b 44 24 04          mov  eax, [esp+4]
005a2a54  6a 00                push 0
005a2a56  68 48 3a af 00       push offset TNLConnection_RTTI   ; 0x00af3a48
005a2a5b  68 a4 0b b0 00       push offset TNL_Object_RTTI      ; 0x00b00ba4
005a2a60  6a 00                push 0
005a2a62  50                   push eax
005a2a63  e8 .. .. .. ..       call __RTDynamicCast
005a2a68  83 c4 14             add  esp, 14h
005a2a6b  f7 d8                neg  eax
005a2a6d  1b c0                sbb  eax, eax
005a2a6f  f7 d8                neg  eax
005a2a71  c2 04 00             ret  4
```

(Disassembly reconstructed from `read_memory` only — not `disassemble_bytes`.)

## Open questions

- Map each of the six vtable bases to Guaranteed / Ordered / NonGuaranteed ± Fragmented (sibling Method1 / string units).
- Runtime failure observability (owned by TNL Process, not this VA).
