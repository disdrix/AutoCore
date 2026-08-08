# Review B (skeptical / adversarial): `aa_004099b0` StdTree_NodeCtor_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004099b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-C) |
| **Counterpart** | `reviews/A_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze + disassemble_function (no disassemble_bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Full buynode (alloc + construct) inside this VA | **Falsified** — no `operator_new`; caller `00408990` allocates |
| 2 | Val24 / isnil@+0x29 / size 0x30 ctor | **Falsified** — Val16 @+0x10; isnil@+0x21; buynode size 0x28 |
| 3 | stdcall host (same as buynode) | **Falsified** — **thiscall** ECX=node; RET 0x14 clears 5 args |
| 4 | Writes +0x0c / full 0x28 zero | **Falsified** — +0x0c untouched; only listed fields |
| 5 | Forces isnil=1 (head sentinel) | **Falsified** — isnil **0** (`C6 40 21 00`) |
| 6 | Freelist / CNDHash slot construct | **Falsified** — tree links + color/isnil layout |
| 7 | Multi-caller shared generic ctor | **Narrow** — **1** xref from buynode only |
| 8 | Decompiler void = no useful return | **Falsified** — EAX=this from entry |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Layout stores | **High** | corrupt nodes |
| RET 0x14 thiscall | **High** | stack smash |
| isnil=0 / color arg | **High** | RB properties |
| Product value English | Medium | naming only |

---

## 3. Cross-check

```
buynode 00408990:
  operator_new(0x28)
  → thiscall 004099b0(node, left, parent, right, value4, color)
     writes L/P/R + Val16 + color + isnil0
```

Do **not** merge with head shell `00408a30` (isnil29 / color black / no Val copy) or Val24 ctors.

---

## 4. Surviving contract for AutoCore

```csharp
Node* NodeCtor(Node* self, Node* L, Node* P, Node* R, in uint32 val4[4], byte color)
{
    self.L/P/R = L/P/R;
    Copy16(self+0x10, val4);
    self.color = color;
    self.isnil = 0;
    return self; // EAX
}
```

---

## 5. Open questions

1. Product value_type for the four dwords.  
2. Runtime golden (optional).
