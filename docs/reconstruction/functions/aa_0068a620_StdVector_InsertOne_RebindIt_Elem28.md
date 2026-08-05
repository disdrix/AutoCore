# Function record: StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a620` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28` |
| **Ghidra name** | `FUN_0068a620` |
| **Address** | `0x0068a620`–`0x0068a68a` exclusive (**106 B** / `0x6A`) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | MSVC-style `vector<POD0x1c>` insert-one + out-iterator rebind |
| **Name confidence** | **Inferred** (structural; family twin of other InsertOne_RebindIt units; no product string) |
| **Completion** | Dual A/B W37-AC — **accept-with-gaps** |
| **Runtime / bit-exact / diff** | Open |

## Role

Thin wrapper over `StdVector_InsertN_Elem28` (`0x0068a1d0`):

1. Compute stable element **index** from `where` relative to `begin` (0 if empty).
2. Call insert-N with **count = 1**.
3. Rebind `*outIt = begin' + index * 0x1c` (post-realloc begin).

Sole known consumer: `FUN_0068ae50` capacity-full push_back slow path.

## Signature

```c
void __thiscall StdVector_InsertOne_RebindIt_Elem28(
    VectorElem28* vec,   // ECX; +4 begin, +8 end, +0xC capEnd
    Elem28** outIt,      // stack0
    Elem28* where,       // stack1
    const Elem28* value  // stack2 — pointer to 0x1c POD
); // RET 0x0C
```

## Related

| Unit | VA | Relation |
|---|---|---|
| `StdVector_InsertN_Elem28` | `0x0068a1d0` | insert-N callee (W34-S) |
| `FUN_0068ae50` | `0x0068ae50` | push_back caller (not OWN) |
| `StdVector_InsertOne_RebindIt_Thiscall` | `0x0040dbf0` | dword-stride twin shape |
| `StdVector_InsertOne_RebindIt_Elem28_ValueEdx` | `0x00469e20` | 0x1c twin, different InsertN ABI |

## Artifacts

See `aa_0068a620_FUN_0068a620.md` for full path table.
