# Review B (skeptical / adversarial): `aa_00408ad0` StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ad0` |
| **VA** | `0x00408ad0`–`0x00408e1d` inclusive (**846 B** / `0x34E`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9L-A OWN dual) |
| **Counterpart** | `reviews/A_aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `RET 0x0C` |
| 2 | isnil/color at +0x31/+0x30 (isnil31 family) | **Falsified** — this unit uses **+0x131 / +0x130** |
| 3 | Same binary as isnil31 erase `0x00408ed0` | **Falsified** — different isnil offset, string dtor present, different min/max/rotate helpers, larger body (846 vs 656 B) |
| 4 | Same as StringKey erase `0x004094c0` | **Falsified** — isnil **+0x2d** family; different succ/min/rot helpers |
| 5 | Same as isnil29 erase `0x004cb740` | **Falsified** — different isnil, ABI, rotate set |
| 6 | Function frees whole tree / range | **Falsified** — single-node erase; range is caller `FUN_00407b70` |
| 7 | ECX-thiscall primary | **Falsified** — **3 stack args**, `RET 0x0C` |
| 8 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 9 | No string value dtor (like isnil31) | **Falsified** — `~basic_string` at node+0x0c before delete |
| 10 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 11 | Two-child mid blocks truly unreachable | **Falsified** — bytes at `0x00408be0`+ are live successor-swap path |
| 12 | Merge with OWN peer iterator++ `00404000` | **Falsified** — this **calls** successor; different ABI/role |
| 13 | Product mission/skill map name sealed | **Not sealed** — only STL throw plate + string@+0x0c layout; keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear/range) | **High** | double-free / corruption |
| ABI RET 0xC / 3 stack args | **High** | stack smash |
| isnil@+0x131 / color@+0x130 | **High** | map corruption |
| string@+0x0c destroy | **High** | leak / double-free of string buffers |
| size-- epilogue | **High** | size drift |
| 1 external caller | **High** | missing specialization |
| Family vs isnil31 / isnil29 / isnil2d | **High** | wrong rotate/dtor |
| Two-child splice plate exactness | **Med** | rare path; clean simplified |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x131) → throw "invalid map/set<T> iterator"  // 0x00a152f0 / DAT_00acc34c
LEA EDX, &node_slot; CALL FUN_00404000   // successor isnil131
splice; fix root/L/R extremity (min 00404160 / max 004043c0)
  // two-child successor-swap path @ 0x00408be0 (decomp "unreachable" = false)
if erased black → RB recolor/rotate (isnil131 L/R 00403cb0/00403d00)
~basic_string(node+0x0c); operator_delete(node)
if size>0 size--; *outIt=succ; RET 0x0C
```

Entry bytes seal isnil@+0x131 and throw path:

```
64 a1 00 00 00 00 6a ff 68 df d0 9b 00 50 8b 44 24 18 ...
80 b8 31 01 00 00 00 74 34 68 f0 52 a1 00 ...   // CMP [EAX+0x131],0; JZ ok; PUSH "invalid..."
```

Epilogue bytes seal size-- / *outIt / RET 0xC:

```
... 89 41 08 8b 54 24 60 8b 44 24 5c 8b 4c 24 48 89 10 ... 83 c4 54 c2 0c 00
```

Clean must **not** invent:

- range loops / freelist recycle
- isnil31 / isnil29 / isnil2d rotate sets
- bare delete without string dtor
- thiscall RET8 ABI
- product map English without RTTI/string evidence

Clean **may** simplify the two-child successor-swap plate in pseudocode, but ports must preserve full MSVC erase semantics (documented gap).

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil131 string-valued tree node by pointer
void EraseAndRebalance_Isnil131_DestroyStr0C(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) // +0x131
        throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil131(node); // FUN_00404000
    UnlinkAndRebalance_Isnil131(map, node);  // min/max + L/R rotate isnil131 family
    DestroyStringAt0C(node);                 // ~basic_string @ +0x0c
    Delete(node);
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x131** / **color@+0x130** / **string@+0x0c** and call the isnil131 rotate/min/iter pair (not isnil31 / isnil29 / isnil2d families).

---

## 5. Open questions

1. Exact demangled map type for `FUN_00407b70` host.  
2. Key English beyond string value @+0x0c.  
3. Full two-child plate bit-exact clean expansion.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
