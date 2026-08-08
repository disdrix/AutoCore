# Review B (skeptical / adversarial): `aa_004e4e10` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4e10` |
| **VA** | `0x004e4e10` |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-024 OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |
| **Dual start** | 2686 |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same unit as single erase `004e3e70` | Body is 180 B range shell; erase is 694 B with throw/RB | **Falsified** interchange |
| 2 | Same as twin `FUN_004e52a0` | Same erase callee, but full free is `004e2e00` vs `004e2e40` | **Falsified** merge |
| 3 | Same as Val12 range `004e5120` | isnil immediates **+0x21** vs Val12 **+0x19**; erase `004e3e70` vs `004e4130` | **Falsified** |
| 4 | Same as Isnil29 range `004cbaa0` | Same 180 B shape / RET 0xC pattern, but isnil offset + free/erase VAs differ | **Falsified** product merge |
| 5 | isnil/color at Val12 (+0x19/+0x18) | Successor uses `CMP [reg+0x21],0` (`80 ?? 21 00`) throughout | **Falsified** Val12 layout |
| 6 | Decompiler void hides stack cleanup | Both exits **`C2 0C 00`** @ `0x004e4e57` and `0x004e4ec1` | **Falsified** for ABI |
| 7 | Full clear leaves size non-zero | Body `MOV dword [map+8], 0` on full path | **Falsified** |
| 8 | Erase called without map ECX | Bytes `MOV ECX,EDI; CALL 004e3e70` @ `0x004e4ead` | **Falsified** |
| 9 | Multi-caller product surface | Sole xref `FUN_004e7320` @ `0x004e7332` | **Agree** 1 caller |
| 10 | Named_VOG_DEBUG identity is product role | Scaffold callee-of chain only | **Falsified** product id |
| 11 | Free-subtree `004e2e00` fully sealed | Decomp shows right-only + false-noreturn delete | **Agree Open** residual |
| 12 | PDB name proven | No body product demangle | **Agree Open**; role High OK |

---

## 2. Live ≡ raw

```
Live decompile 2026-08-05 ≡ raw 2026-07-23 CF for full-clear + successor + erase loop.
read_memory entry: 53 8B 5C 24 10 56 8B 74 24 10 57 8B F9 8B 47 04 ...
isnil immediates: 80 7E 21 00 / 80 78 21 00 throughout successor.
Epilogues: C2 0C 00 both exits; exclusive end 0x004e4ec4; 180 B body; CC×12 pad.
Callees: FUN_004e2e00 (full free), FUN_004e3e70 (single erase @ 004e4eaf).
Caller: FUN_004e7320 only (1 xref).
Peer: FUN_004e52a0 same CF with free FUN_004e2e40 (not owned).
```

---

## 3. Surviving contract

```
// void __thiscall StdTree_EraseRange_Isnil21_Inferred(map*, Node** outIt, Node* first, Node* last)
// RET 0x0C
// if first==begin && last==end:
//   FUN_004e2e00(root); head L/P/R = head; size=0; *outIt=begin
// else while first!=last:
//   succ = successor_isnil21(first)
//   StdTree_EraseAndRebalance_Isnil21(map, &first, first)  // 004e3e70
//   first = succ
// *outIt = first
// NOT Val12 (004e5120); NOT Isnil29 (004cbaa0); NOT twin free 004e2e40 (004e52a0)
// NOT single-node erase (004e3e70 is callee)
```

---

## 4. CF challenge of Review A

- Full-clear + partial range role: **agree Confirmed**
- thiscall + ret 0x0c both exits: **agree Confirmed** (bytes)
- isnil@+0x21: **agree Confirmed**
- Callees `004e2e00` + `004e3e70`: **agree Confirmed**
- Sole caller `004e7320`: **agree Confirmed**
- Name `StdTree_EraseRange_Isnil21_Inferred`: **agree acceptable** (family vocabulary)
- Do not substitute Val12 / Isnil29 / twin free path: **agree**
- Free-subtree completeness of `004e2e00`: **agree Open** residual

---

## 5. Residual risks

1. Product English / demangled `map<K,V>` for sole caller `FUN_004e7320` (skills-abilities context).  
2. Whether `FUN_004e2e00` left-recurses (decomp drops left; false-noreturn on delete).  
3. Exact free difference vs twin `004e52a0`/`004e2e40` (value dtor vs POD).  
4. Runtime / bit-exact / differential not run.  
5. Parent dual erase sealed; free-subtree residual may still need own dual.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, layout, free/erase pair, and inferred name.
