# Dual A/B report — `aa_005a2a50` RPC_rpcMsgGuaranteedOrdered_Execute

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x005a2a50`. Dual A/B + artifacts. Seal Execute / CheckClassType.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ xrefs / analyze; no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a2a50` RPC_rpcMsgGuaranteedOrdered_Execute | **accept** — type-gate sealed; name scope gap only |

---

## Sealed facts

1. **Role:** TNL **RPCEvent Execute / CheckClassType** — not payload execute.  
   Returns whether `param_1` is a **`TNLConnection`** (cast from **`TNL::Object`**).

2. **Body (complete, 36 bytes @ `0x005a2a50`):**
   ```
   mov eax, [esp+4]
   push 0                      ; isRef
   push 0x00af3a48             ; TNLConnection RTTI
   push 0x00b00ba4             ; TNL::Object RTTI
   push 0                      ; VfDelta
   push eax
   call __RTDynamicCast
   add esp, 0x14
   neg eax / sbb eax,eax / neg eax   ; bool 0/1
   ret 4                             ; stdcall, 1 arg
   ```

3. **RTTI strings (`read_memory`):**
   | VA | Decorated name |
   |----|----------------|
   | `0x00af3a50` | `.?AVTNLConnection@@` |
   | `0x00b00bac` | `.?AVObject@TNL@@` |

4. **ABI:** **stdcall**, single stack pointer arg; **bool** in EAX. No `this` use.

5. **Xrefs:** **0** code callers; **exactly 6** DATA refs (Execute vtable slots):
   `0x009d7c84`, `0x009d7cb4`, `0x009d7ce4`, `0x009d7d14`, `0x009d7d44`, `0x009d7d74`  
   (stride **0x30**). Body is **reliability-agnostic**; shared across all six TNLConnection message RPC event classes.

6. **AutoCore parity (pre-existing):**  
   `src/AutoCore.Game/TNL/TNLConnection.cs` — six `RPCMsg*` nested classes each implement  
   `CheckClassType` as `(obj as TNLConnection) != null`  
   (`RPCMsgGuaranteed`, `RPCMsgGuaranteedOrdered`, `RPCMsgNonGuaranteed`, + Fragmented triplets).  
   `lib/TNL.NET/.../RPCEvent.cs`: `Process` → `if (CheckClassType(ps)) Functor.Dispatch(ps)`.

7. **Not in this unit:** reliability enum, BitStream pack/unpack, opcode routing, fragment reassembly, `HandlePacket`.

---

## Gaps

1. Per-slot labeling of the six vtables → specific `RPCMsg*` class names (needs Method1/string siblings; out of OWN VA).  
2. Ghidra symbol `…GuaranteedOrdered…` implies Ordered-only — **body shared** by all six.  
3. Runtime cast-fail path / image bit-diff not run.  
4. Exact relative displacement of `__RTDynamicCast` import not needed for contract.

---

## Dual A/B

| Review | Path | Verdict |
|--------|------|---------|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` | **accept** (name-scope gap noted) |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| Function record | `docs/reconstruction/functions/aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RPC_rpcMsgGuaranteedOrdered_Execute.cpp` |
| Raw | `docs/reconstruction/raw/aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| Annotated | `docs/reconstruction/raw/aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.annotated.md` |
| This report | `docs/agents/task-dual-ab-005a2a50-rpc-guaranteedordered-execute-report.md` |

Server mirrors (pre-existing, no change required):  
`src/AutoCore.Game/TNL/TNLConnection.cs` (`CheckClassType` ×6),  
`lib/TNL.NET/TNL.NET/Entities/RPCEvent.cs` (`Process` / `CheckClassType`).

---

## AutoCore impact

- **No port change required** for this VA: C# `CheckClassType` already matches.  
- Treat native `RPC_rpcMsgGuaranteedOrdered_Execute` as the shared type gate for **all** `rpcMsg*` NetEvents on `TNLConnection`, not as Ordered-only payload logic.  
- Reliability selection remains at send path (`Client_SendSectorPacket` / `SendGamePacket` → `RPCGuaranteedOrdered = 0`), not here.
