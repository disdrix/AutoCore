# Review B (skeptical / adversarial): `aa_004e7450` RbTree_InitEmptyHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-R) |
| **Counterpart** | `reviews/A_aa_004e7450_RbTree_InitEmptyHeader.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This alone is a full node factory | **Falsified** — only calls `FUN_00439770`; no `operator_new` here |
| 2 | Same as `FUN_004e7420` | **Falsified** — sibling uses different factory and `+0x19` flag |
| 3 | AllocEmptyNode already self-links and sets size | **Falsified** — W18-S sealed: factory leaves links 0, `+0x15=0`, no header size |
| 4 | Size field is at `header+4` | **Falsified** — `+4` is head pointer; size at `+8` |
| 5 | Returns the node pointer | **Falsified** — `mov eax,esi` returns header this |
| 6 | Needs stack args / RET N | **Falsified** — plain `ret`, ECX-only |
| 7 | Scaffold Client_InitInstance name defines product semantics | **Falsified as type name** — role is generic empty-tree header; caller is one large ctor among xrefs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Head @ +4 / size @ +8 | **High** | Corrupt map layout on port |
| Node self-links + `+0x15=1` | **High** | Iteration / empty checks break |
| Factory identity `00439770` | **High** | Wrong node size (0x18 vs sibling) |
| OOM null head | Medium | Retail faults; port may want assert |
| Product map key type | Low/Medium | Naming only for this unit |

---

## 3. Cross-check against raw + bytes

```
this (ESI) → node = AllocEmptyNode(0x18)
header+4 = node
node+0x15 = 1
node.left = node.parent = node.right = node
header+8 = 0
return this
```

Clean must **not** invent insert/erase, rebalance, or key compare — empty header only.

Do **not** fold AllocEmptyNode body into this unit (separate sealed VA).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape
unsafe RbTreeHeader* RbTree_InitEmptyHeader(RbTreeHeader* header)
{
    var node = RbTree_AllocEmptyNode(); // 0x18
    header->Head = node;
    node->IsNil = 1;           // +0x15
    node->Left = node->Parent = node->Right = node;
    header->Size = 0;          // +0x08
    return header;
}
```

---

## 5. Open questions

1. Whether server AutoCore maps use this exact 0x18 head layout or a different STL flavor.
2. How many embedded headers `FUN_004d8a10` owns (4 call sites observed).

**Verdict:** **accept**
