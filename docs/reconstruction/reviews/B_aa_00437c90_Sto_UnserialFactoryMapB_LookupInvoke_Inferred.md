# Review B (skeptical / adversarial): `aa_00437c90` Sto_UnserialFactoryMapB_LookupInvoke_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W36-C) |
| **Counterpart** | `reviews/A_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ PeekChunkTag context). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Uses MapA | Calls target `FUN_00438ca0` only | **Falsified if MapA** |
| 2 | Same body as MapA lookup `00437b00` | MapA has out-param + secondary vcall; MapB is 63 B simple invoke | **Falsified if equated** |
| 3 | Is insert | No insert/log strings; only find + call | **Falsified** |
| 4 | Stack args | Prologue uses EAX→ESI only; no stack formals | **Falsified if stack tag param** |
| 5 | Decompiler `(creator)(tag)` stack pass | Bytes: bare `CALL [ECX+0xC]`, no PUSH | **Clarify** — stack arg **unproved** |
| 6 | Returns −1 on miss | Miss is `XOR EAX,EAX` → **0** | **Falsified if −1** (MapA path different) |
| 7 | gfxBody product (scaffold) | MapB + PeekChunkTag + sole storage caller | **Reject scaffold** |
| 8 | ECX-thiscall on self | ECX only used as node for CALL [ECX+0xC] | **Not** object method on factory |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Map B lookup path | **High** | Wrong registry |
| Miss returns 0 | **High** | Error-code confusion with MapA −1 |
| Invoke via node+0xC | **High** | Miss creator |
| Creator formals | **Low / open** | Port ABI break |
| EAX reader entry | **High** | Broken peek |

---

## 3. Cross-check against raw / bytes

```
raw: peek; GetB; find; GetB; if node!=sentinel call [node+0xC](tag?); else 0
bytes: MOV ESI,EAX; CALL peek; CALL 438ca0; find; CALL 438ca0; CMP; POP ESI; CALL [ECX+0xC] | XOR EAX,EAX
```

Clean must **not** invent:

- MapA GetInstance
- Return `0xFFFFFFFF` on miss
- Guaranteed stack tag argument to creator
- Insert/log behavior
- gfxBody naming

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00437c90 — Map B only
// entry: reader in EAX (or explicit arg in port API)
object? Sto_UnserialFactoryMapB_LookupInvoke(StoChunkReader reader)
{
    uint tag = reader.PeekChunkTag();
    var bag = Sto_UnserialFactoryMapB_GetInstance();
    var node = NestedHash_Find(bag, tag);
    if (node == bag.Sentinel)
        return null; // 0
    var creator = node.CreatorAt0x0C;
    return creator.Invoke(/* formals open: reader may be live in ESI */);
}
```

**Port traps:** using MapA; treating miss as −1; hard-coding cdecl `(tag)` without evidence; conflating with `FUN_00437b00`.

---

## 5. Verdict

**accept-with-gaps** — adversarial separation from MapA lookup and insert holds; creator ABI open.
