# Review B (skeptical / adversarial): `aa_00441960` StdTree_EraseRange_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-136) |
| **Counterpart** | `reviews/A_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory_bytes` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`). No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Product gfxUIWindow method (scaffold name) | **Falsified** — pure STL range erase; multi-caller; no UI strings in body |
| 2 | Same as isnil29 erase-range `0x004cbaa0` | **Falsified** — free `00440d20` vs `004cb550`; erase `004477a0` vs `004cb740`; isnil **+0x11** vs **+0x29** |
| 3 | Same as isnil31 erase `0x00408ed0` family | **Falsified** — different free/erase pair; isnil offset |
| 4 | ECX thiscall map (like isnil29 peer) | **Falsified** — entry uses **EDI**; call sites `MOV EDI,shell`; free gets `MOV ECX,EDI` only for free ABI |
| 5 | Full-clear only (no partial range) | **Falsified** — while-loop successor + `FUN_004477a0` path |
| 6 | Single-node erase only | **Falsified** — full-clear free-subtree path + loop |
| 7 | Decompiler void / wrong ret | **Falsified for ABI** — both exits `C2 0C 00`; EAX=outIt |
| 8 | isnil@+0x15 / +0x1d / +0x29 / +0x31 | **Falsified** — immediates **`+0x11` only** |
| 9 | Free path leaves size non-zero | **Falsified** — `MOV [EDI+8],0` on full clear |
| 10 | `unaff_EDI` is junk / non-map | **Falsified** — call sites load shell into EDI before CALL |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range erase role | **High** | wrong API surface |
| RET 0xC + EDI map | **High** | stack smash / wrong register |
| isnil@+0x11 | **High** | map corruption |
| Free/erase callee pair | **High** | merge with other isnil families |
| Product English | Medium | naming only |
| Single-erase residual algebra | Med | partial-range correctness |

---

## 3. Cross-check against raw + bytes

```
if first==begin && last==end:
  free_subtree(root);  // 00440d20 isnil11
  reset head; size=0; *outIt=begin; ret 0xc
while first!=last:
  succ = successor_isnil11(first)
  erase_rebalance(map, &first, first)  // 004477a0
  first = succ
*outIt = first; ret 0xc
```

Clean must **not**: invent ECX-thiscall; merge isnil29/31 free-erase pairs; restore gfxUIWindow scaffold as product role; drop size zeroing; claim runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase [first, last) on isnil@+0x11 tree; map in EDI-style register / explicit map arg
void EraseRange(MapShell map, ref Node outIt, Node first, Node last)
{
    if (first == map.Begin && last == map.End) {
        FreeSubtreeIsnil11(map, map.Root); // 00440d20
        map.ResetEmpty();
        outIt = map.Begin;
        return;
    }
    while (first != last) {
        var succ = SuccessorIsnil11(first);
        EraseAndRebalanceIsnil11(map, ref first, first); // 004477a0 residual
        first = succ;
    }
    outIt = first;
}
```

Port must keep **this free/erase pair** (`00440d20` / `004477a0`) and **isnil@+0x11**. Do not merge with isnil29 range `004cbaa0` or Map_EraseRange free pairs. Map register is **EDI** at call boundary (or pass map explicitly in ported C++).

---

## 5. Open questions

1. Exact demangled map type of shell@+0xA4 on `gfxUIWindow` / other callers.  
2. Full dual of `FUN_004477a0` (throw path shares `"invalid map/set<T> iterator"`).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
