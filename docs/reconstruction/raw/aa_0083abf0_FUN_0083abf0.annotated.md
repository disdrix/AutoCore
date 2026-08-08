# Annotated low-level: ShopVehList_BindSlotFromListIndexIfMismatch_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0083abf0` |
| VA | `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`) |
| Ghidra | `FUN_0083abf0` |
| Named | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` |
| System | shopveh list UI — bind slot entity from list index |
| Date | 2026-08-05 (WQ9L-J dual seal) |
| Evidence | `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |

---

## Machine-level notes

- **ABI (bytes):** **ECX** = slot index; **EDX** = list index; stack **host*** (`MOV EBP,[ESP+8]` after `PUSH EBP`); void; **`RET 4`**.
- Call sites in parent reindex always: `PUSH EBP` (host); `MOV ECX,ESI` (slot); `MOV EDX,EDI` (list_i); `CALL`.
- **Gates (fail → return):**
  1. `EDX (list_i) >= 0` (`TEST EDX` / `JL`)
  2. `host+0x508 != 0`
  3. `ECX (slot) >= 0` and `slot < 5`
  4. `slots[slot] = host+0x50c[slot] != 0`
  5. `*(int*)(*(host+0x508)+0x50) != 0`
- **List lookup:** `LEA EDI,[host+0x508 + 0x2c]` then `FUN_00427d20(list_i, &out_entity)` — EDI is the indexable list container (critical section + linked nodes; residual dual).
- **Entity id probe:** `entity->vtbl[+0x1d4]()` thiscall; non-zero required.
- **Mismatch / unbound:** if `slot+0x508 == 0` **OR** `slot+0x50c != entity_id` (second vtbl call when already nested), then:
  - third `vtbl+0x1d4` (leaves **EAX** = entity id for callee)
  - `PUSH host; MOV ECX,slot_obj; CALL FUN_0083ab90` (bind/refresh; ends with `FUN_0083a880(1)`).
- **Already matching bind:** compare equal → fall through to epilogue (no ab90).
- **Parent role:** reindex calls this when (a) window cell id already encodes list_i but `FUN_0083a860` fails, (b) no donor slot for swap, or (c) dead post-swap `CMP EBX,5` path.

## Pseudocode (annotated)

```c
// ECX = slot [0..4]; EDX = list_i; stack host*; RET 4
void ShopVehList_BindSlotFromListIndexIfMismatch_Inferred(
    int slot, int list_i, void *host)
{
  if (list_i < 0) return;
  void *nested = *(void **)((uint8_t *)host + 0x508);
  if (nested == nullptr) return;
  if (slot < 0 || slot >= 5) return;

  void *slot_obj = ((void **)((uint8_t *)host + 0x50c))[slot];
  if (slot_obj == nullptr) return;
  if (*(int *)((uint8_t *)nested + 0x50) == 0) return;

  // EDI = nested + 0x2c  (list container for FUN_00427d20)
  void *entity = nullptr;
  if (!FUN_00427d20(/*EDI=container*/ list_i, &entity)) return;
  if (entity == nullptr) return;

  // GetEntityId-like: vtbl +0x1d4
  int id = (*(int (__thiscall **)(void *))(*(int *)entity + 0x1d4))(entity);
  if (id == 0) return;

  int *nested_on_slot = *(int **)((uint8_t *)slot_obj + 0x508);
  if (nested_on_slot != nullptr) {
    int bound = *(int *)((uint8_t *)slot_obj + 0x50c);
    int id2 = (*(int (__thiscall **)(void *))(*(int *)entity + 0x1d4))(entity);
    if (bound == id2) return;   // already bound to this entity
  }

  // re-load id into EAX; bind slot
  (void)(*(int (__thiscall **)(void *))(*(int *)entity + 0x1d4))(entity);
  FUN_0083ab90(/* ECX=slot_obj, EAX=entity_id, stack host */);
}
```

## Open questions

- Product demangle for host / slot / entity classes.
- Dual of `FUN_00427d20` (list-by-index) and `FUN_0083ab90` (bind worker) — not OWN.
- Exact meaning of entity vtbl `+0x1d4` (id/handle).
- Runtime / bit-exact / differential.
