# Review B (skeptical / adversarial): `aa_00409180` StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9J-F) |
| **Counterpart** | `reviews/A_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` is correct ABI | **Falsified** — EAX returned; caller stores node* |
| 2 | This is full `_Buyheadnode` including self-link + isnil=1 | **Falsified** — only blank alloc; caller finishes head |
| 3 | Same as isnil29 head `0x00408a30` / isnil21 `0x004088f0` | **Falsified** — different size (0x38) and isnil offset (+0x31) |
| 4 | Scaffold `Named_CalleeOf_*Client_Constructor*` is product role | **Falsified** — chain-of-caller plate only; CF is StdTree head shell |
| 5 | CNDHash freelist / operator_delete recycle | **Falsified** — pure `operator_new` + field stores |
| 6 | isnil set to 1 here (head ready) | **Falsified** — stores **0**; caller writes 1 |
| 7 | Same family as OWN peer erase `0x004094c0` (isnil@+0x2d) | **Falsified** — different isnil offset / node size / role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc size 0x38 | **High** | OOB / wrong node type |
| color@+0x30 / isnil@+0x31 | **High** | tree corruption |
| EAX return | **High** | null head install |
| Head role via sole caller | **High** | mis-name only |
| Product English | Medium | naming only |
| Val36 type | Low–Med | layout docs only |

---

## 3. Cross-check against raw + bytes

```
SEH; push 0x38; operator_new
zero [eax], [eax+4], [eax+8]
mov [eax+0x30], 1
mov [eax+0x31], 0
restore FS; pop*; ret   ; EAX still node
```

Caller:
```
call 00409180
mov [esi+4], eax
mov byte [eax+0x31], 1
self-link L/P/R; size=0
```

Clean must **not** invent freelist, self-link inside this VA, or merge with isnil29/21 heads.

---

## 4. Surviving contract for AutoCore

```csharp
// Allocate blank isnil@+0x31 / 0x38 tree node (head shell)
Node BuyHeadNode_Isnil31_Size0x38()
{
    var n = Alloc(0x38);
    n.Left = n.Parent = n.Right = null;
    n.Color = Black; // +0x30
    n.IsNil = false; // +0x31 — caller sets true for head
    return n;
}
```

Port must keep **isnil@+0x31** and **size 0x38** — do not fold into isnil29 0x30 head helper.

---

## 5. Open questions

1. Exact demangled map type for `FUN_00405f20` host.  
2. What lives in Val36 (+0x0C..+0x2F).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
