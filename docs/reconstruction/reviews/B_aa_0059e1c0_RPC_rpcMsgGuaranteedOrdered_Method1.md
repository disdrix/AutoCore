# Review B (skeptical / adversarial): `aa_0059e1c0` RPC_rpcMsgGuaranteedOrdered_Method1

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059e1c0` |
| **VA** | `0x0059e1c0` |
| **Review type** | Skeptical / adversarial dual residual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| **System** | `networking` / TNL RPC event class-rep |
| **Verdict** | **accept** (runtime open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Non-trivial logic / bitstream / opcode work | Body is 2 ops: `mov eax, imm` + `ret` | **Falsified** — pure pointer return |
| 2 | Returns a heap object / per-instance state | Immediate is fixed BSS `0x00b04f40` | **Falsified** — **static** ClassRep |
| 3 | Immediate is a string / vtbl / code ptr | CRT init constructs ClassRep **in place** at that address; RTTI names NetClassRepInstance | **Falsified** — ClassRep storage |
| 4 | Wrong RPC variant (Guaranteed vs Ordered vs Fragmented) | Name string @ `0x009d80cc` = `…rpcMsgGuaranteedOrdered`; RTTI matches | **Falsified** — **Ordered** only |
| 5 | Free function never virtual | Sole xref is DATA into event vtbl slot 0 | **Falsified** — **virtual** accessor |
| 6 | Uses / requires meaningful `this` | No ECX memory ops | **Falsified** — this ignored (still thiscall at call sites) |
| 7 | Stack arguments / stdcall cleanup | Bare `c3` | **Falsified** — zero formals |
| 8 | This unit implements Execute / CheckClassType | Execute is `0x005a2a50` elsewhere on same vtbl | **Falsified** — Method1 ≠ Execute |
| 9 | Class type is Object/DataBlock | Ctor arg **2** at init; TNL NetClassTypeEvent = 2 | **Falsified** — **Event** |
| 10 | DAT is uninitialized forever | Static init @ `0x009c0eb0` calls `FUN_005a2410` + atexit dtor | **Falsified** — constructed |
| 11 | More direct callers exist | `get_xrefs_to` function = 1 (vtbl only) | **Falsified** — inventory complete for **function** |
| 12 | Return width is byte/word | `MOV EAX, imm32` full pointer | **Falsified** — **dword pointer** |
| 13 | `Method1` is product name | Ghidra synthetic; product class is `RPC_TNLConnection_rpcMsgGuaranteedOrdered` | **Survives as naming residual** — keep Method1 as stable ID alias |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body mov/ret | **High** | Port invents RPC payload logic that does not exist |
| Return absolute `0x00b04f40` | **High** | Wrong ClassRep → wrong net class id registration |
| Class name string | **High** | Mis-map guarantee/fragmented family |
| NetClassTypeEvent (2) | **High** | Register in wrong net class table |
| getClassRep semantics | **High** | Confuse with create()/pack |
| Full ClassRep field map after live run | **Probable** | Only needed for deep net-class dumps |
| Exact retail C++ symbol spelling | **Tentative** | Cosmetic (`getClassRep` vs macro-generated name) |
| Runtime samples of class id | **Open** | Wire class index verification |

---

## 3. Cross-check against raw / live

Live decompile 2026-07-29 matches raw `aa_0059e1c0` body exactly:

```c
return &DAT_00b04f40;
```

Live asm / memory strengthen:

* Opcode immediate confirms **`0x00b04f40`** (`b8 40 4f b0 00`)
* No prologue/epilogue beyond `ret`
* Pad `cc` after function
* ClassRep region boundary **0x38** bytes; init and atexit xrefs present
* String + RTTI independently name the same RPC class

Scaffold function record status (**Partial**) is upgraded by this dual: body was already correct; residual was identity of `DAT_*` and role.

---

## 4. Surviving contract for AutoCore

```
// Virtual ClassRep getter — no message body.
void* /*NetClassRep**/ RPC_rpcMsgGuaranteedOrdered_Method1(void* /*this unused*/) {
  return (void*)0x00b04f40; // static NetClassRepInstance for
                            // RPC_TNLConnection_rpcMsgGuaranteedOrdered
}

// Port rules:
//  - Implement as static ClassRep singleton for GuaranteedOrdered game-msg RPC.
//  - Do not put bitstream read/write in this symbol.
//  - GuaranteeType for factories installing this vtbl: 0 = RPCGuaranteedOrdered.
//  - Pair with Execute (aa_005a2a50) for connection-type gate, not here.
//  - Neighbor BSS ClassReps (…f78, …fb0, …) belong to sibling RPC variants — do not alias.
```

---

## 5. What would overturn this dual

1. Image rebuild where `0x0059e1c0` body is not `mov eax, imm; ret`.
2. Proof `DAT_00b04f40` is not constructed by the ClassRep ctor with the Ordered name string.
3. Proof vtbl slot 0 is not a ClassRep getter (e.g. different TNL fork layout with create() at slot 0 **and** return type not ClassRep) — would require contradictory RTTI/ctor evidence.
4. Evidence the immediate points at a different RPC variant's ClassRep.

Until then, CF + ClassRep identity stand at **High**.
