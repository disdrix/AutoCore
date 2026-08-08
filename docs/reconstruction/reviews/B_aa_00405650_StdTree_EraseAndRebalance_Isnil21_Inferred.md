# Review B (skeptical / adversarial): `aa_00405650` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-009) |
| **Counterpart** | `reviews/A_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 8` |
| 2 | isnil/color at +0x31/+0x30 (isnil31 family) | **Falsified** — this unit uses **+0x21 / +0x20** |
| 3 | isnil/color at +0x29/+0x28 (isnil29 family) | **Falsified** — opcodes `80 78 21 00` seal **+0x21** |
| 4 | Same binary as isnil29 thiscall erase `0x004cb740` | **Falsified** — different rotates (`0050e9f0`/`005a27f0` vs isnil29 pair), isnil offset |
| 5 | Same as isnil29 RetC erase `0x00402850` | **Falsified** — ABI thiscall RET8 vs stack RET0xC; different helpers |
| 6 | Same as isnil31 erase `0x00408ed0` | **Falsified** — isnil offset + rotate/min/iter + ABI (RET8 thiscall vs RET0xC stack) |
| 7 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_00407140` |
| 8 | Stack-only 3-arg RET 0xC primary | **Falsified** — **ECX thiscall**, **2 stack args**, `ret 8` |
| 9 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 10 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 11 | Must destroy string key / value | **Falsified** — bare `operator_delete` only |
| 12 | Role is Rrotate only (parent dual plate) | **Falsified as sole role** — this is **erase** that *calls* Rrotate `005a27f0` |
| 13 | Product skill/ability map English sealed | **Falsified** — structural STL erase only; host map open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI thiscall ret 8 / 2 stack args | **High** | stack smash |
| isnil@+0x21 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| 2 callers (range + host+0xed8) | **High** | missing specialization |
| Family vs isnil29 / isnil2d / isnil31 | **High** | wrong rotate/dtor/ABI |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x21) → throw "invalid map/set<T> iterator"
FUN_004e12c0(); splice; fix root/L/R extremity (min 004cb2c0 / max 00421a60)
if erased black → RB recolor/rotate (isnil21 L/R 0050e9f0/005a27f0)
operator_delete(node);  // no value dtor
if size>0 size--; *outIt=succ; ret 8
```

Clean must **not** invent range loops, freelist recycle, isnil29/isnil31 rotates, value dtor, stack RET 0xC ABI, or skill-product English as the unit name.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil21 tree node by pointer (thiscall)
void EraseAndRebalance_Isnil21(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil21(node); // FUN_004e12c0
    UnlinkAndRebalance(map, node);          // isnil21 L/R rotate helpers 0050e9f0/005a27f0
    Delete(node);                           // no value dtor
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x21** / **color@+0x20** / **node 0x28** and call the isnil21 rotate/min/iter pair (not isnil29 / isnil2d / isnil31 families). ABI: **thiscall** + **ret 8**.

---

## 5. Open questions

1. Exact demangled map type for `FUN_00932c80` host+0xed8 / range parent `FUN_00407140`.  
2. Value payload English (POD/Val16 sealed; fields open).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
