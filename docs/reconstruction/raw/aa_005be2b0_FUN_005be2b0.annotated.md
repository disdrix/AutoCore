# Annotated low-level: FUN_005be2b0 / ObjectMotion_SlotReleaseToFreelist_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005be2b0` |
| VA | `0x005be2b0`–`0x005be2e9` exclusive (**57** B / `0x39`) |
| System | client object motion / reaction slot freelist |
| Date | 2026-07-29 W28-I |
| Preferred name | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| Ghidra name | `FUN_005be2b0` |

## Machine-level notes

- **`__thiscall`**: ECX = freelist head pointer (`int*`); stack one arg = slot node; **`ret 4`**.
- Both dualed callers force **`mov ecx, 0x00B036C0`** before the call — freelist is the global `DAT_00b036c0`, not the motion host.
- Slot layout used here: `+0x0` next freelist link; `+0x8` optional nested child (also freelist-compatible).
- `FUN_004b0bd0` body is empty (`ret` only). Called as thiscall with ECX=child, then ECX=node — residual clear/dtor stub.
- Decompiler drops explicit ECX setup for the empty stub; bytes + `read_memory` seal thiscall ECX.

## Byte evidence (`read_memory`)

Prologue + body + epilogue:

```
56                 push esi
8B 74 24 08        mov esi, [esp+8]     ; node
57                 push edi
8B F9              mov edi, ecx         ; freelist head*
8B 4E 08           mov ecx, [esi+8]     ; child
85 C9              test ecx, ecx
74 19              jz skip_child
E8 …               call FUN_004b0bd0    ; ECX=child
8B 46 08           mov eax, [esi+8]
85 C0              test eax, eax
74 06              jz clear_child
8B 0F              mov ecx, [edi]
89 08              mov [eax], ecx       ; child->next = *head
89 07              mov [edi], eax       ; *head = child
C7 46 08 00 00 00 00  mov dword [esi+8], 0
8B CE              mov ecx, esi         ; ECX=node
E8 …               call FUN_004b0bd0
8B 17              mov edx, [edi]
89 16              mov [esi], edx       ; node->next = *head
89 37              mov [edi], esi       ; *head = node
5F                 pop edi
5E                 pop esi
C2 04 00           ret 4
```

## Callers

| Caller | Site | ECX at call | Stack arg |
|---|---|---|---|
| `ObjectMotion_SlotListTick_Inferred` (`FUN_005bb5e0`) | `0x005bb624` | `0x00B036C0` | payload `node[2]` |
| `FUN_005bbc50` (host teardown) | `0x005bbd0e` | `0x00B036C0` | payload `node[2]` |

## Pseudocode (annotated)

```c
// ECX = freelist_head*; stack node*; ret 4
void ObjectMotion_SlotReleaseToFreelist_Inferred(int **head, int *node)
{
  if (node[2] != 0) {
    FUN_004b0bd0(/*this=*/node[2]);   // empty
    int *child = (int *)node[2];
    if (child) {
      *child = (int)*head;            // child next
      *head = child;
    }
    node[2] = 0;
  }
  FUN_004b0bd0(/*this=*/node);        // empty
  *node = (int)*head;
  *head = node;
}
```

## Open questions

1. Product / PDB symbol for freelist owner class.
2. Why `FUN_004b0bd0` is empty (stripped dtor vs intentional nop).
3. Runtime freelist chain integrity golden — open.
