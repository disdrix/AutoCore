# Review B (skeptical / adversarial): `aa_0040b440` StdTree_EraseAndRebalance_Val12_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-018) |
| **Counterpart** | `reviews/A_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 0xC` |
| 2 | isnil/color at +0x21/+0x20 (isnil21 family) | **Falsified** — this unit uses **+0x19 / +0x18** |
| 3 | isnil/color at +0x29/+0x28 (isnil29 family) | **Falsified** — opcodes `80 78 19 00` seal **+0x19** |
| 4 | Same binary as thiscall Val12 erase `0x004e4130` | **Falsified** — ABI **ret 0xC** vs **ret 8 thiscall**; different min/iter/rotate pair |
| 5 | Same as isnil29 RetC erase `0x00402850` | **Falsified** — isnil offset Val12 vs +0x29; different helpers |
| 6 | Same as isnil31 erase `0x00408ed0` | **Falsified** — isnil offset + helpers |
| 7 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_0040bc10` |
| 8 | Thiscall RET 8 primary (like isnil21 / 004e4130) | **Falsified** — **3 stack args**, **`ret 0xC`**; call sites 3× PUSH |
| 9 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 10 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 11 | Must destroy string key / value | **Falsified** — bare `operator_delete` only |
| 12 | Role is MissionTracker product logic | **Falsified as sole role** — structural STL erase; parent is MissionTracker fill slots |
| 13 | Product inventory-transfer map English sealed | **Falsified** — partition system only; unit is generic Val12 erase |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI stack ret 0xC / 3 stack args | **High** | stack smash |
| isnil@+0x19 layout (Val12) | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| 2 callers (range + MissionTracker parent) | **High** | missing specialization |
| Family vs thiscall Val12 / isnil21/29/31 | **High** | wrong rotate/dtor/ABI |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x19) → throw "invalid map/set<T> iterator"
FUN_00457cc0(); splice; fix root/L/R extremity (min 0043bf90 / max 0040b8f0)
if erased black → RB recolor/rotate (L/R 00446b10 / 0040b910)
operator_delete(node);  // no value dtor
if size>0 size--; *outIt=succ; ret 0xC
```

Clean must **not** invent range loops, freelist recycle, thiscall RET 8, isnil21/29/31 rotates, value dtor, or inventory-product English as the unit name.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one Val12 tree node by pointer (stack 3-arg, ret 0xC)
void EraseAndRebalance_Val12_RetC(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil19(node); // FUN_00457cc0
    UnlinkAndRebalance(map, node);          // L/R 00446b10 / 0040b910
    Delete(node);                           // no value dtor
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x19** / **color@+0x18** / **node 0x1C** and call this clone's rotate/min/iter pair (not the thiscall Val12 pair at `004e4130` / `00573170` / `00418c10`). ABI: **stack 3-arg + ret 0xC**.

---

## 5. Open questions

1. Exact demangled map type for `FUN_0092b2a0` host / range parent `FUN_0040bc10`.  
2. Value payload English (POD/Val12 sealed; fields open).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
