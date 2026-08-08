# Review A (reconstruction fidelity): `aa_00756be0` gfxUIWindow_DetachParent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756be0` |
| **VA** | `0x00756be0`–`0x00756c44` inclusive (**101 B** / `0x65`) |
| **Canonical name** | `gfxUIWindow_DetachParent_Inferred` |
| **Ghidra name** | `FUN_00756be0` |
| **Review date** | `2026-08-05` (MEGA-121 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-121) |
| **Counterpart** | `reviews/B_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md` |
| **System** | skills-abilities / gfxUIWindow child-list unlink |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` @ `0x00759f3a` / `0x007918a5` / `0x00756c63` / `0x005767a4`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Parent-side child detach leaf.** Given parent window (`ECX`) and child pointer (stack), linear-search the parent's dense child-pointer vector (`+0x94` begin / `+0x98` end), erase the matching slot by `memmove` compact + end shrink, clear the child's parent back-pointer at `+0x88`, return status. Shared by dualed `gfxUIWindow_CompleteDtor` (child leaves parent on destroy) and dualed `CNDUIDialog_TeardownChildHash_Inferred` (dialog erases children during hash teardown). Does **not** free either object.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-121 append) | `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_DetachParent_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00756be0.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00756be0.cpp` |
| Live | full disasm; entry/exit hex; 24 UNCONDITIONAL_CALL xrefs; dualed call-site context |

### Entry / exit hex (live `read_memory`)

```text
00756be0: 56 8B F1                  PUSH ESI; MOV ESI,ECX
          8B 8E 98 00 00 00         MOV ECX,[ESI+0x98]
          8B 86 94 00 00 00         MOV EAX,[ESI+0x94]
          3B C1 57 8B 7C 24 0C ...  CMP begin,end; PUSH EDI; MOV EDI,[ESP+0xC]
...
00756c07: 5F 83 C8 FF 5E C2 04 00   POP EDI; OR EAX,-1; POP ESI; RET 4
...
00756c34: C7 87 88 00 00 00 00 00 00 00   MOV [EDI+0x88],0
00756c3e: 5F 33 C0 5E C2 04 00      POP EDI; XOR EAX,EAX; POP ESI; RET 4
```

Pad: `CC` ×… then `FUN_00756c50` @ `0x00756c50`.

---

## 3. Signature (sealed)

```c
// ECX = parent (gfxUIWindow* / dialog*); stack = child*; RET 4
// EAX = 0 success / 0xffffffff not found
std::uint32_t __thiscall gfxUIWindow_DetachParent_Inferred(void *parent, void *child);
```

| Formal | Source | Conf |
|---|---|---|
| parent | **ECX** (`MOV ESI,ECX` @ `0x00756be1`) | **High** |
| child | stack `[ESP+4]` at entry → `[ESP+0xC]` after two pushes (`MOV EDI,[ESP+0xC]`) | **High** |
| return | EAX `0` / `0xffffffff` | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) both exits | **High** |

---

## 4. Control flow (authority)

```text
begin = [parent+0x94]; end = [parent+0x98]; child = stack
if begin == end: return -1
loop:
  if *it == child: break
  it += 1  // +4
  while it != end
if it == end: return -1
memmove(it, it+1, byte_count_from_end)   // IAT [0x009c652c]
[parent+0x98] -= 4
[child+0x88] = 0
return 0
```

| Stage | Match | Conf |
|---|---|---|
| ECX→ESI parent | `MOV ESI,ECX` | **High** |
| begin/end load | `MOV EAX,[ESI+0x94]` / `MOV ECX,[ESI+0x98]` | **High** |
| empty early | `CMP EAX,ECX; JZ not_found` | **High** |
| linear search | `CMP [EAX],EDI; ADD EAX,4; JNZ` | **High** |
| memmove IAT | `CALL [0x009c652c]` + `ADD ESP,0xC` | **High** |
| end shrink | `ADD dword ptr [ESI+0x98],-4` | **High** |
| clear parent link | `MOV [EDI+0x88],0` | **High** |
| dual RET 4 | both exits `C2 04 00` | **High** |

Decompile ≡ raw CF ≡ body bytes.

---

## 5. Call graph

| Direction | Targets |
|---|---|
| Callers | **24** UNCONDITIONAL_CALL; 17 named + Catch@`0094b325` |
| Dualed | `FUN_00759de0` gfxUIWindow_CompleteDtor @ `0x00759f3a`; `FUN_007917c0` CNDUIDialog_TeardownChildHash @ `0x007918a5` |
| Peer residual | `FUN_00756c50` attach/reparent @ `0x00756c63` |
| Callees | `memmove` only (IAT `0x009c652c`) |

Dualed dtor site authority:

```text
// 0x00759f2f..0x00759f3a (gfxUIWindow_CompleteDtor)
MOV ECX, dword ptr [ESI + 0x88]   ; parent = child.parent
CMP ECX, EBX
JZ  skip
PUSH ESI                          ; child = self
CALL 0x00756be0
```

Dualed dialog site authority:

```text
// 0x0079189c..0x007918a5 (CNDUIDialog_TeardownChildHash)
PUSH ESI                          ; child
MOV ECX, EBP                      ; dialog this
CALL 0x00756be0
```

---

## 6. Naming

| Name | Status |
|---|---|
| Ghidra `FUN_00756be0` | sealed |
| Canonical `gfxUIWindow_DetachParent_Inferred` | sealed (partition hint + dualed gfxUIWindow family + clear `+0x88`; product demangle open → `_Inferred`) |
| Scaffold `Named_CalleeOf_Named_gfxUIWindow_00756be0` | **retired** |

**Reject:** thiscall-on-child-only (ECX is parent); bare RET; free/delete; “walk all children”; skill-specific seed names.

---

## 7. Gaps

- Exact product method demangle (no RTTI/string on this leaf).
- Dual residual of attach peer `FUN_00756c50` and remaining non-dualed callers.
- Optional capacity field beyond begin/end (untouched).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF, ABI (ECX=parent, stack=child, **RET 4**, EAX status), offset map (`+0x94`/`+0x98`/`child+0x88`), sole callee `memmove`, and dualed call-site patterns sealed live. Product method demangle + residual peer dual open → **accept-with-gaps**.
