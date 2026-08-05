# Review B (skeptical / adversarial): `aa_004e1830` LockedList_TryAdvanceIterator_Loot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1830` |
| **VA** | `0x004e1830` |
| **Canonical name** | `LockedList_TryAdvanceIterator_Loot_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-T) |
| **Counterpart** | `reviews/A_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md` |
| **System** | combat-loot / locked list walk |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Blocking `EnterCriticalSection` | Body uses **Try**Enter only | **Falsified** |
| 2 | Always starts at head | Only when `*cursor==0` | **Falsified** |
| 3 | Mutates list membership / removes nodes | Only cursor + payload outs | **Falsified** |
| 4 | Return 0 always means “error” | 0 = yielded element; 1 = end; lock-fail = `0x80070005` | **Falsified** |
| 5 | Flag off returns 0 (success) | Flag off falls to `0x80070005` | **Falsified** (cf. one wrong twin review note) |
| 6 | Same body as `0x004022a0` byte-identical | Twin has SEH frame; this does not | **Falsified** identical-bytes |
| 7 | Awards XP / gives items | Iterator only; parents roll/give | **Falsified** domain bleed |
| 8 | `stdcall` three stack args / no this | ECX=list; `ret 8` | **Falsified** |
| 9 | Product name “LootList” proven | Callers are loot-domain; type name open | **Agree Open** |
| 10 | Leaves CS held on yield | Leave on every success path before return | **Falsified** hold-across-yield |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Return code contract 0/1/`0x80070005` | **Confirmed** | Caller loops invert |
| Offsets +4 CS / +0x1C head / +0x28 flag | **Confirmed** | Wrong lock or empty walk |
| Node +4 payload / +8 next | **Confirmed** | Wrong row id/payload |
| Non-blocking TryEnter | **Confirmed** | Deadlock if assumed blocking |
| Product container name | **Open** | Naming only |
| “Loot” in human name | **Probable** | Over-narrow if shared type |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
if (list+0x28) {
  if (TryEnter(list+4)) {
    if (*cursor==0) { seed head; return head==0; }
    if (cursor->next) { advance; return 0; }
    clear; return 1;
  }
}
return 0x80070005;
```

Entry hex: `53 55 56 57 8b 7c 24 14 8b 1f 8b f1 80 7e 28 00` — cursor in EDI, `*cursor` in EBX, this in ESI, flag test.

Fail exit: `b8 05 00 07 80 5b c2 08 00` = `mov eax,0x80070005; pop ebx; ret 8`.

**Trap:** callers treat **non-zero** as stop (end **or** lock fail). `KillLoot_RollTableItems` checks `done != 0` then unlocks/destroys — lock-fail may look like “done”. Server ports should distinguish `1` vs `0x80070005` even if retail folds them.

**Trap:** do not port as `EnterCriticalSection` — TryEnter can fail under contention and returns ACCESS_DENIED-style code.

**Trap:** not the same symbol as inventory `List_IterateNext` (`0x004022a0`); keep separate VA hooks if binary-patching.

---

## 4. Surviving contract for AutoCore

```c
// Port of LockedList_TryAdvanceIterator_Loot_Inferred (aa_004e1830)
// Retail: thiscall list*; stack cursor*, out*; ret 8
enum { YIELD = 0, END = 1, LOCK_FAIL = 0x80070005 };

uint32_t LockedList_TryAdvance(List *list, Node **cursor, void **outPayload) {
  if (!list->traversal_enabled) return LOCK_FAIL;          // +0x28
  if (!TryEnterCriticalSection(&list->cs)) return LOCK_FAIL; // +4
  if (*cursor == nullptr) {
    *cursor = list->head;                                    // +0x1C
    *outPayload = list->head ? list->head->payload : nullptr; // node+4
    LeaveCriticalSection(&list->cs);
    return list->head ? YIELD : END;
  }
  if ((*cursor)->next) {
    *cursor = (*cursor)->next;                               // node+8
    *outPayload = (*cursor)->payload;
    LeaveCriticalSection(&list->cs);
    return YIELD;
  }
  *cursor = nullptr;
  *outPayload = nullptr;
  LeaveCriticalSection(&list->cs);
  return END;
}
```

- Server: prefer one shared C++ iterator helper for both twins; keep VA distinction only for hooks.
- Pair with parent lock/unlock wrappers (`FUN_0050eec0` family) — this unit **re-enters** CS each step.
- Do not invent loot roll math here.

---

## 5. Open questions

1. Product/PDB type name of list / node.
2. Why no SEH vs `0x004022a0` (exception policy).
3. Runtime: concurrent writer during kill-loot walk.
4. Whether `FUN_0050a7d0` / `FUN_004d5c10` share the same list element type as kill-loot rows.

**Verdict:** **accept-with-gaps**
