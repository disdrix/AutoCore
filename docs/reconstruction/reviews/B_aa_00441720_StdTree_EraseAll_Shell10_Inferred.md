# Review B (skeptical / adversarial): `aa_00441720` StdTree_EraseAll_Shell10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441720` |
| **VA** | `0x00441720` |
| **Canonical name** | `StdTree_EraseAll_Shell10_Inferred` |
| **Review date** | `2026-08-05` (MEGA-135 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **single-node erase** only | **Falsified** — full-clear free-subtree path + while-loop multi-node partial |
| 2 | isnil/color at +0x29/+0x28 or +0x31/+0x30 | **Falsified** — nil guards **`+0x1d`** only (`80 7E 1D 00` / `80 78 1D 00`) |
| 3 | Same as `Map_EraseRange_Isnil1d` `0x0051d700` | **Falsified** — different VA; free `00440c90` / erase `00442000` vs `0051be10`/`0051c880` |
| 4 | Same as isnil@+0x11 twin `00441960` | **Falsified** — isnil imm + free target differ (`00440d20`) |
| 5 | ECX-thiscall like isnil29 erase-range | **Falsified** — body starts `MOV EAX,[EDI+4]`; no `MOV EDI,ECX`; callers set **EDI** |
| 6 | `RET 4` / bare `RET` | **Falsified** — two **`C2 0C 00`** (`RET 0xC`) exits |
| 7 | gfxUIWindow method body (product UI) | **Falsified** — pure STL tree shell; UI is caller `00759de0` |
| 8 | Free-subtree is the only callee / no partial | **Falsified** — `CALL 00442000` in partial loop with saved victim in ECX |
| 9 | Shell size 0x20 or 0x38 node | **Falsified** — isnil@+0x1d ⇒ color@+0x1c ⇒ value span **0x10** (Shell10) |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
// Entry — tree in EDI, three stack args, RET 0xC
MOV EAX, [EDI+4]           // head
MOV EBX, [ESP+10]          // last  (after PUSH EBX)
MOV EBP, [ESP+0C]          // outIt (after PUSH EBP)
MOV ESI, [ESP+14]          // first (after PUSH ESI)
CMP ESI, [EAX]             // first == begin?
JNZ partial
CMP EBX, EAX               // last == end (head)?
JNZ partial
// full clear
MOV EAX, [EAX+4]           // root
PUSH EAX
MOV ECX, EDI
CALL 00440c90
// head reset + size 0 ...
RET 0xC

partial:
CMP ESI, EBX
JZ done
CMP BYTE PTR [ESI+0x1D], 0
MOV ECX, ESI               // victim
// ... successor on ESI ...
PUSH ECX
LEA EAX, [ESP+14]
PUSH EAX
PUSH EDI
CALL 00442000
// loop
done:
MOV [EBP], ESI
MOV EAX, EBP
RET 0xC
```

Call-site (`FUN_004401d0` @ `0x004401d0`):

```text
MOV EDI, EAX               // tree → EDI
MOV EAX, [EDI+4]           // head
MOV ECX, [EAX]             // begin
PUSH EAX                   // last = head
PUSH ECX                   // first = begin
LEA EAX, [ESP+0C]
PUSH EAX                   // outIt
CALL 00441720
// then operator_delete(head)
```

Call-site (gfx complete @ `0x0075a09c` region): same begin/end full-clear push pattern with tree in EDI.

A ≡ B on live decompile + body hex + xrefs + disassembly.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase-range CF (full + partial) | **High** | use-after-free / leak |
| isnil@+0x1d / Shell10 | **High** | wrong family merge |
| EDI-tree + RET 0xC | **High** | stack smash |
| Caller set (2 xrefs) | **High** | missing specialization |
| Product English | Medium | naming only |
| Partial path runtime exercised | Medium | only full-clear sites static |

---

## 4. Surviving contract for AutoCore

```csharp
// Range erase for isnil@+0x1d / value-shell 0x10 map tree.
// Retail: tree in EDI; stack (outIt, first, last); RET 0xC.
Node** EraseRange(MapShell tree, Node** outIt, Node* first, Node* last)
{
    var head = tree.Head;
    if (first == head.Left && last == head)
    {
        FreeSubtree(tree, head.Parent); // FUN_00440c90
        head.Parent = head.Left = head.Right = head;
        tree.Size = 0;
        *outIt = head.Left;
        return outIt;
    }
    while (first != last)
    {
        var victim = first;
        if (first.IsNil == 0)
            first = Successor(first); // isnil@+0x1d
        EraseNode(tree, ref tmp, victim); // FUN_00442000
    }
    *outIt = first;
    return outIt;
}
```

Do **not** merge with `0051d700` / isnil29 / isnil11 shells. Do **not** treat as UI method.

---

## 5. Gaps surviving attack

1. Product map `K/V` demangle for Shell10.
2. Callee duals residual.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
