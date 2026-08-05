# Review B (skeptical / adversarial): `aa_004e4130` StdTree_EraseAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-Q) |
| **Counterpart** | `reviews/A_aa_004e4130_StdTree_EraseAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*out_it`, `ret 8` |
| 2 | isnil/color at +0x15/+0x14 (isnil@15 maps) | **Falsified** — this unit uses **+0x19 / +0x18** (Val12) |
| 3 | Same binary as `StdMap_EraseIterator_Inferred` @ `004baa30` | **Falsified** — different VA, rotates (`00573170`/`00418c10` vs `004e22d0`/`006753b0`), isnil offset |
| 4 | Function frees whole tree / range | **Falsified** — single-node erase; range would loop this |
| 5 | Legacy VOG_DEBUG name is product role | **Narrow** — scaffold callee-of chain; structural erase is the role |
| 6 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 7 | `param_2` is unused dead formal | **Falsified** — out-iterator store in epilogue bytes |
| 8 | Scaffold alone is dual-ready | **Falsified** — needed ABI + epilogue + Val12 seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 8 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| Sole caller | **High** | missing specialization |
| Product English | Medium | naming only |
| Successor prep helper name | Low–Med | naming only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil → throw "invalid map/set<T> iterator"
FUN_005ae0b0(); splice; fix root/L/R extremity
if erased black → RB recolor/rotate (Val12 L/R)
operator_delete(node); if size>0 size--; *outIt=succ; ret 8
```

Clean must **not** invent range loops, freelist recycle, or isnil@+0x15 offsets from the other erase clone.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one Val12 tree node by pointer; parent owns key identity
void EraseAndRebalance(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor(node); // FUN_005ae0b0
    UnlinkAndRebalance(map, node);  // Val12 L/R rotate helpers
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x19** and call the Val12 rotate pair (not the isnil@15 rotate pair).

---

## 5. Open questions

1. Exact demangled map type for `FUN_004e5120`.  
2. Whether `FUN_005ae0b0` also writes the out-it shadow fully.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
