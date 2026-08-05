# Review B (skeptical / adversarial): `aa_004024d0` CsSList_AppendPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004024d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual W18-B) |
| **Counterpart** | `reviews/A_aa_004024d0_CsSList_AppendPayload_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same type as `LockedList_InsertPayloadTail` (`aa_0041c7e0`) | **Falsified** — different layout: this list head/tail at `+4/+8`, CS at `+0x10`; LockedList uses head `+0x1C`, CS at `+4`, doubly-linked |
| 2 | Doubly-linked insert | **Falsified** — only `node+8` next; no prev write |
| 3 | Count bumped under the same CS | **Falsified as “under”** — `InterlockedIncrement` runs **after** Leave in `FUN_00402598` |
| 4 | Always takes both critical sections | **Falsified** — outer `+0x28` only when `count ≤ 3` |
| 5 | Null payload still allocates | **Falsified** — early `ret 4` with AL=0 |
| 6 | `__stdcall` two stack args | **Falsified** — thiscall ECX + one stack; `ret 4` |
| 7 | Head at list+0 | **Falsified** — head at `+4`, tail at `+8` |
| 8 | Product name known | **Unproven** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tail-append + CS primary | **High** | Concurrent list corruption in ports |
| Interlocked count after unlock | **High** | Mis-model lock scope |
| Distinct from skill LockedList | **High** | Wrong freelist/node size in shared helper ports |
| Outer CS gate | **High** | Deadlock / missing lock under shallow lists |
| Node 0xC + vtbl imm | **High** | Wrong allocator size |
| English class name | **Low** | Naming only |
| OOM path safe | **Weak** | Raw may write null node — residual |

---

## 3. Cross-check against raw + bytes

```
if payload==0: return 0 (AL)
node = new(0xC); vtbl=009cb340; next=0; payload=arg
if count<=3: Enter(list+0x28)
Enter(list+0x10)
if tail==0: head=tail=node
else: tail->next=node; tail=node
Leave(+0x10) [+ outer]; InterlockedIncrement(count); return 1
```

Clean must **not** invent prev links, freelist vtbl alloc, or LockedList offsets. Parent `Object_EnqueueDeferredOnce` only needs “append payload once” contract.

---

## 4. Surviving contract for AutoCore

```
// Port sketch — CsSList_AppendPayload (client deferred / spawn lists)
// NOT the skill LockedList (aa_0041c7e0).
bool Append(CsSList* L, void* payload) {
  if (!payload) return false;
  Node* n = new Node; // 0xC: vtbl, payload, next
  n->payload = payload; n->next = nullptr;
  if (L->count <= 3) EnterCS(&L->outerCS); // +0x28
  EnterCS(&L->cs);                           // +0x10
  if (!L->tail) L->head = L->tail = n;
  else { L->tail->next = n; L->tail = n; }
  LeaveCS(&L->cs);
  if (outer) LeaveCS(&L->outerCS);
  InterlockedIncrement(&L->count);           // +0x0C
  return true;
}
```

---

## 5. Open questions

1. Who frees nodes and clears deferred bit0 on objects.
2. Whether outer CS is a “startup” lock shared with another subsystem.
3. Product symbol for `PTR_FUN_009cb340`.

**Verdict:** Structural contract sealed; distinct from LockedList family. **accept-with-gaps.**
