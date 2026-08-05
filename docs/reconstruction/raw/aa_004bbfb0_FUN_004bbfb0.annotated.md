# Annotated low-level: FUN_004bbfb0 → COList_Constructor

| Field | Value |
|---|---|
| Stable ID | `aa_004bbfb0` |
| VA | `0x004bbfb0`–`0x004bc17f` (**464 B / `0x1D0`**) |
| System | client / COList |
| Date | 2026-07-29 (W27-L seal; scaffold 2026-07-23) |
| Canonical name | `COList_Constructor` |
| Ghidra name | `FUN_004bbfb0` |

## Machine-level notes

- **Role:** C++ constructor for **COList** (product rdata `COList::Insert` on vtbl adjacency; InitInstance log `"before CVOGClonedObjectList"`).
- **ABI:** `__thiscall`; ECX=`this`; stack args `(int capA, int capB)`; **`ret 8`**; returns `this`.
- **SEH:** installs `LAB_009a1742` FS:0 frame; state byte tracks partial construction for unwind of nested `operator_new` + sub-ctors.
- **Vtbl:** `*this = PTR_FUN_009cb448` (`C7 06 48 B4 9C 00`). Slot0 = scalar dtor `FUN_004bd1b0`.
- **Cap clamps:** `capA = max(capA,0)`, `capB = max(capB,0)`.
- **Flags:** `*(byte*)(this+0x0C) = (capA != 0)`; `*(byte*)(this+0x0D) = (capB != 0)`; `*(byte*)(this+0x0E) = 0`.
- **Hash members (+0x04 / +0x08):** if corresponding flag, `operator_new(0x34)` then `FUN_004bcf90(cap)` (bit-size ctor: table length `1<<cap`). Else null.
- **Third table (+0x18):** always `operator_new(0x34)` + `FUN_004bce90(5)` (fixed bit-size 5 → length 32). Different vtbl (`PTR_FUN_009cb450`) than hashA/B (`PTR_FUN_009cb45c`).
- **Three list objects (+0x1C/+0x20/+0x24):** each `operator_new(0x2C)`:
  - interim vtbl `PTR_FUN_009cb334`
  - zero dwords at +0x1C/+0x20/+0x24 and byte +0x28
  - `InitializeCriticalSection` at object+0x04 (single CS)
  - final vtbl `PTR_FUN_009cb378`
  - **Not** the dual-CS stack list layout used in `COList_Destructor` (`PTR_FUN_009cb368`); do not conflate product layout without further seal.
- **Vector buffer triples:** zero `[0xB..0xD]`, `[0xF..0x11]`, `[0x13..0x15]` (dtor frees heads at indices 0xB/0xF/0x13).
- **Caller:** sole code xref `FUN_0094a6a0` (`Client_InitInstance`) @ `0x0094a7eb`:
  - `operator_new(0x58)` → `FUN_004bbfb0(5, 10)` → `DAT_00b04830` and `*(client+0xD34)`.
- **Dtor twins:** body `FUN_004bbc70` / scalar `FUN_004bd1b0` (same vtbl).

## Pseudocode (annotated)

```c
// __thiscall; ECX=this; stack (capA, capB); ret 8; returns this*
uint32_t* __thiscall COList_Constructor(uint32_t* self, int capA, int capB)
{
  // SEH frame → LAB_009a1742
  *self = (uint32_t)&PTR_FUN_009cb448;

  // zero buffer triple bases (partial; see raw for exact indices)
  self[0xB] = self[0xC] = self[0xD] = 0;
  self[0xF] = self[0x10] = self[0x11] = 0;
  self[0x13] = self[0x14] = self[0x15] = 0;

  if (capA < 0) capA = 0;
  if (capB < 0) capB = 0;

  self[4] = (uint32_t)capA;                 // +0x10
  self[5] = (uint32_t)capB;                 // +0x14
  *(uint8_t*)(self + 3) = (capA != 0);      // +0x0C
  *(uint8_t*)((uint8_t*)self + 0x0D) = (capB != 0);

  // hashA @ +0x04
  self[1] = (capA != 0)
    ? construct_hash_004bcf90(operator_new(0x34), (uint8_t)capA)
    : 0;

  // hashB @ +0x08
  self[2] = (*(uint8_t*)((uint8_t*)self + 0x0D) != 0)
    ? construct_hash_004bcf90(operator_new(0x34), (uint8_t)capB)
    : 0;

  // third table @ +0x18 always bit-size 5
  self[6] = construct_hash_004bce90(operator_new(0x34), 5);

  // three 0x2C CS-list objects @ +0x1C / +0x20 / +0x24
  self[7] = construct_cs_list_0x2c();
  self[8] = construct_cs_list_0x2c();
  self[9] = construct_cs_list_0x2c();

  *(uint8_t*)((uint8_t*)self + 0x0E) = 0;
  // pop SEH
  return self;
}
```

## InitInstance call site (sealed)

| Step | Detail |
|---|---|
| Log | `FUN_007a4480(…, "before CVOGClonedObjectList")` |
| Alloc | `operator_new(0x58)` |
| Ctor args | push **10**, push **5**, ECX=new → `FUN_004bbfb0` |
| Publish | `DAT_00b04830 = this`; `*(client + 0xD34) = this` |

## Open questions

- Product English for hashA vs hashB vs third table (`004bce90` vs `004bcf90`).
- Product name of 0x2C single-CS list (vtbl `009cb378`) vs dual-CS `ThreadSafeObjectList` (`009cb368`).
- Exact MSVC SEH unwind tables (not required for CF port).
- Runtime / bit-exact open.
