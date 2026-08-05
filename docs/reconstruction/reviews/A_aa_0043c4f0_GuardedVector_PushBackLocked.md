# Review A (reconstruction fidelity): `aa_0043c4f0` GuardedVector_PushBackLocked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c4f0` |
| **VA** | `0x0043c4f0`–`0x0043c54d` (**94 B**) |
| **Canonical name** | `GuardedVector_PushBackLocked` (**Inferred**) |
| **Ghidra name** | `FUN_0043c4f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-D) |
| **Counterpart** | `reviews/B_aa_0043c4f0_GuardedVector_PushBackLocked.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 94 B) + `analyze_function_complete`; sole caller setup bytes |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Optional CS wrapper around sealed `GuardedVector_PushBack`:

1. If `container+0x2c != 0`, `EnterCriticalSection(container+0x14)`.
2. `EAX = container`; call `FUN_0043c830(value*)`.
3. If locked, `LeaveCriticalSection(container+0x14)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c4f0_FUN_0043c4f0.md` (+ W30-D live seal) |
| Annotated | `docs/reconstruction/raw/aa_0043c4f0_FUN_0043c4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBackLocked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c4f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c4f0_FUN_0043c4f0.md` |
| Named record | `docs/reconstruction/functions/aa_0043c4f0_GuardedVector_PushBackLocked.md` |
| Live | decompile ≡ raw CF; full 94 B hex; RET 4; 1 xref |
| Caller | `007b75b0`: `MOV EDI,[DAT_00d1f058]; ADD EDI,0x58` then call |

---

## 3. Signature (sealed)

```c
// EDI=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushBackLocked(const uint32_t* value /*stack*/,
                                  GuardedVectorHeader* container /*EDI*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EDI** (`unaff_EDI`; sole-caller `ADD EDI,0x58`) | **High** |
| value* | Stack[+4] at entry | **High** |
| cleanup | **`RET 0x4`** | **High** |
| return | void | **High** |

Decompiler omits EDI — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install (LAB_009be0c8)
if [EDI+0x2c]: EnterCS(EDI+0x14)
SEH state = 0
EAX = EDI; PushBack(value*)   // FUN_0043c830
if [EDI+0x2c]: LeaveCS(EDI+0x14)
SEH teardown; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Lock flag +0x2c | **Yes** | **High** |
| CS +0x14 | **Yes** | **High** |
| Enter → push → Leave order | **Yes** | **High** |
| EAX←EDI for nested PushBack | **Yes** | **High** |
| Full body 94 B hex | **Yes** | **High** |
| Product English | inferred only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Full hex (94 B):

```
6aff68c8e09b0064a100000000506489250000000051807f2c00568d771489742404740756ff15bc619c008b442418508bc7c744241400000000e801030000807e1800740756ff15b8619c008b4c24085e64890d0000000083c410c20400
```

Key sites:

| Site | Bytes | Meaning |
|---|---|---|
| Gate | `80 7F 2C 00` | `cmp byte [edi+0x2c],0` |
| CS lea | `8D 77 14` | `lea esi,[edi+0x14]` |
| Nested | `8B C7` … `E8 01 03 00 00` | `mov eax,edi; call 0043c830` |
| Epilogue | `83 C4 10 C2 04 00` | `add esp,10; ret 4` |

Next function: `FUN_0043c550` after `CC CC`.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural family only).
- Runtime / bit-exact under contended CS.
- Nested PushBack internals owned by W29-B (not re-sealed here).

---

## 7. Verdict

ABI, CS gate, enter/push/leave order, and full body bytes sealed from live decompile + `read_memory` + sole-caller setup → **accept**.
