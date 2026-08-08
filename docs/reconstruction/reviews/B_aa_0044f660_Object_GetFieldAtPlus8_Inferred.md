# Review B (skeptical / adversarial): `aa_0044f660` Object_GetFieldAtPlus8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044f660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R10-027) |
| **Counterpart** | `reviews/A_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Ghidra meta signature `undefined FUN(void)` is authoritative | **Falsified** — decompiler + bytes show ECX this + EAX return of `[ECX+8]` |
| 2 | This is exclusive to skills-abilities / parent class only | **Falsified as exclusive** — 10 DATA vtable embeds; 2 CALL sites are util/Havok paths (`FUN_00641ad0`, `FUN_00647990`) |
| 3 | Stack args / `RET n` ABI | **Falsified** — plain `RET` (`C3`); zero stack formals |
| 4 | Field +8 is a non-pointer scalar always | **Not sealed either way** — both CALL sites treat as object*; cannot claim for all hosts → gap, not reject |
| 5 | Function does work beyond the load | **Falsified** — 4-byte leaf; no callees; no branches |
| 6 | Product name without `_Inferred` | **Rejected** — no RTTI/string plate for field |
| 7 | Runtime Confirmed | **Not claimed** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offset +8 dword load | **High** | Wrong field in ports |
| ECX thiscall / plain RET | **High** | Corrupt stack / wrong register |
| Multi-vtable share | **High** | Over-narrow domain ownership |
| Product field English | Low | Naming only |
| Typed as pointer for all hosts | Medium | Over-constrain clean type |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
0044f660  8B 41 08     mov eax, dword ptr [ecx+8]
0044f663  C3           ret
0044f664  CC…          int3 pad
```

Caller `FUN_00641ad0` @ `0x00641b11`:
```
call 0044f660          ; EAX = *(this+8)
mov  edx, [eax]        ; vptr of returned object
push 0
push 0
mov  ecx, eax
call [edx+0x14]        ; virtual on returned ptr
```

Caller `FUN_00647990` @ `0x00648123`:
```
call 0044f660
mov  edi, eax          ; keep returned ptr as context
```

Sibling setter bytes @ `0x00416150` (context, not owned):
```
mov eax, [esp+4]
mov [ecx+8], eax
ret 4
```

Do **not** port as `void f(void)`. Do **not** invent product field plates. Do **not** claim skills-only ownership.

---

## 4. Surviving contract for AutoCore

```csharp
// uint Object_GetFieldAtPlus8(IntPtr self)  // ECX thiscall, plain RET
// return ReadUInt32(self + 8);
```

Shared leaf — pair with setter `0x00416150` where that vtable is used. Preserve multi-host reuse.

---

## 5. Verdict rationale

Adversarial checks kill void-signature, exclusive-domain, and stack-ABI misreads. Remaining gaps are product English and universal pointer typing → **accept-with-gaps**.
