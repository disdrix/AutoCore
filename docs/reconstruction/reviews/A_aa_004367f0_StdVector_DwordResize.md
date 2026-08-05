# Review A (reconstruction fidelity): `aa_004367f0` StdVector_DwordResize (leave-FUN / inferred role)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004367f0` |
| **VA** | `0x004367f0` |
| **Body** | `0x004367f0`–`0x00436858` (**`ret 8`**) |
| **Canonical name** | `FUN_004367f0` retained; role **`StdVector_DwordResize`** (**Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004367f0_StdVector_DwordResize.md` |
| **System** | STL / container utility (multi-domain; gfx host clear path cited) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF **High**; product STL symbol open; leave Ghidra `FUN_*` |

---

## 1. Purpose

**Resize** a MSVC-style `vector<uint32_t>`-shaped object (`this` points at the vector control block with **begin @ +4**, **end @ +8**, capacity sibling used only in grow callee):

```
size = (begin == 0) ? 0 : (end - begin) >> 2;   // dword count

if (size < newCount):
  // grow: insert (newCount - size) filled dwords at end
  FUN_004507a0(end, newCount - size, &fillValue /* stack+8 */)
  return;

if (begin != 0 && newCount < size):
  // shrink: erase [begin + newCount, end)
  FUN_00410490(&tmp, begin + newCount*4, end)
return;
```

**ABI:** `__thiscall`, **two stack dwords** — `newCount`, `fillValue` — **`ret 8`**.

Caller evidence: `EquipGfxHost_ClearListIfFlag` dual arms `push 0; push 0; add ecx, 0xA8; call` → resize-clear host list to 0. Many other domains (23 xrefs).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x004367f0` |
| Complete analysis | 23 xrefs; callees `FUN_004507a0` (grow), `FUN_00410490` (shrink/erase) |
| Machine | `read_memory` @ `0x004367f0` length 110 |
| Grow callee | `FUN_004507a0` decompile — capacity/reallocate path |
| Shrink callee | `FUN_00410490` — `memmove` erase + end update |
| Caller dual | `A_aa_004962b0_EquipGfxHost_ClearListIfFlag_Inferred` |
| Raw / clean scaffold | `raw/aa_004367f0_*`, `reconstructed-exact/FUN_004367f0.cpp` |
| Function record | `functions/aa_004367f0_FUN_004367f0.md` |

---

## 3. Authoritative body

```c
void __thiscall FUN_004367f0(int param_1, uint param_2 /* newCount */, /* fill @ stack+8 */)
{
  uint uVar1;
  int iVar2 = *(int *)(param_1 + 4); // begin
  if (iVar2 == 0) uVar1 = 0;
  else uVar1 = (*(int *)(param_1 + 8) - iVar2) >> 2; // size

  if (uVar1 < param_2) {
    // recompute size into iVar2
    if (iVar2 == 0) iVar2 = 0;
    else iVar2 = (*(int *)(param_1 + 8) - iVar2) >> 2;
    FUN_004507a0(*(undefined4 *)(param_1 + 8), param_2 - iVar2, &stack0x00000008);
    return;
  }
  if ((iVar2 != 0) && (param_2 < (uint)((*(int *)(param_1 + 8) - iVar2) >> 2))) {
    FUN_00410490(&param_2, iVar2 + param_2 * 4, *(int *)(param_1 + 8));
  }
  return;
}
```

---

## 4. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| begin `this+4`, end `this+8` | `mov edx,[ecx+4]` / `mov eax,[ecx+8]` | **High** |
| size `>> 2` (dword elems) | `c1 f8 02` | **High** |
| Compare size vs newCount (`[esp+8]` after pushes) | `mov esi,[esp+8]; cmp eax,esi` | **High** |
| Grow path `call FUN_004507a0` then **`ret 8`** | `e8 …; pop edi; pop esi; c2 08 00` | **High** |
| Shrink path `lea eax,[edx+esi*4]` + `call FUN_00410490` + **`ret 8`** | `8d 04 b2` / second `c2 08 00` | **High** |
| No-op when size == newCount | fall off end / no call | **High** |
| Fill value is 3rd arg (stack after count) | grow passes `&stack+16` after setup | **High** |

---

## 5. Layout contract

| Offset | Role |
|---|---|
| `vec+0x00` | (unused here; often cookie / proxy) |
| `vec+0x04` | begin (`T*`) |
| `vec+0x08` | end (`T*`) |
| `vec+0x0C` | capacity end (grow callee only) |

Element size **4** bytes (dword). Not string/vector of structs without extra destroy path in **this** unit — shrink uses raw memmove erase (`FUN_00410490`).

---

## 6. Gaps / open

1. Product STL helper name (`vector::resize` mangling).
2. Whether any caller relies on non-zero fill beyond zero-clear paths.
3. Element destructor absence — safe only for POD dwords (callers must not use for non-trivial T without different helper).
4. Runtime / differential — open.

**Verdict:** **accept-with-gaps** (leave Ghidra `FUN_004367f0`)
