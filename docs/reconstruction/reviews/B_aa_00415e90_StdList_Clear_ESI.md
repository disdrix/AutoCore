# Review B (skeptical / adversarial): `aa_00415e90` StdList_Clear_ESI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00415e90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9L-H) |
| **Counterpart** | `reviews/A_aa_00415e90_StdList_Clear_ESI.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Body frees only the first node | **Falsified** — bytes have full free loop (`JNE` back); decompiler noreturn artifact only |
| 2 | Frees sentinel | **Falsified** — loop condition `node != head`; sentinel re-ringed |
| 3 | Standard ECX thiscall | **Falsified** — entry uses **ESI**; no `MOV ESI,ECX` prologue (that is twin `00404060`) |
| 4 | Same VA as `StdList_Clear_Inferred` | **Falsified** — different VA; twin is ECX wrapper of same algorithm |
| 5 | Frees the list shell object | **Falsified** — bare RET; no `operator_delete(list)` |
| 6 | Calls element value dtors | **Falsified** — only `operator_delete` on node* |
| 7 | Enters critical section | **Falsified** — no CS (contrast locked-list helpers) |
| 8 | Size field is @+4 | **Falsified** — size store `MOV [ESI+8],0`; head @+4 |
| 9 | Safe on empty list | **Survives** — `first==head` skips loop |
| 10 | CNDUIDialog-only helper | **Falsified** — ~78 xrefs; shared leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = list clear (not destroy-free-head) | **High** | leak sentinel or double-free head |
| ESI ABI | **High** | broken port if rewritten as ECX without site rewrite |
| Multi-node free | **High** | leak if port keeps decompiler single-delete |
| Element type / owned nested | **Open** | wrong dtor policy if nodes own pointers |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_00415e90:
// ESI = list*
mov  ecx, [esi+4]       ; head
mov  eax, [ecx]         ; first = head->next
mov  [ecx], ecx         ; head->next = head
mov  ecx, [esi+4]
mov  [ecx+4], ecx       ; head->prev = head
cmp  eax, [esi+4]
mov  dword ptr [esi+8], 0
je   done
push edi
loop:
mov  edi, [eax]         ; next
push eax
call operator_delete
add  esp, 4
cmp  edi, [esi+4]
mov  eax, edi
jne  loop
pop  edi
done:
ret
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF (truncated free). Full loop sealed by `read_memory`.  
Dialog site: `LEA ESI,[EDI+0x4dc]; CALL 00415e90; MOV EAX,[ESI+4]; PUSH EAX; CALL delete` — clear then free sentinel.

---

## 4. Surviving contract for AutoCore

```
// Port with ESI=list* (or rewrite call sites to pass list*):
void StdList_Clear_ESI(ListShell* list) {
  Node* head = list->head;
  Node* node = head->next;
  head->next = head->prev = head;
  list->size = 0;
  while (node != head) {
    Node* next = node->next;
    operator_delete(node);
    node = next;
  }
}
// Do NOT free head/sentinel here; do NOT free list shell.
// Twin ECX form: 0x00404060. Destroy_FreeHead is a different unit.
```

**Gaps (honest):** element `T` / node size product English; whether any site needs value dtor before free (this leaf does not call one).

**Verdict:** **accept-with-gaps**.
