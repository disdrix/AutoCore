# Review B (skeptical / adversarial): `aa_005738d0` StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005738d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-004 OWN dual) |
| **Counterpart** | `reviews/A_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` |
| **System** | inventory-transfer / MSVC tree bare tidy Val12 |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after `operator_delete` drops null head/size + RET; **bytes win** |
| 2 | This is InventoryGrid complete dtor (ECX=grid) | **Falsified** — no vtbl install; frees **head** only; unwind does `ADD ECX,0x5c` before JMP (shell, not grid base) |
| 3 | Same function as complete dtor `005725a0` | **Falsified** — complete dtor inlines erase+delete with SEH; this is bare tidy leaf used by unwind |
| 4 | Same instance as peer `0040d6d0` | **Structural yes, instance no** — 45 B hex clone with different CALL relocs (erase=`00573700` vs `0040d700`) |
| 5 | `local_4 = param_1` is semantic | **Falsified as value** — `push ECX` only allocates out slot; erase overwrites |
| 6 | Erases partial range | **Falsified** — args are `*head` and `head` (full-range gate in `00573700`) |
| 7 | Frees the map shell / grid object | **Falsified** — nulls facade fields after free head; shell lifetime owned by host |
| 8 | Has SEH frame like `0040d7c0` | **Falsified** — bare 45 B, single BB, no ExceptionList |
| 9 | Product map type sealed | **Careful** — structural Val12 + InventoryGrid owner only; demangle open |
| 10 | Direct product CALL sites | **Careful** — analyze shows unwind-only xrefs; complete dtor inlines same order without calling this |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tidy order erase→delete head→null | **High** | Use-after-free / leak |
| ABI ECX + bare RET | **High** | Stack imbalance |
| Not host free | **High** | Double free host |
| Full-range only (via erase args) | **High** | Wrong residual nodes |
| InventoryGrid shell @+0x5c | **High** | Field map error |
| No SEH in this body | **High** | Wrong twin pairing |
| Product plate English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```text
// Peer bare tidy 0040d6d0 (W33-A):
//   same skeleton; erase=0040d700; 45 B; bare RET

// This 005738d0:
//   erase=00573700 (InventoryGrid); operator_delete; null; RET

// Complete dtor 005725a0 (not this VA):
//   SEH; FUN_00573700(grid+0x5c, full); operator_delete(head) inline
//   does NOT CALL 005738d0

// Unwind@009a4f37:
//   MOV ECX,[EBP-14]; ADD ECX,0x5c; JMP 005738d0
// Unwind@009a4f57:
//   MOV ECX,[EBP-10]; ADD ECX,0x5c; JMP 005738d0
```

Live decompile 2026-08-05 **≡** raw 2026-07-23 truncate shape; 45 B hex seals post-delete.

Entry hex:  
`51 56 8B F1 8B 46 04 8B 08 50 51 8D 44 24 0C 50 8B CE E8 19 FE FF FF … 5E 59 C3`

---

## 4. Surviving contract for AutoCore

```c
// Port as bare tree tidy (no SEH) for InventoryGrid Val12 maps:
void StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid(MapShell* m) {
  void* out;
  Node* head = m->head;
  StdTree_EraseRange_Val12_InventoryGrid(m, &out, head->left, head); // full
  operator_delete(head);
  m->head = nullptr;
  m->size = 0;
}
// ECX = map shell (object+0x5c), NOT InventoryGrid*.
// Do not free m itself. Do not collapse with peer 0040d6d0 (different erase leaf).
// Pair with dualed erase 00573700. Complete dtor 005725a0 may inline same order.
```

---

## 5. Falsified / rejected names

| Rejected | Why |
|---|---|
| `InventoryGrid_CompleteDtor` | Wrong unit — residual `005725a0` owns complete dtor |
| `InventoryGrid_DestroyItemList` | Product full-clear alias for erase range, not this tidy |
| Free-this / scalar deleting dtor | No `operator_delete(this)`; dualed scalar is `00573910` |
| Partial erase wrapper | Args force full-range gate in erase leaf |
| Same VA as `0040d6d0` | Separate clone instance |

---

## 6. Verdict

Adversarial pass confirms A on tidy order/ABI/epilogue/InventoryGrid shell ownership/peer shape. Residual product T + unwind frame class English + runtime → **accept-with-gaps**. Terminal **false**.
