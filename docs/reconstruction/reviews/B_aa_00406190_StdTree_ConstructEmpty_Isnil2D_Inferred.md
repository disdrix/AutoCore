# Review B (skeptical / adversarial): `aa_00406190` StdTree_ConstructEmpty_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9K-D) |
| **Counterpart** | `reviews/A_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is product host-ctor method English | **Falsified** — generic StdTree empty shell; host only embeds subobject |
| 2 | Full `_Buyheadnode` including alloc lives entirely here | **Falsified** — alloc is dualed callee `00409780`; this only installs |
| 3 | isnil31 / node 0x38 family (merge with `00405f20`) | **Falsified** — isnil store @+0x2d; buyhead size 0x30 |
| 4 | isnil29 BuyHead family (`00408a30`) | **Falsified** — isnil @+0x2d not +0x29 |
| 5 | thiscall ECX=this | **Falsified** — stdcall stack arg; RET 0x4 |
| 6 | Clears value payload / freelist recycle | **Falsified** — only head links + isnil1 + size0 |
| 7 | Same as OWN peer insert-or-find `00405bd0` | **Falsified** — different role/family (empty shell vs pair-key insert) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| isnil@+0x2d install | **High** | wrong tree family |
| self-link + size0 | **High** | empty-tree invariant break |
| RET 0x4 stdcall | **High** | stack imbalance |
| Sole host-subobject caller | **High** | mis-scope only |
| Product English | Medium | naming only |
| Key/value type at host+0x0C | Low–Med | map identity only |

---

## 3. Cross-check against raw + bytes

```
SEH; mov esi, [esp+0x14]   ; shell*
call 00409780              ; buyhead isnil2D → eax
mov [esi+4], eax           ; _Myhead
mov byte [eax+0x2d], 1     ; isnil head
mov [eax+4], eax           ; parent=self
mov [eax], eax             ; left=self
mov [eax+8], eax           ; right=self
mov [esi+8], 0             ; size
mov eax, esi; ret 0x4
```

Clean must **not** invent host domain semantics, freelist, or isnil29/31 head wrappers.

---

## 4. Surviving contract for AutoCore

```csharp
// Empty isnil2D tree shell construct
TreeShell ConstructEmpty_Isnil2D(TreeShell shell)
{
    var head = BuyHeadNode_Isnil2D_Size0x30();
    shell.Myhead = head;
    head.IsNil = true; // +0x2d
    head.Left = head.Parent = head.Right = head;
    shell.Mysize = 0;
    return shell;
}
```

Port must keep **isnil@+0x2d** and pair with **0x30** buyhead — do not fold into isnil31 empty construct.

---

## 5. Open questions

1. English type of host subobject at +0x0C.
2. Allocator field at shell+0.
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
