# Review B (skeptical / adversarial): `aa_00440ab0` StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440ab0` |
| **VA** | `0x00440ab0` |
| **Canonical name** | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` |
| **Review date** | `2026-08-05` (MEGA-130 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler CF is complete (single right-recurse then delete) | **Falsified** — full hex has left-walk loop after delete (`80 7E 3D 00` / `8B FE` / `74 DB`) |
| 2 | Bare `RET` / cdecl no cleanup | **Falsified** — epilogue **`C2 04 00`** (`RET 4`) |
| 3 | ECX = node; stack = tree | **Falsified** — body saves `MOV EBX,ECX` and never uses ECX as node; node from stack `MOV EDI,[ESP+0x10]`; call sites `MOV ECX,host` + `PUSH root` |
| 4 | Same as isnil1D peer `00440c90` | **Falsified** — different isnil (`+0x3D` vs `+0x1D`) and value trampoline (`00442720` vs `00442730`) |
| 5 | Same as isnil11 peer `00440d20` (delete-only) | **Falsified** — this unit calls value dtor before delete |
| 6 | Full tree clear (resets head/size) | **Falsified** — body has no stores to host head/size; callers reset after CALL |
| 7 | gfxUIWindow method body / scalar dtor | **Falsified** — leaf free-subtree worker; scalar peer is `004401b0`; complete is `00759de0` |
| 8 | Scaffold name `Named_CalleeOf_Named_gfxUIWindow_*` is product | **Falsified** — plate only; dual seals FreeSubtree structural name |
| 9 | isnil at +0x31 / +0x2D / +0x19 | **Falsified** — sole nil guard **`+0x3D`** (`80 7F 3D 00` / `80 7E 3D 00`) |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
MOV EDI, [ESP+0x10]          // node from stack
CMP BYTE PTR [EDI+0x3D], 0
MOV EBX, ECX                 // tree host
MOV ESI, EDI
JNZ epilogue
loop:
  MOV EAX, [ESI+8]           // right
  PUSH EAX
  MOV ECX, EBX
  CALL 00440ab0              // free right
  MOV ESI, [ESI]             // left
  MOV EAX, EDI
  CALL 00442720              // destroy val @ node+0x0C
  PUSH EDI
  CALL operator_delete
  ADD ESP, 4
  CMP BYTE PTR [ESI+0x3D], 0
  MOV EDI, ESI
  JZ  loop
epilogue:
  POP EDI / ESI / EBX
  RET 4
```

Call-site (gfxUIWindow complete @ `0x00759e6c`):

```text
LEA  EDI, [ESI+0x4]          // shell = this+0x04
MOV  EAX, [EDI+0x4]          // head
MOV  ECX, [EAX+0x4]          // root
PUSH ECX
MOV  ECX, EDI
CALL 00440ab0
// then: head.parent/left/right = head; size = 0
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-subtree CF (bytes) | **High** | leaks / double-free |
| isnil@+0x3D | **High** | wrong family merge |
| thiscall ECX=host + RET 4 | **High** | stack smash |
| Val destroy @+0x0C | **High** | resource leak |
| ClearShell_At04 call-site role | **High** | wrong shell offset |
| Product English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// Free subtree of isnil@+0x3D nodes with value @ +0x0C.
// ECX = tree host (threaded); stack = root node; RET 4.
void FreeSubtree(TreeHost host, Node node)
{
    if (node.IsNil) return; // isnil @ +0x3D
    for (;;)
    {
        FreeSubtree(host, node.Right);   // +0x08
        var left = node.Left;            // +0x00
        DestroyValueAt0C(node);          // trampoline 00442720 → 00440770
        operator_delete(node);
        node = left;
        if (node.IsNil) break;
    }
}
// Callers must empty-reset head/size after whole-tree free.
// Keep distinct from isnil1D (00440c90) and isnil11 (00440d20) peers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles; decompiler-only free path **rejected**. Residual product map/value English → **accept-with-gaps**.
