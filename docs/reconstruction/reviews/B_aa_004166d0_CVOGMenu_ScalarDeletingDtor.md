# Review B (skeptical / adversarial): `aa_004166d0` CVOGMenu_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004166d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-138) |
| **Counterpart** | `reviews/A_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callers/callees. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a vector-deleting dtor (flags&2 / count) | **Falsified** — only bit0 tested; no count arg; body 30 B |
| 2 | operator_delete never returns / function diverges | **Falsified** — bytes always `MOV EAX,ESI; RET 4`; `ADD ESP,4` after delete |
| 3 | Complete is inline / no callee | **Falsified** — `CALL 0x0082d540` |
| 4 | CODE call sites exist | **Falsified** — DATA xref only (vtbl[0]); callers list empty |
| 5 | Same unit as complete `0082d540` | **Falsified** — complete has SEH + hash + base chain, no free/flags |
| 6 | Product name is unsealed / needs `_Inferred` | **Falsified** — RTTI `.?AVCVOGMenu@@` @ `0x00afe39c` via COL |
| 7 | `RET 0` / cdecl | **Falsified** — `C2 04 00` thiscall flags cleanup |
| 8 | Vtbl binding is different class (e.g. CMenuChatlog) | **Falsified** — dword0 @ `00a72f6c` = `004166d0`; chatlog complete `008327f0` is derived that **chains** this complete |
| 9 | Named_CalleeOf scaffold is still correct name | **N/A** — no Named_CalleeOf plate existed; scaffold `FUN_004166d0` retired to product name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / RET 4 / return this | **High** | Wrong delete path |
| flags bit0 → delete | **High** | Leak or double-free port |
| vtbl[0] @ `00a72f6c` | **High** | Wrong slot binding |
| Complete `0082d540` | **High** | Incomplete teardown |
| Product demangle CVOGMenu | **High** | Naming only if wrong |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push esi
mov esi, ecx
call FUN_0082d540          ; CVOGMenu_CompleteDtor
test byte [esp+8], 1
jz skip
push esi
call operator_delete
add esp, 4
skip:
mov eax, esi
pop esi
ret 4
```

Hex (30 B): `568bf1e8686e4100f644240801740956e83d31070083c4048bc65ec20400`

Vtbl dword0 @ `0x00a72f6c` = `0x004166d0`. RTTI name `.?AVCVOGMenu@@`. Do **not** invent vector-deleting form. Do **not** claim runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// void* ScalarDeletingDtor(this, byte flags)  // thiscall, ret 4
// CVOGMenu_CompleteDtor(this); if ((flags&1)!=0) delete this; return this;
```

Port as MSVC vtbl[0] scalar dtor for **CVOGMenu**. Pair complete `0082d540` (already dualed). Keep distinct from derived menu completes (e.g. CMenuChatlog `008327f0`) that chain the same complete then free via their own scalar shells.

---

## 5. Verdict

**accept** — adversarial checks confirm standard scalar-deleting dtor with RTTI-sealed product name. Residual: vtbl[1+] English, runtime. Not reject.
