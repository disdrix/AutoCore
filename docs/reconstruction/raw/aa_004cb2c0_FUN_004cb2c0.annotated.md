# Annotated low-level: StdTree_Min_Isnil21_Inferred (FUN_004cb2c0)

| Field | Value |
|---|---|
| Stable ID | `aa_004cb2c0` |
| VA | `0x004cb2c0`–`0x004cb2da` inclusive (**27 B** / `0x1b`) |
| System | skills-abilities (partition); role = generic MSVC `_Tree` min |
| Date | 2026-08-05 (R13-002 dual seal) |
| Canonical | `StdTree_Min_Isnil21_Inferred` |
| Ghidra | `FUN_004cb2c0` |

## Machine-level notes

- Source: raw capture + R13-002 re-verify for `aa_004cb2c0`.
- Prefer assembly when decompiler conflicts (decomp `void` vs EAX return).
- Leaf: no callees. 7 erase-family callers, all isnil@+0x21.
- Layout: left@+0, isnil@**+0x21** (color@+0x20 per erase parent).

## Pseudocode (annotated — ABI-corrected)

```c
// Stack arg node*; return leftmost non-nil in EAX; bare RET
// Ghidra void is wrong — sealed by call-site MOV [EBX],EAX after ADD ESP,4

void *StdTree_Min_Isnil21_Inferred(void *node /* [esp+4] */)
{
  void *left = *(void **)node;                 // node->left
  if (*(char *)((int)left + 0x21) != 0)        // left isnil
    return node;                               // EAX still = node

  do {
    node = left;
    left = *(void **)node;
  } while (*(char *)((int)left + 0x21) == 0);  // walk left while non-nil

  return node;                                 // EAX = min
}
```

## Bytes (sealed)

```text
8b442404 8b08 80792100 750e 8d642400 8bc1 8b08 80792100 74f6 c3
```

## Callers (7)

| Caller | Call site | Role |
|---|---|---|
| `FUN_00405650` | `0x0040571a` | StdTree_EraseAndRebalance_Isnil21 (parent dual R12-009) |
| `FUN_004e3e70` | `0x004e3f5f` | erase family residual |
| `FUN_00511c00` | `0x00511cec` | erase family residual |
| `FUN_0059d300` | `0x0059d3ec` | erase family residual |
| `FUN_005a2ea0` | `0x005a2f8f` | erase family residual |
| `FUN_005a4590` | `0x005a467c` | erase family residual |
| `FUN_005ae6d0` | `0x005ae7bf` | erase family residual |

Uniform plate: `PUSH EDI; CALL; ADD ESP,4; MOV [EBX],EAX` → head leftmost recompute.

## Family (do not merge)

| Peer | VA | Diff |
|---|---|---|
| `StdTree_Min_Isnil29` | `0x0051b5d0` | isnil@+0x29; same stack ABI plate |
| `StdTree_Min_Isnil31` | `0x00409160` | isnil@+0x31; **EAX-in** ABI |
| Max residual | `FUN_00421a60` | rightmost twin (R13-001) |
| Parent erase | `0x00405650` | dualed R12-009 |

## Open questions

1. Product / PDB map value_type for each of the 7 host erase parents.
2. Exact node size class beyond isnil@+0x21 / color@+0x20 (parent says node 0x28 Val16).
3. Runtime / bit-exact / differential.
