# Review B (skeptical / adversarial): `aa_004027f0` StdList_PushFront_DwordFromEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004027f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY dual **MEGA-089**) |
| **Counterpart** | `reviews/A_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `get_assembly_context` + callers/xrefs. No Launcher. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Exclusive callee of `Client_RecvCreateCharacter` only | **Falsified** — **7** callers / **8** xrefs (vehicle create, give-item, UI hosts, …) |
| 2 | `__thiscall` with ECX = list | **Falsified** — list from `[ESP+8]` after push EBX; ECX used only as temp for head→next / later as `_Incsize` delta |
| 3 | Value is second stack arg | **Falsified** — value ptr is **EAX** (`PUSH EAX` into buynode); only one stack arg (`RET 4`) |
| 4 | `push_back` / insert-before-head | **Falsified** — `_Buynode(head, head->_Next, val)` + `head->_Next = node` is **push_front** / insert-at-begin |
| 5 | Same as `CsSList_AppendPayload` (`aa_004024d0`) | **Falsified** — no CS, doubly-linked 0xC node with prev/next/val, size at list+8 via length_error path |
| 6 | Same as sibling `FUN_00402d10` ABI | **Falsified as identical** — sibling is thiscall + stack val + `FUN_00404840` size helper; CF shape similar but ABI/size path differ |
| 7 | Map/set tree insert | **Falsified** — `"list<T> too long"` in `FUN_00418790`; node size 0xC circular list |
| 8 | Product English name known | **Unproven** — `_Inferred` required |
| 9 | Returns useful value in EAX | **Unproven / unused** — void-like; EAX after body is last link temp; callers ignore |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack list* + RET 4 | **High** | Wrong calling convention in port |
| EAX = const dword* | **High** | Silent wrong value / stack smash if modeled as stack arg |
| push_front link math | **High** | Corrupted circular list |
| Distinct from CsSList / LockedList | **High** | Wrong CS / node layout |
| Element is always object* | **Med** | Hosts store dword; type English open |
| Null buynode safe | **Weak** | Retail may crash on OOM — do not "fix" in clean |
| English class name | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes

```
list = [esp+4]
head = list->_Myhead            // +4
node = buynode(head, head->next, *eax_val)  // 0xC
_Incsize(list, 1)               // may throw length_error
head->next = node
node->next->prev = node
ret 4
```

Call-site pattern (RecvCreateCharacter / FUN_0080af70):

```
lea  reg, [this + list_off]   ; 0xf08 / 0xefc / 0xaa8
push reg                      ; list*
lea  eax, [esp + local]       ; &dword
mov  [local], object*
call FUN_004027f0
```

Clean must **not** invent thiscall, CS, push_back, or RecvCreateCharacter-only naming.

---

## 4. Surviving contract for AutoCore

```
// Port sketch — std::list push_front of a 4-byte element
// ABI quirk: value pointer arrives in EAX; list on stack; ret 4.
void StdList_PushFront_Dword(List* L, const uint32_t* val) {
  Node* head = L->myhead;           // +4
  Node* node = Buynode(head, head->next, *val); // new 0xC
  Incsize(L, 1);                    // +8; throw if too long
  head->next = node;
  node->next->prev = node;
}
```

Pair with:

- `FUN_00418700` buynode / `FUN_00418790` incsize
- Dualed `Std_LengthError_CtorFromString` (`0x00401a40`) on overflow path inside incsize
- Do **not** merge with `CsSList_AppendPayload` or skill LockedList families

---

## 5. Open questions

1. Element type English per host (character inventory-of-objects list vs mission UI list @ `+0xaa8`).
2. Whether any caller relies on EAX after return (none observed).
3. OOM null-node crash vs guarded higher frame.

**Verdict:** Structural list push_front contract sealed; multi-caller; product names inferred. **accept-with-gaps.**
