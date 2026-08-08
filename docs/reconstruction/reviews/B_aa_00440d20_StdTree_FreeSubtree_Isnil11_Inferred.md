# Review B (skeptical / adversarial): `aa_00440d20` StdTree_FreeSubtree_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440d20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-132) |
| **Counterpart** | `reviews/A_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn; real body is left-walk loop (53 B) |
| 2 | Bare cdecl `void(node*)` only | **Falsified** — ECX threaded (`MOV EBX,ECX`); **`RET 4`** |
| 3 | This destroys `T*` values / calls value dtor | **Falsified** — no payload load / no intermediate CALL (unlike `00440ab0`/`00440c90`) |
| 4 | Frees including isnil sentinel | **Falsified** — isnil@+0x11 returns without delete |
| 5 | Same function as shell clear / erase-all parent | **Falsified** — this is free-subtree only; shell reset + size=0 live in callers |
| 6 | isnil@+0x19 Val12 free | **Falsified** — displacement is `0x11` (`80 7F 11 00`) |
| 7 | isnil@+0x29 FreeSubtree merge | **Falsified** — same CF shape, **distinct VA** / isnil offset / callers |
| 8 | Product name `Named_CalleeOf_Named_gfxUIWindow_*` | **Reject** — parent-chain scaffold only |
| 9 | thiscall on node in ECX | **Falsified** — ECX is tree_base; node is stack arg |
| 10 | Right-only free (no left) | **Falsified** — `MOV ESI,[ESI]` then loop on left |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree shape | **High** | Leak / double free |
| ABI ECX + RET 4 | **High** | Stack corruption |
| isnil/left/right layout | **High** | Wrong walk |
| No value destroy here | **High** | Missed dtor if assumed |
| Host shell `@+0xA4` role | **High** (call-site LEA) | Naming only if generalized |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against host clear paths

```
// gfxUIWindow_CompleteDtor (00759de0) @ shell +0xA4:
//   LEA EBP,[ESI+0xA4]
//   PUSH head->parent
//   MOV ECX,EBP
//   CALL FUN_00440d20          // free subtree
//   self-link head L/P/R; size=0

// FUN_00759090:
//   FUN_00440d20(*( *(param+0xa8) + 4 ));  // head->parent
//   reset head; size@+0xac = 0

// FUN_00441960 full clear:
//   if first==head->left && last==head:
//     FUN_00440d20(head->parent); reset; size=0
//   else: successor + erase node (FUN_004477a0)
```

Host role matches partition **ClearShell_AtA4**; algorithm remains free-subtree.

---

## 4. Surviving contract for AutoCore

```
// Port as free-subtree helper (not erase-all, not value dtor):
void StdTree_FreeSubtree_Isnil11(void* tree_base /*unused*/, NodeIsnil11* n) {
  if (n->isnil /*@+0x11*/) return;
  while (!n->isnil) {
    StdTree_FreeSubtree_Isnil11(tree_base, n->right /*@+8*/);
    NodeIsnil11* L = n->left /*@+0*/;
    operator_delete(n);
    n = L;
  }
}
// ABI: ECX=tree_base, stack node*, RET 4.
// Keep distinct from isnil29 FreeSubtree twins and value-dtor siblings 00440ab0/00440c90.
// Ignore Ghidra noreturn on operator_delete.
// Shell self-link / size=0 stay in callers (00759de0 / 00441960 / 00759090).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/callers. Residual product types → **accept-with-gaps**.
