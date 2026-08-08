# Review B (skeptical / adversarial): `aa_00409e20` StdVector_ConstructN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-044) |
| **Counterpart** | `reviews/A_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs + assembly context. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void FUN_00409e20(undefined4 param_1,int param_2)` is complete ABI | **Falsified as ABI** — `param_1` phantom; real formals are **ECX=template**, stack dest+count |
| 2 | This is PollBoundActions input logic (scaffold name) | **Falsified** — pure ConstructN 0x10; PollBound is multi-hop parent only |
| 3 | This is insert-N / grow / realloc | **Falsified** — no capacity math, no `new`/`delete`; only fill loop |
| 4 | This is range-copy / uninitialized_copy (source walks) | **Falsified** — template fixed in EBX; only dest advances |
| 5 | Stride is 0x28 / 12 / 4 | **Falsified** — `ADD ESI,0x10` + 4-dword PodCopy |
| 6 | `ret 4` / thiscall like fill-n wrappers | **Falsified** — plain **`RET` (`C3`)** cdecl; callers `ADD ESP,0x10` |
| 7 | Returns end pointer `dest+count*0x10` | **Falsified for this VA** — end math lives in wrapper `FUN_00407000` after call |
| 8 | PodCopy is complex non-POD ctor | **Falsified** — `00409f70` is 4 dword stores + null check |
| 9 | Many independent domain callers | **Fails as multi-domain** — only 2 sites: construct wrapper + SortTargetList |
| 10 | SEH proves throwing element ctor | **Weak / not required** — MSVC emits EH around ConstructN even for POD copy; no throw in leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX/template + dest/count + RET cdecl | **High** | Wrong stack / register wiring |
| Stride 0x10 | **High** | Misaligned vector elements |
| Role = ConstructN fill-from-one | **High** | Invented copy/grow semantics |
| PodCopy 0x10 leaf | **High** | Wrong element size |
| Scaffold PollBound name | **Rejected** | Mis-file under input system |
| Product demangle | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
; entry
push ebp / mov ebp,esp
push -1 / push LAB_009bc610 / SEH link
mov ebx, ecx          ; template
mov edi, [ebp+0xc]    ; count
mov esi, [ebp+8]      ; dest
; loop
test edi,edi / jbe done
mov ecx, ebx / mov eax, esi / call FUN_00409f70
sub edi,1 / add esi,0x10 / jmp loop
; exit
seh unlink / pop edi,esi,ebx / leave / ret   ; C3
```

Call site `0040700c`:

```
push … / push esi / push edi / call 00409e20 / add esp,0x10
mov eax,esi / shl eax,4 / add eax,edi / ret 4   ; end = dest+count*0x10 in WRAPPER
```

Call site `009305a5`:

```
push 1 / push esi / lea ecx,[esp+40] / call 00409e20 / add esp,0x10 / add esi,0x10
```

Do **not** merge with ConstructN 0x28 (`00409d40`) or elem12 (`00409db0`). Do **not** treat as insert-N `00408640`. Do **not** keep Named_CalleeOf_PollBound scaffold as role.

---

## 4. Surviving contract for AutoCore

```csharp
// void ConstructN_Elem0x10(const Elem0x10* value /*ECX*/, Elem0x10* dest, int count)
// cdecl; callers often push 2 phantom dwords + dest + count and ADD ESP,0x10
// loop: PodCopy4Dwords(dest, value); dest++; count--
// SEH frame present; no return value
// Pair with: wrapper 00407000 (returns end); InsertN 00408640; PodCopy 00409f70
```

Port as shared vector ConstructN helper for stride-16 POD. Keep distinct from uninitialized_copy range walkers and from insert-N growth.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm ConstructN CF/ABI/stride/callers; scaffold PollBound role and decompiler signature claims falsified. Residual product demangle + helper duals + runtime. Not reject.
