# Annotated low-level: Map_LowerBoundFindByCharKey

| Field | Value |
|---|---|
| Stable ID | `aa_00402210` |
| VA | `0x00402210` |
| System | `skills-abilities` (shared map helper; primary consumers skill/cast paths) |
| Date | `2026-07-29` (refined dual pass; prior scaffold 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_00402210` + live Ghidra `decompile_function` / `read_memory` / `analyze_function_complete` (2026-07-29).
- **Leaf helper** — no callees.
- **`ret 8`** (`C2 08 00`) ⇒ **two stack formals** only (+ `this` in ECX). Decompiler signature lists a third unused `char *pKey` phantom; **ignore it**.
- True formals (stack):
  1. `Node **pOutIt` — write destination for hit node or end sentinel
  2. `char *pKey` — pointer to search key (**one signed char** loaded via `MOV CL,[EDI]`)
- Decompiler names are swapped/messy: body reads key from formal `pOutIt` and writes iterator through formal `pMap`. Annotated renames below recover intent.
- Prefer assembly when decompiler conflicts (param count already conflicts).

### Node / map layout (this family)

| Offset | Role | Evidence |
|---|---|---|
| `map+4` | end / `_Myhead` sentinel pointer | body both arms; miss writes this |
| `head+4` (`head[1]`) | root / parent of head | walk start |
| `node+0` | left child | else branch `*puVar1` |
| `node+8` (`[2]`) | right child | then branch |
| `node+0x0C` (`[3]` as char) | **char key** | `CMP [EAX+0x0C], CL` / `CMP CL,[EDX+0x0C]` |
| `node+0x21` | nil / isnil byte; **0 = real node** | `CMP BYTE PTR [reg+0x21], 0` |

Distinct from sibling helpers:

| Helper | Nil | Key | Key width |
|---|---|---|---|
| `Map_LowerBoundFindByIntKey` (`0x0050f940`) | `+0x15` | `[3]` dword | int |
| `StdMap_LowerBoundByIntKey_INFERRED` (`0x004054f0`) | `+0x1d` | `[3]` dword | int |
| `Map_ExactFindByIntKey` (`0x0051c150`) | `+0x29` | `+0x10` | int |
| **`Map_LowerBoundFindByCharKey` (`0x00402210`)** | **`+0x21`** | **`+0x0C`** | **char** |

### Semantics

MSVC-style **ordered-tree find** for a **char** key:

1. Start candidate = end; cursor = root (`head[1]`).
2. While cursor is non-nil (`+0x21 == 0`):
   - if `node.key < *pKey` → go **right**
   - else → candidate = node, go **left**
3. Accept only if `candidate != end` **and** `node.key <= *pKey` (signed char).
4. With walk invariant (candidate is first with `key >= search`), the post gate seals **equality** → **exact find**, not pure `lower_bound` “first ≥”.
5. Miss / empty → `*pOutIt = end`.
6. **Read-only** — no insert, erase, or allocation.

Naming note: Ghidra plate / registry keep `Map_LowerBoundFindByCharKey` (lower_bound-shaped walk + find gate). Do **not** port as open lower_bound without the equality gate.

## Pseudocode (annotated; CF ≡ raw)

```c
// True ABI (from ret 8 + body uses):
//   void __thiscall Map_LowerBoundFindByCharKey(
//       MapHeader *this,   // ECX
//       Node     **pOutIt, // Stack[0x4]
//       char      *pKey);  // Stack[0x8]  — points to one char
//
// Decompiler still prints (pMap,pOutIt,pKey) with pKey phantom and names swapped.

void __thiscall Map_LowerBoundFindByCharKey(void *this, void *pOutIt, void *pKey /* char* */)
{
  undefined4 *cand;   // puVar3 — lower_bound candidate
  undefined4 *cur;    // puVar1
  undefined4 *next;   // puVar2
  undefined4 *end;    // *(this+4)

  end  = *(undefined4 **)((int)this + 4);
  cand = end;
  cur  = (undefined4 *)end[1];               // root

  if (*(char *)((int)cur + 0x21) == '\0') {  // non-nil root
    do {
      // signed char: node.key @ +0x0C  vs  *pKey
      if (*(char *)(cur + 3) < *(char *)pKey) {
        next = (undefined4 *)cur[2];         // right @ +8
      }
      else {
        next = (undefined4 *)*cur;           // left @ +0
        cand = cur;
      }
      cur = next;
    } while (*(char *)((int)next + 0x21) == '\0');
  }

  // exact-match gate (not pure lower_bound)
  if ((cand != end) && (*(char *)(cand + 3) <= *(char *)pKey)) {
    *(undefined4 **)pOutIt = cand;
    return;
  }
  *(undefined4 **)pOutIt = end;
  return;
}
```

### Bytes (own VA, `read_memory` 2026-07-29)

```
00402210  51 56 8B F1 8B 56 04 8B 42 04 80 78 21 00 ...
          PUSH ECX; PUSH ESI; MOV ESI,ECX; MOV EDX,[ESI+4]; MOV EAX,[EDX+4]
          CMP BYTE PTR [EAX+0x21],0
...
          8A 0F 38 48 0C          ; MOV CL,[EDI]; CMP [EAX+0x0C],CL
...
          C2 08 00                ; RET 8
```

## Callers (xrefs inventory, own dual — sites only)

| Site | Owner (Ghidra) |
|---|---|
| `0x0059aa7e` | `FUN_0059a940` |
| `0x005d13ad` | `NPC_TryCastSkillFromSet` |
| `0x00616ff9` | `FUN_00616d10` |
| `0x00621293` | `FUN_00620ff0` |
| `0x007eb997`, `0x007ec62b` | `FUN_007eaf20` |
| `0x0084526b` | `FUN_00845030` |
| `0x00956152` | `FUN_00955eb0` |
| `0x006165b0`, `0x00616bb0`, `0x00620e90` | call sites (xref list; may be data/thunk-adjacent) |

Several skill-side callers pass map at **`object+0x51c`** and a **char** search key (often a small enum stuffed in a stack byte). Full caller contracts are **not** owned by this VA.

## Open questions

- Product / RTTI STL name (leave structural `Map_LowerBoundFindByCharKey`).
- Full node size and value payload after key (caller-owned).
- Whether any non-skill map reuses this exact layout (xrefs suggest skill/cast-adjacent consumers).
