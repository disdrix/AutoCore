# Review A (reconstruction fidelity): `aa_00497360` StdList_Destroy_FreeHead

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497360` |
| **VA** | `0x00497360`–`0x004973a7` (**72 B**) |
| **Canonical name** | `StdList_Destroy_FreeHead` |
| **Ghidra name** | `FUN_00497360` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-K) |
| **Counterpart** | `reviews/B_aa_00497360_StdList_Destroy_FreeHead.md` |
| **System** | shared / MSVC std::list |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body through RET) + call-site context. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**List object destructor tail** for MSVC circular `std::list`-shaped objects:

1. Snapshot first node; self-link sentinel; size = 0.
2. Free every node in the ring until sentinel.
3. Free sentinel; **null** `list+4`.

Used from `CVOGSectorMap_Destructor` (multiple embedded lists) and other teardown callers (11 xrefs).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W27-K) | `docs/reconstruction/raw/aa_00497360_FUN_00497360.md` |
| Annotated | `docs/reconstruction/raw/aa_00497360_FUN_00497360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00497360.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_Destroy_FreeHead_00497360.cpp` |
| Function record | `docs/reconstruction/functions/aa_00497360_FUN_00497360.md` |
| Sibling | `StdList_Destroy_FreeHead_Inferred` `0x00403430` |
| Live | decompile **incomplete**; bytes seal loop + null head + RET |

---

## 3. Signature (sealed)

```c
// ECX = list* (+4 head, +8 size); bare RET; void
void __fastcall StdList_Destroy_FreeHead(void *list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX | **High** |
| return | void | **High** |
| cleanup | bare `RET` (`5E C3`) | **High** |

---

## 4. Control flow (clean ≡ **bytes**; decompile incomplete)

```
head = [list+4]; first = [head]
[head]=head; [head+4]=head; [list+8]=0
if first != head:
  loop: next=[first]; delete(first); first=next; while first != head
delete([list+4]); [list+4]=0
ret
```

| Stage | Match | Conf |
|---|---|---|
| Self-link + size 0 | **Yes** | **High** |
| Free-all-nodes loop | **Yes** (bytes) | **High** |
| Free sentinel + null head | **Yes** (bytes) | **High** |
| Ghidra single-delete decompile | **No** — superseded by bytes | — |

---

## 5. Machine bytes (`read_memory`)

Full body hex (72 B):
```
568bf18b4e048b0189098b4e048949043b4604c74608000000007417578d49008b3850e89a24ffff83c4043b7e048bc775ee5f8b460450e88624ffff83c404c74604000000005ec3
```

| Feature | Encoding |
|---|---|
| Loop back | `75 EE` after `CMP EDI,[ESI+4]` / `MOV EAX,EDI` |
| Null head | `C7 46 04 00 00 00 00` |
| Epilogue | `5E C3` |
| Pad | `CC` after RET |

**No `disassemble_bytes` used.** Ghidra function-end `0x0049739b` is mid-CALL — use byte end `0x004973a7`.

---

## 6. Gaps

- `list+0` field unused (allocator / padding) — open.
- Product English beyond MSVC list role — residual (`_Inferred` not required; layout strong).
- Runtime differential — open.

---

## 7. Verdict

**accept** — destructor CF and ABI sealed from full body bytes; decompiler loop collapse documented and corrected in clean/annotated.
