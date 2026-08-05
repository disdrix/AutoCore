# Annotated low-level: LinkPair_SortedDiffWalk_Inferred (FUN_006caaa0)

| Field | Value |
|---|---|
| Stable ID | `aa_006caaa0` |
| VA | `0x006caaa0`–`0x006cac19` (**378 B**) |
| Ghidra name | `FUN_006caaa0` |
| Inferred name | `LinkPair_SortedDiffWalk_Inferred` |
| System | world-object / spatial-link merge |
| Date | 2026-07-29 (W27-N dual seal) |
| Tools | `decompile_function` + `read_memory` + callers/xrefs; **no** `disassemble_bytes` |

## Machine-level notes

- **ABI:** thiscall; ECX = handler-table base; five stack formals; `ret 0x14`; void.
- **Entry:** `MOV EBX,ECX` captures this; range ends computed as `base + count*8` (pairs of dwords).
- **No direct FUN_* callees** — all side effects are vtable calls through `param_1` handler table and optional predicate object `param_6`.
- Prefer this annotated CF + raw body over invented product names; keys are structural (`node+4`, `partner+4`, `field8` index).

## Signature

```c
// thiscall; ret 0x14; void
void LinkPair_SortedDiffWalk_Inferred(
    void *handler_table /*ECX*/,
    int *left_pairs /*stack*/,
    int left_count,              // promoted to end ptr: left + count*2 ints
    int *right_pairs,
    int right_count,             // promoted to end ptr: right + count*2 ints
    void *predicate_obj          // vtbl[0] -> char* gate
);
```

## Pseudocode (annotated)

```c
void __thiscall
FUN_006caaa0(int param_1,int *param_2,int *param_3,int *param_4,int param_5,uint32_t *param_6)
{
  // param_3/param_5 are counts on entry; rewritten to exclusive end pointers (int* + count*2).
  int *left_end = param_2 + (int)param_3 * 2;
  int *right_end = param_4 + param_5 * 2;
  uint32_t *pred = param_6;
  int *L = param_2;
  int *R = param_4;

  // Main merge while both ranges live
  if (param_2 != left_end) {
    do {
      if (R == right_end) break;
      uint kL = *(uint *)(*L + 4);
      uint kR = *(uint *)(*R + 4);
      if (kR == kL && *(int *)(R[1] + 4) == *(int *)(L[1] + 4)) {
        L += 2; R += 2;                 // match — keep both, advance
      } else if (kR < kL || (kR == kL && *(uint *)(R[1] + 4) < *(uint *)(L[1] + 4))) {
        // right-only → handler vcall +8 (remove/apply-right)
        (**(code **)(**(int **)(param_1 + (*(int *)(R[1] + 8) + *(int *)(*R + 8) * 8) * 4) + 8))(R);
        R += 2;
      } else {
        // left-only → optional predicate then handler vcall +4 (add/apply-left)
        int a = (*L == 0) ? 0 : *L - 0x10;
        int b = (L[1] == 0) ? 0 : L[1] - 0x10;
        char *gate = (char *)(**(code **)*pred)(&param_2, a, b);
        if (*gate != '\0') {
          (**(code **)(**(int **)(param_1 + (*(int *)(L[1] + 8) + *(int *)(*L + 8) * 8) * 4) + 4))(L);
        }
        L += 2;
      }
    } while (L != left_end);
  }
  // Left tail
  while (L < left_end) {
    int a = (*L == 0) ? 0 : *L - 0x10;
    int b = (L[1] == 0) ? 0 : L[1] - 0x10;
    char *gate = (char *)(**(code **)*pred)(&param_6, a, b);
    if (*gate != '\0') {
      (**(code **)(**(int **)(param_1 + (*(int *)(L[1] + 8) + *(int *)(*L + 8) * 8) * 4) + 4))(L);
    }
    L += 2;
  }
  // Right tail
  while (R < right_end) {
    (**(code **)(**(int **)(param_1 + (*(int *)(R[1] + 8) + *(int *)(*R + 8) * 8) * 4) + 8))(R);
    R += 2;
  }
}
```

## Open questions

- Product English for handler-table type matrix (`field8` × 8).
- Predicate object layout / who installs `param_6` (stack callback on bind/unbind frames).
- Exact node header before `+0x10` adjustment.
- Runtime / bit-exact — open.
