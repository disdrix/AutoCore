# Review B (skeptical / adversarial): `aa_00405f20` StdTree_ConstructEmpty_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9K-C) |
| **Counterpart** | `reviews/A_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is Client constructor product method | **Falsified** — generic StdTree empty shell; Client only hosts subobject |
| 2 | Scaffold `Named_CalleeOf_Named_Client_Constructor_*` is correct name | **Falsified** — chain-of-caller plate only |
| 3 | Full `_Buyheadnode` including alloc lives entirely here | **Falsified** — alloc is dualed callee `00409180`; this only installs |
| 4 | isnil29 / node 0x30 family | **Falsified** — isnil store @+0x31; buyhead size 0x38 |
| 5 | thiscall ECX=this | **Falsified** — stdcall stack arg; RET 0x4 |
| 6 | Clears value payload / freelist recycle | **Falsified** — only head links + isnil1 + size0 |
| 7 | Same as OWN peer buynode `00404180` | **Falsified** — different family (isnil31 head shell vs isnil29 data node buy) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| isnil@+0x31 install | **High** | wrong tree family |
| self-link + size0 | **High** | empty-tree invariant break |
| RET 0x4 stdcall | **High** | stack imbalance |
| Sole Client-subobject caller | **High** | mis-scope only |
| Product English | Medium | naming only |
| Key/value type at +0xF14 | Low–Med | map identity only |

---

## 3. Cross-check against raw + bytes

```
SEH; mov esi, [esp+0x14]   ; shell*
call 00409180              ; buyhead → eax
mov [esi+4], eax           ; _Myhead
mov byte [eax+0x31], 1     ; isnil head
mov [eax+4], eax           ; parent=self
mov [eax], eax             ; left=self
mov [eax+8], eax           ; right=self
mov [esi+8], 0             ; size
mov eax, esi; ret 0x4
```

Clean must **not** invent Client domain semantics, freelist, or isnil29 head wrappers.

---

## 4. Surviving contract for AutoCore

```csharp
// Empty isnil31 tree shell construct
TreeShell ConstructEmpty_Isnil31(TreeShell shell)
{
    var head = BuyHeadNode_Isnil31_Size0x38();
    shell.Myhead = head;
    head.IsNil = true; // +0x31
    head.Left = head.Parent = head.Right = head;
    shell.Mysize = 0;
    return shell;
}
```

Port must keep **isnil@+0x31** and pair with **0x38** buyhead — do not fold into isnil29 empty construct.

---

## 5. Open questions

1. English type of Client subobject at +0xF14.  
2. Allocator field at shell+0.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
