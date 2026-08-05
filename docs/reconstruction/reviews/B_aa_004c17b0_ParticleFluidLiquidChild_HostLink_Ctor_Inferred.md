# Review B (skeptical / adversarial): `aa_004c17b0` ParticleFluidLiquidChild_HostLink_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c17b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-L) |
| **Counterpart** | `reviews/A_aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Whole liquid-child is `this` (ECX = 0x40 object) | **Falsified** — caller `LEA ECX,[ESI+0x18]`; only 8 B written |
| 2 | Always inserts into list | **Falsified** — null host skips (`74 34`) |
| 3 | List size at host+8 | **Falsified** — head @ host+8; size @ host+0xC (IncSize ECX=host+4) |
| 4 | NDRiver / Drive product plate is structural | **Narrow** — scaffold Named_CalleeOf chain; reject product |
| 5 | Decompiler `FUN_004c20b0(1)` hides thiscall target | **Weakened display only** — bytes `MOV ECX,ESI` with ESI=host+4 |
| 6 | Subobject owns +0x20..+0x3C zero region | **Falsified** — those zeros are liquid-child siblings (W37-G) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Subobject +0x18 / 8 B | **High** | corrupt liquid-child layout |
| RET 4 thiscall | **High** | stack smash |
| List head/size slots | **High** | list corruption |
| Sole-caller coupling | **High** | wrong specialization |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
MOV EAX,[ESP+4]; TEST; PUSH EBP; MOV EBP,ECX
*this = 009cb7a4; *(this+4)=host; JZ skip
head=*(host+8); prev=head->prev; value=this
node = Buynode0C(head, prev, &value)
IncSize(host+4, 1); head->prev=node; old_prev->next=node
return this; RET 4
```

Clean must **not** treat ECX as full liquid-child or invent NDRiver product names.

---

## 4. Surviving contract for AutoCore

```csharp
// HostLink subobject @ liquidChild+0x18
HostLink Ctor(HostLink* self, object host)
{
    self.Vtbl = Vtbl_009cb7a4;
    self.Host = host;
    if (host != null)
        ListPushBack(host.ListHeadAt8, host.SizeAtC, self);
    return self; // ret 4
}
```

---

## 5. Open questions

1. Demangled type behind vtbl `009cb7a4` / method `004c09c0`.  
2. Whether host can ever be non-liquid-child (other list owners).  
3. Runtime / differential.
