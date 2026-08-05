
# Annotated low-level: FUN_0075dae0 / Owner_ClearDestroyGuardedPtrDequeAt28

| Field | Value |
|---|---|
| Stable ID | `aa_0075dae0` |
| VA | `0x0075dae0`–`0x0075db93` (**180 B**) |
| System | owner object + guarded ring-deque of owned pointers |
| Date | 2026-07-23 scaffold; **2026-07-29 W30-C seal** |

## Machine-level notes

- **ECX = owner**. Embedded GuardedVector (locked form) at **`this+0x28`**.
- SEH frame with handler `LAB_009afe4b`.
- Builds **empty local** GuardedVector header on stack (pages/cap/begin/size = 0).
- **`GuardedVector_ClearAndSwap`** (`0043c660`): ESI=local, EDI=`this+0x28` — clear local via Resize(0), swap ring headers under optional CS on B. After call, **local holds former field contents**; field is empty.
- Walk absolute ring range `[begin, begin+size)` with same page map math as PushBack (`>>2` / `&3` / capacity wrap).
- Each non-null element: **`vtable[0](elem, 1)`** — MSVC scalar deleting destructor.
- **`FUN_0040d9c0`** with ESI=local: drain size to 0 (pop-back bookkeeping loop), delete each page block, delete page map, zero +4/+8.
- Decompiler **must not** be trusted for this unit: dead `for (u=0;u!=0;)` and missing page base.

## Pseudocode (sealed from bytes)

```c
// ECX = owner*
void Owner_ClearDestroyGuardedPtrDequeAt28(void* owner /*ECX*/)
{
  GuardedVectorHeader local = {};           // +4..+10 zeroed
  GuardedVectorHeader* field =
      (GuardedVectorHeader*)((char*)owner + 0x28);

  // ESI=&local, EDI=field
  GuardedVector_ClearAndSwap(&local, field);

  int32_t begin = local.begin;
  int32_t size  = local.size;
  int32_t end   = begin + size;
  for (int32_t idx = begin; idx != end; ++idx) {
    uint32_t page = (uint32_t)idx >> 2;
    uint32_t sub  = (uint32_t)idx - (page << 2); // idx & 3
    if ((uint32_t)local.capacity <= page)
      page -= (uint32_t)local.capacity;
    void** elem = (void**)local.pages[page][sub]; // dword load
    if (elem != nullptr) {
      void (**vtbl)(void*, int) = *(void (***)(void*, int))elem;
      vtbl[0](elem, 1); // scalar deleting dtor
    }
  }

  // ESI=&local
  FUN_0040d9c0(); // free pages + map; size already walked but not zeroed until here
}
```

## Bytes (entry / steal / free)

Entry: `6A FF 68 4B FE 9A 00` SEH; `8B F9 83 C7 28 8D 74 24 0C E8 … → 0043c660`.

Loop element call: `8B 11 6A 01 FF 12` (`MOV EDX,[ECX]; PUSH 1; CALL [EDX]`).

Free: `8D 74 24 0C E8 … → 0040d9c0`.

Epilogue: `64 89 0D 00 00 00 00 83 C4 20 C3`.

Full 180 B hex: see raw append.

## Open questions

- Owner class product/PDB name and field English at +0x28.
- Why **zero** Ghidra code xrefs (vtable/data miss vs dead).
- Element static type beyond “owned object with scalar deleting dtor”.
- Runtime / bit-exact under CS contention (nested in ClearAndSwap).
- Confirm `FUN_0040d9c0` naming residual (W18-M OwnedPtrTable_Clear vs GuardedVector page free — body matches page-map free here).

