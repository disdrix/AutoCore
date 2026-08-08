# Review B (skeptical / adversarial): `aa_00408ed0` StdTree_EraseAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9K-E) |
| **Counterpart** | `reviews/A_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 0xC` |
| 2 | isnil/color at +0x2D/+0x2C (StringKey family) | **Falsified** — this unit uses **+0x31 / +0x30** |
| 3 | Same binary as isnil29 erase `0x004cb740` | **Falsified** — different rotates (`00403e90`/`00403ee0`), isnil offset, ABI (RET0xC stack vs thiscall RET8) |
| 4 | Same as StringKey erase `0x004094c0` | **Falsified** — no `~basic_string`; different succ/min/rot helpers |
| 5 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_00407cb0` |
| 6 | ECX-thiscall primary | **Falsified** — **3 stack args**, `ret 0x0C` |
| 7 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 8 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 9 | Must destroy string key | **Falsified** — bare `operator_delete` only |
| 10 | Role is tree min only (partition plate shorthand) | **Falsified as sole role** — this is **erase** that *calls* min for head-left fix |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 0xC / 3 stack args | **High** | stack smash |
| isnil@+0x31 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| 1 caller | **High** | missing specialization |
| Family vs isnil29 / isnil2d | **High** | wrong rotate/dtor |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x31) → throw "invalid map/set<T> iterator"
FUN_00408590(); splice; fix root/L/R extremity (min 00409160 / max 004043e0)
if erased black → RB recolor/rotate (isnil31 L/R 00403e90/00403ee0)
operator_delete(node);  // no value dtor
if size>0 size--; *outIt=succ; ret 0xC
```

Clean must **not** invent range loops, freelist recycle, isnil29/isnil2d rotates, string dtor, or thiscall RET8 ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil31 tree node by pointer
void EraseAndRebalance(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil31(node); // FUN_00408590
    UnlinkAndRebalance(map, node);          // isnil31 L/R rotate helpers
    Delete(node);                           // no string dtor
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x31** / **color@+0x30** / **node 0x38** and call the isnil31 rotate/min/iter pair (not isnil29 / isnil2d families).

---

## 5. Open questions

1. Exact demangled map type for `FUN_00407cb0` host.  
2. Value payload English (POD sealed; fields open).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
