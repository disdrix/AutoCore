# Review A (reconstruction fidelity): `aa_004027f0` StdList_PushFront_DwordFromEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004027f0` |
| **VA** | `0x004027f0`–`0x0040281e` |
| **Canonical name** | `StdList_PushFront_DwordFromEax_Inferred` |
| **Ghidra name** | `FUN_004027f0` |
| **Review date** | `2026-08-05` (OWN-ONLY dual **MEGA-089**) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md` |
| **System** | missions-progression (partition) + multi-system list host |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + `get_assembly_context` (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

MSVC **`std::list` push_front** of a **4-byte** value: buy 0xC node after head sentinel, increment `_Mysize`, rewire circular links. Value source is **EAX** (pointer-to-dword); list is the sole stack arg (`RET 4`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x004027f0` — ≡ 2026-07-23 raw |
| Live analyze | `analyze_function_complete` — 1 BB, 2 callees, 8 xrefs, phantom `in_EAX` |
| Live disasm | `disassemble_function` — 21 insns; `RET 4` |
| Live bytes | `read_memory` 48–80 B @ `0x004027f0` — hex seal |
| Call-site ctx | `get_assembly_context` on RecvCreateCharacter / CreateVehicle / FUN_0080af70 / FUN_0093ffb0 |
| Callee raw | `aa_00418700` `_Buynode`; `aa_00418790` `_Incsize` + `"list<T> too long"` |
| Raw | `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.md` (+ MEGA-089 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushFront_DwordFromEax_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004027f0.cpp` |
| Function records | `aa_004027f0_FUN_004027f0.md` + named |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, product PDB.

---

## 3. Byte seal (key claims)

| Claim | Confidence | Evidence |
|---|---|---|
| Stack list* → EBX | **High** | `8B 5C 24 08` after `PUSH EBX` |
| `head = list+4` → ESI | **High** | `8B 73 04` |
| `head->_Next` → ECX | **High** | `8B 4E 04` |
| EAX pushed as val* | **High** | `50` before `PUSH ECX; PUSH ESI` |
| `CALL FUN_00418700` | **High** | rel32 to `0x00418700` |
| `_Incsize(1)` ECX=1 EDX=list | **High** | `B9 01 00 00 00` / `8B D3` / `CALL 00418790` |
| `head->_Next = node` | **High** | `89 7E 04` |
| `node->_Next->_Prev = node` | **High** | `8B 57 04` / `89 3A` |
| **`RET 4`** | **High** | `C2 04 00` |
| Body end before pad | **High** | last insn `0040281e`; `CC` pad |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head / next | **Yes** |
| Buynode(prev=head, next=head→next, val*) | **Yes** |
| Incsize(1) | **Yes** (register args restored in clean; decompiler elides) |
| Splice next/prev | **Yes** |
| Single return / no branches | **Yes** |
| No modernization | **Yes** |

---

## 5. Confidence summary

| Dimension | Level |
|---|---|
| Function boundary + ABI | **High / Sealed** |
| push_front structure | **High / Sealed** |
| Node 0xC + dword val | **High / Sealed** |
| Multi-caller list host | **High** (xrefs + call-site LEA offsets) |
| Product class / element English | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 6. Gaps

1. Product C++ typedef for `list<T>` element (object* vs other dword) per host offset (`+0xf08` / `+0xefc` / `+0xaa8`).
2. Full ownership of list+0 field (allocator / base) — unused by this body.
3. OOM: `FUN_00418700` can return null; this unit stores through `node` without null check (retail risk retained).
4. Runtime / differential verification.

**Verdict:** CF + ABI + layout sealed from live decompile + disasm + `read_memory` + call-site context. Product names inferred. **accept-with-gaps.**
