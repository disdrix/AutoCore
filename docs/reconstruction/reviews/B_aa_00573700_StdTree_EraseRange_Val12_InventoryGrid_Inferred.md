# Review B (skeptical / adversarial): `aa_00573700` StdTree_EraseRange_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-120 OWN dual) |
| **Counterpart** | `reviews/A_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` |
| **System** | inventory-transfer / MSVC tree range erase Val12 |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is product-only `InventoryGrid_DestroyItemList` | **Falsified as sole name** — body is generic `[first,last)` erase; used by AutoMerge temp map + map-shell dtor, not only “destroy item list” |
| 2 | This is InventoryGrid method (ECX=grid) | **Falsified** — complete dtor does `LEA ESI,[EDI+0x5c]; MOV ECX,ESI` before CALL; ECX is **map shell**, not grid |
| 3 | Stack formals are 2 (missing outIt) | **Falsified** — dual `RET 0x0C` and three stack loads (out, first, last) |
| 4 | isnil at +0x15 / +0x1d / +0x29 / +0x31 | **Falsified** — successor loads `+0x19` only (Val12 family with dualed erase `00573250`) |
| 5 | Full free destroys T* via vtbl | **Falsified for this body** — only `FUN_005731c0` free + head reset; no value vtbl walk here |
| 6 | Same callees as peer `0040d700` | **Falsified** — free=`005731c0`, erase=`00573250` (peer uses `0040d630` / `004188e0`); **CF skeleton** matches, not callees |
| 7 | Decompiler `FUN_00573250(&param_3,node)` drops this | **Partial** — assembly `MOV ECX,EDI` seals thiscall; decomp omits ECX formal |
| 8 | Free `005731c0` only recurses right (decomp) | **Falsified via bytes** — live disasm: free right, advance left, delete, loop; decomp false noreturn |
| 9 | Product map type sealed | **Careful** — structural Val12 + InventoryGrid owner only; demangle open |
| 10 | Identical function to `0040d700` (same VA family) | **Structural yes, instance no** — 180 B hex clone with different CALL relocs; separate dual unit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Full vs partial CF | **High** | Wrong bulk clear path |
| RET 0x0C / 3 stack args | **High** | ABI crash |
| ECX = map shell (not grid) | **High** | Wrong this in port |
| Val12 isnil@+0x19 | **High** | Wrong node family |
| FreeSubtree full path | **High** | Leak / double free |
| Value dtor on full free | **Med** | Leak of non-POD T if any |
| InventoryGrid shell @+0x5c | **High** | Field map error |
| Product plate English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```text
// Complete dtor 005725a0 @ 005725e9:
//   head = [EDI+0x60]
//   ESI  = EDI+0x5c          // map shell
//   push head; push *head; push &out; ECX=ESI
//   CALL 00573700            // full [begin,end)
//   operator_delete(head)

// Map-shell dtor 005738d0:
//   EraseRange(this, &tmp, *head, head); operator_delete(head)

// AutoMerge 00572ab0 @ 00572e71:
//   EraseRange(local_map, …); operator_delete(mapHead)

// Peer W32-C 0040d700: identical CF skeleton, 180 B, RET 0xC
// Single erase dual W27-S 00573250: RET 8, isnil@+0x19
```

Live decompile 2026-08-05 **≡** raw 2026-07-23; body hex seals size + dual RET.

Entry hex (leading):  
`53 8B 5C 24 10 56 8B 74 24 10 57 8B F9 8B 47 04 3B 30 75 36 3B D8 75 32 … C2 0C 00`

---

## 4. Surviving contract for AutoCore

```c
// Port as MSVC tree range erase (InventoryGrid Val12 maps):
void StdTree_EraseRange_Val12_InventoryGrid(
    MapShell* m, Node** out, Node* first, Node* last)
{
  if (first == m->head->left && last == m->head) {
    FreeSubtree(m->head->parent);   // FUN_005731c0
    reset head; m->size = 0; *out = m->head->left; return;
  }
  while (first != last) {
    Node* next = successor(first);  // isnil@+0x19
    StdTree_Erase_Val12(m, first);  // 00573250
    first = next;
  }
  *out = first;
}
// RET 0xC. ECX = map shell (grid+0x5c), NOT InventoryGrid*.
// Do not invent value vtbl destroy on full path.
// Pair free 005731c0 + dualed erase 00573250.
// Do not collapse with peer 0040d700 (different free/erase leaves).
```

---

## 5. Falsified / rejected names

| Rejected | Why |
|---|---|
| `InventoryGrid_DestroyItemList` as sole canonical | Product-facing full-clear alias only; body is generic range erase |
| `Named_CalleeOf_*` plates | Xref-seed noise; retire |
| `Map_EraseNode` / single-erase | Wrong arity + CF (no successor loop) |
| Isnil15 / Isnil1d / Isnil29 / Isnil31 erase-range | Wrong isnil offset |

---

## 6. Verdict

Adversarial pass confirms A on ABI/CF/Val12/InventoryGrid shell ownership/peer shape. Residual product T + free-subtree dual + runtime → **accept-with-gaps**. Terminal **false**.
