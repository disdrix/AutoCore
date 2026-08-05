# Review A (reconstruction fidelity): `aa_004e7350` StdMap_Dtor_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7350` |
| **VA** | `0x004e7350` |
| **Body** | `0x004e7350`–`0x004e737e` exclusive (**46** B) |
| **Canonical name** | `StdMap_Dtor_Val12` (inferred) |
| **Ghidra symbol** | `FUN_004e7350` |
| **Prior / alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004e7350` (narrow) |
| **Review date** | `2026-07-29` (W29-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e7350_StdMap_Dtor_Val12.md` |
| **System** | std map Val12 destructor |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`std::map` / MSVC `_Tree` **destructor body** for Val12 nodes: erase `[begin,end)`, free header, null `head`/`size`.

```
StdMap_Dtor(map):
  EraseRange(map, begin=*head, end=head)   // FUN_004e5120
  operator_delete(head)
  head = 0; size = 0
  RET 0
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e7350_FUN_004e7350.md` (+ W29-M append) |
| Annotated | `raw/aa_004e7350_FUN_004e7350.annotated.md` |
| Clean | `reconstructed-exact/StdMap_Dtor_Val12.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_004e7350.cpp` |
| Function record | `functions/aa_004e7350_StdMap_Dtor_Val12.md` |
| Live decompile | erase + delete surface ≡ raw; post-delete from bytes |
| Bytes | `read_memory` @ `0x004e7350` (48 B) — full body through `C3` + `CC` |
| Callees | `0x004e5120` EraseRange Val12 (W28-P); `operator_delete` |
| Callers | `FUN_004d64d0` ×2 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0`** (`C3`) | **High** | no stack pop of args; ECX→ESI |
| Full erase via `FUN_004e5120` | **High** | site `0x004e7362`; first=`*head`, last=`head` |
| Free header then null head/size | **High** | bytes after delete: `xor eax,eax; mov [esi+4],eax; mov [esi+8],eax` |
| Decomp noreturn on delete is residual | **High** | fall-through proven by bytes |
| Ghidra body end `0x004e736f` stale | **High** | cuts before null stores / ret |
| Val12 layout via erase-range | **High** | W28-P seal; isnil@+0x19 |
| Two callers in `FUN_004d64d0` | **High** | xrefs 2026-07-29 |
| Product demangle / map K-V types | **Inferred** | open |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| thiscall ECX=map → ESI | **Yes** |
| EraseRange(out, *head, head) | **Yes** |
| operator_delete(head) cdecl | **Yes** |
| head=0, size=0 | **Yes** (bytes; raw scaffold truncated) |
| `RET` (`C3`) | **Yes** |

---

## 5. Asm-sealed signature + layouts

```
MapShell { head@+4, size@+8 }
call EraseRange thiscall ret 0x0c (callee)
call operator_delete cdecl
RET 0
Body 46 B sealed; pad CC
```

---

## 6. Gaps

1. Product English / full MSVC demangle for the two map instantiations in `FUN_004d64d0`.
2. Whether `*head` is always leftmost under all empty/non-empty states (MSVC header invariant — assumed OK).
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
