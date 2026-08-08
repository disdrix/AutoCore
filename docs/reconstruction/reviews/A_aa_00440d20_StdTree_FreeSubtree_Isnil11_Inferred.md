# Review A (reconstruction fidelity): `aa_00440d20` StdTree_FreeSubtree_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440d20` |
| **VA** | `0x00440d20`–`0x00440d54` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil11_Inferred` |
| **Ghidra name** | `FUN_00440d20` |
| **Partition alias** | `StdTree_ClearShell_AtA4` (host role on gfxUIWindow shell `@+0xA4`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-132) |
| **Counterpart** | `reviews/B_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` |
| **System** | skills-abilities — STL tree free-subtree / isnil@+0x11 (gfxUIWindow teardown) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`_Tree` free-subtree** for small nodes (**isnil @ +0x11**). For each node on the left spine of the given root: recursively free the **right** child, `operator_delete` the node, advance to **left**. Stop at isnil sentinel. **No** value destroy. Used to empty the gfxUIWindow tree shell at **`+0xA4`**, by erase-all full-clear `FUN_00441960`, and by UI rebuild `FUN_00759090`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (2026-08-05 ≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 53 B full body + `CC` pad |
| Disasm | `disassemble_function` (mid-loop opcodes recovered from hex where listing skipped) |
| CF twins | `StdTree_FreeSubtree_Isnil29_Inferred` `0x00406c00`; `Map_FreeSubtree_Isnil29` `0x0051bbc0` |
| Value-dtor siblings | `FUN_00440ab0` isnil@+0x3d; `FUN_00440c90` isnil@+0x1d |
| Host parent | dualed `gfxUIWindow_CompleteDtor` `0x00759de0` (WQ9L-F) — shell `@+0xA4` |

---

## 3. Signature (sealed)

```c
// ECX = tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(void* tree_base, void* node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`MOV EBX,ECX`; recursive `MOV ECX,EBX`) | **High** |
| node | stack `[ESP+0x10]` after 3 pushes | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

```
if node.isnil@+0x11: ret 4
loop:
  FreeSubtree(tree_base, node.right@+8)
  left = node.left@+0
  operator_delete(node)   // cdecl; ADD ESP,4
  node = left
  if !node.isnil: continue
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x11 gate | `80 7F 11 00` / `80 7E 11 00` | **High** |
| right recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL 00489822; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |
| No value dtor | no CALL between left load and delete | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B):

```
53 56 57 8B 7C 24 10 80 7F 11 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 DE 8A 04 00
83 C4 04 80 7E 11 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Self | recursive right free @ `0x00440d37` |
| External callers | `FUN_00441960` @ `0x00441980`; `FUN_00759de0` @ `0x00759ed6`; `FUN_00759090` @ `0x0075911a` |
| Xrefs | 4 UNCONDITIONAL_CALL |
| Host role | free root of gfxUIWindow shell `@+0xA4` (partition ClearShell_AtA4) |

---

## 7. Gaps

- Product / MSVC demangle for map key/value of isnil@+0x11 family.
- Erase-all parent `FUN_00441960` residual (MEGA-136).
- Value-dtor siblings `00440ab0` / `00440c90` residual (MEGA-130/131).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity seals free-subtree CF/ABI/isnil11/callers/no-value-dtor. Product residual → **accept-with-gaps**.
