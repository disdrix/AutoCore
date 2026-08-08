# Review B (skeptical / adversarial): `aa_00440c90` StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-131) |
| **Counterpart** | `reviews/A_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn after value dtor; real body is left-walk loop (59 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded (`MOV EBX,ECX`); **`RET 4`** |
| 3 | This is clear-shell (hint name) | **Falsified** — no head-link reset / size=0 here; parents do that after CALL |
| 4 | Same as `Map_FreeSubtree_Isnil1d` | **Falsified** — extra `FUN_00442730` value destroy; 59 B vs 53 B |
| 5 | Same as shell+0x04 free `FUN_00440ab0` | **Falsified** — isnil imm `0x1d` vs `0x3d`; different value dtor |
| 6 | Frees including isnil sentinel | **Falsified** — isnil@+0x1d gate returns without delete |
| 7 | thiscall with no stack arg | **Falsified** — stack node + RET 4 |
| 8 | Product gfxUIWindow method | **Reject** — generic STL free-subtree; host is shell subobject |
| 9 | `Named_CalleeOf_Named_gfxUIWindow_*` | **Reject** — parent-seed scaffold; structural free-subtree sealed |
| 10 | Value is plain `T*` / string only | **Falsified** — `FUN_00442730` erases nested tree at node+0x10 then deletes head |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape + left walk | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right @ +0x1d/+0/+8 | **High** | Wrong walk |
| Value destroy before delete | **High** | Nested leak if skipped |
| Embedded tree @ node+0x10 | **High** (callee disasm) | Wrong nested layout |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against gfxUIWindow_CompleteDtor shell@+0x10

```
// gfxUIWindow_CompleteDtor @ 0x00759e10..0x00759e38:
//   MOV EAX,[ESI+0x14]        ; head = shell+4
//   MOV ECX,[EAX+0x4]         ; root = head->parent
//   LEA EDI,[ESI+0x10]        ; tree shell @ this+0x10
//   PUSH ECX
//   MOV ECX,EDI
//   CALL FUN_00440c90         ; THIS free-subtree
//   ; then head self-links + size=0  (clear-shell tail — NOT in this VA)
```

Same clear-shell tail pattern after CALL at `FUN_00758c80` @ `0x00758d76` and erase full-clear `FUN_00441720` @ `0x0044173a`.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper with value destroy (not clear, not product method):
void StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10(
    void* tree_shell /*unused*/, NodeIsnil1d* n)
{
  if (n->isnil@0x1d) return;
  while (!n->isnil@0x1d) {
    FreeSubtree(tree_shell, n->right);
    NodeIsnil1d* L = n->left;
    DestroyEmbeddedTreeAt10(n);  // FUN_00442730 EAX=n
    operator_delete(n);
    n = L;
  }
}
// Call from clear-shell: free(head->parent); then reset head links; size=0.
// Ignore Ghidra noreturn on operator_delete.
// Keep separate from Map_FreeSubtree_Isnil1d (no dtor) and FUN_00440ab0 (isnil3d).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/value-dtor/callers. Residual product types + nested free duals → **accept-with-gaps**.
