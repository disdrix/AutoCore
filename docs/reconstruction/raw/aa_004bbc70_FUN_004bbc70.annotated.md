# Annotated low-level: FUN_004bbc70 → COList_Destructor

| Field | Value |
|---|---|
| Stable ID | `aa_004bbc70` |
| VA | `0x004bbc70`–`0x004bbea4` (**565 B**) |
| System | client / COList (cloned-object list host) |
| Date | 2026-07-29 (W26-J re-annotate; scaffold 2026-07-23) |

## Machine-level notes

- **Role:** C++ destructor body for **COList** (product strings on vtbl rdata: `COList::Insert`).
- **ABI:** frame `sub esp,0x44`; ESI=`this` from ECX; bare `ret` after `add esp,0x44`.
- **Vtbl:** `*this = PTR_FUN_009cb448` at entry.
- **Scalar deleting wrapper:** `FUN_004bd1b0` → this body; if `(flags & 1)` then `operator_delete(this)`; `ret 4`. Vtbl[0] = `0x004bd1b0`.
- **Ctor twin:** `FUN_004bbfb0` same vtbl; `Client_InitInstance` publishes `DAT_00b04830`.

### Stack ThreadSafeObjectList (not a member)

Bytes construct a **stack** list with sealed layout (`aa_0040b020` / `aa_004bcbf0` / `aa_004024d0`):

| Off | Init |
|----:|---|
| +0x00 | `PTR_FUN_009cb368` |
| +0x04/+0x08/+0x0C | head/tail/count = 0 |
| +0x10 / +0x28 | `InitializeCriticalSection` |

Decompiler surfaces ICS as `local_34` / `local_1c`; PopFront/Dtor/Append target this stack object via `lea ecx,[esp+…]`.

### Hash traversal (members `this+4`, `this+8`)

CNDHash-style:
- lock byte `hash+0x1d` (`HashError:TraversalLock` / `TraverseToNext`)
- first node from `hash+0x14`; next via `node+0x20`
- payload at `node+0x0C`
- if `payload+0xac != 0` → `CsSList_AppendPayload` (`FUN_004024d0`) onto **stack list**

### Drain

```
payload = PopFront(stackList)
while payload:
  ClonedObjectList_TakeByCoid(this, payload+0x168 /*mode*/, payload+0x160, payload+0x164)
  payload = PopFront(stackList)
```

(`FUN_004bb970` dual: TakeByCoid; `ret 0xC`.)

### Owned teardown

Virtual-delete (`(*vtbl)(obj,1)`) then null:
- dword indices **6, 7, 8, 9, 1, 2**

Then `ThreadSafeObjectList_Dtor(stackList)` (`FUN_004bcbf0`).

Then free buffer triples (begin/end/cap zero):
- indices **0x13..0x15**, **0x0f..0x11**, **0x0b..0x0d**

## Pseudocode (annotated)

```c
// __thiscall  ECX = COList* this
void COList_Destructor(COList *self)
{
  *self = (void*)0x009cb448;   // PTR_FUN_009cb448

  ThreadSafeObjectList stackList; // construct on stack (vtbl 0x009cb368 + dual CS)

  // traverse self->hashA (self[1]) and self->hashB (self[2]):
  //   for each object with object+0xac != 0: AppendPayload(&stackList, object)

  // while (payload = PopFront(&stackList))
  //   TakeByCoid(self, *(u8*)(payload+0x168), *(u32*)(payload+0x160), *(u32*)(payload+0x164))

  // virtual-delete self[6], [7], [8], [9], [1], [2]

  ThreadSafeObjectList_Dtor(&stackList);

  // operator_delete buffer triples at [0x13], [0xf], [0xb] (+ companion end/cap zeros)
}
```

## Open questions

- Product English for hash members / vector slots beyond COList class name.
- Exact alloc size of COList instance (ctor fields through ~+0x54).
- Runtime / bit-exact.
