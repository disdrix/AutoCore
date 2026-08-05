# Review B (skeptical / adversarial): `aa_00566f00` CNDDoubleList_InsertTail_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00566f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00566f00_CNDDoubleList_InsertTail_Inferred.md` |
| **System** | `inventory-transfer` + generic list |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + layout; **reject** inventory-only naming, “returns success bool”, and scaffold `VOG_DEBUG_STOP` product name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This stamps footprint cells | **Falsified** — only list link; stamp is `0x00571620` |
| 2 | Product name is `VOG_DEBUG_STOP` | **Falsified** — string only on locked assert path |
| 3 | Insert at head (push_front) | **Falsified** — new node becomes `tail (+0x20)`; old tail `.next=+8` updated |
| 4 | Returns 1 on success | **Falsified** — `XOR EAX,EAX` → **0** |
| 5 | Inventory-only helper | **Falsified** — callers include spawn / `0x00572730` / thin wrappers |
| 6 | `this` is the item | **Falsified** — place: `LEA ECX,[EDI+0x2c]` (grid list subobject) |
| 7 | Singly-linked list | **Falsified** — writes both `+8` and `+0xc` (next/prev) |
| 8 | Silently fails if locked | **Falsified** — throws `0x80070005` after `VOG_DEBUG_STOP` |
| 9 | Null alloc returns 0 | **Falsified** — throws `0x8007000e` |
| 10 | Ready for bit-exact complete | **Fail** — runtime/diff open; method name open |
| 11 | Same as TraversalLock iterate API | **Partial** — same host layout; this is **mutate-under-CS**, not TraversalLock API |

---

## 2. Decisive dataflow (bytes 2026-07-29)

```
list = ECX; payload = [EBP+8]
EnterCriticalSection(list+4)
if *(u8*)(list+0x28) != 0:
  FUN_007a4480(0, "VOG_DEBUG_STOP")
  throw 0x80070005
node = list->vtbl[1](0)          // [vtbl+4]
if node == 0: throw 0x8007000e
if *(list+0x1c) == 0: *(list+0x1c) = node   // head
node+0xc = *(list+0x20)                     // prev = old tail
if *(list+0x20): *(*(list+0x20)+8) = node   // old_tail.next = node
*(node+4) = payload
*(list+0x24)++
*(list+0x20) = node                         // tail
LeaveCriticalSection(list+4)
return 0
// RET 4
```

### Layout attack (vs sibling seals)

| Field | This unit | `aa_004e2600` remove | IterateNext `0x004022a0` | Result |
|-------|-----------|----------------------|--------------------------|--------|
| CS | `+4` | `+4` | `+4` | **Same** |
| Head | `+0x1c` | `+0x1c` | `+0x1c` | **Same** |
| Tail | `+0x20` | `+0x20` (unlink) | — | **Same** |
| Count | `+0x24` | `+0x24` | — | **Same** |
| Busy/lock | `+0x28` | `+0x28` | must be set for iterate | **Same family** |
| Node payload | `+4` | `node[1]` | `node+4` | **Same** |
| Node next | `+8` | `node[2]` | walk `+8` | **Same** |
| Node prev | `+0xc` | `node[3]` | — | **Same** |

**Conclusion:** Same CNDDoubleList-shaped host as remove dual. Inventory place host base = `grid+0x2c` (place + Contains duals).

### Direction attack (head vs tail)

| Hypothesis | Prediction | Observation |
|------------|------------|-------------|
| push_front | head = new always; old head prev → new | head set **only if empty**; **tail** always = new |
| push_back | tail = new; old_tail.next = new | **Matches** |
| insert-middle | needs cursor arg | **No** second pointer arg (`RET 4` only payload) |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Append CF | **Confirmed** | Wrong list order / UI enumeration |
| Offsets head/tail/count | **Confirmed** | Corruption on place |
| Place `this=grid+0x2c` | **Confirmed** | Call into wrong object |
| Return value 0 | **Confirmed** | Callers treating AL as bool success misread |
| Throws on lock/OOM | **Confirmed** | Silent fail ports |
| CNDDoubleList family | **High** | Name overclaim without RTTI string this pass |
| Method product name | **Open** | Docs only |
| Allocator vtbl identity | **Open** | Port may use wrong free pairing |
| Runtime | **Open** | Residual parity |
| Bit-exact complete | **Fail** | Policy |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `param_1[7]` head | Invented? | **No** — `CMP [ESI+0x1c]` / `MOV [ESI+0x1c],EAX` |
| `param_1[8]` tail | Invented? | **No** — `+0x20` loads/stores |
| `param_1[9]` count | Invented? | **No** — `ADD [ESI+0x24],1` |
| Lock is CS itself | Flag? | **No** — separate `byte +0x28` |
| `RET 0` (cdecl) | ABI? | **No** — `C2 04 00` |
| Success `return 1` | Decompiler? | **No** — `XOR EAX,EAX` |
| Inventory cell write | Hidden? | **No** — no cell base / `IMUL` / COID stores |
| Only Place caller | Exclusive? | **No** — six Ghidra callers |

---

## 5. Surviving contract for AutoCore

```
// Host: CNDDoubleList-shaped object (InventoryGrid embeds at +0x2c)
// Node: { vtbl?, payload@+4, next@+8, prev@+0xc }  — payload/next/prev sealed
InsertTail(list, payload):
  CS enter list+4
  if traversal_locked: throw E_ACCESSDENIED
  node = list.AllocateNode(0)   // vtbl+4; throw E_OUTOFMEMORY if null
  link as new tail; count++
  CS leave
  return 0
```

**Port notes:**

- Do **not** call while TraversalLock (`+0x28`) is held — client throws.
- Place path: after cell stamp (or type-4 light path), append item* then set item flag `|0x10`.
- Contains (`0x00571b60` → `0x00415c00`) walks the same list for membership — not cell COIDs.

---

## 6. Verdict

### **accept-with-gaps**

Adversarial review **confirms** append-at-tail on CNDDoubleList layout and place’s `grid+0x2c` this-pointer. **Rejects** stamp-role, VOG product name, head-insert, bool success, and inventory-exclusive claims.

**Gaps kept open:** product method mangling, exact template RTTI for inventory list, node allocator symbol, runtime list dump, bit-exact.
