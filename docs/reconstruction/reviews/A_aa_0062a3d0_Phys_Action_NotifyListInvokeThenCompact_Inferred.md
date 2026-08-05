# Review A (reconstruction fidelity): `aa_0062a3d0` Phys_Action_NotifyListInvokeThenCompact_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a3d0` |
| **VA** | `0x0062a3d0` |
| **Canonical name** | `Phys_Action_NotifyListInvokeThenCompact_Inferred` |
| **Ghidra name** | `FUN_0062a3d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0062a3d0_Phys_Action_NotifyListInvokeThenCompact_Inferred.md` |
| **System** | `physics` (action post-register) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Post-register** helper used as the tail of `Phys_RegisterAction`:

1. Walk the growable **pointer array on the action** at **`action+0x3c`** (count **`action+0x40`**) **in reverse**.
2. For each **non-null** entry `p`, call **`p->vtbl[+0x8](world)`** (payload = world/sim from second formal).
3. **Tail-jump** `FUN_005fff20` with **`EAX = &action.arrayHeader (+0x3c)`** to **compact out null slots** (slide-down densify; count shrinks).

Not the action-list push (`006292a0`). Not body-pair glue (`0055efd0`). Not applyAction (`vtbl+0x14`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0062a3d0_FUN_0062a3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0062a3d0_FUN_0062a3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0062a3d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0062a3d0_FUN_0062a3d0.md` |
| Live decompile | Ghidra MCP `batch_decompile` @ `0x0062a3d0` + `0x005fff20` |
| Bytes | `read_memory` 64 B — reverse loop, vcall `+8`, **`jmp FUN_005fff20`** |
| Call-site ABI | `get_assembly_context` @ `0x0055fee3` — `PUSH world; PUSH action; CALL; ADD ESP,8` → **cdecl** `(action, world)` |
| Parent dual | `A\|B_aa_0055fe50_Phys_RegisterAction` (post-register residual) |
| Compact leaf | `FUN_005fff20` (null-slot densify on `{data,count}` header in EAX) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| **cdecl** two stack args; caller `ADD ESP,8` | **Confirmed** | sole site `0x0055fee3` |
| Formals order **`(action*, world*)`** (MSVC right-to-left push) | **Confirmed** | push world then action; body indexes first formal `+0x3c/+0x40` |
| Ghidra decompile of parent may swap labels | **Confirmed noise** | parent dual text said `(world, action)` — **corrected by asm** |
| Reverse iterate `i = count-1 … 0` | **Confirmed** | `sub esi,1` / `js` / loop |
| Skip null entries | **Confirmed** | `test ecx,ecx; jz` |
| Virtual call **`(*p->vtbl)[+0x8](world)`** | **Confirmed** | `mov edx,[ecx]; push ebx; call [edx+8]` with ebx=world |
| Tail `jmp FUN_005fff20` with `EAX = action+0x3c` | **Confirmed** | no local ret; compact is epilogue |
| `005fff20` removes nulls by sliding and decrements count | **High** | decompile of compact leaf |
| Sole caller RegisterAction | **Confirmed** | 1 xref |
| Product English for vtbl+8 / list | **Open** | notify / bind / attach family |
| Working name `_Inferred` | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load count from `action+0x40` | Yes |
| Reverse loop over `*(action+0x3c)` | Yes |
| Null skip | Yes |
| vtbl+8(world) | Yes |
| Compact via `005fff20` | Yes |
| cdecl cleanup at caller | Yes |

### Recovered CF

```c
// void __cdecl Phys_Action_NotifyListInvokeThenCompact_Inferred(void *action, void *world)
// Caller cleans 8 bytes. Tail → FUN_005fff20(header in EAX).
void Phys_Action_NotifyListInvokeThenCompact_Inferred(void *action, void *world)
{
  int *hdr = (int *)((char *)action + 0x3c);  // [0]=data, [1]=count (count also @ action+0x40)
  int i = hdr[1];
  while (--i >= 0) {
    void **slot = (void **)((char *)(*(void **)hdr) + i * 4);
    void *p = *slot;
    if (p != NULL) {
      void **vtbl = *(void ***)p;
      ((void (__thiscall *)(void *, void *))vtbl[2])(p, world);  // +0x8 == index 2
      // asm: push world; call [vtbl+8] with ECX=p  (thiscall-shaped vcall)
    }
  }
  // EAX = hdr; jmp FUN_005fff20 — densify nulls in-place
  FUN_005fff20(/*EAX=*/hdr);
}
```

**Note on vcall convention:** body loads `this` from array into ECX-equivalent (`mov ecx,[…]`, `mov edx,[ecx]`, `push world`, `call [edx+8]`). Treat as **thiscall-like** virtual method on list element with one stack arg = world.

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `Phys_RegisterAction` `0x0055fe50` | `0x0055fee3` | After host loop; sole site |

---

## 6. Gaps

1. Product name; English role of `action+0x3c` list (listeners / constraints / related hosts).
2. Implementers of vtbl `+0x8` on list elements.
3. Whether reverse order is load-bearing vs arbitrary.
4. Compact helper not given its own dual this pass (CF read is enough for parent seal).
5. Runtime / bit-exact open.

**Verdict:** CF + cdecl ABI + reverse notify + compact tail sealed. **accept-with-gaps.**
