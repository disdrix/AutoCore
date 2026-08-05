# Review B (skeptical / adversarial): `aa_005399f0` Map_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005399f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-R) |
| **Counterpart** | `reviews/A_aa_005399f0_Map_EraseNode_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function ends at Ghidra `0x00539c76` with no size update | **Falsified** — bytes continue: size--, `*outIt`, **ret 8** through `0x00539ca6` |
| 2 | `operator_delete` is true noreturn / no fall-through | **Falsified** — epilogue after call |
| 3 | Same layout as `Map_EraseNode` `aa_0051cb40` (isnil@+0x29) | **Falsified** — this VA uses **isnil@+0x19** / **color@+0x18** (Val12) |
| 4 | Zero stack args / cdecl | **Falsified** — **ret 8** ⇒ two stack formals |
| 5 | Multi-caller shared skill path | **Weakened** — **sole** caller `FUN_0053a260` (range erase) |
| 6 | Decompiler "unreachable blocks" are dead alternate algorithms | **Falsified risk** — RB case folding |
| 7 | Product name is known | **Open** — structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase + throw + delete contract | **High** | map corruption / leak |
| ABI ret 8 | **High** | stack smash |
| Val12 isnil/color | **High** | wrong peer family |
| size-- | **High** | size desync |
| Full RB cases | Med | edge-case balance |
| Product English | Low–Med | naming only |

---

## 3. Cross-check against raw + bytes

```
if (isnil@+0x19) throw "invalid map/set<T> iterator"
FUN_005ae0b0(); unlink; maybe min/max; if black: rebalance rotates
operator_delete(node); // falls through
if (size) size--; *outIt = succ; ret 8
```

Clean must **not** use isnil@+0x29, claim Ghidra end is true, or omit size--.

---

## 4. Surviving contract for AutoCore

```csharp
// Val12 map/set single-node erase
void EraseNode(MapShell map, out Node succ, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    // unlink + RB fixup (Val12 rotates)
    Free(node);
    if (map.Size > 0) map.Size--;
    succ = /* successor */;
}
```

Do not substitute large-node `Map_EraseNode` (isnil@+0x29) for this clone.

---

## 5. Open questions

1. Exact demangled type for the map owning `FUN_0053a260`.  
2. Full semantics of `FUN_005ae0b0` at this site.  
3. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
